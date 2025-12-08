`timescale 1ns/1ps
`include "reduction_types.vh"
`include "valu_if.vh"

module valu_tb;

    // ------------------------------------------------------
    // Clock / Reset
    // ------------------------------------------------------
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
        .valuif(valuif)
    );

    // ------------------------------------------------------
    // Utility: BF16 helper for testbench
    // ------------------------------------------------------
    function automatic logic [15:0] bf16(real r);
        shortreal sr = shortreal'(r);
        return sr[31:16];
    endfunction

    // ------------------------------------------------------
    // Simple drive tasks
    // ------------------------------------------------------

    // Issue one operation (every-other-cycle constraint respected)
    task automatic issue_op(
        input logic [15:0] a,
        input logic [15:0] b,
        input logic [1:0]  op
    );
        // Wait until DUT is ready
        @(posedge clk);
        while (!valuif.ready_in)
            @(posedge clk);

        valuif.operand1 = a;
        valuif.operand2 = b;
        valuif.alu_op   = op;
        valuif.valid_in = 1;

        @(posedge clk);  // one beat of valid
        valuif.valid_in = 0;

        // Issue every other cycle → insert bubble
        @(posedge clk);
    endtask

    // Hold ready_out low for N cycles (stall output)
    task automatic hold_output(int cycles);
        $display("[%0t] *** HOLDING OUTPUT for %0d cycles ***",
                 $time, cycles);
        valuif.ready_out = 0;
        repeat(cycles) @(posedge clk);
        valuif.ready_out = 1;
        $display("[%0t] *** RELEASE OUTPUT ***", $time);
    endtask

    // ------------------------------------------------------
    // Output monitor
    // ------------------------------------------------------
    always @(posedge clk) begin
        if (valuif.valid_out) begin
            $display("[%0t] OUT result=%h  (ready_out=%0b)",
                      $time, valuif.result, valuif.ready_out);
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
        valuif.operand1  = 0;
        valuif.operand2  = 0;
        valuif.alu_op    = 0;
        valuif.valid_in  = 0;

        valuif.ready_out = 1;   // IMPORTANT: default ready
        // (This was missing — caused backpressure test to never run)

        // --------------------------------------------------
        // Apply reset
        // --------------------------------------------------
        repeat (5) @(posedge clk);
        nRST = 1;
        repeat (2) @(posedge clk);

        // --------------------------------------------------
        // Basic SUM tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(1.0), VR_SUM);
        issue_op(bf16(10.0), bf16(2.0), VR_SUM);
        issue_op(16'h0000, 16'h8000, VR_SUM);     // +0 + -0
        issue_op(16'h7F80, bf16(2.0), VR_SUM);    // inf + 2
        issue_op(16'h7FC0, bf16(1.0), VR_SUM);    // NaN + x

        // --------------------------------------------------
        // SUB tests
        // --------------------------------------------------
        issue_op(bf16(10.0), bf16(2.0), VR_SUB);
        issue_op(bf16(1.0),  bf16(2.0), VR_SUB);
        issue_op(16'h7F80, 16'h7F80, VR_SUB);     // inf - inf
        issue_op(16'h7FC0, bf16(1.0), VR_SUB);    // NaN - x

        // --------------------------------------------------
        // MIN tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(2.0), VR_MIN);
        issue_op(16'h8000, 16'h0000, VR_MIN);     // -0 vs +0
        issue_op(16'h7F7F, bf16(2.0), VR_MIN);    // max vs 2
        issue_op(16'h7FC0, bf16(2.0), VR_MIN);    // NaN input

        // --------------------------------------------------
        // MAX tests
        // --------------------------------------------------
        issue_op(bf16(1.0), bf16(2.0), VR_MAX);
        issue_op(16'h7F7F, bf16(10.0), VR_MAX);   // max vs 10
        issue_op(16'h8000, 16'h0000, VR_MAX);     // -0 vs +0
        issue_op(16'h7FC0, bf16(1.0), VR_MAX);    // NaN input

        // --------------------------------------------------
        // BACKPRESSURE TEST
        // --------------------------------------------------
        $display("\n==== Starting Backpressure Test ====\n");

        issue_op(bf16(3.0), bf16(4.0), VR_SUM);

        // Stall output for 6 cycles
        hold_output(6);

        // Issue more ops after stall
        issue_op(bf16(5.0), bf16(6.0), VR_SUM);
        issue_op(bf16(7.0), bf16(8.0), VR_SUM);

        // --------------------------------------------------
        // Done
        // --------------------------------------------------
        repeat (20) @(posedge clk);

        $display("==== VALU Testbench Complete ====");
        $finish;
    end

endmodule
