module blink_led (
    input wire clk,
    input wire reset,
    output reg led 
);
  
    reg [31:0] counter; // Counter to create delay 

    // Paramater to set frequency
    parameter DIVISOR = 25000000;

    always @(posedge clk or posedge reset) begin 
        if (reset) begin 
          counter <= 0; 
          led <= 0; 
        end else begin
          counter <= counter + 1;
          if (counter >= DIVISOR) begin 
            counter <= 0;
            led <= ~led;
          end 

        end 
   end 
endmodule
