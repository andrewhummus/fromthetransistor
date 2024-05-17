#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vblink_led.h"

const int CLOCK_PERIOD = 10;

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);

  Vblink_led *top = new Vblink_led;

  VerilatedVcdC *trace = new VerilatedVcdC;
  Verilated::traceEverOn(true);
  top->trace(trace, 99);
  trace->open("blink_led.vcd");

  top->clk = 0;
  top->reset = 1;

  for (int i = 0; i < 200000; i++) {
      top->clk = !top->clk;

      if (i < 20) {
        top->reset = 1;
      } else {
        top->reset = 0;
      }

      top->eval();

      trace->dump(i * CLOCK_PERIOD / 2);

      Verilated::timeInc(CLOCK_PERIOD / 2);
  }

  trace->close();
  top->final();

  delete top;
  delete trace;

  return 0;
}
