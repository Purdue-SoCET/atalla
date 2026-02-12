`ifndef S_WB_ARBITER_IF
`define S_WB_ARBITER_IF

`include "scalar_wb_arbiter_pkg.vh"

interface s_wb_arbiter;
  import scalar_wb_pkg::*;

  // Top level signals
  logic CLK, nRST;

  scalar_wb_in_t scalar_wb_in;
  scalar_wb_out_t scalar_wb_out;

  modport s_wb_arbiter (
    input CLK, nRST,
    input scalar_wb_in_out,
    output scalar_wb_out_in
  );

endinterface

`endif