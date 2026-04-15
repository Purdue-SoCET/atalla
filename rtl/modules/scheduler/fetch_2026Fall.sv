`include "atalla_isa_types.vh"
import atalla_isa_pkg::*;
`include "BTB_if.vh"
`include "if_dec1_if.vh"
`include "datapath_cache_if.vh"

module fetch (
  input  logic    clk,
  input  logic    rst_n,
  input  logic    flush,
  input  logic    ready,
  input  logic    halt,
  input  word_t   pc_branch,

  // Interfaces
  datapath_cache_if.dp dc_if,
  if_dec1_if.src       ifdec1_if,
  BTB_if.fetch_view    btb_if
);

  address_t req_pc;
  address_t next_req_pc;
  logic     pred_taken;
  logic [3:0] fetch_epoch;  

  logic req_fire, resp_fire, resp_epoch_match;

  assign req_fire  = dc_if.if_req_valid  && dc_if.if_req_ready;
  assign resp_fire = dc_if.if_resp_valid && dc_if.if_resp_ready && resp_epoch_match;
  assign resp_epoch_match = (dc_if.if_resp_epoch == fetch_epoch);

  always_comb begin
    // BTFNT Strategy: Predict taken if BTB hits AND target is backward
    pred_taken = btb_if.bhit && (btb_if.predict_target < req_pc);
  end

  always_comb begin
    if (flush) begin
      next_req_pc = pc_branch;
    end
    else if (pred_taken) begin
      next_req_pc = btb_if.predict_target;
    end
    else begin
      next_req_pc = req_pc + PACKET_BYTE_W;
    end
  end

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      req_pc <= '0;
    end
    else if (flush || req_fire) begin
      req_pc <= next_req_pc;
    end
  end 

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      fetch_epoch <= '0;
    end
    else if (flush) begin
      fetch_epoch <= fetch_epoch + 1'b1;
    end
  end

  assign dc_if.if_req_valid  = !halt;
  assign dc_if.if_req_pc     = req_pc;
  assign dc_if.if_resp_ready = ready || flush;
  assign dc_if.if_req_pred_taken  = pred_taken;
  assign dc_if.if_req_pred_target = btb_if.predict_target;
  assign dc_if.if_req_epoch       = fetch_epoch;  


  assign btb_if.pc_fetch = req_pc;

  assign ifdec1_if.pc_in            = resp_fire ? dc_if.if_resp_pc : '0;
  assign ifdec1_if.predict_taken_in = resp_fire ? dc_if.if_resp_pred_taken : 1'b0;
  assign ifdec1_if.pc_pred_addr_in  = resp_fire ? dc_if.if_resp_pred_target : '0;
  assign ifdec1_if.inst_packet_in   = (resp_fire) ? dc_if.if_resp_packet : NOP_PACKET;

endmodule