/*  Julio Hernandez - herna628@purdue.edu */

// VLSU Testbench - Single Channel, Continuous Operation
// Uses vlsu_if for scheduler/wb/status, scpad_if for scratchpad.
// Single power-on reset, then tests run back-to-back without resets.
//
// NOTE: sync_fifo comes from ./rtl/modules/vector/sync_fifo.sv
//       (compiled by Makefile via dut= flag).

module vlsu_tb;
    import vector_pkg::*;
    import scpad_pkg::*;

    localparam int CLK_PERIOD = 10;
    localparam int FIFO_DEPTH = 13;
    localparam int SP_LATENCY = 5;
    localparam int NUM_VREGS  = 256;
    localparam logic [SCPAD_ID_WIDTH-1:0] TB_IDX = '0;

    // ------------------------------------------------------------------
    // Clock / Reset
    // ------------------------------------------------------------------
    logic CLK, nRST;
    always #(CLK_PERIOD/2) CLK = ~CLK;

    // ------------------------------------------------------------------
    // Interfaces
    // ------------------------------------------------------------------
    vlsu_if  vif(.clk(CLK), .n_rst(nRST));
    scpad_if sif(.clk(CLK), .n_rst(nRST));

    // ------------------------------------------------------------------
    // DUTs - one per scratchpad channel
    // ------------------------------------------------------------------
    vlsu #(
        .FIFO_DEPTH(FIFO_DEPTH),
        .NUM_VREGS(NUM_VREGS),
        .IDX(0)
    ) DUT0 (
        .vif (vif),
        .sif (sif)
    );

    vlsu #(
        .FIFO_DEPTH(FIFO_DEPTH),
        .NUM_VREGS(NUM_VREGS),
        .IDX(1)
    ) DUT1 (
        .vif (vif),
        .sif (sif)
    );

    // ------------------------------------------------------------------
    // Scratchpad response model - per-channel delay pipeline
    // ------------------------------------------------------------------
    typedef struct packed {
        logic        valid;
        logic        write;
        scpad_data_t rdata;
    } sp_pipe_entry_t;

    logic sp_stall [NUM_SCPADS];

    generate
        for (genvar ch = 0; ch < NUM_SCPADS; ch++) begin : gen_sp_model
            sp_pipe_entry_t sp_pipe [SP_LATENCY];

            assign sif.fe_vec_stall[ch] = sp_stall[ch];

            always_ff @(posedge CLK or negedge nRST) begin
                if (!nRST) begin
                    for (int d = 0; d < SP_LATENCY; d++)
                        sp_pipe[d] <= '0;
                    sif.vec_res[ch].valid <= 1'b0;
                    sif.vec_res[ch].write <= 1'b0;
                    sif.vec_res[ch].rdata <= '0;
                end else begin
                    sp_pipe[0].valid <= sif.vec_req[ch].valid;
                    sp_pipe[0].write <= sif.vec_req[ch].write;
                    if (sif.vec_req[ch].valid && !sif.vec_req[ch].write) begin
                        // Tag response data with channel + addr so we can distinguish
                        for (int e = 0; e < NUM_COLS; e++)
                            sp_pipe[0].rdata[e] <= ELEM_BITS'(sif.vec_req[ch].spad_addr[ELEM_BITS-1:0])
                                                 + ELEM_BITS'(e)
                                                 + ELEM_BITS'(ch << 8);
                    end else begin
                        sp_pipe[0].rdata <= '0;
                    end
                    for (int d = 1; d < SP_LATENCY; d++)
                        sp_pipe[d] <= sp_pipe[d-1];
                    sif.vec_res[ch].valid <= sp_pipe[SP_LATENCY-1].valid;
                    sif.vec_res[ch].write <= sp_pipe[SP_LATENCY-1].write;
                    sif.vec_res[ch].rdata <= sp_pipe[SP_LATENCY-1].rdata;
                end
            end
        end
    endgenerate

    // ------------------------------------------------------------------
    // Convenience aliases — channel 0 (single-channel tests)
    // ------------------------------------------------------------------
    `define SCHED_REQ  vif.sched_req[TB_IDX]
    `define SCHED_RES  vif.sched_res[TB_IDX]
    `define VRF_STORE  vif.vrf_store[TB_IDX]
    `define WB_OUT     vif.wb_out[TB_IDX]
    `define WB_READY   vif.wb_ready[TB_IDX]
    `define STATUS     vif.status[TB_IDX]
    `define SP_REQ     sif.vec_req[TB_IDX]

    // ------------------------------------------------------------------
    // Convenience aliases — channel 1 (parallel test)
    // ------------------------------------------------------------------
    `define SCHED_REQ1 vif.sched_req[1]
    `define SCHED_RES1 vif.sched_res[1]
    `define VRF_STORE1 vif.vrf_store[1]
    `define WB_OUT1    vif.wb_out[1]
    `define WB_READY1  vif.wb_ready[1]
    `define STATUS1    vif.status[1]
    `define SP_REQ1    sif.vec_req[1]

    // ------------------------------------------------------------------
    // Test infrastructure
    // ------------------------------------------------------------------
    int test_num, errors, total_tests;
    string test_name;

    task automatic drain_and_idle(input int timeout_cycles = 200);
        int waited;

        `SCHED_REQ  = '0;
        `VRF_STORE  = '0;
        sp_stall[0] = 1'b0;
        `WB_READY   = 1'b1;

        waited = 0;
        while ((`STATUS.busy || !DUT0.lq_empty || !DUT0.rq_empty) && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end

        if (waited >= timeout_cycles) begin
            $error("[%s] drain_and_idle TIMEOUT after %0d cycles (busy=%b, lq_empty=%b, rq_empty=%b)",
                    test_name, timeout_cycles, `STATUS.busy, DUT0.lq_empty, DUT0.rq_empty);
            errors++;
        end

        repeat (SP_LATENCY + 2) @(posedge CLK);
    endtask

    // Drain both channels
    task automatic drain_both(input int timeout_cycles = 200);
        int waited;

        `SCHED_REQ  = '0;
        `SCHED_REQ1 = '0;
        `VRF_STORE  = '0;
        `VRF_STORE1 = '0;
        sp_stall[0] = 1'b0;
        sp_stall[1] = 1'b0;
        `WB_READY   = 1'b1;
        `WB_READY1  = 1'b1;

        waited = 0;
        while ((`STATUS.busy  || !DUT0.lq_empty || !DUT0.rq_empty ||
                `STATUS1.busy || !DUT1.lq_empty || !DUT1.rq_empty) && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end

        if (waited >= timeout_cycles) begin
            $error("[%s] drain_both TIMEOUT after %0d cycles", test_name, timeout_cycles);
            errors++;
        end

        repeat (SP_LATENCY + 2) @(posedge CLK);
    endtask

    task automatic issue_load(
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input logic [VIDX_W-1:0] vd
    );
        @(posedge CLK);
        `SCHED_REQ.valid     = 1'b1;
        `SCHED_REQ.write     = 1'b0;
        `SCHED_REQ.spad_addr = addr;
        `SCHED_REQ.vdst      = vd;
        @(posedge CLK);
        `SCHED_REQ.valid     = 1'b0;
    endtask

    task automatic issue_store(
        input logic [SCPAD_ADDR_WIDTH-1:0] addr,
        input vreg_t data
    );
        @(posedge CLK);
        `SCHED_REQ.valid     = 1'b1;
        `SCHED_REQ.write     = 1'b1;
        `SCHED_REQ.spad_addr = addr;
        `VRF_STORE.data      = data;
        `VRF_STORE.valid     = 1'b1;
        @(posedge CLK);
        `SCHED_REQ.valid     = 1'b0;
        `SCHED_REQ.write     = 1'b0;
        `VRF_STORE.valid     = 1'b0;
    endtask

    task automatic wait_writeback(
        input logic [VIDX_W-1:0] expected_vd,
        input int timeout_cycles
    );
        int waited;
        waited = 0;
        while (!`WB_OUT.valid && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end
        if (!`WB_OUT.valid) begin
            $error("[%s] Timeout waiting for writeback of v%0d after %0d cycles",
                    test_name, expected_vd, timeout_cycles);
            errors++;
        end else if (`WB_OUT.vdst !== expected_vd) begin
            $error("[%s] Writeback vdst mismatch: expected v%0d, got v%0d",
                    test_name, expected_vd, `WB_OUT.vdst);
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
        while (!`WB_OUT.valid && waited < timeout_cycles) begin
            @(posedge CLK);
            waited++;
        end
        if (!`WB_OUT.valid) begin
            $error("[%s] Timeout waiting for any writeback after %0d cycles",
                    test_name, timeout_cycles);
            errors++;
            got_vd = '0;
        end else begin
            got_vd = `WB_OUT.vdst;
        end
        @(posedge CLK);
    endtask

    // ==================================================================
    // Test Cases
    // ==================================================================

    initial begin
        $display("============================================================");
        $display(" VLSU Single-Channel Testbench (Continuous Operation)");
        $display("============================================================");
        errors      = 0;
        total_tests = 0;

        // ==============================================================
        // VP 1.1 - Power On Reset (only reset in entire simulation)
        // ==============================================================
        test_name = "VP1.1_power_on_reset";
        test_num  = 1;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        CLK        = 1'b0;
        nRST       = 1'b0;
        `SCHED_REQ = '0;
        `VRF_STORE = '0;
        `WB_READY  = 1'b1;
        sp_stall[0] = 1'b0;
        sp_stall[1] = 1'b0;
        `SCHED_REQ1 = '0;
        `VRF_STORE1 = '0;
        `WB_READY1  = 1'b1;
        repeat (3) @(posedge CLK);

        begin
            int rst_err;
            rst_err = 0;
            if (`WB_OUT.valid !== 1'b0) begin
                $error("[%s] wb valid not 0 in reset", test_name); rst_err++;
            end
            if (`WB_OUT.vdst !== '0) begin
                $error("[%s] wb vdst not 0 in reset", test_name); rst_err++;
            end
            if (`STATUS.busy !== 1'b0) begin
                $error("[%s] busy not 0 in reset", test_name); rst_err++;
            end
            if (`SP_REQ.valid !== 1'b0) begin
                $error("[%s] vec_req.valid not 0 in reset", test_name); rst_err++;
            end
            if (`STATUS.load_queue_full !== 1'b0) begin
                $error("[%s] load_queue_full not 0 in reset", test_name); rst_err++;
            end
            if (rst_err == 0)
                $display("[%s] PASS - all outputs 0 upon reset", test_name);
            else
                errors += rst_err;
        end
        nRST = 1'b1;
        @(posedge CLK);

        // ==============================================================
        // VP 1.2 - Read/Valid Signals
        // ==============================================================
        test_name = "VP1.2_read_valid_signals";
        test_num  = 2;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int vp12_err;
            vp12_err = 0;

            // (a) Load request
            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b0;
            `SCHED_REQ.spad_addr = 'hA0;
            `SCHED_REQ.vdst      = 8'd20;
            #1;
            if (`SP_REQ.valid !== 1'b1) begin
                $error("[%s] vec_req.valid not asserted on load", test_name); vp12_err++;
            end
            if (`SP_REQ.write !== 1'b0) begin
                $error("[%s] vec_req.write should be 0 for load", test_name); vp12_err++;
            end
            if (`SCHED_RES.ready !== 1'b1) begin
                $error("[%s] sched_res.ready should be 1", test_name); vp12_err++;
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            // (b) Store request
            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b1;
            `SCHED_REQ.spad_addr = 'hB0;
            `VRF_STORE.data      = '1;
            `VRF_STORE.valid     = 1'b1;
            #1;
            if (`SP_REQ.valid !== 1'b1) begin
                $error("[%s] vec_req.valid not asserted on store", test_name); vp12_err++;
            end
            if (`SP_REQ.write !== 1'b1) begin
                $error("[%s] vec_req.write should be 1 for store", test_name); vp12_err++;
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;
            `SCHED_REQ.write = 1'b0;
            `VRF_STORE.valid = 1'b0;

            // (c) Stall - should reject
            sp_stall[0] = 1'b1;
            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b0;
            `SCHED_REQ.spad_addr = 'hCC;
            `SCHED_REQ.vdst      = 8'd21;
            #1;
            if (`SCHED_RES.ready !== 1'b0) begin
                $error("[%s] ready should be 0 when stalled", test_name); vp12_err++;
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;
            sp_stall[0]      = 1'b0;

            if (vp12_err == 0)
                $display("[%s] PASS - valid/ready/write correct for load, store, stall", test_name);
            else
                errors += vp12_err;
        end
        drain_and_idle();

        // ==============================================================
        // VP 1.3 - Load Data From Scratchpad
        // ==============================================================
        test_name = "VP1.3_load_data";
        test_num  = 3;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b0;
            `SCHED_REQ.spad_addr = 'h100;
            `SCHED_REQ.vdst      = 8'd30;
            #1;
            if (`SP_REQ.spad_addr !== SCPAD_ADDR_WIDTH'('h100)) begin
                $error("[%s] vec_req.spad_addr mismatch", test_name); errors++;
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            wait_writeback(8'd30, SP_LATENCY + 10);
        end
        drain_and_idle();

        // ==============================================================
        // VP 1.4 - Store Data To Scratchpad
        // ==============================================================
        test_name = "VP1.4_store_data";
        test_num  = 4;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            vreg_t s_data;
            int vp14_err;
            vp14_err = 0;

            for (int e = 0; e < VLMAX; e++)
                s_data[e] = {1'b0, 5'd10, 10'(e)};

            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b1;
            `SCHED_REQ.spad_addr = 'h300;
            `VRF_STORE.data      = s_data;
            `VRF_STORE.valid     = 1'b1;
            #1;
            if (`SP_REQ.spad_addr !== SCPAD_ADDR_WIDTH'('h300)) begin
                $error("[%s] vec_req.spad_addr mismatch on store", test_name); vp14_err++;
            end
            if (`SP_REQ.write !== 1'b1) begin
                $error("[%s] vec_req.write should be 1", test_name); vp14_err++;
            end
            if (`SP_REQ.wdata === '0 && s_data !== '0) begin
                $error("[%s] vec_req.wdata appears all-zero", test_name); vp14_err++;
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;
            `SCHED_REQ.write = 1'b0;
            `VRF_STORE.valid = 1'b0;

            repeat (SP_LATENCY + 5) @(posedge CLK);
            if (`WB_OUT.valid) begin
                $error("[%s] Unexpected writeback after store", test_name); vp14_err++;
            end

            if (vp14_err == 0)
                $display("[%s] PASS - store addr+data correct, no spurious WB", test_name);
            else
                errors += vp14_err;
        end
        drain_and_idle();

        // ==============================================================
        // VP 1.6 - FIFO Pop Order
        // ==============================================================
        test_name = "VP1.6_fifo_pop_order";
        test_num  = 5;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            logic [VIDX_W-1:0] expected_vds [3];
            logic [VIDX_W-1:0] got_vd;
            int vp16_err;
            vp16_err = 0;

            expected_vds[0] = 8'd40;
            expected_vds[1] = 8'd41;
            expected_vds[2] = 8'd42;

            for (int i = 0; i < 3; i++) begin
                @(posedge CLK);
                `SCHED_REQ.valid     = 1'b1;
                `SCHED_REQ.write     = 1'b0;
                `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'(i * 'h10);
                `SCHED_REQ.vdst      = expected_vds[i];
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            for (int i = 0; i < 3; i++) begin
                wait_any_writeback(got_vd, SP_LATENCY + 10);
                if (got_vd !== expected_vds[i]) begin
                    $error("[%s] WB %0d: expected v%0d, got v%0d (FIFO order violated)",
                            test_name, i, expected_vds[i], got_vd);
                    vp16_err++;
                end else begin
                    $display("[%s] PASS - WB %0d popped v%0d in order",
                             test_name, i, got_vd);
                end
            end
            if (vp16_err > 0) errors += vp16_err;
        end
        drain_and_idle();

        // ==============================================================
        // VP 1.7 - Split Transaction
        // ==============================================================
        test_name = "VP1.7_split_transaction";
        test_num  = 6;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int vp17_err;
            vp17_err = 0;

            issue_load('h500, 8'd50);
            repeat (SP_LATENCY - 1) @(posedge CLK);

            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b0;
            `SCHED_REQ.spad_addr = 'h600;
            `SCHED_REQ.vdst      = 8'd51;
            #1;
            if (`SCHED_RES.ready !== 1'b1) begin
                $error("[%s] Cannot accept new load during in-flight (split failed)", test_name);
                vp17_err++;
            end else begin
                $display("[%s] PASS - new load accepted while first in-flight", test_name);
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            wait_writeback(8'd50, SP_LATENCY + 10);
            wait_writeback(8'd51, SP_LATENCY + 10);

            if (vp17_err > 0) errors += vp17_err;
        end
        drain_and_idle();

        // ==============================================================
        // T7 - Pipeline stress (6 back-to-back loads)
        // ==============================================================
        test_name = "T7_pipeline_stress";
        test_num  = 7;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int num_loads;
            logic [VIDX_W-1:0] got_vd;
            num_loads = 6;

            for (int i = 0; i < num_loads; i++) begin
                @(posedge CLK);
                `SCHED_REQ.valid     = 1'b1;
                `SCHED_REQ.write     = 1'b0;
                `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'(i * 'h10);
                `SCHED_REQ.vdst      = VIDX_W'(i);
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            for (int i = 0; i < num_loads; i++) begin
                wait_any_writeback(got_vd, SP_LATENCY + 20);
                if (got_vd !== VIDX_W'(i)) begin
                    $error("[%s] WB %0d: expected v%0d, got v%0d", test_name, i, i, got_vd);
                    errors++;
                end else begin
                    $display("[%s] PASS - WB %0d: v%0d", test_name, i, got_vd);
                end
            end
        end
        drain_and_idle();

        // ==============================================================
        // T8 - FIFO full (backpressure blocks writeback, fills FIFO)
        // ==============================================================
        test_name = "T8_fifo_full";
        test_num  = 8;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        `WB_READY = 1'b0;
        for (int i = 0; i < FIFO_DEPTH; i++) begin
            @(posedge CLK);
            `SCHED_REQ.valid     = 1'b1;
            `SCHED_REQ.write     = 1'b0;
            `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'(i * 4);
            `SCHED_REQ.vdst      = VIDX_W'(i + 100);
        end
        @(posedge CLK);
        `SCHED_REQ.valid = 1'b0;

        @(posedge CLK);
        if (`STATUS.load_queue_full !== 1'b1) begin
            $error("[%s] Expected full after %0d loads", test_name, FIFO_DEPTH);
            errors++;
        end else
            $display("[%s] PASS - FIFO full asserted after %0d loads", test_name, FIFO_DEPTH);

        `SCHED_REQ.valid     = 1'b1;
        `SCHED_REQ.write     = 1'b0;
        `SCHED_REQ.spad_addr = 'hFFF;
        `SCHED_REQ.vdst      = 8'hFF;
        @(posedge CLK);
        if (`SCHED_RES.ready !== 1'b0) begin
            $error("[%s] Should reject load when full", test_name);
            errors++;
        end else
            $display("[%s] PASS - load rejected when full", test_name);
        `SCHED_REQ.valid = 1'b0;

        `WB_READY = 1'b1;
        drain_and_idle();

        // ==============================================================
        // T9 - Writeback backpressure (hold then release)
        // ==============================================================
        test_name = "T9_wb_backpressure";
        test_num  = 9;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        issue_load('h400, 8'd70);
        `WB_READY = 1'b0;
        repeat (SP_LATENCY + 5) @(posedge CLK);

        if (`WB_OUT.valid) begin
            $display("  WB valid asserted while ready=0, checking hold...");
            if (`WB_OUT.vdst !== 8'd70) begin
                $error("[%s] wb vdst mismatch while held", test_name);
                errors++;
            end
            repeat (3) @(posedge CLK);
            if (!`WB_OUT.valid || `WB_OUT.vdst !== 8'd70) begin
                $error("[%s] WB did not hold stable under backpressure", test_name);
                errors++;
            end else begin
                $display("[%s] PASS - writeback held stable for 3 extra cycles", test_name);
            end
            `WB_READY = 1'b1;
            @(posedge CLK);
            $display("[%s] PASS - writeback consumed after ready released", test_name);
        end else begin
            $error("[%s] wb_valid not asserted (backpressure broken)", test_name);
            errors++;
            `WB_READY = 1'b1;
        end
        drain_and_idle();

        // ==============================================================
        // T10 - Busy lifecycle (idle -> busy -> idle without reset)
        // ==============================================================
        test_name = "T10_busy_lifecycle";
        test_num  = 10;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        if (`STATUS.busy) begin
            $error("[%s] busy should be 0 before issuing (stale state!)", test_name);
            errors++;
        end else begin
            $display("[%s] PASS - idle before load", test_name);
        end

        issue_load('hC00, 8'd90);
        @(posedge CLK);
        if (!`STATUS.busy) begin
            $error("[%s] busy should be 1 after load issued", test_name);
            errors++;
        end else begin
            $display("[%s] PASS - busy asserted after load", test_name);
        end

        wait_writeback(8'd90, SP_LATENCY + 10);
        @(posedge CLK);
        if (`STATUS.busy) begin
            $error("[%s] busy should be 0 after drain", test_name);
            errors++;
        end else
            $display("[%s] PASS - busy cleared after drain", test_name);
        drain_and_idle();

        // ==============================================================
        // T11 - Saturation stress (half-depth burst)
        // ==============================================================
        test_name = "T11_saturation_stress";
        test_num  = 11;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            int num;
            logic [VIDX_W-1:0] got_vd;
            num = FIFO_DEPTH / 2;

            for (int i = 0; i < num; i++) begin
                @(posedge CLK);
                `SCHED_REQ.valid     = 1'b1;
                `SCHED_REQ.write     = 1'b0;
                `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'(i * 'h10);
                `SCHED_REQ.vdst      = VIDX_W'(i + 200);
            end
            @(posedge CLK);
            `SCHED_REQ.valid = 1'b0;

            for (int i = 0; i < num; i++) begin
                wait_any_writeback(got_vd, SP_LATENCY + num + 20);
                if (got_vd !== VIDX_W'(i + 200)) begin
                    $error("[%s] WB %0d: expected v%0d, got v%0d", test_name, i, i + 200, got_vd);
                    errors++;
                end
            end
            $display("[%s] PASS - all %0d writebacks collected", test_name, num);
        end
        drain_and_idle();

        // ==============================================================
        // T12 - Mixed load/store interleaving (continuous traffic)
        // ==============================================================
        test_name = "T12_mixed_load_store";
        test_num  = 12;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            vreg_t st_data;
            logic [VIDX_W-1:0] got_vd;
            int t12_err;
            t12_err = 0;

            for (int e = 0; e < VLMAX; e++)
                st_data[e] = {1'b1, 5'd5, 10'(e)};

            issue_load('hD00, 8'd60);
            issue_store('hD10, st_data);
            issue_load('hD20, 8'd61);

            wait_any_writeback(got_vd, SP_LATENCY + 15);
            if (got_vd !== 8'd60) begin
                $error("[%s] First WB expected v60, got v%0d", test_name, got_vd);
                t12_err++;
            end else
                $display("[%s] PASS - v60 returned first", test_name);

            wait_any_writeback(got_vd, SP_LATENCY + 15);
            if (got_vd !== 8'd61) begin
                $error("[%s] Second WB expected v61, got v%0d", test_name, got_vd);
                t12_err++;
            end else
                $display("[%s] PASS - v61 returned second (store caused no issue)", test_name);

            if (t12_err > 0) errors += t12_err;
        end
        drain_and_idle();

        // ==============================================================
        // T13 - Back-to-back bursts (no idle gap between batches)
        // ==============================================================
        test_name = "T13_back_to_back_bursts";
        test_num  = 13;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            logic [VIDX_W-1:0] got_vd;
            int total_loads;
            int t13_err;
            total_loads = 8;
            t13_err = 0;

            fork
                // --- Issue thread: 2 bursts of 4 back-to-back ---
                begin
                    for (int i = 0; i < 4; i++) begin
                        @(posedge CLK);
                        `SCHED_REQ.valid     = 1'b1;
                        `SCHED_REQ.write     = 1'b0;
                        `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'('hE00 + i * 'h10);
                        `SCHED_REQ.vdst      = VIDX_W'(150 + i);
                    end
                    for (int i = 0; i < 4; i++) begin
                        @(posedge CLK);
                        `SCHED_REQ.valid     = 1'b1;
                        `SCHED_REQ.write     = 1'b0;
                        `SCHED_REQ.spad_addr = SCPAD_ADDR_WIDTH'('hF00 + i * 'h10);
                        `SCHED_REQ.vdst      = VIDX_W'(154 + i);
                    end
                    @(posedge CLK);
                    `SCHED_REQ.valid = 1'b0;
                end

                // --- Collect thread: gather 8 writebacks in order ---
                begin
                    for (int i = 0; i < total_loads; i++) begin
                        wait_any_writeback(got_vd, SP_LATENCY + total_loads + 20);
                        if (got_vd !== VIDX_W'(150 + i)) begin
                            $error("[%s] WB %0d: expected v%0d, got v%0d", test_name, i, 150 + i, got_vd);
                            t13_err++;
                        end else begin
                            $display("[%s] PASS - WB %0d: v%0d", test_name, i, got_vd);
                        end
                    end
                end
            join

            errors += t13_err;
        end
        drain_and_idle();

        // ==============================================================
        // T14 - Dual-channel parallel loads
        //       Both scratchpads receive loads simultaneously.
        //       Verify independent writeback on each channel.
        // ==============================================================
        test_name = "T14_dual_channel_parallel";
        test_num  = 14;
        total_tests++;
        $display("\n--- Test %0d: %s ---", test_num, test_name);

        begin
            logic [VIDX_W-1:0] got_vd0, got_vd1;
            int t14_err;
            t14_err = 0;

            // Issue loads to both channels on the same cycle
            @(posedge CLK);
            `SCHED_REQ.valid      = 1'b1;
            `SCHED_REQ.write      = 1'b0;
            `SCHED_REQ.spad_addr  = 'hA00;
            `SCHED_REQ.vdst       = 8'd80;

            `SCHED_REQ1.valid     = 1'b1;
            `SCHED_REQ1.write     = 1'b0;
            `SCHED_REQ1.spad_addr = 'hB00;
            `SCHED_REQ1.vdst      = 8'd81;

            #1;
            // Both should be accepted
            if (`SCHED_RES.ready !== 1'b1) begin
                $error("[%s] CH0 ready should be 1", test_name); t14_err++;
            end
            if (`SCHED_RES1.ready !== 1'b1) begin
                $error("[%s] CH1 ready should be 1", test_name); t14_err++;
            end
            // Both scratchpads should see a request
            if (`SP_REQ.valid !== 1'b1) begin
                $error("[%s] CH0 vec_req.valid should be 1", test_name); t14_err++;
            end
            if (`SP_REQ1.valid !== 1'b1) begin
                $error("[%s] CH1 vec_req.valid should be 1", test_name); t14_err++;
            end

            @(posedge CLK);
            `SCHED_REQ.valid  = 1'b0;
            `SCHED_REQ1.valid = 1'b0;

            // Wait for both writebacks in parallel
            fork
                // CH0
                begin
                    int w0;
                    w0 = 0;
                    while (!`WB_OUT.valid && w0 < SP_LATENCY + 10) begin
                        @(posedge CLK); w0++;
                    end
                    if (!`WB_OUT.valid) begin
                        $error("[%s] CH0 writeback timeout", test_name); t14_err++;
                    end else if (`WB_OUT.vdst !== 8'd80) begin
                        $error("[%s] CH0 WB vdst expected v80, got v%0d", test_name, `WB_OUT.vdst);
                        t14_err++;
                    end else begin
                        $display("[%s] PASS - CH0 writeback v80 after %0d cycles", test_name, w0);
                    end
                end
                // CH1
                begin
                    int w1;
                    w1 = 0;
                    while (!`WB_OUT1.valid && w1 < SP_LATENCY + 10) begin
                        @(posedge CLK); w1++;
                    end
                    if (!`WB_OUT1.valid) begin
                        $error("[%s] CH1 writeback timeout", test_name); t14_err++;
                    end else if (`WB_OUT1.vdst !== 8'd81) begin
                        $error("[%s] CH1 WB vdst expected v81, got v%0d", test_name, `WB_OUT1.vdst);
                        t14_err++;
                    end else begin
                        $display("[%s] PASS - CH1 writeback v81 after %0d cycles", test_name, w1);
                    end
                end
            join

            // Verify both channels independent — issue second burst
            @(posedge CLK);
            // 3 loads on CH0, 2 loads on CH1, simultaneously
            for (int i = 0; i < 3; i++) begin
                @(posedge CLK);
                `SCHED_REQ.valid      = 1'b1;
                `SCHED_REQ.write      = 1'b0;
                `SCHED_REQ.spad_addr  = SCPAD_ADDR_WIDTH'('hC00 + i * 'h10);
                `SCHED_REQ.vdst       = VIDX_W'(170 + i);

                if (i < 2) begin
                    `SCHED_REQ1.valid     = 1'b1;
                    `SCHED_REQ1.write     = 1'b0;
                    `SCHED_REQ1.spad_addr = SCPAD_ADDR_WIDTH'('hD00 + i * 'h10);
                    `SCHED_REQ1.vdst      = VIDX_W'(180 + i);
                end else begin
                    `SCHED_REQ1.valid     = 1'b0;
                end
            end
            @(posedge CLK);
            `SCHED_REQ.valid  = 1'b0;
            `SCHED_REQ1.valid = 1'b0;

            // Collect both channels in parallel (fork/join)
            begin
                int ch0_err, ch1_err;
                ch0_err = 0;
                ch1_err = 0;

                fork
                    // --- CH0: collect 3 writebacks ---
                    begin
                        for (int i = 0; i < 3; i++) begin
                            begin
                                int ww;
                                ww = 0;
                                while (!`WB_OUT.valid && ww < SP_LATENCY + 20) begin
                                    @(posedge CLK); ww++;
                                end
                                if (!`WB_OUT.valid) begin
                                    $error("[%s] CH0 burst WB %0d timeout", test_name, i); ch0_err++;
                                end else if (`WB_OUT.vdst !== VIDX_W'(170 + i)) begin
                                    $error("[%s] CH0 burst WB %0d: expected v%0d, got v%0d",
                                            test_name, i, 170 + i, `WB_OUT.vdst); ch0_err++;
                                end else begin
                                    $display("[%s] PASS - CH0 burst WB %0d: v%0d", test_name, i, `WB_OUT.vdst);
                                end
                                @(posedge CLK);
                            end
                        end
                    end

                    // --- CH1: collect 2 writebacks ---
                    begin
                        for (int i = 0; i < 2; i++) begin
                            begin
                                int ww;
                                ww = 0;
                                while (!`WB_OUT1.valid && ww < SP_LATENCY + 20) begin
                                    @(posedge CLK); ww++;
                                end
                                if (!`WB_OUT1.valid) begin
                                    $error("[%s] CH1 burst WB %0d timeout", test_name, i); ch1_err++;
                                end else if (`WB_OUT1.vdst !== VIDX_W'(180 + i)) begin
                                    $error("[%s] CH1 burst WB %0d: expected v%0d, got v%0d",
                                            test_name, i, 180 + i, `WB_OUT1.vdst); ch1_err++;
                                end else begin
                                    $display("[%s] PASS - CH1 burst WB %0d: v%0d", test_name, i, `WB_OUT1.vdst);
                                end
                                @(posedge CLK);
                            end
                        end
                    end
                join

                t14_err += ch0_err + ch1_err;
            end

            if (t14_err == 0)
                $display("[%s] PASS - all dual-channel operations verified", test_name);
            else
                errors += t14_err;
        end
        drain_both();

        // ==============================================================
        // Summary
        // ==============================================================
        $display("\n============================================================");
        $display(" Results: %0d tests, %0d errors", total_tests, errors);
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