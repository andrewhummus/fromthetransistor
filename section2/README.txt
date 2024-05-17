Section 2: What language is hardware coded in? 

Emulation -- Real hardware? Cool but limiting. We're using Verilator, so all you need is a computer. No fancy FPGA boards required. 

Welcome to Verilog :). This is where we start programming hardware. This is the stuff that make our devices tick. Not that high-level shit.

**Blinking awn LED (Verilog)** 
- Make an LED Blink. Nothing fancy, but sick.

**Building the UART (Verilog)**
- TLDR a UART teaches your hardware to communciate.
- You'll learn: 
  - Verilog constructs, like state machines, case statements
  - HOw to do memory-mapped I/O (MMIO)
  - Testinmg/debugging Verilog designs

**Advanced Verilog Constructs**
1. State machines: used to model vehavior of sequential logic. They help in designing complex control logic by defining different states and transitions between them.
  - Example Structure:
    ```
        typedef enum logic [1:0] {
         IDLE,
         START,
         TRANSFER,
         STOP
     } state_t;

     state_t current_state, next_state;

     always @(posedge clk or posedge reset) begin
         if (reset) begin
             current_state <= IDLE;
         end else begin
             current_state <= next_state;
         end
     end

     always @(*) begin
         case (current_state)
             IDLE: next_state = START;
             START: next_state = TRANSFER;
             TRANSFER: next_state = STOP;
             STOP: next_state = IDLE;
             default: next_state = IDLE;
         endcase
     end
     ```

2. **Case Statements**": Used for decision making logic, similar to switch-case in software programming.

  - Example Structure:
  ```
  always @(*) begin
         case (opcode)
             4'b0000: result = operand1 + operand2; // ADD
             4'b0001: result = operand1 - operand2; // SUBTRACT
             4'b0010: result = operand1 & operand2; // AND
             4'b0011: result = operand1 | operand2; // OR
             default: result = 0;
         endcase
     end
  ```

**UART Protocol**
- **Overview**: UART (Universal Asynchronous Receiver-Transmitter) is a protocol for serial communication. It transmits data one bit at a time, with start, data, parity, and stop bits.
- **Implementation Steps**:
  - Create a baud rate generator to control the timing of data transmission and reception.
  - Implement the transmitter module to send data.
  - Implement the receiver module to receive data.

**Memory-Mapped I/O (MMIO)**
- **Concept**: MMIO allows the CPU to control peripherals by reading and writing to specific memory addresses. It's like giving the CPU direct access to the device's registers.
- **Implementation**:
  - Define specific memory addresses for different control and status registers.
  - Use these addresses to read from and write to the peripherals.
