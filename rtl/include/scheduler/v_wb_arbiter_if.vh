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
  scalar_wb_in_maskWBonly_t scalar_wb_in_maskWBonly;
  mask_wb_out_t mask_wb_out;
  logic scalarMaskNotReady;

  modport v_wb_arbiter_if (
    input vector_wb_in,
    input scalar_wb_in_maskWBonly,
    output vector_wb_out,
    output mask_wb_out,
    output scalarMaskNotReady
  );

endinterface

`endif
