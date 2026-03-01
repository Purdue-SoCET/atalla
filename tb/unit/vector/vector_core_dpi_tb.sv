// ============================================================================
// vector_core_dpi_tb.sv
// L1 Integration Testbench — DPI-C driven
//
// Uses C++ models via DPI-C:
//   Scheduler  -> instruction decode -> drive vif, gsauif
//   Veggie     -> VRF reads/writes   -> feed v1/v2 data to DUT
//   Sysarr     -> systolic array sim -> respond to gsauif
//   Scratchpad -> scratchpad sim     -> respond to sif
//
// DUT: vector_datapath (vector_if, gsau_control_unit_if, scpad_if)
// This part is completely claude based rn, based off the old tb, 
// just using my new dpi-c stuff, will check later to see. rn just to check if runs
// Owner: Vedant Sharma
// ============================================================================
`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module vector_core_dpi_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;
    import inst_parser_dpi_pkg::*;

    // -----------------------------------------------------------------------
    // Parameters
    // -----------------------------------------------------------------------
    parameter string PROGRAM_PATH = "./testcases/add_vv";
    parameter int    DRAIN_CYCLES = 40;
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
    // DUT
    // -----------------------------------------------------------------------
    vector_datapath dut (
        .CLK    (CLK),
        .nRST   (nRST),
        .vif    (vif),
        .sif    (sif),
        .gsauif (gsauif)
    );

    // -----------------------------------------------------------------------
    // Cycle counter
    // -----------------------------------------------------------------------
    int cycle_count;

    // -----------------------------------------------------------------------
    // Temp arrays for DPI vector transfers
    // -----------------------------------------------------------------------
    logic [15:0] tmp_vec  [0:31];
    logic [15:0] tmp_vec2 [0:31];

    // -----------------------------------------------------------------------
    // Helper: pack tmp_vec into vreg_t
    // -----------------------------------------------------------------------
    function automatic vreg_t pack_vreg(logic [15:0] arr [0:31]);
        vreg_t v;
        for (int i = 0; i < 32; i++) v[i] = arr[i];
        return v;
    endfunction

    // -----------------------------------------------------------------------
    // Helper: unpack vreg_t into tmp_vec
    // -----------------------------------------------------------------------
    task automatic unpack_vreg(input vreg_t v, output logic [15:0] arr [0:31]);
        for (int i = 0; i < 32; i++) arr[i] = v[i];
    endtask

    // -----------------------------------------------------------------------
    // Clear tasks (matching Jacob's TB exactly)
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
        clear_vlsu_port(0);
        clear_vlsu_port(1);
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

    task automatic drive_gsau_from_sys(
        input vreg_t data  = '0,
        input logic  valid = 1'b0,
        input logic  ready = 1'b0
    );
        gsauif.sa_array_output = data;
        gsauif.sa_valid_in     = valid;
        gsauif.sa_ready_in     = ready;
    endtask

    task automatic drive_vlsu_from_sp(
        input int    port,
        input logic  valid = 1'b0,
        input logic  write = 1'b0,
        input vreg_t data  = '0,
        input logic  stall = 1'b0
    );
        sif.vec_res[port].valid = valid;
        sif.vec_res[port].write = write;
        sif.vec_res[port].rdata = data;
        sif.fe_vec_stall[port]  = stall;
    endtask

    // -----------------------------------------------------------------------
    // Reset (matching Jacob's apply_reset)
    // -----------------------------------------------------------------------
    task automatic apply_reset();
        nRST = 1'b0;
        clear_lane_port(0);
        clear_lane_port(1);
        clear_vlsu_port(0);
        clear_vlsu_port(1);
        clear_gsau_port();
        set_wb_ready({LANE_FU_COUNT{1'b1}}, {NUM_SCPADS{1'b1}}, 1'b1, 1'b1);

        sif.fe_vec_stall[0]    = '0;
        sif.fe_vec_stall[1]    = '0;
        sif.vec_res[0]         = '0;
        sif.vec_res[1]         = '0;
        gsauif.sa_ready_in     = 1'b1;
        gsauif.sa_valid_in     = 1'b0;
        gsauif.sa_array_output = '0;

        // Tick DPI models under reset
        dpi_scheduler_tick(1'b0);
        dpi_sysarr_tick(1'b0);
        dpi_scratchpad_tick(1'b0);
        dpi_veggie_tick(1'b0);

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
                // Read V1 from veggie
                dpi_veggie_set_lane_vs(p*2, dpi_get_veggie_vs1(p));
                dpi_veggie_set_lane_ren(p, dpi_get_veggie_ren(p));
                dpi_veggie_tick(nRST);
                dpi_veggie_get_lane_rdata(p, tmp_vec);

                // V2: broadcast scalar or VRF read
                if (dpi_get_lane_broadcast_v2(p)) begin
                    dpi_get_lane_v2_broadcast(p, tmp_vec2);
                end else begin
                    dpi_veggie_set_lane_vs(p*2 + 1, dpi_get_veggie_vs2(p));
                    dpi_veggie_tick(nRST);
                    dpi_veggie_get_lane_rdata(p, tmp_vec2);
                end

                // Issue using Jacob's exact signal names
                vif.lanes_in.lane_issue_ports[p].v1          = pack_vreg(tmp_vec);
                vif.lanes_in.lane_issue_ports[p].v2          = pack_vreg(tmp_vec2);
                vif.lanes_in.lane_issue_ports[p].usel        = fu_t'(dpi_get_lane_fu_sel(p));
                vif.lanes_in.lane_issue_ports[p].alu_op      = alu_op_t'(dpi_get_lane_alu_op(p));
                vif.lanes_in.lane_issue_ports[p].vd          = dpi_get_lane_vd(p);
                vif.lanes_in.lane_issue_ports[p].rm          = dpi_get_lane_rm(p);
                vif.lanes_in.lane_issue_ports[p].input_valid = 1'b1;

                // Mask
                if (dpi_get_mask_vmrf_mren(p)) begin
                    dpi_veggie_set_mask_vs(p, dpi_get_mask_vmrf_vs(p));
                    dpi_veggie_set_mask_ren(p, 1'b1);
                    dpi_veggie_tick(nRST);
                    vif.lanes_in.lane_issue_ports[p].mask = dpi_veggie_get_mask_rdata(p);
                end else begin
                    vif.lanes_in.lane_issue_ports[p].mask = '1;
                end

            end else begin
                clear_lane_port(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive GSAU from scheduler + veggie
    // Uses vif.gsau_in (matching Jacob's interface)
    // -----------------------------------------------------------------------
    task automatic drive_gsau_issue();
        if (dpi_get_sys_valid_in()) begin
            // Read vs1/vs2 from veggie
            dpi_veggie_set_sys_vs(0, dpi_get_sys_vs1());
            dpi_veggie_set_sys_vs(1, dpi_get_sys_vs2());
            dpi_veggie_set_sys_ren(0, dpi_get_sys_ren(0));
            dpi_veggie_set_sys_ren(1, dpi_get_sys_ren(1));
            dpi_veggie_tick(nRST);

            dpi_veggie_get_sys_rdata(0, tmp_vec);
            dpi_veggie_get_sys_rdata(1, tmp_vec2);

            // Issue through vif.gsau_in (Jacob's path)
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
    // Respond to GSAU with sysarr model
    // Uses gsauif (SA side, matching Jacob's drive_gsau_from_sys)
    // -----------------------------------------------------------------------
    task automatic respond_gsau();
        // Push DUT's SA outputs into sysarr model
        if (gsauif.sa_weight_en) begin
            unpack_vreg(gsauif.sa_array_in, tmp_vec);
            dpi_sysarr_set_weight(tmp_vec, 1'b1);
        end else begin
            dpi_sysarr_set_weight(tmp_vec, 1'b0);
        end

        if (gsauif.sa_input_en) begin
            unpack_vreg(gsauif.sa_array_in, tmp_vec);
            dpi_sysarr_set_activation(tmp_vec, 1'b1);
        end else begin
            dpi_sysarr_set_activation(tmp_vec, 1'b0);
        end

        // Tick sysarr
        dpi_sysarr_tick(nRST);

        // Drive results back (matching Jacob's drive_gsau_from_sys)
        if (dpi_sysarr_get_valid()) begin
            dpi_sysarr_get_output(tmp_vec);
            drive_gsau_from_sys(
                .data  (pack_vreg(tmp_vec)),
                .valid (1'b1),
                .ready (dpi_sysarr_get_ready())
            );
        end else begin
            drive_gsau_from_sys(
                .ready (dpi_sysarr_get_ready())
            );
        end
    endtask

    // -----------------------------------------------------------------------
    // Drive VLSU from scheduler + veggie
    // Uses vif.vlsu_in (matching Jacob's issue_to_vlsu_port)
    // -----------------------------------------------------------------------
    task automatic drive_vlsu_issue();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_sp_valid_in(p)) begin
                // Read VRF data for stores
                dpi_veggie_set_sp_vs(p, dpi_get_veggie_vs1(p));
                dpi_veggie_set_sp_ren(p, 1'b1);
                dpi_veggie_tick(nRST);
                dpi_veggie_get_sp_rdata(p, tmp_vec);

                // Issue (matching Jacob's exact signal names)
                vif.vlsu_in.sched_req[p].valid      = 1'b1;
                vif.vlsu_in.sched_req[p].write      = (dpi_get_sp_rc(p) != 0) ? 1'b1 : 1'b0; // TODO: verify store encoding
                vif.vlsu_in.sched_req[p].spad_addr  = dpi_get_sp_sid(p);
                vif.vlsu_in.sched_req[p].vdst       = dpi_get_sp_vd(p);
                vif.vlsu_in.sched_req[p].num_rows   = dpi_get_sp_num_rows(p);
                vif.vlsu_in.sched_req[p].num_cols   = dpi_get_sp_num_cols(p);
                vif.vlsu_in.sched_req[p].row_or_col = dpi_get_sp_rc(p);

                if (dpi_get_sp_rc(p) == 0) begin
                    vif.vlsu_in.sched_req[p].row_id = dpi_get_sp_rcid(p);
                    vif.vlsu_in.sched_req[p].col_id = '0;
                end else begin
                    vif.vlsu_in.sched_req[p].row_id = '0;
                    vif.vlsu_in.sched_req[p].col_id = dpi_get_sp_rcid(p);
                end

                vif.vlsu_in.vrf_data[p].data  = pack_vreg(tmp_vec);
                vif.vlsu_in.vrf_data[p].valid = 1'b1;
            end else begin
                clear_vlsu_port(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Respond to VLSU with scratchpad model
    // Uses sif (matching Jacob's drive_vlsu_from_sp)
    // -----------------------------------------------------------------------
    task automatic respond_vlsu();
        for (int p = 0; p < NUM_SCPADS; p++) begin
            // Push DUT's scratchpad requests into model
            dpi_scratchpad_set_request(
                p,
                sif.vec_req[p].valid,
                sif.vec_req[p].write,
                sif.vec_req[p].addr,
                sif.vec_req[p].row_id,
                sif.vec_req[p].col_id,
                sif.vec_req[p].num_rows,
                sif.vec_req[p].num_cols,
                sif.vec_req[p].row_or_col
            );

            if (sif.vec_req[p].write && sif.vec_req[p].valid) begin
                unpack_vreg(sif.vec_req[p].wdata, tmp_vec);
                dpi_scratchpad_set_wdata(p, tmp_vec);
            end
        end

        // Tick scratchpad
        dpi_scratchpad_tick(nRST);

        // Drive results back (matching Jacob's drive_vlsu_from_sp)
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (dpi_scratchpad_get_valid(p)) begin
                dpi_scratchpad_get_rdata(p, tmp_vec);
                drive_vlsu_from_sp(p, .valid(1'b1), .data(pack_vreg(tmp_vec)));
            end else begin
                drive_vlsu_from_sp(p);
            end
        end
    endtask

    // -----------------------------------------------------------------------
    // Writeback: capture DUT outputs and write back to veggie
    // -----------------------------------------------------------------------
    task automatic handle_writeback();
        // Lane result collectors → veggie write
        for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
            if (vif.lanes_out.result_collectors[fu].wb_valid) begin
                unpack_vreg(vif.lanes_out.result_collectors[fu].vector_output, tmp_vec);
                dpi_veggie_set_lane_vd(fu, vif.lanes_out.result_collectors[fu].vd_output);
                dpi_veggie_set_lane_wen(fu, 1'b1);
                dpi_veggie_set_lane_wdata(fu, tmp_vec);
            end else begin
                dpi_veggie_set_lane_wen(fu, 1'b0);
            end
        end

        // GSAU writeback → veggie write
        if (gsauif.wb_valid_out) begin
            unpack_vreg(gsauif.wb_psum, tmp_vec);
            dpi_veggie_set_sys_vd(0, gsauif.wb_wbdst);
            dpi_veggie_set_sys_wen(0, 1'b1);
            dpi_veggie_set_sys_wdata(0, tmp_vec);
        end else begin
            dpi_veggie_set_sys_wen(0, 1'b0);
        end

        // VLSU load writeback → veggie write
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vif.vlsu_out.wb[p].valid) begin
                unpack_vreg(vif.vlsu_out.wb[p].load_data, tmp_vec);
                dpi_veggie_set_sp_vd(p, vif.vlsu_out.wb[p].vdst);
                dpi_veggie_set_sp_wen(p, 1'b1);
                dpi_veggie_set_sp_wdata(p, tmp_vec);
            end else begin
                dpi_veggie_set_sp_wen(p, 1'b0);
            end
        end

        // Tick veggie so writes settle
        dpi_veggie_tick(nRST);
    endtask

    // -----------------------------------------------------------------------
    // Sample ready signals from DUT → push to scheduler
    // RTL fu_global_status: bit0=VALU, bit1=MUL, bit2=DIV, bit3=EXP, bit4=SQRT
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
    // Main test loop
    // -----------------------------------------------------------------------
    initial begin
        $display("============================================================");
        $display(" Vector Core L1 Integration Testbench (DPI-C)");
        $display(" Program: %s", PROGRAM_PATH);
        $display("============================================================");

        cycle_count = 0;

        // Init all DPI models
        dpi_scheduler_init(PROGRAM_PATH);
        dpi_veggie_init();
        dpi_sysarr_init();
        dpi_scratchpad_init();

        // Reset
        apply_reset();
        $display("[TB] Reset released at cycle %0d", cycle_count);

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

            // 4) Tick scheduler
            dpi_scheduler_tick(nRST);

            // 5) Drive DUT from scheduler + veggie
            drive_lanes();
            drive_gsau_issue();
            drive_vlsu_issue();

            // 6) Respond to DUT's external requests
            respond_gsau();
            respond_vlsu();

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
                    $display("[TB] Cyc %0d: SP[%0d] vd=%0d rows=%0d cols=%0d",
                        cycle_count, p,
                        dpi_get_sp_vd(p),
                        dpi_get_sp_num_rows(p),
                        dpi_get_sp_num_cols(p));
            end

            // 8) Termination
            if (dpi_get_all_issued()) begin
                $display("[TB] All instructions issued at cycle %0d. Draining...", cycle_count);
                repeat (DRAIN_CYCLES) begin
                    @(posedge CLK);
                    cycle_count++;
                    handle_writeback();
                    respond_gsau();
                    respond_vlsu();
                end
                break;
            end

            if (cycle_count >= TIMEOUT) begin
                $display("[TB] TIMEOUT at cycle %0d!", cycle_count);
                break;
            end
        end

        // Cleanup
        dpi_scheduler_destroy();
        dpi_veggie_destroy();
        dpi_sysarr_destroy();
        dpi_scratchpad_destroy();

        $display("============================================================");
        $display(" Done. Total cycles: %0d", cycle_count);
        $display("============================================================");
        $finish;
    end

    // -----------------------------------------------------------------------
    // Waveform
    // -----------------------------------------------------------------------
    initial begin
        $dumpfile("vector_core_dpi_tb.vcd");
        $dumpvars(0, vector_core_dpi_tb);
    end

endmodule