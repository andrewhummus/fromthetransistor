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

    wire [3:0] cond;
    wire [3:0] opcode;
    wire [3:0] rn, rd;
    wire [11:0] operand2;
    wire imm;

    assign cond = instr_decode[31:28];
    assign opcode = instr_decode[24:21];
    assign rn = instr_fetch[19:16];
    assign rd = instr_fetch[15:12];
    assign operand2 = instr_fetch[11:0];
    operand imm = instr_decode[25];

    always @(*) begin
        case (opcode)
          4'b1100: sram_we = 1;
          default: sram_we = 0;

        endcase
    end

    always @(*) begin 
        sram_addr = alu_result;
        sram_data_out = reg_file[rn];
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
        alu_fags = (alu_result[31]);
    end
  
    // Program counter update 
    always @(posedge clk or posedge reset) begin 
        if (reset) begin 
            pc <= 32'h0;
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
    

    always @(posedge clk or posedge reset) begin 
        if (reset) begin 
            instr_execute <= 32'h0;
        end else begin 
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
                4'b0000: reg_file[rd] <= alu_result; // TEQ
                default: reg_file[rd] <= reg_file[rd];
            endcase 
        end
    end

endmodule
