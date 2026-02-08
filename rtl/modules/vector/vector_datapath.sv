// ------------------------------------------------------------
// vector_datapath.sv (formerly vector_top.sv)
// Top-level glue: vector_in -> MaskU -> Lanes[NUM_LANES]
//               -> Result Collector + Reduction Tree (VALU rm)
// Multi-issue using LANE_ISSUE_W issue slots.
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"
`include "gsau_control_unit_if.vh"

module vector_datapath (
    input  logic     CLK,
    input  logic     nRST,
    vector_if        vif      // NOTE: use full interface, not modport .vector
);
    import vector_pkg::*;
    import reduction_pkg::*;


    // GLOBAL UNITS ############################################
    gsau_control_unit_if gsau_if();

    gsau_control_unit #(
        .VEGGIEREGS(NUM_VREGS),
        .FIFOSIZE(1536)
    ) u_gsau (
        .CLK (CLK),
        .nRST(nRST),
        .gsau_port(gsau_if.gsau)
    );

    // ------------ Top-level vector_in.gsau → GSAU inputs -------------
    // Veggie → GSAU
    assign gsau_if.veg_vdata1        = vif.vector_in.gsau.veg_vdata1;
    assign gsau_if.veg_vdata2        = vif.vector_in.gsau.veg_vdata2;
    assign gsau_if.veg_valid         = vif.vector_in.gsau.veg_valid;

    // Scoreboard → GSAU
    assign gsau_if.sb_vdst           = vif.vector_in.gsau.sb_vdst;
    assign gsau_if.sb_valid          = vif.vector_in.gsau.sb_valid;
    assign gsau_if.sb_weight         = vif.vector_in.gsau.sb_weight;

    // WB buffer → GSAU
    assign gsau_if.wb_output_ready   = vif.vector_in.gsau.wb_output_ready;

    // Systolic array → GSAU
    assign gsau_if.sa_array_output   = vif.vector_in.gsau.sa_array_output;
    assign gsau_if.sa_out_valid      = vif.vector_in.gsau.sa_out_valid;
    assign gsau_if.sa_fifo_has_space = vif.vector_in.gsau.sa_fifo_has_space;

    // ------------ GSAU outputs → vector_out.gsau -------------
    // GSAU → Veggie
    assign vif.vector_out.gsau.veg_ready        = gsau_if.veg_ready;

    // GSAU → Scoreboard
    assign vif.vector_out.gsau.sb_ready         = gsau_if.sb_ready;

    // GSAU → WB buffer
    assign vif.vector_out.gsau.wb_psum          = gsau_if.wb_psum;
    assign vif.vector_out.gsau.wb_wbdst         = gsau_if.wb_wbdst;
    assign vif.vector_out.gsau.wb_valid         = gsau_if.wb_valid;

    // GSAU → Systolic array
    assign vif.vector_out.gsau.sa_array_in          = gsau_if.sa_array_in;
    assign vif.vector_out.gsau.sa_array_in_partials = gsau_if.sa_array_in_partials;
    assign vif.vector_out.gsau.sa_input_en          = gsau_if.sa_input_en;
    assign vif.vector_out.gsau.sa_weight_en         = gsau_if.sa_weight_en;
    assign vif.vector_out.gsau.sa_partial_en        = gsau_if.sa_partial_en;
    assign vif.vector_out.gsau.sa_output_ready      = gsau_if.sa_output_ready;


    // LANE DATAPATH ###########################################

    // --------------------------------------------------------
    // 0. Hook global clock/reset into the interface itself
    // --------------------------------------------------------
    assign vif.CLK  = CLK;
    assign vif.nRST = nRST;

    // --------------------------------------------------------
    // 1. Per-lane vector_if instances and lane instantiation
    // --------------------------------------------------------
    vector_if lane_if[NUM_LANES]();

    genvar ln;
    generate
        for (ln = 0; ln < NUM_LANES; ln++) begin : GEN_LANES
            assign lane_if[ln].CLK  = CLK;
            assign lane_if[ln].nRST = nRST;

            lane #(
                .LANE_ID(ln)
            ) u_lane (
                .CLK (CLK),
                .nRST(nRST),
                .lif (lane_if[ln])
            );
        end
    endgenerate

    // --------------------------------------------------------
    // 1a. Reduction control (VALU rm)
    // --------------------------------------------------------
    // Global "this op is a VALU reduction" + op + destination vd
    logic       reduction_mode;
    logic [1:0] reduction_op;
    vsel_t      reduction_vd;

    always_comb begin
        reduction_mode = 1'b0;
        reduction_op   = 2'b10; // default SUM
        reduction_vd   = '0;

        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (vif.vector_in.valid_in[i] &&
                vif.vector_in.rm[i] &&
                (vif.vector_in.fu_sel[i] == VALU)) begin
                reduction_mode = 1'b1;
                reduction_op   = vif.vector_in.vop[i][1:0];
                reduction_vd   = vif.vector_in.vd[i];
            end
        end
    end

    // --------------------------------------------------------
    // 2. Mask Unit (pick first valid issue slot's mask)
    // --------------------------------------------------------
    always_comb begin
        logic   found_valid;
        vmask_t eff_mask;
        int     i;

        found_valid  = 1'b0;
        eff_mask     = '0;
        vif.masku_in = '0;

        for (i = 0; i < LANE_ISSUE_W; i++) begin
            if (!found_valid && vif.vector_in.valid_in[i]) begin
                found_valid = 1'b1;
                eff_mask    = vif.vector_in.vmask[i];
            end
        end

        vif.masku_in.vm    = found_valid;
        vif.masku_in.vmask = eff_mask;
    end

    masku u_masku (
        .vif(vif)
    );

        // --------------------------------------------------------
    // 3. Map vector_in (multi-issue) -> lane_in for each lane/FU
    //    Robust version:
    //      - ready_in stays combinational
    //      - data/metadata (v1/v2/vmask/vd/vop/rm/valid_in) are
    //        registered so they are stable when the sequencer
    //        samples them.
    // --------------------------------------------------------

    // Reduction interface (needs to be visible where ready_in is set)
    vreduction_if vruif();

    genvar l_gen;
    generate
        for (l_gen = 0; l_gen < NUM_LANES; l_gen++) begin : GEN_LANE_IN_MAP

            // -----------------------------
            // 3a. READY path: pure combinational
            // -----------------------------
            always_comb begin : READY_PATH
                for (int fu = 0; fu < LANE_FU_COUNT; fu++) begin
                    if (fu == VALU) begin
                        lane_if[l_gen].lane_in.ready_in[fu] =
                            (reduction_mode ? vruif.out.ready_in
                                            : vif.rc_out.ready_in[fu]);
                    end
                    else begin
                        lane_if[l_gen].lane_in.ready_in[fu] =
                            vif.rc_out.ready_in[fu];
                    end
                end
            end

            // -----------------------------
            // 3b. DATA / METADATA path: registered
            // -----------------------------
            always_ff @(posedge CLK or negedge nRST) begin : LANE_IN_REG
                int    i;
                fu_t   fu_i;
                int    base;

                if (!nRST) begin
                    lane_if[l_gen].lane_in.v1       <= '{default:'0};
                    lane_if[l_gen].lane_in.v2       <= '{default:'0};
                    lane_if[l_gen].lane_in.vmask    <= '{default:'0};
                    lane_if[l_gen].lane_in.vd       <= '{default:'0};
                    lane_if[l_gen].lane_in.vop      <= '{default:'0};
                    lane_if[l_gen].lane_in.rm       <= '{default:'0};
                    lane_if[l_gen].lane_in.valid_in <= '{default:1'b0};
                end
                else begin
                    // By default, no new slice issued this cycle
                    lane_if[l_gen].lane_in.valid_in <= '{default:1'b0};

                    // For each issue slot, if it's valid, update that FU's slice
                    for (i = 0; i < LANE_ISSUE_W; i++) begin
                        if (vif.vector_in.valid_in[i]) begin
                            fu_i = vif.vector_in.fu_sel[i];
                            base = l_gen * SLICE_W;

                            // Slice data for this lane/FU
                            lane_if[l_gen].lane_in.v1[fu_i]    <=
                                vif.vector_in.v1[i][base +: SLICE_W];
                            lane_if[l_gen].lane_in.v2[fu_i]    <=
                                vif.vector_in.v2[i][base +: SLICE_W];
                            lane_if[l_gen].lane_in.vmask[fu_i] <=
                                vif.masku_out.mask[l_gen];

                            // Metadata
                            lane_if[l_gen].lane_in.vd[fu_i]       <= vif.vector_in.vd[i];
                            lane_if[l_gen].lane_in.vop[fu_i]      <= vif.vector_in.vop[i];
                            lane_if[l_gen].lane_in.rm[fu_i]       <= vif.vector_in.rm[i];
                            lane_if[l_gen].lane_in.valid_in[fu_i] <= 1'b1;
                        end
                    end
                end
            end
        end
    endgenerate

    // --------------------------------------------------------
    // 3c. Compute global ready signals (Per FU)
    // --------------------------------------------------------
    logic [LANE_FU_COUNT-1:0][NUM_LANES-1:0] lane_ready_transposed;

    genvar lg, fug;
    generate
    for (lg = 0; lg < NUM_LANES; lg++) begin : FLAT_READY
        for (fug = 0; fug < LANE_FU_COUNT; fug++) begin : FLAT_READY_FU
        assign lane_ready_transposed[fug][lg] =
            lane_if[lg].lane_out.ready_o[fug];
        end
    end
    endgenerate

    logic [LANE_FU_COUNT-1:0] fu_global_ready;

    always_comb begin : FU_GLOBAL_READY
    logic all_lanes_ready;
    //logic wb_ready;

    for (int f = 0; f < LANE_FU_COUNT; f++) begin
        all_lanes_ready = (&lane_ready_transposed[f]);

        // if (f == VALU && reduction_mode) begin
        // wb_ready = vruif.out.ready_in;
        // end else begin
        // wb_ready = vif.rc_out.ready_in[f];
        // end

        fu_global_ready[f] = all_lanes_ready;
    end
    end

    always_comb begin : ISSUE_READY_OUT
    fu_t fu_i;
    for (int i = 0; i < LANE_ISSUE_W; i++) begin
        fu_i = vif.vector_in.fu_sel[i];

        if (!vif.vector_in.valid_in[i]) begin
            vif.vector_out.ready_o[i] = 1'b1;
        end else begin
            vif.vector_out.ready_o[i] = fu_global_ready[fu_i];
        end
    end
    end


    // --------------------------------------------------------
    // 4. Result Collector
    // --------------------------------------------------------
    result_collector u_result_collector (
        .CLK (CLK),
        .nRST(nRST),
        .rcif(vif)
    );

    // 4a. Lanes' outputs -> rc_in
    genvar l_rc;
    generate
        for (l_rc = 0; l_rc < NUM_LANES; l_rc++) begin : GEN_RC_IN_MAP
            always_comb begin
                int fu;
                for (fu = 0; fu < LANE_FU_COUNT; fu++) begin
                    vif.rc_in.result   [l_rc][fu] = lane_if[l_rc].lane_out.result  [fu];
                    vif.rc_in.valid_in [l_rc][fu] = lane_if[l_rc].lane_out.valid_o [fu];
                    vif.rc_in.vd       [l_rc][fu] = lane_if[l_rc].lane_out.vd      [fu];
                    vif.rc_in.elem_idx [l_rc][fu] = lane_if[l_rc].lane_out.elem_idx[fu];
                    vif.rc_in.last     [l_rc][fu] = lane_if[l_rc].lane_out.last    [fu];

                    // This is "ready from WB buffer into RC"; keep simple for now
                    vif.rc_in.ready_in [l_rc][fu] = 1'b1;
                end
            end
        end
    endgenerate

    // --------------------------------------------------------
    // 4c. Reduction Tree (VALU rm path)
    // --------------------------------------------------------

    vreduction #(
        .LANES(NUM_LANES)
    ) u_vreduction (
        .CLK (CLK),
        .nRST(nRST),
        .vruif(vruif.ruif)
    );

    // Tap per-lane VALU reduction scalars into a plain array
    logic [NUM_LANES-1:0][15:0] lane_rval_valu;

    genvar l_red;
    generate
        for (l_red = 0; l_red < NUM_LANES; l_red++) begin : GEN_REDUCE_TAP
            assign lane_rval_valu[l_red] = lane_if[l_red].lane_out.rval[VALU];
        end
    endgenerate

    // Drive the reduction tree input
    logic reduce_fire_any;

    always_comb begin
        reduce_fire_any = 1'b0;
        vruif.in        = '0;

        // Assume next stage always ready for now
        vruif.in.ready_out = 1'b1;

        for (int l = 0; l < NUM_LANES; l++) begin
            vruif.in.lane_input[l] = lane_rval_valu[l];

            if (lane_rval_valu[l] != '0)
                reduce_fire_any = 1'b1;
        end

        vruif.in.valid_in       = reduction_mode & reduce_fire_any;
        vruif.in.reduction_type = reduction_op;
        // vector_input / broadcast / clear / imm left at '0 for now
    end

    // --------------------------------------------------------
    // 5. rc_out -> vector_out (normal FU path + reduction fields)
    // --------------------------------------------------------
    assign vif.vector_out.result  = vif.rc_out.result;
    assign vif.vector_out.valid_o = vif.rc_out.valid_o;
    assign vif.vector_out.vd      = vif.rc_out.vd;

    // Reduction result
    assign vif.vector_out.reduction_result = vruif.out.vector_output;
    assign vif.vector_out.reduction_valid  = vruif.out.valid_out;
    assign vif.vector_out.reduction_vd     = reduction_vd;

    // --------------------------------------------------------
    // 6. Performance Counters
    // --------------------------------------------------------

    /*
    perf_handshake #(.SIG_WIDTH(LANE_ISSUE_W)) u_perf_handshake_vec (
        .CLK(CLK),
        .nRST(nRST),
        .valid(vif.vector_in.valid_in),
        .ready(vif.vector_out.ready_o)
    );

    perf_handshake  u_perf_handshake_gsau_veggie (
        .CLK(CLK),
        .nRST(nRST),
        .valid(vif.vector_in.gsau.veg_valid),
        .ready(vif.vector_out.gsau.veg_ready)
    );
    */

endmodule
