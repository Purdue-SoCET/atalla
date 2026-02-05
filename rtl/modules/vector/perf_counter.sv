module perf_counter #(
  parameter int WIDTH = 32 // Width of the counter
) (
  input logic CLK,
  input logic nRST,
  input logic enable = 1'b1, // Enable counting
  input logic clear = 1'b0, // Synchronous clear
  output logic [WIDTH-1:0] count // Current count value
);

  always_ff @(posedge CLK, negedge nRST) begin : counter_ff
    if (!nRST) begin
      count <= '0;
    end else if (clear) begin
      count <= '0;
    end else if (enable) begin
      count <= count + 1;
    end
  end

endmodule

