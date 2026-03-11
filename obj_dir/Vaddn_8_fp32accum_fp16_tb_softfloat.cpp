// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaddn_8_fp32accum_fp16_tb_softfloat__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vaddn_8_fp32accum_fp16_tb_softfloat::Vaddn_8_fp32accum_fp16_tb_softfloat(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaddn_8_fp32accum_fp16_tb_softfloat__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vaddn_8_fp32accum_fp16_tb_softfloat::Vaddn_8_fp32accum_fp16_tb_softfloat(const char* _vcname__)
    : Vaddn_8_fp32accum_fp16_tb_softfloat(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaddn_8_fp32accum_fp16_tb_softfloat::~Vaddn_8_fp32accum_fp16_tb_softfloat() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
#endif  // VL_DEBUG
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_static(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_settle(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);
void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

void Vaddn_8_fp32accum_fp16_tb_softfloat::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaddn_8_fp32accum_fp16_tb_softfloat::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_static(&(vlSymsp->TOP));
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_initial(&(vlSymsp->TOP));
        Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vaddn_8_fp32accum_fp16_tb_softfloat::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vaddn_8_fp32accum_fp16_tb_softfloat::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vaddn_8_fp32accum_fp16_tb_softfloat::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vaddn_8_fp32accum_fp16_tb_softfloat::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vaddn_8_fp32accum_fp16_tb_softfloat::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_final(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat::final() {
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaddn_8_fp32accum_fp16_tb_softfloat::hierName() const { return vlSymsp->name(); }
const char* Vaddn_8_fp32accum_fp16_tb_softfloat::modelName() const { return "Vaddn_8_fp32accum_fp16_tb_softfloat"; }
unsigned Vaddn_8_fp32accum_fp16_tb_softfloat::threads() const { return 1; }
void Vaddn_8_fp32accum_fp16_tb_softfloat::prepareClone() const { contextp()->prepareClone(); }
void Vaddn_8_fp32accum_fp16_tb_softfloat::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vaddn_8_fp32accum_fp16_tb_softfloat::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_decl_types(VerilatedVcd* tracep);

void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_top(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaddn_8_fp32accum_fp16_tb_softfloat___024root*>(voidSelf);
    Vaddn_8_fp32accum_fp16_tb_softfloat__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_decl_types(tracep);
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_register(Vaddn_8_fp32accum_fp16_tb_softfloat___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vaddn_8_fp32accum_fp16_tb_softfloat::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vaddn_8_fp32accum_fp16_tb_softfloat::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vaddn_8_fp32accum_fp16_tb_softfloat___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
