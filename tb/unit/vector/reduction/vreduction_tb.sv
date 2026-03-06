`timescale 1ns/1ps

`include "vreduction_if.vh"
`include "vector_pkg.vh"

module vreduction_tb;

    import vector_pkg::*;

    //--------------------------------------------
    // Clock + Reset
    //--------------------------------------------
    logic CLK = 0;
    logic nRST = 0;

    always #5 CLK = ~CLK;   // 100 MHz

    //--------------------------------------------
    // Interface + DUT
    //--------------------------------------------
    vreduction_if vruif();

    vreduction dut (
        .CLK(CLK),
        .nRST(nRST),
        .vruif(vruif)
    );

    //--------------------------------------------
    // Constant Dummy Data (not functionally checked)
    //--------------------------------------------
    logic [31:0][15:0] test_vec;
    logic [15:0][15:0] test_lane;

    initial begin
        for (int i = 0; i < 32; i++)
            test_vec[i] = 16'h3f80;

        for (int i = 0; i < 16; i++)
            test_lane[i] = 16'h3f80;
    end

    //--------------------------------------------
    // Main Test Sequence
    //--------------------------------------------
    initial begin
        //-------------------------------------------------
        // Default driving
        //-------------------------------------------------
        vruif.in.valid_in  = 0;
        vruif.in.ready_out = 1;
        vruif.in.clear     = 0;
        vruif.in.broadcast = 0;
        vruif.in.imm       = 0;
        vruif.in.reduction_type = ALU_ADD;
        vruif.in.vector_input   = test_vec;
        vruif.in.lane_input     = test_lane;

        //-------------------------------------------------
        // Reset
        //-------------------------------------------------
        nRST = 0;
        repeat (4) @(posedge CLK);
        nRST = 1;
        repeat (2) @(posedge CLK);

        run_ready_valid_tests();

        $display("\nAll non-pipelined handshake tests completed.");
        $finish;
    end

    //--------------------------------------------
    // Ready/Valid Tests for NON-PIPELINED Unit
    //--------------------------------------------
    task automatic run_ready_valid_tests();

        $display("\n====================================");
        $display(" NON-PIPELINED READY/VALID TESTS");
        $display("====================================");

        //-------------------------------------------------
        // TEST 1: ready_in must be HIGH after reset
        //-------------------------------------------------
        @(posedge CLK);
        if (!vruif.out.ready_in)
            $error("FAIL: ready_in not HIGH after reset");
        else
            $display("PASS: ready_in HIGH after reset");

        //-------------------------------------------------
        // TEST 2: Accept single transaction
        //-------------------------------------------------
        $display("\nTest 2: Single transaction acceptance");

        vruif.in.valid_in = 1;

        wait (vruif.out.ready_in);
        @(posedge CLK);  // handshake happens

        vruif.in.valid_in = 0;

        @(posedge CLK);

        if (vruif.out.ready_in)
            $error("FAIL: ready_in did not drop after accept (should be busy)");
        else
            $display("PASS: ready_in dropped (unit busy)");

        //-------------------------------------------------
        // TEST 3: Must NOT accept new transaction while busy
        //-------------------------------------------------
        $display("\nTest 3: Reject new transaction while busy");

        vruif.in.valid_in = 1;

        repeat (3) @(posedge CLK);

        if (vruif.out.ready_in)
            $error("FAIL: ready_in asserted while busy");
        else
            $display("PASS: ready_in remained LOW while busy");

        vruif.in.valid_in = 0;

        //-------------------------------------------------
        // TEST 4: valid_out must assert when result ready
        //-------------------------------------------------
        $display("\nTest 4: valid_out assertion");

        wait (vruif.out.valid_out);

        if (!vruif.out.valid_out)
            $error("FAIL: valid_out never asserted");
        else
            $display("PASS: valid_out asserted");

        //-------------------------------------------------
        // TEST 5: valid_out must HOLD during stall
        //-------------------------------------------------
        $display("\nTest 5: valid_out HOLD under stall");

        vruif.in.ready_out = 0;   // Stall output

        repeat (5) begin
            @(posedge CLK);
            if (!vruif.out.valid_out)
                $error("FAIL: valid_out dropped during stall");
        end

        $display("PASS: valid_out held during stall");

        //-------------------------------------------------
        // TEST 6: valid_out drops after handshake
        //-------------------------------------------------
        $display("\nTest 6: valid_out drops after handshake");

        vruif.in.ready_out = 1;   // Release stall

        @(posedge CLK);  // handshake

        @(posedge CLK);

        if (vruif.out.valid_out)
            $error("FAIL: valid_out did not drop after handshake");
        else
            $display("PASS: valid_out dropped correctly");

        //-------------------------------------------------
        // TEST 7: ready_in returns HIGH after completion
        //-------------------------------------------------
        $display("\nTest 7: ready_in returns HIGH");

        @(posedge CLK);

        if (!vruif.out.ready_in)
            $error("FAIL: ready_in did not return HIGH after completion");
        else
            $display("PASS: ready_in returned HIGH");

        //-------------------------------------------------
        // TEST 8: Reset while busy
        //-------------------------------------------------
        $display("\nTest 8: Reset while busy");

        // Start transaction
        vruif.in.valid_in = 1;
        wait (vruif.out.ready_in);
        @(posedge CLK);
        vruif.in.valid_in = 0;

        @(posedge CLK);

        nRST = 0;
        @(posedge CLK);

        if (vruif.out.valid_out || vruif.out.ready_in)
            $error("FAIL: signals not cleared on reset");
        else
            $display("PASS: reset cleared outputs");

        nRST = 1;
        repeat (2) @(posedge CLK);

        $display("\n====================================");
        $display(" HANDSHAKE TESTS COMPLETE");
        $display("====================================\n");

    endtask

endmodule