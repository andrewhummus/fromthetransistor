module uart (
    input wire clk, 
    input wire reset, 
    input wire rx,
    output reg tx,
    input wire [7:0] data_in,
    input wire wr_en,
    output reg [7:0] data_out,
    output reg rx_ready,
    output reg tx_ready
);
  

    parameter CLK_FREQ = 50000000; // 50 Mhz
    parameter BAUD_RATE = 115200; // (115200 bps)
    localparam BAUD_DIV = CLK_FREQ / BAUD_RATE;

    typedef enum logic [2:0] {
        IDLE,
        START,
        DATA,
        STOP
    } state_t;

    state_t rx_state, tx_state;
    reg [15:0] baud_counter;
    reg [3:0] bit_counter;
    reg [7:0] rx_shift_reg, tx_shift_reg;

    always @(posedge clk or posedge reset) begin
      if (reset) begin 
          baud_counter <= 0;
      end else begin
        /* verilator lint_off WIDTHEXPAND */
        if (baud_counter >= BAUD_DIV - 1'b1) begin 
        /* verilator lint_off WIDTHEXPAND */
            baud_counter <= 0; 
        end else begin 
            baud_counter <= baud_counter + 1;
        end 
      end 
    end


    always @(posedge clk or posedge reset) begin 
        if (reset) begin 
          rx_state <= IDLE;
          bit_counter <= 0;
          rx_ready <= 0;

        end else if (baud_counter == 0) begin 
            case (rx_state)
                IDLE: if (~rx) rx_state <= START; 
                START: if (bit_counter == 3'd7) begin rx_state <= DATA; bit_counter <= 0; end else bit_counter <= bit_counter + 1;
                DATA: begin
                   /* verilator lint_off WIDTHTRUNC */
                    rx_shift_reg[bit_counter] <= rx;
                   /* verilator lint_off WIDTHTRUNC */
                    if (bit_counter == 3'd7) begin 
                      rx_state <= STOP;
                      bit_counter <= 0; 
                    end else bit_counter <= bit_counter + 1;

                end 
                STOP: if (bit_counter == 3'd7) begin rx_state <= IDLE; data_out <= rx_shift_reg; rx_ready <= 1; end else bit_counter <= bit_counter + 1;
                default: rx_state <= IDLE;
            endcase
         end else begin 
            rx_ready <= 0;
        end
    end

    always @(posedge clk or posedge reset) begin 
        if (reset) begin 
            tx_state <= IDLE;
            tx_ready <= 1; 
            bit_counter <= 0;
            tx <= 1'b1;
        end else if (baud_counter == 0) begin 
            case (tx_state) 
                IDLE: if (wr_en) begin tx_state <= START; tx_shift_reg <= data_in; tx_ready <= 0; end 
                START: if (bit_counter == 3'd7) begin tx_state <= DATA; bit_counter <= 0; end else bit_counter <= bit_counter + 1;
                DATA: begin
                    /* verilator lint_off WIDTHTRUNC */
                    tx <= tx_shift_reg[bit_counter];
                    /* verilator lint_off WIDTHTRUNC */
                    if (bit_counter == 3'd7) begin 
                        tx_state <= STOP;
                        bit_counter <= 0; 
                    end else bit_counter <= bit_counter + 1;
                end 
                STOP: if (bit_counter == 7) begin tx_state <= IDLE; tx_ready <= 1; end else bit_counter <= bit_counter + 1; 
                default: tx_state <= IDLE;
            endcase
        end 
    end 

endmodule
