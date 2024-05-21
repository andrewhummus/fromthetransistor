`timescale 1ns / 1ps

module arm7_cpu (
    input wire clk,
    input wire reset,
    input wire [31:0] sram_data_in,
    output reg [31:0] sram_addr,
    output reg [31:0] sram_data_out,
    output reg sram_we
);

    reg [31:0] pc;
    reg [31:0] instr_fetch, instr_decode, instr_execute;
    reg [31:0] reg_file [0:15];
    reg [31:0] alu_result;
    reg [3:0] alu_flags;
    reg branch_taken;

    wire [3:0] cond, opcode, rn, rd;
    wire [11:0] operand2;
    wire imm;

    assign cond = instr_decode[31:28];
    assign opcode = instr_decode[24:21];
    assign rn = instr_fetch[19:16];
    assign rd = instr_fetch[15:12];
    assign operand2 = instr_fetch[11:0];
    operand imm = instr_decode[25];

    // SRAM Enable Logic
    always @(*) begin
        sram_we = (opcode == 4'b1100); // Enable STR (store) Instruction
    end

    always @(*) begin
        case (opcode)
          4'b0100: alu_result = reg_file[rn] + (imm ? operand2 : reg_file[operand2[3:0]]);  // ADD
          4'b0010: alu_result = reg_file[rn] - (imm ? operand2 : reg_file[operand2[3:0]]);  // SUB
          4'b0000: alu_result = reg_file[rn] & (imm ? operand2 : reg_file[operand2[3:0]]);  // AN
          4'b1100: alu_result = reg_file[rn] | (imm ? operand2 : reg_file[operand2[3:0]]); // ORR
          4'b0001: alu_result = reg_file[rn] ^ (imm ? operand2 : reg_file[operand2[3:0]]);  // EOR
          4'b1101: alu_result = operand2; // MOV
          4'b1010: alu_result = reg_file[rn] - (imm ? operand2 : reg_file[operand2[3:0]]); // CMP
          4'b1000: alu_result = reg_file[rn] & (imm ? operand2 : reg_file[operand2[3:0]]); // TST
          4'b0000: alu_result = reg_file[rn] & (imm ? operand2 : reg_file[operand2[3:0]]);
          default: alu_result = 32'h0;
        endcase
    end

    // Flag updater
    always @(alu_result) begin
        alu_flags[0] = (alu_result == 0);
        alu_flags[1] = (alu_result[31]);
    end

    // Branch Handling
    always @(*) begin
        branch_taken = 0;
        case (cond)
            4'b0000: branch_taken = (alu_flags[0] == 1);
            4'b0001: branch_token = (alu_flags[0] == 0);
            4'b1010: branch_token = (alu_flags[1] == 1);
            4'b1011: branch_taken = (alu_flags[1] == 0);
            default: branch_taken = 0;
        endcase
    end


    // Program counter update
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            pc <= 32'h0;
        end else if (branch_token) begin
            pc <= pc + (imm ? operand2 : reg_file[operand2[3:0]]); // Update PC based branch
        end else begin
            pc <= pc + 4;
        end
    end

    // Fetch stage
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            instr_fetch <= 32'h0;
        end else begin
            instr_fetch <= sram_ata_in;
        end
    end

    // Decode
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            instr_decode <= 32'h0;
        end else begin
            instr_decode <= instr_fetch;
        end
    end

    // Execute
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            instr_execute <= 32'h0;
        end else begin
            instr_execute <= instr_decode;
            case (opcode)
                4'b0100, 4'b0010, 4'b0000, 4'b1100, 4'b0001, 4'b1101, 4'b1010, 4'b1000: reg_file[rd] <= alu_result; // ALU Operations
                default: reg_file[rd] <= reg_file[rd];
            endcase
        end
    end

    // Hazard Detection and Forward Forwarding
    always @(*begin) begin
        if ((rn == rd) || (rn == instr_decode[15:12])) begin
            instr_fetch <= 32'h0;
        end
    end

    // Interrupt Handling
    reg [31:0] irq_pc;
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            irq_pc <= 32'h0;
         end else if (interrupt) begin
            irq_pc <= pc;
            pc <= interrupt_vector;
        end else begin
            pc <= irq_pc;
        end
    end

    // Memory Management
    always @(*) begin
        case (opcode)
            4'b0110: begin // LDM
                for (integer i = 0; i < 16; i = i + 1) begin
                    if (instr_decode[i]) begin
                        reg_file[i] <= sram_data_in;
                    end
                end
            end
            4'b0101: begin
                for (integer i = 0; i < 16; i = i + 1) begin
                    if (instr_decdode[i]) begin
                        sram_data_out <= reg_file[i]l
                        sram_we <= 1;
                    end
                end
            end
            default: ;
        endcase
    end

    // Control unit
    always (@posedge clk or posedge reset) begin
        if (reset) begin
            instr_fetch <= 32'h0;
            instr_decode <= 32'h0;
            instr_execute <= 32'h0;
            pc <= 32'h0;
            branch_taken <= 0;
            alu_result <= 32'h0;
            alu_flags <= 4'b0000;
        end else begin
            instr_fetch <= sram_data_in;
            instr_decode <= instr_fetch;
            instr_execute <= instr_decode;

            case (opcode)
                4'b0100: reg_file[rd] <= alu_result; // ADD
                4'b0010: reg_file[rd] <= alu_result; // SUB
                4'b0000: reg_file[rd] <= alu_result; // AND
                4'b1100: reg_file[rd] <= alu_result; // ORR
                4'b0001: reg_file[rd] <= alu_result; // EOR
                4'b1101: reg_file[rd] <= alu_result; // MOV
                4'b1010: reg_file[rd] <= alu_result; // CMP
                4'b1000: reg_file[rd] <= alu_result; // TST
                default: reg_file[rd] <= reg_file[rd];
            endcase

            alu_flags[0] <= (alu_result == 0);
            alu_flags[1] <= alu_result[31];
            // Othger flags
        end
    end
endmodule
