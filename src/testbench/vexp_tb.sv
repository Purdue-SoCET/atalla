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

  int casenum;
  string casename;

initial begin

  casename = "NRST";
  casenum = 0;

  nRST = '0;
  vexpif.operand = '0;
  vexpif.valid_in = '0;
  vexpif.ready_out = '0;

  #(PERIOD * 5);

  //////////////////////////
  nRST = 1;
  
  casename = "e^1";
  casenum = 1;
  
  nRST = 1;
  vexpif.operand = 16'h3F80;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;

  #(PERIOD * 20);

  $stop;

end


endmodule
