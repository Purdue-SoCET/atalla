`ifndef V_WB_ARBITER_IF
`define V_WB_ARBITER_IF

`include "vector_pkg.vh"
//`include "scpad_pkg.sv"

interface v_wb_arbiter_if;
  import vector_pkg::*;

  // Top level signals
  // logic CLK, nRST;

  vector_wb_in_t vector_wb_in;
  vector_wb_out_t vector_wb_out;

  modport v_wb_arbiter_if (
    input vector_wb_in,
    output vector_wb_out
  );

endinterface

`endif
