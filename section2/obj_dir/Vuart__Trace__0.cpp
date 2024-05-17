// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vuart__Syms.h"


void Vuart___024root__trace_chg_0_sub_0(Vuart___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vuart___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root__trace_chg_0\n"); );
    // Init
    Vuart___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vuart___024root*>(voidSelf);
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vuart___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vuart___024root__trace_chg_0_sub_0(Vuart___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->uart__DOT__rx_state),3);
        bufp->chgCData(oldp+1,(vlSelf->uart__DOT__tx_state),3);
        bufp->chgSData(oldp+2,(vlSelf->uart__DOT__baud_counter),16);
        bufp->chgCData(oldp+3,(vlSelf->uart__DOT__bit_counter),4);
        bufp->chgCData(oldp+4,(vlSelf->uart__DOT__rx_shift_reg),8);
        bufp->chgCData(oldp+5,(vlSelf->uart__DOT__tx_shift_reg),8);
    }
    bufp->chgBit(oldp+6,(vlSelf->clk));
    bufp->chgBit(oldp+7,(vlSelf->reset));
    bufp->chgBit(oldp+8,(vlSelf->rx));
    bufp->chgBit(oldp+9,(vlSelf->tx));
    bufp->chgCData(oldp+10,(vlSelf->data_in),8);
    bufp->chgBit(oldp+11,(vlSelf->wr_en));
    bufp->chgCData(oldp+12,(vlSelf->data_out),8);
    bufp->chgBit(oldp+13,(vlSelf->rx_ready));
    bufp->chgBit(oldp+14,(vlSelf->tx_ready));
}

void Vuart___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vuart___024root__trace_cleanup\n"); );
    // Init
    Vuart___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vuart___024root*>(voidSelf);
    Vuart__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
