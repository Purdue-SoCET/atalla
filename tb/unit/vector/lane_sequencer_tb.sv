`timescale 1ns/1ps

`include "lane_sequencer_if.vh"
`include "vector_pkg.vh"

/*
lane_sequencer_tb.sv
Owner: Vedant Sharma 
Test Cases:
1. Power on reset
2. Basic sequencing (no stalling, FU ready, valid data)
3. B2B test (back-to-back slices)
4. Invalid data (valid_in = 0)
5. FU not ready during sequencing
6. Empty sequencer accepts slice when FU not ready
*/

module lane_sequencer_tb();

    import vector_pkg::*;

    // Clock setup
    logic CLK;
    logic nRST;
    string test_name;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK; // 100 MHz

    // DUT instantiation
    lane_sequencer_if seq_if();
    lane_sequencer DUT (
        .CLK(CLK),
        .nRST(nRST),
        .seq_if(seq_if)
    );

    task automatic power_on_reset();
        @(posedge CLK);
        nRST = 1'b0;
        seq_if.in.v1 = '0;
        seq_if.in.v2 = '0;
        seq_if.in.mask = '0;
        seq_if.in.valid_in = 1'b0;
        seq_if.in.ready_out = 1'b0;
        @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    task automatic basic_sequencing();
        logic [SLICE_W-1:0][ESZ-1:0] test_v1;
        logic [SLICE_W-1:0][ESZ-1:0] test_v2;
        logic [SLICE_W-1:0] test_mask;
        int i;

        // Create test data
        for (i = 0; i < SLICE_W; i++) begin
            test_v1[i] = 32'hAAAA_0000 + i;
            test_v2[i] = 32'hBBBB_0000 + i;
            test_mask[i] = i[0];
        end

        // FU is ready
        seq_if.in.ready_out = 1'b1;
        @(posedge CLK);

        // Send slice
        seq_if.in.v1 = test_v1;
        seq_if.in.v2 = test_v2;
        seq_if.in.mask = test_mask;
        seq_if.in.valid_in = 1'b1;
        @(posedge CLK);
        seq_if.in.valid_in = 1'b0;

        // Wait for all elements to be sequenced
        for (i = 0; i < SLICE_W; i++) begin
            @(posedge CLK);
        end
    endtask

    task automatic b2b_saas_ahh_test();
        logic [SLICE_W-1:0][ESZ-1:0] test_v1;
        logic [SLICE_W-1:0][ESZ-1:0] test_v2;
        logic [SLICE_W-1:0] test_mask;
        int slice, i;

        seq_if.in.ready_out = 1'b1;

        for (slice = 0; slice < 4; slice++) begin
            // Generate data for each slice
            for (i = 0; i < SLICE_W; i++) begin
                test_v1[i] = (slice << 24) | (32'hCAFE_0000 + i);
                test_v2[i] = (slice << 24) | (32'hDEAD_0000 + i);
                test_mask[i] = (slice + i) % 2;
            end

            // Wait for ready
            while (!seq_if.out.ready_in) @(posedge CLK);

            // Send slice
            seq_if.in.v1 = test_v1;
            seq_if.in.v2 = test_v2;
            seq_if.in.mask = test_mask;
            seq_if.in.valid_in = 1'b1;
            @(posedge CLK);
            seq_if.in.valid_in = 1'b0;

            // Wait for sequencing to done
            for (i = 0; i < SLICE_W; i++) begin
                @(posedge CLK);
            end
        end
    endtask

    task automatic invalid_data_test();
        logic [SLICE_W-1:0][ESZ-1:0] test_v1;
        logic [SLICE_W-1:0][ESZ-1:0] test_v2;
        logic [SLICE_W-1:0] test_mask;
        int i;

        for (i = 0; i < SLICE_W; i++) begin
            test_v1[i] = 32'hBAD_DATA0 + i;
            test_v2[i] = 32'hBAD_DATA1 + i;
            test_mask[i] = 1'b1;
        end

        seq_if.in.ready_out = 1'b1;
        @(posedge CLK);

        // Put data on inputs but DON'T assert valid
        seq_if.in.v1 = test_v1;
        seq_if.in.v2 = test_v2;
        seq_if.in.mask = test_mask;
        seq_if.in.valid_in = 1'b0; // NOT valid

        // Wait sequencer should not accept data
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        // ready_in should still be 1, valid_out should still be 0
    endtask

    task automatic fu_not_ready_test();
        logic [SLICE_W-1:0][ESZ-1:0] test_v1;
        logic [SLICE_W-1:0][ESZ-1:0] test_v2;
        logic [SLICE_W-1:0] test_mask;
        int i;

        for (i = 0; i < SLICE_W; i++) begin
            test_v1[i] = 32'hFEED_0000 + i;
            test_v2[i] = 32'hBEEF_0000 + i;
            test_mask[i] = 1'b1;
        end

        // FU starts ready
        seq_if.in.ready_out = 1'b1;
        @(posedge CLK);

        // Send slice
        seq_if.in.v1 = test_v1;
        seq_if.in.v2 = test_v2;
        seq_if.in.mask = test_mask;
        seq_if.in.valid_in = 1'b1;
        @(posedge CLK);
        seq_if.in.valid_in = 1'b0;

        // FU becomes not ready
        seq_if.in.ready_out = 1'b0;

        // Hold output should stay stable
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        // FU becomes ready again
        seq_if.in.ready_out = 1'b1;

        for (i = 0; i < SLICE_W; i++) begin
            @(posedge CLK);
        end
    endtask

    // credit to Jacob for helping w this test case, def wouldve not realized this one
    task automatic empty_sequencer_fu_not_ready_test();
        logic [SLICE_W-1:0][ESZ-1:0] test_v1;
        logic [SLICE_W-1:0][ESZ-1:0] test_v2;
        logic [SLICE_W-1:0] test_mask;
        int i;

        for (i = 0; i < SLICE_W; i++) begin
            test_v1[i] = 32'h1234_0000 + i;
            test_v2[i] = 32'h5678_0000 + i;
            test_mask[i] = 1'b0;
        end

        // FU is NOT ready, but sequencer is empty
        seq_if.in.ready_out = 1'b0;
        @(posedge CLK);

        // Sequencer should still accept slice (it's empty)
        // ready_in should be 1

        // Send slice while FU not ready
        seq_if.in.v1 = test_v1;
        seq_if.in.v2 = test_v2;
        seq_if.in.mask = test_mask;
        seq_if.in.valid_in = 1'b1;
        @(posedge CLK);
        seq_if.in.valid_in = 1'b0;

        // Sequencer now has data, valid_out should be 1
        // Output should hold steady since FU not ready
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        // FU becomes ready
        seq_if.in.ready_out = 1'b1;

        for (i = 0; i < SLICE_W; i++) begin
            @(posedge CLK);
        end
    endtask

    initial begin
        nRST = 1'b1;

        test_name = "Power on reset";
        power_on_reset();
        @(posedge CLK);

        test_name = "Basic sequencing";
        basic_sequencing();
        @(posedge CLK);
        @(posedge CLK);

        power_on_reset();
        @(posedge CLK);

        test_name = "B2B SaaS ahh test";
        b2b_saas_ahh_test();
        @(posedge CLK);
        @(posedge CLK);

        power_on_reset();
        @(posedge CLK);

        test_name = "Invalid data test";
        invalid_data_test();
        @(posedge CLK);
        @(posedge CLK);

        power_on_reset();
        @(posedge CLK);

        test_name = "FU not ready during sequencing";
        fu_not_ready_test();
        @(posedge CLK);
        @(posedge CLK);

        power_on_reset();
        @(posedge CLK);

        test_name = "Empty sequencer FU not ready";
        empty_sequencer_fu_not_ready_test();
        @(posedge CLK);
        @(posedge CLK);

        $stop;
    end

endmodule