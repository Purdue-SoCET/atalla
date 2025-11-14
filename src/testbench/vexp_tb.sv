// vexp_tb.sv
`timescale 1ns/1ps

`include "vector_types.vh"
`include "vector_if.vh"
`include "vexp_if.vh"
`include "vaddsub_if.vh"

module vexp_tb;
  
  parameter PERIOD = 10;
  logic CLK = 0, nRST;

  always #(PERIOD/2) CLK++;

  vexp_if vexpif();

  vexp dut (
  .CLK   (CLK),
  .nRST  (nRST),
  .vexpif(vexpif)
  );

  localparam logic [15:0] FP16_P0   = 16'h0000; // +0
  localparam logic [15:0] FP16_N0   = 16'h8000; // -0
  localparam logic [15:0] FP16_ONE  = 16'h3C00; // +1
  localparam logic [15:0] FP16_NEG1 = 16'hBC00; // -1
  localparam logic [15:0] FP16_TWO  = 16'h4000; // +2
  localparam logic [15:0] FP16_HALF = 16'h3800; // +0.5
  localparam logic [15:0] FP16_PINF = 16'h7C00; // +Inf
  localparam logic [15:0] FP16_NINF = 16'hFC00; // -Inf
  localparam logic [15:0] FP16_QNAN = 16'h7E00; // qNaN

  int casenum;
  string casename;

initial begin

  casename = "NRST";
  casenum = 0;

  nRST = '0;
  vexpif.operand = '0;
  vexpif.a = '0;
  vexpif.valid_in = '0;
  vexpif.ready_out = '0;

  $stop;

end


endmodule
