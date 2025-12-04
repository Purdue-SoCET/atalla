`timescale 1ns/1ps

`include "vector_if.vh"
`include "vector_pkg.vh"

module lane_tb;
    import vector_pkg::*;

    // ------------------------------------------------------------
    // Clock / Reset
    // ------------------------------------------------------------
    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD = 10;

    // Clock generation
    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    // Reset generation
    initial begin
        nRST = 1'b0;
        #(5*CLK_PERIOD);
        nRST = 1'b1;
    end

    // ------------------------------------------------------------
    // Interface + DUT
    // ------------------------------------------------------------

    // Interface has NO ports → plain instantiation
    vector_if lane_if();

    // Drive interface's internal clock/reset from TB signals
    assign lane_if.CLK  = CLK;
    assign lane_if.nRST = nRST;

    // DUT
    lane dut (
        .CLK (CLK),
        .nRST(nRST),
        .lif (lane_if.lane)
    );

    // FU index for SQRT (enum fu_t has SQRT)
    localparam int FU_SQRT = SQRT;

    // ------------------------------------------------------------
    // Scoreboard / helper state (module-scope declarations)
    // ------------------------------------------------------------
    int expected_results;
    int seen_results;

    typedef struct packed {
        vsel_t      vd;
        slice_idx_t elem_idx;
    } obs_t;

    obs_t observed[$];
    obs_t tmp_obs;

    int i;
    int idx_counts[SLICE_W];

    // ------------------------------------------------------------
    // WB always ready (for SQRT only)
    // ------------------------------------------------------------
    initial begin
        // Default everything
        lane_if.lane_in = '0;

        // WB ready for SQRT FU
        forever begin
            @(posedge CLK);
            if (!nRST) begin
                lane_if.lane_in.ready_in <= '0;
            end else begin
                lane_if.lane_in.ready_in <= '0;
                lane_if.lane_in.ready_in[FU_SQRT] <= 1'b1; // WB always ready for SQRT
            end
        end
    end

    // ------------------------------------------------------------
    // Capture outputs whenever SQRT has a valid result
    // ------------------------------------------------------------
    always @(posedge CLK) begin
        if (!nRST) begin
            seen_results <= 0;
            observed.delete();
        end else begin
            if (lane_if.lane_out.valid_o[FU_SQRT]) begin
                seen_results <= seen_results + 1;

                tmp_obs.vd       = lane_if.lane_out.vd[FU_SQRT];
                tmp_obs.elem_idx = lane_if.lane_out.elem_idx[FU_SQRT];
                observed.push_back(tmp_obs);

                $display("[%0t] SQRT result: result=%h vd=%0d elem_idx=%0d",
                         $time,
                         lane_if.lane_out.result[FU_SQRT],
                         tmp_obs.vd, tmp_obs.elem_idx);
            end
        end
    end

    // ------------------------------------------------------------
    // Task: drive one SQRT slice
    // ------------------------------------------------------------
    task automatic drive_sqrt_slice(
        input slice_vt    slice_v1,
        input slice_vt    slice_v2,
        input slice_mt    slice_mask,
        input vsel_t      vd_tag,
        input opcode_t    op
    );
        // Wait until lane is ready for a new SQRT slice
        @(posedge CLK);
        wait (lane_if.lane_out.ready_o[FU_SQRT] && nRST);

        @(posedge CLK);
        lane_if.lane_in.v1[FU_SQRT]       <= slice_v1;
        lane_if.lane_in.v2[FU_SQRT]       <= slice_v2;
        lane_if.lane_in.vmask[FU_SQRT]    <= slice_mask;
        lane_if.lane_in.vd[FU_SQRT]       <= vd_tag;
        lane_if.lane_in.vop[FU_SQRT]      <= op;
        lane_if.lane_in.rm[FU_SQRT]       <= '0;
        lane_if.lane_in.valid_in[FU_SQRT] <= 1'b1;   // present slice
    

        // Only need to assert valid for one cycle; sequencer latches it
        @(posedge CLK);
        lane_if.lane_in.valid_in[FU_SQRT] <= 1'b0;
    endtask

    // ------------------------------------------------------------
    // Test sequences
    // ------------------------------------------------------------
    initial begin : main_test
        string testname;
        slice_vt  v1, v2;
        slice_mt  mask;
        vsel_t    vd;
        opcode_t  op;

        // Wait for reset deassert
        @(posedge nRST);
        @(posedge CLK);

        // -----------------------------
        // TEST 1: All elements unmasked
        // -----------------------------
        $display("\n=== TEST 1: All elements unmasked ===");
        testname = "TEST 1 UNMASKED ELEMENTS";

        // Build a simple slice: v1[i] = i, v2[i] = 0, all active
        for (i = 0; i < SLICE_W; i++) begin
            v1[i]   = fp16_t'(i);
            v2[i]   = '0;
            mask[i] = 1'b1;
        end
        vd = vsel_t'(3);
        op = '0; // adjust if you have a real SQRT opcode

        expected_results = SLICE_W;
        seen_results     = 0;
        observed.delete();

        drive_sqrt_slice(v1, v2, mask, vd, op);

        // Wait long enough: latency + some slack
        repeat (SLICE_W + 20) @(posedge CLK);


        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);
        @(posedge CLK);

        if (seen_results !== expected_results) begin
            $error("TEST 1 FAILED: expected %0d results, saw %0d",
                   expected_results, seen_results);
        end else begin
            $display("TEST 1 PASSED: saw %0d results as expected.", seen_results);
        end

        // -----------------------------
        // TEST 2: Masked elements
        // -----------------------------
        $display("\n=== TEST 2: Masked elements ===");
        testname = "TEST 2 MASKED ELEMENTS";

        // v1[i] = i+10, mask = 0,1,0,1,... (active on odd indices)
        for (i = 0; i < SLICE_W; i++) begin
            v1[i]   = fp16_t'(i+10);
            v2[i]   = '0;
            mask[i] = (i % 2);  // active on odd indices
        end
        vd = vsel_t'(5);
        op = '0;

        expected_results = 0;
        for (i = 0; i < SLICE_W; i++) begin
            if (mask[i]) expected_results++;
        end

        seen_results = 0;
        observed.delete();

        drive_sqrt_slice(v1, v2, mask, vd, op);

        repeat (SLICE_W + 20) @(posedge CLK);

        if (seen_results !== expected_results) begin
            $error("TEST 2 FAILED: expected %0d results, saw %0d",
                   expected_results, seen_results);
        end else begin
            $display("TEST 2 PASSED: saw %0d results as expected.", seen_results);
        end

        // (Optional) simple sanity on indices: just print queue content
        $display("\nObserved elem_idx for TEST 2:");
        for (i = 0; i < observed.size(); i++) begin
            $display("  result %0d: vd=%0d elem_idx=%0d",
                     i, observed[i].vd, observed[i].elem_idx);
        end

        $display("\nAll tests done.");
        #100;
        $finish;
    end

endmodule
