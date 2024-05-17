// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vuart__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vuart::Vuart(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vuart__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , rx{vlSymsp->TOP.rx}
    , tx{vlSymsp->TOP.tx}
    , data_in{vlSymsp->TOP.data_in}
    , wr_en{vlSymsp->TOP.wr_en}
    , data_out{vlSymsp->TOP.data_out}
    , rx_ready{vlSymsp->TOP.rx_ready}
    , tx_ready{vlSymsp->TOP.tx_ready}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vuart::Vuart(const char* _vcname__)
    : Vuart(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vuart::~Vuart() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vuart___024root___eval_debug_assertions(Vuart___024root* vlSelf);
#endif  // VL_DEBUG
void Vuart___024root___eval_static(Vuart___024root* vlSelf);
void Vuart___024root___eval_initial(Vuart___024root* vlSelf);
void Vuart___024root___eval_settle(Vuart___024root* vlSelf);
void Vuart___024root___eval(Vuart___024root* vlSelf);

void Vuart::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vuart::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vuart___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vuart___024root___eval_static(&(vlSymsp->TOP));
        Vuart___024root___eval_initial(&(vlSymsp->TOP));
        Vuart___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vuart___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vuart::eventsPending() { return false; }

uint64_t Vuart::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vuart::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vuart___024root___eval_final(Vuart___024root* vlSelf);

VL_ATTR_COLD void Vuart::final() {
    Vuart___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vuart::hierName() const { return vlSymsp->name(); }
const char* Vuart::modelName() const { return "Vuart"; }
unsigned Vuart::threads() const { return 1; }
void Vuart::prepareClone() const { contextp()->prepareClone(); }
void Vuart::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vuart::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vuart___024root__trace_decl_types(VerilatedVcd* tracep);

void Vuart___024root__trace_init_top(Vuart___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vuart___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vuart___024root*>(voidSelf);
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vuart___024root__trace_decl_types(tracep);
    Vuart___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vuart___024root__trace_register(Vuart___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vuart::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vuart::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vuart___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
