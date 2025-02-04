// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsysarr_PS_FIFO__pch.h"

//============================================================
// Constructors

Vsysarr_PS_FIFO::Vsysarr_PS_FIFO(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsysarr_PS_FIFO__Syms(contextp(), _vcname__, this)}
    , __PVT__sysarr_PS_FIFO_tb__DOT__ps_fifo_if{vlSymsp->TOP.__PVT__sysarr_PS_FIFO_tb__DOT__ps_fifo_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsysarr_PS_FIFO::Vsysarr_PS_FIFO(const char* _vcname__)
    : Vsysarr_PS_FIFO(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsysarr_PS_FIFO::~Vsysarr_PS_FIFO() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsysarr_PS_FIFO___024root___eval_debug_assertions(Vsysarr_PS_FIFO___024root* vlSelf);
#endif  // VL_DEBUG
void Vsysarr_PS_FIFO___024root___eval_static(Vsysarr_PS_FIFO___024root* vlSelf);
void Vsysarr_PS_FIFO___024root___eval_initial(Vsysarr_PS_FIFO___024root* vlSelf);
void Vsysarr_PS_FIFO___024root___eval_settle(Vsysarr_PS_FIFO___024root* vlSelf);
void Vsysarr_PS_FIFO___024root___eval(Vsysarr_PS_FIFO___024root* vlSelf);

void Vsysarr_PS_FIFO::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsysarr_PS_FIFO::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsysarr_PS_FIFO___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsysarr_PS_FIFO___024root___eval_static(&(vlSymsp->TOP));
        Vsysarr_PS_FIFO___024root___eval_initial(&(vlSymsp->TOP));
        Vsysarr_PS_FIFO___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsysarr_PS_FIFO___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsysarr_PS_FIFO::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsysarr_PS_FIFO::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsysarr_PS_FIFO::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsysarr_PS_FIFO___024root___eval_final(Vsysarr_PS_FIFO___024root* vlSelf);

VL_ATTR_COLD void Vsysarr_PS_FIFO::final() {
    Vsysarr_PS_FIFO___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsysarr_PS_FIFO::hierName() const { return vlSymsp->name(); }
const char* Vsysarr_PS_FIFO::modelName() const { return "Vsysarr_PS_FIFO"; }
unsigned Vsysarr_PS_FIFO::threads() const { return 1; }
void Vsysarr_PS_FIFO::prepareClone() const { contextp()->prepareClone(); }
void Vsysarr_PS_FIFO::atClone() const {
    contextp()->threadPoolpOnClone();
}
