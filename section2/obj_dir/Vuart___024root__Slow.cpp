// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart__pch.h"
#include "Vuart__Syms.h"
#include "Vuart___024root.h"

void Vuart___024root___ctor_var_reset(Vuart___024root* vlSelf);

Vuart___024root::Vuart___024root(Vuart__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vuart___024root___ctor_var_reset(this);
}

void Vuart___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vuart___024root::~Vuart___024root() {
}
