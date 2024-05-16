// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSIMPLE__SYMS_H_
#define VERILATED_VSIMPLE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsimple.h"

// INCLUDE MODULE CLASSES
#include "Vsimple___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vsimple__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsimple* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vsimple___024root              TOP;

    // CONSTRUCTORS
    Vsimple__Syms(VerilatedContext* contextp, const char* namep, Vsimple* modelp);
    ~Vsimple__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
