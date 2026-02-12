// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd4_fp16_tb_softfloat__pch.h"

//============================================================
// Constructors

Vadd4_fp16_tb_softfloat::Vadd4_fp16_tb_softfloat(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd4_fp16_tb_softfloat__Syms(contextp(), _vcname__, this)}
    , __PVT__add4_fp16_tb_softfloat__DOT__add_if{vlSymsp->TOP.__PVT__add4_fp16_tb_softfloat__DOT__add_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd4_fp16_tb_softfloat::Vadd4_fp16_tb_softfloat(const char* _vcname__)
    : Vadd4_fp16_tb_softfloat(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd4_fp16_tb_softfloat::~Vadd4_fp16_tb_softfloat() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd4_fp16_tb_softfloat___024root___eval_debug_assertions(Vadd4_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd4_fp16_tb_softfloat___024root___eval_static(Vadd4_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp16_tb_softfloat___024root___eval_initial(Vadd4_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp16_tb_softfloat___024root___eval_settle(Vadd4_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp16_tb_softfloat___024root___eval(Vadd4_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp16_tb_softfloat::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd4_fp16_tb_softfloat::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd4_fp16_tb_softfloat___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd4_fp16_tb_softfloat___024root___eval_static(&(vlSymsp->TOP));
        Vadd4_fp16_tb_softfloat___024root___eval_initial(&(vlSymsp->TOP));
        Vadd4_fp16_tb_softfloat___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd4_fp16_tb_softfloat___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd4_fp16_tb_softfloat::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vadd4_fp16_tb_softfloat::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vadd4_fp16_tb_softfloat::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd4_fp16_tb_softfloat___024root___eval_final(Vadd4_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp16_tb_softfloat::final() {
    Vadd4_fp16_tb_softfloat___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd4_fp16_tb_softfloat::hierName() const { return vlSymsp->name(); }
const char* Vadd4_fp16_tb_softfloat::modelName() const { return "Vadd4_fp16_tb_softfloat"; }
unsigned Vadd4_fp16_tb_softfloat::threads() const { return 1; }
void Vadd4_fp16_tb_softfloat::prepareClone() const { contextp()->prepareClone(); }
void Vadd4_fp16_tb_softfloat::atClone() const {
    contextp()->threadPoolpOnClone();
}
