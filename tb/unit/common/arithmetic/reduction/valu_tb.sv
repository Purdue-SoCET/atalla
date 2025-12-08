`timescale 1ns/1ps
`include "reduction_types.vh"
`include "valu_if.vh"

module valu_tb;

    // ------------------------------------------------------
    // Clock / Reset
    // ------------------------------------------------------
    import reduction_pkg::*;
    logic clk = 0;
    always #5 clk = ~clk;

    logic nRST = 0;

    // ------------------------------------------------------
    // Interface
    // ------------------------------------------------------
    valu_if valuif();

    // ------------------------------------------------------
    // DUT
    // ------------------------------------------------------
    valu dut (
        .CLK(clk),
        .nRST(nRST),
        .alu(valuif)
    );

    // ------------------------------------------------------
    // Utility: BF16 helper for testbench
    // ------------------------------------------------------
    function automatic logic [15:0] bf16(real r);
        shortreal sr;
        logic [31:0] sr_bits;
        sr = r;
        sr_bits = $shortrealtobits(sr);  // convert shortreal to 32-bit logic
        bf16 = sr_bits[31:16];           // upper 16 bits = BF16
    endfunction

    // ------------------------------------------------------
    // Simple drive tasks
    // ------------------------------------------------------
    task automatic issue_op(
        input logic [15:0] a,
        input logic [15:0] b,
        input logic [1:0]  op
    );
        // Wait until DUT is ready
        @(posedge clk);
        while (!valuif.out.ready_in)
            @(posedge clk);

        valuif.in.operand1 = a;
        valuif.in.operand2 = b;
        valuif.in.alu_op   = op;
        valuif.in.valid_in = 1;

        @(posedge clk);
        valuif.in.valid_in = 0;

        // Issue every other cycle → insert bubble
    endtask

    task automatic hold_output(int cycles);
        $display("[%0t] *** HOLDING OUTPUT for %0d cycles ***",
                 $time, cycles);
        valuif.in.ready_out = 0;
        repeat(cycles) @(posedge clk);
        valuif.in.ready_out = 1;
        $display("[%0t] *** RELEASE OUTPUT ***", $time);
    endtask

    // ------------------------------------------------------
    // Output monitor
    // ------------------------------------------------------
    always @(posedge clk) begin
        if (valuif.out.valid_out) begin
            $display("[%0t] OUT result=%h  (ready_in=%0b)",
                      $time, valuif.out.result, valuif.out.ready_in);
        end
    end

    // ------------------------------------------------------
    // MAIN TEST
    // ------------------------------------------------------
    initial begin
        $display("==== Starting VALU Testbench ====");

        // --------------------------------------------------
        // Initialize interface signals
        // --------------------------------------------------
        valuif.in.operand1  = 0;
        valuif.in.operand2  = 0;
        valuif.in.alu_op    = 0;
        valuif.in.valid_in  = 0;
        valuif.in.ready_out = 1;  // default ready

        // --------------------------------------------------
        // Apply reset
        // --------------------------------------------------
        repeat (5) @(posedge clk);
        nRST = 1;
        repeat (2) @(posedge clk);

        // --------------------------------------------------
        // SUM tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(1.0), SUM);
        issue_op(bf16(10.0), bf16(2.0), SUM);
        issue_op(16'h0000, 16'h8000, SUM);     // +0 + -0
        issue_op(16'h7F80, bf16(2.0), SUM);    // inf + 2
        issue_op(16'h7FC0, bf16(1.0), SUM);    // NaN + x

        // --------------------------------------------------
        // SUB tests
        // --------------------------------------------------
        issue_op(bf16(10.0), bf16(2.0), SUB);
        issue_op(bf16(1.0),  bf16(2.0), SUB);
        issue_op(16'h7F80, 16'h7F80, SUB);     // inf - inf
        issue_op(16'h7FC0, bf16(1.0), SUB);    // NaN - x

        // --------------------------------------------------
        // MIN tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(2.0), MIN);
        issue_op(16'h8000, 16'h0000, MIN);     // -0 vs +0
        issue_op(16'h7F7F, bf16(2.0), MIN);    // max vs 2
        issue_op(16'h7FC0, bf16(2.0), MIN);    // NaN input

        // --------------------------------------------------
        // MAX tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(2.0), MAX);
        issue_op(16'h7F7F, bf16(10.0), MAX);   // max vs 10
        issue_op(16'h8000, 16'h0000, MAX);     // -0 vs +0
        issue_op(16'h7FC0, bf16(1.0), MAX);    // NaN input

        // --------------------------------------------------
        // BACKPRESSURE TEST
        // --------------------------------------------------
        $display("\n==== Starting Backpressure Test ====\n");

        issue_op(bf16(3.0), bf16(4.0), SUM);

        // Stall output for 6 cycles
        hold_output(6);

        // Issue more ops after stall
        issue_op(bf16(5.0), bf16(6.0), SUM);
        issue_op(bf16(7.0), bf16(8.0), SUM);

        // --------------------------------------------------
        // Done
        // --------------------------------------------------
        repeat (20) @(posedge clk);
        $display("==== VALU Testbench Complete ====");
        $finish;
    end

endmodule
