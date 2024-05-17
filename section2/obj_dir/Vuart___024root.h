// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vuart.h for the primary calling header

#ifndef VERILATED_VUART___024ROOT_H_
#define VERILATED_VUART___024ROOT_H_  // guard

#include "verilated.h"


class Vuart__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vuart___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(rx,0,0);
    VL_OUT8(tx,0,0);
    VL_IN8(data_in,7,0);
    VL_IN8(wr_en,0,0);
    VL_OUT8(data_out,7,0);
    VL_OUT8(rx_ready,0,0);
    VL_OUT8(tx_ready,0,0);
    CData/*2:0*/ uart__DOT__rx_state;
    CData/*2:0*/ uart__DOT__tx_state;
    CData/*3:0*/ uart__DOT__bit_counter;
    CData/*7:0*/ uart__DOT__rx_shift_reg;
    CData/*7:0*/ uart__DOT__tx_shift_reg;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ uart__DOT__baud_counter;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vuart__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vuart___024root(Vuart__Syms* symsp, const char* v__name);
    ~Vuart___024root();
    VL_UNCOPYABLE(Vuart___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
