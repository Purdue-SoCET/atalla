`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"

module scheduler_core_branch_tb;
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

  logic        btb_hit;
  logic [31:0] btb_tgt;

  logic        pred_raw;
  logic [31:0] pc_fetch_raw;
  logic [31:0] next_pc_raw;

  logic [31:0] if_pc_in;
  logic        pred_in;
  logic [31:0] pred_tgt_in;

  logic [31:0] if_pc_out;
  logic        pred_out;
  logic [31:0] pred_tgt_out;

  logic [31:0] d1_d2_pc;
  logic [31:0] dec2_ex_pc;

  assign pc_fetch     = DUT.datapath_cache_if.imemaddr;
  assign redir_v      = DUT.scalar_ex_if.redirect_valid;
  assign redir_pc     = DUT.scalar_ex_if.pc_out;
  assign redir_tgt    = DUT.scalar_ex_if.redirect_target;

  assign btb_hit      = DUT.S_FETCH_DECODE_1.btb_if.bhit;
  assign btb_tgt      = DUT.S_FETCH_DECODE_1.btb_if.predict_target;

  assign pred_raw     = DUT.S_FETCH_DECODE_1.fu.pred_taken;
  assign pc_fetch_raw = DUT.S_FETCH_DECODE_1.fu.pc;
  assign next_pc_raw  = DUT.S_FETCH_DECODE_1.fu.next_pc;

  assign if_pc_in     = DUT.S_FETCH_DECODE_1.ifdec1_if.pc_in;
  assign pred_in      = DUT.S_FETCH_DECODE_1.ifdec1_if.predict_taken_in;
  assign pred_tgt_in  = DUT.S_FETCH_DECODE_1.ifdec1_if.pc_pred_addr_in;

  assign if_pc_out    = DUT.S_FETCH_DECODE_1.ifdec1_if.pc_out;
  assign pred_out     = DUT.S_FETCH_DECODE_1.ifdec1_if.predict_taken_out;
  assign pred_tgt_out = DUT.S_FETCH_DECODE_1.ifdec1_if.pc_pred_addr_out;

  assign d1_d2_pc     = DUT.D1_D2_latch.pc;
  assign dec2_ex_pc   = DUT.DEC2_EX_PC_latch.pc;

  localparam logic [31:0] PC_FWD_WRONG   = 32'h0000_0048; // wrong path after 0x30
  localparam logic [31:0] PC_FWD_TARGET  = 32'h0000_0060; // target of 0x30
  localparam logic [31:0] PC_BACK_BRANCH = 32'h0000_0090; // backward branch
  localparam logic [31:0] PC_RELEASE_FT  = 32'h0000_00a8; // fallthrough after loop release
  localparam logic [31:0] PC_TEST_BRANCH = 32'h0000_0120; // second branch test
  localparam logic [31:0] PC_TEST_FT     = 32'h0000_0138; // correct fallthrough
  localparam logic [31:0] PC_TEST_WRONG  = 32'h0000_0150; // wrong predicted target

  logic release_back_loop;
  logic use_not_taken_case;

  int back_branch_train_count;
  int not_taken_branch_fetch_count;

  always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
      release_back_loop            <= 1'b0;
      use_not_taken_case           <= 1'b0;
      back_branch_train_count      <= 0;
      not_taken_branch_fetch_count <= 0;
    end else begin
      // Train backward branch at 0x90 first.
      if (!release_back_loop && pc_fetch == PC_BACK_BRANCH) begin
        back_branch_train_count <= back_branch_train_count + 1;
        if (back_branch_train_count + 1 >= 8)
          release_back_loop <= 1'b1;
      end

      // After first visit to 0x120, switch to not-taken case.
      if (!use_not_taken_case && pc_fetch == PC_TEST_BRANCH) begin
        not_taken_branch_fetch_count <= not_taken_branch_fetch_count + 1;
        if (not_taken_branch_fetch_count + 1 >= 1)
          use_not_taken_case <= 1'b1;
      end
    end
  end

  // ------------------------------------------------------------
  // 0x000 : x1 = 1
  // 0x018 : x2 = 4
  // 0x030 : forward taken branch -> 0x060, wrong path at 0x048
  // 0x078 : loop body
  // 0x090 : backward branch for BTB / predictor training
  // 0x0A8 : fallthrough after releasing backward loop
  // 0x0D8 : set x2 for taken / not-taken phase
  // 0x120 : second branch under test
  // 0x138 : correct not-taken fallthrough
  // 0x150 : wrong predicted target
  // 0x168 : optional loop-back observation
  // ------------------------------------------------------------
  always_comb begin
    dhit      = 1'b0;
    data_load = 32'b0;
    ihit      = nRST;
    imemload  = '0;

    unique case (pc_fetch)

      // Set x1 for later branch compares.
      32'h0000_0000: begin
        imemload.inst0 = 48'h000000800096; // x1 = 1
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Set x2 so branch at 0x30 is taken.
      32'h0000_0018: begin
        imemload.inst0 = 48'h000002000116; // x2 = 4
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Forward branch test; later wrong path should be flushed.
      32'h0000_0030: begin
        imemload.inst0 = 48'h0018010082a4; // bne x1, x2, +0x30  (0x30 -> 0x60)
        imemload.inst1 = 48'h000000800196; // wrong-path op
        imemload.inst2 = 48'h000000800216; // wrong-path op
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Wrong path after the forward branch.
      PC_FWD_WRONG: begin
        imemload.inst0 = 48'h000000800296; // wrong-path op
        imemload.inst1 = 48'h000000800316; // wrong-path op
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Correct target after redirect.
      PC_FWD_TARGET: begin
        imemload.inst0 = 48'h00000000002f; // target packet
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Loop body before backward branch.
      32'h0000_0078: begin
        imemload.inst0 = 48'h00000000002f; // loop body nop
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Train taken first, then flip same PC to not-taken.
      PC_BACK_BRANCH: begin
        if (!release_back_loop)
          imemload.inst0 = 48'h00f40100c2a4; // bne x1, x2, -0x18  (0x90 -> 0x78), taken
        else
          imemload.inst0 = 48'h00f40080c2a4; // bne x1, x1, -0x18, actual not taken -> 0xA8

        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Fallthrough after releasing trained backward branch.
      PC_RELEASE_FT: begin
        imemload.inst0 = 48'h00000000002f; // released fallthrough
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Spacer toward second branch test.
      32'h0000_00c0: begin
        imemload.inst0 = 48'h00000000002f; // nop
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Switch x2 so branch at 0x120 can be taken first, then not taken.
      32'h0000_00d8: begin
        if (!use_not_taken_case)
          imemload.inst0 = 48'h000002000116; // x2 = 4, branch at 0x120 is taken
        else
          imemload.inst0 = 48'h000000800116; // x2 = 1, branch at 0x120 should be not taken

        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Spacer before second branch test.
      32'h0000_00f0: begin
        imemload.inst0 = 48'h00000000002f; // nop
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Spacer before second branch test.
      32'h0000_0108: begin
        imemload.inst0 = 48'h00000000002f; // nop
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Second branch test; observe taken vs not-taken behavior.
      PC_TEST_BRANCH: begin
        imemload.inst0 = 48'h0018010082a4; // bne x1, x2, +0x30  (0x120 -> 0x150)
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Correct path for not-taken branch.
      PC_TEST_FT: begin
        imemload.inst0 = 48'h00000000002f; // correct fallthrough when actual not taken
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Wrong predicted target for second branch.
      PC_TEST_WRONG: begin
        imemload.inst0 = 48'h000000800196; // wrong-path op
        imemload.inst1 = 48'h000000800216; // wrong-path op
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Optional loop-back check.
      32'h0000_0168: begin
        imemload.inst0 = 48'h00dc0100c2a4; // intended loop-back branch: 0x168 -> 0x120
        imemload.inst1 = 48'h00000000002f; // nop
        imemload.inst2 = 48'h00000000002f; // nop
        imemload.inst3 = 48'h00000000002f; // nop
      end

      // Keep core stable after program region.
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

    $display("DONE");
    $finish;
  end

endmodule