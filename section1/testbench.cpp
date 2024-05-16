#include <verilated.h>
#include "Vsimple.h"

int main(int argc, char** argv, char** env) {
  Verilated::commandArgs(argc, argv);
  Vsimple* top = new Vsimple;


  top->clk = 0;
  top->reset = 1;
  top->eval();

  for (int i = 0; i < 10; i++) {
    top->clk = !top->clk;
    if (i==2) top->reset = 0;
    top->eval();
    printf("At time %d: counter = %d\n", i, top->counter);
  }

  top->final();
  delete top;
  return 0;
}
