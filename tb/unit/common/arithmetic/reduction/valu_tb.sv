`timescale 1ns/1ps

`include "valu_if.vh"
`include "reduction_types.vh"

module valu_tb;
    import reduction_pkg::*;
    // ============================================================
    // Clock + Reset
    // ============================================================
    logic CLK = 0;
    logic nRST = 0;

    always #5 CLK = ~CLK;   // 100 MHz

    // ============================================================
    // Interface + DUT
    // ============================================================
    valu_if vif();

    valu dut (
        .CLK(CLK),
        .nRST(nRST),
        .valuif(vif)
    );

    // ============================================================
    // BF16 constants for testing
    // ============================================================
    localparam BF16_POS_ZERO = 16'h0000;
    localparam BF16_NEG_ZERO = 16'h8000;

    localparam BF16_INF      = 16'h7F80;
    localparam BF16_NINF     = 16'hFF80;

    localparam BF16_CANON_NAN= 16'h7FC0;

    localparam BF16_ONE      = 16'h3F80;
    localparam BF16_TWO      = 16'h4000;
    localparam BF16_TEN      = 16'h4120;

    localparam BF16_BIG      = 16'h7F7F;  // largest finite

    // ============================================================
    // Handshake-based send task
    // ============================================================
    task send_op(
    input logic [15:0] a,
    input logic [15:0] b,
    input logic [1:0]  op,
    input string       name
);
    begin
        // Wait until VALU is ready (every other cycle)
        while (!vif.ready_in)
            @(posedge CLK);

        // Drive request
        vif.operand1 = a;
        vif.operand2 = b;
        vif.alu_op   = op;
        vif.valid_in = 1;

        @(posedge CLK);
        vif.valid_in = 0;   // Fire single cycle

        // Wait for result
        while (!vif.valid_out)
            @(posedge CLK);

        $display("[%0t] %-12s A=%h B=%h → Result=%h",
            $time, name, a, b, vif.result);

        // Consume result
        vif.ready_out = 1;
        @(posedge CLK);
        vif.ready_out = 0;

        // *** IMPORTANT ***
        // VALU needs 1 bubble cycle before accepting new input
        @(posedge CLK);   // enforce "every other cycle"
    end
endtask

    // ============================================================
    // BF16 test vectors
    // ============================================================
    initial begin
        $display("==== Starting VALU BF16 Testbench ====");

        // Init interface
        vif.valid_in  = 0;
        vif.ready_out = 0;
        vif.operand1  = 0;
        vif.operand2  = 0;
        vif.alu_op    = 0;

        // Reset
        repeat (5) @(posedge CLK);
        nRST = 1;
        repeat (5) @(posedge CLK);

        // ========================================================
        // SUM Tests
        // ========================================================
        send_op(BF16_ONE, BF16_ONE, VR_SUM, "SUM 1+1");
        send_op(BF16_TEN, BF16_TWO, VR_SUM, "SUM 10+2");
        send_op(BF16_POS_ZERO, BF16_NEG_ZERO, VR_SUM, "SUM +0 + -0");
        send_op(BF16_INF, BF16_TWO, VR_SUM, "SUM inf + 2");
        send_op(BF16_CANON_NAN, BF16_ONE, VR_SUM, "SUM NaN input");

        // ========================================================
        // SUB Tests
        // ========================================================
        send_op(BF16_TEN, BF16_TWO, VR_SUB, "SUB 10-2");
        send_op(BF16_ONE, BF16_TWO, VR_SUB, "SUB 1-2");
        send_op(BF16_INF, BF16_INF, VR_SUB, "SUB inf - inf (NaN)");
        send_op(BF16_CANON_NAN, BF16_TEN, VR_SUB, "SUB NaN input");

        // ========================================================
        // MIN Tests
        // ========================================================
        send_op(BF16_ONE, BF16_TWO, VR_MIN, "MIN 1 vs 2");
        send_op(BF16_NEG_ZERO, BF16_POS_ZERO, VR_MIN, "MIN -0 vs +0");
        send_op(BF16_BIG, BF16_TWO, VR_MIN, "MIN max vs 2");
        send_op(BF16_CANON_NAN, BF16_TWO, VR_MIN, "MIN NaN input");

        // ========================================================
        // MAX Tests
        // ========================================================
        send_op(BF16_ONE, BF16_TWO, VR_MAX, "MAX 1 vs 2");
        send_op(BF16_BIG, BF16_TEN, VR_MAX, "MAX max vs 10");
        send_op(BF16_NEG_ZERO, BF16_POS_ZERO, VR_MAX, "MAX -0 vs +0");
        send_op(BF16_CANON_NAN, BF16_ONE, VR_MAX, "MAX NaN input");

        // End simulation
        $display("==== VALU BF16 Testbench Complete ====");
        $finish;
    end

endmodule
