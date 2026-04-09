`ifndef IF_DEC1_IF_VH
`define IF_DEC1_IF_VH
`include "atalla_isa_types.vh"
  import atalla_isa_pkg::*;

interface if_dec1_if;

  address_t     pc_in, pc_out;
  logic         predict_taken_in, predict_taken_out;
  address_t     pc_pred_addr_in, pc_pred_addr_out;
  instruction_packet_t inst_packet_in, inst_packet_out;
  logic         ready, flush;
  logic         ihit;


  modport src (
    output pc_in, predict_taken_in, pc_pred_addr_in, inst_packet_in
  );


  modport dst (
    input  pc_out, predict_taken_out, pc_pred_addr_out, inst_packet_out
  );


  modport latch_view (
    input  pc_in, predict_taken_in, pc_pred_addr_in, inst_packet_in,
    input  ready, flush, ihit,
    output pc_out, predict_taken_out, pc_pred_addr_out, inst_packet_out
  );

endinterface

`endif