// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsimple__pch.h"

//============================================================
// Constructors

Vsimple::Vsimple(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsimple__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , counter{vlSymsp->TOP.counter}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsimple::Vsimple(const char* _vcname__)
    : Vsimple(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsimple::~Vsimple() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsimple___024root___eval_debug_assertions(Vsimple___024root* vlSelf);
#endif  // VL_DEBUG
void Vsimple___024root___eval_static(Vsimple___024root* vlSelf);
void Vsimple___024root___eval_initial(Vsimple___024root* vlSelf);
void Vsimple___024root___eval_settle(Vsimple___024root* vlSelf);
void Vsimple___024root___eval(Vsimple___024root* vlSelf);

void Vsimple::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsimple::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vsimple___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vsimple___024root___eval_static(&(vlSymsp->TOP));
        Vsimple___024root___eval_initial(&(vlSymsp->TOP));
        Vsimple___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vsimple___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vsimple::eventsPending() { return false; }

uint64_t Vsimple::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsimple::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vsimple___024root___eval_final(Vsimple___024root* vlSelf);

VL_ATTR_COLD void Vsimple::final() {
    Vsimple___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsimple::hierName() const { return vlSymsp->name(); }
const char* Vsimple::modelName() const { return "Vsimple"; }
unsigned Vsimple::threads() const { return 1; }
void Vsimple::prepareClone() const { contextp()->prepareClone(); }
void Vsimple::atClone() const {
    contextp()->threadPoolpOnClone();
}
