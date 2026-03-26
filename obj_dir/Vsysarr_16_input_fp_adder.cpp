// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsysarr_16_input_fp_adder__pch.h"

//============================================================
// Constructors

Vsysarr_16_input_fp_adder::Vsysarr_16_input_fp_adder(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsysarr_16_input_fp_adder__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsysarr_16_input_fp_adder::Vsysarr_16_input_fp_adder(const char* _vcname__)
    : Vsysarr_16_input_fp_adder(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsysarr_16_input_fp_adder::~Vsysarr_16_input_fp_adder() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsysarr_16_input_fp_adder___024root___eval_debug_assertions(Vsysarr_16_input_fp_adder___024root* vlSelf);
#endif  // VL_DEBUG
void Vsysarr_16_input_fp_adder___024root___eval_static(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___eval_initial(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___eval_settle(Vsysarr_16_input_fp_adder___024root* vlSelf);
void Vsysarr_16_input_fp_adder___024root___eval(Vsysarr_16_input_fp_adder___024root* vlSelf);

void Vsysarr_16_input_fp_adder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsysarr_16_input_fp_adder::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsysarr_16_input_fp_adder___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsysarr_16_input_fp_adder___024root___eval_static(&(vlSymsp->TOP));
        Vsysarr_16_input_fp_adder___024root___eval_initial(&(vlSymsp->TOP));
        Vsysarr_16_input_fp_adder___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsysarr_16_input_fp_adder___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsysarr_16_input_fp_adder::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsysarr_16_input_fp_adder::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsysarr_16_input_fp_adder::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsysarr_16_input_fp_adder___024root___eval_final(Vsysarr_16_input_fp_adder___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_16_input_fp_adder::final() {
    Vsysarr_16_input_fp_adder___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsysarr_16_input_fp_adder::hierName() const { return vlSymsp->name(); }
const char* Vsysarr_16_input_fp_adder::modelName() const { return "Vsysarr_16_input_fp_adder"; }
unsigned Vsysarr_16_input_fp_adder::threads() const { return 1; }
void Vsysarr_16_input_fp_adder::prepareClone() const { contextp()->prepareClone(); }
void Vsysarr_16_input_fp_adder::atClone() const {
    contextp()->threadPoolpOnClone();
}
