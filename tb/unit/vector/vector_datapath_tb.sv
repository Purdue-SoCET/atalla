// ------------------------------------------------------------
// vector_datapath_tb.sv
// Top-level TB for vector_datapath
// ------------------------------------------------------------
`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"
`include "vector_tb_pkg.sv"    // the package above
`include "vector_datapath.sv"       // where vector_datapath is defined

module vector_datapath_tb;
  import vector_pkg::*;
  import vector_tb_pkg::*;

  // Clock and reset
  logic CLK;
  logic nRST;

  // Interface instance
  vector_if vif();

  // DUT (note: use the vector modport!)
  vector_datapath DUT (
    .CLK (CLK),
    .nRST(nRST),
    .vif (vif)
  );

  // Env
  vector_env env;

  // Clock
  initial begin
    CLK = 1'b0;
    forever #5 CLK = ~CLK;
  end

  // Reset and env start
 initial begin
  nRST = 1'b0;

  // Only clear what the testbench owns
  vif.vector_in.valid_in = '0;
  vif.vector_in.rm       = '0;
  vif.vector_in.fu_sel   = '{default:'0};
  vif.vector_in.vd       = '0;
  vif.vector_in.vop      = '0;
  vif.vector_in.v1       = '{default:'0};
  vif.vector_in.v2       = '{default:'0};
  vif.vector_in.vmask    = '0;
  // Do NOT assign ready_in here
  vif.vector_in.ready_in = '1;

  repeat (10) @(posedge CLK);
  nRST = 1'b1;

  env = new(vif);
  env.run();
end


endmodule
