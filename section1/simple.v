module simple(input logic clk, input logic reset, output logic [3:0] counter);
  always_ff @(posedge clk or posedge reset) begin 
      if (reset)
        counter <= 0;
      else
        counter <= counter + 1;
  end 
endmodule
