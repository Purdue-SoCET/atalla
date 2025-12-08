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

    localparam int CLK_PERIOD      = 10;
    localparam int FU_SQRT         = SQRT;
    localparam int FU_DIV          = DIV;
    localparam int FU_MUL          = MUL;

    // generous limits because SQRT IP is very deep
    localparam int DIR_MAX_CYCLES  = 200_000;
    localparam int RAND_MAX_CYCLES = 200_000;

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
    vector_if lane_if();         // no ports, just instantiate

    assign lane_if.CLK  = CLK;
    assign lane_if.nRST = nRST;

    lane dut (
        .CLK (CLK),
        .nRST(nRST),
        .lif (lane_if.lane)
    );

    // ------------------------------------------------------------
    // Scoreboard state
    // ------------------------------------------------------------
    typedef struct packed {
        vsel_t      vd;
        slice_idx_t elem_idx;
    } obs_t;

    // Expected queue for random tests (3, 4, 7)
    obs_t exp_q[$];

    int total_errors = 0;

    // Directed-test monitor state
    int   dir_seen_results;
    int   dir_seen_results_div;
    obs_t dir_observed[$];
    obs_t dir_observed_div[$];
    bit   dir_monitor_en;
    bit   dir_monitor_en_div;

    // Driver-done flags for random tests
    bit   driver_done_sqrt;
    bit   driver_done_div;
    bit   driver_done_mul;

    // Current test name for printing
    string cur_test;

    // ------------------------------------------------------------
    // WB control: default ready on SQRT, DIV, and MUL after reset
    // ------------------------------------------------------------
    initial begin
        lane_if.lane_in = '0;
        lane_if.lane_in.ready_in = '0;

        // wait for reset deassertion
        @(posedge nRST);
        @(posedge CLK);

        // default: SQRT, DIV, and MUL WB always ready
        lane_if.lane_in.ready_in[FU_SQRT] = 1'b1;
        lane_if.lane_in.ready_in[FU_DIV]  = 1'b1;
        lane_if.lane_in.ready_in[FU_MUL]  = 1'b1;
    end

    // ------------------------------------------------------------
    // Monitor for directed tests (1 & 2) - SQRT
    // ------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        obs_t tmp_obs;

        if (!nRST || !dir_monitor_en) begin
            dir_seen_results <= 0;
            dir_observed.delete();
        end else begin
            if (lane_if.lane_out.valid_o[FU_SQRT]) begin
                dir_seen_results <= dir_seen_results + 1;

                tmp_obs.vd       = lane_if.lane_out.vd[FU_SQRT];
                tmp_obs.elem_idx = lane_if.lane_out.elem_idx[FU_SQRT];
                dir_observed.push_back(tmp_obs);

                $display("[%0t] %s: SQRT result result=%h vd=%0d elem_idx=%0d",
                         $time, cur_test,
                         lane_if.lane_out.result[FU_SQRT],
                         tmp_obs.vd, tmp_obs.elem_idx);
            end
        end
    end

    // ------------------------------------------------------------
    // Monitor for directed tests - DIV
    // ------------------------------------------------------------
    always_ff @(posedge CLK or negedge nRST) begin
        obs_t tmp_obs;

        if (!nRST || !dir_monitor_en_div) begin
            dir_seen_results_div <= 0;
            dir_observed_div.delete();
        end else begin
            if (lane_if.lane_out.valid_o[FU_DIV]) begin
                dir_seen_results_div <= dir_seen_results_div + 1;

                tmp_obs.vd       = lane_if.lane_out.vd[FU_DIV];
                tmp_obs.elem_idx = lane_if.lane_out.elem_idx[FU_DIV];
                dir_observed_div.push_back(tmp_obs);

                $display("[%0t] %s: DIV result result=%h vd=%0d elem_idx=%0d",
                         $time, cur_test,
                         lane_if.lane_out.result[FU_DIV],
                         tmp_obs.vd, tmp_obs.elem_idx);
            end
        end
    end

    // ------------------------------------------------------------
    // Helper: drive one SQRT slice
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
        lane_if.lane_in.valid_in[FU_SQRT] <= 1'b1;

        // Only need to assert valid for one cycle; sequencer latches it
        @(posedge CLK);
        lane_if.lane_in.valid_in[FU_SQRT] <= 1'b0;
    endtask

    // ------------------------------------------------------------
    // Helper: drive one DIV slice
    // ------------------------------------------------------------
    task automatic drive_div_slice(
        input slice_vt    slice_v1,
        input slice_vt    slice_v2,
        input slice_mt    slice_mask,
        input vsel_t      vd_tag,
        input opcode_t    op
    );
        int wait_cycles;
        // Wait until lane is ready for a new DIV slice
        wait_cycles = 0;
        @(posedge CLK);
        while (!lane_if.lane_out.ready_o[FU_DIV] && nRST && wait_cycles < 1000) begin
            @(posedge CLK);
            wait_cycles++;
        end

        if (wait_cycles >= 1000) begin
            $error("drive_div_slice: DIV lane never became ready!");
        end

        @(posedge CLK);
        lane_if.lane_in.v1[FU_DIV]       <= slice_v1;
        lane_if.lane_in.v2[FU_DIV]       <= slice_v2;
        lane_if.lane_in.vmask[FU_DIV]    <= slice_mask;
        lane_if.lane_in.vd[FU_DIV]       <= vd_tag;
        lane_if.lane_in.vop[FU_DIV]      <= op;
        lane_if.lane_in.rm[FU_DIV]       <= '0;
        lane_if.lane_in.valid_in[FU_DIV] <= 1'b1;

        // Only need to assert valid for one cycle; sequencer latches it
        @(posedge CLK);
        lane_if.lane_in.valid_in[FU_DIV] <= 1'b0;
    endtask

    // ------------------------------------------------------------
    // Helper: drive one MUL slice
    // ------------------------------------------------------------
    task automatic drive_mul_slice(
        input slice_vt    slice_v1,
        input slice_vt    slice_v2,
        input slice_mt    slice_mask,
        input vsel_t      vd_tag,
        input opcode_t    op
    );
        int wait_cycles;
        // Wait until lane is ready for a new MUL slice
        wait_cycles = 0;
        @(posedge CLK);
        while (!lane_if.lane_out.ready_o[FU_MUL] && nRST && wait_cycles < 1000) begin
            @(posedge CLK);
            wait_cycles++;
        end

        if (wait_cycles >= 1000) begin
            $error("drive_mul_slice: MUL lane never became ready!");
        end

        @(posedge CLK);
        lane_if.lane_in.v1[FU_MUL]       <= slice_v1;
        lane_if.lane_in.v2[FU_MUL]       <= slice_v2;
        lane_if.lane_in.vmask[FU_MUL]    <= slice_mask;
        lane_if.lane_in.vd[FU_MUL]       <= vd_tag;
        lane_if.lane_in.vop[FU_MUL]      <= op;
        lane_if.lane_in.rm[FU_MUL]       <= '0;
        lane_if.lane_in.valid_in[FU_MUL] <= 1'b1;

        // Only need to assert valid for one cycle; sequencer latches it
        @(posedge CLK);
        lane_if.lane_in.valid_in[FU_MUL] <= 1'b0;
    endtask

    // ------------------------------------------------------------
    // Directed Tests 1 & 2 (SQRT)
    // ------------------------------------------------------------
    task automatic run_directed_tests;
        int i;
        slice_vt  v1, v2;
        slice_mt  mask;
        vsel_t    vd;
        opcode_t  op;

        int expected_results;
        int cycles;

        // Enable directed monitor
        dir_monitor_en = 1'b1;

        // Wait for reset deassert
        @(posedge nRST);
        @(posedge CLK);

        // -----------------------------
        // TEST 1: All elements unmasked
        // -----------------------------
        cur_test = "TEST 1";
        $display("\n=== %s: All elements unmasked ===", cur_test);

        for (i = 0; i < SLICE_W; i++) begin
            v1[i]   = fp16_t'(i);
            v2[i]   = '0;
            mask[i] = 1'b1;
        end
        vd = vsel_t'(3);
        op = '0;

        expected_results = SLICE_W;
        dir_seen_results = 0;
        dir_observed.delete();
        cycles = 0;

        drive_sqrt_slice(v1, v2, mask, vd, op);

        // Wait until all expected results seen or timeout
        while ((dir_seen_results < expected_results) &&
               (cycles < DIR_MAX_CYCLES)) begin
            @(posedge CLK);
            cycles++;
        end

        if (dir_seen_results !== expected_results) begin
            $error("%s FAILED: expected %0d results, saw %0d (cycles=%0d)",
                   cur_test, expected_results, dir_seen_results, cycles);
            total_errors++;
        end else begin
            $display("%s PASSED (results=%0d, cycles=%0d)",
                     cur_test, dir_seen_results, cycles);
        end

        // -----------------------------
        // TEST 2: Masked elements
        // -----------------------------
        cur_test = "TEST 2";
        $display("\n=== %s: Masked elements ===", cur_test);

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

        dir_seen_results = 0;
        dir_observed.delete();
        cycles = 0;

        drive_sqrt_slice(v1, v2, mask, vd, op);

        while ((dir_seen_results < expected_results) &&
               (cycles < DIR_MAX_CYCLES)) begin
            @(posedge CLK);
            cycles++;
        end

        if (dir_seen_results !== expected_results) begin
            $error("%s FAILED: expected %0d results, saw %0d (cycles=%0d)",
                   cur_test, expected_results, dir_seen_results, cycles);
            total_errors++;
        end else begin
            $display("%s PASSED (results=%0d, cycles=%0d)",
                     cur_test, dir_seen_results, cycles);
        end

        $display("\n(SQRT Directed tests) All observed results have correct vd/idx and no drops.\n");

        // Disable directed monitor so random tests own the scoreboard
        dir_monitor_en = 1'b0;
    endtask

    // ------------------------------------------------------------
    // Directed Tests for DIV (1 & 2)
    // ------------------------------------------------------------
    task automatic run_directed_tests_div;
        int i;
        slice_vt  v1, v2;
        slice_mt  mask;
        vsel_t    vd;
        opcode_t  op;

        int expected_results;
        int cycles;

        // Enable directed monitor for DIV
        dir_monitor_en_div = 1'b1;

        // Give DIV lane time to initialize (nRST already high from SQRT tests)
        repeat (10) @(posedge CLK);

        $display("\n=== Starting DIV Tests ===");
        $display("DIV ready_o = %b", lane_if.lane_out.ready_o[FU_DIV]);

        // -----------------------------
        // TEST 1_DIV: All elements unmasked
        // -----------------------------
        cur_test = "TEST 1_DIV";
        $display("\n=== %s: All elements unmasked ===", cur_test);

        for (i = 0; i < SLICE_W; i++) begin
            v1[i]   = fp16_t'(i + 10);
            v2[i]   = fp16_t'(i + 1);  // non-zero divisor
            mask[i] = 1'b1;
        end
        vd = vsel_t'(17);
        op = '0;

        expected_results = SLICE_W;
        dir_seen_results_div = 0;
        dir_observed_div.delete();
        cycles = 0;

        drive_div_slice(v1, v2, mask, vd, op);

        // Wait until all expected results seen or timeout
        while ((dir_seen_results_div < expected_results) &&
               (cycles < DIR_MAX_CYCLES)) begin
            @(posedge CLK);
            cycles++;
        end

        if (dir_seen_results_div !== expected_results) begin
            $error("%s FAILED: expected %0d results, saw %0d (cycles=%0d)",
                   cur_test, expected_results, dir_seen_results_div, cycles);
            total_errors++;
        end else begin
            $display("%s PASSED (results=%0d, cycles=%0d)",
                     cur_test, dir_seen_results_div, cycles);
        end

        // -----------------------------
        // TEST 2_DIV: Masked elements
        // -----------------------------
        cur_test = "TEST 2_DIV";
        $display("\n=== %s: Masked elements ===", cur_test);

        for (i = 0; i < SLICE_W; i++) begin
            v1[i]   = fp16_t'(i + 20);
            v2[i]   = fp16_t'(i + 1);  // non-zero divisor
            mask[i] = (i % 2);  // active on odd indices
        end
        vd = vsel_t'(19);
        op = '0;

        expected_results = 0;
        for (i = 0; i < SLICE_W; i++) begin
            if (mask[i]) expected_results++;
        end

        dir_seen_results_div = 0;
        dir_observed_div.delete();
        cycles = 0;

        drive_div_slice(v1, v2, mask, vd, op);

        while ((dir_seen_results_div < expected_results) &&
               (cycles < DIR_MAX_CYCLES)) begin
            @(posedge CLK);
            cycles++;
        end

        if (dir_seen_results_div !== expected_results) begin
            $error("%s FAILED: expected %0d results, saw %0d (cycles=%0d)",
                   cur_test, expected_results, dir_seen_results_div, cycles);
            total_errors++;
        end else begin
            $display("%s PASSED (results=%0d, cycles=%0d)",
                     cur_test, dir_seen_results_div, cycles);
        end

        $display("\n(DIV Directed tests) All observed results have correct vd/idx and no drops.\n");

        // Disable directed monitor
        dir_monitor_en_div = 1'b0;
    endtask

    // ------------------------------------------------------------
    // All-zero-mask driver (for TEST 5) - SQRT
    // ------------------------------------------------------------
    task automatic zero_mask_driver(
        input  int    num_slices,
        input  vsel_t base_vd
    );
        int s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;

        for (s = 0; s < num_slices; s++) begin
            // Arbitrary data, but mask all zeros
            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'($urandom_range(1000, 0));
                v2[i]   = '0;
                mask[i] = 1'b0;
            end
            op = '0;

            // NOTE: no expected entries pushed into exp_q on purpose
            drive_sqrt_slice(v1, v2, mask, base_vd, op);
        end
    endtask

    // ------------------------------------------------------------
    // All-zero-mask driver (for TEST 5) - DIV
    // ------------------------------------------------------------
    task automatic zero_mask_driver_div(
        input  int    num_slices,
        input  vsel_t base_vd
    );
        int s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;

        for (s = 0; s < num_slices; s++) begin
            // Arbitrary data, but mask all zeros
            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'($urandom_range(1000, 0));
                v2[i]   = fp16_t'($urandom_range(1000, 1));  // non-zero divisor
                mask[i] = 1'b0;
            end
            op = '0;

            // NOTE: no expected entries pushed into exp_q on purpose
            drive_div_slice(v1, v2, mask, base_vd, op);
        end
    endtask

    // ------------------------------------------------------------
    // Random driver for tests 3, 4, 7 - SQRT
    // ------------------------------------------------------------
    task automatic random_driver(
        input int num_slices,
        input int back_to_back_prob,  // 0..100
        input vsel_t base_vd,
        output int   total_expected
    );
        int s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;
        obs_t    item;

        total_expected = 0;
        // NEW: mark that the SQRT driver is active
        driver_done_sqrt = 1'b0;

        for (s = 0; s < num_slices; s++) begin
            // Random data
            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'($urandom_range(1000, 0));
                v2[i]   = '0;
                mask[i] = $urandom_range(1,0);
            end
            op = '0;

            // Enqueue expected for unmasked elements
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = base_vd;
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    total_expected++;
                end
            end

            if ((base_vd == 7 || base_vd == 9) && mask != 0) begin
                $display("[%0t] TB ACTIVE SLICE s=%0d vd=%0d MASK=%b",
                         $time, s, base_vd, mask);
            end

            drive_sqrt_slice(v1, v2, mask, base_vd, op);

            // Upstream starvation (gaps between slices)
            if ($urandom_range(99,0) > back_to_back_prob) begin
                repeat ($urandom_range(4,1)) @(posedge CLK);
            end
        end

        // NEW: signal that no more SQRT slices will be issued
        driver_done_sqrt = 1'b1;
    endtask

    // ------------------------------------------------------------
    // Random driver for tests 3, 4, 7 - DIV
    // ------------------------------------------------------------
    task automatic random_driver_div(
        input int num_slices,
        input int back_to_back_prob,  // 0..100
        input vsel_t base_vd,
        output int   total_expected
    );
        int s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;
        obs_t    item;

        total_expected  = 0;
        driver_done_div = 1'b0;   // NEW: mark driver as not done yet

        for (s = 0; s < num_slices; s++) begin
            // Random data
            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'($urandom_range(1000, 0));
                v2[i]   = fp16_t'($urandom_range(1000, 1));  // non-zero divisor
                mask[i] = $urandom_range(1,0);
            end
            op = '0;

            // Enqueue expected for unmasked elements
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = base_vd;
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    total_expected++;
                end
            end

            if ((base_vd == 17 || base_vd == 19) && mask != 0) begin
                $display("[%0t] TB ACTIVE SLICE s=%0d vd=%0d MASK=%b",
                         $time, s, base_vd, mask);
            end

            drive_div_slice(v1, v2, mask, base_vd, op);

            // Upstream starvation (gaps between slices)
            if ($urandom_range(99,0) > back_to_back_prob) begin
                repeat ($urandom_range(4,1)) @(posedge CLK);
            end
        end

        driver_done_div = 1'b1;   // NEW: mark driver as finished
    endtask

    // ------------------------------------------------------------
    // Monitor for tests 3, 4, 7 with bounded runtime - SQRT
    // ------------------------------------------------------------
    task automatic random_monitor(
        input int           max_cycles,
        output int          seen,
        output int          errors,
        input  int          stall_prob, // 0..100, probability to stall WB
        input  string       label
    );
        int cycles;
        obs_t exp;

        seen   = 0;
        errors = 0;
        cycles = 0;

        while (cycles < max_cycles) begin
            // Random WB backpressure on SQRT (only in tests that request it)
            if (stall_prob > 0) begin
                if ($urandom_range(99,0) < stall_prob)
                    lane_if.lane_in.ready_in[FU_SQRT] <= 1'b0;
                else
                    lane_if.lane_in.ready_in[FU_SQRT] <= 1'b1;
            end

            @(posedge CLK);
            cycles++;

            if (lane_if.lane_out.valid_o[FU_SQRT] &&
                lane_if.lane_in.ready_in[FU_SQRT]) begin

                if (exp_q.size() == 0) begin
                    $error("[%s] Unexpected result: queue empty", label);
                    errors++;
                end else begin
                    exp = exp_q.pop_front();

                    if (lane_if.lane_out.vd[FU_SQRT] !== exp.vd) begin
                        $error("[%s] VD mismatch: exp=%0d got=%0d (elem_idx=%0d)",
                               label, exp.vd, lane_if.lane_out.vd[FU_SQRT],
                               lane_if.lane_out.elem_idx[FU_SQRT]);
                        errors++;
                    end

                    if (lane_if.lane_out.elem_idx[FU_SQRT] !== exp.elem_idx) begin
                        $error("[%s] IDX mismatch: exp=%0d got=%0d (vd=%0d)",
                               label, exp.elem_idx,
                               lane_if.lane_out.elem_idx[FU_SQRT],
                               lane_if.lane_out.vd[FU_SQRT]);
                        errors++;
                    end

                    $display("[%0t] %s: SQRT result result=%h vd=%0d elem_idx=%0d",
                             $time, label,
                             lane_if.lane_out.result[FU_SQRT],
                             lane_if.lane_out.vd[FU_SQRT],
                             lane_if.lane_out.elem_idx[FU_SQRT]);

                    seen++;
                end
            end

            // Stop early only if:
            //  - scoreboard is drained
            //  - WB not stalled
            //  - driver is done issuing all SQRT slices
            if (exp_q.size() == 0 &&
                lane_if.lane_in.ready_in[FU_SQRT] &&
                driver_done_sqrt) begin
                break;
            end
        end

        if (cycles >= max_cycles && exp_q.size() != 0) begin
            $error("[%s] TIMEOUT: scoreboard not drained after %0d cycles (remaining=%0d)",
                   label, max_cycles, exp_q.size());
            errors++;
        end
    endtask

    // ------------------------------------------------------------
    // Random driver for tests 3, 4, 7 - MUL
    // ------------------------------------------------------------
    task automatic random_driver_mul(
        input int num_slices,
        input int back_to_back_prob,  // 0..100
        input vsel_t base_vd,
        output int   total_expected
    );
        int s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;
        obs_t    item;

        total_expected  = 0;
        driver_done_mul = 1'b0;   // Mark driver as not done yet

        for (s = 0; s < num_slices; s++) begin
            // Random data
            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'($urandom_range(1000, 0));
                v2[i]   = fp16_t'($urandom_range(1000, 0));
                mask[i] = $urandom_range(1,0);
            end
            op = '0;

            // Enqueue expected for unmasked elements
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = base_vd;
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    total_expected++;
                end
            end

            if ((base_vd == 31 || base_vd == 33) && mask != 0) begin
                $display("[%0t] TB ACTIVE SLICE s=%0d vd=%0d MASK=%b",
                         $time, s, base_vd, mask);
            end

            drive_mul_slice(v1, v2, mask, base_vd, op);

            // Upstream starvation (gaps between slices)
            if ($urandom_range(99,0) > back_to_back_prob) begin
                repeat ($urandom_range(4,1)) @(posedge CLK);
            end
        end

        driver_done_mul = 1'b1;   // Mark driver as finished
    endtask

    // ------------------------------------------------------------
    // Monitor for tests 3, 4, 7 with bounded runtime - DIV
    // ------------------------------------------------------------
    // NOTE: max_cycles semantics:
    //   - Total cycle budget from monitor start
    //   - Increments each @(posedge CLK)
    //   - Exits early if exp_q drains (all results seen) AND driver_done_div is 1
    //   - TIMEOUT if cycles >= max_cycles with remaining > 0
    //   - For DIV: need longer timeout than SQRT due to 11-cycle latency (vs 8)
    task automatic random_monitor_div(
        input int           max_cycles,
        output int          seen,
        output int          errors,
        input  int          stall_prob, // 0..100, probability to stall WB
        input  string       label
    );
        int cycles;
        obs_t exp;

        seen   = 0;
        errors = 0;
        cycles = 0;

`ifdef TB_DEBUG_DIV_MON
        $display("[%0t] [DIV_MON] %s: Starting monitor, max_cycles=%0d, stall_prob=%0d%%",
                 $time, label, max_cycles, stall_prob);
`endif

        while (cycles < max_cycles) begin
            // Random WB backpressure on DIV (only in tests that request it)
            if (stall_prob > 0) begin
                if ($urandom_range(99,0) < stall_prob)
                    lane_if.lane_in.ready_in[FU_DIV] <= 1'b0;
                else
                    lane_if.lane_in.ready_in[FU_DIV] <= 1'b1;
            end

            @(posedge CLK);
            cycles++;

            if (lane_if.lane_out.valid_o[FU_DIV] &&
                lane_if.lane_in.ready_in[FU_DIV]) begin

                if (exp_q.size() == 0) begin
                    $error("[%s] Unexpected result: queue empty", label);
                    errors++;
                end else begin
                    exp = exp_q.pop_front();

                    if (lane_if.lane_out.vd[FU_DIV] !== exp.vd) begin
                        $error("[%s] VD mismatch: exp=%0d got=%0d (elem_idx=%0d)",
                               label, exp.vd, lane_if.lane_out.vd[FU_DIV],
                               lane_if.lane_out.elem_idx[FU_DIV]);
                        errors++;
                    end

                    if (lane_if.lane_out.elem_idx[FU_DIV] !== exp.elem_idx) begin
                        $error("[%s] IDX mismatch: exp=%0d got=%0d (vd=%0d)",
                               label, exp.elem_idx,
                               lane_if.lane_out.elem_idx[FU_DIV],
                               lane_if.lane_out.vd[FU_DIV]);
                        errors++;
                    end

                    $display("[%0t] %s: DIV result result=%h vd=%0d elem_idx=%0d",
                             $time, label,
                             lane_if.lane_out.result[FU_DIV],
                             lane_if.lane_out.vd[FU_DIV],
                             lane_if.lane_out.elem_idx[FU_DIV]);

`ifdef TB_DEBUG_DIV_MON
                    $display("[%0t] [DIV_MON] RESULT #%0d: vd=%0d elem_idx=%0d (remaining=%0d, cycles=%0d)",
                             $time, seen+1, lane_if.lane_out.vd[FU_DIV],
                             lane_if.lane_out.elem_idx[FU_DIV], exp_q.size(), cycles);
`endif

                    seen++;
                end
            end

            // Stop early only if:
            //  - scoreboard is drained
            //  - WB not stalled
            //  - driver is done issuing all slices
            if (exp_q.size() == 0 &&
                lane_if.lane_in.ready_in[FU_DIV] &&
                driver_done_div) begin
`ifdef TB_DEBUG_DIV_MON
                $display("[%0t] [DIV_MON] EARLY EXIT: All results seen, cycles=%0d/%0d (driver_done_div=1)",
                         $time, cycles, max_cycles);
`endif
                break;
            end
        end

`ifdef TB_DEBUG_DIV_MON
        $display("[%0t] [DIV_MON] %s: Monitor done, cycles=%0d, seen=%0d, remaining=%0d (driver_done_div=%0d)",
                 $time, label, cycles, seen, exp_q.size(), driver_done_div);
`endif

        if (cycles >= max_cycles && exp_q.size() != 0) begin
`ifdef TB_DEBUG_DIV_MON
            $display("[%0t] [DIV_MON] TIMEOUT: max_cycles=%0d reached, remaining=%0d, seen=%0d",
                     $time, max_cycles, exp_q.size(), seen);
`endif
            $error("[%s] TIMEOUT: scoreboard not drained after %0d cycles (remaining=%0d)",
                   label, max_cycles, exp_q.size());
            errors++;
        end
    endtask

    // ------------------------------------------------------------
    // Monitor for tests 3, 4, 7 with bounded runtime - MUL
    // ------------------------------------------------------------
    task automatic random_monitor_mul(
        input int           max_cycles,
        output int          seen,
        output int          errors,
        input  int          stall_prob, // 0..100, probability to stall WB
        input  string       label
    );
        int cycles;
        obs_t exp;

        seen   = 0;
        errors = 0;
        cycles = 0;

`ifdef TB_DEBUG_MUL_MON
        $display("[%0t] [MUL_MON] %s: Starting monitor, max_cycles=%0d, stall_prob=%0d%%",
                 $time, label, max_cycles, stall_prob);
`endif

        while (cycles < max_cycles) begin
            // Random WB backpressure on MUL (only in tests that request it)
            if (stall_prob > 0) begin
                if ($urandom_range(99,0) < stall_prob)
                    lane_if.lane_in.ready_in[FU_MUL] <= 1'b0;
                else
                    lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;
            end

            @(posedge CLK);
            cycles++;

            if (lane_if.lane_out.valid_o[FU_MUL] &&
                lane_if.lane_in.ready_in[FU_MUL]) begin

                if (exp_q.size() == 0) begin
                    $error("[%s] Unexpected result: queue empty", label);
                    errors++;
                end else begin
                    exp = exp_q.pop_front();

                    if (lane_if.lane_out.vd[FU_MUL] !== exp.vd) begin
                        $error("[%s] VD mismatch: exp=%0d got=%0d (elem_idx=%0d)",
                               label, exp.vd, lane_if.lane_out.vd[FU_MUL],
                               lane_if.lane_out.elem_idx[FU_MUL]);
                        errors++;
                    end

                    if (lane_if.lane_out.elem_idx[FU_MUL] !== exp.elem_idx) begin
                        $error("[%s] IDX mismatch: exp=%0d got=%0d (vd=%0d)",
                               label, exp.elem_idx,
                               lane_if.lane_out.elem_idx[FU_MUL],
                               lane_if.lane_out.vd[FU_MUL]);
                        errors++;
                    end

                    $display("[%0t] %s: MUL result result=%h vd=%0d elem_idx=%0d",
                             $time, label,
                             lane_if.lane_out.result[FU_MUL],
                             lane_if.lane_out.vd[FU_MUL],
                             lane_if.lane_out.elem_idx[FU_MUL]);

`ifdef TB_DEBUG_MUL_MON
                    $display("[%0t] [MUL_MON] RESULT #%0d: vd=%0d elem_idx=%0d (remaining=%0d, cycles=%0d)",
                             $time, seen+1, lane_if.lane_out.vd[FU_MUL],
                             lane_if.lane_out.elem_idx[FU_MUL], exp_q.size(), cycles);
`endif

                    seen++;
                end
            end

            // Stop early only if:
            //  - scoreboard is drained
            //  - WB not stalled
            //  - driver is done issuing all slices
            if (exp_q.size() == 0 &&
                lane_if.lane_in.ready_in[FU_MUL] &&
                driver_done_mul) begin
`ifdef TB_DEBUG_MUL_MON
                $display("[%0t] [MUL_MON] EARLY EXIT: All results seen, cycles=%0d/%0d (driver_done_mul=1)",
                         $time, cycles, max_cycles);
`endif
                break;
            end
        end

`ifdef TB_DEBUG_MUL_MON
        $display("[%0t] [MUL_MON] %s: Monitor done, cycles=%0d, seen=%0d, remaining=%0d (driver_done_mul=%0d)",
                 $time, label, cycles, seen, exp_q.size(), driver_done_mul);
`endif

        if (cycles >= max_cycles && exp_q.size() != 0) begin
`ifdef TB_DEBUG_MUL_MON
            $display("[%0t] [MUL_MON] TIMEOUT: max_cycles=%0d reached, remaining=%0d, seen=%0d",
                     $time, max_cycles, exp_q.size(), seen);
`endif
            $error("[%s] TIMEOUT: scoreboard not drained after %0d cycles (remaining=%0d)",
                   label, max_cycles, exp_q.size());
            errors++;
        end
    endtask

    // ------------------------------------------------------------
    // Top-level initial: run all tests
    // ------------------------------------------------------------
    initial begin : main_test
        int exp_total;
        int seen;
        int errors;

        
        // SQRT: 1 & 2 directed
        run_directed_tests();

        $display("\n********** SQRT TESTS COMPLETE, STARTING DIV TESTS **********\n");

        // DIV: 1 & 2 directed
        run_directed_tests_div();

        $display("\n********** DIV DIRECTED TESTS COMPLETE **********\n");

        // ========================================================
        // TEST 3: Upstream Starvation (random gaps, WB always ready)
        // ========================================================
        cur_test = "TEST 3";
        $display("\n=== %s: Upstream Starvation (random gaps) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_SQRT] <= 1'b1; // WB always ready

        // Run driver and monitor concurrently
        fork
            random_driver(10, /*back_to_back_prob=*/50, vsel_t'(7), exp_total);
            random_monitor(/*max_cycles=*/RAND_MAX_CYCLES,
                           seen, errors,
                           /*stall_prob=*/0,
                           cur_test);
        join

        if (errors == 0 && exp_q.size() == 0) begin
            $display("%s PASSED (errors=%0d, results=%0d)", cur_test, errors, seen);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // ========================================================
        // TEST 4: Heavy Writeback Backpressure (WB stalls randomly)
        // ========================================================
        cur_test = "TEST 4";
        $display("\n=== %s: Heavy WB Backpressure ===", cur_test);
        exp_q.delete();

        // Run driver and monitor concurrently again
        fork
            random_driver(10, /*back_to_back_prob=*/100, vsel_t'(9), exp_total);
            random_monitor(/*max_cycles=*/RAND_MAX_CYCLES,
                           seen, errors,
                           /*stall_prob=*/75,
                           cur_test);
        join

        if (errors == 0 && exp_q.size() == 0) begin
            $display("%s PASSED (errors=%0d, results=%0d)", cur_test, errors, seen);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // ========================================================
        // TEST 5: All-zero masks for multiple slices (SQRT)
        //   - No results should ever be produced
        // ========================================================
        cur_test = "TEST 5";
        $display("\n=== %s: All-zero masks (multiple slices) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_SQRT] <= 1'b1; // WB always ready

        fork
            begin
                // 20 slices, all masked off
                zero_mask_driver(20, vsel_t'(13));
            end
            begin
                int cycles_5;
                seen   = 0;
                errors = 0;
                cycles_5 = 0;

                // Watch for stray results for a while
                while (cycles_5 < RAND_MAX_CYCLES) begin
                    @(posedge CLK);
                    cycles_5++;

                    if (lane_if.lane_out.valid_o[FU_SQRT] &&
                        lane_if.lane_in.ready_in[FU_SQRT]) begin
                        $error("[%s] Unexpected result under all-zero mask", cur_test);
                        errors++;
                        seen++;  // count any unexpected hits
                    end
                end
            end
        join

        if (errors == 0 && seen == 0) begin
            $display("%s PASSED (no results, as expected)", cur_test);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // ========================================================
        // TEST 7: Long random run (stress test) - SQRT
        //   - Many slices, random masks, moderate WB stalls
        // ========================================================
        cur_test = "TEST 7";
        $display("\n=== %s: Long random run ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_SQRT] <= 1'b1; // will still be modulated by stall_prob in monitor

        fork
            // 100 slices, always back-to-back (no upstream starvation here)
            random_driver(100, /*back_to_back_prob=*/100, vsel_t'(15), exp_total);
            random_monitor(/*max_cycles=*/10*RAND_MAX_CYCLES, // more time
                           seen, errors,
                           /*stall_prob=*/50,  // moderate random WB stalls
                           cur_test);
        join

        if (errors == 0 && exp_q.size() == 0) begin
            $display("%s PASSED (errors=%0d, results=%0d)", cur_test, errors, seen);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // ========================================================
        // DIV TESTS (Random / Stress)
        // ========================================================

        // ========================================================
        // TEST 3_DIV: Upstream Starvation (random gaps, WB always ready)
        // ========================================================
        // Configuration:
        //   - 10 slices with random masks (~50% active)
        //   - back_to_back_prob=50% (upstream gaps between slices)
        //   - WB always ready (stall_prob=0)
        //   - max_cycles=10*RAND_MAX_CYCLES (2M cycles @ 10ns = 20ms)
        cur_test = "TEST 3_DIV";
        $display("\n=== %s: Upstream Starvation (random gaps) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_DIV] <= 1'b1; // WB always ready

        $display("[TB] %s using max_cycles=%0d", cur_test, 10*RAND_MAX_CYCLES);

        // Run driver and monitor concurrently
        fork
            random_driver_div(10, /*back_to_back_prob=*/50, vsel_t'(21), exp_total);
            random_monitor_div(/*max_cycles=*/10*RAND_MAX_CYCLES,
                               seen, errors,
                               /*stall_prob=*/0,
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // Small drain window before next DIV test (belt-and-suspenders)
        repeat (20) @(posedge CLK);

        // ========================================================
        // TEST 4_DIV: Heavy Writeback Backpressure (WB stalls randomly)
        // ========================================================
        // Configuration:
        //   - 10 slices with random masks (~50% active)
        //   - back_to_back_prob=100% (no upstream gaps)
        //   - WB heavily stalled (stall_prob=75% - ready only 25% of time)
        //   - max_cycles=10*RAND_MAX_CYCLES (2M cycles)
        cur_test = "TEST 4_DIV";
        $display("\n=== %s: Heavy WB Backpressure ===", cur_test);
        exp_q.delete();

        $display("[TB] %s using max_cycles=%0d", cur_test, 10*RAND_MAX_CYCLES);

        // Run driver and monitor concurrently
        fork
            random_driver_div(10, /*back_to_back_prob=*/100, vsel_t'(23), exp_total);
            random_monitor_div(/*max_cycles=*/10*RAND_MAX_CYCLES,
                               seen, errors,
                               /*stall_prob=*/75,
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // Small drain window before TEST 5_DIV
        repeat (20) @(posedge CLK);

        // ========================================================
        // TEST 5_DIV: All-zero masks for multiple slices
        //   - No results should ever be produced
        // ========================================================
        cur_test = "TEST 5_DIV";
        $display("\n=== %s: All-zero masks (multiple slices) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_DIV] <= 1'b1; // WB always ready

        fork
            begin
                // 20 slices, all masked off
                zero_mask_driver_div(20, vsel_t'(25));
            end
            begin
                int cycles_5;
                seen   = 0;
                errors = 0;
                cycles_5 = 0;

                // Watch for stray results for a while
                while (cycles_5 < RAND_MAX_CYCLES) begin
                    @(posedge CLK);
                    cycles_5++;

                    if (lane_if.lane_out.valid_o[FU_DIV] &&
                        lane_if.lane_in.ready_in[FU_DIV]) begin
                        $error("[%s] Unexpected DIV result under all-zero mask: vd=%0d elem_idx=%0d result=%h",
                               cur_test,
                               lane_if.lane_out.vd[FU_DIV],
                               lane_if.lane_out.elem_idx[FU_DIV],
                               lane_if.lane_out.result[FU_DIV]);
                        errors++;
                        seen++;  // count any unexpected hits
                    end
                end
            end
        join

        if (errors == 0 && seen == 0) begin
            $display("%s PASSED (no DIV results, as expected)", cur_test);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // ========================================================
        // TEST 7_DIV: Long random run (stress test)
        // ========================================================
        // Configuration:
        //   - 100 slices with random masks (expect ~50 active ops, ~100 results)
        //   - back_to_back_prob=100% (no upstream gaps)
        //   - Moderate WB backpressure (stall_prob=50%)
        //   - max_cycles=10*RAND_MAX_CYCLES (2M cycles, 10x base timeout)
        cur_test = "TEST 7_DIV";
        $display("\n=== %s: Long random run ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_DIV] <= 1'b1; // will still be modulated by stall_prob in monitor

        $display("[TB] %s using max_cycles=%0d", cur_test, 10*RAND_MAX_CYCLES);

        fork
            // 100 slices, always back-to-back (no upstream starvation here)
            random_driver_div(100, /*back_to_back_prob=*/100, vsel_t'(27), exp_total);
            random_monitor_div(/*max_cycles=*/10*RAND_MAX_CYCLES, // more time
                               seen, errors,
                               /*stall_prob=*/50,  // moderate random WB stalls
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // Small drain window before MUL tests
        repeat (20) @(posedge CLK);

        // ========================================================
        // MUL TESTS
        // ========================================================
        $display("\n********** STARTING MUL TESTS **********\n");

        // ========================================================
        // TEST 1_MUL: All elements unmasked
        // ========================================================
        cur_test = "TEST 1_MUL";
        $display("\n=== %s: All elements unmasked ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;

        begin
            int i;
            slice_vt v1, v2;
            slice_mt mask;
            int expected_results;
            int cycles_1mul;
            obs_t item;

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'(i + 5);
                v2[i]   = fp16_t'(i + 1);
                mask[i] = 1'b1;
            end

            expected_results = SLICE_W;

            // Push expected results
            for (i = 0; i < SLICE_W; i++) begin
                item.vd       = vsel_t'(29);
                item.elem_idx = slice_idx_t'(i);
                exp_q.push_back(item);
            end

            drive_mul_slice(v1, v2, mask, vsel_t'(29), '0);

            seen   = 0;
            errors = 0;
            cycles_1mul = 0;

            // Wait for all results
            while ((seen < expected_results) && (cycles_1mul < DIR_MAX_CYCLES)) begin
                @(posedge CLK);
                cycles_1mul++;

                if (lane_if.lane_out.valid_o[FU_MUL] &&
                    lane_if.lane_in.ready_in[FU_MUL]) begin

                    if (exp_q.size() == 0) begin
                        $error("[%s] Unexpected result: queue empty", cur_test);
                        errors++;
                    end else begin
                        obs_t exp_item;
                        exp_item = exp_q.pop_front();

                        if (lane_if.lane_out.vd[FU_MUL] !== exp_item.vd ||
                            lane_if.lane_out.elem_idx[FU_MUL] !== exp_item.elem_idx) begin
                            $error("[%s] Mismatch: exp vd=%0d idx=%0d, got vd=%0d idx=%0d",
                                   cur_test, exp_item.vd, exp_item.elem_idx,
                                   lane_if.lane_out.vd[FU_MUL],
                                   lane_if.lane_out.elem_idx[FU_MUL]);
                            errors++;
                        end

                        $display("[%0t] %s: MUL result result=%h vd=%0d elem_idx=%0d",
                                 $time, cur_test,
                                 lane_if.lane_out.result[FU_MUL],
                                 lane_if.lane_out.vd[FU_MUL],
                                 lane_if.lane_out.elem_idx[FU_MUL]);

                        seen++;
                    end
                end
            end

            if (errors == 0 && exp_q.size() == 0 && seen == expected_results) begin
                $display("%s PASSED (results=%0d, cycles=%0d)", cur_test, seen, cycles_1mul);
            end else begin
                $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                       cur_test, errors, seen, expected_results, exp_q.size());
                total_errors += (errors == 0 ? 1 : errors);
            end
        end

        repeat (10) @(posedge CLK);

        // ========================================================
        // TEST 2_MUL: Partial mask
        // ========================================================
        cur_test = "TEST 2_MUL";
        $display("\n=== %s: Partial mask ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;

        begin
            int i;
            slice_vt v1, v2;
            slice_mt mask;
            int expected_results;
            int cycles_2mul;
            obs_t item;

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = fp16_t'(i + 10);
                v2[i]   = fp16_t'(i + 2);
                mask[i] = (i % 2);  // active on odd indices
            end

            expected_results = 0;
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = vsel_t'(30);
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    expected_results++;
                end
            end

            drive_mul_slice(v1, v2, mask, vsel_t'(30), '0);

            seen   = 0;
            errors = 0;
            cycles_2mul = 0;

            // Wait for all results
            while ((seen < expected_results) && (cycles_2mul < DIR_MAX_CYCLES)) begin
                @(posedge CLK);
                cycles_2mul++;

                if (lane_if.lane_out.valid_o[FU_MUL] &&
                    lane_if.lane_in.ready_in[FU_MUL]) begin

                    if (exp_q.size() == 0) begin
                        $error("[%s] Unexpected result: queue empty", cur_test);
                        errors++;
                    end else begin
                        obs_t exp_item;
                        exp_item = exp_q.pop_front();

                        if (lane_if.lane_out.vd[FU_MUL] !== exp_item.vd ||
                            lane_if.lane_out.elem_idx[FU_MUL] !== exp_item.elem_idx) begin
                            $error("[%s] Mismatch: exp vd=%0d idx=%0d, got vd=%0d idx=%0d",
                                   cur_test, exp_item.vd, exp_item.elem_idx,
                                   lane_if.lane_out.vd[FU_MUL],
                                   lane_if.lane_out.elem_idx[FU_MUL]);
                            errors++;
                        end

                        $display("[%0t] %s: MUL result result=%h vd=%0d elem_idx=%0d",
                                 $time, cur_test,
                                 lane_if.lane_out.result[FU_MUL],
                                 lane_if.lane_out.vd[FU_MUL],
                                 lane_if.lane_out.elem_idx[FU_MUL]);

                        seen++;
                    end
                end
            end

            if (errors == 0 && exp_q.size() == 0 && seen == expected_results) begin
                $display("%s PASSED (results=%0d, cycles=%0d)", cur_test, seen, cycles_2mul);
            end else begin
                $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                       cur_test, errors, seen, expected_results, exp_q.size());
                total_errors += (errors == 0 ? 1 : errors);
            end
        end

        repeat (10) @(posedge CLK);

        // ========================================================
        // TEST 3_MUL: Upstream Starvation (random gaps, WB always ready)
        // ========================================================
        cur_test = "TEST 3_MUL";
        $display("\n=== %s: Upstream Starvation (random gaps) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;

        $display("[TB] %s using max_cycles=%0d", cur_test, RAND_MAX_CYCLES);

        fork
            random_driver_mul(10, /*back_to_back_prob=*/50, vsel_t'(31), exp_total);
            random_monitor_mul(/*max_cycles=*/RAND_MAX_CYCLES,
                               seen, errors,
                               /*stall_prob=*/0,
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        repeat (20) @(posedge CLK);

        // ========================================================
        // TEST 4_MUL: Heavy Writeback Backpressure (WB stalls randomly)
        // ========================================================
        cur_test = "TEST 4_MUL";
        $display("\n=== %s: Heavy WB Backpressure ===", cur_test);
        exp_q.delete();

        $display("[TB] %s using max_cycles=%0d", cur_test, RAND_MAX_CYCLES);

        fork
            random_driver_mul(10, /*back_to_back_prob=*/100, vsel_t'(33), exp_total);
            random_monitor_mul(/*max_cycles=*/RAND_MAX_CYCLES,
                               seen, errors,
                               /*stall_prob=*/75,
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        repeat (20) @(posedge CLK);

        // ========================================================
        // TEST 5_MUL: All-zero masks for multiple slices
        //   - No results should ever be produced
        // ========================================================
        cur_test = "TEST 5_MUL";
        $display("\n=== %s: All-zero masks (multiple slices) ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;

        fork
            begin
                int s, i;
                slice_vt v1, v2;
                slice_mt mask;

                // 20 slices, all masked off
                for (s = 0; s < 20; s++) begin
                    for (i = 0; i < SLICE_W; i++) begin
                        v1[i]   = fp16_t'($urandom_range(1000, 0));
                        v2[i]   = fp16_t'($urandom_range(1000, 0));
                        mask[i] = 1'b0;
                    end

                    drive_mul_slice(v1, v2, mask, vsel_t'(35), '0);
                end
            end
            begin
                int cycles_5mul;
                seen   = 0;
                errors = 0;
                cycles_5mul = 0;

                // Watch for stray results for a while
                while (cycles_5mul < RAND_MAX_CYCLES) begin
                    @(posedge CLK);
                    cycles_5mul++;

                    if (lane_if.lane_out.valid_o[FU_MUL] &&
                        lane_if.lane_in.ready_in[FU_MUL]) begin
                        $error("[%s] Unexpected MUL result under all-zero mask: vd=%0d elem_idx=%0d result=%h",
                               cur_test,
                               lane_if.lane_out.vd[FU_MUL],
                               lane_if.lane_out.elem_idx[FU_MUL],
                               lane_if.lane_out.result[FU_MUL]);
                        errors++;
                        seen++;
                    end
                end
            end
        join

        if (errors == 0 && seen == 0) begin
            $display("%s PASSED (no MUL results, as expected)", cur_test);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        repeat (20) @(posedge CLK);

        // ========================================================
        // TEST 7_MUL: Long random run (stress test)
        // ========================================================
        cur_test = "TEST 7_MUL";
        $display("\n=== %s: Long random run ===", cur_test);
        exp_q.delete();
        lane_if.lane_in.ready_in[FU_MUL] <= 1'b1;

        $display("[TB] %s using max_cycles=%0d", cur_test, 10*RAND_MAX_CYCLES);

        fork
            // 100 slices, always back-to-back (no upstream starvation here)
            random_driver_mul(100, /*back_to_back_prob=*/100, vsel_t'(37), exp_total);
            random_monitor_mul(/*max_cycles=*/10*RAND_MAX_CYCLES,
                               seen, errors,
                               /*stall_prob=*/50,
                               cur_test);
        join

        if (errors == 0 && exp_q.size() == 0 && seen == exp_total) begin
            $display("%s PASSED (errors=%0d, results=%0d, expected=%0d)",
                     cur_test, errors, seen, exp_total);
        end else begin
            $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                   cur_test, errors, seen, exp_total, exp_q.size());
            total_errors += (errors == 0 ? 1 : errors);
        end

        // Final summary
        $display("\n========================================");
        if (total_errors == 0)
            $display("ALL TESTS PASSED");
        else
            $display("TOTAL ERRORS ACROSS ALL TESTS: %0d", total_errors);
        $display("========================================\n");

        $finish;
    end

    // Global watchdog so the sim can *never* hang silently
    initial begin
        #(5_000_000 * CLK_PERIOD); // much larger for both SQRT and DIV tests
        $error("GLOBAL WATCHDOG TIMEOUT");
        $finish;
    end

endmodule
