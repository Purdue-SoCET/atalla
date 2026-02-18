`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"

module vector_datapath_tb;
    import vector_pkg::*;

    // ------------------------------------------------------------
    // Clock / Reset
    // ------------------------------------------------------------
    logic CLK;
    logic nRST;

    localparam int CLK_PERIOD      = 10;
    localparam int DIR_MAX_CYCLES  = 200_000;
    localparam int RAND_MAX_CYCLES = 200_000;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    task automatic apply_reset;
        begin
            nRST = 1'b0;
            repeat (5) @(posedge CLK);
            nRST = 1'b1;
            repeat (5) @(posedge CLK);
        end
    endtask

    // ------------------------------------------------------------
    // Interface + DUT
    // ------------------------------------------------------------
    vector_if vif();

    vector_datapath dut (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif)
    );

    // Alias lane 0 so lane_tb-style code still reads naturally
    `define lane_if dut.lane_if[0]

    // ------------------------------------------------------------
    // FU indices (must match fu_t encoding)
    // ------------------------------------------------------------
    localparam int FU_VALU = VALU;
    localparam int FU_EXP  = EXP;
    localparam int FU_SQRT = SQRT;
    localparam int FU_MUL  = MUL;
    localparam int FU_DIV  = DIV;

    // ------------------------------------------------------------
    // Scoreboard types / state
    // ------------------------------------------------------------
    typedef struct packed {
        vsel_t      vd;
        slice_idx_t elem_idx;
    } obs_t;

    obs_t exp_q[$];

    string cur_test;
    int    total_errors;

    int seen;
    int errors;

    // For random driver/monitor coordination
    logic driver_done_mul;

    // ------------------------------------------------------------
    // Helper: expand lane slice → full vreg/vmask
    // ------------------------------------------------------------
    task automatic make_full_vector_from_slice(
        input  slice_vt slice_v1,
        input  slice_vt slice_v2,
        input  slice_mt slice_mask,
        output vreg_t   v1_full,
        output vreg_t   v2_full,
        output vmask_t  mask_full
    );
        int i;
        begin
            v1_full   = '0;
            v2_full   = '0;
            mask_full = '0;

            // Lane 0 occupies indices [0 .. SLICE_W-1]
            for (i = 0; i < SLICE_W; i++) begin
                v1_full[i]   = slice_v1[i];
                v2_full[i]   = slice_v2[i];
                mask_full[i] = slice_mask[i];
            end
        end
    endtask

    // ------------------------------------------------------------
    // Helper: drive WB ready for MUL into Result Collector
    // (this drives rc_in.ready_in[ln][FU_MUL], which RC uses as wb_ready)
    // ------------------------------------------------------------
    task automatic set_wb_ready_mul(input logic val);
        int ln;
        begin
            for (ln = 0; ln < NUM_LANES; ln++) begin
                vif.rc_in.ready_in[ln][FU_MUL] <= val;
            end
        end
    endtask

    // WB backpressure driver for MUL via RC (no TB poking lane ready)
    task automatic wb_backpressure_mul(
        input int max_cycles,
        input int stall_prob  // 0..100
    );
        int cycles;
        begin
            cycles = 0;
            while (cycles < max_cycles) begin
                @(posedge CLK);
                cycles++;

                if ($urandom_range(99,0) < stall_prob)
                    set_wb_ready_mul(1'b0);
                else
                    set_wb_ready_mul(1'b1);
            end

            // Leave WB ready high at the end
            set_wb_ready_mul(1'b1);
        end
    endtask

    // ------------------------------------------------------------
    // Generic FU driver via vector_in[0]
    // ------------------------------------------------------------
    task automatic drive_fu_slice_vec(
        input int        fu_idx,
        input slice_vt   slice_v1,
        input slice_vt   slice_v2,
        input slice_mt   slice_mask,
        input vsel_t     vd_tag,
        input opcode_t   op
    );
        vreg_t  v1_full, v2_full;
        vmask_t mask_full;
        int     wait_cycles;
        fu_t    fu_local;
        begin
            make_full_vector_from_slice(slice_v1, slice_v2, slice_mask,
                                        v1_full, v2_full, mask_full);

            fu_local = fu_t'(fu_idx);

            // Wait for lane 0 FU ready_o (through full datapath)
            wait_cycles = 0;
            @(posedge CLK);
            while (!`lane_if.lane_out.ready_o[fu_idx] && nRST &&
                   wait_cycles < 1000) begin
                @(posedge CLK);
                wait_cycles++;
            end

            if (wait_cycles >= 1000) begin
                $error("drive_fu_slice_vec(FU=%0d): lane never became ready!", fu_idx);
            end

            @(posedge CLK);
            // Issue slot 0
            vif.vector_in.v1[0]       <= v1_full;
            vif.vector_in.v2[0]       <= v2_full;
            vif.vector_in.vmask[0]    <= mask_full;
            vif.vector_in.vd[0]       <= vd_tag;
            vif.vector_in.vop[0]      <= op;
            vif.vector_in.rm[0]       <= 1'b0;
            vif.vector_in.fu_sel[0]   <= fu_local;
            vif.vector_in.valid_in[0] <= 1'b1;

            // one-cycle pulse
            @(posedge CLK);
            vif.vector_in.valid_in[0] <= 1'b0;
        end
    endtask

    // Convenience wrappers
    task automatic drive_sqrt_slice_vec(
        input slice_vt slice_v1,
        input slice_vt slice_v2,
        input slice_mt slice_mask,
        input vsel_t   vd_tag,
        input opcode_t op
    );
        drive_fu_slice_vec(FU_SQRT, slice_v1, slice_v2, slice_mask, vd_tag, op);
    endtask

    task automatic drive_mul_slice_vec(
        input slice_vt slice_v1,
        input slice_vt slice_v2,
        input slice_mt slice_mask,
        input vsel_t   vd_tag,
        input opcode_t op
    );
        drive_fu_slice_vec(FU_MUL, slice_v1, slice_v2, slice_mask, vd_tag, op);
    endtask

    // ------------------------------------------------------------
    // Simple directed FU monitor (used by tests 1 & 2)
    // ------------------------------------------------------------
    task automatic wait_and_check_fu(
        input int fu_idx,
        input int expected_results
    );
        obs_t exp_item;
        begin
            seen   = 0;
            errors = 0;

            while (seen < expected_results) begin
                @(posedge CLK);

                if (`lane_if.lane_out.valid_o[fu_idx] &&
                    `lane_if.lane_in.ready_in[fu_idx]) begin

                    if (exp_q.size() == 0) begin
                        $error("[%s] FU%0d unexpected result: queue empty",
                               cur_test, fu_idx);
                        errors++;
                    end else begin
                        exp_item = exp_q.pop_front();

                        if (`lane_if.lane_out.vd[fu_idx]       !== exp_item.vd ||
                            `lane_if.lane_out.elem_idx[fu_idx] !== exp_item.elem_idx) begin
                            $error("[%s] FU%0d meta mismatch: exp vd=%0d idx=%0d, got vd=%0d idx=%0d",
                                  cur_test, fu_idx,
                                  exp_item.vd, exp_item.elem_idx,
                                  `lane_if.lane_out.vd[fu_idx],
                                  `lane_if.lane_out.elem_idx[fu_idx]);
                            errors++;
                        end
                        $display("[MUL DEBUG] t=%0t fu=%0d vd=%0d elem_idx=%0d",
                                $time,
                                fu_idx,
                                `lane_if.lane_out.vd[fu_idx],
                                `lane_if.lane_out.elem_idx[fu_idx]);

                        $display("[%0t] %s: FU%0d result=%h vd=%0d elem_idx=%0d",
                                 $time, cur_test, fu_idx,
                                 `lane_if.lane_out.result[fu_idx],
                                 `lane_if.lane_out.vd[fu_idx],
                                 `lane_if.lane_out.elem_idx[fu_idx]);
                        seen++;
                    end
                end
            end

            if (errors == 0 && exp_q.size() == 0 && seen == expected_results) begin
                $display("%s PASSED (results=%0d)", cur_test, seen);
            end else begin
                $error("%s FAILED (errors=%0d, results=%0d, expected=%0d, remaining=%0d)",
                       cur_test, errors, seen, expected_results, exp_q.size());
                total_errors += (errors == 0 ? 1 : errors);
            end
        end
    endtask

    // ============================================================
    //  SQRT TESTS
    // ============================================================

    task automatic test1_sqrt_all_unmasked;
        slice_vt v1, v2;
        slice_mt mask;
        int      expected_results;
        int      i;
        obs_t    item;
        opcode_t op;
        begin
            cur_test = "TEST 1_SQRT_ALL";
            $display("\n=== %s ===", cur_test);
            exp_q.delete();

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = bf16_t'(i + 3);
                v2[i]   = '0;
                mask[i] = 1'b1;
            end

            expected_results = SLICE_W;
            for (i = 0; i < SLICE_W; i++) begin
                item.vd       = vsel_t'(39);
                item.elem_idx = slice_idx_t'(i);
                exp_q.push_back(item);
            end

            op = '0;
            drive_sqrt_slice_vec(v1, v2, mask, vsel_t'(39), op);
            wait_and_check_fu(FU_SQRT, expected_results);
        end
    endtask

    task automatic test2_sqrt_partial_mask;
        slice_vt v1, v2;
        slice_mt mask;
        int      expected_results;
        int      i;
        obs_t    item;
        opcode_t op;
        begin
            cur_test = "TEST 2_SQRT_PARTIAL_MASK";
            $display("\n=== %s ===", cur_test);
            exp_q.delete();

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = bf16_t'(i + 11);
                v2[i]   = '0;
                mask[i] = (i % 2);
            end

            expected_results = 0;
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = vsel_t'(40);
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    expected_results++;
                end
            end

            op = '0;
            drive_sqrt_slice_vec(v1, v2, mask, vsel_t'(40), op);
            wait_and_check_fu(FU_SQRT, expected_results);
        end
    endtask

    // ============================================================
    //  MUL TESTS 1 & 2 (directed)
    // ============================================================

    task automatic test1_mul_all_unmasked;
        slice_vt v1, v2;
        slice_mt mask;
        int      expected_results;
        int      i;
        obs_t    item;
        opcode_t op;
        begin
            cur_test = "TEST 1_MUL_ALL";
            $display("\n=== %s ===", cur_test);
            exp_q.delete();

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = bf16_t'(i + 5);
                v2[i]   = bf16_t'(i + 1);
                mask[i] = 1'b1;
            end

            expected_results = SLICE_W;
            for (i = 0; i < SLICE_W; i++) begin
                item.vd       = vsel_t'(30);
                item.elem_idx = slice_idx_t'(i);
                exp_q.push_back(item);
            end

            op = '0;
            drive_mul_slice_vec(v1, v2, mask, vsel_t'(30), op);
            wait_and_check_fu(FU_MUL, expected_results);
        end
    endtask

    task automatic test2_mul_partial_mask;
        slice_vt v1, v2;
        slice_mt mask;
        int      expected_results;
        int      i;
        obs_t    item;
        opcode_t op;
        begin
            cur_test = "TEST 2_MUL_PARTIAL_MASK";
            $display("\n=== %s ===", cur_test);
            exp_q.delete();

            for (i = 0; i < SLICE_W; i++) begin
                v1[i]   = bf16_t'(i + 10);
                v2[i]   = bf16_t'((i + 2));
                mask[i] = (i % 2);
            end

            expected_results = 0;
            for (i = 0; i < SLICE_W; i++) begin
                if (mask[i]) begin
                    item.vd       = vsel_t'(31);
                    item.elem_idx = slice_idx_t'(i);
                    exp_q.push_back(item);
                    expected_results++;
                end
            end

            op = '0;
            drive_mul_slice_vec(v1, v2, mask, vsel_t'(31), op);
            wait_and_check_fu(FU_MUL, expected_results);
        end
    endtask

    // ============================================================
    //  MUL Random driver / monitor (for tests 3,4,7)
    // ============================================================

    task automatic random_driver_mul_vec(
        input int   num_slices,
        input int   back_to_back_prob,  // 0..100
        input vsel_t base_vd,
        output int total_expected
    );
        int     s, i;
        slice_vt v1, v2;
        slice_mt mask;
        opcode_t op;
        obs_t    item;
        begin
            total_expected  = 0;
            driver_done_mul = 1'b0;

            for (s = 0; s < num_slices; s++) begin
                // random data
                for (i = 0; i < SLICE_W; i++) begin
                    v1[i]   = bf16_t'($urandom_range(1000, 0));
                    v2[i]   = bf16_t'($urandom_range(1000, 0));
                    mask[i] = $urandom_range(1, 0);
                end
                op = '0;

                // enqueue expected for unmasked elems
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

                drive_mul_slice_vec(v1, v2, mask, base_vd, op);

                // Upstream starvation: random gaps
                if ($urandom_range(99,0) > back_to_back_prob) begin
                    repeat ($urandom_range(4,1)) @(posedge CLK);
                end
            end

            driver_done_mul = 1'b1;
        end
    endtask
    task automatic random_monitor_mul(
        input  int    max_cycles,
        output int    seen_o,
        output int    errors_o,
        input  string label
    );
        int   cycles;
        obs_t exp;
        int   hit_idx;
        begin
            seen_o   = 0;
            errors_o = 0;
            cycles   = 0;

            // Pure observer: handshake == what the DUT sees
            while (cycles < max_cycles) begin
                @(posedge CLK);
                cycles++;

                if (`lane_if.lane_out.valid_o[FU_MUL] &&
                    `lane_if.lane_in.ready_in[FU_MUL]) begin

                    // Observed metadata
                    vsel_t      obs_vd   = `lane_if.lane_out.vd[FU_MUL];
                    slice_idx_t obs_idx  = `lane_if.lane_out.elem_idx[FU_MUL];

                    // ---- Bag-style check: find *any* matching expected entry ----
                    if (exp_q.size() == 0) begin
                        $error("[%s] Unexpected MUL result: queue empty (vd=%0d idx=%0d)",
                               label, obs_vd, obs_idx);
                        errors_o++;
                    end else begin
                        hit_idx = -1;
                        // Search for a matching (vd, elem_idx) anywhere in the queue
                        for (int j = 0; j < exp_q.size(); j++) begin
                            if (exp_q[j].vd == obs_vd &&
                                exp_q[j].elem_idx == obs_idx) begin
                                hit_idx = j;
                                break;
                            end
                        end

                        if (hit_idx < 0) begin
                            // No matching expected entry → duplicate/wrong elem
                            $error("[%s] MUL IDX mismatch: saw vd=%0d idx=%0d with no matching expected entry",
                                   label, obs_vd, obs_idx);
                            errors_o++;
                        end else begin
                            // Found a match: remove that expected item (bag semantics)
                            exp_q.delete(hit_idx);
                            seen_o++;
                        end
                    end
                end

                // If driver is done and we matched all expected items, we can quit early
                if (driver_done_mul && exp_q.size() == 0)
                    break;
            end
        end
    endtask


    // ============================================================
    //  TEST 3_MUL: Upstream starvation (random gaps, WB always ready)
    // ============================================================
    task automatic test3_mul_upstream_starvation;
        int exp_total;
        begin
            cur_test = "TEST 3_MUL";
            $display("\n=== %s: Upstream Starvation (random gaps) ===", cur_test);
            exp_q.delete();

            // WB always ready, only upstream random gaps
            set_wb_ready_mul(1'b1);

            $display("[TB] %s using max_cycles=%0d", cur_test, RAND_MAX_CYCLES);

            fork
                random_driver_mul_vec(10, /*back_to_back_prob=*/50,
                                      vsel_t'(31), exp_total);
                random_monitor_mul(/*max_cycles=*/RAND_MAX_CYCLES,
                                   seen, errors,
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
        end
    endtask

    // ============================================================
    //  TEST 4_MUL: Heavy WB backpressure (random stalls)
    // ============================================================
    task automatic test4_mul_heavy_backpressure;
        int exp_total;
        begin
            cur_test = "TEST 4_MUL";
            $display("\n=== %s: Heavy WB Backpressure ===", cur_test);
            exp_q.delete();

            // Default WB ready high, then wb_backpressure_mul will toggle
            set_wb_ready_mul(1'b1);

            $display("[TB] %s using max_cycles=%0d", cur_test, RAND_MAX_CYCLES);

            fork
                // Driver: fully back-to-back MUL slices
                random_driver_mul_vec(10, /*back_to_back_prob=*/100,
                                      vsel_t'(33), exp_total);

                // Monitor: pure observer on real handshake
                random_monitor_mul(/*max_cycles=*/RAND_MAX_CYCLES,
                                   seen, errors,
                                   cur_test);

                // WB backpressure: randomly stall RC WB
                wb_backpressure_mul(/*max_cycles=*/RAND_MAX_CYCLES,
                                    /*stall_prob=*/75);
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
            $display("[TB TEST4] exp_total=%0d lane0_mul_issue=%0d lane0_mul_wb=%0d",
             exp_total,
             vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_issue_cnt,
             //vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_fire_cnt,
             vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_wb_cnt);
        end
    endtask

    // ============================================================
    //  TEST 5_MUL: All-zero masks (no results allowed)
    // ============================================================
    task automatic test5_mul_all_zero_mask;
        int cycles_5mul;
        begin
            cur_test = "TEST 5_MUL";
            $display("\n=== %s: All-zero masks (multiple slices) ===", cur_test);
            exp_q.delete();

            set_wb_ready_mul(1'b1);

            seen   = 0;
            errors = 0;
            cycles_5mul = 0;

            fork
                // driver: many slices, all masked off
                begin
                    int s, i;
                    slice_vt v1, v2;
                    slice_mt mask;

                    for (s = 0; s < 20; s++) begin
                        for (i = 0; i < SLICE_W; i++) begin
                            v1[i]   = bf16_t'($urandom_range(1000, 0));
                            v2[i]   = bf16_t'($urandom_range(1000, 0));
                            mask[i] = 1'b0;
                        end

                        drive_mul_slice_vec(v1, v2, mask, vsel_t'(35), '0);
                    end
                end

                // monitor: any MUL retire is an error
                begin
                    while (cycles_5mul < RAND_MAX_CYCLES) begin
                        @(posedge CLK);
                        cycles_5mul++;

                        if (`lane_if.lane_out.valid_o[FU_MUL] &&
                            `lane_if.lane_in.ready_in[FU_MUL]) begin
                            $error("[%s] Unexpected MUL result under all-zero mask: vd=%0d elem_idx=%0d result=%h",
                                  cur_test,
                                  `lane_if.lane_out.vd[FU_MUL],
                                  `lane_if.lane_out.elem_idx[FU_MUL],
                                  `lane_if.lane_out.result[FU_MUL]);
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
        end
    endtask

    // ============================================================
    //  TEST 7_MUL: Long random run (stress)
    // ============================================================
    task automatic test7_mul_long_random;
        int exp_total;
        begin
            cur_test = "TEST 7_MUL";
            $display("\n=== %s: Long random run ===", cur_test);
            exp_q.delete();

            set_wb_ready_mul(1'b1);

            fork
                // Heavy sustained traffic
                random_driver_mul_vec(100, /*back_to_back_prob=*/100,
                                      vsel_t'(37), exp_total);

                random_monitor_mul(/*max_cycles=*/10*RAND_MAX_CYCLES,
                                   seen, errors,
                                   cur_test);

                wb_backpressure_mul(/*max_cycles=*/10*RAND_MAX_CYCLES,
                                    /*stall_prob=*/50);
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
            $display("[TB TEST7] exp_total=%0d lane0_mul_issue=%0d lane0_mul_wb=%0d",
                exp_total,
                vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_issue_cnt,
                //vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_fire_cnt,
                vector_datapath_tb.dut.GEN_LANES[0].u_lane.mul_wb_cnt);
        end
    endtask

    // ------------------------------------------------------------
    // Main stimulus
    // ------------------------------------------------------------
    initial begin
        string testname;
        int testnum;

        total_errors = 0;
        vif.vector_in = '0;

        // default WB ready high for all FUs/lanes unless tests override
        for (int ln = 0; ln < NUM_LANES; ln++) begin
            for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
                vif.rc_in.ready_in[ln][fu] = 1'b1;
            end
        end

        apply_reset();
        testnum = 0;

        // SQRT basic directed tests
        testnum += 1;
        testname = $sformatf("Test %0d - SQRT all unmasked", testnum);
        test1_sqrt_all_unmasked();

        testnum += 1;
        testname = $sformatf("Test %0d - SQRT partial mask", testnum);
        test2_sqrt_partial_mask();

        // MUL directed + random tests (1–5 & 7)
        testnum += 1;
        testname = $sformatf("Test %0d - MUL all unmasked", testnum);
        //test1_mul_all_unmasked();

        testnum += 1;
        testname = $sformatf("Test %0d - MUL partial mask", testnum);
        //test2_mul_partial_mask();

        testnum += 1;
        testname = $sformatf("Test %0d - MUL upstream starvation", testnum);
        //test3_mul_upstream_starvation();

        testnum += 1;
        testname = $sformatf("Test %0d - MUL heavy backpressure", testnum);
        test4_mul_heavy_backpressure();

        testnum += 1;
        testname = $sformatf("Test %0d - MUL all zero mask", testnum);
        //test5_mul_all_zero_mask();

        testnum += 1;
        testname = $sformatf("Test %0d - MUL long random", testnum);
        test7_mul_long_random();


        $display("\n========== ALL TESTS COMPLETE, total_errors = %0d ==========",
                 total_errors);
        $finish;
    end

endmodule
