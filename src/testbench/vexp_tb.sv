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

  // casename = "NRST";
  // casenum = 0;

  // nRST = '0;
  // vexpif.operand = '0;
  // vexpif.valid_in = '0;
  // vexpif.ready_out = '0;

  // #(PERIOD * 1);

  // //////////////////////////
  // nRST = 1;
  // /////////////////////////
  
  // casename = "e^1";
  // casenum = 1;

  // vexpif.operand = 16'h3C00;
  // vexpif.valid_in = 1;
  // vexpif.ready_out = 1;

  // #(PERIOD * 13);

  // vexpif.valid_in = 0;

  // #(PERIOD * 1);

  // ////////////////////////////

  // casename = "e^2.5";
  // casenum = 2;

  // vexpif.operand = 16'h4100;
  // vexpif.valid_in = 1;
  // vexpif.ready_out = 1;

  // #(PERIOD * 13);

  // vexpif.valid_in = 0;

  // #(PERIOD * 1);

  // ////////////////////////////

  // casename = "e^8.9";
  // casenum = 3;

  // vexpif.operand = 16'h4873;
  // vexpif.valid_in = 1;
  // vexpif.ready_out = 1;

  // #(PERIOD * 13);

  // vexpif.valid_in = 0;

  // #(PERIOD * 1);

  // ////////////////////////////

  // casename = "e^-1";
  // casenum = 4;

  // vexpif.operand = 16'hBC00;
  // vexpif.valid_in = 1;
  // vexpif.ready_out = 1;

  // #(PERIOD * 13);

  // vexpif.valid_in = 0;

  // #(PERIOD * 1);

  // ////////////////////////////

  // casename = "e^-2.5";
  // casenum = 4;

  // vexpif.operand = 16'hC100;
  // vexpif.valid_in = 1;
  // vexpif.ready_out = 1;

  // #(PERIOD * 13);

  // vexpif.valid_in = 0;

  // #(PERIOD * 1);

  ///////////////////////////////////
  /////////// BF16 Tests ////////////
  ///////////////////////////////////

  casename = "NRST";
  casenum = 0;

  nRST = '0;
  vexpif.operand = '0;
  vexpif.valid_in = '0;
  vexpif.ready_out = '0;

  #(PERIOD * 1);

  //////////////////////////
  nRST = 1;
  /////////////////////////
  
  casename = "e^1";
  casenum = 1;

  vexpif.operand = 16'h3f80;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  ////////////////////////////

  casename = "e^2.5";
  casenum = 2;

  vexpif.operand = 16'h4020;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  ////////////////////////////

  casename = "e^8.9";
  casenum = 3;

  vexpif.operand = 16'h410E;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  ////////////////////////////

  casename = "e^12.6";
  casenum = 3;

  vexpif.operand = 16'h414a;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  ////////////////////////////

  casename = "e^-1";
  casenum = 4;

  vexpif.operand = 16'hbf80;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  ////////////////////////////

  casename = "e^-2.5";
  casenum = 4;

  vexpif.operand = 16'hc020;
  vexpif.valid_in = 1;
  vexpif.ready_out = 1;
  
  #(PERIOD * 1);
  
  vexpif.valid_in = 0;

  #(PERIOD * 14);

  $stop;

end

endmodule