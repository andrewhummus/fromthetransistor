// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vuart.h for the primary calling header

#include "Vuart__pch.h"
#include "Vuart___024root.h"

void Vuart___024root___eval_act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_act\n"); );
}

void Vuart___024root___nba_sequent__TOP__0(Vuart___024root* vlSelf);

void Vuart___024root___eval_nba(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vuart___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void Vuart___024root___nba_sequent__TOP__0(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__uart__DOT__baud_counter;
    __Vdly__uart__DOT__baud_counter = 0;
    CData/*2:0*/ __Vdly__uart__DOT__rx_state;
    __Vdly__uart__DOT__rx_state = 0;
    CData/*3:0*/ __Vdly__uart__DOT__bit_counter;
    __Vdly__uart__DOT__bit_counter = 0;
    CData/*2:0*/ __Vdly__uart__DOT__tx_state;
    __Vdly__uart__DOT__tx_state = 0;
    // Body
    __Vdly__uart__DOT__baud_counter = vlSelf->uart__DOT__baud_counter;
    __Vdly__uart__DOT__rx_state = vlSelf->uart__DOT__rx_state;
    __Vdly__uart__DOT__tx_state = vlSelf->uart__DOT__tx_state;
    __Vdly__uart__DOT__bit_counter = vlSelf->uart__DOT__bit_counter;
    if (vlSelf->reset) {
        __Vdly__uart__DOT__baud_counter = 0U;
        __Vdly__uart__DOT__rx_state = 0U;
        __Vdly__uart__DOT__bit_counter = 0U;
        vlSelf->rx_ready = 0U;
        __Vdly__uart__DOT__tx_state = 0U;
        vlSelf->tx_ready = 1U;
        __Vdly__uart__DOT__bit_counter = 0U;
        vlSelf->tx = 1U;
    } else {
        __Vdly__uart__DOT__baud_counter = ((0x1b1U 
                                            <= (IData)(vlSelf->uart__DOT__baud_counter))
                                            ? 0U : 
                                           (0xffffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlSelf->uart__DOT__baud_counter))));
        if ((0U == (IData)(vlSelf->uart__DOT__baud_counter))) {
            if ((4U & (IData)(vlSelf->uart__DOT__rx_state))) {
                __Vdly__uart__DOT__rx_state = 0U;
            } else if ((2U & (IData)(vlSelf->uart__DOT__rx_state))) {
                if ((1U & (IData)(vlSelf->uart__DOT__rx_state))) {
                    if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                        __Vdly__uart__DOT__rx_state = 0U;
                        vlSelf->data_out = vlSelf->uart__DOT__rx_shift_reg;
                        vlSelf->rx_ready = 1U;
                    } else {
                        __Vdly__uart__DOT__bit_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->uart__DOT__bit_counter)));
                    }
                } else {
                    vlSelf->uart__DOT__rx_shift_reg 
                        = (((~ ((IData)(1U) << (7U 
                                                & (IData)(vlSelf->uart__DOT__bit_counter)))) 
                            & (IData)(vlSelf->uart__DOT__rx_shift_reg)) 
                           | (0xffU & ((IData)(vlSelf->rx) 
                                       << (7U & (IData)(vlSelf->uart__DOT__bit_counter)))));
                    if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                        __Vdly__uart__DOT__rx_state = 3U;
                        __Vdly__uart__DOT__bit_counter = 0U;
                    } else {
                        __Vdly__uart__DOT__bit_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->uart__DOT__bit_counter)));
                    }
                }
            } else if ((1U & (IData)(vlSelf->uart__DOT__rx_state))) {
                if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                    __Vdly__uart__DOT__rx_state = 2U;
                    __Vdly__uart__DOT__bit_counter = 0U;
                } else {
                    __Vdly__uart__DOT__bit_counter 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart__DOT__bit_counter)));
                }
            } else if ((1U & (~ (IData)(vlSelf->rx)))) {
                __Vdly__uart__DOT__rx_state = 1U;
            }
            if ((4U & (IData)(vlSelf->uart__DOT__tx_state))) {
                __Vdly__uart__DOT__tx_state = 0U;
            } else if ((2U & (IData)(vlSelf->uart__DOT__tx_state))) {
                if ((1U & (IData)(vlSelf->uart__DOT__tx_state))) {
                    if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                        __Vdly__uart__DOT__tx_state = 0U;
                        vlSelf->tx_ready = 1U;
                    } else {
                        __Vdly__uart__DOT__bit_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->uart__DOT__bit_counter)));
                    }
                } else {
                    vlSelf->tx = (1U & ((IData)(vlSelf->uart__DOT__tx_shift_reg) 
                                        >> (7U & (IData)(vlSelf->uart__DOT__bit_counter))));
                    if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                        __Vdly__uart__DOT__tx_state = 3U;
                        __Vdly__uart__DOT__bit_counter = 0U;
                    } else {
                        __Vdly__uart__DOT__bit_counter 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelf->uart__DOT__bit_counter)));
                    }
                }
            } else if ((1U & (IData)(vlSelf->uart__DOT__tx_state))) {
                if ((7U == (IData)(vlSelf->uart__DOT__bit_counter))) {
                    __Vdly__uart__DOT__tx_state = 2U;
                    __Vdly__uart__DOT__bit_counter = 0U;
                } else {
                    __Vdly__uart__DOT__bit_counter 
                        = (0xfU & ((IData)(1U) + (IData)(vlSelf->uart__DOT__bit_counter)));
                }
            } else if (vlSelf->wr_en) {
                __Vdly__uart__DOT__tx_state = 1U;
                vlSelf->uart__DOT__tx_shift_reg = vlSelf->data_in;
                vlSelf->tx_ready = 0U;
            }
        } else {
            vlSelf->rx_ready = 0U;
        }
    }
    vlSelf->uart__DOT__rx_state = __Vdly__uart__DOT__rx_state;
    vlSelf->uart__DOT__tx_state = __Vdly__uart__DOT__tx_state;
    vlSelf->uart__DOT__bit_counter = __Vdly__uart__DOT__bit_counter;
    vlSelf->uart__DOT__baud_counter = __Vdly__uart__DOT__baud_counter;
}

void Vuart___024root___eval_triggers__act(Vuart___024root* vlSelf);

bool Vuart___024root___eval_phase__act(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vuart___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vuart___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vuart___024root___eval_phase__nba(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vuart___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__nba(Vuart___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vuart___024root___dump_triggers__act(Vuart___024root* vlSelf);
#endif  // VL_DEBUG

void Vuart___024root___eval(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vuart___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("uart.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vuart___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("uart.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vuart___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vuart___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vuart___024root___eval_debug_assertions(Vuart___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->rx & 0xfeU))) {
        Verilated::overWidthError("rx");}
    if (VL_UNLIKELY((vlSelf->wr_en & 0xfeU))) {
        Verilated::overWidthError("wr_en");}
}
#endif  // VL_DEBUG
