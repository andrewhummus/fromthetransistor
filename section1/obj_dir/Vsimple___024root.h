// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsimple.h for the primary calling header

#ifndef VERILATED_VSIMPLE___024ROOT_H_
#define VERILATED_VSIMPLE___024ROOT_H_  // guard

#include "verilated.h"


class Vsimple__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsimple___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(counter,3,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsimple__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vsimple___024root(Vsimple__Syms* symsp, const char* v__name);
    ~Vsimple___024root();
    VL_UNCOPYABLE(Vsimple___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
