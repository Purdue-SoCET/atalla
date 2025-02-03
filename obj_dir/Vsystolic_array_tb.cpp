// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsystolic_array_tb__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vsystolic_array_tb::Vsystolic_array_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsystolic_array_tb__Syms(contextp(), _vcname__, this)}
    , __PVT__systolic_array_tb__DOT__memory_if{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__memory_if}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__control_unit_if{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__control_unit_if}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__15__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__14__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__13__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__12__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__11__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__10__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__9__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__8__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__7__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__6__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__5__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__4__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__3__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__2__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__1__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__mac_ifs__BRA__0__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__3__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__2__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__1__KET__}
    , __PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__{vlSymsp->TOP.__PVT__systolic_array_tb__DOT__DUT__DOT__add_ifs__BRA__0__KET__}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vsystolic_array_tb::Vsystolic_array_tb(const char* _vcname__)
    : Vsystolic_array_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsystolic_array_tb::~Vsystolic_array_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsystolic_array_tb___024root___eval_debug_assertions(Vsystolic_array_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vsystolic_array_tb___024root___eval_static(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___eval_initial(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___eval_settle(Vsystolic_array_tb___024root* vlSelf);
void Vsystolic_array_tb___024root___eval(Vsystolic_array_tb___024root* vlSelf);

void Vsystolic_array_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsystolic_array_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsystolic_array_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsystolic_array_tb___024root___eval_static(&(vlSymsp->TOP));
        Vsystolic_array_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vsystolic_array_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsystolic_array_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vsystolic_array_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vsystolic_array_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vsystolic_array_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vsystolic_array_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vsystolic_array_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsystolic_array_tb___024root___eval_final(Vsystolic_array_tb___024root* vlSelf);

VL_ATTR_COLD void Vsystolic_array_tb::final() {
    Vsystolic_array_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsystolic_array_tb::hierName() const { return vlSymsp->name(); }
const char* Vsystolic_array_tb::modelName() const { return "Vsystolic_array_tb"; }
unsigned Vsystolic_array_tb::threads() const { return 1; }
void Vsystolic_array_tb::prepareClone() const { contextp()->prepareClone(); }
void Vsystolic_array_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vsystolic_array_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vsystolic_array_tb___024root__trace_decl_types(VerilatedFst* tracep);

void Vsystolic_array_tb___024root__trace_init_top(Vsystolic_array_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsystolic_array_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsystolic_array_tb___024root*>(voidSelf);
    Vsystolic_array_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vsystolic_array_tb___024root__trace_decl_types(tracep);
    Vsystolic_array_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vsystolic_array_tb___024root__trace_register(Vsystolic_array_tb___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vsystolic_array_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vsystolic_array_tb::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vsystolic_array_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
