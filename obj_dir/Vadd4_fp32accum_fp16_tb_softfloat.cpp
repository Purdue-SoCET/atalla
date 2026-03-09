// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd4_fp32accum_fp16_tb_softfloat__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd4_fp32accum_fp16_tb_softfloat::Vadd4_fp32accum_fp16_tb_softfloat(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd4_fp32accum_fp16_tb_softfloat__Syms(contextp(), _vcname__, this)}
    , __PVT__add4_fp32accum_fp16_tb_softfloat__DOT__add_if{vlSymsp->TOP.__PVT__add4_fp32accum_fp16_tb_softfloat__DOT__add_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vadd4_fp32accum_fp16_tb_softfloat::Vadd4_fp32accum_fp16_tb_softfloat(const char* _vcname__)
    : Vadd4_fp32accum_fp16_tb_softfloat(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd4_fp32accum_fp16_tb_softfloat::~Vadd4_fp32accum_fp16_tb_softfloat() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_static(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_settle(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vadd4_fp32accum_fp16_tb_softfloat::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd4_fp32accum_fp16_tb_softfloat::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_static(&(vlSymsp->TOP));
        Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_initial(&(vlSymsp->TOP));
        Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vadd4_fp32accum_fp16_tb_softfloat::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vadd4_fp32accum_fp16_tb_softfloat::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vadd4_fp32accum_fp16_tb_softfloat::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vadd4_fp32accum_fp16_tb_softfloat::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vadd4_fp32accum_fp16_tb_softfloat::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_final(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat::final() {
    Vadd4_fp32accum_fp16_tb_softfloat___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd4_fp32accum_fp16_tb_softfloat::hierName() const { return vlSymsp->name(); }
const char* Vadd4_fp32accum_fp16_tb_softfloat::modelName() const { return "Vadd4_fp32accum_fp16_tb_softfloat"; }
unsigned Vadd4_fp32accum_fp16_tb_softfloat::threads() const { return 1; }
void Vadd4_fp32accum_fp16_tb_softfloat::prepareClone() const { contextp()->prepareClone(); }
void Vadd4_fp32accum_fp16_tb_softfloat::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vadd4_fp32accum_fp16_tb_softfloat::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_decl_types(VerilatedVcd* tracep);

void Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_init_top(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd4_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vadd4_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_decl_types(tracep);
    Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_register(Vadd4_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4_fp32accum_fp16_tb_softfloat::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd4_fp32accum_fp16_tb_softfloat::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd4_fp32accum_fp16_tb_softfloat___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
