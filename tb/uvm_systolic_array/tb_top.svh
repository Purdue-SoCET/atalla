module tb_top;

  timeunit 1ns;
  timeprecision 1ps;

  import uvm_pkg::*;

  logic clk   = 1'b0;
  logic n_rst = 1'b0;

  systolic_array_tb_if tb_if (
    .clk(clk),
    .n_rst(n_rst)
  );

  always #5ns clk = ~clk;

  initial begin
    repeat (5) @(negedge clk);
    n_rst = 1'b1;
  end

  systolic_array #(
  .N(4),
  .WIDTH(16)
) dut (
  .clk(clk),
  .nRST(n_rst),
  .memory(memory_if)
);
  
  initial begin
    uvm_config_db#(virtual systolic_array_tb_if)::set(
      null, "uvm_test_top.*", "vif", tb_if
    );

    run_test("systolic_array_test");
  end

endmodule
