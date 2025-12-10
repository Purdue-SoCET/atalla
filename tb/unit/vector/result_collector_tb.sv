// ------------------------------------------------------------
// tb_result_collector.sv
// Standalone smoke + directed test for result_collector + rc_fu
// Drives rc_in directly (no lane.sv involved in the datapath).
// ------------------------------------------------------------
`timescale 1ns/1ps

`include "vector_if.vh"
`include "vector_pkg.vh"

module result_collector_tb;
    import vector_pkg::*;

    // ------------------------------------------------------------
    // 1. Clock / Reset
    // ------------------------------------------------------------
    logic CLK;
    logic nRST;

    initial CLK = 1'b0;
    always #5 CLK = ~CLK;   // 100 MHz

    initial begin
        nRST = 1'b0;
        repeat (5) @(posedge CLK);
        nRST = 1'b1;
        $display("[%0t] TB: Reset deasserted", $time);
    end

    // Some useful locals
    localparam int ELEM_W        = $bits(bf16_t);
    localparam int NUM_ELEMS_MAX = VLMAX;  // Maximum elements in a vector

    // ------------------------------------------------------------
    // 2. Shared Vector Interface (only rc_in/rc_out used here)
    // ------------------------------------------------------------
    vector_if vif();

    // ------------------------------------------------------------
    // 3. DUT: Result Collector
    // ------------------------------------------------------------
    result_collector u_result_collector (
        .CLK (CLK),
        .nRST(nRST),
        .rcif(vif.result_collector)
    );

    // ------------------------------------------------------------
    // 4. Default / Initial Drives
    // ------------------------------------------------------------
    initial begin
        vif.rc_in = '0;

        // WB ready: default "ready" = 1 (can be overridden in tests)
        for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
            vif.rc_in.ready_in[0][fu] = 1'b1;
        end
    end

    // ------------------------------------------------------------
    // 4.5 Current test name (for logging)
    // ------------------------------------------------------------
    string cur_test_name;

    // ------------------------------------------------------------
    // 5. Scoreboard: expected items & WB monitor
    // ------------------------------------------------------------
    typedef struct {
        int    fu;
        vsel_t vd;
        vreg_t vec;
        string name;
    } exp_item_t;

    exp_item_t exp_q[$];

    task automatic push_expect(
        input int    fu,
        input vsel_t vd,
        input vreg_t vec,
        input string name
    );
        exp_item_t item;
        item.fu   = fu;
        item.vd   = vd;
        item.vec  = vec;
        item.name = name;
        exp_q.push_back(item);
    endtask

    // For checking stability while WB is stalled
    logic   hold_valid [LANE_FU_COUNT];
    vreg_t  hold_vec   [LANE_FU_COUNT];
    vsel_t  hold_vd    [LANE_FU_COUNT];
    logic   prev_vr    [LANE_FU_COUNT];


    initial begin
        for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
            hold_valid[fu] = 1'b0;
            hold_vec[fu]   = '0;
            hold_vd[fu]    = '0;
        end
    end

       // Writeback Monitor / Sink
    initial begin : WB_MONITOR
        int   fu;
        logic cur_vr;
        logic fire;

        @(posedge nRST);
        @(posedge CLK);

        forever begin
            @(posedge CLK);

            for (fu = 0; fu < LANE_FU_COUNT; fu++) begin
                // ------------------------------
                // Backpressure / stability check
                // ------------------------------
                if (vif.rc_out.valid_o[fu] && !vif.rc_in.ready_in[0][fu]) begin
                    if (!hold_valid[fu]) begin
                        hold_valid[fu] <= 1'b1;
                        hold_vec[fu]   <= vif.rc_out.result[fu];
                        hold_vd[fu]    <= vif.rc_out.vd[fu];
                    end else begin
                        assert(vif.rc_out.result[fu] == hold_vec[fu])
                            else $error("[%0t] (%s) RC: FU=%0d result changed while stalled",
                                        $time, cur_test_name, fu);
                        assert(vif.rc_out.vd[fu] == hold_vd[fu])
                            else $error("[%0t] (%s) RC: FU=%0d vd changed while stalled",
                                        $time, cur_test_name, fu);
                    end
                end else if (!vif.rc_out.valid_o[fu]) begin
                    hold_valid[fu] <= 1'b0;
                end

                // ------------------------------
                // Handshake edge-detect:
                // count only the 0->1 edge of (valid && ready)
                // ------------------------------
                cur_vr = vif.rc_out.valid_o[fu] && vif.rc_in.ready_in[0][fu];
                fire   = cur_vr && !prev_vr[fu];

                if (fire) begin
                    if (exp_q.size == 0) begin
                        $error("[%0t] (%s) RC WB: Unexpected writeback FU=%0d, VD=%0d",
                               $time, cur_test_name, fu, vif.rc_out.vd[fu]);
                    end else begin
                        exp_item_t got;
                        got = exp_q.pop_front();

                        if (got.fu != fu) begin
                            $error("[%0t] (%s) RC WB: FU mismatch. Expected FU=%0d (%s), got FU=%0d",
                                   $time, cur_test_name, got.fu, got.name, fu);
                        end

                        if (vif.rc_out.vd[fu] !== got.vd) begin
                            $error("[%0t] (%s) RC WB: VD mismatch for %s. Exp=%0d got=%0d",
                                   $time, cur_test_name, got.name, got.vd, vif.rc_out.vd[fu]);
                        end

                        if (vif.rc_out.result[fu] !== got.vec) begin
                            $error("[%0t] (%s) RC WB: DATA mismatch for %s (FU=%0d, VD=%0d)",
                                   $time, cur_test_name, got.name, fu, got.vd);
                        end else begin
                            $display("[%0t] (%s) RC WB PASS: %s (FU=%0d, VD=%0d)",
                                     $time, cur_test_name, got.name, fu, got.vd);
                        end
                    end
                end

                // Remember current (valid && ready) for next cycle
                prev_vr[fu] <= cur_vr;
            end
        end
    end


    // ------------------------------------------------------------
    // 6. Helper: one-cycle, one-element-per-lane vector (elem_idx=0)
    // last asserted on final lane
    // ------------------------------------------------------------
    task automatic drive_vector_for_fu(
        input int    fu_idx,
        input vsel_t dest_vd,
        input bf16_t base_val
    );
        int ln;

        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][fu_idx] = 1'b1;
            vif.rc_in.vd       [ln][fu_idx] = dest_vd;
            // Simple pattern: base + lane index
            vif.rc_in.result   [ln][fu_idx] = base_val + bf16_t'(ln);
            vif.rc_in.elem_idx [ln][fu_idx] = '0;                  // elem 0
            vif.rc_in.last     [ln][fu_idx] = (ln == NUM_LANES-1); // last lane
        end

        @(posedge CLK);

        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][fu_idx] = 1'b0;
            vif.rc_in.last     [ln][fu_idx] = 1'b0;
        end
    endtask

    // ------------------------------------------------------------
    // 7. Helper: two-elements-per-lane vector (elem_idx=0 then 1)
    // last asserted on final lane at elem_idx=1
    // ------------------------------------------------------------
    task automatic drive_two_elem_vector_for_fu(
        input int    fu_idx,
        input vsel_t dest_vd,
        input bf16_t base_val
    );
        int ln;

        // First element per lane: elem_idx=0, last=0
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][fu_idx] = 1'b1;
            vif.rc_in.vd       [ln][fu_idx] = dest_vd;
            vif.rc_in.result   [ln][fu_idx] = base_val + bf16_t'(ln*2 + 0);
            vif.rc_in.elem_idx [ln][fu_idx] = slice_idx_t'(0);
            vif.rc_in.last     [ln][fu_idx] = 1'b0;
        end
        @(posedge CLK);

        // Second element per lane: elem_idx=1, last=1 on final lane
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][fu_idx] = 1'b1;
            vif.rc_in.vd       [ln][fu_idx] = dest_vd;
            vif.rc_in.result   [ln][fu_idx] = base_val + bf16_t'(ln*2 + 1);
            vif.rc_in.elem_idx [ln][fu_idx] = slice_idx_t'(1);
            vif.rc_in.last     [ln][fu_idx] = (ln == NUM_LANES-1);
        end
        @(posedge CLK);

        // Drop valids/last
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][fu_idx] = 1'b0;
            vif.rc_in.last     [ln][fu_idx] = 1'b0;
        end
    endtask

    // ------------------------------------------------------------
    // 8. Build expected vectors for the helpers above
    // ------------------------------------------------------------
    function automatic vreg_t build_exp_one_elem_per_lane(
        input bf16_t base_val
    );
        vreg_t exp;
        exp = '0;

        for (int ln = 0; ln < NUM_LANES; ln++) begin
            bf16_t val = base_val + bf16_t'(ln);
            // gidx = { lane_bits, elem_idx(0) }
            int unsigned gidx;
            gidx = { ln[$clog2(NUM_LANES)-1:0], slice_idx_t'(0) };
            exp[gidx*ELEM_W +: ELEM_W] = val;
        end

        return exp;
    endfunction

    function automatic vreg_t build_exp_two_elem_per_lane(
        input bf16_t base_val
    );
        vreg_t exp;
        exp = '0;

        for (int ln = 0; ln < NUM_LANES; ln++) begin
            for (int e = 0; e < SLICE_W; e++) begin
                bf16_t val = base_val + bf16_t'(ln*2 + e);
                int unsigned gidx;
                gidx = { ln[$clog2(NUM_LANES)-1:0], slice_idx_t'(e) };
                exp[gidx*ELEM_W +: ELEM_W] = val;
            end
        end

        return exp;
    endfunction

    // ------------------------------------------------------------
    // 9. Directed Tests
    // ------------------------------------------------------------
    task automatic test_basic_mul;
        bf16_t base;
        vreg_t exp;
        vsel_t vd;

        cur_test_name = "TEST 1: BASIC_MUL";

        vd   = vsel_t'(5'd1);
        base = bf16_t'(16'h3C00); // just a pattern

        exp = build_exp_one_elem_per_lane(base);
        push_expect(MUL, vd, exp, "TEST_BASIC_MUL");

        $display("[%0t] (%s) TB: TEST_BASIC_MUL starting", $time, cur_test_name);
        drive_vector_for_fu(MUL, vd, base);
        repeat (20) @(posedge CLK);
    endtask

    task automatic test_fu_routing_mul_then_div;
        bf16_t base_mul, base_div;
        vreg_t exp_mul, exp_div;
        vsel_t vd_mul, vd_div;

        cur_test_name = "TEST 2: FU_ROUTING_MUL_DIV";

        vd_mul   = vsel_t'(5'd2);
        vd_div   = vsel_t'(5'd3);
        base_mul = bf16_t'(16'h4000);
        base_div = bf16_t'(16'h4200);

        exp_mul = build_exp_one_elem_per_lane(base_mul);
        exp_div = build_exp_one_elem_per_lane(base_div);

        push_expect(MUL, vd_mul, exp_mul, "TEST_FU_ROUTE_MUL");
        push_expect(DIV, vd_div, exp_div, "TEST_FU_ROUTE_DIV");

        $display("[%0t] (%s) TB: TEST_FU_ROUTING MUL then DIV", $time, cur_test_name);
        drive_vector_for_fu(MUL, vd_mul, base_mul);
        repeat (10) @(posedge CLK);
        drive_vector_for_fu(DIV, vd_div, base_div);
        repeat (20) @(posedge CLK);
    endtask

    task automatic test_global_index_two_elems;
        bf16_t base;
        vreg_t exp;
        vsel_t vd;

        cur_test_name = "TEST 3: GLOBAL_INDEX_2ELEM";

        vd   = vsel_t'(5'd4);
        base = bf16_t'(16'h4400);

        exp = build_exp_two_elem_per_lane(base);
        push_expect(MUL, vd, exp, "TEST_GLOBAL_INDEX_2ELEM");

        $display("[%0t] (%s) TB: TEST_GLOBAL_INDEX_2ELEM starting", $time, cur_test_name);
        drive_two_elem_vector_for_fu(MUL, vd, base);
        repeat (40) @(posedge CLK);
    endtask

    // Backpressure test
    task automatic test_wb_backpressure;
        bf16_t base;
        vreg_t exp;
        vsel_t vd;

        cur_test_name = "TEST 4: WB_BACKPRESSURE";

        vd   = vsel_t'(5'd5);
        base = bf16_t'(16'h4500);

        exp = build_exp_one_elem_per_lane(base);
        push_expect(MUL, vd, exp, "TEST_WB_BACKPRESSURE");

        $display("[%0t] (%s) TB: TEST_WB_BACKPRESSURE starting", $time, cur_test_name);

        // Start with ready=0 for MUL
        vif.rc_in.ready_in[0][MUL] = 1'b0;

        drive_vector_for_fu(MUL, vd, base);

        // Hold ready low for a few cycles while RC has time to build the vector
        repeat (10) @(posedge CLK);

        // Now release backpressure
        $display("[%0t] (%s) TB: WB ready asserted again for MUL", $time, cur_test_name);
        vif.rc_in.ready_in[0][MUL] = 1'b1;

        repeat (40) @(posedge CLK);

        // Restore default ready
        vif.rc_in.ready_in[0][MUL] = 1'b1;
    endtask

    // Fast "last lane" race test
    task automatic test_fast_last_lane_race;
        bf16_t base;
        vreg_t exp;
        vsel_t vd;
        int ln;

        cur_test_name = "TEST 5: FAST_LAST_LANE_RACE";

        vd   = vsel_t'(5'd6);
        base = bf16_t'(16'h4600);

        // EXPECTATION: full vector with all lanes written
        exp = build_exp_one_elem_per_lane(base);
        push_expect(MUL, vd, exp, "TEST_FAST_LAST_LANE_RACE");

        $display("[%0t] (%s) TB: TEST_FAST_LAST_LANE_RACE starting (may FAIL with current rc_fu)",
                 $time, cur_test_name);

        // Step 1: ONLY last lane writes, with last=1
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][MUL] = 1'b0;
            vif.rc_in.last     [ln][MUL] = 1'b0;
        end
        vif.rc_in.valid_in [NUM_LANES-1][MUL] = 1'b1;
        vif.rc_in.vd       [NUM_LANES-1][MUL] = vd;
        vif.rc_in.result   [NUM_LANES-1][MUL] = base + bf16_t'(NUM_LANES-1);
        vif.rc_in.elem_idx [NUM_LANES-1][MUL] = '0;
        vif.rc_in.last     [NUM_LANES-1][MUL] = 1'b1;

        @(posedge CLK);

        // Step 2: now try to write remaining lanes (0..NUM_LANES-2)
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES-1; ln++) begin
            vif.rc_in.valid_in [ln][MUL] = 1'b1;
            vif.rc_in.vd       [ln][MUL] = vd;
            vif.rc_in.result   [ln][MUL] = base + bf16_t'(ln);
            vif.rc_in.elem_idx [ln][MUL] = '0;
            vif.rc_in.last     [ln][MUL] = 1'b0;
        end
        // Clear last on lane NUM_LANES-1
        vif.rc_in.valid_in [NUM_LANES-1][MUL] = 1'b0;
        vif.rc_in.last     [NUM_LANES-1][MUL] = 1'b0;

        @(posedge CLK);

        // Drop all valids
        @(negedge CLK);
        for (ln = 0; ln < NUM_LANES; ln++) begin
            vif.rc_in.valid_in [ln][MUL] = 1'b0;
            vif.rc_in.last     [ln][MUL] = 1'b0;
        end

        repeat (40) @(posedge CLK);
    endtask

    // ------------------------------------------------------------
    // 10. Main Test Sequence
    // ------------------------------------------------------------
    initial begin : MAIN_TEST
        @(posedge nRST);
        @(posedge CLK);

        $display("[%0t] TB: Starting RC tests...", $time);

        test_basic_mul();
        test_fu_routing_mul_then_div();
        //test_global_index_two_elems(); // enable when 2-e/lanes are supported
        test_wb_backpressure();
        test_fast_last_lane_race();

        // Let outstanding WB complete
        repeat (100) @(posedge CLK);

        if (exp_q.size != 0) begin
            $error("TB: Some expected items never observed. Remaining = %0d", exp_q.size);
        end else begin
            $display("[%0t] TB: All expected writebacks observed.", $time);
        end

        $display("[%0t] TB: Done.", $time);
        $finish;
    end

endmodule
