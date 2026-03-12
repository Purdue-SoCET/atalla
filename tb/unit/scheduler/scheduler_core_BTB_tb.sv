`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"

module scheduler_core_BTB_tb;
  import execution_unit_types_pkg::*;
  import atalla_isa_pkg::*;

  parameter PERIOD = 2;
  logic CLK = 0, nRST;
  always #(PERIOD/2) CLK = ~CLK;

  logic dhit;
  logic [31:0] data_load;
  logic ready_DEC2_out;
  logic ihit;
  instruction_packet_t imemload;

  scheduler_core DUT (
    .CLK(CLK),
    .nRST(nRST),
    .hit(dhit),
    .data_load(data_load),
    .ihit(ihit),
    .imemload(imemload),
    .ready(ready_DEC2_out)
  );

  logic [31:0] pc_fetch;
  logic        btb_hit;
  logic [31:0] btb_tgt;

  logic        redir_v;
  logic [31:0] redir_tgt;
  logic [31:0] redir_pc;

  logic        pred_raw;
  logic [31:0] pc_fetch_raw;
  logic [31:0] next_pc_raw;

  assign pc_fetch     = DUT.datapath_cache_if.imemaddr;
  assign btb_hit      = DUT.S_FETCH_DECODE_1.btb_if.bhit;
  assign btb_tgt      = DUT.S_FETCH_DECODE_1.btb_if.predict_target;

  assign redir_v      = DUT.scalar_ex_if.redirect_valid;
  assign redir_tgt    = DUT.scalar_ex_if.redirect_target;
  assign redir_pc     = DUT.scalar_ex_if.pc_out;

  assign pred_raw     = DUT.S_FETCH_DECODE_1.fu.pred_taken;
  assign pc_fetch_raw = DUT.S_FETCH_DECODE_1.fu.pc;
  assign next_pc_raw  = DUT.S_FETCH_DECODE_1.fu.next_pc;

  always_comb begin
    dhit      = 1'b0;
    data_load = 32'b0;
    ihit      = nRST;
    imemload  = '0;

    unique case (pc_fetch)
      32'h0000_0000: begin
        imemload.inst0 = 48'h000000800096; // x1 = 1
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      32'h0000_0018: begin
        imemload.inst0 = 48'h000002000116; // x2 = 4
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      32'h0000_0030: begin
        imemload.inst0 = 48'h00f40100c2a4; // bne x1, x2, -0x18  (PC=0x30 -> target=0x18)
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      default: begin
        imemload.inst0 = 48'h00000000002f; // nop
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end
    endcase
  end

  initial begin
    nRST = 1'b0;
    repeat(2) @(posedge CLK);
    nRST = 1'b1;

    repeat(500) @(posedge CLK);

    $finish;
  end

endmodule