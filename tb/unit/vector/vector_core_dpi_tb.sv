// ============================================================================
// vector_core_dpi_tb.sv
// L1 Integration Testbench - DPI-C driven
//
//  C++ models using DPI-C:
//   Scheduler -> instruction decode -> drive vif, gsauif
//   Veggie -> VRF reads/writes -> feed v1/v2 data to DUT
//   Sysarr -> systolic array sim -> respond to gsauif
//   Scratchpad -> scratchpad sim -> respond to sif
//
// This part is completely claude based rn, based off the old tb, 
// just using my new dpi-c stuff, will check later to see. rn just to check if runs
//
// Owner: Vedant Sharma
// ============================================================================

/*

Quick note for future Vedant, and for future readers in general. DO NOT BE A DUMBASS AND THINK THAT YOU ARE THE GOAT
DPI DOES NOT BEND TO YOUR WILL, QUESTA HATES YOU, SYSTEMVERILOG WANTS U DEAD. 

In other words, the unpacked arrays dont go through the version of questa we are using, and I'm too scared to try packed arrays
as it'll be wasting an hour (this a generous estimate), of my precious time.

IE for future vedant, cause I know yo dumbahh not gonna remember this, we are doing ELEMENT BY ELEMENT DPI CALLS, you are not tuff
stop thinking you are, you simple-minded plebian of a homosapien.

hello my name is Vedant and that was my TED Talk...

*/

`timescale 1ns/1ps

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "gsau_control_unit_if.vh"

module vector_core_dpi_tb;
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;
    import inst_parser_dpi_pkg::*;


    // yk ideally i should have a bunch of if_defs for whichever test case u want, but im hella lazy, do ts shit and give me a break breeeuhhhh
    parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/add_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/sub_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-vector/mul_vv";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/vreg_ld";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/load-store/vreg_st";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rsum_vi";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rmin_vi";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/vector-immediate/reduction/rmax_vi";
    //parameter string PROGRAM_PATH = "./tb/formal/vector/testcases/gemmm/gemm_vv";

    // for any singular instruct other than gemm_vv use the regular 40 cycles
    parameter int DRAIN_CYCLES = 40;

    // for testing gemm_vv use 150 drain cycles
    //parameter int DRAIN_CYCLES = 150;

    parameter int TIMEOUT = 10000;

    logic CLK;
    logic nRST;
    localparam int CLK_PERIOD = 10;

    initial begin
        CLK = 1'b0;
        forever #(CLK_PERIOD/2) CLK = ~CLK;
    end

    vector_if vif();
    gsau_control_unit_if gsauif();
    scpad_if sif(CLK, nRST);

    vector_datapath dut (
        .CLK(CLK),
        .nRST(nRST),
        .vif(vif),
        .sif(sif),
        .gsauif(gsauif)
    );

    int cycle_count;

    // Temp arrays for DPI vectors
    bit [15:0] tmp_vec  [0:31];
    bit [15:0] tmp_vec2 [0:31];

    function automatic vreg_t pack_vreg(bit [15:0] arr [0:31]);
        vreg_t v;
        for (int i = 0; i < 32; i++) v[i] = arr[i];
        return v;
    endfunction

    task automatic unpack_vreg(input vreg_t v, output bit [15:0] arr [0:31]);
        for (int i = 0; i < 32; i++) arr[i] = v[i];
    endtask

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
        clear_vlsu_port(0);
        clear_vlsu_port(1);
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

    task automatic drive_gsau_from_sys(
        input vreg_t data = '0,
        input logic valid = 1'b0,
        input logic ready = 1'b0
    );
        gsauif.sa_array_output = data;
        gsauif.sa_valid_in = valid;
        gsauif.sa_ready_in = ready;
    endtask

    task automatic drive_vlsu_from_sp(
        input int port,
        input logic valid = 1'b0,
        input logic write = 1'b0,
        input vreg_t data = '0,
        input logic stall = 1'b0
    );
        sif.vec_res[port].valid = valid;
        sif.vec_res[port].write = write;
        sif.vec_res[port].rdata = data;
        sif.fe_vec_stall[port] = stall;
    endtask

    task automatic apply_reset();
        nRST = 1'b0;
        clear_lane_port(0);
        clear_lane_port(1);
        clear_vlsu_port(0);
        clear_vlsu_port(1);
        clear_gsau_port();
        set_wb_ready({LANE_FU_COUNT{1'b1}}, {NUM_SCPADS{1'b1}}, 1'b1, 1'b1);

        sif.fe_vec_stall[0] = '0;
        sif.fe_vec_stall[1] = '0;
        sif.vec_res[0] = '0;
        sif.vec_res[1] = '0;
        gsauif.sa_ready_in = 1'b1;
        gsauif.sa_valid_in = 1'b0;
        gsauif.sa_array_output = '0;

        // testing to see if sched is being dumb
        //dpi_scheduler_tick(1'b0);
        dpi_sysarr_tick(1'b0);
        dpi_scratchpad_tick(1'b0);
        dpi_veggie_tick(1'b0);

        repeat (5) @(posedge CLK);
        nRST = 1'b1;
        repeat (5) @(posedge CLK);
    endtask


    task automatic drive_lanes();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_lane_valid_in(p)) begin
                // Read V1 from veggie element-by-element
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs1(p), e);

                // V2: broadcast scalar or VRF read
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

                // Mask
                /*if (dpi_get_mask_vmrf_mren(p)) begin
                    vif.lanes_in.lane_issue_ports[p].mask = dpi_veggie_get_mask_rdata(p);
                end else begin
                    vif.lanes_in.lane_issue_ports[p].mask = 32'hFFFFFFFF;
                end
                */

                // Mask — force all enabled for now
                vif.lanes_in.lane_issue_ports[p].mask = 32'hFFFFFFFF;

            end else begin
                clear_lane_port(p);
            end
        end
    endtask


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

    task automatic respond_gsau();
        // Push DUT's SA outputs into sysarr model element-by-element
        if (gsauif.sa_weight_en) begin
            unpack_vreg(gsauif.sa_array_in, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_sysarr_set_weight_elem(e, tmp_vec[e]);
            dpi_sysarr_set_weight_valid(1'b1);
        end else begin
            dpi_sysarr_set_weight_valid(1'b0);
        end

        if (gsauif.sa_input_en) begin
            unpack_vreg(gsauif.sa_array_in, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_sysarr_set_activation_elem(e, tmp_vec[e]);
            dpi_sysarr_set_activation_valid(1'b1);
        end else begin
            dpi_sysarr_set_activation_valid(1'b0);
        end

        // Tick sysarr
        dpi_sysarr_tick(nRST);

        $display("[TB-SA-DBG] Cyc %0d: w_en=%0b i_en=%0b sa_valid=%0b sa_ready=%0b",
            cycle_count, gsauif.sa_weight_en, gsauif.sa_input_en,
            dpi_sysarr_get_valid(), dpi_sysarr_get_ready());

        // Drive results back
        if (dpi_sysarr_get_valid()) begin
            for (int e = 0; e < 32; e++)
                tmp_vec[e] = dpi_sysarr_get_output_elem(e);
            drive_gsau_from_sys(
                .data(pack_vreg(tmp_vec)),
                .valid(1'b1),
                .ready(dpi_sysarr_get_ready())
            );
        end else begin
            drive_gsau_from_sys(
                .ready(dpi_sysarr_get_ready())
            );
        end
    endtask

    task automatic drive_vlsu_issue();
        for (int p = 0; p < 2; p++) begin
            if (dpi_get_sp_valid_in(p)) begin
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_veggie_read_vector_elem(dpi_get_veggie_vs1(p), e);

                vif.vlsu_in.sched_req[p].valid      = 1'b1;
                vif.vlsu_in.sched_req[p].write       = (dpi_get_sp_wen(p) == 1) ? 1'b1 : 1'b0;
                vif.vlsu_in.sched_req[p].spad_addr   = dpi_get_sp_sid(p);
                vif.vlsu_in.sched_req[p].vdst        = dpi_get_sp_vd(p);
                vif.vlsu_in.sched_req[p].num_cols    = dpi_get_sp_num_cols(p);
                vif.vlsu_in.sched_req[p].row_id      = dpi_get_sp_row_num(p);

                vif.vlsu_in.vrf_data[p].data  = pack_vreg(tmp_vec);
                vif.vlsu_in.vrf_data[p].valid = 1'b1;
            end else begin
                clear_vlsu_port(p);
            end
        end
    endtask

    task automatic respond_vlsu();
        for (int p = 0; p < NUM_SCPADS; p++) begin
            dpi_scratchpad_set_request(
                p,
                sif.vec_req[p].valid,
                sif.vec_req[p].write,
                sif.vec_req[p].spad_addr,
                sif.vec_req[p].row_id,
                '0,                          // col_id (removed)
                sif.vec_req[p].num_rows,
                sif.vec_req[p].num_cols,
                1'b0                         // row_or_col (removed, default row)
            );

            if (sif.vec_req[p].write && sif.vec_req[p].valid) begin
                unpack_vreg(sif.vec_req[p].wdata, tmp_vec);
                for (int e = 0; e < 32; e++)
                    dpi_scratchpad_write_elem(p, e, tmp_vec[e]);
            end

            if (sif.vec_req[p].valid)
                $display("[TB-SPREQ] Cyc %0d: port=%0d write=%0b addr=%h row=%0d nrows=%0d ncols=%0d",
                    cycle_count, p, sif.vec_req[p].write, sif.vec_req[p].spad_addr,
                    sif.vec_req[p].row_id, sif.vec_req[p].num_rows, sif.vec_req[p].num_cols);
        end

        dpi_scratchpad_tick(nRST);

        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (dpi_scratchpad_get_valid(p))
                $display("[TB-SP] Cyc %0d: SP[%0d] response valid, rdata[0]=%h", cycle_count, p, dpi_scratchpad_read_elem(p, 0));
        end

        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (dpi_scratchpad_get_valid(p)) begin
                for (int e = 0; e < 32; e++)
                    tmp_vec[e] = dpi_scratchpad_read_elem(p, e);
                drive_vlsu_from_sp(p, .valid(1'b1), .data(pack_vreg(tmp_vec)));
            end else begin
                drive_vlsu_from_sp(p);
            end
        end
    endtask

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
        end

        // VLSU load writeback → veggie write element-by-element
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vif.vlsu_out.wb[p].valid) begin
                unpack_vreg(vif.vlsu_out.wb[p].load_data, tmp_vec);
                for (int e = 0; e < 32; e++)
                    dpi_veggie_write_vector_elem(
                        vif.vlsu_out.wb[p].vdst, e, tmp_vec[e]);
            end
        end

        // Debug VLSU writeback
        for (int p = 0; p < NUM_SCPADS; p++) begin
            if (vif.vlsu_out.wb[p].valid)
                $display("[TB-WB] Cyc %0d: VLSU wb[%0d] valid, vdst=%0d", cycle_count, p, vif.vlsu_out.wb[p].vdst);
        end

        // Reduction writeback → veggie write element-by-element
        if (vif.lanes_out.reduction.wb_valid) begin
            unpack_vreg(vif.lanes_out.reduction.vector_output, tmp_vec);
            for (int e = 0; e < 32; e++)
                dpi_veggie_write_vector_elem(
                    vif.lanes_out.reduction.vd_output, e, tmp_vec[e]);
            $display("[TB-RED] Reduction WB: vd=%0d data[0]=%h", 
                vif.lanes_out.reduction.vd_output, tmp_vec[0]);
        end
    endtask

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
            1'b1,           // exp (not done yet)
            gsau_rdy,
            (vlsu_rdy != 0) ? 1'b1 : 1'b0
        );
    endtask

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

        // Preloading VRF with test data
        // Preload VRF with test data attempt 2
        // Preload VRF element by element attempt 3 lmfao (avoids open array handle issues)
        // my dumbahh fucked up the register numbers for the test case bruhhhhhhhhhh

        // Preload VRF — simple 1.0 + 1.0 = 2.0
        // bf16 1.0 = 0x3F80
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd2, i, 16'h3F80);  // vs1 = 1.0
            dpi_veggie_write_vector_elem(8'd3, i, 16'h3F80);  // vs2 = 1.0
        end
        $display("[TB] Preloaded v1 and v2 with test vectors");
        

        /*
        // Preload VRF — 3.0 - 1.0 = 2.0
        // bf16 3.0 = 0x4040, bf16 1.0 = 0x3F80
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd5, i, 16'h4040);  // vs1 = 3.0
            dpi_veggie_write_vector_elem(8'd6, i, 16'h3F80);  // vs2 = 1.0
        end
        */

        // Preload VRF — 2.0 * 3.0 = 6.0
        // bf16 2.0 = 0x4000, bf16 3.0 = 0x4040
        /*
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd8, i, 16'h4000);  // vs1 = 2.0
            dpi_veggie_write_vector_elem(8'd9, i, 16'h4040);  // vs2 = 3.0
        end
        */

        // Preload mask register 0 with all enabled
        dpi_veggie_write_mask(8'd0, 32'hFFFFFFFF);
        $display("[TB] Preloaded mask register 0");

        // Preload scratchpad at addr=1 (matching DUT request)
        for (int r = 0; r < 32; r++) begin
            dpi_scratchpad_preload_row_val(0, 8'd1, r[7:0], 8'd32, 16'h3F80);
            dpi_scratchpad_preload_row_val(1, 8'd1, r[7:0], 8'd32, 16'h3F80);
        end
        $display("[TB] Preloaded scratchpad addr=1 with 1.0");

        // Preload v0 for store test
        /*
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd0, i, 16'hBEEF);
        end
        */

        // Preload v0 with 1.0 for reduction sum (32 * 1.0 = 32.0)
        /*
        for (int i = 0; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);
        end
        */

        // Preload VRF for gemm: weights in v0-v31, activations in v32-v64
        /*
        for (int v = 0; v < 32; v++) begin
            for (int e = 0; e < 32; e++) begin
                dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);      // weights = 1.0
            end
        end
        for (int v = 32; v <= 64; v++) begin
            for (int e = 0; e < 32; e++) begin
                dpi_veggie_write_vector_elem(v[7:0], e, 16'h3F80);      // activations = 1.0
            end
        end
        $display("[TB] Preloaded VRF for gemm test");
        */

        // Preload v0: element 0 = 1.0 (0x3F80), rest = 5.0 (0x40A0)
        /*
        dpi_veggie_write_vector_elem(8'd0, 0, 16'h3F80);  // 1.0 = min
        for (int i = 1; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd0, i, 16'h40A0);  // 5.0
        end
        */

        // Preload v0: element 0 = 10.0 (0x4120), rest = 1.0 (0x3F80)
        /*
        dpi_veggie_write_vector_elem(8'd0, 0, 16'h4120);  // 10.0 = max
        for (int i = 1; i < 32; i++) begin
            dpi_veggie_write_vector_elem(8'd0, i, 16'h3F80);  // 1.0
        end
        */

        // ---- Main loop ----
        forever begin
            @(posedge CLK);
            cycle_count++;

            // 1) Handle writeback from previous cycle (DUT -> veggie)
            handle_writeback();

            // 2) Clear ports from previous cycle
            clear_all_ports();

            // 3) Sample DUT ready -> push to scheduler
            sample_and_push_ready();

            // 4) Tick scheduler
            dpi_scheduler_tick(nRST);

            $display("[TB-RM] Cyc %0d: reduction_mode=%0b", cycle_count, dpi_get_reduction_mode());

            // Debug: print lane valid + all_issued
            $display("[TB-DBG] Cyc %0d: lane0_valid=%0b lane1_valid=%0b all_issued=%0b",
                cycle_count,
                dpi_get_lane_valid_in(0),
                dpi_get_lane_valid_in(1),
                dpi_get_all_issued());

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
                    $display("[TB] Cyc %0d: SP[%0d] vd=%0d row=%0d cols=%0d",
                        cycle_count, p,
                        dpi_get_sp_vd(p),
                        dpi_get_sp_row_num(p),
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
                // Verify load result in VRF
                $display("[TB] Verifying VRF v0 after load:");
                for (int e = 0; e < 4; e++)
                    $display("[TB]   v0[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd0, e));
                break;
            end

            if (cycle_count >= TIMEOUT) begin
                $display("[TB] TIMEOUT at cycle %0d!", cycle_count);
                break;
            end
        end

        $display("[TB] Verify v1 (reduction dest):");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v1[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd1, e));

        $display("[TB] Verify v2 (rmin dest):");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v2[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd2, e));

        $display("[TB] Verify v3 (rmax dest):");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v3[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd3, e));

        // Verify gemm results
        $display("[TB] Verify gemm output (v65):");
        for (int e = 0; e < 4; e++)
            $display("[TB]   v65[%0d] = %h", e, dpi_veggie_read_vector_elem(8'd65, e));

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

    initial begin
        $dumpfile("vector_core_dpi_tb.vcd");
        $dumpvars(0, vector_core_dpi_tb);
    end

endmodule