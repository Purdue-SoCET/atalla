// ============================================================================
// vector_core_L2_tb.sv
// L2 Integration Testbench - DPI-C driven
//
// L2 replaces C++ models with real RTL:
//   Scheduler -> still C++ DPI (drives instructions)
//   Veggie -> still C++ DPI (VRF reads/writes)
//   Sysarr -> REAL RTL (sysarr_MEISSA_top)
//   Scratchpad -> REAL RTL (scratchpad)
//
// DUT: vector_datapath + scratchpad + systolic_array
// Owner: Vedant Sharma
//
// Usage: make l2_test VLOG_FLAGS="+define+TEST_ADD_VV"
//        make l2_test_gui VLOG_FLAGS="+define+TEST_GEMM_VV"

//   Available defines:
//     TEST_ADD_VV, TEST_SUB_VV, TEST_MUL_VV,
//     TEST_ADD_VI, TEST_SUB_VI, TEST_MULI_VI,
//     TEST_ADD_VS, TEST_SUB_VS, TEST_MUL_VS,
//     TEST_RSUM_VI, TEST_RMIN_VI, TEST_RMAX_VI,
//     TEST_GEMM_VV, TEST_STORE_LOAD,
//     TEST_GEMM_BP, TEST_DRAM_BP,
//     TEST_MASKED0, TEST_MASKED1, TEST_MASKED2, TEST_MASKED3
//
// Please for the love of all things holy don't run a full regression unless you're just testing all functionality (except the backpressure tests), and have 10-20 min of your time,
// Its genuinely a waste if you only want a look at a few specific functions
// Pick a couple of tests, run those, if you want to change the preloads to test different values go ahead
// But note that the expected values are hardcoded into my verification scoreboard, so if you change the preloads you also have to change the expected values in the scoreboard.
// Also full regression doesnt run the backpressure tests, run those seperately if you want to see those
//
// Full regression:
//   for t in TEST_ADD_VV TEST_SUB_VV TEST_MUL_VV TEST_ADD_VS TEST_SUB_VS TEST_MUL_VS TEST_ADD_VI TEST_SUB_VI TEST_MULI_VI TEST_RSUM_VI TEST_RMIN_VI TEST_RMAX_VI TEST_GEMM_VV TEST_STORE_LOAD TEST_GEMM_BP TEST_DRAM_BP; do echo "=== $t ==="; rm -rf work && make l2_test VLOG_FLAGS="+define+$t" 2>&1 | grep -E "Verification|expect|Done|Error"; done
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

    // Test selection via ifdef
    `ifdef TEST_ADD_VV
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/add_vv";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_SUB_VV
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/sub_vv";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MUL_VV
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/mul_vv";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_ADD_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/add_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_SUB_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/sub_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MULI_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/muli_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_ADD_VS
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-scalar/add_vs";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_SUB_VS
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-scalar/sub_vs";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MUL_VS
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-scalar/mul_vs";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_RSUM_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rsum_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_RMIN_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rmin_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_RMAX_VI
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rmax_vi";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_GEMM_VV
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_vv";
        parameter int    DRAIN_CYCLES = 300;
    `elsif TEST_STORE_LOAD
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";
        parameter int    DRAIN_CYCLES = 150;
    `elsif TEST_GEMM_BP
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_bp_test";
        parameter int    DRAIN_CYCLES = 500;
    `elsif TEST_DRAM_BP
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/store_load_l2";
        parameter int    DRAIN_CYCLES = 150;
    `elsif TEST_MASKED0
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/masked-unit-tests/masked_testing0";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MASKED1
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/masked-unit-tests/masked_testing1";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MASKED2
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/masked-unit-tests/masked_testing2";
        parameter int    DRAIN_CYCLES = 40;
    `elsif TEST_MASKED3
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/masked-unit-tests/masked_testing3";
        parameter int    DRAIN_CYCLES = 40;
    `else
        parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/add_vv";
        parameter int    DRAIN_CYCLES = 40;
    `endif

    parameter int TIMEOUT = 10000;

    // Clock / Reset
    logic CLK;
    logic nRST;
    localparam int CLK_PERIOD = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    // Interfaces
    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    // DUT: Vector Datapath
    vector_datapath dut(
        .CLK(CLK),
        .nRST(nRST),
        .vif(vif),
        .sif(sif),
        .gsauif(gsauif)
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
        vif.lanes_in.lane_issue_ports[port].v1 = '0;
        vif.lanes_in.lane_issue_ports[port].v2 = '0;
        vif.lanes_in.lane_issue_ports[port].usel = VALU;
        vif.lanes_in.lane_issue_ports[port].vd = '0;
        vif.lanes_in.lane_issue_ports[port].rm = 1'b0;
        vif.lanes_in.lane_issue_ports[port].mask = '0;
        vif.lanes_in.lane_issue_ports[port].alu_op = ALU_ADD;
        vif.lanes_in.lane_issue_ports[port].input_valid = 1'b0;
    endtask

    task automatic clear_gsau_port();
        vif.gsau_in.veg_vdata1 = '0;
        vif.gsau_in.veg_vdata2 = '0;
        vif.gsau_in.vd = '0;
        vif.gsau_in.valid_in = 1'b0;
        vif.gsau_in.weight = 1'b0;
    endtask

    task automatic clear_vlsu_port(input int port);
        vif.vlsu_in.sched_req[port] = '0;
        vif.vlsu_in.vrf_data[port] = '0;
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
        input logic [NUM_SCPADS-1:0] vlsu_status,
        input logic gsau_status,
        input logic reduction_status
    );
        vif.wb_ready_signals.lanes_wb_ready = lane_status;
        vif.wb_ready_signals.vlsu_wb_ready = vlsu_status;
        vif.wb_ready_signals.gsau_wb_ready = gsau_status;
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
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs1(p), e);

                if (dpi_get_lane_broadcast_v2(p)) begin
                    bit [15:0] scalar_val;
                    scalar_val = dpi_veggie_read_vector_elem(dpi_get_veggie_rs1(p), 0);
                    for (int e = 0; e < 32; e++)
                        tmp_vec2[e] = scalar_val;
                end else begin
                    for (int e = 0; e < 32; e++)
                        tmp_vec2[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs2(p), e);
                end

                vif.lanes_in.lane_issue_ports[p].v1 = pack_vreg(tmp_vec);
                vif.lanes_in.lane_issue_ports[p].v2 = pack_vreg(tmp_vec2);
                vif.lanes_in.lane_issue_ports[p].usel = fu_t'(dpi_get_lane_fu_sel(p));
                vif.lanes_in.lane_issue_ports[p].alu_op = alu_op_t'(dpi_get_lane_alu_op(p));
                vif.lanes_in.lane_issue_ports[p].vd = dpi_get_lane_vd(p);
                vif.lanes_in.lane_issue_ports[p].rm = dpi_get_lane_rm(p);
                vif.lanes_in.lane_issue_ports[p].input_valid = 1'b1;
                vif.lanes_in.lane_issue_ports[p].mask = 32'hFFFFFFFF;
            end else begin
                clear_lane_port(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive GSAU from scheduler + veggie
    // -----------------------------------------------------------------------
    task automatic drive_gsau_issue();
        if (dpi_get_sys_valid_in()) begin
            for (int e = 0; e < 32; e++)
                tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_sys_vs1(), e);
            for (int e = 0; e < 32; e++)
                tmp_vec2[e] = dpi_veggie_read_vector_elem(dpi_get_sys_vs2(), e);

            vif.gsau_in.veg_vdata1 = pack_vreg(tmp_vec);
            vif.gsau_in.veg_vdata2 = pack_vreg(tmp_vec2);
            vif.gsau_in.vd = dpi_get_sys_vd();
            vif.gsau_in.weight = dpi_get_sys_weight();
            vif.gsau_in.valid_in = 1'b1;
        end else begin
            clear_gsau_port();
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive VLSU from scheduler + veggie
    // -----------------------------------------------------------------------
    task automatic drive_vlsu_issue();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_sp_valid_in(p)) begin
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_sp_vd(p), e);

                vif.vlsu_in.sched_req[p].valid = 1'b1;
                vif.vlsu_in.sched_req[p].write = (dpi_get_sp_wen(p) == 1) ? 1'b1 : 1'b0;
                vif.vlsu_in.sched_req[p].spad_addr = dpi_get_sp_sid(p);
                vif.vlsu_in.sched_req[p].vdst = dpi_get_sp_vd(p);
                vif.vlsu_in.sched_req[p].num_cols = dpi_get_sp_num_cols(p);
                vif.vlsu_in.sched_req[p].row_id = dpi_get_sp_row_num(p);

                vif.vlsu_in.vrf_data[p].data = pack_vreg(tmp_vec);
                vif.vlsu_in.vrf_data[p].valid = 1'b1;
            end else begin
                clear_vlsu_port(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Writeback: capture DUT outputs -> write to veggie VRF (Jaideep, this is where youll need to add ur stuff instead of my emulation of writeback)
    // -----------------------------------------------------------------------
    task automatic handle_writeback();
        for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
            if (vif.lanes_out.result_collectors[fu].wb_valid) begin
                unpack_vreg(vif.lanes_out.result_collectors[fu].vector_output, tmp_vec);
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(
                        vif.lanes_out.result_collectors[fu].vd_output, e, tmp_vec[e]);
            end
        end

        if (gsauif.wb_valid_out) begin
            unpack_vreg(gsauif.wb_psum, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(gsauif.wb_wbdst, e, tmp_vec[e]);
            $display("[TB-GSAU-WB] Cyc %0d: wb vd=%0d data[0]=%h", 
                cycle_count, gsauif.wb_wbdst, tmp_vec[0]);
        end

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
    // Sample ready signals from DUT -> push to scheduler
    // -----------------------------------------------------------------------
    task automatic sample_and_push_ready();
        logic [LANE_FU_COUNT-1:0] lane_ready;
        logic gsau_rdy;
        logic [NUM_SCPADS-1:0] vlsu_rdy;

        lane_ready = vif.unit_ready_signals.fu_global_status;
        gsau_rdy = gsauif.sb_ready_out;

        for (int p = 0; p < NUM_SCPADS; p++)
            vlsu_rdy[p] = vif.unit_ready_signals.vlsu_status[p].ready;

        dpi_set_ready_signals(
            lane_ready[0],  // alu
            lane_ready[1],  // mul
            1'b1, // exp (not done yet)
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

        dpi_scheduler_init(PROGRAM_PATH);
        dpi_veggie_init();

        apply_reset();
        $display("[TB] Reset released at cycle %0d", cycle_count);

        // ==================================================================
        // Preload VRF per test
        // ==================================================================
        dpi_veggie_write_mask(8'd0, 32'hFFFFFFFF);

        `ifdef TEST_ADD_VV
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd2, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);
            end
            $display("[TB] Preloaded: add_vv (v2=1.0, v3=1.0)");

        `elsif TEST_SUB_VV
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd5, i, 16'h4040);
                dpi_veggie_write_vector_elem(8'd6, i, 16'h3F80);
            end
            $display("[TB] Preloaded: sub_vv (v5=3.0, v6=1.0)");

        `elsif TEST_MUL_VV
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd8, i, 16'h4000);
                dpi_veggie_write_vector_elem(8'd9, i, 16'h4040);
            end
            $display("[TB] Preloaded: mul_vv (v8=2.0, v9=3.0)");

        `elsif TEST_ADD_VI
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);
            $display("[TB] Preloaded: add_vi (v0=1.0, imm=0x00A0)");

        `elsif TEST_SUB_VI
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h4040);
            $display("[TB] Preloaded: sub_vi (v0=3.0, imm=0x0060)");

        `elsif TEST_MULI_VI
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h4000);
            $display("[TB] Preloaded: muli_vi (v0=2.0, imm=0x0080)");

        `elsif TEST_ADD_VS
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd2, i, 16'h4000);
            end
            $display("[TB] Preloaded: add_vs (v0=1.0, v2=2.0)");

        `elsif TEST_SUB_VS
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd1, i, 16'h4040);
                dpi_veggie_write_vector_elem(8'd4, i, 16'h3F80);
            end
            $display("[TB] Preloaded: sub_vs (v1=3.0, v4=1.0)");

        `elsif TEST_MUL_VS
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd2, i, 16'h4000);
                dpi_veggie_write_vector_elem(8'd6, i, 16'h4040);
            end
            $display("[TB] Preloaded: mul_vs (v2=2.0, v6=3.0)");

        `elsif TEST_RSUM_VI
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);
            $display("[TB] Preloaded: rsum_vi (v0=all 1.0)");

        `elsif TEST_RMIN_VI
            dpi_veggie_write_vector_elem(8'd0, 0, 16'h3F80);
            for (int i = 1; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h40A0);
            $display("[TB] Preloaded: rmin_vi (v0[0]=1.0, rest=5.0)");

        `elsif TEST_RMAX_VI
            dpi_veggie_write_vector_elem(8'd0, 0, 16'h4120);
            for (int i = 1; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);
            $display("[TB] Preloaded: rmax_vi (v0[0]=10.0, rest=1.0)");

        `elsif TEST_GEMM_VV
            for (int v = 0; v < 32; v++)
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);
            for (int v = 32; v <= 64; v++)
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);
            $display("[TB] Preloaded: gemm_vv (weights+activations=1.0)");

        `elsif TEST_STORE_LOAD
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'hBEEF);
            $display("[TB] Preloaded: store_load (v0=BEEF)");

        `elsif TEST_GEMM_BP
            for (int v = 0; v < 32; v++)
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);
            for (int v = 32; v <= 64; v++)
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);
            $display("[TB] Preloaded: gemm_bp (weights+activations=1.0)");

        `elsif TEST_DRAM_BP
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd0, i, 16'hBEEF);
            $display("[TB] Preloaded: dram_bp (v0=BEEF)");

        `elsif TEST_MASKED0
            $display("[TB] Preloaded: masked_testing0 (mv.stm only)");

        `elsif TEST_MASKED1
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd2, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd4, i, 16'h4040);
                dpi_veggie_write_vector_elem(8'd5, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd6, i, 16'h4000);
                dpi_veggie_write_vector_elem(8'd7, i, 16'h4040);
            end
            dpi_veggie_write_mask(8'd1, 32'hAAAAAAAA);
            $display("[TB] Preloaded: masked_testing1");

        `elsif TEST_MASKED2
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd4, i, 16'h4000);
                dpi_veggie_write_vector_elem(8'd5, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd6, i, 16'h4040);
            end
            dpi_veggie_write_mask(8'd2, 32'hFFFF0000);
            $display("[TB] Preloaded: masked_testing2");

        `elsif TEST_MASKED3
            for (int i = 0; i < 32; i++)
                dpi_veggie_write_vector_elem(8'd1, i, 16'h3F80);
            dpi_veggie_write_mask(8'd3, 32'h0000FFFF);
            $display("[TB] Preloaded: masked_testing3");

        `else
            for (int i = 0; i < 32; i++) begin
                dpi_veggie_write_vector_elem(8'd2, i, 16'h3F80);
                dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);
            end
            $display("[TB] Preloaded: default (add_vv)");
        `endif

        // ==================================================================
        // Backpressure injection (forked)
        // ==================================================================
        `ifdef TEST_DRAM_BP
            fork
                begin
                    repeat (10) @(posedge CLK);
                    inject_dram_backpressure(0, 10);
                end
            join_none
        `endif

        // ---- Main loop ----
        forever begin
            @(posedge CLK);
            cycle_count++;

            handle_writeback();
            clear_all_ports();
            sample_and_push_ready();

            // Debug ready (first 5 cycles and every 100)
            if (cycle_count <= 5 || cycle_count % 100 == 0) begin
                logic [NUM_SCPADS-1:0] vlsu_dbg;
                for (int p = 0; p < NUM_SCPADS; p++)
                    vlsu_dbg[p] = vif.unit_ready_signals.vlsu_status[p].ready;
                $display("[TB-RDY] Cyc %0d: vlsu_rdy=%b gsau_rdy=%b", 
                    cycle_count, vlsu_dbg, gsauif.sb_ready_out);
            end

            dpi_scheduler_tick(nRST);

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

            // Debug logging
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
                    $display("[TB] Cyc %0d: SP[%0d] vd=%0d row=%0d cols=%0d wen=%0b",
                        cycle_count, p,
                        dpi_get_sp_vd(p),
                        dpi_get_sp_row_num(p),
                        dpi_get_sp_num_cols(p),
                        dpi_get_sp_wen(p));
            end

            // Termination
            if (dpi_get_all_issued()) begin
                $display("[TB] All instructions issued at cycle %0d. Draining...", cycle_count);
                repeat (DRAIN_CYCLES) begin
                    @(posedge CLK);
                    cycle_count++;
                    handle_writeback();
                    if (!gsauif.sa_ready_in)
                        $display("[TB-SA-BP] Cyc %0d: sa_ready_in LOW", cycle_count);
                    if (!gsauif.sb_ready_out)
                        $display("[TB-SA-BP] Cyc %0d: sb_ready_out LOW", cycle_count);
                    for (int p = 0; p < NUM_SCPADS; p++) begin
                        if (sif.vec_res[p].valid)
                            $display("[TB-SP-RES] Cyc %0d: port=%0d valid", cycle_count, p);
                    end
                    for (int p = 0; p < NUM_SCPADS; p++) begin
                        if (vif.vlsu_out.wb[p].valid)
                            $display("[TB-VLSU-WB-DRAIN] Cyc %0d: port=%0d vdst=%0d", cycle_count, p, vif.vlsu_out.wb[p].vdst);
                    end
                end
                break;
            end

            if (cycle_count >= TIMEOUT) begin
                $display("[TB] TIMEOUT at cycle %0d!", cycle_count);
                break;
            end
        end

        // ==================================================================
        // Verification per test
        // ==================================================================
        $display("[TB] ---- Verification ----");

        `ifdef TEST_ADD_VV
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect 4000)", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_SUB_VV
            for (int e = 0; e < 32; e++)
                $display("[TB]   v4[%0d] = %h (expect 4000)", e, dpi_veggie_read_vector_elem(8'd4, e));

        `elsif TEST_MUL_VV
            for (int e = 0; e < 32; e++)
                $display("[TB]   v7[%0d] = %h (expect 40C0)", e, dpi_veggie_read_vector_elem(8'd7, e));

        `elsif TEST_ADD_VI
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect ~3F80)", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_SUB_VI
            for (int e = 0; e < 32; e++)
                $display("[TB]   v2[%0d] = %h (expect ~4040)", e, dpi_veggie_read_vector_elem(8'd2, e));

        `elsif TEST_MULI_VI
            for (int e = 0; e < 32; e++)
                $display("[TB]   v3[%0d] = %h (expect ~0000)", e, dpi_veggie_read_vector_elem(8'd3, e));

        `elsif TEST_ADD_VS
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect 4040)", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_SUB_VS
            for (int e = 0; e < 32; e++)
                $display("[TB]   v3[%0d] = %h (expect 4000)", e, dpi_veggie_read_vector_elem(8'd3, e));

        `elsif TEST_MUL_VS
            for (int e = 0; e < 32; e++)
                $display("[TB]   v5[%0d] = %h (expect 40C0)", e, dpi_veggie_read_vector_elem(8'd5, e));

        `elsif TEST_RSUM_VI
            $display("[TB]   v1[0] = %h (expect 4200)", dpi_veggie_read_vector_elem(8'd1, 0));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_RMIN_VI
            $display("[TB]   v2[0] = %h (expect 3F80)", dpi_veggie_read_vector_elem(8'd2, 0));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v2[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd2, e));

        `elsif TEST_RMAX_VI
            $display("[TB]   v3[0] = %h (expect 4120)", dpi_veggie_read_vector_elem(8'd3, 0));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v3[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd3, e));

        `elsif TEST_GEMM_VV
            for (int e = 0; e < 32; e++)
                $display("[TB]   v65[%0d] = %h (expect 4200)", e, dpi_veggie_read_vector_elem(8'd65, e));

        `elsif TEST_STORE_LOAD
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect BEEF)", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_GEMM_BP
            for (int e = 0; e < 32; e++)
                $display("[TB]   v65[%0d] = %h (expect 4200)", e, dpi_veggie_read_vector_elem(8'd65, e));

        `elsif TEST_DRAM_BP
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect BEEF)", e, dpi_veggie_read_vector_elem(8'd1, e));

        `elsif TEST_MASKED0
            $display("[TB]   masked_testing0: mv.stm only, no data to verify");

        `elsif TEST_MASKED1
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (masked add)", e, dpi_veggie_read_vector_elem(8'd1, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v3[%0d] = %h (masked sub)", e, dpi_veggie_read_vector_elem(8'd3, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v5[%0d] = %h (masked mul)", e, dpi_veggie_read_vector_elem(8'd5, e));

        `elsif TEST_MASKED2
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (masked vs add)", e, dpi_veggie_read_vector_elem(8'd1, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v4[%0d] = %h (masked vs sub)", e, dpi_veggie_read_vector_elem(8'd4, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v5[%0d] = %h (masked vs mul)", e, dpi_veggie_read_vector_elem(8'd5, e));

        `elsif TEST_MASKED3
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (masked vi add)", e, dpi_veggie_read_vector_elem(8'd1, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v8[%0d] = %h (masked vi sub)", e, dpi_veggie_read_vector_elem(8'd8, e));
            for (int e = 0; e < 32; e++)
                $display("[TB]   v9[%0d] = %h (masked vi mul)", e, dpi_veggie_read_vector_elem(8'd9, e));

        `else
            for (int e = 0; e < 32; e++)
                $display("[TB]   v1[%0d] = %h (expect 4000)", e, dpi_veggie_read_vector_elem(8'd1, e));
        `endif

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