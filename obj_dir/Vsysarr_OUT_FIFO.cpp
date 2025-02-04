// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsysarr_OUT_FIFO__pch.h"

//============================================================
// Constructors

Vsysarr_OUT_FIFO::Vsysarr_OUT_FIFO(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsysarr_OUT_FIFO__Syms(contextp(), _vcname__, this)}
    , __PVT__sysarr_OUT_FIFO_tb__DOT__fifo_if{vlSymsp->TOP.__PVT__sysarr_OUT_FIFO_tb__DOT__fifo_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsysarr_OUT_FIFO::Vsysarr_OUT_FIFO(const char* _vcname__)
    : Vsysarr_OUT_FIFO(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsysarr_OUT_FIFO::~Vsysarr_OUT_FIFO() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsysarr_OUT_FIFO___024root___eval_debug_assertions(Vsysarr_OUT_FIFO___024root* vlSelf);
#endif  // VL_DEBUG
void Vsysarr_OUT_FIFO___024root___eval_static(Vsysarr_OUT_FIFO___024root* vlSelf);
void Vsysarr_OUT_FIFO___024root___eval_initial(Vsysarr_OUT_FIFO___024root* vlSelf);
void Vsysarr_OUT_FIFO___024root___eval_settle(Vsysarr_OUT_FIFO___024root* vlSelf);
void Vsysarr_OUT_FIFO___024root___eval(Vsysarr_OUT_FIFO___024root* vlSelf);

void Vsysarr_OUT_FIFO::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsysarr_OUT_FIFO::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsysarr_OUT_FIFO___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsysarr_OUT_FIFO___024root___eval_static(&(vlSymsp->TOP));
        Vsysarr_OUT_FIFO___024root___eval_initial(&(vlSymsp->TOP));
        Vsysarr_OUT_FIFO___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsysarr_OUT_FIFO___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsysarr_OUT_FIFO::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsysarr_OUT_FIFO::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsysarr_OUT_FIFO::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsysarr_OUT_FIFO___024root___eval_final(Vsysarr_OUT_FIFO___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_OUT_FIFO::final() {
    Vsysarr_OUT_FIFO___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsysarr_OUT_FIFO::hierName() const { return vlSymsp->name(); }
const char* Vsysarr_OUT_FIFO::modelName() const { return "Vsysarr_OUT_FIFO"; }
unsigned Vsysarr_OUT_FIFO::threads() const { return 1; }
void Vsysarr_OUT_FIFO::prepareClone() const { contextp()->prepareClone(); }
void Vsysarr_OUT_FIFO::atClone() const {
    contextp()->threadPoolpOnClone();
}
