`timescale 1ns/1ps

module tb_top;

  logic CLK;
  logic nRST;

  // Clock generation
  initial CLK = 0;
  always #5 CLK = ~CLK;   // 100MHz

  // Reset
  initial begin
    nRST = 0;
    repeat (5) @(posedge CLK);
    nRST = 1;
  end

  // Instantiate vector interface
  vector_if vif (CLK);

  // Instantiate ONE lane (LANE_ID = 0)
  lane #(
    .LANE_ID(0)
  ) dut (
    .CLK   (CLK),
    .nRST  (nRST),
    .lif   (vif.lane)
  );

  // Simple end simulation
  initial begin
    #2000;
    $finish;
  end

endmodule
