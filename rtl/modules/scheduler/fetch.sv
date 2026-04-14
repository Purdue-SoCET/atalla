`include "atalla_isa_types.vh"
import atalla_isa_pkg::*;
`include "BTB_if.vh"
`include "if_dec1_if.vh"
`include "datapath_cache_if.vh"

module fetch (
  input  logic    clk,
  input  logic    rst_n,
  input logic     flush,
  input logic     ready,
  input logic     halt,
  input word_t    pc_branch,

  // Interfaces
  datapath_cache_if.dp dc_if,
  if_dec1_if.src       ifdec1_if,
  BTB_if.fetch_view    btb_if
);

  address_t pc;
  address_t next_pc;
  logic     pred_taken;

  // --------------------------------------------------------------------------
  // Pass NOP when there's no ihit.
  // --------------------------------------------------------------------------
  //localparam r_t NOP_R = '{reserved:'0, rs2:'0, rs1:'0, rd:'0, opcode:NOP_S};
  //localparam logic [INST_W-1:0] NOP_INST = logic'(NOP_R);
  //localparam instruction_packet_t NOP_PACKET = '{inst0: NOP_INST, inst1: NOP_INST, inst2: NOP_INST, inst3: NOP_INST};

  always_comb begin
    // BTFNT Strategy: Predict taken if BTB hits AND target is backward
    pred_taken = btb_if.bhit && (btb_if.predict_target < pc);
  end


  always_comb begin
    if (halt) begin
      next_pc = '0;
    end
    else if (flush) begin
      // Priority 1: Redirect from Branch Unit (Misprediction Recovery)
      next_pc = pc_branch;
    end
    else if (pred_taken) begin
      // Priority 2: BTB Prediction
      next_pc = btb_if.predict_target;
    end
    else begin
      // Priority 3: Sequential flow
      next_pc = pc + PACKET_BYTE_W;
    end
  end


  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      pc <= 32'h0;
    end
    else begin

      // Currently unsure
      if (flush || (dc_if.ihit && ready)) begin
        pc <= next_pc;
      end
    end
  end

// Instantaneous outputs for current cycle lookup
  assign dc_if.imemaddr  = pc;
  assign btb_if.pc_fetch = pc;

  assign ifdec1_if.pc_in            = pc;
  assign ifdec1_if.predict_taken_in = dc_if.ihit ? pred_taken : 1'b0;
  assign ifdec1_if.pc_pred_addr_in  = dc_if.ihit ? btb_if.predict_target : '0;

  assign ifdec1_if.inst_packet_in   = (dc_if.ihit && !halt) ? dc_if.imemload : NOP_PACKET;
  

  always_comb begin
    if(ready && !flush) begin
      dc_if.imemREN = 1'b1;
    end else begin
      dc_if.imemREN = 1'b0;
    end

  end
endmodule