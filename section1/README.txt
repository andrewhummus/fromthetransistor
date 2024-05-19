Section 1: Cheating our way past the transitor

Transitors are essential components in electronics, acting as amplifiers, switches or signal modulators. They replaced vacuum tubes, making devices more efficient and compact. Made from semiconductor materials like sillicon, transitors can either conduct or insulate electrial current based on doping.

There are two main types of transitors: Bipolar Junction Transitors (BJTs) and Field-Effect Transitors (FETs). BJTs have three layers (emitter, base, collector ) and amplify signals by allowing a small base current to control larger current flow. FETs, including MOSFETs, control current via anelectric field with high input impedance and low output impedenace.

Transistors are foundational in both digital and analog circuits. In digital circuits, they act asswitches for logic gates and memory cells. In analog circuits, they amplify signals. ICs pack millions of transitors in a single chip, powering processors and memory devices.

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
