// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd_fp16_tb_full__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd_fp16_tb_full::Vadd_fp16_tb_full(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd_fp16_tb_full__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vadd_fp16_tb_full::Vadd_fp16_tb_full(const char* _vcname__)
    : Vadd_fp16_tb_full(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd_fp16_tb_full::~Vadd_fp16_tb_full() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd_fp16_tb_full___024root___eval_debug_assertions(Vadd_fp16_tb_full___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd_fp16_tb_full___024root___eval_static(Vadd_fp16_tb_full___024root* vlSelf);
void Vadd_fp16_tb_full___024root___eval_initial(Vadd_fp16_tb_full___024root* vlSelf);
void Vadd_fp16_tb_full___024root___eval_settle(Vadd_fp16_tb_full___024root* vlSelf);
void Vadd_fp16_tb_full___024root___eval(Vadd_fp16_tb_full___024root* vlSelf);

void Vadd_fp16_tb_full::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd_fp16_tb_full::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd_fp16_tb_full___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd_fp16_tb_full___024root___eval_static(&(vlSymsp->TOP));
        Vadd_fp16_tb_full___024root___eval_initial(&(vlSymsp->TOP));
        Vadd_fp16_tb_full___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd_fp16_tb_full___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd_fp16_tb_full::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vadd_fp16_tb_full::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vadd_fp16_tb_full::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd_fp16_tb_full___024root___eval_final(Vadd_fp16_tb_full___024root* vlSelf);

VL_ATTR_COLD void Vadd_fp16_tb_full::final() {
    Vadd_fp16_tb_full___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd_fp16_tb_full::hierName() const { return vlSymsp->name(); }
const char* Vadd_fp16_tb_full::modelName() const { return "Vadd_fp16_tb_full"; }
unsigned Vadd_fp16_tb_full::threads() const { return 1; }
void Vadd_fp16_tb_full::prepareClone() const { contextp()->prepareClone(); }
void Vadd_fp16_tb_full::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vadd_fp16_tb_full::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd_fp16_tb_full___024root__trace_decl_types(VerilatedVcd* tracep);

void Vadd_fp16_tb_full___024root__trace_init_top(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd_fp16_tb_full___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd_fp16_tb_full___024root*>(voidSelf);
    Vadd_fp16_tb_full__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vadd_fp16_tb_full___024root__trace_decl_types(tracep);
    Vadd_fp16_tb_full___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd_fp16_tb_full___024root__trace_register(Vadd_fp16_tb_full___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd_fp16_tb_full::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd_fp16_tb_full::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd_fp16_tb_full___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
