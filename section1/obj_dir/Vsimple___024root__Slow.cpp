// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsimple.h for the primary calling header

#include "Vsimple__pch.h"
#include "Vsimple__Syms.h"
#include "Vsimple___024root.h"

void Vsimple___024root___ctor_var_reset(Vsimple___024root* vlSelf);

Vsimple___024root::Vsimple___024root(Vsimple__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vsimple___024root___ctor_var_reset(this);
}

void Vsimple___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsimple___024root::~Vsimple___024root() {
}
