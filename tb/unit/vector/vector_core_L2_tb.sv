// ============================================================================
// vector_core_L2_tb.sv
// L2 Integration Testbench — DPI-C driven
//
// L2 replaces C++ models with real RTL:
//   Scheduler  → still C++ DPI (drives instructions)
//   Veggie     → still C++ DPI (VRF reads/writes)
//   Sysarr     → REAL RTL (sysarr_MEISSA_top)
//   Scratchpad → REAL RTL (scratchpad)
//
// DUT: vector_datapath + scratchpad + systolic_array
// Owner: Vedant Sharma
// ============================================================================

/*
L2 TB Notes:
- respond_vlsu() and respond_gsau() are GONE — real RTL handles it
- sysarr/scratchpad DPI init/destroy/tick are GONE
- DRAM interface tied off with controllable backpressure injection
- NUM_SCPADS = 4, all 4 VLSU ports cleared
- Element-by-element DPI for veggie (same as L1)
*/

`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module vector_core_L2_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;
    import inst_parser_dpi_pkg::*;

    // -----------------------------------------------------------------------
    // Parameters
    // -----------------------------------------------------------------------
    parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/add_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";

    // bp test for sys array works, there is a timeout from scheduler stalls and the NO OPs dont go thru so my cond in the all_issued doesnt work,
    // my termination cond didnt trigger causing the timeout, sys array works properly, need to fix the tb condition, but backpressure is now done for both spad and sys array
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_bp_test";
    // make drain 500 for sysarray bp test, 300 for gemm, 150 for reg.
    parameter int    DRAIN_CYCLES = 500;
    parameter int    TIMEOUT      = 10000;

    // -----------------------------------------------------------------------
    // Clock / Reset
    // -----------------------------------------------------------------------
    logic CLK;
    logic nRST;
    localparam int CLK_PERIOD = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    // -----------------------------------------------------------------------
    // Interfaces
    // -----------------------------------------------------------------------
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    // -----------------------------------------------------------------------
    // DUT: Vector Datapath
    // -----------------------------------------------------------------------
    vector_datapath dut (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    // -----------------------------------------------------------------------
    // L2: Real Scratchpad RTL
    // -----------------------------------------------------------------------
    scratchpad sp_inst (
        .sif(sif)
    );

    // -----------------------------------------------------------------------
    // L2: Real Systolic Array RTL
    // -----------------------------------------------------------------------
    sysarr_MEISSA_top sa_inst (
        .clk    (CLK),
        .nRST   (nRST),
        .gsau_if(gsauif)
    );

    // -----------------------------------------------------------------------
    // DRAM Tie-off (controllable for backpressure testing)
    // -----------------------------------------------------------------------
    logic dram_stall_inject [NUM_SCPADS];
    initial begin
        for (int i = 0; i < NUM_SCPADS; i++) dram_stall_inject[i] = 1'b0;
    end

    genvar dram_i;
    generate
        for (dram_i = 0; dram_i < NUM_SCPADS; dram_i++) begin : dram_tieoff
            assign sif.dram_be_stall[dram_i] = dram_stall_inject[dram_i];
            assign sif.dram_be_res[dram_i]   = '0;
        end
    endgenerate

    // -----------------------------------------------------------------------
    // Backpressure injection tasks
    // -----------------------------------------------------------------------
    task automatic inject_dram_backpressure(int port, int cycles);
        $display("[TB-BP] Injecting DRAM backpressure on port %0d for %0d cycles", port, cycles);
        dram_stall_inject[port] = 1'b1;
        repeat (cycles) @(posedge CLK);
        dram_stall_inject[port] = 1'b0;
        $display("[TB-BP] DRAM backpressure released on port %0d", port);
    endtask

    // -----------------------------------------------------------------------
    // Cycle counter
    // -----------------------------------------------------------------------
    int cycle_count;

    // -----------------------------------------------------------------------
    // Temp arrays for DPI vectors
    // -----------------------------------------------------------------------
    bit [15:0] tmp_vec  [0:31];
    bit [15:0] tmp_vec2 [0:31];

    // -----------------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------------
    function automatic vreg_t pack_vreg(bit [15:0] arr [0:31]);
        vreg_t v;
        for (int i = 0; i < 32; i++) v[i] = arr[i];
        return v;
    endfunction

    task automatic unpack_vreg(input vreg_t v, output bit [15:0] arr [0:31]);
        for (int i = 0; i < 32; i++) arr[i] = v[i];
    endtask

    // -----------------------------------------------------------------------
    // Clear tasks
    // -----------------------------------------------------------------------
    task automatic clear_lane_port(input int port);
        vif.lanes_in.lane_issue_ports[port].v1          = '0;
        vif.lanes_in.lane_issue_ports[port].v2          = '0;
        vif.lanes_in.lane_issue_ports[port].usel        = VALU;
        vif.lanes_in.lane_issue_ports[port].vd          = '0;
        vif.lanes_in.lane_issue_ports[port].rm          = 1'b0;
        vif.lanes_in.lane_issue_ports[port].mask        = '0;
        vif.lanes_in.lane_issue_ports[port].alu_op      = ALU_ADD;
        vif.lanes_in.lane_issue_ports[port].input_valid = 1'b0;
    endtask

    task automatic clear_gsau_port();
        vif.gsau_in.veg_vdata1 = '0;
        vif.gsau_in.veg_vdata2 = '0;
        vif.gsau_in.vd         = '0;
        vif.gsau_in.valid_in   = 1'b0;
        vif.gsau_in.weight     = 1'b0;
    endtask

    task automatic clear_vlsu_port(input int port);
        vif.vlsu_in.sched_req[port] = '0;
        vif.vlsu_in.vrf_data[port]  = '0;
    endtask

    task automatic clear_all_ports();
        clear_lane_port(0);
        clear_lane_port(1);
        clear_gsau_port();
        for (int p = 0; p < NUM_SCPADS; p++)
            clear_vlsu_port(p);
    endtask

    task automatic set_wb_ready(
        input logic [LANE_FU_COUNT-1:0] lane_status,
        input logic [NUM_SCPADS-1:0]    vlsu_status,
        input logic                     gsau_status,
        input logic                     reduction_status
    );
        vif.wb_ready_signals.lanes_wb_ready     = lane_status;
        vif.wb_ready_signals.vlsu_wb_ready      = vlsu_status;
        vif.wb_ready_signals.gsau_wb_ready      = gsau_status;
        vif.wb_ready_signals.reduction_wb_ready = reduction_status;
    endtask

    // -----------------------------------------------------------------------
    // Reset
    // -----------------------------------------------------------------------
    task automatic apply_reset();
        nRST = 1'b0;
        clear_lane_port(0);
        clear_lane_port(1);
        for (int p = 0; p < NUM_SCPADS; p++)
            clear_vlsu_port(p);
        clear_gsau_port();
        set_wb_ready({LANE_FU_COUNT{1'b1}}, {NUM_SCPADS{1'b1}}, 1'b1, 1'b1);

        // No need to drive sif or gsauif SA signals — real RTL handles them

        repeat (5) @(posedge CLK);
        nRST = 1'b1;
        repeat (5) @(posedge CLK);
    endtask

    // -----------------------------------------------------------------------
    // Drive lane issue ports from scheduler + veggie
    // -----------------------------------------------------------------------
    task automatic drive_lanes();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_lane_valid_in(p)) begin
                // Read V1 from veggie element-by-element
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs1(p), e);

                // V2: broadcast or VRF read
                if (dpi_get_lane_broadcast_v2(p)) begin
                    for (int e = 0; e < 32; e++)
                        tmp_vec2[e] = dpi_get_lane_v2_broadcast_elem(p, e);
                end else begin
                    for (int e = 0; e < 32; e++)
                        tmp_vec2[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs2(p), e);
                end

                vif.lanes_in.lane_issue_ports[p].v1          = pack_vreg(tmp_vec);
                vif.lanes_in.lane_issue_ports[p].v2          = pack_vreg(tmp_vec2);
                vif.lanes_in.lane_issue_ports[p].usel        = fu_t'(dpi_get_lane_fu_sel(p));
                vif.lanes_in.lane_issue_ports[p].alu_op      = alu_op_t'(dpi_get_lane_alu_op(p));
                vif.lanes_in.lane_issue_ports[p].vd          = dpi_get_lane_vd(p);
                vif.lanes_in.lane_issue_ports[p].rm          = dpi_get_lane_rm(p);
                vif.lanes_in.lane_issue_ports[p].input_valid = 1'b1;

                // Mask — force all enabled
                vif.lanes_in.lane_issue_ports[p].mask = 32'hFFFFFFFF;

            end else begin
                clear_lane_port(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive GSAU from scheduler + veggie
    // (SA RTL responds automatically via gsauif)
    // -----------------------------------------------------------------------
    task automatic drive_gsau_issue();
        if (dpi_get_sys_valid_in()) begin
            for (int e = 0; e < 32; e++)
                tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_sys_vs1(), e);
            for (int e = 0; e < 32; e++)
                tmp_vec2[e] = dpi_veggie_read_vector_elem(dpi_get_sys_vs2(), e);

            vif.gsau_in.veg_vdata1 = pack_vreg(tmp_vec);
            vif.gsau_in.veg_vdata2 = pack_vreg(tmp_vec2);
            vif.gsau_in.vd         = dpi_get_sys_vd();
            vif.gsau_in.weight     = dpi_get_sys_weight();
            vif.gsau_in.valid_in   = 1'b1;
        end else begin
            clear_gsau_port();
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive VLSU from scheduler + veggie
    // (Scratchpad RTL responds automatically via sif)
    // -----------------------------------------------------------------------
    task automatic drive_vlsu_issue();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_sp_valid_in(p)) begin
                int sp_port;
                sp_port = dpi_get_sp_sid(p);  // Route to correct VLSU by sid
                $display("[TB-VLSU-DRIVE] Cyc %0d: sp_port=%0d vd=%0d wen=%0b",
                    cycle_count, sp_port, dpi_get_sp_vd(p), dpi_get_sp_wen(p));
                
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_sp_vd(p), e);

                vif.vlsu_in.sched_req[sp_port].valid      = 1'b1;
                vif.vlsu_in.sched_req[sp_port].write       = (dpi_get_sp_wen(p) == 1) ? 1'b1 : 1'b0;
                vif.vlsu_in.sched_req[sp_port].spad_addr   = dpi_get_sp_sid(p);
                vif.vlsu_in.sched_req[sp_port].vdst        = dpi_get_sp_vd(p);
                vif.vlsu_in.sched_req[sp_port].num_rows    = dpi_get_sp_num_rows(p);
                vif.vlsu_in.sched_req[sp_port].num_cols    = dpi_get_sp_num_cols(p);

                if (dpi_get_sp_rc(p) == 0) begin
                    vif.vlsu_in.sched_req[sp_port].row_id = dpi_get_sp_rcid(p);
                end else begin
                    vif.vlsu_in.sched_req[sp_port].row_id = '0;
                end

                vif.vlsu_in.vrf_data[sp_port].data  = pack_vreg(tmp_vec);
                vif.vlsu_in.vrf_data[sp_port].valid = 1'b1;
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Writeback: capture DUT outputs → write to veggie VRF
    // -----------------------------------------------------------------------
    task automatic handle_writeback();
        // Lane result collectors → veggie write element-by-element
        for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
            if (vif.lanes_out.result_collectors[fu].wb_valid) begin
                unpack_vreg(vif.lanes_out.result_collectors[fu].vector_output, tmp_vec);
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(
                        vif.lanes_out.result_collectors[fu].vd_output, e, tmp_vec[e]);
            end
        end

        // GSAU writeback → veggie write element-by-element
        if (gsauif.wb_valid_out) begin
            unpack_vreg(gsauif.wb_psum, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(gsauif.wb_wbdst, e, tmp_vec[e]);
            $display("[TB-GSAU-WB] Cyc %0d: wb vd=%0d data[0]=%h", 
                cycle_count, gsauif.wb_wbdst, tmp_vec[0]);
        end

        // VLSU load writeback → veggie write element-by-element
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vif.vlsu_out.wb[p].valid) begin
                unpack_vreg(vif.vlsu_out.wb[p].load_data, tmp_vec);
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(
                        vif.vlsu_out.wb[p].vdst, e, tmp_vec[e]);
                $display("[TB-VLSU-WB] Cyc %0d: port=%0d vdst=%0d data[0]=%h",
                    cycle_count, p, vif.vlsu_out.wb[p].vdst, tmp_vec[0]);
            end
        end

        // Reduction writeback → veggie write element-by-element
        if (vif.lanes_out.reduction.wb_valid) begin
            unpack_vreg(vif.lanes_out.reduction.vector_output, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(
                    vif.lanes_out.reduction.vd_output, e, tmp_vec[e]);
            $display("[TB-RED] Cyc %0d: Reduction WB vd=%0d data[0]=%h",
                cycle_count, vif.lanes_out.reduction.vd_output, tmp_vec[0]);
        end
    endtask

    // -----------------------------------------------------------------------
    // Sample ready signals from DUT → push to scheduler
    // -----------------------------------------------------------------------
    task automatic sample_and_push_ready();
        logic [LANE_FU_COUNT-1:0] lane_ready;
        logic gsau_rdy;
        logic [NUM_SCPADS-1:0] vlsu_rdy;

        lane_ready = vif.unit_ready_signals.fu_global_status;
        gsau_rdy   = gsauif.sb_ready_out;

        for (int p = 0; p < NUM_SCPADS; p++)
            vlsu_rdy[p] = vif.unit_ready_signals.vlsu_status[p].ready;

        dpi_set_ready_signals(
            lane_ready[0],  // alu   -> VALU
            lane_ready[3],  // exp   -> EXP
            lane_ready[4],  // sqrt  -> SQRT
            lane_ready[1],  // mul   -> MUL
            lane_ready[2],  // div   -> DIV
            gsau_rdy,
            (vlsu_rdy != 0) ? 1'b1 : 1'b0
        );
    endtask

    // -----------------------------------------------------------------------
    // Main
    // -----------------------------------------------------------------------
    initial begin
        $display("============================================================");
        $display(" Vector Core L2 Integration Testbench (DPI-C + Real RTL)");
        $display(" Program: %s", PROGRAM_PATH);
        $display("============================================================");

        cycle_count = 0;

        // Init DPI models (scheduler + veggie only)
        dpi_scheduler_init(PROGRAM_PATH);
        dpi_veggie_init();

        // Reset
        apply_reset();
        $display("[TB] Reset released at cycle %0d", cycle_count);

        // Preload VRF with test data
        // (adjust per testcase — this is for add_vv)
        /*
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd2, i, 16'h3F80);  // v2 = 1.0
            dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);  // v3 = 1.0
        end
        */

        // Preload v0 with BEEF for store-load test
        /*
        for (int i = 0; i < 32; i++)
            dpi_veggie_write_vector_elem(8'd0, i, 16'hBEEF);
        dpi_veggie_write_mask(8'd0, 32'hFFFFFFFF);
        $display("[TB] Preloaded VRF and mask register");
        */

        // Preload VRF for gemm: weights in v0-v31, activations in v32-v64
        
        for (int v = 0; v < 32; v++)
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);  // 1.0
        for (int v = 32; v <= 64; v++)
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);  // 1.0

        // Backpressure test: inject DRAM stall on port 1 from cycle 10-20
        /*
        fork
            begin
                repeat (10) @(posedge CLK);  // wait 10 cycles
                inject_dram_backpressure(1, 10);  // stall port 1 for 10 cycles
            end
        join_none
        */

        // ---- Main loop ----
        forever begin
            @(posedge CLK);
            cycle_count++;

            // 1) Handle writeback from previous cycle (DUT → veggie)
            handle_writeback();

            // 2) Clear ports from previous cycle
            clear_all_ports();

            // 3) Sample DUT ready → push to scheduler
            sample_and_push_ready();

            // Debug ready
            if (cycle_count <= 5 || cycle_count % 100 == 0) begin
                logic [NUM_SCPADS-1:0] vlsu_dbg;
                for (int p = 0; p < NUM_SCPADS; p++)
                    vlsu_dbg[p] = vif.unit_ready_signals.vlsu_status[p].ready;
                $display("[TB-RDY] Cyc %0d: vlsu_rdy=%b gsau_rdy=%b", 
                    cycle_count, vlsu_dbg, gsauif.sb_ready_out);
            end
            // Debug stall signals
            if (cycle_count <= 10) begin
                $display("[TB-STALL] Cyc %0d: fe_vec_stall=%b%b%b%b fe_stall=%b%b%b%b",
                    cycle_count,
                    sif.fe_vec_stall[0], sif.fe_vec_stall[1], sif.fe_vec_stall[2], sif.fe_vec_stall[3],
                    sif.fe_stall[0], sif.fe_stall[1], sif.fe_stall[2], sif.fe_stall[3]);
            end

            if (cycle_count <= 5) begin
                $display("[TB-VLSU-IN] Cyc %0d: req[0].valid=%b req[1].valid=%b vrf[0].valid=%b vrf[1].valid=%b",
                    cycle_count,
                    vif.vlsu_in.sched_req[0].valid, vif.vlsu_in.sched_req[1].valid,
                    vif.vlsu_in.vrf_data[0].valid, vif.vlsu_in.vrf_data[1].valid);
            end

            // 4) Tick scheduler
            dpi_scheduler_tick(nRST);

            // 5) Drive DUT from scheduler + veggie
            drive_lanes();
            drive_gsau_issue();
            drive_vlsu_issue();

            // SA backpressure monitoring
            if (!gsauif.sa_ready_in)
                $display("[TB-SA-BP] Cyc %0d: sa_ready_in LOW (credit exhaustion!)", cycle_count);
            if (!gsauif.sb_ready_out)
                $display("[TB-SA-BP] Cyc %0d: sb_ready_out LOW (GSAU stalling scheduler!)", cycle_count);

            

            // Debug: monitor sif vec_req
            for (int p = 0; p < NUM_SCPADS; p++) begin
                if (sif.vec_req[p].valid)
                    $display("[TB-SIF] Cyc %0d: vec_req[%0d] valid write=%0b addr=%h", 
                        cycle_count, p, sif.vec_req[p].write, sif.vec_req[p].spad_addr);
            end

            // 6) No respond_gsau/respond_vlsu — real RTL handles it!

            // 7) Debug logging
            for (int p = 0; p < 2; p++) begin
                if (dpi_get_lane_valid_in(p))
                    $display("[TB] Cyc %0d: Lane[%0d] vd=%0d fu=%0d aluop=%0d rm=%0b",
                        cycle_count, p,
                        dpi_get_lane_vd(p),
                        dpi_get_lane_fu_sel(p),
                        dpi_get_lane_alu_op(p),
                        dpi_get_lane_rm(p));
            end
            if (dpi_get_sys_valid_in())
                $display("[TB] Cyc %0d: GSAU vd=%0d weight=%0b",
                    cycle_count, dpi_get_sys_vd(), dpi_get_sys_weight());
            for (int p = 0; p < 2; p++) begin
                if (dpi_get_sp_valid_in(p))
                    $display("[TB] Cyc %0d: SP[%0d] vd=%0d rows=%0d cols=%0d wen=%0b",
                        cycle_count, p,
                        dpi_get_sp_vd(p),
                        dpi_get_sp_num_rows(p),
                        dpi_get_sp_num_cols(p),
                        dpi_get_sp_wen(p));
            end

            // 8) Termination
            if (dpi_get_all_issued()) begin
                $display("[TB] All instructions issued at cycle %0d. Draining...", cycle_count);
                repeat (DRAIN_CYCLES) begin
                    @(posedge CLK);
                    cycle_count++;
                    handle_writeback();
                    // SA backpressure monitoring
                    if (!gsauif.sa_ready_in)
                        $display("[TB-SA-BP] Cyc %0d: sa_ready_in LOW (credit exhaustion!)", cycle_count);
                    if (!gsauif.sb_ready_out)
                        $display("[TB-SA-BP] Cyc %0d: sb_ready_out LOW (GSAU stalling scheduler!)", cycle_count);
                    // Debug scratchpad signals
                    for (int p = 0; p < NUM_SCPADS; p++) begin
                        if (sif.vec_res[p].valid)
                            $display("[TB-SP-RES] Cyc %0d: port=%0d valid", cycle_count, p);
                    end
                    for (int p = 0; p < NUM_SCPADS; p++) begin
                        if (vif.vlsu_out.wb[p].valid)
                            $display("[TB-VLSU-WB-DRAIN] Cyc %0d: port=%0d vdst=%0d", cycle_count, p, vif.vlsu_out.wb[p].vdst);
                    end
                    // Debug: monitor sif vec_req
                    for (int p = 0; p < NUM_SCPADS; p++) begin
                        if (sif.vec_req[p].valid)
                            $display("[TB-SIF] Cyc %0d: vec_req[%0d] valid write=%0b addr=%h", 
                                cycle_count, p, sif.vec_req[p].write, sif.vec_req[p].spad_addr);
                    end
                end
                break;
            end

            if (cycle_count >= TIMEOUT) begin
                $display("[TB] TIMEOUT at cycle %0d!", cycle_count);
                break;
            end
        end

        // Verify results (adjust per testcase)
        $display("[TB] ---- Verification ----");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v1[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd1, e));
        for (int e = 0; e < 4; e++)
            $display("[TB]   v0[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd0, e));
        for (int e = 0; e < 4; e++)
            $display("[TB]   v1[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd1, e));
        
        $display("[TB] Verify gemm output (v65):");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v65[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd65, e));

        // Cleanup
        dpi_scheduler_destroy();
        dpi_veggie_destroy();

        $display("============================================================");
        $display(" Done. Total cycles: %0d", cycle_count);
        $display("============================================================");
        $finish;
    end

    // -----------------------------------------------------------------------
    // Waveform
    // -----------------------------------------------------------------------
    initial begin
        $dumpfile("vector_core_L2_tb.vcd");
        $dumpvars(0, vector_core_L2_tb);
    end

endmodule
