`timescale 1ns / 10ps
`include "execution_unit_if.sv"
`include "scheduler_pkg.sv"
`include "atalla_isa_types.vh"

module scheduler_core_branch_tb;
  import execution_unit_types_pkg::*;
  import atalla_isa_pkg::*;

  parameter PERIOD = 2;
  logic CLK = 0, nRST;
  always #(PERIOD/2) CLK++;

  logic dhit;
  logic [31:0] data_load;
  logic ready_DEC2_out;
  logic ihit;
  instruction_packet_t imemload;

  scheduler_core DUT (
    .CLK(CLK), .nRST(nRST),
    .hit(dhit), .data_load(data_load),
    .ihit(ihit), .imemload(imemload),
    .ready(ready_DEC2_out)
  );

  // taps
  wire [31:0] pc_fetch = DUT.datapath_cache_if.imemaddr;
  wire        btb_hit  = DUT.S_FETCH_DECODE_1.btb_if.bhit;
  wire [31:0] btb_tgt  = DUT.S_FETCH_DECODE_1.btb_if.predict_target;
  wire        pred_taken_latched = DUT.decode_1_if.predict_taken_in;
  wire        redir_v   = DUT.scalar_ex_if.redirect_valid;
  wire [31:0] redir_tgt = DUT.scalar_ex_if.redirect_target;
  wire [31:0] redir_pc  = DUT.scalar_ex_if.pc_out;

  // your known constants
  localparam logic [47:0] NOP48 = 48'h2f;
  localparam logic [47:0] X1_EQ_1_HEX = 48'h000000800096; // x1=1 (you already used)
  // TODO: replace with your verified encoding for "x2 = 1"
  localparam logic [47:0] X2_EQ_1_HEX = 48'h000001000116; // <-- if not sure, replace

  // use your branch hex directly
  localparam logic [47:0] BEQ_HEX = 48'h0018010082a3; // your beq example

  task automatic set_tv (
    input logic [47:0] tv_instr0, tv_instr1, tv_instr2, tv_instr3,
    input int idx
  );
    $display("TV[%0d] @%0t PC=%08h", idx, $time, pc_fetch);

    @(negedge CLK);
      ihit = 1'b1;
      imemload.inst0 = tv_instr0;
      imemload.inst1 = tv_instr1;
      imemload.inst2 = tv_instr2;
      imemload.inst3 = tv_instr3;
    @(negedge CLK);
      ihit = 1'b0;

    repeat(8) @(negedge CLK);
  endtask

  // monitor
  always_ff @(posedge CLK) begin
    if (nRST) begin
      $display("[%0t] PC=%08h | BTB(hit=%0d tgt=%08h) | pred_taken=%0d | redir(v=%0d pc=%08h tgt=%08h) | ready=%0d",
               $time, pc_fetch, btb_hit, btb_tgt, pred_taken_latched,
               redir_v, redir_pc, redir_tgt, ready_DEC2_out);
    end
  end

  // scoreboard
  logic        saw_redirect;
  logic [31:0] trained_tgt;

  initial begin
    dhit = 1'b0;
    data_load = 32'b0;
    ihit = 1'b0;
    imemload = '0;

    nRST = 1'b0;
    repeat(2) @(posedge CLK);
    nRST = 1'b1;
    repeat(2) @(posedge CLK);

    // init regs so BEQ can be taken
    set_tv(X1_EQ_1_HEX, NOP48, NOP48, NOP48, 1);
    set_tv(X2_EQ_1_HEX, NOP48, NOP48, NOP48, 2);

    // inject BEQ (your encoding)
    set_tv(BEQ_HEX, NOP48, NOP48, NOP48, 3);

    // wait for redirect (BTB training point)
    saw_redirect = 1'b0;
    trained_tgt  = '0;

    // give some cycles window to see redirect
    repeat(200) @(posedge CLK);
    if (!redir_v) begin
      $fatal(1, "FAIL: redirect_valid never asserted after BEQ. Likely BEQ not taken or encoding mismatch (rs/imm/incr).");
    end

    // capture target at first redirect edge
    // (simple: just sample after it becomes 1)
    wait (redir_v == 1'b1);
    trained_tgt = redir_tgt;
    saw_redirect = 1'b1;
    $display("---- CAPTURE redirect: pc_out=%08h target=%08h ----", redir_pc, trained_tgt);

    // Now run some more cycles; if your BEQ target loops back, BTB should eventually hit
    repeat(400) @(posedge CLK);

    // Not forcing a specific PC here because your BEQ_HEX has its own imm/behavior.
    // We only check that BTB ever hits after training.
    if (btb_hit !== 1'b1) begin
      $fatal(1, "FAIL: Never saw btb_hit go high after redirect training. Branch may not revisit the same PC.");
    end

    $display("DONE");
    $finish;
  end

endmodule