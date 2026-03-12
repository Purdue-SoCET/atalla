`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"

module scheduler_core_flush_tb;
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
  logic        redir_v;
  logic [31:0] redir_pc;
  logic [31:0] redir_tgt;

  logic [31:0] d1_d2_pc;
  logic [31:0] dec2_ex_pc;

  assign pc_fetch   = DUT.datapath_cache_if.imemaddr;
  assign redir_v    = DUT.scalar_ex_if.redirect_valid;
  assign redir_pc   = DUT.scalar_ex_if.pc_out;
  assign redir_tgt  = DUT.scalar_ex_if.redirect_target;

  assign d1_d2_pc   = DUT.D1_D2_latch.pc;
  assign dec2_ex_pc = DUT.DEC2_EX_PC_latch.pc;

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
        imemload.inst0 = 48'h0018010082a4; // bne x1, x2, +0x30  (PC=0x30 -> target=0x60)
        imemload.inst1 = 48'h000000800196; // wrong-path inst0
        imemload.inst2 = 48'h000000800216; // wrong-path inst1
        imemload.inst3 = 48'h00000000002f; // nop
      end

      32'h0000_0048: begin
        imemload.inst0 = 48'h000000800296; // wrong-path inst2
        imemload.inst1 = 48'h000000800316; // wrong-path inst3
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      32'h0000_0060: begin
        imemload.inst0 = 48'h00000000002f; // target packet
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

    repeat(250) @(posedge CLK);

    $finish;
  end

endmodule