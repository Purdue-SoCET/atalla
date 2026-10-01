/*
Vector top level

This is the full integration of the vector core

This 100% doesnt meet code standards, but i have woreked 46 hours over the course of 6 days so ill fix it when i have time
Owner: Jacob Walter
*/
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "lane_if.vh"
`include "result_collector_if.vh"
`include "gsau_control_unit_if.vh"
`include "reduction_FU_if.vh"
`include "transpose_unit_if.vh"


module vector_datapath (
    input  logic     CLK,
    input  logic     nRST,
    vector_if           vif,
    scpad_if.vec_frontend  sif,
    gsau_control_unit_if.gsau gsauif
);
    `include "scpad_params.svh"
    import vector_pkg::*;
    import scpad_pkg::*;

    logic [LANE_FU_COUNT-1:0][NUM_LANES-1:0] fu_lane_readies;

    //interface definitons
    lane_if lane_interfaces [NUM_LANES-1:0]();
    result_collector_if rc_interfaces [LANE_FU_COUNT]();

    //slicer
    slicer slicer_inst (
        .vif(vif.lanes),
        .lif(lane_interfaces)
    );

    //lanes instanciation
    genvar ln_i;
    generate
        for (ln_i = 0; ln_i < NUM_LANES; ln_i ++) begin : lane_gen
            lane lane_inst (
                .CLK(CLK),
                .nRST(nRST),
                .lif(lane_interfaces[ln_i].lif)
            );
        end
        
    endgenerate

    //lane->result collector connections
    //not modports cause im not in the mood to fix it right now, might move this logic into the RC
    //modports might entail adding an IF connection for every single FU to each FU
    //I think this should work well enough for now
    genvar i, j;
    generate
        for (i = 0; i < LANE_FU_COUNT; i++) begin : gen_rc_fu
            for (j = 0; j < NUM_LANES; j++) begin : gen_rc_lane
                always_comb begin : rc_lane_connection
                    // Per-lane, per-FU signals
                    if (i == 0) begin
                        rc_interfaces[i].in.input_valid[j] = lane_interfaces[j].out.units[i].wb_valid & !(lane_interfaces[j].out.units[i].rm);
                        
                    end 
                    else begin
                        rc_interfaces[i].in.input_valid[j] = lane_interfaces[j].out.units[i].wb_valid;
                    end
                    rc_interfaces[i].in.lane_input[j] = lane_interfaces[j].out.units[i].result;
                    rc_interfaces[i].in.mask[j]       = lane_interfaces[j].out.units[i].mask;
                    lane_interfaces[j].in.ready[i] = rc_interfaces[i].out.input_ready;
                end
            end : gen_rc_lane

            always_comb begin : rc_scalar_connection
                rc_interfaces[i].in.vd_input  = lane_interfaces[0].out.units[i].vd;
                //rc_interfaces[2].in.mop_in = 'b0;
            end
        end : gen_rc_fu
    endgenerate

    always_comb begin
        rc_interfaces[0].in.mop_in = lane_interfaces[0].out.units[0].mop_out;
        rc_interfaces[1].in.mop_in = 'b0;
    end

 

    genvar rc_i;
    generate
        for (rc_i = 0; rc_i < LANE_FU_COUNT; rc_i++) begin : rc_gen
            result_collector rc_inst (
                .CLK(CLK),
                .nRST(nRST),
                .rcif(rc_interfaces[rc_i])
            );
        end
    endgenerate

    // =========================================================================
    // Transpose Unit (FU slot 2)
    // =========================================================================
    transpose_unit_if #(.VEC_LEN(NUM_ELEMENTS), .DATA_W(ESZ)) tu_if();

    transpose_unit tu_inst (
        .CLK(CLK),
        .nRST(nRST),
        .tif(tu_if.transpose)
    );

    logic tu_issue_valid;
    logic tu_is_push;
    logic tu_is_pop;
    vreg_t tu_issue_v1;
    logic [7:0] tu_issue_vd;

    always_comb begin
        tu_issue_valid = 1'b0;
        tu_is_push     = 1'b0;
        tu_is_pop      = 1'b0;
        tu_issue_v1    = '0;
        tu_issue_vd    = '0;

        if (vif.lanes_in.lane_issue_ports[0].input_valid && (vif.lanes_in.lane_issue_ports[0].usel == TRANS)) begin
            tu_issue_valid = 1'b1;
            tu_is_push     = (vif.lanes_in.lane_issue_ports[0].alu_op == TU_PUSH);
            tu_is_pop      = (vif.lanes_in.lane_issue_ports[0].alu_op == TU_POP);
            tu_issue_v1    = vif.lanes_in.lane_issue_ports[0].v1;
            tu_issue_vd    = vif.lanes_in.lane_issue_ports[0].vd;
        end else if (vif.lanes_in.lane_issue_ports[1].input_valid && (vif.lanes_in.lane_issue_ports[1].usel == TRANS)) begin
            tu_issue_valid = 1'b1;
            tu_is_push     = (vif.lanes_in.lane_issue_ports[1].alu_op == TU_PUSH);
            tu_is_pop      = (vif.lanes_in.lane_issue_ports[1].alu_op == TU_POP);
            tu_issue_v1    = vif.lanes_in.lane_issue_ports[1].v1;
            tu_issue_vd    = vif.lanes_in.lane_issue_ports[1].vd;
        end
    end

    vreg_t tu_push_vec_r;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            tu_push_vec_r <= '0;
        end else if (tu_issue_valid && tu_is_push) begin
            tu_push_vec_r <= tu_issue_v1;
        end
    end

    assign tu_if.in.push_req  = tu_issue_valid && tu_is_push;
    assign tu_if.in.pop_req   = tu_issue_valid && tu_is_pop;
    assign tu_if.in.valid_in  = tu_issue_valid && tu_is_push;
    assign tu_if.in.vec_in    = (tu_issue_valid && tu_is_push) ? tu_issue_v1 : tu_push_vec_r;
    assign tu_if.in.ready_out = vif.wb_ready_signals.lanes_wb_ready[2];

    logic [7:0] tu_base_vd_r,  tu_base_vd_next;
    logic [4:0] tu_pop_cnt_r,  tu_pop_cnt_next;
    logic       tu_popping_r,  tu_popping_next;

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            tu_base_vd_r <= '0;
            tu_pop_cnt_r <= '0;
            tu_popping_r <= 1'b0;
        end else begin
            tu_base_vd_r <= tu_base_vd_next;
            tu_pop_cnt_r <= tu_pop_cnt_next;
            tu_popping_r <= tu_popping_next;
        end
    end

    always_comb begin
        tu_base_vd_next = tu_base_vd_r;
        tu_pop_cnt_next = tu_pop_cnt_r;
        tu_popping_next = tu_popping_r;

        if (tu_issue_valid && tu_is_pop) begin
            tu_base_vd_next = tu_issue_vd;
            tu_pop_cnt_next = 5'd0;
            tu_popping_next = 1'b1;
        end

        if (tu_popping_r && tu_if.out.valid_out && vif.wb_ready_signals.lanes_wb_ready[2]) begin
            if (tu_pop_cnt_r == 5'd31) begin
                tu_pop_cnt_next = 5'd0;
                tu_popping_next = 1'b0;
            end else begin
                tu_pop_cnt_next = tu_pop_cnt_r + 1'b1;
            end
        end
    end

    // RC connections: slots 0 (ALU) & 1 (MUL) from RC, slot 2 (TRANS) from TU
    genvar rc_vif_i;
    generate
        for (rc_vif_i = 0; rc_vif_i < 2; rc_vif_i++) begin : gen_rc_vif_connection
            always_comb begin : rc_vif_connection
                vif.lanes_out.result_collectors[rc_vif_i] = rc_interfaces[rc_vif_i].out;
                rc_interfaces[rc_vif_i].in.wb_ready = vif.wb_ready_signals.lanes_wb_ready[rc_vif_i];
            end
        end
    endgenerate

    always_comb begin : tu_rc_connection
        rc_interfaces[2].in.wb_ready = 1'b0;
        vif.lanes_out.result_collectors[2].input_ready   = '0;
        vif.lanes_out.result_collectors[2].wb_valid      = tu_if.out.valid_out;
        vif.lanes_out.result_collectors[2].vector_output = tu_if.out.vec_out;
        vif.lanes_out.result_collectors[2].vd_output     = tu_base_vd_r + {3'b000, tu_pop_cnt_r};
        vif.lanes_out.result_collectors[2].mop_out       = 1'b0;
    end

    // Lanes ready to vif out: slots 0 & 1 from lane readies, slot 2 from TU
    genvar ready_vif_i, ready_vif_j;
    generate
        for (ready_vif_i = 0; ready_vif_i < 2; ready_vif_i++) begin : gen_fu_ready
            for (ready_vif_j = 0; ready_vif_j < NUM_LANES; ready_vif_j++) begin : gen_lane_ready
                always_comb begin : ready_vif_connection
                    fu_lane_readies[ready_vif_i][ready_vif_j] = lane_interfaces[ready_vif_j].out.units[ready_vif_i].input_ready;
                end
            end

            always_comb begin : fu_status_connection
                vif.unit_ready_signals.fu_global_status[ready_vif_i] = (&fu_lane_readies[ready_vif_i]);
            end
        end
    endgenerate

    assign vif.unit_ready_signals.fu_global_status[2] = tu_if.out.ready_in && !tu_popping_r && !tu_issue_valid;
    

    
    //VLSU
    vlsu_if vlsuif();
    genvar vlsu_i;
    generate 
        for (vlsu_i = 0; vlsu_i < NUM_SCPADS; vlsu_i++) begin : gen_vlsu_connections
            vlsu #(.IDX(vlsu_i)) vlsu_inst (
                .CLK(CLK),
                .nRST(nRST),
                .vif(vlsuif),
                .sif(sif)
            );

            assign vlsuif.sched_req[vlsu_i] = vif.vlsu_in.sched_req[vlsu_i];
            assign vlsuif.vrf_store[vlsu_i] = vif.vlsu_in.vrf_data[vlsu_i];
            assign vlsuif.wb_ready[vlsu_i] = vif.wb_ready_signals.vlsu_wb_ready[vlsu_i];

            assign vif.vlsu_out.wb[vlsu_i] = vlsuif.wb_out[vlsu_i];
            assign vif.vlsu_out.status[vlsu_i] = vlsuif.status[vlsu_i];
            assign vif.unit_ready_signals.vlsu_status[vlsu_i] = vlsuif.sched_res[vlsu_i].ready;
        end
    endgenerate


    //GSAU
    gsau_control_unit_if gsuaif();
    gsau_control_unit gsau(
        .CLK(CLK),
        .nRST(nRST),
        .gsau_port(gsauif)
    );

    //connect the gsau to the vif
    //again this is horrible but fixing this can be a L2 problem
    always_comb begin : gsau_connections
        //non syarr gsau inputs
        gsauif.veg_vdata1 = vif.gsau_in.veg_vdata1;
        gsauif.veg_vdata2 = vif.gsau_in.veg_vdata2;
        gsauif.sb_vdst =  vif.gsau_in.vd;
        gsauif.sb_valid_in = vif.gsau_in.valid_in;
        gsauif.sb_weight = vif.gsau_in.weight;
        gsauif.wb_ready_in = vif.wb_ready_signals.gsau_wb_ready;
        //non sysarr gsau outputs
        vif.unit_ready_signals.gsau_status = gsauif.sb_ready_out;
        vif.gsau_out.ready_out = gsauif.sb_ready_out;
        vif.gsau_out.psum = gsauif.wb_psum;
        vif.gsau_out.vd = gsauif.wb_wbdst;
        vif.gsau_out.wb_valid = gsauif.wb_valid_out;
        
    end

    //reduction tree
    reduction_FU_if ruif();
    reduction_FU reduction (
        .CLK(CLK),
        .nRST(nRST),
        .ruif(ruif)
    );

    //connections to reduction
    genvar vri;
    generate
        for (vri = 0; vri < NUM_LANES; vri++) begin : collect_lane_inputs
            assign ruif.in.lane_input[vri] = lane_interfaces[vri].out.units[0].result;
        end
    endgenerate

    always_comb begin : reduction_connections
        ruif.in.ports = vif.lanes_in.lane_issue_ports; 

        ruif.in.lane_valid = lane_interfaces[0].out.units[0].wb_valid & lane_interfaces[0].out.units[0].rm;
        
        ruif.in.wb_ready = vif.wb_ready_signals.reduction_wb_ready;
        
        vif.lanes_out.reduction = ruif.out;

        vif.unit_ready_signals.reduction_status = vif.lanes_out.reduction.input_ready;
    end


endmodule