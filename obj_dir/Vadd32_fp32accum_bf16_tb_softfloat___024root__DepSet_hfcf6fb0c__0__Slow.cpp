// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd32_fp32accum_bf16_tb_softfloat.h for the primary calling header

#include "Vadd32_fp32accum_bf16_tb_softfloat__pch.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat__Syms.h"
#include "Vadd32_fp32accum_bf16_tb_softfloat___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___eval_triggers__stl\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vadd32_fp32accum_bf16_tb_softfloat___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void Vadd32_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0(Vadd32_fp32accum_bf16_tb_softfloat___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd32_fp32accum_bf16_tb_softfloat___024root___stl_sequent__TOP__0\n"); );
    Vadd32_fp32accum_bf16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_14;
    VlWide<5>/*159:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<5>/*159:0*/ __Vtemp_22;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_27;
    VlWide<4>/*127:0*/ __Vtemp_28;
    VlWide<4>/*127:0*/ __Vtemp_30;
    VlWide<4>/*127:0*/ __Vtemp_31;
    VlWide<4>/*127:0*/ __Vtemp_32;
    VlWide<4>/*127:0*/ __Vtemp_38;
    VlWide<5>/*159:0*/ __Vtemp_39;
    VlWide<4>/*127:0*/ __Vtemp_41;
    VlWide<4>/*127:0*/ __Vtemp_44;
    VlWide<4>/*127:0*/ __Vtemp_45;
    VlWide<5>/*159:0*/ __Vtemp_46;
    VlWide<4>/*127:0*/ __Vtemp_48;
    VlWide<4>/*127:0*/ __Vtemp_49;
    VlWide<4>/*127:0*/ __Vtemp_51;
    VlWide<4>/*127:0*/ __Vtemp_52;
    VlWide<4>/*127:0*/ __Vtemp_54;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<4>/*127:0*/ __Vtemp_56;
    VlWide<4>/*127:0*/ __Vtemp_62;
    VlWide<5>/*159:0*/ __Vtemp_63;
    VlWide<4>/*127:0*/ __Vtemp_65;
    VlWide<4>/*127:0*/ __Vtemp_68;
    VlWide<4>/*127:0*/ __Vtemp_69;
    VlWide<5>/*159:0*/ __Vtemp_70;
    VlWide<4>/*127:0*/ __Vtemp_72;
    VlWide<4>/*127:0*/ __Vtemp_73;
    VlWide<4>/*127:0*/ __Vtemp_75;
    VlWide<4>/*127:0*/ __Vtemp_76;
    VlWide<4>/*127:0*/ __Vtemp_78;
    VlWide<4>/*127:0*/ __Vtemp_79;
    VlWide<4>/*127:0*/ __Vtemp_80;
    VlWide<4>/*127:0*/ __Vtemp_86;
    VlWide<5>/*159:0*/ __Vtemp_87;
    VlWide<4>/*127:0*/ __Vtemp_89;
    VlWide<4>/*127:0*/ __Vtemp_92;
    VlWide<4>/*127:0*/ __Vtemp_93;
    VlWide<5>/*159:0*/ __Vtemp_94;
    VlWide<4>/*127:0*/ __Vtemp_96;
    VlWide<4>/*127:0*/ __Vtemp_97;
    VlWide<4>/*127:0*/ __Vtemp_99;
    VlWide<4>/*127:0*/ __Vtemp_100;
    VlWide<4>/*127:0*/ __Vtemp_102;
    VlWide<4>/*127:0*/ __Vtemp_103;
    VlWide<4>/*127:0*/ __Vtemp_104;
    VlWide<4>/*127:0*/ __Vtemp_110;
    VlWide<5>/*159:0*/ __Vtemp_111;
    VlWide<4>/*127:0*/ __Vtemp_113;
    VlWide<4>/*127:0*/ __Vtemp_116;
    VlWide<4>/*127:0*/ __Vtemp_117;
    VlWide<5>/*159:0*/ __Vtemp_118;
    VlWide<4>/*127:0*/ __Vtemp_120;
    VlWide<4>/*127:0*/ __Vtemp_121;
    VlWide<4>/*127:0*/ __Vtemp_123;
    VlWide<4>/*127:0*/ __Vtemp_124;
    VlWide<4>/*127:0*/ __Vtemp_126;
    VlWide<4>/*127:0*/ __Vtemp_127;
    VlWide<4>/*127:0*/ __Vtemp_128;
    VlWide<4>/*127:0*/ __Vtemp_134;
    VlWide<5>/*159:0*/ __Vtemp_135;
    VlWide<4>/*127:0*/ __Vtemp_137;
    VlWide<4>/*127:0*/ __Vtemp_140;
    VlWide<4>/*127:0*/ __Vtemp_141;
    VlWide<5>/*159:0*/ __Vtemp_142;
    VlWide<4>/*127:0*/ __Vtemp_144;
    VlWide<4>/*127:0*/ __Vtemp_145;
    VlWide<4>/*127:0*/ __Vtemp_147;
    VlWide<4>/*127:0*/ __Vtemp_148;
    VlWide<4>/*127:0*/ __Vtemp_150;
    VlWide<4>/*127:0*/ __Vtemp_151;
    VlWide<4>/*127:0*/ __Vtemp_152;
    VlWide<4>/*127:0*/ __Vtemp_158;
    VlWide<5>/*159:0*/ __Vtemp_159;
    VlWide<4>/*127:0*/ __Vtemp_161;
    VlWide<4>/*127:0*/ __Vtemp_164;
    VlWide<4>/*127:0*/ __Vtemp_165;
    VlWide<5>/*159:0*/ __Vtemp_166;
    VlWide<4>/*127:0*/ __Vtemp_168;
    VlWide<4>/*127:0*/ __Vtemp_169;
    VlWide<4>/*127:0*/ __Vtemp_171;
    VlWide<4>/*127:0*/ __Vtemp_172;
    VlWide<4>/*127:0*/ __Vtemp_174;
    VlWide<4>/*127:0*/ __Vtemp_175;
    VlWide<4>/*127:0*/ __Vtemp_176;
    VlWide<4>/*127:0*/ __Vtemp_182;
    VlWide<5>/*159:0*/ __Vtemp_183;
    VlWide<4>/*127:0*/ __Vtemp_185;
    VlWide<4>/*127:0*/ __Vtemp_188;
    VlWide<4>/*127:0*/ __Vtemp_189;
    VlWide<5>/*159:0*/ __Vtemp_190;
    VlWide<4>/*127:0*/ __Vtemp_192;
    VlWide<4>/*127:0*/ __Vtemp_193;
    VlWide<4>/*127:0*/ __Vtemp_195;
    VlWide<4>/*127:0*/ __Vtemp_196;
    VlWide<4>/*127:0*/ __Vtemp_198;
    VlWide<4>/*127:0*/ __Vtemp_199;
    VlWide<4>/*127:0*/ __Vtemp_200;
    VlWide<4>/*127:0*/ __Vtemp_206;
    VlWide<5>/*159:0*/ __Vtemp_207;
    VlWide<4>/*127:0*/ __Vtemp_209;
    VlWide<4>/*127:0*/ __Vtemp_212;
    VlWide<4>/*127:0*/ __Vtemp_213;
    VlWide<5>/*159:0*/ __Vtemp_214;
    VlWide<4>/*127:0*/ __Vtemp_216;
    VlWide<4>/*127:0*/ __Vtemp_217;
    VlWide<4>/*127:0*/ __Vtemp_219;
    VlWide<4>/*127:0*/ __Vtemp_220;
    VlWide<4>/*127:0*/ __Vtemp_222;
    VlWide<4>/*127:0*/ __Vtemp_223;
    VlWide<4>/*127:0*/ __Vtemp_224;
    VlWide<4>/*127:0*/ __Vtemp_230;
    VlWide<5>/*159:0*/ __Vtemp_231;
    VlWide<4>/*127:0*/ __Vtemp_233;
    VlWide<4>/*127:0*/ __Vtemp_236;
    VlWide<4>/*127:0*/ __Vtemp_237;
    VlWide<5>/*159:0*/ __Vtemp_238;
    VlWide<4>/*127:0*/ __Vtemp_240;
    VlWide<4>/*127:0*/ __Vtemp_241;
    VlWide<4>/*127:0*/ __Vtemp_243;
    VlWide<4>/*127:0*/ __Vtemp_244;
    VlWide<4>/*127:0*/ __Vtemp_246;
    VlWide<4>/*127:0*/ __Vtemp_247;
    VlWide<4>/*127:0*/ __Vtemp_248;
    VlWide<4>/*127:0*/ __Vtemp_254;
    VlWide<5>/*159:0*/ __Vtemp_255;
    VlWide<4>/*127:0*/ __Vtemp_257;
    VlWide<4>/*127:0*/ __Vtemp_260;
    VlWide<4>/*127:0*/ __Vtemp_261;
    VlWide<5>/*159:0*/ __Vtemp_262;
    VlWide<4>/*127:0*/ __Vtemp_264;
    VlWide<4>/*127:0*/ __Vtemp_265;
    VlWide<4>/*127:0*/ __Vtemp_267;
    VlWide<4>/*127:0*/ __Vtemp_268;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<4>/*127:0*/ __Vtemp_271;
    VlWide<4>/*127:0*/ __Vtemp_272;
    VlWide<4>/*127:0*/ __Vtemp_279;
    VlWide<4>/*127:0*/ __Vtemp_284;
    VlWide<4>/*127:0*/ __Vtemp_287;
    VlWide<4>/*127:0*/ __Vtemp_292;
    VlWide<4>/*127:0*/ __Vtemp_295;
    VlWide<4>/*127:0*/ __Vtemp_300;
    VlWide<4>/*127:0*/ __Vtemp_303;
    VlWide<4>/*127:0*/ __Vtemp_308;
    VlWide<4>/*127:0*/ __Vtemp_311;
    VlWide<4>/*127:0*/ __Vtemp_316;
    VlWide<4>/*127:0*/ __Vtemp_319;
    VlWide<4>/*127:0*/ __Vtemp_324;
    VlWide<4>/*127:0*/ __Vtemp_327;
    VlWide<4>/*127:0*/ __Vtemp_332;
    VlWide<4>/*127:0*/ __Vtemp_334;
    VlWide<4>/*127:0*/ __Vtemp_343;
    VlWide<4>/*127:0*/ __Vtemp_348;
    VlWide<4>/*127:0*/ __Vtemp_351;
    VlWide<4>/*127:0*/ __Vtemp_356;
    VlWide<4>/*127:0*/ __Vtemp_359;
    VlWide<4>/*127:0*/ __Vtemp_364;
    VlWide<4>/*127:0*/ __Vtemp_367;
    VlWide<4>/*127:0*/ __Vtemp_372;
    VlWide<4>/*127:0*/ __Vtemp_375;
    VlWide<4>/*127:0*/ __Vtemp_380;
    VlWide<4>/*127:0*/ __Vtemp_383;
    VlWide<4>/*127:0*/ __Vtemp_388;
    VlWide<4>/*127:0*/ __Vtemp_391;
    VlWide<4>/*127:0*/ __Vtemp_396;
    VlWide<4>/*127:0*/ __Vtemp_398;
    VlWide<4>/*127:0*/ __Vtemp_407;
    VlWide<4>/*127:0*/ __Vtemp_412;
    VlWide<4>/*127:0*/ __Vtemp_415;
    VlWide<4>/*127:0*/ __Vtemp_420;
    VlWide<4>/*127:0*/ __Vtemp_423;
    VlWide<4>/*127:0*/ __Vtemp_428;
    VlWide<4>/*127:0*/ __Vtemp_431;
    VlWide<4>/*127:0*/ __Vtemp_436;
    VlWide<4>/*127:0*/ __Vtemp_439;
    VlWide<4>/*127:0*/ __Vtemp_444;
    VlWide<4>/*127:0*/ __Vtemp_447;
    VlWide<4>/*127:0*/ __Vtemp_452;
    VlWide<4>/*127:0*/ __Vtemp_455;
    VlWide<4>/*127:0*/ __Vtemp_460;
    VlWide<4>/*127:0*/ __Vtemp_462;
    VlWide<4>/*127:0*/ __Vtemp_471;
    VlWide<4>/*127:0*/ __Vtemp_476;
    VlWide<4>/*127:0*/ __Vtemp_479;
    VlWide<4>/*127:0*/ __Vtemp_484;
    VlWide<4>/*127:0*/ __Vtemp_487;
    VlWide<4>/*127:0*/ __Vtemp_492;
    VlWide<4>/*127:0*/ __Vtemp_495;
    VlWide<4>/*127:0*/ __Vtemp_500;
    VlWide<4>/*127:0*/ __Vtemp_503;
    VlWide<4>/*127:0*/ __Vtemp_508;
    VlWide<4>/*127:0*/ __Vtemp_511;
    VlWide<4>/*127:0*/ __Vtemp_516;
    VlWide<4>/*127:0*/ __Vtemp_519;
    VlWide<4>/*127:0*/ __Vtemp_524;
    VlWide<4>/*127:0*/ __Vtemp_526;
    VlWide<4>/*127:0*/ __Vtemp_535;
    VlWide<4>/*127:0*/ __Vtemp_540;
    VlWide<4>/*127:0*/ __Vtemp_543;
    VlWide<4>/*127:0*/ __Vtemp_548;
    VlWide<4>/*127:0*/ __Vtemp_551;
    VlWide<4>/*127:0*/ __Vtemp_556;
    VlWide<4>/*127:0*/ __Vtemp_559;
    VlWide<4>/*127:0*/ __Vtemp_564;
    VlWide<4>/*127:0*/ __Vtemp_567;
    VlWide<4>/*127:0*/ __Vtemp_572;
    VlWide<4>/*127:0*/ __Vtemp_575;
    VlWide<4>/*127:0*/ __Vtemp_580;
    VlWide<4>/*127:0*/ __Vtemp_583;
    VlWide<4>/*127:0*/ __Vtemp_588;
    VlWide<4>/*127:0*/ __Vtemp_590;
    VlWide<4>/*127:0*/ __Vtemp_599;
    VlWide<4>/*127:0*/ __Vtemp_604;
    VlWide<4>/*127:0*/ __Vtemp_607;
    VlWide<4>/*127:0*/ __Vtemp_612;
    VlWide<4>/*127:0*/ __Vtemp_615;
    VlWide<4>/*127:0*/ __Vtemp_620;
    VlWide<4>/*127:0*/ __Vtemp_623;
    VlWide<4>/*127:0*/ __Vtemp_628;
    VlWide<4>/*127:0*/ __Vtemp_631;
    VlWide<4>/*127:0*/ __Vtemp_636;
    VlWide<4>/*127:0*/ __Vtemp_639;
    VlWide<4>/*127:0*/ __Vtemp_644;
    VlWide<4>/*127:0*/ __Vtemp_647;
    VlWide<4>/*127:0*/ __Vtemp_652;
    VlWide<4>/*127:0*/ __Vtemp_654;
    VlWide<4>/*127:0*/ __Vtemp_663;
    VlWide<4>/*127:0*/ __Vtemp_668;
    VlWide<4>/*127:0*/ __Vtemp_671;
    VlWide<4>/*127:0*/ __Vtemp_676;
    VlWide<4>/*127:0*/ __Vtemp_679;
    VlWide<4>/*127:0*/ __Vtemp_684;
    VlWide<4>/*127:0*/ __Vtemp_687;
    VlWide<4>/*127:0*/ __Vtemp_692;
    VlWide<4>/*127:0*/ __Vtemp_695;
    VlWide<4>/*127:0*/ __Vtemp_700;
    VlWide<4>/*127:0*/ __Vtemp_703;
    VlWide<4>/*127:0*/ __Vtemp_708;
    VlWide<4>/*127:0*/ __Vtemp_711;
    VlWide<4>/*127:0*/ __Vtemp_716;
    VlWide<4>/*127:0*/ __Vtemp_718;
    VlWide<4>/*127:0*/ __Vtemp_727;
    VlWide<4>/*127:0*/ __Vtemp_732;
    VlWide<4>/*127:0*/ __Vtemp_735;
    VlWide<4>/*127:0*/ __Vtemp_740;
    VlWide<4>/*127:0*/ __Vtemp_743;
    VlWide<4>/*127:0*/ __Vtemp_748;
    VlWide<4>/*127:0*/ __Vtemp_751;
    VlWide<4>/*127:0*/ __Vtemp_756;
    VlWide<4>/*127:0*/ __Vtemp_759;
    VlWide<4>/*127:0*/ __Vtemp_764;
    VlWide<4>/*127:0*/ __Vtemp_767;
    VlWide<4>/*127:0*/ __Vtemp_772;
    VlWide<4>/*127:0*/ __Vtemp_775;
    VlWide<4>/*127:0*/ __Vtemp_780;
    VlWide<4>/*127:0*/ __Vtemp_782;
    VlWide<4>/*127:0*/ __Vtemp_791;
    VlWide<4>/*127:0*/ __Vtemp_796;
    VlWide<4>/*127:0*/ __Vtemp_799;
    VlWide<4>/*127:0*/ __Vtemp_804;
    VlWide<4>/*127:0*/ __Vtemp_807;
    VlWide<4>/*127:0*/ __Vtemp_812;
    VlWide<4>/*127:0*/ __Vtemp_815;
    VlWide<4>/*127:0*/ __Vtemp_820;
    VlWide<4>/*127:0*/ __Vtemp_823;
    VlWide<4>/*127:0*/ __Vtemp_828;
    VlWide<4>/*127:0*/ __Vtemp_831;
    VlWide<4>/*127:0*/ __Vtemp_836;
    VlWide<4>/*127:0*/ __Vtemp_839;
    VlWide<4>/*127:0*/ __Vtemp_844;
    VlWide<4>/*127:0*/ __Vtemp_846;
    VlWide<4>/*127:0*/ __Vtemp_855;
    VlWide<4>/*127:0*/ __Vtemp_860;
    VlWide<4>/*127:0*/ __Vtemp_863;
    VlWide<4>/*127:0*/ __Vtemp_868;
    VlWide<4>/*127:0*/ __Vtemp_871;
    VlWide<4>/*127:0*/ __Vtemp_876;
    VlWide<4>/*127:0*/ __Vtemp_879;
    VlWide<4>/*127:0*/ __Vtemp_884;
    VlWide<4>/*127:0*/ __Vtemp_887;
    VlWide<4>/*127:0*/ __Vtemp_892;
    VlWide<4>/*127:0*/ __Vtemp_895;
    VlWide<4>/*127:0*/ __Vtemp_900;
    VlWide<4>/*127:0*/ __Vtemp_903;
    VlWide<4>/*127:0*/ __Vtemp_908;
    VlWide<4>/*127:0*/ __Vtemp_910;
    VlWide<4>/*127:0*/ __Vtemp_919;
    VlWide<4>/*127:0*/ __Vtemp_924;
    VlWide<4>/*127:0*/ __Vtemp_927;
    VlWide<4>/*127:0*/ __Vtemp_932;
    VlWide<4>/*127:0*/ __Vtemp_935;
    VlWide<4>/*127:0*/ __Vtemp_940;
    VlWide<4>/*127:0*/ __Vtemp_943;
    VlWide<4>/*127:0*/ __Vtemp_948;
    VlWide<4>/*127:0*/ __Vtemp_951;
    VlWide<4>/*127:0*/ __Vtemp_956;
    VlWide<4>/*127:0*/ __Vtemp_959;
    VlWide<4>/*127:0*/ __Vtemp_964;
    VlWide<4>/*127:0*/ __Vtemp_967;
    VlWide<4>/*127:0*/ __Vtemp_972;
    VlWide<4>/*127:0*/ __Vtemp_974;
    VlWide<4>/*127:0*/ __Vtemp_988;
    VlWide<4>/*127:0*/ __Vtemp_989;
    VlWide<4>/*127:0*/ __Vtemp_994;
    VlWide<4>/*127:0*/ __Vtemp_997;
    VlWide<4>/*127:0*/ __Vtemp_998;
    VlWide<4>/*127:0*/ __Vtemp_1003;
    VlWide<4>/*127:0*/ __Vtemp_1006;
    VlWide<4>/*127:0*/ __Vtemp_1007;
    VlWide<4>/*127:0*/ __Vtemp_1012;
    VlWide<4>/*127:0*/ __Vtemp_1036;
    VlWide<4>/*127:0*/ __Vtemp_1039;
    VlWide<4>/*127:0*/ __Vtemp_1041;
    VlWide<4>/*127:0*/ __Vtemp_1053;
    VlWide<4>/*127:0*/ __Vtemp_1054;
    VlWide<4>/*127:0*/ __Vtemp_1059;
    VlWide<4>/*127:0*/ __Vtemp_1062;
    VlWide<4>/*127:0*/ __Vtemp_1063;
    VlWide<4>/*127:0*/ __Vtemp_1068;
    VlWide<4>/*127:0*/ __Vtemp_1071;
    VlWide<4>/*127:0*/ __Vtemp_1072;
    VlWide<4>/*127:0*/ __Vtemp_1077;
    VlWide<4>/*127:0*/ __Vtemp_1101;
    VlWide<4>/*127:0*/ __Vtemp_1104;
    VlWide<4>/*127:0*/ __Vtemp_1106;
    VlWide<4>/*127:0*/ __Vtemp_1118;
    VlWide<4>/*127:0*/ __Vtemp_1119;
    VlWide<4>/*127:0*/ __Vtemp_1124;
    VlWide<4>/*127:0*/ __Vtemp_1127;
    VlWide<4>/*127:0*/ __Vtemp_1128;
    VlWide<4>/*127:0*/ __Vtemp_1133;
    VlWide<4>/*127:0*/ __Vtemp_1136;
    VlWide<4>/*127:0*/ __Vtemp_1137;
    VlWide<4>/*127:0*/ __Vtemp_1142;
    VlWide<4>/*127:0*/ __Vtemp_1166;
    VlWide<4>/*127:0*/ __Vtemp_1169;
    VlWide<4>/*127:0*/ __Vtemp_1171;
    VlWide<4>/*127:0*/ __Vtemp_1183;
    VlWide<4>/*127:0*/ __Vtemp_1184;
    VlWide<4>/*127:0*/ __Vtemp_1189;
    VlWide<4>/*127:0*/ __Vtemp_1192;
    VlWide<4>/*127:0*/ __Vtemp_1193;
    VlWide<4>/*127:0*/ __Vtemp_1198;
    VlWide<4>/*127:0*/ __Vtemp_1201;
    VlWide<4>/*127:0*/ __Vtemp_1202;
    VlWide<4>/*127:0*/ __Vtemp_1207;
    VlWide<4>/*127:0*/ __Vtemp_1231;
    VlWide<4>/*127:0*/ __Vtemp_1234;
    VlWide<4>/*127:0*/ __Vtemp_1236;
    VlWide<4>/*127:0*/ __Vtemp_1248;
    VlWide<4>/*127:0*/ __Vtemp_1249;
    VlWide<4>/*127:0*/ __Vtemp_1254;
    VlWide<4>/*127:0*/ __Vtemp_1257;
    VlWide<4>/*127:0*/ __Vtemp_1258;
    VlWide<4>/*127:0*/ __Vtemp_1263;
    VlWide<4>/*127:0*/ __Vtemp_1266;
    VlWide<4>/*127:0*/ __Vtemp_1267;
    VlWide<4>/*127:0*/ __Vtemp_1272;
    VlWide<4>/*127:0*/ __Vtemp_1296;
    VlWide<4>/*127:0*/ __Vtemp_1299;
    VlWide<4>/*127:0*/ __Vtemp_1301;
    VlWide<4>/*127:0*/ __Vtemp_1313;
    VlWide<4>/*127:0*/ __Vtemp_1314;
    VlWide<4>/*127:0*/ __Vtemp_1319;
    VlWide<4>/*127:0*/ __Vtemp_1322;
    VlWide<4>/*127:0*/ __Vtemp_1323;
    VlWide<4>/*127:0*/ __Vtemp_1328;
    VlWide<4>/*127:0*/ __Vtemp_1331;
    VlWide<4>/*127:0*/ __Vtemp_1332;
    VlWide<4>/*127:0*/ __Vtemp_1337;
    VlWide<4>/*127:0*/ __Vtemp_1361;
    VlWide<4>/*127:0*/ __Vtemp_1364;
    VlWide<4>/*127:0*/ __Vtemp_1366;
    VlWide<4>/*127:0*/ __Vtemp_1378;
    VlWide<4>/*127:0*/ __Vtemp_1379;
    VlWide<4>/*127:0*/ __Vtemp_1384;
    VlWide<4>/*127:0*/ __Vtemp_1387;
    VlWide<4>/*127:0*/ __Vtemp_1388;
    VlWide<4>/*127:0*/ __Vtemp_1393;
    VlWide<4>/*127:0*/ __Vtemp_1396;
    VlWide<4>/*127:0*/ __Vtemp_1397;
    VlWide<4>/*127:0*/ __Vtemp_1402;
    VlWide<4>/*127:0*/ __Vtemp_1426;
    VlWide<4>/*127:0*/ __Vtemp_1429;
    VlWide<4>/*127:0*/ __Vtemp_1431;
    VlWide<4>/*127:0*/ __Vtemp_1443;
    VlWide<4>/*127:0*/ __Vtemp_1444;
    VlWide<4>/*127:0*/ __Vtemp_1449;
    VlWide<4>/*127:0*/ __Vtemp_1452;
    VlWide<4>/*127:0*/ __Vtemp_1453;
    VlWide<4>/*127:0*/ __Vtemp_1458;
    VlWide<4>/*127:0*/ __Vtemp_1461;
    VlWide<4>/*127:0*/ __Vtemp_1462;
    VlWide<4>/*127:0*/ __Vtemp_1467;
    VlWide<4>/*127:0*/ __Vtemp_1491;
    VlWide<4>/*127:0*/ __Vtemp_1494;
    VlWide<4>/*127:0*/ __Vtemp_1496;
    VlWide<4>/*127:0*/ __Vtemp_1508;
    VlWide<4>/*127:0*/ __Vtemp_1509;
    VlWide<4>/*127:0*/ __Vtemp_1514;
    VlWide<4>/*127:0*/ __Vtemp_1517;
    VlWide<4>/*127:0*/ __Vtemp_1518;
    VlWide<4>/*127:0*/ __Vtemp_1523;
    VlWide<4>/*127:0*/ __Vtemp_1526;
    VlWide<4>/*127:0*/ __Vtemp_1527;
    VlWide<4>/*127:0*/ __Vtemp_1532;
    VlWide<4>/*127:0*/ __Vtemp_1556;
    VlWide<4>/*127:0*/ __Vtemp_1559;
    VlWide<4>/*127:0*/ __Vtemp_1561;
    VlWide<4>/*127:0*/ __Vtemp_1573;
    VlWide<4>/*127:0*/ __Vtemp_1574;
    VlWide<4>/*127:0*/ __Vtemp_1579;
    VlWide<4>/*127:0*/ __Vtemp_1582;
    VlWide<4>/*127:0*/ __Vtemp_1583;
    VlWide<4>/*127:0*/ __Vtemp_1588;
    VlWide<4>/*127:0*/ __Vtemp_1591;
    VlWide<4>/*127:0*/ __Vtemp_1592;
    VlWide<4>/*127:0*/ __Vtemp_1597;
    VlWide<4>/*127:0*/ __Vtemp_1621;
    VlWide<4>/*127:0*/ __Vtemp_1624;
    VlWide<4>/*127:0*/ __Vtemp_1626;
    VlWide<4>/*127:0*/ __Vtemp_1638;
    VlWide<4>/*127:0*/ __Vtemp_1639;
    VlWide<4>/*127:0*/ __Vtemp_1644;
    VlWide<4>/*127:0*/ __Vtemp_1647;
    VlWide<4>/*127:0*/ __Vtemp_1648;
    VlWide<4>/*127:0*/ __Vtemp_1653;
    VlWide<4>/*127:0*/ __Vtemp_1656;
    VlWide<4>/*127:0*/ __Vtemp_1657;
    VlWide<4>/*127:0*/ __Vtemp_1662;
    VlWide<4>/*127:0*/ __Vtemp_1686;
    VlWide<4>/*127:0*/ __Vtemp_1689;
    VlWide<4>/*127:0*/ __Vtemp_1691;
    // Body
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
    __Vtemp_14[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[0U];
    __Vtemp_14[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[1U];
    __Vtemp_14[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[2U];
    __Vtemp_14[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_15, __Vtemp_14);
    __Vtemp_17[0U] = __Vtemp_15[0U];
    __Vtemp_17[1U] = __Vtemp_15[1U];
    __Vtemp_17[2U] = __Vtemp_15[2U];
    __Vtemp_17[3U] = __Vtemp_15[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_20, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_carry_vec, 1U);
    __Vtemp_21[0U] = __Vtemp_20[0U];
    __Vtemp_21[1U] = __Vtemp_20[1U];
    __Vtemp_21[2U] = __Vtemp_20[2U];
    __Vtemp_21[3U] = (0x7fffffffU & __Vtemp_20[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_22, __Vtemp_21);
    __Vtemp_24[0U] = __Vtemp_22[0U];
    __Vtemp_24[1U] = __Vtemp_22[1U];
    __Vtemp_24[2U] = __Vtemp_22[2U];
    __Vtemp_24[3U] = __Vtemp_22[3U];
    VL_ADD_W(4, __Vtemp_25, __Vtemp_17, __Vtemp_24);
    __Vtemp_27[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st1_hot_ones;
    __Vtemp_27[1U] = 0U;
    __Vtemp_27[2U] = 0U;
    __Vtemp_27[3U] = 0U;
    VL_ADD_W(4, __Vtemp_28, __Vtemp_25, __Vtemp_27);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[0U] 
        = __Vtemp_28[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[1U] 
        = __Vtemp_28[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[2U] 
        = __Vtemp_28[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_28[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U])) {
        __Vtemp_30[0U] = 1U;
        __Vtemp_30[1U] = 0U;
        __Vtemp_30[2U] = 0U;
        __Vtemp_30[3U] = 0U;
        __Vtemp_31[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[0U]);
        __Vtemp_31[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[1U]);
        __Vtemp_31[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[2U]);
        __Vtemp_31[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_32, __Vtemp_30, __Vtemp_31);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[0U] 
            = __Vtemp_32[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[1U] 
            = __Vtemp_32[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[2U] 
            = __Vtemp_32[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_32[3U]);
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
    __Vtemp_38[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_38[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_38[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_38[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_39, __Vtemp_38);
    __Vtemp_41[0U] = __Vtemp_39[0U];
    __Vtemp_41[1U] = __Vtemp_39[1U];
    __Vtemp_41[2U] = __Vtemp_39[2U];
    __Vtemp_41[3U] = __Vtemp_39[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_44, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_45[0U] = __Vtemp_44[0U];
    __Vtemp_45[1U] = __Vtemp_44[1U];
    __Vtemp_45[2U] = __Vtemp_44[2U];
    __Vtemp_45[3U] = (0x7fffffffU & __Vtemp_44[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_46, __Vtemp_45);
    __Vtemp_48[0U] = __Vtemp_46[0U];
    __Vtemp_48[1U] = __Vtemp_46[1U];
    __Vtemp_48[2U] = __Vtemp_46[2U];
    __Vtemp_48[3U] = __Vtemp_46[3U];
    VL_ADD_W(4, __Vtemp_49, __Vtemp_41, __Vtemp_48);
    __Vtemp_51[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_51[1U] = 0U;
    __Vtemp_51[2U] = 0U;
    __Vtemp_51[3U] = 0U;
    VL_ADD_W(4, __Vtemp_52, __Vtemp_49, __Vtemp_51);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_52[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_52[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_52[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_52[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_54[0U] = 1U;
        __Vtemp_54[1U] = 0U;
        __Vtemp_54[2U] = 0U;
        __Vtemp_54[3U] = 0U;
        __Vtemp_55[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_55[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_55[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_55[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_56, __Vtemp_54, __Vtemp_55);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_56[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_56[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_56[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_56[3U]);
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
    __Vtemp_62[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_62[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_62[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_62[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_63, __Vtemp_62);
    __Vtemp_65[0U] = __Vtemp_63[0U];
    __Vtemp_65[1U] = __Vtemp_63[1U];
    __Vtemp_65[2U] = __Vtemp_63[2U];
    __Vtemp_65[3U] = __Vtemp_63[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_68, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_69[0U] = __Vtemp_68[0U];
    __Vtemp_69[1U] = __Vtemp_68[1U];
    __Vtemp_69[2U] = __Vtemp_68[2U];
    __Vtemp_69[3U] = (0x7fffffffU & __Vtemp_68[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_70, __Vtemp_69);
    __Vtemp_72[0U] = __Vtemp_70[0U];
    __Vtemp_72[1U] = __Vtemp_70[1U];
    __Vtemp_72[2U] = __Vtemp_70[2U];
    __Vtemp_72[3U] = __Vtemp_70[3U];
    VL_ADD_W(4, __Vtemp_73, __Vtemp_65, __Vtemp_72);
    __Vtemp_75[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_75[1U] = 0U;
    __Vtemp_75[2U] = 0U;
    __Vtemp_75[3U] = 0U;
    VL_ADD_W(4, __Vtemp_76, __Vtemp_73, __Vtemp_75);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_76[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_76[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_76[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_76[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_78[0U] = 1U;
        __Vtemp_78[1U] = 0U;
        __Vtemp_78[2U] = 0U;
        __Vtemp_78[3U] = 0U;
        __Vtemp_79[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_79[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_79[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_79[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_80, __Vtemp_78, __Vtemp_79);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_80[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_80[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_80[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_80[3U]);
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
    __Vtemp_86[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_86[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_86[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_86[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_87, __Vtemp_86);
    __Vtemp_89[0U] = __Vtemp_87[0U];
    __Vtemp_89[1U] = __Vtemp_87[1U];
    __Vtemp_89[2U] = __Vtemp_87[2U];
    __Vtemp_89[3U] = __Vtemp_87[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_92, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_93[0U] = __Vtemp_92[0U];
    __Vtemp_93[1U] = __Vtemp_92[1U];
    __Vtemp_93[2U] = __Vtemp_92[2U];
    __Vtemp_93[3U] = (0x7fffffffU & __Vtemp_92[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_94, __Vtemp_93);
    __Vtemp_96[0U] = __Vtemp_94[0U];
    __Vtemp_96[1U] = __Vtemp_94[1U];
    __Vtemp_96[2U] = __Vtemp_94[2U];
    __Vtemp_96[3U] = __Vtemp_94[3U];
    VL_ADD_W(4, __Vtemp_97, __Vtemp_89, __Vtemp_96);
    __Vtemp_99[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_99[1U] = 0U;
    __Vtemp_99[2U] = 0U;
    __Vtemp_99[3U] = 0U;
    VL_ADD_W(4, __Vtemp_100, __Vtemp_97, __Vtemp_99);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_100[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_100[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_100[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_100[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_102[0U] = 1U;
        __Vtemp_102[1U] = 0U;
        __Vtemp_102[2U] = 0U;
        __Vtemp_102[3U] = 0U;
        __Vtemp_103[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_103[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_103[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_103[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_104, __Vtemp_102, __Vtemp_103);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_104[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_104[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_104[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_104[3U]);
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
    __Vtemp_110[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_110[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_110[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_110[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_111, __Vtemp_110);
    __Vtemp_113[0U] = __Vtemp_111[0U];
    __Vtemp_113[1U] = __Vtemp_111[1U];
    __Vtemp_113[2U] = __Vtemp_111[2U];
    __Vtemp_113[3U] = __Vtemp_111[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_116, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_117[0U] = __Vtemp_116[0U];
    __Vtemp_117[1U] = __Vtemp_116[1U];
    __Vtemp_117[2U] = __Vtemp_116[2U];
    __Vtemp_117[3U] = (0x7fffffffU & __Vtemp_116[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_118, __Vtemp_117);
    __Vtemp_120[0U] = __Vtemp_118[0U];
    __Vtemp_120[1U] = __Vtemp_118[1U];
    __Vtemp_120[2U] = __Vtemp_118[2U];
    __Vtemp_120[3U] = __Vtemp_118[3U];
    VL_ADD_W(4, __Vtemp_121, __Vtemp_113, __Vtemp_120);
    __Vtemp_123[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_123[1U] = 0U;
    __Vtemp_123[2U] = 0U;
    __Vtemp_123[3U] = 0U;
    VL_ADD_W(4, __Vtemp_124, __Vtemp_121, __Vtemp_123);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_124[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_124[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_124[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_124[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_126[0U] = 1U;
        __Vtemp_126[1U] = 0U;
        __Vtemp_126[2U] = 0U;
        __Vtemp_126[3U] = 0U;
        __Vtemp_127[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_127[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_127[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_127[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_128, __Vtemp_126, __Vtemp_127);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_128[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_128[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_128[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_128[3U]);
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
    __Vtemp_134[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_134[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_134[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_134[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_135, __Vtemp_134);
    __Vtemp_137[0U] = __Vtemp_135[0U];
    __Vtemp_137[1U] = __Vtemp_135[1U];
    __Vtemp_137[2U] = __Vtemp_135[2U];
    __Vtemp_137[3U] = __Vtemp_135[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_140, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_141[0U] = __Vtemp_140[0U];
    __Vtemp_141[1U] = __Vtemp_140[1U];
    __Vtemp_141[2U] = __Vtemp_140[2U];
    __Vtemp_141[3U] = (0x7fffffffU & __Vtemp_140[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_142, __Vtemp_141);
    __Vtemp_144[0U] = __Vtemp_142[0U];
    __Vtemp_144[1U] = __Vtemp_142[1U];
    __Vtemp_144[2U] = __Vtemp_142[2U];
    __Vtemp_144[3U] = __Vtemp_142[3U];
    VL_ADD_W(4, __Vtemp_145, __Vtemp_137, __Vtemp_144);
    __Vtemp_147[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_147[1U] = 0U;
    __Vtemp_147[2U] = 0U;
    __Vtemp_147[3U] = 0U;
    VL_ADD_W(4, __Vtemp_148, __Vtemp_145, __Vtemp_147);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_148[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_148[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_148[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_148[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_150[0U] = 1U;
        __Vtemp_150[1U] = 0U;
        __Vtemp_150[2U] = 0U;
        __Vtemp_150[3U] = 0U;
        __Vtemp_151[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_151[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_151[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_151[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_152, __Vtemp_150, __Vtemp_151);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_152[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_152[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_152[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_152[3U]);
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
    __Vtemp_158[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_158[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_158[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_158[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_159, __Vtemp_158);
    __Vtemp_161[0U] = __Vtemp_159[0U];
    __Vtemp_161[1U] = __Vtemp_159[1U];
    __Vtemp_161[2U] = __Vtemp_159[2U];
    __Vtemp_161[3U] = __Vtemp_159[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_164, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_165[0U] = __Vtemp_164[0U];
    __Vtemp_165[1U] = __Vtemp_164[1U];
    __Vtemp_165[2U] = __Vtemp_164[2U];
    __Vtemp_165[3U] = (0x7fffffffU & __Vtemp_164[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_166, __Vtemp_165);
    __Vtemp_168[0U] = __Vtemp_166[0U];
    __Vtemp_168[1U] = __Vtemp_166[1U];
    __Vtemp_168[2U] = __Vtemp_166[2U];
    __Vtemp_168[3U] = __Vtemp_166[3U];
    VL_ADD_W(4, __Vtemp_169, __Vtemp_161, __Vtemp_168);
    __Vtemp_171[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_171[1U] = 0U;
    __Vtemp_171[2U] = 0U;
    __Vtemp_171[3U] = 0U;
    VL_ADD_W(4, __Vtemp_172, __Vtemp_169, __Vtemp_171);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_172[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_172[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_172[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_172[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_174[0U] = 1U;
        __Vtemp_174[1U] = 0U;
        __Vtemp_174[2U] = 0U;
        __Vtemp_174[3U] = 0U;
        __Vtemp_175[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_175[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_175[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_175[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_176, __Vtemp_174, __Vtemp_175);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_176[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_176[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_176[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_176[3U]);
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
    __Vtemp_182[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_182[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_182[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_182[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_183, __Vtemp_182);
    __Vtemp_185[0U] = __Vtemp_183[0U];
    __Vtemp_185[1U] = __Vtemp_183[1U];
    __Vtemp_185[2U] = __Vtemp_183[2U];
    __Vtemp_185[3U] = __Vtemp_183[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_188, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_189[0U] = __Vtemp_188[0U];
    __Vtemp_189[1U] = __Vtemp_188[1U];
    __Vtemp_189[2U] = __Vtemp_188[2U];
    __Vtemp_189[3U] = (0x7fffffffU & __Vtemp_188[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_190, __Vtemp_189);
    __Vtemp_192[0U] = __Vtemp_190[0U];
    __Vtemp_192[1U] = __Vtemp_190[1U];
    __Vtemp_192[2U] = __Vtemp_190[2U];
    __Vtemp_192[3U] = __Vtemp_190[3U];
    VL_ADD_W(4, __Vtemp_193, __Vtemp_185, __Vtemp_192);
    __Vtemp_195[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_195[1U] = 0U;
    __Vtemp_195[2U] = 0U;
    __Vtemp_195[3U] = 0U;
    VL_ADD_W(4, __Vtemp_196, __Vtemp_193, __Vtemp_195);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_196[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_196[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_196[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_196[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_198[0U] = 1U;
        __Vtemp_198[1U] = 0U;
        __Vtemp_198[2U] = 0U;
        __Vtemp_198[3U] = 0U;
        __Vtemp_199[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_199[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_199[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_199[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_200, __Vtemp_198, __Vtemp_199);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_200[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_200[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_200[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_200[3U]);
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
    __Vtemp_206[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[0U];
    __Vtemp_206[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[1U];
    __Vtemp_206[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[2U];
    __Vtemp_206[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_207, __Vtemp_206);
    __Vtemp_209[0U] = __Vtemp_207[0U];
    __Vtemp_209[1U] = __Vtemp_207[1U];
    __Vtemp_209[2U] = __Vtemp_207[2U];
    __Vtemp_209[3U] = __Vtemp_207[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_212, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_carry_vec, 1U);
    __Vtemp_213[0U] = __Vtemp_212[0U];
    __Vtemp_213[1U] = __Vtemp_212[1U];
    __Vtemp_213[2U] = __Vtemp_212[2U];
    __Vtemp_213[3U] = (0x7fffffffU & __Vtemp_212[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_214, __Vtemp_213);
    __Vtemp_216[0U] = __Vtemp_214[0U];
    __Vtemp_216[1U] = __Vtemp_214[1U];
    __Vtemp_216[2U] = __Vtemp_214[2U];
    __Vtemp_216[3U] = __Vtemp_214[3U];
    VL_ADD_W(4, __Vtemp_217, __Vtemp_209, __Vtemp_216);
    __Vtemp_219[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st1_hot_ones;
    __Vtemp_219[1U] = 0U;
    __Vtemp_219[2U] = 0U;
    __Vtemp_219[3U] = 0U;
    VL_ADD_W(4, __Vtemp_220, __Vtemp_217, __Vtemp_219);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[0U] 
        = __Vtemp_220[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[1U] 
        = __Vtemp_220[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[2U] 
        = __Vtemp_220[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_220[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U])) {
        __Vtemp_222[0U] = 1U;
        __Vtemp_222[1U] = 0U;
        __Vtemp_222[2U] = 0U;
        __Vtemp_222[3U] = 0U;
        __Vtemp_223[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[0U]);
        __Vtemp_223[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[1U]);
        __Vtemp_223[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[2U]);
        __Vtemp_223[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_224, __Vtemp_222, __Vtemp_223);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[0U] 
            = __Vtemp_224[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[1U] 
            = __Vtemp_224[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[2U] 
            = __Vtemp_224[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_224[3U]);
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
    __Vtemp_230[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[0U];
    __Vtemp_230[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[1U];
    __Vtemp_230[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[2U];
    __Vtemp_230[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_231, __Vtemp_230);
    __Vtemp_233[0U] = __Vtemp_231[0U];
    __Vtemp_233[1U] = __Vtemp_231[1U];
    __Vtemp_233[2U] = __Vtemp_231[2U];
    __Vtemp_233[3U] = __Vtemp_231[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_236, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U);
    __Vtemp_237[0U] = __Vtemp_236[0U];
    __Vtemp_237[1U] = __Vtemp_236[1U];
    __Vtemp_237[2U] = __Vtemp_236[2U];
    __Vtemp_237[3U] = (0x7fffffffU & __Vtemp_236[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_238, __Vtemp_237);
    __Vtemp_240[0U] = __Vtemp_238[0U];
    __Vtemp_240[1U] = __Vtemp_238[1U];
    __Vtemp_240[2U] = __Vtemp_238[2U];
    __Vtemp_240[3U] = __Vtemp_238[3U];
    VL_ADD_W(4, __Vtemp_241, __Vtemp_233, __Vtemp_240);
    __Vtemp_243[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st1_hot_ones;
    __Vtemp_243[1U] = 0U;
    __Vtemp_243[2U] = 0U;
    __Vtemp_243[3U] = 0U;
    VL_ADD_W(4, __Vtemp_244, __Vtemp_241, __Vtemp_243);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[0U] 
        = __Vtemp_244[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[1U] 
        = __Vtemp_244[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[2U] 
        = __Vtemp_244[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_244[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U])) {
        __Vtemp_246[0U] = 1U;
        __Vtemp_246[1U] = 0U;
        __Vtemp_246[2U] = 0U;
        __Vtemp_246[3U] = 0U;
        __Vtemp_247[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[0U]);
        __Vtemp_247[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[1U]);
        __Vtemp_247[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[2U]);
        __Vtemp_247[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_248, __Vtemp_246, __Vtemp_247);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = __Vtemp_248[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = __Vtemp_248[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = __Vtemp_248[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_248[3U]);
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
    __Vtemp_254[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[0U];
    __Vtemp_254[1U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[1U];
    __Vtemp_254[2U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[2U];
    __Vtemp_254[3U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_sum_vec[3U];
    VL_EXTENDS_WW(129,128, __Vtemp_255, __Vtemp_254);
    __Vtemp_257[0U] = __Vtemp_255[0U];
    __Vtemp_257[1U] = __Vtemp_255[1U];
    __Vtemp_257[2U] = __Vtemp_255[2U];
    __Vtemp_257[3U] = __Vtemp_255[3U];
    VL_SHIFTL_WWI(127,127,32, __Vtemp_260, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_carry_vec, 1U);
    __Vtemp_261[0U] = __Vtemp_260[0U];
    __Vtemp_261[1U] = __Vtemp_260[1U];
    __Vtemp_261[2U] = __Vtemp_260[2U];
    __Vtemp_261[3U] = (0x7fffffffU & __Vtemp_260[3U]);
    VL_EXTENDS_WW(129,127, __Vtemp_262, __Vtemp_261);
    __Vtemp_264[0U] = __Vtemp_262[0U];
    __Vtemp_264[1U] = __Vtemp_262[1U];
    __Vtemp_264[2U] = __Vtemp_262[2U];
    __Vtemp_264[3U] = __Vtemp_262[3U];
    VL_ADD_W(4, __Vtemp_265, __Vtemp_257, __Vtemp_264);
    __Vtemp_267[0U] = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st1_hot_ones;
    __Vtemp_267[1U] = 0U;
    __Vtemp_267[2U] = 0U;
    __Vtemp_267[3U] = 0U;
    VL_ADD_W(4, __Vtemp_268, __Vtemp_265, __Vtemp_267);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[0U] 
        = __Vtemp_268[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[1U] 
        = __Vtemp_268[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[2U] 
        = __Vtemp_268[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U] 
        = (0x7fffffffU & __Vtemp_268[3U]);
    if ((0x40000000U & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U])) {
        __Vtemp_270[0U] = 1U;
        __Vtemp_270[1U] = 0U;
        __Vtemp_270[2U] = 0U;
        __Vtemp_270[3U] = 0U;
        __Vtemp_271[0U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[0U]);
        __Vtemp_271[1U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[1U]);
        __Vtemp_271[2U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[2U]);
        __Vtemp_271[3U] = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__raw_sum[3U]);
        VL_ADD_W(4, __Vtemp_272, __Vtemp_270, __Vtemp_271);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[0U] 
            = __Vtemp_272[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[1U] 
            = __Vtemp_272[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[2U] 
            = __Vtemp_272[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__mag_sum[3U] 
            = (0x7fffffffU & __Vtemp_272[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_279, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_279[0U] | __Vtemp_279[1U]) 
                     | __Vtemp_279[2U]) | (0x7fffffffU 
                                           & __Vtemp_279[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_284, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_284[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_284[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_284[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_284[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_287, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_287[0U] | __Vtemp_287[1U]) 
                     | __Vtemp_287[2U]) | (0x7fffffffU 
                                           & __Vtemp_287[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_292, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_292[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_292[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_292[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_292[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_295, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_295[0U] | __Vtemp_295[1U]) 
                     | __Vtemp_295[2U]) | (0x7fffffffU 
                                           & __Vtemp_295[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_300, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_300[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_300[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_300[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_300[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_303, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_303[0U] | __Vtemp_303[1U]) 
                     | __Vtemp_303[2U]) | (0x7fffffffU 
                                           & __Vtemp_303[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_308, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_308[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_308[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_308[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_308[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_311, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_311[0U] | __Vtemp_311[1U]) 
                     | __Vtemp_311[2U]) | (0x7fffffffU 
                                           & __Vtemp_311[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_316, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_316[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_316[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_316[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_316[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_319, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_319[0U] | __Vtemp_319[1U]) 
                     | __Vtemp_319[2U]) | (0x7fffffffU 
                                           & __Vtemp_319[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_324, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_324[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_324[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_324[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_324[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_327, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_327[0U] | __Vtemp_327[1U]) 
                     | __Vtemp_327[2U]) | (0x7fffffffU 
                                           & __Vtemp_327[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_332, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[0U] 
                = __Vtemp_332[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[1U] 
                = __Vtemp_332[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[2U] 
                = __Vtemp_332[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_332[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_334, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[0U] 
        = __Vtemp_334[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[1U] 
        = __Vtemp_334[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[2U] 
        = __Vtemp_334[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_334[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_343, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_343[0U] | __Vtemp_343[1U]) 
                     | __Vtemp_343[2U]) | (0x7fffffffU 
                                           & __Vtemp_343[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_348, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_348[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_348[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_348[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_348[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_351, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_351[0U] | __Vtemp_351[1U]) 
                     | __Vtemp_351[2U]) | (0x7fffffffU 
                                           & __Vtemp_351[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_356, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_356[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_356[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_356[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_356[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_359, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_359[0U] | __Vtemp_359[1U]) 
                     | __Vtemp_359[2U]) | (0x7fffffffU 
                                           & __Vtemp_359[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_364, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_364[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_364[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_364[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_364[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_367, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_367[0U] | __Vtemp_367[1U]) 
                     | __Vtemp_367[2U]) | (0x7fffffffU 
                                           & __Vtemp_367[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_372, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_372[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_372[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_372[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_372[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_375, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_375[0U] | __Vtemp_375[1U]) 
                     | __Vtemp_375[2U]) | (0x7fffffffU 
                                           & __Vtemp_375[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_380, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_380[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_380[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_380[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_380[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_383, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_383[0U] | __Vtemp_383[1U]) 
                     | __Vtemp_383[2U]) | (0x7fffffffU 
                                           & __Vtemp_383[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_388, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_388[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_388[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_388[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_388[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_391, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_391[0U] | __Vtemp_391[1U]) 
                     | __Vtemp_391[2U]) | (0x7fffffffU 
                                           & __Vtemp_391[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_396, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_396[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_396[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_396[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_396[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_398, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_398[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_398[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_398[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_398[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_407, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_407[0U] | __Vtemp_407[1U]) 
                     | __Vtemp_407[2U]) | (0x7fffffffU 
                                           & __Vtemp_407[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_412, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_412[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_412[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_412[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_412[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_415, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_415[0U] | __Vtemp_415[1U]) 
                     | __Vtemp_415[2U]) | (0x7fffffffU 
                                           & __Vtemp_415[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_420, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_420[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_420[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_420[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_420[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_423, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_423[0U] | __Vtemp_423[1U]) 
                     | __Vtemp_423[2U]) | (0x7fffffffU 
                                           & __Vtemp_423[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_428, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_428[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_428[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_428[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_428[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_431, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_431[0U] | __Vtemp_431[1U]) 
                     | __Vtemp_431[2U]) | (0x7fffffffU 
                                           & __Vtemp_431[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_436, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_436[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_436[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_436[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_436[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_439, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_439[0U] | __Vtemp_439[1U]) 
                     | __Vtemp_439[2U]) | (0x7fffffffU 
                                           & __Vtemp_439[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_444, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_444[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_444[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_444[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_444[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_447, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_447[0U] | __Vtemp_447[1U]) 
                     | __Vtemp_447[2U]) | (0x7fffffffU 
                                           & __Vtemp_447[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_452, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_452[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_452[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_452[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_452[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_455, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_455[0U] | __Vtemp_455[1U]) 
                     | __Vtemp_455[2U]) | (0x7fffffffU 
                                           & __Vtemp_455[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_460, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_460[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_460[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_460[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_460[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_462, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_462[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_462[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_462[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_462[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_471, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_471[0U] | __Vtemp_471[1U]) 
                     | __Vtemp_471[2U]) | (0x7fffffffU 
                                           & __Vtemp_471[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_476, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_476[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_476[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_476[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_476[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_479, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_479[0U] | __Vtemp_479[1U]) 
                     | __Vtemp_479[2U]) | (0x7fffffffU 
                                           & __Vtemp_479[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_484, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_484[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_484[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_484[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_484[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_487, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_487[0U] | __Vtemp_487[1U]) 
                     | __Vtemp_487[2U]) | (0x7fffffffU 
                                           & __Vtemp_487[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_492, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_492[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_492[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_492[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_492[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_495, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_495[0U] | __Vtemp_495[1U]) 
                     | __Vtemp_495[2U]) | (0x7fffffffU 
                                           & __Vtemp_495[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_500, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_500[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_500[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_500[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_500[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_503, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_503[0U] | __Vtemp_503[1U]) 
                     | __Vtemp_503[2U]) | (0x7fffffffU 
                                           & __Vtemp_503[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_508, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_508[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_508[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_508[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_508[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_511, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_511[0U] | __Vtemp_511[1U]) 
                     | __Vtemp_511[2U]) | (0x7fffffffU 
                                           & __Vtemp_511[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_516, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_516[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_516[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_516[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_516[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_519, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_519[0U] | __Vtemp_519[1U]) 
                     | __Vtemp_519[2U]) | (0x7fffffffU 
                                           & __Vtemp_519[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_524, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_524[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_524[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_524[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_524[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_526, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_526[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_526[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_526[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_526[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_535, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_535[0U] | __Vtemp_535[1U]) 
                     | __Vtemp_535[2U]) | (0x7fffffffU 
                                           & __Vtemp_535[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_540, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_540[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_540[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_540[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_540[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_543, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_543[0U] | __Vtemp_543[1U]) 
                     | __Vtemp_543[2U]) | (0x7fffffffU 
                                           & __Vtemp_543[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_548, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_548[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_548[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_548[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_548[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_551, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_551[0U] | __Vtemp_551[1U]) 
                     | __Vtemp_551[2U]) | (0x7fffffffU 
                                           & __Vtemp_551[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_556, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_556[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_556[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_556[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_556[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_559, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_559[0U] | __Vtemp_559[1U]) 
                     | __Vtemp_559[2U]) | (0x7fffffffU 
                                           & __Vtemp_559[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_564, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_564[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_564[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_564[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_564[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_567, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_567[0U] | __Vtemp_567[1U]) 
                     | __Vtemp_567[2U]) | (0x7fffffffU 
                                           & __Vtemp_567[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_572, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_572[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_572[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_572[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_572[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_575, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_575[0U] | __Vtemp_575[1U]) 
                     | __Vtemp_575[2U]) | (0x7fffffffU 
                                           & __Vtemp_575[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_580, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_580[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_580[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_580[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_580[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_583, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_583[0U] | __Vtemp_583[1U]) 
                     | __Vtemp_583[2U]) | (0x7fffffffU 
                                           & __Vtemp_583[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_588, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_588[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_588[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_588[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_588[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_590, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_590[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_590[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_590[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_590[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_599, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_599[0U] | __Vtemp_599[1U]) 
                     | __Vtemp_599[2U]) | (0x7fffffffU 
                                           & __Vtemp_599[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_604, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_604[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_604[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_604[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_604[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_607, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_607[0U] | __Vtemp_607[1U]) 
                     | __Vtemp_607[2U]) | (0x7fffffffU 
                                           & __Vtemp_607[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_612, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_612[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_612[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_612[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_612[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_615, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_615[0U] | __Vtemp_615[1U]) 
                     | __Vtemp_615[2U]) | (0x7fffffffU 
                                           & __Vtemp_615[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_620, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_620[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_620[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_620[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_620[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_623, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_623[0U] | __Vtemp_623[1U]) 
                     | __Vtemp_623[2U]) | (0x7fffffffU 
                                           & __Vtemp_623[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_628, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_628[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_628[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_628[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_628[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_631, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_631[0U] | __Vtemp_631[1U]) 
                     | __Vtemp_631[2U]) | (0x7fffffffU 
                                           & __Vtemp_631[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_636, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_636[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_636[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_636[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_636[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_639, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_639[0U] | __Vtemp_639[1U]) 
                     | __Vtemp_639[2U]) | (0x7fffffffU 
                                           & __Vtemp_639[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_644, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_644[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_644[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_644[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_644[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_647, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_647[0U] | __Vtemp_647[1U]) 
                     | __Vtemp_647[2U]) | (0x7fffffffU 
                                           & __Vtemp_647[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_652, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_652[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_652[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_652[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_652[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_654, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_654[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_654[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_654[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_654[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_663, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_663[0U] | __Vtemp_663[1U]) 
                     | __Vtemp_663[2U]) | (0x7fffffffU 
                                           & __Vtemp_663[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_668, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_668[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_668[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_668[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_668[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_671, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_671[0U] | __Vtemp_671[1U]) 
                     | __Vtemp_671[2U]) | (0x7fffffffU 
                                           & __Vtemp_671[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_676, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_676[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_676[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_676[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_676[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_679, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_679[0U] | __Vtemp_679[1U]) 
                     | __Vtemp_679[2U]) | (0x7fffffffU 
                                           & __Vtemp_679[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_684, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_684[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_684[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_684[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_684[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_687, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_687[0U] | __Vtemp_687[1U]) 
                     | __Vtemp_687[2U]) | (0x7fffffffU 
                                           & __Vtemp_687[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_692, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_692[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_692[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_692[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_692[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_695, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_695[0U] | __Vtemp_695[1U]) 
                     | __Vtemp_695[2U]) | (0x7fffffffU 
                                           & __Vtemp_695[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_700, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_700[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_700[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_700[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_700[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_703, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_703[0U] | __Vtemp_703[1U]) 
                     | __Vtemp_703[2U]) | (0x7fffffffU 
                                           & __Vtemp_703[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_708, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_708[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_708[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_708[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_708[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_711, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_711[0U] | __Vtemp_711[1U]) 
                     | __Vtemp_711[2U]) | (0x7fffffffU 
                                           & __Vtemp_711[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_716, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_716[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_716[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_716[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_716[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_718, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_718[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_718[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_718[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_718[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_727, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_727[0U] | __Vtemp_727[1U]) 
                     | __Vtemp_727[2U]) | (0x7fffffffU 
                                           & __Vtemp_727[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_732, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_732[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_732[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_732[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_732[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_735, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_735[0U] | __Vtemp_735[1U]) 
                     | __Vtemp_735[2U]) | (0x7fffffffU 
                                           & __Vtemp_735[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_740, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_740[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_740[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_740[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_740[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_743, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_743[0U] | __Vtemp_743[1U]) 
                     | __Vtemp_743[2U]) | (0x7fffffffU 
                                           & __Vtemp_743[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_748, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_748[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_748[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_748[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_748[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_751, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_751[0U] | __Vtemp_751[1U]) 
                     | __Vtemp_751[2U]) | (0x7fffffffU 
                                           & __Vtemp_751[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_756, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_756[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_756[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_756[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_756[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_759, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_759[0U] | __Vtemp_759[1U]) 
                     | __Vtemp_759[2U]) | (0x7fffffffU 
                                           & __Vtemp_759[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_764, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_764[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_764[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_764[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_764[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_767, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_767[0U] | __Vtemp_767[1U]) 
                     | __Vtemp_767[2U]) | (0x7fffffffU 
                                           & __Vtemp_767[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_772, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_772[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_772[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_772[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_772[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_775, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_775[0U] | __Vtemp_775[1U]) 
                     | __Vtemp_775[2U]) | (0x7fffffffU 
                                           & __Vtemp_775[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_780, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_780[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_780[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_780[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_780[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_782, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_782[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_782[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_782[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_782[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_791, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_791[0U] | __Vtemp_791[1U]) 
                     | __Vtemp_791[2U]) | (0x7fffffffU 
                                           & __Vtemp_791[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_796, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_796[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_796[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_796[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_796[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_799, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_799[0U] | __Vtemp_799[1U]) 
                     | __Vtemp_799[2U]) | (0x7fffffffU 
                                           & __Vtemp_799[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_804, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_804[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_804[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_804[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_804[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_807, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_807[0U] | __Vtemp_807[1U]) 
                     | __Vtemp_807[2U]) | (0x7fffffffU 
                                           & __Vtemp_807[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_812, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_812[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_812[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_812[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_812[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_815, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_815[0U] | __Vtemp_815[1U]) 
                     | __Vtemp_815[2U]) | (0x7fffffffU 
                                           & __Vtemp_815[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_820, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_820[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_820[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_820[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_820[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_823, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_823[0U] | __Vtemp_823[1U]) 
                     | __Vtemp_823[2U]) | (0x7fffffffU 
                                           & __Vtemp_823[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_828, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_828[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_828[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_828[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_828[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_831, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_831[0U] | __Vtemp_831[1U]) 
                     | __Vtemp_831[2U]) | (0x7fffffffU 
                                           & __Vtemp_831[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_836, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_836[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_836[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_836[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_836[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_839, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_839[0U] | __Vtemp_839[1U]) 
                     | __Vtemp_839[2U]) | (0x7fffffffU 
                                           & __Vtemp_839[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_844, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[0U] 
                = __Vtemp_844[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[1U] 
                = __Vtemp_844[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[2U] 
                = __Vtemp_844[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_844[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_846, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[0U] 
        = __Vtemp_846[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[1U] 
        = __Vtemp_846[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[2U] 
        = __Vtemp_846[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_846[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_855, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_855[0U] | __Vtemp_855[1U]) 
                     | __Vtemp_855[2U]) | (0x7fffffffU 
                                           & __Vtemp_855[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_860, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_860[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_860[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_860[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_860[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_863, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_863[0U] | __Vtemp_863[1U]) 
                     | __Vtemp_863[2U]) | (0x7fffffffU 
                                           & __Vtemp_863[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_868, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_868[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_868[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_868[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_868[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_871, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_871[0U] | __Vtemp_871[1U]) 
                     | __Vtemp_871[2U]) | (0x7fffffffU 
                                           & __Vtemp_871[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_876, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_876[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_876[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_876[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_876[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_879, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_879[0U] | __Vtemp_879[1U]) 
                     | __Vtemp_879[2U]) | (0x7fffffffU 
                                           & __Vtemp_879[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_884, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_884[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_884[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_884[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_884[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_887, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_887[0U] | __Vtemp_887[1U]) 
                     | __Vtemp_887[2U]) | (0x7fffffffU 
                                           & __Vtemp_887[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_892, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_892[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_892[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_892[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_892[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_895, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_895[0U] | __Vtemp_895[1U]) 
                     | __Vtemp_895[2U]) | (0x7fffffffU 
                                           & __Vtemp_895[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_900, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_900[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_900[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_900[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_900[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_903, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_903[0U] | __Vtemp_903[1U]) 
                     | __Vtemp_903[2U]) | (0x7fffffffU 
                                           & __Vtemp_903[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_908, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_908[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_908[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_908[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_908[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_910, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[0U] 
        = __Vtemp_910[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[1U] 
        = __Vtemp_910[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[2U] 
        = __Vtemp_910[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_910[3U]);
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
        VL_SHIFTR_WWI(127,127,32, __Vtemp_919, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x3fU);
        if ((0U == (((__Vtemp_919[0U] | __Vtemp_919[1U]) 
                     | __Vtemp_919[2U]) | (0x7fffffffU 
                                           & __Vtemp_919[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x40U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_924, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x40U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_924[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_924[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_924[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_924[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_927, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x5fU);
        if ((0U == (((__Vtemp_927[0U] | __Vtemp_927[1U]) 
                     | __Vtemp_927[2U]) | (0x7fffffffU 
                                           & __Vtemp_927[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x20U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_932, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x20U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_932[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_932[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_932[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_932[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_935, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x6fU);
        if ((0U == (((__Vtemp_935[0U] | __Vtemp_935[1U]) 
                     | __Vtemp_935[2U]) | (0x7fffffffU 
                                           & __Vtemp_935[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(0x10U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_940, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x10U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_940[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_940[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_940[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_940[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_943, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x77U);
        if ((0U == (((__Vtemp_943[0U] | __Vtemp_943[1U]) 
                     | __Vtemp_943[2U]) | (0x7fffffffU 
                                           & __Vtemp_943[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(8U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_948, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 8U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_948[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_948[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_948[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_948[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_951, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7bU);
        if ((0U == (((__Vtemp_951[0U] | __Vtemp_951[1U]) 
                     | __Vtemp_951[2U]) | (0x7fffffffU 
                                           & __Vtemp_951[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(4U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_956, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 4U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_956[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_956[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_956[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_956[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_959, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7dU);
        if ((0U == (((__Vtemp_959[0U] | __Vtemp_959[1U]) 
                     | __Vtemp_959[2U]) | (0x7fffffffU 
                                           & __Vtemp_959[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(2U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_964, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 2U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_964[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_964[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_964[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_964[3U]);
        }
        VL_SHIFTR_WWI(127,127,32, __Vtemp_967, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 0x7eU);
        if ((0U == (((__Vtemp_967[0U] | __Vtemp_967[1U]) 
                     | __Vtemp_967[2U]) | (0x7fffffffU 
                                           & __Vtemp_967[3U])))) {
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros 
                = (0x7fU & ((IData)(1U) + (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros)));
            VL_SHIFTL_WWI(127,127,32, __Vtemp_972, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan, 1U);
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[0U] 
                = __Vtemp_972[0U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[1U] 
                = __Vtemp_972[1U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[2U] 
                = __Vtemp_972[2U];
            vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lzd_scan[3U] 
                = (0x7fffffffU & __Vtemp_972[3U]);
        }
    }
    VL_SHIFTL_WWI(127,127,7, __Vtemp_974, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__st2_sum_mag, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__lead_zeros));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[0U] 
        = __Vtemp_974[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[1U] 
        = __Vtemp_974[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[2U] 
        = __Vtemp_974[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__norm_val[3U] 
        = (0x7fffffffU & __Vtemp_974[3U]);
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
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[1U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_988[0U] = 0xffffffffU;
    __Vtemp_988[1U] = 0xffffffffU;
    __Vtemp_988[2U] = 0xffffffffU;
    __Vtemp_988[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_989, __Vtemp_988, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_989[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_989[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_989[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_989[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_994, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_994[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_994[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_994[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_994[3U]);
    }
    __Vtemp_997[0U] = 0xffffffffU;
    __Vtemp_997[1U] = 0xffffffffU;
    __Vtemp_997[2U] = 0xffffffffU;
    __Vtemp_997[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_998, __Vtemp_997, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_998[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                               & (~ 
                                                  __Vtemp_998[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_998[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                 & (~ 
                                                    __Vtemp_998[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1003, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1003[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1003[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1003[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1003[3U]);
    }
    __Vtemp_1006[0U] = 0xffffffffU;
    __Vtemp_1006[1U] = 0xffffffffU;
    __Vtemp_1006[2U] = 0xffffffffU;
    __Vtemp_1006[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1007, __Vtemp_1006, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1007[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1007[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1007[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1007[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1012, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1012[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1012[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1012[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1012[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1036, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1036[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1036[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1036[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1036[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1039, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1041, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1039[0U]) | (__Vtemp_1041[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1039[1U]) | (__Vtemp_1041[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1039[2U]) | (__Vtemp_1041[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1039[3U]) | (__Vtemp_1041[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__0__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[2U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[3U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1053[0U] = 0xffffffffU;
    __Vtemp_1053[1U] = 0xffffffffU;
    __Vtemp_1053[2U] = 0xffffffffU;
    __Vtemp_1053[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1054, __Vtemp_1053, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1054[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1054[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1054[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1054[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1059, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1059[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1059[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1059[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1059[3U]);
    }
    __Vtemp_1062[0U] = 0xffffffffU;
    __Vtemp_1062[1U] = 0xffffffffU;
    __Vtemp_1062[2U] = 0xffffffffU;
    __Vtemp_1062[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1063, __Vtemp_1062, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1063[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1063[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1063[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1063[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1068, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1068[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1068[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1068[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1068[3U]);
    }
    __Vtemp_1071[0U] = 0xffffffffU;
    __Vtemp_1071[1U] = 0xffffffffU;
    __Vtemp_1071[2U] = 0xffffffffU;
    __Vtemp_1071[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1072, __Vtemp_1071, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1072[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1072[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1072[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1072[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1077, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1077[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1077[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1077[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1077[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1101, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1101[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1101[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1101[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1101[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1104, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1106, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1104[0U]) | (__Vtemp_1106[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1104[1U]) | (__Vtemp_1106[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1104[2U]) | (__Vtemp_1106[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1104[3U]) | (__Vtemp_1106[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__1__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[4U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[5U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1118[0U] = 0xffffffffU;
    __Vtemp_1118[1U] = 0xffffffffU;
    __Vtemp_1118[2U] = 0xffffffffU;
    __Vtemp_1118[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1119, __Vtemp_1118, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1119[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1119[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1119[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1119[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1124, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1124[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1124[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1124[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1124[3U]);
    }
    __Vtemp_1127[0U] = 0xffffffffU;
    __Vtemp_1127[1U] = 0xffffffffU;
    __Vtemp_1127[2U] = 0xffffffffU;
    __Vtemp_1127[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1128, __Vtemp_1127, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1128[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1128[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1128[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1128[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1133, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1133[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1133[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1133[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1133[3U]);
    }
    __Vtemp_1136[0U] = 0xffffffffU;
    __Vtemp_1136[1U] = 0xffffffffU;
    __Vtemp_1136[2U] = 0xffffffffU;
    __Vtemp_1136[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1137, __Vtemp_1136, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1137[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1137[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1137[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1137[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1142, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1142[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1142[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1142[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1142[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1166, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1166[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1166[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1166[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1166[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1169, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1171, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1169[0U]) | (__Vtemp_1171[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1169[1U]) | (__Vtemp_1171[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1169[2U]) | (__Vtemp_1171[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1169[3U]) | (__Vtemp_1171[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__2__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[6U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[7U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1183[0U] = 0xffffffffU;
    __Vtemp_1183[1U] = 0xffffffffU;
    __Vtemp_1183[2U] = 0xffffffffU;
    __Vtemp_1183[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1184, __Vtemp_1183, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1184[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1184[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1184[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1184[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1189, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1189[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1189[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1189[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1189[3U]);
    }
    __Vtemp_1192[0U] = 0xffffffffU;
    __Vtemp_1192[1U] = 0xffffffffU;
    __Vtemp_1192[2U] = 0xffffffffU;
    __Vtemp_1192[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1193, __Vtemp_1192, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1193[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1193[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1193[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1193[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1198, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1198[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1198[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1198[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1198[3U]);
    }
    __Vtemp_1201[0U] = 0xffffffffU;
    __Vtemp_1201[1U] = 0xffffffffU;
    __Vtemp_1201[2U] = 0xffffffffU;
    __Vtemp_1201[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1202, __Vtemp_1201, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1202[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1202[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1202[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1202[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1207, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1207[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1207[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1207[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1207[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1231, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1231[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1231[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1231[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1231[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1234, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1236, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1234[0U]) | (__Vtemp_1236[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1234[1U]) | (__Vtemp_1236[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1234[2U]) | (__Vtemp_1236[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1234[3U]) | (__Vtemp_1236[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__3__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[8U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[9U] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1248[0U] = 0xffffffffU;
    __Vtemp_1248[1U] = 0xffffffffU;
    __Vtemp_1248[2U] = 0xffffffffU;
    __Vtemp_1248[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1249, __Vtemp_1248, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1249[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1249[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1249[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1249[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1254, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1254[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1254[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1254[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1254[3U]);
    }
    __Vtemp_1257[0U] = 0xffffffffU;
    __Vtemp_1257[1U] = 0xffffffffU;
    __Vtemp_1257[2U] = 0xffffffffU;
    __Vtemp_1257[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1258, __Vtemp_1257, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1258[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1258[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1258[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1258[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1263, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1263[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1263[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1263[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1263[3U]);
    }
    __Vtemp_1266[0U] = 0xffffffffU;
    __Vtemp_1266[1U] = 0xffffffffU;
    __Vtemp_1266[2U] = 0xffffffffU;
    __Vtemp_1266[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1267, __Vtemp_1266, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1267[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1267[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1267[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1267[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1272, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1272[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1272[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1272[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1272[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1296, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1296[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1296[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1296[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1296[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1299, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1301, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1299[0U]) | (__Vtemp_1301[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1299[1U]) | (__Vtemp_1301[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1299[2U]) | (__Vtemp_1301[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1299[3U]) | (__Vtemp_1301[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__4__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xaU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xbU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1313[0U] = 0xffffffffU;
    __Vtemp_1313[1U] = 0xffffffffU;
    __Vtemp_1313[2U] = 0xffffffffU;
    __Vtemp_1313[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1314, __Vtemp_1313, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1314[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1314[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1314[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1314[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1319, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1319[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1319[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1319[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1319[3U]);
    }
    __Vtemp_1322[0U] = 0xffffffffU;
    __Vtemp_1322[1U] = 0xffffffffU;
    __Vtemp_1322[2U] = 0xffffffffU;
    __Vtemp_1322[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1323, __Vtemp_1322, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1323[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1323[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1323[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1323[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1328, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1328[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1328[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1328[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1328[3U]);
    }
    __Vtemp_1331[0U] = 0xffffffffU;
    __Vtemp_1331[1U] = 0xffffffffU;
    __Vtemp_1331[2U] = 0xffffffffU;
    __Vtemp_1331[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1332, __Vtemp_1331, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1332[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1332[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1332[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1332[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1337, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1337[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1337[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1337[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1337[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1361, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1361[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1361[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1361[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1361[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1364, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1366, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1364[0U]) | (__Vtemp_1366[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1364[1U]) | (__Vtemp_1366[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1364[2U]) | (__Vtemp_1366[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1364[3U]) | (__Vtemp_1366[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__5__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xcU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xdU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1378[0U] = 0xffffffffU;
    __Vtemp_1378[1U] = 0xffffffffU;
    __Vtemp_1378[2U] = 0xffffffffU;
    __Vtemp_1378[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1379, __Vtemp_1378, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1379[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1379[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1379[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1379[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1384, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1384[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1384[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1384[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1384[3U]);
    }
    __Vtemp_1387[0U] = 0xffffffffU;
    __Vtemp_1387[1U] = 0xffffffffU;
    __Vtemp_1387[2U] = 0xffffffffU;
    __Vtemp_1387[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1388, __Vtemp_1387, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1388[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1388[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1388[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1388[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1393, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1393[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1393[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1393[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1393[3U]);
    }
    __Vtemp_1396[0U] = 0xffffffffU;
    __Vtemp_1396[1U] = 0xffffffffU;
    __Vtemp_1396[2U] = 0xffffffffU;
    __Vtemp_1396[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1397, __Vtemp_1396, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1397[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1397[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1397[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1397[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1402, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1402[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1402[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1402[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1402[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1426, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1426[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1426[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1426[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1426[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1429, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1431, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1429[0U]) | (__Vtemp_1431[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1429[1U]) | (__Vtemp_1431[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1429[2U]) | (__Vtemp_1431[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1429[3U]) | (__Vtemp_1431[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__6__KET____DOT__adder_s1__DOT__csa_s1[3U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xeU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                       >> 7U))) ? (0x8000U 
                                                   & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU])
                       : vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz 
        = (0xffffU & ((0U == (0xffU & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                       >> 0x17U))) ? 
                      (0x8000U & (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                  >> 0x10U)) : ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                                 << 0x10U) 
                                                | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__tb_inputs[0xfU] 
                                                   >> 0x10U))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__a_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__b_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__c_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d 
        = (1U & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                 >> 0xfU));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d 
        = (0xffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz) 
                    >> 7U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d 
        = (0x7fU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__d_daz));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any 
        = (((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))) 
             | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))) 
            | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
               & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))) 
           | ((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
              & (0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b))) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c))) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (~ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d))) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf 
        = ((((((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a))))) 
             | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b)) 
                 & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b)) 
                & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b)))))) 
            | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c)) 
                & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c)) 
               & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c)))))) 
           | (((0xffU == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d)) 
               & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d)) 
              & (~ (IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d))))));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0U;
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__is_nan_any) 
         | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) 
            & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf)))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7fc00000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_pos_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0x7f800000U;
    } else if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__any_neg_inf) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_case = 1U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__special_result = 0xff800000U;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_b;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_a;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_a;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_d;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_c;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_c;
    }
    if (((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p) 
         >= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_r;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_p;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_n;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_m;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_m;
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff 
        = ((0U == (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))
            ? 1U : (0xffU & (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift 
        = (0x1ffU & ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x_eff) 
                     - (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx_eff)));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_x))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_x) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_y))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_y) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_mx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_mx) 
                         << 0x14U));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[0U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[1U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[2U] = 0U;
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
        = (((IData)((0U != (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__exp_nx))) 
            << 0x1bU) | ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__frac_nx) 
                         << 0x14U));
    __Vtemp_1443[0U] = 0xffffffffU;
    __Vtemp_1443[1U] = 0xffffffffU;
    __Vtemp_1443[2U] = 0xffffffffU;
    __Vtemp_1443[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1444, __Vtemp_1443, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1444[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1444[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1444[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1444[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1449, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U] 
            = __Vtemp_1449[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U] 
            = __Vtemp_1449[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U] 
            = __Vtemp_1449[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1449[3U]);
    }
    __Vtemp_1452[0U] = 0xffffffffU;
    __Vtemp_1452[1U] = 0xffffffffU;
    __Vtemp_1452[2U] = 0xffffffffU;
    __Vtemp_1452[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1453, __Vtemp_1452, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1453[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1453[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1453[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1453[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1458, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U] 
            = __Vtemp_1458[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U] 
            = __Vtemp_1458[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U] 
            = __Vtemp_1458[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1458[3U]);
    }
    __Vtemp_1461[0U] = 0xffffffffU;
    __Vtemp_1461[1U] = 0xffffffffU;
    __Vtemp_1461[2U] = 0xffffffffU;
    __Vtemp_1461[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1462, __Vtemp_1461, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1462[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1462[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1462[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1462[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1467, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U] 
            = __Vtemp_1467[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U] 
            = __Vtemp_1467[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U] 
            = __Vtemp_1467[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1467[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_y));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_mx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op 
        = ((IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_x) 
           ^ (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__sign_nx));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[0U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[1U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[2U];
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
        = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__x_mant[3U];
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__y_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__m_shifted[3U]);
    }
    if (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_op) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
            = (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U]);
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & (~ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U]));
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
            = vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
            = (0x7fffffffU & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__n_shifted[3U]);
    }
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
            ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U]) 
           ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[0U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[1U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[2U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U] 
             & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U]) 
            | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_y[3U] 
               & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_m[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_x[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1491, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
            ^ __Vtemp_1491[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
            ^ __Vtemp_1491[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
            ^ __Vtemp_1491[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
                           ^ __Vtemp_1491[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1494, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1496, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U] 
             & __Vtemp_1494[0U]) | (__Vtemp_1496[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U] 
             & __Vtemp_1494[1U]) | (__Vtemp_1496[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U] 
             & __Vtemp_1494[2U]) | (__Vtemp_1496[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U] 
             & __Vtemp_1494[3U]) | (__Vtemp_1496[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s1__BRA__7__KET____DOT__adder_s1__DOT__csa_s1[3U]));
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
    __Vtemp_1508[0U] = 0xffffffffU;
    __Vtemp_1508[1U] = 0xffffffffU;
    __Vtemp_1508[2U] = 0xffffffffU;
    __Vtemp_1508[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1509, __Vtemp_1508, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1509[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1509[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1509[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1509[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1514, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[0U] 
            = __Vtemp_1514[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[1U] 
            = __Vtemp_1514[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[2U] 
            = __Vtemp_1514[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1514[3U]);
    }
    __Vtemp_1517[0U] = 0xffffffffU;
    __Vtemp_1517[1U] = 0xffffffffU;
    __Vtemp_1517[2U] = 0xffffffffU;
    __Vtemp_1517[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1518, __Vtemp_1517, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1518[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1518[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1518[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1518[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1523, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[0U] 
            = __Vtemp_1523[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[1U] 
            = __Vtemp_1523[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[2U] 
            = __Vtemp_1523[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1523[3U]);
    }
    __Vtemp_1526[0U] = 0xffffffffU;
    __Vtemp_1526[1U] = 0xffffffffU;
    __Vtemp_1526[2U] = 0xffffffffU;
    __Vtemp_1526[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1527, __Vtemp_1526, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1527[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1527[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1527[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1527[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1532, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[0U] 
            = __Vtemp_1532[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[1U] 
            = __Vtemp_1532[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[2U] 
            = __Vtemp_1532[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1532[3U]);
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
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1556, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U] 
            ^ __Vtemp_1556[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U] 
            ^ __Vtemp_1556[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U] 
            ^ __Vtemp_1556[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U] 
                           ^ __Vtemp_1556[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1559, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1561, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U] 
             & __Vtemp_1559[0U]) | (__Vtemp_1561[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U] 
             & __Vtemp_1559[1U]) | (__Vtemp_1561[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U] 
             & __Vtemp_1559[2U]) | (__Vtemp_1561[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U] 
             & __Vtemp_1559[3U]) | (__Vtemp_1561[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__adder_s3__DOT__csa_s1[3U]));
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
    __Vtemp_1573[0U] = 0xffffffffU;
    __Vtemp_1573[1U] = 0xffffffffU;
    __Vtemp_1573[2U] = 0xffffffffU;
    __Vtemp_1573[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1574, __Vtemp_1573, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1574[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1574[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1574[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1574[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1579, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[0U] 
            = __Vtemp_1579[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[1U] 
            = __Vtemp_1579[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[2U] 
            = __Vtemp_1579[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1579[3U]);
    }
    __Vtemp_1582[0U] = 0xffffffffU;
    __Vtemp_1582[1U] = 0xffffffffU;
    __Vtemp_1582[2U] = 0xffffffffU;
    __Vtemp_1582[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1583, __Vtemp_1582, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1583[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1583[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1583[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1583[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1588, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[0U] 
            = __Vtemp_1588[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[1U] 
            = __Vtemp_1588[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[2U] 
            = __Vtemp_1588[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1588[3U]);
    }
    __Vtemp_1591[0U] = 0xffffffffU;
    __Vtemp_1591[1U] = 0xffffffffU;
    __Vtemp_1591[2U] = 0xffffffffU;
    __Vtemp_1591[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1592, __Vtemp_1591, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1592[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1592[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1592[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1592[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1597, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[0U] 
            = __Vtemp_1597[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[1U] 
            = __Vtemp_1597[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[2U] 
            = __Vtemp_1597[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1597[3U]);
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
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1621, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U] 
            ^ __Vtemp_1621[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U] 
            ^ __Vtemp_1621[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U] 
            ^ __Vtemp_1621[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U] 
                           ^ __Vtemp_1621[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1624, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1626, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U] 
             & __Vtemp_1624[0U]) | (__Vtemp_1626[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U] 
             & __Vtemp_1624[1U]) | (__Vtemp_1626[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U] 
             & __Vtemp_1624[2U]) | (__Vtemp_1626[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U] 
             & __Vtemp_1624[3U]) | (__Vtemp_1626[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__0__KET____DOT__adder_s2__DOT__csa_s1[3U]));
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
    __Vtemp_1638[0U] = 0xffffffffU;
    __Vtemp_1638[1U] = 0xffffffffU;
    __Vtemp_1638[2U] = 0xffffffffU;
    __Vtemp_1638[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1639, __Vtemp_1638, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_y 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[0U] 
                     & (~ __Vtemp_1639[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1639[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[2U] 
                      & (~ __Vtemp_1639[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1639[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1644, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[0U] 
            = __Vtemp_1644[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[1U] 
            = __Vtemp_1644[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[2U] 
            = __Vtemp_1644[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__y_shifted[3U] 
            = (0xfffffffU & __Vtemp_1644[3U]);
    }
    __Vtemp_1647[0U] = 0xffffffffU;
    __Vtemp_1647[1U] = 0xffffffffU;
    __Vtemp_1647[2U] = 0xffffffffU;
    __Vtemp_1647[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1648, __Vtemp_1647, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_m 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[0U] 
                     & (~ __Vtemp_1648[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1648[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[2U] 
                      & (~ __Vtemp_1648[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1648[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1653, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[0U] 
            = __Vtemp_1653[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[1U] 
            = __Vtemp_1653[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[2U] 
            = __Vtemp_1653[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__m_shifted[3U] 
            = (0xfffffffU & __Vtemp_1653[3U]);
    }
    __Vtemp_1656[0U] = 0xffffffffU;
    __Vtemp_1656[1U] = 0xffffffffU;
    __Vtemp_1656[2U] = 0xffffffffU;
    __Vtemp_1656[3U] = 0xfffffffU;
    VL_SHIFTL_WWI(124,124,9, __Vtemp_1657, __Vtemp_1656, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__sticky_n 
        = (0U != ((((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[0U] 
                     & (~ __Vtemp_1657[0U])) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[1U] 
                                                & (~ 
                                                   __Vtemp_1657[1U]))) 
                   | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[2U] 
                      & (~ __Vtemp_1657[2U]))) | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base[3U] 
                                                  & (~ 
                                                     __Vtemp_1657[3U]))));
    VL_SHIFTR_WWI(124,124,9, __Vtemp_1662, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_mant_base, (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift));
    if ((0x7cU <= (IData)(vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shift))) {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U] = 0U;
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U] = 0U;
    } else {
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[0U] 
            = __Vtemp_1662[0U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[1U] 
            = __Vtemp_1662[1U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[2U] 
            = __Vtemp_1662[2U];
        vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__n_shifted[3U] 
            = (0xfffffffU & __Vtemp_1662[3U]);
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
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1686, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[0U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U] 
            ^ __Vtemp_1686[0U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[1U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U] 
            ^ __Vtemp_1686[1U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[2U] 
        = ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U] 
            ^ __Vtemp_1686[2U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U]);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s2[3U] 
        = (0x7fffffffU & ((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U] 
                           ^ __Vtemp_1686[3U]) ^ vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U]));
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1689, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    VL_SHIFTL_WWI(127,127,32, __Vtemp_1691, vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c1, 1U);
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[0U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U] 
             & __Vtemp_1689[0U]) | (__Vtemp_1691[0U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[0U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[0U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[1U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U] 
             & __Vtemp_1689[1U]) | (__Vtemp_1691[1U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[1U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[1U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[2U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U] 
             & __Vtemp_1689[2U]) | (__Vtemp_1691[2U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[2U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[2U]));
    vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_c2[3U] 
        = (((vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U] 
             & __Vtemp_1689[3U]) | (__Vtemp_1691[3U] 
                                    & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U])) 
           | (vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__op_n[3U] 
              & vlSelfRef.add32_fp32accum_bf16_tb_softfloat__DOT__dut__DOT__gen_s2__BRA__1__KET____DOT__adder_s2__DOT__csa_s1[3U]));
}
