#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vuart.h"

const int CLOCK_PERIOD = 20; 

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    Vuart *top = new Vuart;

    // Trace initilization 
    VerilatedVcdC *trace = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(trace, 99);
    trace->open("uart.vcd");
    
    // Simulation inputs
    top->clk = 0;
    top->reset = 1;
    top->rx = 1;
    top->data_in = 0;
    top->wr_en = 0;
    
    // Release reset
    for (int i = 0; i < 10; i++) {
        top->clk = !top->clk;
        top->eval();
        trace->dump(i * CLOCK_PERIOD / 2);
    }
    top->reset = 0;
    
    // Transmit data
    top->data_in = 0x55;
    top->wr_en = 1;

    for (int i = 0; i < 1000; i++) {
        top->clk = !top->clk;
        top->eval();
        trace->dump(i * CLOCK_PERIOD / 2);
        
        // Write pulse
        if (i == 1) top->wr_en = 0;
    }
    
    trace->close();
    top->final();

    delete top;
    delete trace;

    return 0;
}
