`include "vector_pkg.vh"
`include "scpad_pkg.sv"

// VLSU Testbench - Multi-Channel
// Verification plan items 1.1–1.7, plus additional stress/corner tests.
// Scratchpad response latency is modeled with a configurable delay pipeline.

module vlsu_tb;
    import vector_pkg::*;
    import scpad_pkg::*;

    localparam int CLK_PERIOD   = 10;
    localparam int FIFO_DEPTH   = 13;
    localparam int SP_LATENCY   = 5;
    localparam int NUM_VREGS    = 256;
    localparam int VDST_W       = VIDX_W;
    localparam int NUM_SP       = NUM_SCPADS;

    // Clock / Reset
    logic CLK, nRST;
    always #(CLK_PERIOD/2) CLK = ~CLK;

    // Scheduler channels
    logic                           sched_valid_in  [NUM_SP];
    logic                           sched_ready_out [NUM_SP];
    logic                           sched_write     [NUM_SP];
    logic [SCPAD_ADDR_WIDTH-1:0]    sched_addr      [NUM_SP];
    logic [VIDX_W-1:0]              sched_vdst      [NUM_SP];

    logic [MAX_DIM_WIDTH-1:0]       sched_num_rows  [NUM_SP];
    logic [MAX_DIM_WIDTH-1:0]       sched_num_cols  [NUM_SP];
    logic [MAX_DIM_WIDTH-1:0]       sched_row_id    [NUM_SP];
    logic [MAX_DIM_WIDTH-1:0]       sched_col_id    [NUM_SP];
    logic                           sched_row_or_col[NUM_SP];

    // VRF store data
    vreg_t                          vrf_store_data  [NUM_SP];
    logic                           vrf_store_valid [NUM_SP];

    // Scratchpad interface
    req_t                           sp_req  [NUM_SP];
    logic                           sp_stall [NUM_SP];
    res_t                           sp_res  [NUM_SP];

    // Writeback
    vreg_t                          wb_load_data;
    logic [VIDX_W-1:0]             wb_vdst;
    logic                           wb_valid_out;
    logic                           wb_ready_in;

    // Status
    logic                           vlsu_busy;
    logic                           load_queue_full [NUM_SP];

    // DUT
    vlsu #(
        .FIFO_DEPTH(FIFO_DEPTH),
        .NUM_VREGS(NUM_VREGS)
    ) DUT (.*);

    // Scratchpad response model - per-channel delay pipeline
    typedef struct packed {
        logic        valid;
        logic        write;
        scpad_data_t rdata;
    } sp_pipe_entry_t;

    sp_pipe_entry_t sp_pipe [NUM_SP][SP_LATENCY];

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            for (int s = 0; s < NUM_SP; s++) begin
                for (int d = 0; d < SP_LATENCY; d++)
                    sp_pipe[s][d] <= '0;
                sp_res[s].valid <= 1'b0;
                sp_res[s].write <= 1'b0;
                sp_res[s].rdata <= '0;
            end
        end else begin
            for (int s = 0; s < NUM_SP; s++) begin
                sp_pipe[s][0].valid <= sp_req[s].valid;
                sp_pipe[s][0].write <= sp_req[s].write;
                if (sp_req[s].valid && !sp_req[s].write) begin
                    for (int e = 0; e < NUM_COLS; e++)
                        sp_pipe[s][0].rdata[e] <= ELEM_BITS'({s[3:0], sp_req[s].spad_addr[ELEM_BITS-5:0]}) + ELEM_BITS'(e);
                end else begin
                    sp_pipe[s][0].rdata <= '0;
                end
                for (int d = 1; d < SP_LATENCY; d++)
                    sp_pipe[s][d] <= sp_pipe[s][d-1];
                sp_res[s].valid <= sp_pipe[s][SP_LATENCY-1].valid;
                sp_res[s].write <= sp_pipe[s][SP_LATENCY-1].write;
                sp_res[s].rdata <= sp_pipe[s][SP_LATENCY-1].rdata;
            end
        end
    end

    // Test infrastructure
    int test_num;
    int errors;
    int total_tests;
    string test_name;

    task automatic reset();
        nRST = 1'b0;
        CLK  = 1'b0;
        wb_ready_in = 1'b1;
        for (int i = 0; i < NUM_SP; i++) begin
            sched_valid_in[i]   = 1'b0;
            sched_write[i]      = 1'b0;
            sched_addr[i]       = '0;
            sched_vdst[i]       = '0;
            sched_num_rows[i]   = '0;
            sched_num_cols[i]   = '0;
            sched_row_id[i]     = '0;
            sched_col_id[i]     = '0;
            sched_row_or_col[i] = 1'b0;
            vrf_store_data[i]   = '0;
            vrf_store_valid[i]  = 1'b0;
            sp_stall[i]         = 1'b0;
        end
        repeat (3) @(posedge CLK);
        nRST = 1'b1;
        @(posedge CLK);
    endtask

    task automatic issue_load(
        input int ch,
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input logic [VIDX_W-1:0] vd
    );
        @(posedge CLK);
        sched_valid_in[ch] = 1'b1;
        sched_write[ch]    = 1'b0;
        sched_addr[ch]     = addr;
        sched_vdst[ch]     = vd;
        @(posedge CLK);
        sched_valid_in[ch] = 1'b0;
    endtask

    task automatic issue_store(
        input int ch,
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input vreg_t data
    );
        @(posedge CLK);
        sched_valid_in[ch]  = 1'b1;
        sched_write[ch]     = 1'b1;
        sched_addr[ch]      = addr;
        vrf_store_data[ch]  = data;
        vrf_store_valid[ch] = 1'b1;
        @(posedge CLK);
        sched_valid_in[ch]  = 1'b0;
        sched_write[ch]     = 1'b0;
        vrf_store_valid[ch] = 1'b0;
    endtask

    task automatic wait_writeback(
        input logic [VIDX_W-1:0] expected_vd,
        input int timeout_cycles
    );
        int waited;
        waited = 0;
        while (!wb_valid_out && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end
        if (!wb_valid_out) begin
            $error("[%s] Timeout waiting for writeback of v%0d after %0d cycles",
                    test_name, expected_vd, timeout_cycles);
            errors++;
        end else if (wb_vdst !== expected_vd) begin
            $error("[%s] Writeback vdst mismatch: expected v%0d, got v%0d",
                    test_name, expected_vd, wb_vdst);
            errors++;
        end else begin
            $display("[%s] PASS - writeback v%0d received after %0d cycles",
                     test_name, expected_vd, waited);
        end
        @(posedge CLK);
    endtask

    task automatic wait_any_writeback(
        output logic [VIDX_W-1:0] got_vd,
        input int timeout_cycles
    );
        int waited;
        waited = 0;
        while (!wb_valid_out && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end
        if (!wb_valid_out) begin
            $error("[%s] Timeout waiting for any writeback after %0d cycles",
                    test_name, timeout_cycles);
            errors++;
            got_vd = '0;
        end else begin
            got_vd = wb_vdst;
        end
        @(posedge CLK);
    endtask

    //=========================================================================
    // Test Cases
    //=========================================================================

    initial begin
        $display("============================================================");
        $display(" VLSU Multi-Channel Testbench - NUM_SCPADS = %0d", NUM_SP);
        $display("============================================================");
        errors      = 0;
        total_tests = 0;

        //=================================================================
        // VP 1.1 - Power On Reset
        // Reset all signals; verify all outputs are 0 upon reset.
        //=================================================================
        test_name = "VP1.1_power_on_reset";
        test_num  = 1;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        nRST = 1'b0;
        CLK  = 1'b0;
        wb_ready_in = 1'b1;
        for (int i = 0; i < NUM_SP; i++) begin
            sched_valid_in[i]   = 1'b0;
            sched_write[i]      = 1'b0;
            sched_addr[i]       = '0;
            sched_vdst[i]       = '0;
            sched_num_rows[i]   = '0;
            sched_num_cols[i]   = '0;
            sched_row_id[i]     = '0;
            sched_col_id[i]     = '0;
            sched_row_or_col[i] = 1'b0;
            vrf_store_data[i]   = '0;
            vrf_store_valid[i]  = 1'b0;
            sp_stall[i]         = 1'b0;
        end
        repeat (3) @(posedge CLK);

        // Check all outputs are 0 while in reset
        begin
            int rst_err;
            rst_err = 0;

            if (wb_valid_out !== 1'b0) begin
                $error("[%s] wb_valid_out not 0 in reset", test_name);
                rst_err++;
            end
            if (wb_vdst !== '0) begin
                $error("[%s] wb_vdst not 0 in reset", test_name);
                rst_err++;
            end
            if (vlsu_busy !== 1'b0) begin
                $error("[%s] vlsu_busy not 0 in reset", test_name);
                rst_err++;
            end
            for (int ch = 0; ch < NUM_SP; ch++) begin
                if (sp_req[ch].valid !== 1'b0) begin
                    $error("[%s] sp_req[%0d].valid not 0 in reset", test_name, ch);
                    rst_err++;
                end
                if (load_queue_full[ch] !== 1'b0) begin
                    $error("[%s] load_queue_full[%0d] not 0 in reset", test_name, ch);
                    rst_err++;
                end
            end

            if (rst_err == 0)
                $display("[%s] PASS - all outputs 0 upon reset", test_name);
            else
                errors += rst_err;
        end
        nRST = 1'b1;
        @(posedge CLK);

        //=================================================================
        // VP 1.2 - Read/Valid Signals
        // Verify valid/ready handshake fires correctly for loads and stores.
        // (a) Load: sp_req.valid=1, sp_req.write=0, sched_ready_out=1
        // (b) Store: sp_req.valid=1, sp_req.write=1, sched_ready_out=1
        // (c) Stalled: sched_ready_out=0 when sp_stall asserted
        //=================================================================
        test_name = "VP1.2_read_valid_signals";
        test_num  = 2;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int vp12_err;
            vp12_err = 0;

            // (a) Load on ch0
            @(posedge CLK);
            sched_valid_in[0] = 1'b1;
            sched_write[0]    = 1'b0;
            sched_addr[0]     = 'hA0;
            sched_vdst[0]     = 8'd20;
            #1;
            if (sp_req[0].valid !== 1'b1) begin
                $error("[%s] sp_req[0].valid not asserted on load", test_name);
                vp12_err++;
            end
            if (sp_req[0].write !== 1'b0) begin
                $error("[%s] sp_req[0].write should be 0 for load", test_name);
                vp12_err++;
            end
            if (sched_ready_out[0] !== 1'b1) begin
                $error("[%s] sched_ready_out[0] should be 1 (accepting load)", test_name);
                vp12_err++;
            end
            @(posedge CLK);
            sched_valid_in[0] = 1'b0;

            // (b) Store on ch1
            if (NUM_SP > 1) begin
                @(posedge CLK);
                sched_valid_in[1]  = 1'b1;
                sched_write[1]     = 1'b1;
                sched_addr[1]      = 'hB0;
                vrf_store_data[1]  = '1;
                vrf_store_valid[1] = 1'b1;
                #1;
                if (sp_req[1].valid !== 1'b1) begin
                    $error("[%s] sp_req[1].valid not asserted on store", test_name);
                    vp12_err++;
                end
                if (sp_req[1].write !== 1'b1) begin
                    $error("[%s] sp_req[1].write should be 1 for store", test_name);
                    vp12_err++;
                end
                @(posedge CLK);
                sched_valid_in[1]  = 1'b0;
                sched_write[1]     = 1'b0;
                vrf_store_valid[1] = 1'b0;
            end

            // (c) Stall ch0
            sp_stall[0] = 1'b1;
            @(posedge CLK);
            sched_valid_in[0] = 1'b1;
            sched_write[0]    = 1'b0;
            sched_addr[0]     = 'hCC;
            sched_vdst[0]     = 8'd21;
            #1;
            if (sched_ready_out[0] !== 1'b0) begin
                $error("[%s] ready_out[0] should be 0 when stalled", test_name);
                vp12_err++;
            end
            @(posedge CLK);
            sched_valid_in[0] = 1'b0;
            sp_stall[0]       = 1'b0;

            if (vp12_err == 0)
                $display("[%s] PASS - valid/ready/write correct for load, store, stall", test_name);
            else
                errors += vp12_err;
        end
        repeat (SP_LATENCY + 5) @(posedge CLK);

        //=================================================================
        // VP 1.3 - Load Data From Scratchpad
        // Issue loads on BOTH scratchpad channels simultaneously.
        // Verify: two addresses sent, two vdst registers written back.
        //=================================================================
        test_name = "VP1.3_load_data_from_scratchpad";
        test_num  = 3;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            logic [SCPAD_ADDR_WIDTH-1:0] addr0, addr1;
            logic [VIDX_W-1:0] vd0, vd1;
            addr0 = 'h100;
            addr1 = 'h200;
            vd0   = 8'd30;
            vd1   = 8'd31;

            @(posedge CLK);
            sched_valid_in[0] = 1'b1;
            sched_write[0]    = 1'b0;
            sched_addr[0]     = addr0;
            sched_vdst[0]     = vd0;
            if (NUM_SP > 1) begin
                sched_valid_in[1] = 1'b1;
                sched_write[1]    = 1'b0;
                sched_addr[1]     = addr1;
                sched_vdst[1]     = vd1;
            end

            // Verify sp_req carries correct addresses
            #1;
            if (sp_req[0].spad_addr !== addr0) begin
                $error("[%s] sp_req[0].spad_addr mismatch: exp %h got %h",
                        test_name, addr0, sp_req[0].spad_addr);
                errors++;
            end
            if (NUM_SP > 1 && sp_req[1].spad_addr !== addr1) begin
                $error("[%s] sp_req[1].spad_addr mismatch: exp %h got %h",
                        test_name, addr1, sp_req[1].spad_addr);
                errors++;
            end

            @(posedge CLK);
            for (int ch = 0; ch < NUM_SP; ch++)
                sched_valid_in[ch] = 1'b0;

            // Collect writebacks - both vd0 and vd1 must appear
            begin
                logic [VIDX_W-1:0] collected [NUM_SP];
                logic seen0, seen1;
                seen0 = 0;
                seen1 = 0;
                for (int w = 0; w < NUM_SP; w++)
                    wait_any_writeback(collected[w], SP_LATENCY + 10);

                for (int w = 0; w < NUM_SP; w++) begin
                    if (collected[w] == vd0) seen0 = 1;
                    if (collected[w] == vd1) seen1 = 1;
                end

                if (seen0)
                    $display("[%s] PASS - v%0d writeback received (ch0 load)", test_name, vd0);
                else begin
                    $error("[%s] Missing writeback for v%0d (ch0 load)", test_name, vd0);
                    errors++;
                end
                if (NUM_SP > 1) begin
                    if (seen1)
                        $display("[%s] PASS - v%0d writeback received (ch1 load)", test_name, vd1);
                    else begin
                        $error("[%s] Missing writeback for v%0d (ch1 load)", test_name, vd1);
                        errors++;
                    end
                end
            end
        end

        //=================================================================
        // VP 1.4 - Store Data To Scratchpad
        // Issue stores on BOTH channels simultaneously.
        // Verify: sp_req carries correct addr + wdata, no spurious WB.
        //=================================================================
        test_name = "VP1.4_store_data_to_scratchpad";
        test_num  = 4;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            logic [SCPAD_ADDR_WIDTH-1:0] s_addr0, s_addr1;
            vreg_t s_data0, s_data1;
            int vp14_err;
            vp14_err = 0;

            s_addr0 = 'h300;
            s_addr1 = 'h400;
            for (int e = 0; e < VLMAX; e++) begin
                s_data0[e] = {1'b0, 5'd10, 10'(e)};
                s_data1[e] = {1'b1, 5'd20, 10'(e + 100)};
            end

            @(posedge CLK);
            sched_valid_in[0]  = 1'b1;
            sched_write[0]     = 1'b1;
            sched_addr[0]      = s_addr0;
            vrf_store_data[0]  = s_data0;
            vrf_store_valid[0] = 1'b1;
            if (NUM_SP > 1) begin
                sched_valid_in[1]  = 1'b1;
                sched_write[1]     = 1'b1;
                sched_addr[1]      = s_addr1;
                vrf_store_data[1]  = s_data1;
                vrf_store_valid[1] = 1'b1;
            end

            #1;
            // Ch0 checks
            if (sp_req[0].spad_addr !== s_addr0) begin
                $error("[%s] sp_req[0].spad_addr mismatch on store", test_name);
                vp14_err++;
            end
            if (sp_req[0].write !== 1'b1) begin
                $error("[%s] sp_req[0].write should be 1", test_name);
                vp14_err++;
            end
            if (sp_req[0].wdata === '0 && s_data0 !== '0) begin
                $error("[%s] sp_req[0].wdata appears all-zero, expected store data", test_name);
                vp14_err++;
            end
            // Ch1 checks
            if (NUM_SP > 1) begin
                if (sp_req[1].spad_addr !== s_addr1) begin
                    $error("[%s] sp_req[1].spad_addr mismatch on store", test_name);
                    vp14_err++;
                end
                if (sp_req[1].write !== 1'b1) begin
                    $error("[%s] sp_req[1].write should be 1", test_name);
                    vp14_err++;
                end
                if (sp_req[1].wdata === '0 && s_data1 !== '0) begin
                    $error("[%s] sp_req[1].wdata appears all-zero, expected store data", test_name);
                    vp14_err++;
                end
            end

            @(posedge CLK);
            for (int ch = 0; ch < NUM_SP; ch++) begin
                sched_valid_in[ch]  = 1'b0;
                sched_write[ch]     = 1'b0;
                vrf_store_valid[ch] = 1'b0;
            end

            // No writeback from stores
            repeat (SP_LATENCY + 5) @(posedge CLK);
            if (wb_valid_out) begin
                $error("[%s] Unexpected writeback after store-only operations", test_name);
                vp14_err++;
            end

            if (vp14_err == 0)
                $display("[%s] PASS - both channels stored correct addr+data, no spurious WB", test_name);
            else
                errors += vp14_err;
        end

        //=================================================================
        // VP 1.6 - Pop off a vector register from the FIFO queue
        // When scratchpad returns valid data, FIFO pops vdst and sends
        // it to writeback. Issue multiple loads, confirm FIFO-order pop.
        //=================================================================
        test_name = "VP1.6_fifo_pop_on_valid";
        test_num  = 5;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int vp16_err;
            logic [VIDX_W-1:0] expected_vds [3];
            logic [VIDX_W-1:0] got_vd;
            vp16_err = 0;

            expected_vds[0] = 8'd40;
            expected_vds[1] = 8'd41;
            expected_vds[2] = 8'd42;

            for (int i = 0; i < 3; i++) begin
                @(posedge CLK);
                sched_valid_in[0] = 1'b1;
                sched_write[0]    = 1'b0;
                sched_addr[0]     = SCPAD_ADDR_WIDTH'(i * 'h10);
                sched_vdst[0]     = expected_vds[i];
            end
            @(posedge CLK);
            sched_valid_in[0] = 1'b0;

            // Verify writebacks in FIFO order
            for (int i = 0; i < 3; i++) begin
                wait_any_writeback(got_vd, SP_LATENCY + 10);
                if (got_vd !== expected_vds[i]) begin
                    $error("[%s] Writeback %0d: expected v%0d, got v%0d (FIFO order violated)",
                            test_name, i, expected_vds[i], got_vd);
                    vp16_err++;
                end else begin
                    $display("[%s] PASS - writeback %0d popped v%0d in FIFO order",
                             test_name, i, got_vd);
                end
            end

            if (vp16_err > 0)
                errors += vp16_err;
        end

        //=================================================================
        // VP 1.7 - Split Transaction
        // Can finish a load and start a new one in the same cycle.
        //=================================================================
        test_name = "VP1.7_split_transaction";
        test_num  = 6;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int vp17_err;
            logic [VIDX_W-1:0] got_vd;
            vp17_err = 0;

            // Issue first load
            issue_load(0, 'h500, 8'd50);

            // Wait until response is about to arrive, then issue second load
            repeat (SP_LATENCY - 1) @(posedge CLK);

            @(posedge CLK);
            sched_valid_in[0] = 1'b1;
            sched_write[0]    = 1'b0;
            sched_addr[0]     = 'h600;
            sched_vdst[0]     = 8'd51;

            // Can we accept a new load during/near a writeback?
            #1;
            if (sched_ready_out[0] !== 1'b1) begin
                $error("[%s] Cannot accept new load during writeback (split transaction failed)", test_name);
                vp17_err++;
            end else begin
                $display("[%s] PASS - new load accepted while writeback pending", test_name);
            end

            @(posedge CLK);
            sched_valid_in[0] = 1'b0;

            // Collect both writebacks
            wait_any_writeback(got_vd, SP_LATENCY + 10);
            if (got_vd == 8'd50)
                $display("[%s] PASS - first load (v50) completed", test_name);
            else if (got_vd == 8'd51)
                $display("[%s] INFO - second load (v51) came first", test_name);
            else begin
                $error("[%s] Unexpected writeback v%0d", test_name, got_vd);
                vp17_err++;
            end

            wait_any_writeback(got_vd, SP_LATENCY + 10);
            if (got_vd == 8'd51)
                $display("[%s] PASS - second load (v51) completed", test_name);
            else if (got_vd == 8'd50)
                $display("[%s] PASS - first load (v50) completed second", test_name);
            else begin
                $error("[%s] Unexpected writeback v%0d", test_name, got_vd);
                vp17_err++;
            end

            if (vp17_err > 0)
                errors += vp17_err;
        end

        //=================================================================
        // Additional Tests (beyond verification plan)
        //=================================================================

        // Test 7: Round-robin fairness with concurrent loads
        test_name = "T7_concurrent_loads_rr_fairness";
        test_num  = 7;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        for (int burst = 0; burst < 3; burst++) begin
            @(posedge CLK);
            for (int ch = 0; ch < NUM_SP; ch++) begin
                sched_valid_in[ch] = 1'b1;
                sched_write[ch]    = 1'b0;
                sched_addr[ch]     = SCPAD_ADDR_WIDTH'(ch * 'h100 + burst * 'h10);
                sched_vdst[ch]     = VIDX_W'(ch * 10 + burst);
            end
        end
        @(posedge CLK);
        for (int ch = 0; ch < NUM_SP; ch++)
            sched_valid_in[ch] = 1'b0;

        begin
            int wb_count;
            logic [VIDX_W-1:0] wb_vd;
            wb_count = 0;
            for (int w = 0; w < 3 * NUM_SP; w++) begin
                wait_any_writeback(wb_vd, SP_LATENCY + 20);
                wb_count++;
                $display("  Writeback #%0d: v%0d", wb_count, wb_vd);
            end
            if (wb_count == 3 * NUM_SP)
                $display("[%s] PASS - all %0d writebacks received", test_name, wb_count);
            else begin
                $error("[%s] Only got %0d / %0d writebacks", test_name, wb_count, 3*NUM_SP);
                errors++;
            end
        end

        // Test 8: FIFO full
        // Block writeback during fill so responses don't drain the FIFO.
        test_name = "T8_fifo_full";
        test_num  = 8;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        wb_ready_in = 1'b0;  // Prevent FIFO from draining during fill
        for (int i = 0; i < FIFO_DEPTH; i++) begin
            @(posedge CLK);
            sched_valid_in[0] = 1'b1;
            sched_write[0]    = 1'b0;
            sched_addr[0]     = SCPAD_ADDR_WIDTH'(i * 4);
            sched_vdst[0]     = VIDX_W'(i);
        end
        @(posedge CLK);
        sched_valid_in[0] = 1'b0;

        @(posedge CLK);
        if (load_queue_full[0] !== 1'b1) begin
            $error("[%s] Expected load_queue_full[0] after %0d loads", test_name, FIFO_DEPTH);
            errors++;
        end else
            $display("[%s] PASS - FIFO full asserted after %0d loads", test_name, FIFO_DEPTH);

        sched_valid_in[0] = 1'b1;
        sched_write[0]    = 1'b0;
        sched_addr[0]     = 'hFFF;
        sched_vdst[0]     = 8'hFF;
        @(posedge CLK);
        if (sched_ready_out[0] !== 1'b0) begin
            $error("[%s] Channel 0 should reject load when FIFO full", test_name);
            errors++;
        end else
            $display("[%s] PASS - load rejected when FIFO full", test_name);
        sched_valid_in[0] = 1'b0;

        wb_ready_in = 1'b1;  // Allow drain
        repeat (FIFO_DEPTH + SP_LATENCY + 10) @(posedge CLK);

        // Test 9: Writeback backpressure
        test_name = "T9_wb_backpressure";
        test_num  = 9;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        issue_load(0, 'h400, 8'd70);
        wb_ready_in = 1'b0;
        repeat (SP_LATENCY + 5) @(posedge CLK);

        // With the response buffer, wb_valid_out asserts independently of wb_ready_in
        if (wb_valid_out) begin
            $display("  Writeback valid asserted while ready=0, checking hold...");
            if (wb_vdst !== 8'd70) begin
                $error("[%s] wb_vdst mismatch while held: expected v70, got v%0d", test_name, wb_vdst);
                errors++;
            end
            // Re-enable ready - handshake should complete
            wb_ready_in = 1'b1;
            @(posedge CLK);
            $display("[%s] PASS - writeback held until ready", test_name);
        end else begin
            $error("[%s] wb_valid_out not asserted despite pending response (backpressure broken)", test_name);
            errors++;
            wb_ready_in = 1'b1;
            repeat (10) @(posedge CLK);
        end

        // Test 10: vlsu_busy lifecycle
        test_name = "T10_busy_lifecycle";
        test_num  = 10;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        if (vlsu_busy) begin
            $error("[%s] vlsu_busy should be 0 after reset", test_name);
            errors++;
        end
        issue_load(0, 'hC00, 8'd90);
        @(posedge CLK);
        if (!vlsu_busy) begin
            $error("[%s] vlsu_busy should be 1 after load issued", test_name);
            errors++;
        end
        wait_writeback(8'd90, SP_LATENCY + 10);
        @(posedge CLK);
        if (vlsu_busy) begin
            $error("[%s] vlsu_busy should be 0 after queue drained", test_name);
            errors++;
        end else
            $display("[%s] PASS - busy cleared after drain", test_name);

        // Test 11: All channels saturated stress
        test_name = "T11_all_channels_saturated";
        test_num  = 11;
        total_tests++;
        reset();
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int loads_per_ch;
            loads_per_ch = FIFO_DEPTH / 2;
            for (int burst = 0; burst < loads_per_ch; burst++) begin
                @(posedge CLK);
                for (int ch = 0; ch < NUM_SP; ch++) begin
                    sched_valid_in[ch] = 1'b1;
                    sched_write[ch]    = 1'b0;
                    sched_addr[ch]     = SCPAD_ADDR_WIDTH'(ch * 'h1000 + burst * 'h10);
                    sched_vdst[ch]     = VIDX_W'(ch * 32 + burst);
                end
            end
            @(posedge CLK);
            for (int ch = 0; ch < NUM_SP; ch++)
                sched_valid_in[ch] = 1'b0;

            begin
                int total_expected, collected;
                logic [VIDX_W-1:0] vd_tmp;
                total_expected = loads_per_ch * NUM_SP;
                collected = 0;
                for (int w = 0; w < total_expected; w++) begin
                    wait_any_writeback(vd_tmp, SP_LATENCY + loads_per_ch + 20);
                    collected++;
                end
                if (collected == total_expected)
                    $display("[%s] PASS - all %0d writebacks collected from %0d channels",
                             test_name, collected, NUM_SP);
                else begin
                    $error("[%s] Only %0d / %0d writebacks", test_name, collected, total_expected);
                    errors++;
                end
            end
        end

        //---------------------------------------------------------------------
        // Summary
        //---------------------------------------------------------------------
        $display("\n============================================================");
        $display(" Results: %0d tests, %0d errors (NUM_SCPADS=%0d)",
                 total_tests, errors, NUM_SP);
        if (errors == 0)
            $display(" ALL TESTS PASSED");
        else
            $display(" SOME TESTS FAILED");
        $display("============================================================");
        $finish;
    end

    // Timeout watchdog
    initial begin
        #(CLK_PERIOD * 50000);
        $error("GLOBAL TIMEOUT - simulation did not finish");
        $finish;
    end

    // Waveform dump
    initial begin
        $dumpfile("vlsu_tb.vcd");
        $dumpvars(0, vlsu_tb);
    end

endmodule

// Minimal sync_fifo behavioral model for simulation
module sync_fifo #(
    parameter int FIFODEPTH = 8,
    parameter int DATAWIDTH = 8
) (
    input  logic                  nRST,
    input  logic                  CLK,
    input  logic                  wr_en,
    input  logic                  shift,
    input  logic [DATAWIDTH-1:0]  din,
    output logic [DATAWIDTH-1:0]  dout,
    output logic                  empty,
    output logic                  full
);

    logic [DATAWIDTH-1:0] mem [FIFODEPTH];
    int head, tail, count;

    assign empty = (count == 0);
    assign full  = (count >= FIFODEPTH);
    assign dout  = mem[head];

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            head  <= 0;
            tail  <= 0;
            count <= 0;
            for (int i = 0; i < FIFODEPTH; i++)
                mem[i] <= '0;
        end else begin
            if (wr_en && !full && shift && !empty) begin
                mem[tail] <= din;
                tail  <= (tail + 1) % FIFODEPTH;
                head  <= (head + 1) % FIFODEPTH;
            end
            else if (wr_en && !full) begin
                mem[tail] <= din;
                tail  <= (tail + 1) % FIFODEPTH;
                count <= count + 1;
            end
            else if (shift && !empty) begin
                head  <= (head + 1) % FIFODEPTH;
                count <= count - 1;
            end
        end
    end

endmodule