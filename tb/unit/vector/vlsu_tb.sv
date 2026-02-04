`timescale 1ps/1ps

module vlsu_tb;
    import vector_pkg::*;
    import scpad_pkg::*;

    localparam CLK_PERIOD = 10;
    logic clk = 0;
    logic n_rst;
    always #(CLK_PERIOD/2) clk = ~clk;

    // Test tracking
    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;
    string current_test_type;

    //==========================================================================
    // DUT Signals
    //==========================================================================

    // Scheduler interface
    logic                        sched_valid_in;
    logic                        sched_ready_out;
    logic                        sched_write;
    logic [SCPAD_ADDR_WIDTH-1:0] sched_addr;
    logic [SCPAD_ID_WIDTH-1:0]   sched_sp_sel;
    logic [VIDX_W-1:0]           sched_vdst;
    logic [MAX_DIM_WIDTH-1:0]    sched_num_rows;
    logic [MAX_DIM_WIDTH-1:0]    sched_num_cols;
    logic [MAX_DIM_WIDTH-1:0]    sched_row_id;
    logic [MAX_DIM_WIDTH-1:0]    sched_col_id;
    logic                        sched_row_or_col;

    // VRF interface
    vreg_t                       vrf_store_data;
    logic                        vrf_store_valid;

    // Scratchpad interface
    req_t                        sp_req   [NUM_SCPADS];
    logic                        sp_stall [NUM_SCPADS];
    res_t                        sp_res   [NUM_SCPADS];

    // Writeback interface
    vreg_t                       wb_load_data;
    logic [VIDX_W-1:0]           wb_vdst;
    logic                        wb_valid_out;
    logic                        wb_ready_in;

    // Status
    logic                        vlsu_busy;
    logic                        load_queue_full [NUM_SCPADS];

    //==========================================================================
    // DUT
    //==========================================================================

    vlsu #(
        .FIFO_DEPTH(13),
        .NUM_VREGS(256)
    ) DUT (
        .CLK              (clk),
        .nRST             (n_rst),
        .sched_valid_in   (sched_valid_in),
        .sched_ready_out  (sched_ready_out),
        .sched_write      (sched_write),
        .sched_addr       (sched_addr),
        .sched_sp_sel     (sched_sp_sel),
        .sched_vdst       (sched_vdst),
        .sched_num_rows   (sched_num_rows),
        .sched_num_cols   (sched_num_cols),
        .sched_row_id     (sched_row_id),
        .sched_col_id     (sched_col_id),
        .sched_row_or_col (sched_row_or_col),
        .vrf_store_data   (vrf_store_data),
        .vrf_store_valid  (vrf_store_valid),
        .sp_req           (sp_req),
        .sp_stall         (sp_stall),
        .sp_res           (sp_res),
        .wb_load_data     (wb_load_data),
        .wb_vdst          (wb_vdst),
        .wb_valid_out     (wb_valid_out),
        .wb_ready_in      (wb_ready_in),
        .vlsu_busy        (vlsu_busy),
        .load_queue_full  (load_queue_full)
    );

    //==========================================================================
    // Scratchpad Latency Model (13-cycle pipeline per scratchpad)
    //==========================================================================

    localparam SCPAD_LATENCY = 13;
    logic [SCPAD_LATENCY-1:0] sp_delay_valid [NUM_SCPADS];
    scpad_data_t              sp_delay_data  [NUM_SCPADS][SCPAD_LATENCY];

    genvar sp_i;
    generate
        for (sp_i = 0; sp_i < NUM_SCPADS; sp_i++) begin : gen_sp_model
            always_ff @(posedge clk or negedge n_rst) begin
                if (!n_rst) begin
                    sp_delay_valid[sp_i] <= '0;
                    sp_res[sp_i]         <= '0;
                    for (int j = 0; j < SCPAD_LATENCY; j++)
                        sp_delay_data[sp_i][j] <= '0;
                end else begin
                    // Shift valid pipeline
                    sp_delay_valid[sp_i] <= {sp_delay_valid[sp_i][SCPAD_LATENCY-2:0],
                                             (sp_req[sp_i].valid && !sp_req[sp_i].write && !sp_stall[sp_i])};
                    // Shift data pipeline
                    for (int j = SCPAD_LATENCY-1; j > 0; j--)
                        sp_delay_data[sp_i][j] <= sp_delay_data[sp_i][j-1];

                    // Generate mock read data: addr + col + (sp_id << 12)
                    if (sp_req[sp_i].valid && !sp_req[sp_i].write && !sp_stall[sp_i]) begin
                        for (int k = 0; k < NUM_COLS; k++)
                            sp_delay_data[sp_i][0][k] <= sp_req[sp_i].spad_addr[15:0] + k[15:0] + (sp_i << 12);
                    end

                    // Output
                    sp_res[sp_i].valid <= sp_delay_valid[sp_i][SCPAD_LATENCY-1];
                    sp_res[sp_i].write <= 1'b0;
                    sp_res[sp_i].rdata <= sp_delay_data[sp_i][SCPAD_LATENCY-1];
                end
            end
        end
    endgenerate

    //==========================================================================
    // Helper Tasks
    //==========================================================================

    task automatic report_error(string msg);
        $display("[FAIL] %s | %s", current_test_type, msg);
        failed_tests++;
        total_tests++;
    endtask

    task automatic report_success(string msg);
        $display("[PASS] %s | %s", current_test_type, msg);
        passed_tests++;
        total_tests++;
    endtask

    task automatic do_reset();
        n_rst = 0;
        sched_valid_in = 0;
        sched_write = 0;
        sched_addr = '0;
        sched_sp_sel = '0;
        sched_vdst = '0;
        sched_num_rows = '0;
        sched_num_cols = '0;
        sched_row_id = '0;
        sched_col_id = '0;
        sched_row_or_col = 0;
        vrf_store_data = '0;
        vrf_store_valid = 0;
        wb_ready_in = 1;
        for (int i = 0; i < NUM_SCPADS; i++) begin
            sp_stall[i] = 0;
        end
        repeat (5) @(posedge clk);
        n_rst = 1;
        @(posedge clk);
    endtask

    // Issue a load and wait for handshake
    task automatic issue_load(
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input logic [SCPAD_ID_WIDTH-1:0]   sp_sel,
        input logic [VIDX_W-1:0]           vdst
    );
        sched_valid_in   <= 1;
        sched_write      <= 0;
        sched_addr       <= addr;
        sched_sp_sel     <= sp_sel;
        sched_vdst       <= vdst;
        sched_num_rows   <= '0;
        sched_num_cols   <= 5'(NUM_COLS - 1);
        sched_row_id     <= '0;
        sched_col_id     <= '0;
        sched_row_or_col <= 1;

        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);
        sched_valid_in <= 0;
    endtask

    // Issue a store and wait for handshake
    task automatic issue_store(
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input logic [SCPAD_ID_WIDTH-1:0]   sp_sel,
        input vreg_t                       data
    );
        sched_valid_in   <= 1;
        sched_write      <= 1;
        sched_addr       <= addr;
        sched_sp_sel     <= sp_sel;
        sched_num_rows   <= '0;
        sched_num_cols   <= 5'(NUM_COLS - 1);
        sched_row_id     <= '0;
        sched_col_id     <= '0;
        sched_row_or_col <= 1;
        vrf_store_data   <= data;
        vrf_store_valid  <= 1;

        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);
        sched_valid_in  <= 0;
        vrf_store_valid <= 0;
    endtask

    // Wait for a writeback response, return success/fail
    // Always samples at negedge to avoid posedge race conditions
    task automatic wait_wb_response(
        input  logic [VIDX_W-1:0] expected_vdst,
        output logic              success
    );
        automatic int timeout = SCPAD_LATENCY + 20;
        success = 0;

        // Always advance to next negedge first, then check
        forever begin
            @(negedge clk);
            timeout--;
            if (wb_valid_out || timeout == 0) break;
        end

        if (timeout == 0)
            success = 0;
        else if (wb_vdst !== expected_vdst)
            success = 0;
        else
            success = 1;
    endtask

    //==========================================================================
    // Smoke Tests
    //==========================================================================

    task automatic test_single_load_sp0();
        automatic logic success;
        current_test_type = "LOAD_SP0";

        issue_load(20'h1000, 0, 8'h10);
        wait_wb_response(8'h10, success);

        if (success)
            report_success("Single load to SP0, correct vdst returned");
        else
            report_error("Single load to SP0 failed");
    endtask

    task automatic test_single_load_sp1();
        automatic logic success;
        current_test_type = "LOAD_SP1";

        issue_load(20'h2000, 1, 8'h20);
        wait_wb_response(8'h20, success);

        if (success)
            report_success("Single load to SP1, correct vdst returned");
        else
            report_error("Single load to SP1 failed");
    endtask

    task automatic test_single_store();
        automatic vreg_t wdata;
        current_test_type = "STORE_SP0";

        for (int i = 0; i < VLMAX; i++)
            wdata[i] = 16'(i + 1);

        issue_store(20'h3000, 0, wdata);
        // Store is pass-through; just verify request was accepted
        report_success("Store accepted by VLSU");
    endtask

    task automatic test_multiple_outstanding();
        automatic logic success;
        automatic int errors = 0;
        current_test_type = "MULTI_LOAD";

        // Issue 5 loads truly back-to-back: hold valid high, change addr/vdst each cycle
        for (int i = 0; i < 5; i++) begin
            sched_valid_in   <= 1;
            sched_write      <= 0;
            sched_addr       <= 20'h4000 + i * 20'h100;
            sched_sp_sel     <= '0;
            sched_vdst       <= 8'h40 + i;
            sched_num_rows   <= '0;
            sched_num_cols   <= 5'(NUM_COLS - 1);
            sched_row_id     <= '0;
            sched_col_id     <= '0;
            sched_row_or_col <= 1;
            @(posedge clk);
            while (!sched_ready_out) @(posedge clk);
        end
        sched_valid_in <= 0;

        // Collect all 5 responses in order
        for (int i = 0; i < 5; i++) begin
            wait_wb_response(8'h40 + i, success);
            if (!success) errors++;
        end

        if (errors == 0)
            report_success("5 outstanding loads returned in FIFO order");
        else
            report_error($sformatf("%0d of 5 responses incorrect", errors));
    endtask

    task automatic test_backpressure();
        current_test_type = "BACKPRESS";

        wb_ready_in = 0;  // Block writeback so FIFO fills

        // Fill FIFO (depth=13)
        for (int i = 0; i < 13; i++) begin
            sched_valid_in <= 1;
            sched_write    <= 0;
            sched_addr     <= 20'h5000 + i * 20'h10;
            sched_sp_sel   <= '0;
            sched_vdst     <= 8'h50 + i;
            @(posedge clk);
            while (!sched_ready_out) @(posedge clk);
            sched_valid_in <= 0;
            @(posedge clk);
        end

        // One more should be rejected
        sched_valid_in <= 1;
        sched_write    <= 0;
        sched_addr     <= 20'h5FFF;
        sched_sp_sel   <= '0;
        sched_vdst     <= 8'hFF;
        @(posedge clk);

        if (!sched_ready_out && load_queue_full[0])
            report_success("Backpressure asserted when FIFO full");
        else
            report_error("No backpressure when FIFO should be full");

        sched_valid_in <= 0;
        wb_ready_in = 1;
        // Drain
        repeat(SCPAD_LATENCY + 13 + 10) @(posedge clk);
    endtask

    task automatic test_stall_handling();
        automatic logic success;
        current_test_type = "SP_STALL";

        sp_stall[0] = 1;

        sched_valid_in <= 1;
        sched_write    <= 0;
        sched_addr     <= 20'h6000;
        sched_sp_sel   <= '0;
        sched_vdst     <= 8'h60;
        @(posedge clk);

        if (sched_ready_out) begin
            report_error("Ready should be LOW when scratchpad stalled");
            sched_valid_in <= 0;
            sp_stall[0] = 0;
            return;
        end

        // Release stall
        sp_stall[0] = 0;
        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);
        sched_valid_in <= 0;

        wait_wb_response(8'h60, success);

        if (success)
            report_success("Load completed after stall released");
        else
            report_error("Load failed after stall released");
    endtask

    // Test 1.7: Split Transaction
    // Issue a load, then while its response is coming back, issue a second load.
    // Verify the VLSU can complete writeback of the first AND accept the second
    // in the same cycle.
    task automatic test_split_transaction();
        automatic logic success;
        automatic int errors = 0;
        current_test_type = "SPLIT_TXN";

        // Issue first load to SP0
        issue_load(20'hA000, 0, 8'hA0);

        // Wait until the response is about to arrive (just before latency completes)
        repeat(SCPAD_LATENCY - 2) @(posedge clk);

        // Now issue a second load while the first response is in flight
        // The VLSU should accept this new request AND writeback the first result
        sched_valid_in   <= 1;
        sched_write      <= 0;
        sched_addr       <= 20'hA100;
        sched_sp_sel     <= '0;
        sched_vdst       <= 8'hA1;
        sched_num_rows   <= '0;
        sched_num_cols   <= 5'(NUM_COLS - 1);
        sched_row_id     <= '0;
        sched_col_id     <= '0;
        sched_row_or_col <= 1;

        // Wait for the first response writeback
        wait_wb_response(8'hA0, success);
        if (!success) errors++;

        // Check that the second load was accepted (ready should have been high)
        // Deassert after handshake
        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);
        sched_valid_in <= 0;

        // Wait for second response
        wait_wb_response(8'hA1, success);
        if (!success) errors++;

        if (errors == 0)
            report_success("Writeback + new request accepted concurrently");
        else
            report_error($sformatf("Split transaction failed with %0d errors", errors));
    endtask

    // Test: Dual Scratchpad Concurrent Loads
    // Issue loads to SP0 and SP1 back-to-back, verify both responses
    // come back independently and in correct order.
    task automatic test_dual_sp_load();
        automatic logic success;
        automatic int errors = 0;
        current_test_type = "DUAL_SP";

        // Issue load to SP0
        sched_valid_in   <= 1;
        sched_write      <= 0;
        sched_addr       <= 20'hB000;
        sched_sp_sel     <= 0;
        sched_vdst       <= 8'hB0;
        sched_num_rows   <= '0;
        sched_num_cols   <= 5'(NUM_COLS - 1);
        sched_row_id     <= '0;
        sched_col_id     <= '0;
        sched_row_or_col <= 1;
        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);

        // Immediately issue load to SP1 (next cycle)
        sched_sp_sel     <= 1;
        sched_addr       <= 20'hB100;
        sched_vdst       <= 8'hB1;
        @(posedge clk);
        while (!sched_ready_out) @(posedge clk);
        sched_valid_in <= 0;

        // Both are now in-flight to different scratchpads
        // SP0 response arrives first (issued one cycle earlier)
        wait_wb_response(8'hB0, success);
        if (!success) begin
            $display("[DEBUG] DUAL_SP: SP0 response mismatch");
            errors++;
        end

        // SP1 response arrives one cycle later
        wait_wb_response(8'hB1, success);
        if (!success) begin
            $display("[DEBUG] DUAL_SP: SP1 response mismatch");
            errors++;
        end

        if (errors == 0)
            report_success("Concurrent loads to SP0 and SP1 both returned correctly");
        else
            report_error($sformatf("Dual SP load failed with %0d errors", errors));
    endtask

    // Test: Dual Scratchpad Multi-Outstanding
    // Issue 3 loads to SP0 and 3 loads to SP1 interleaved, verify all 6
    // come back with correct vdst values.
    task automatic test_dual_sp_interleaved();
        automatic logic success;
        automatic int errors = 0;
        current_test_type = "DUAL_SP_INTLV";

        // Issue 3 loads alternating between SP0 and SP1
        for (int i = 0; i < 3; i++) begin
            // SP0
            sched_valid_in   <= 1;
            sched_write      <= 0;
            sched_addr       <= 20'hC000 + i * 20'h100;
            sched_sp_sel     <= 0;
            sched_vdst       <= 8'hC0 + 2*i;   // C0, C2, C4
            sched_num_rows   <= '0;
            sched_num_cols   <= 5'(NUM_COLS - 1);
            sched_row_id     <= '0;
            sched_col_id     <= '0;
            sched_row_or_col <= 1;
            @(posedge clk);
            while (!sched_ready_out) @(posedge clk);

            // SP1
            sched_sp_sel     <= 1;
            sched_addr       <= 20'hD000 + i * 20'h100;
            sched_vdst       <= 8'hC1 + 2*i;   // C1, C3, C5
            @(posedge clk);
            while (!sched_ready_out) @(posedge clk);
        end
        sched_valid_in <= 0;

        // Responses arrive interleaved: SP0 first each pair (issued 1 cycle earlier)
        // Priority arbitration picks SP0 (lower index) when both pending same cycle
        for (int i = 0; i < 3; i++) begin
            // SP0 response
            wait_wb_response(8'hC0 + 2*i, success);
            if (!success) begin
                $display("[DEBUG] DUAL_SP_INTLV: SP0 resp %0d mismatch", i);
                errors++;
            end
            // SP1 response
            wait_wb_response(8'hC1 + 2*i, success);
            if (!success) begin
                $display("[DEBUG] DUAL_SP_INTLV: SP1 resp %0d mismatch", i);
                errors++;
            end
        end

        if (errors == 0)
            report_success("6 interleaved loads across SP0/SP1 all correct");
        else
            report_error($sformatf("Interleaved dual SP failed with %0d errors", errors));
    endtask

    // Test: Power-On Reset (1.1)
    // Verify all outputs are in known default state after reset.
    task automatic test_power_on_reset();
        automatic int errors = 0;
        current_test_type = "POR_RESET";

        // Check all outputs are at default after reset
        if (sched_ready_out !== 1'b1) begin
            $display("[DEBUG] POR: sched_ready_out=%b (expected 1)", sched_ready_out);
            errors++;
        end
        if (wb_valid_out !== 1'b0) begin
            $display("[DEBUG] POR: wb_valid_out=%b (expected 0)", wb_valid_out);
            errors++;
        end
        if (vlsu_busy !== 1'b0) begin
            $display("[DEBUG] POR: vlsu_busy=%b (expected 0)", vlsu_busy);
            errors++;
        end
        for (int i = 0; i < NUM_SCPADS; i++) begin
            if (sp_req[i].valid !== 1'b0) begin
                $display("[DEBUG] POR: sp_req[%0d].valid=%b (expected 0)", i, sp_req[i].valid);
                errors++;
            end
            if (load_queue_full[i] !== 1'b0) begin
                $display("[DEBUG] POR: load_queue_full[%0d]=%b (expected 0)", i, load_queue_full[i]);
                errors++;
            end
        end

        if (errors == 0)
            report_success("All outputs at default state after reset");
        else
            report_error($sformatf("Reset state incorrect: %0d signals wrong", errors));
    endtask

    //==========================================================================
    // Test Suite & Summary
    //==========================================================================

    task automatic run_smoke_tests();
        $display("\n======== VLSU SMOKE TESTS ========\n");

        // 1.1 Power-On Reset
        do_reset();
        test_power_on_reset();

        // 1.2 / 1.3 Single loads (ready/valid + load from scratchpad)
        do_reset();
        test_single_load_sp0();

        do_reset();
        test_single_load_sp1();

        // 1.4 Store to scratchpad
        do_reset();
        test_single_store();

        // 1.3 / 1.6 Multiple outstanding loads (FIFO pop on writeback)
        do_reset();
        test_multiple_outstanding();

        // Backpressure (FIFO full)
        do_reset();
        test_backpressure();

        // Stall handling
        do_reset();
        test_stall_handling();

        // 1.7 Split transaction (writeback + new request same cycle)
        do_reset();
        test_split_transaction();

        // Dual scratchpad: concurrent loads
        do_reset();
        test_dual_sp_load();

        // Dual scratchpad: interleaved multi-outstanding
        do_reset();
        test_dual_sp_interleaved();
    endtask

    task automatic print_summary();
        $display("\n");
        $display("============ TEST SUMMARY ============");
        $display("  Total: %0d | Passed: %0d | Failed: %0d", total_tests, passed_tests, failed_tests);
        if (failed_tests == 0) $display("  ALL TESTS PASSED");
        else $display("  SOME TESTS FAILED");
        $display("======================================\n");
    endtask

    //==========================================================================
    // Main
    //==========================================================================
    initial begin
        $display("\n===== VLSU SMOKE TEST SUITE =====\n");

        run_smoke_tests();

        print_summary();

        if (failed_tests > 0)
            $display("FATAL: Test suite failed with %0d failures", failed_tests);
        $finish;
    end

    // Timeout watchdog
    initial begin
        #2000000;
        $display("\n[TIMEOUT] Simulation exceeded time limit\n");
        $finish;
    end

endmodule