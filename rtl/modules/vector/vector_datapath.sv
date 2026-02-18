/*
Vector top level

This is the full integration of the vector core

Owner: Jacob Walter
*/
`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"
`include "gsau_control_unit_if.vh"

module vector_datapath (
    input  logic     CLK,
    input  logic     nRST,
    vector_if.vif    vif    
);
    import vector_pkg::*;
    import reduction_pkg::*;

    logic [LANE_FU_COUNT][NUM_LANES] fu_lane_readies;

    //interface definitons
    lane_if lane_interfaces [NUM_LANES]();
    result_collector_if rc_interfaces [LANE_FU_COUNT]();

    //slicer
    slicer slicer_inst (
        .vif(vif),
        .lif(lane_interfaces)
    )

    //lanes instanciation
    genvar ln_i;
    generate lanes;
        for (ln_i = 0; ln_i < NUM_LANES; ln_i ++) begin
            lane lane_inst (
                .CLK(CLK),
                .nRST(nRST),
                .lif(lane_interfaces)
            );
        end
        
    endgenerate

    //lane->result collector connections
    //not modports cause im not in the mood to fix it right now, might move this logic into the RC
    //modports might entail adding an IF connection for every single FU to each FU
    //I think this should work well enough for now
    always_comb begin : rc_lane_connection
        for (int i = 0; i < LANE_FU_COUNT; i++) begin
            for (int j = 0; j < NUM_LANE; j++) begin
                if (i == 0) begin
                    rc_interfaces[i].in.input_valid[j] = lane_interfaces[j].out.units[i].wb_valid & !(lane_interfaces[j].out.units[i].rm); // do not start RC if its a reduction
                end
                else begin
                    rc_interfaces[i].in.input_valid[j] = lane_interfaces[j].out.units[i].wb_valid;
                end
                rc_interfaces[i].in.lane_input[j] = lane_interfaces[j].out.units[i].result;
                rc_interfaces[i].in.mask[j] = lane_interfaces[j].out.units[i].mask;
                rc_interfaces[i].in.vd_input[j] = lane_interfaces[j].out.units[i].vd;
                lane_interfaces[i].in.ready = rc_interfaces[j].out.input_ready;
            end
        end
    end

 

    genvar rc_i;
    generate result_collectors
        for (rc_i = 0; rc_i < LANE_FU_COUNT; rc_i++) begin
            result_collector rc_inst (
                .CLK(CLK),
                .nRST(nRST),
                .rcif(rc_interfaces[i])
            );
        end
    endgenerate

    //rc to vif out, and vif in to rc
    always_comb begin : rc_vif_connection
        for (int i = 0; i < LANE_FU_COUNT; i++) begin
            vif.lanes_out.result_collectors[i] = rc_interfaces[i].out;
            rc_interfaces[i].in.wb_ready = vif.in.wb_ready[i];
        end
    end
    

    //lanes ready to vif out
    for (int i = 0; i < LANE_FU_COUTN; i++) begin
        for (int j = 0; j < NUM_LANES; j++) begin
            fu_lane_readies[j][i] = lane_interfaces[j].out.units[i].input_ready;
        end
        vif.lanes_out.fu_global_status[i] = !(|fu_lane_readies[i]);
    end

    

    

endmodule
