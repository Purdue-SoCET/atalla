`include "atalla_isa_types.vh"
`include "datapath_cache_if.vh"
`include "if_dec1_if.vh"
`include "dec1_dec2_if.vh"
`include "BTB_if.vh"

import atalla_isa_pkg::*;

module fetch_decode1 (
    input logic     clk,
    input logic     rst_n,


    input logic     flush,
    input logic     ready,
    input word_t    pc_branch,


    input logic     btb_update_en,
    input address_t btb_pc_update,
    input address_t btb_true_target,


    datapath_cache_if.dp dc_if,
    dec1_dec2_if.src         dec12_if
);


  if_dec1_if ifdec1_if();
  BTB_if     btb_if();



  assign ifdec1_if.ready = ready;
  assign ifdec1_if.flush = flush;
  assign ifdec1_if.ihit  = dc_if.ihit;

  assign btb_if.update_en   = btb_update_en;
  assign btb_if.pc_update   = btb_pc_update;
  assign btb_if.true_target = btb_true_target;



  fetch fu (
    .clk(clk), .rst_n(rst_n), .flush(flush), .ready(ready), .pc_branch(pc_branch), .dc_if(dc_if), .ifdec1_if(ifdec1_if.src), .btb_if(btb_if.fetch_view)
  );


  if_dec1_reg ifdec1_reg (
    .CLK(clk), .nRST(rst_n), .ifdec1_if(ifdec1_if)
  );


  decode1_stage dec1_u (
    .ifdec1_if(ifdec1_if.dst), .dec12_if(dec12_if)
  );


  BTB btb_u (
    .CLK(clk), .nRST(rst_n), .btb_if(btb_if.btb_view)
  );

endmodule