// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadder_4input_tree32_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadder_4input_tree32_tb::Vadder_4input_tree32_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadder_4input_tree32_tb__Syms(contextp(), _vcname__, this)}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__31__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__30__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__30__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__29__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__29__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__28__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__28__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__27__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__27__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__26__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__26__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__25__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__25__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__24__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__24__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__23__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__23__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__22__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__22__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__21__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__21__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__20__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__20__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__19__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__19__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__18__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__18__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__17__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__17__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__16__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__16__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__15__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__15__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__14__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__14__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__13__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__13__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__12__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__12__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__11__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__11__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__10__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__10__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__9__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__9__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__8__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__8__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__7__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__7__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__6__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__6__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__5__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__5__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__4__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__4__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__3__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__3__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__2__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__2__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__1__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__1__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__0__KET__{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__ifc__BRA__0__KET__}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__1__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__2__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__3__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__4__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__5__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__6__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__7__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__8__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__9__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__10__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__11__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__12__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__13__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__14__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__15__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__16__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__17__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__18__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__19__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__20__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__21__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__22__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__23__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__24__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__25__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__26__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__27__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__28__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__29__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__30__KET____DOT__stage_inst}
    , __PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst{vlSymsp->TOP.__PVT__adder_4input_tree32_tb__DOT__dut__DOT__gen_accum_stages__BRA__31__KET____DOT__stage_inst}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vadder_4input_tree32_tb::Vadder_4input_tree32_tb(const char* _vcname__)
    : Vadder_4input_tree32_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadder_4input_tree32_tb::~Vadder_4input_tree32_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadder_4input_tree32_tb___024root___eval_debug_assertions(Vadder_4input_tree32_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vadder_4input_tree32_tb___024root___eval_static(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb___024root___eval_initial(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb___024root___eval_settle(Vadder_4input_tree32_tb___024root* vlSelf);
void Vadder_4input_tree32_tb___024root___eval(Vadder_4input_tree32_tb___024root* vlSelf);

void Vadder_4input_tree32_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadder_4input_tree32_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadder_4input_tree32_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadder_4input_tree32_tb___024root___eval_static(&(vlSymsp->TOP));
        Vadder_4input_tree32_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vadder_4input_tree32_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadder_4input_tree32_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vadder_4input_tree32_tb::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vadder_4input_tree32_tb::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vadder_4input_tree32_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vadder_4input_tree32_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vadder_4input_tree32_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadder_4input_tree32_tb___024root___eval_final(Vadder_4input_tree32_tb___024root* vlSelf);

VL_ATTR_COLD void Vadder_4input_tree32_tb::final() {
    Vadder_4input_tree32_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadder_4input_tree32_tb::hierName() const { return vlSymsp->name(); }
const char* Vadder_4input_tree32_tb::modelName() const { return "Vadder_4input_tree32_tb"; }
unsigned Vadder_4input_tree32_tb::threads() const { return 1; }
void Vadder_4input_tree32_tb::prepareClone() const { contextp()->prepareClone(); }
void Vadder_4input_tree32_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vadder_4input_tree32_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadder_4input_tree32_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vadder_4input_tree32_tb___024root__trace_init_top(Vadder_4input_tree32_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadder_4input_tree32_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadder_4input_tree32_tb___024root*>(voidSelf);
    Vadder_4input_tree32_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vadder_4input_tree32_tb___024root__trace_decl_types(tracep);
    Vadder_4input_tree32_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vadder_4input_tree32_tb___024root__trace_register(Vadder_4input_tree32_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadder_4input_tree32_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadder_4input_tree32_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadder_4input_tree32_tb___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
