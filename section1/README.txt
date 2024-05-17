Section 1: Cheating our way past the transitor

Transistors are building blocks of electronic devices. They act like switches or amplifiers, controlling the flow of electrical current in circuits. Integrated Circuits are collections of transistors organized into functional units.

Field-Programmable Gate Arraus (FPGAs) 

FPGAs are reconfigureaable ICs that can be programmed to perform specific tasks. Unlike fixed-function ICs, FPGAs offer flexibility and adaptability, making them ideal for prototyping applications.

Inside an FPGA, you will discover:

- Lookup Tables: These are programmable logic blocks that implement boolean funcs.
- Flip-Flops: Used for storing binary data and implementing sequential logic.
- Interconnects: Network that connect various logic blocks and allow communication between them.

Download verilator: https://www.veripool.org/verilator/

Generate the model

verilator -Wall --cc --exe --build simple.v testbench.cpp

Run test bench 
./obj_dir/Vsimple
