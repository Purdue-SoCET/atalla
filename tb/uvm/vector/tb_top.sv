`timescale 1ns/1ps

import uvm_pkg::*;
`include "uvm_macros.svh"
import vector_pkg::*;

module tb_top;

  // --------------------------------------------------
  // Clock & Reset
  // --------------------------------------------------
  logic CLK;
  logic nRST;

  initial CLK = 0;
  always #5 CLK = ~CLK;   // 100 MHz

  initial begin
    nRST = 0;
    #50;
    nRST = 1;
  end

  // --------------------------------------------------
  // Interface Instance
  // --------------------------------------------------
  vector_if vif (.*);   // assumes vector_if has CLK,nRST

  // --------------------------------------------------
  // DUT Instance (Single Lane)
  // --------------------------------------------------
  lane #(
    .LANE_ID(0)
  ) dut (
    .CLK (CLK),
    .nRST(nRST),
    .lif (vif)
  );

  // --------------------------------------------------
  // UVM Config DB Setup
  // --------------------------------------------------
  initial begin
    uvm_config_db#(virtual vector_if)::set(
      null,
      "*",
      "vif",
      vif
    );

    run_test();
  end

endmodule