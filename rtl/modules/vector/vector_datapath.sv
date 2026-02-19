/*
Vector top level

This is the full integration of the vector core

Owner: Jacob Walter
*/
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "lane_if.vh"
`include "result_collector_if.vh"

module vector_datapath (
    input  logic     CLK,
    input  logic     nRST,
    vector_if.vif    vif    
);
    import vector_pkg::*;

    logic [LANE_FU_COUNT-1:0][NUM_LANES-1:0] fu_lane_readies;

    //interface definitons
    lane_if lane_interfaces [NUM_LANES]();
    result_collector_if rc_interfaces [LANE_FU_COUNT]();

    //slicer
    slicer slicer_inst (
        .vif(vif),
        .lif(lane_interfaces)
    );

    //lanes instanciation
    genvar ln_i;
    generate
        for (ln_i = 0; ln_i < NUM_LANES; ln_i ++) begin : lane_gen
            lane lane_inst (
                .CLK(CLK),
                .nRST(nRST),
                .lif(lane_interfaces[ln_i])
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
                end
            end : gen_rc_lane

            always_comb begin : rc_scalar_connection
                rc_interfaces[i].in.vd_input  = lane_interfaces[0].out.units[i].vd;
                lane_interfaces[i].in.ready   = rc_interfaces[i].out.input_ready;
            end
        end : gen_rc_fu
    endgenerate

 

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

    //rc to vif out, and vif in to rc
    genvar rc_vif_i;
    generate
        for (rc_vif_i = 0; rc_vif_i < LANE_FU_COUNT; rc_vif_i++) begin : gen_rc_vif_connection
            always_comb begin : rc_vif_connection
                vif.lanes_out.result_collectors[rc_vif_i] = rc_interfaces[rc_vif_i].out;
                rc_interfaces[rc_vif_i].in.wb_ready = vif.lanes_in.wb_ready[rc_vif_i];
            end
        end
    endgenerate
        

    //lanes ready to vif out
    genvar ready_vif_i, ready_vif_j;
    generate
        for (ready_vif_i = 0; ready_vif_i < LANE_FU_COUNT; ready_vif_i++) begin : gen_fu_ready
            for (ready_vif_j = 0; ready_vif_j < NUM_LANES; ready_vif_j++) begin : gen_lane_ready
                always_comb begin : ready_vif_connection
                    fu_lane_readies[ready_vif_i][ready_vif_j] = lane_interfaces[ready_vif_j].out.units[ready_vif_i].input_ready;
                end
            end

            always_comb begin : fu_status_connection
                vif.lanes_out.fu_global_status[ready_vif_i] = (&fu_lane_readies[ready_vif_i]);
            end
        end
    endgenerate
    

    

    

endmodule
