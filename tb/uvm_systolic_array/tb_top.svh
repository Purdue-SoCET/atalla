`timescale 1ns/1ps

`include "gsau_control_unit_if.vh"

interface systolic_array_tb_if (
  input logic clk,
  input logic n_rst
);
  gsau_control_unit_if bus();
endinterface


module tb_top;

  import uvm_pkg::*;
  import systolic_array_tb_pkg::*;

  logic clk   = 1'b0;
  logic n_rst = 1'b0;

  //tb if
  systolic_array_tb_if tb_if (
    .clk   (clk),
    .n_rst (n_rst)
  );

  //DUT
  sysarr_STANDARD #(
    .MAC_LATENCY(2)
  ) dut (
    .clk     (clk),
    .nRST    (n_rst),
    .gsau_if (tb_if.bus)
  );

  always #5 clk = ~clk;

  initial begin
    repeat (5) @(negedge clk);
    n_rst = 1'b1;
  end

  //start test
  initial begin
    uvm_config_db#(virtual systolic_array_tb_if)::set(
      null,
      "uvm_test_top.*",
      "vif",
      tb_if
    );

    run_test("systolic_array_test");
  end

endmodule
