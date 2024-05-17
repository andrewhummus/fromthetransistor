// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart__pch.h"
#include "Vuart___024root.h"

VL_ATTR_COLD void Vuart___024root___eval_static(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vuart___024root___eval_initial(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
}

VL_ATTR_COLD void Vuart___024root___eval_final(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vuart___024root___eval_settle(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__nba(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vuart___024root___ctor_var_reset(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->rx = VL_RAND_RESET_I(1);
    vlSelf->tx = VL_RAND_RESET_I(1);
    vlSelf->data_in = VL_RAND_RESET_I(8);
    vlSelf->wr_en = VL_RAND_RESET_I(1);
    vlSelf->data_out = VL_RAND_RESET_I(8);
    vlSelf->rx_ready = VL_RAND_RESET_I(1);
    vlSelf->tx_ready = VL_RAND_RESET_I(1);
    vlSelf->uart__DOT__rx_state = VL_RAND_RESET_I(3);
    vlSelf->uart__DOT__tx_state = VL_RAND_RESET_I(3);
    vlSelf->uart__DOT__baud_counter = VL_RAND_RESET_I(16);
    vlSelf->uart__DOT__bit_counter = VL_RAND_RESET_I(4);
    vlSelf->uart__DOT__rx_shift_reg = VL_RAND_RESET_I(8);
    vlSelf->uart__DOT__tx_shift_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
