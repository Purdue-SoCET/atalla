`ifndef V_WB_ARBITER_IF
`define V_WB_ARBITER_IF

`include "vector_pkg.vh"

interface v_wb_arbiter_if;
  import vector_pkg::*;

  // Top level signals
  logic CLK, nRST;

  vector_out_t vector_out;
  veggie_out_t veggie_out;
  veggie_in_t veggie_in;

  modport v_wb_arbiter_if (
    // input CLK, nRST,
    input vector_out,
    input veggie_out,
    output veggie_in
  );

endinterface

`endif
