`timescale 1ns/1ps

`include "reduction_FU_if.vh"
`include "vector_pkg.vh"

module reduction_FU_tb;

    import vector_pkg::*;

    //--------------------------------------------
    // Clock / Reset
    //--------------------------------------------
    logic CLK = 0;
    logic nRST = 0;

    always #5 CLK = ~CLK;

    //--------------------------------------------
    // Interface + DUT
    //--------------------------------------------
    reduction_FU_if ruif();

    reduction_FU dut (
        .CLK(CLK),
        .nRST(nRST),
        .ruif(ruif)
    );

    //--------------------------------------------
    // Dummy lane data
    //--------------------------------------------
    logic [NUM_LANES-1:0][ESZ-1:0] lane_data;

    initial begin
        for (int i = 0; i < NUM_LANES; i++)
            lane_data[i] = 16'h3f80;  // 1.0 in BF16
    end

    //--------------------------------------------
    // Test Sequence
    //--------------------------------------------
    initial begin

        //----------------------------------------
        // Default drive
        //----------------------------------------
        ruif.in.lane_valid = 0;
        ruif.in.wb_ready   = 1;
        
        // Initialize port 0
        ruif.in.ports[0].input_valid = 0;
        ruif.in.ports[0].rm          = 0;
        ruif.in.ports[0].v1          = '0;
        ruif.in.ports[0].v2          = '0;
        ruif.in.ports[0].alu_op      = ALU_ADD;
        ruif.in.ports[0].vd          = 8'd3;
        ruif.in.ports[0].mask        = '0;
        ruif.in.ports[0].usel        = VALU;

        // Initialize port 1
        ruif.in.ports[1].input_valid = 0;
        ruif.in.ports[1].rm          = 0;
        ruif.in.ports[1].v1          = '0;
        ruif.in.ports[1].v2          = '0;
        ruif.in.ports[1].alu_op      = ALU_ADD;
        ruif.in.ports[1].vd          = 8'd3;
        ruif.in.ports[1].mask        = '0;
        ruif.in.ports[1].usel        = VALU;

        ruif.in.lane_input = lane_data;

        //----------------------------------------
        // Reset
        //----------------------------------------
        nRST = 0;
        repeat (4) @(posedge CLK);
        nRST = 1;
        repeat (2) @(posedge CLK);

        $display("\n==================================");
        $display(" reduction_FU TEST START");
        $display("==================================");

        //-------------------------------------------------
        // TEST 1: Issue reduction op (metadata latch)
        //-------------------------------------------------
        $display("\nTest 1: Metadata latching");

        // Setup v1 with test data
        for (int i = 0; i < VLMAX; i++)
            ruif.in.ports[0].v1[i] = 16'h4000;  // 2.0 in BF16

        // Setup v2 with control bits: broadcast=0, clear=1, imm=3
        ruif.in.ports[0].v2 = '0;
        ruif.in.ports[0].v2[6] = 0;  // broadcast
        ruif.in.ports[0].v2[5] = 1;  // clear
        ruif.in.ports[0].v2[4:0] = 5'd3;  // imm

        ruif.in.ports[0].input_valid = 1;
        ruif.in.ports[0].rm          = 1;
        ruif.in.ports[0].alu_op      = ALU_ADD;
        ruif.in.ports[0].vd          = 8'd5;

        wait (ruif.out.input_ready);
        @(posedge CLK);

        ruif.in.ports[0].input_valid = 0;

        @(posedge CLK);

        $display("PASS: Metadata accepted");

        //-------------------------------------------------
        // TEST 2: Should NOT start without lane_valid
        //-------------------------------------------------
        $display("\nTest 2: No start without lane_valid");

        repeat (5) @(posedge CLK);

        if (ruif.out.wb_valid)
            $error("FAIL: Reduction started without lane_valid");
        else
            $display("PASS: No start without lane_valid");

        //-------------------------------------------------
        // TEST 3: Start when lane_valid asserted
        //-------------------------------------------------
        $display("\nTest 3: Start when lane_valid=1");

        ruif.in.lane_valid = 1;
        @(posedge CLK);
        ruif.in.lane_valid = 0;

        wait (ruif.out.wb_valid);

        $display("PASS: wb_valid asserted");
        $display("Result vd_output: %0d", ruif.out.vd_output);
        $display("Result in element 0: %h", ruif.out.vector_output[0]);
        $display("Result in element 3: %h", ruif.out.vector_output[3]);

        //-------------------------------------------------
        // TEST 4: Hold wb_valid if wb_ready=0
        //-------------------------------------------------
        $display("\nTest 4: wb_valid HOLD");

        ruif.in.wb_ready = 0;

        repeat (5) begin
            @(posedge CLK);
            if (!ruif.out.wb_valid)
                $error("FAIL: wb_valid dropped during stall");
        end

        $display("PASS: wb_valid held during stall");

        //-------------------------------------------------
        // TEST 5: Clear after handshake
        //-------------------------------------------------
        $display("\nTest 5: wb_valid clears after handshake");

        ruif.in.wb_ready = 1;
        @(posedge CLK);
        @(posedge CLK);

        if (ruif.out.wb_valid)
            $error("FAIL: wb_valid did not clear");
        else
            $display("PASS: wb_valid cleared");

        //-------------------------------------------------
        // TEST 6: input_ready returns after handshake
        //-------------------------------------------------
        $display("\nTest 6: input_ready returns after handshake");

        if (ruif.out.input_ready)
            $display("PASS: input_ready returned");
        else
            $error("FAIL: input_ready did not return");

        $display("\n==================================");
        $display(" ALL TESTS COMPLETE");
        $display("==================================\n");

        $finish;
    end

endmodule