`ifndef DEC1_DEC2_IF_VH
`define DEC1_DEC2_IF_VH

`include "atalla_isa_types.vh"

interface dec1_dec2_if;
  import atalla_isa_pkg::*;

  address_t          pc_in,            pc_out;
  logic              predict_taken_in, predict_taken_out;
  address_t          pc_pred_addr_in,  pc_pred_addr_out;

  instr_t [SCALAR_SLOTS-1:0] scalar_inst_in, scalar_inst_out;
  instr_t [VECTOR_SLOTS-1:0] vector_inst_in, vector_inst_out;
  instr_t [SCRATCH_SLOTS-1:0] scpad_inst_in, scpad_inst_out;

  // --- Control ---
  logic              ready;
  logic              flush;


  modport src (
    output pc_in, predict_taken_in, pc_pred_addr_in,
    output scalar_inst_in, vector_inst_in, scpad_inst_in
  );


  modport dst (
    input  pc_out, predict_taken_out, pc_pred_addr_out,
    input  scalar_inst_out, vector_inst_out, scpad_inst_out
  );

  modport latch_view (
    input  pc_in, predict_taken_in, pc_pred_addr_in,
    input  scalar_inst_in, vector_inst_in, scpad_inst_in,
    output pc_out, predict_taken_out, pc_pred_addr_out,
    output scalar_inst_out, vector_inst_out, scpad_inst_out,
    input  ready, flush
  );

endinterface

`endif