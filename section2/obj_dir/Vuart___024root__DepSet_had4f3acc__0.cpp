// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart__pch.h"
#include "Vuart__Syms.h"
#include "Vuart___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__act(Vuart___024root* vlSelf);
#endif  // VL_DEBUG

void Vuart___024root___eval_triggers__act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vuart___024root___dump_triggers__act(vlSelf);
    }
#endif
}
