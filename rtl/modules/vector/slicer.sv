/*
Lane slicer
Slices the two input ports down to the lane input ports
Just combinational logic connections, but just here to keep the top level clean
Owner: Jacob Walter
*/

`include "vector_pkg.vh"
`include "vector_if.vh"
`include "lane_if.vh"

module slicer 
    import vector_pkg::*;
(
    vector_if.lanes vif,
    lane_if.slicer  lif [NUM_LANES-1:0] 
);
    

    genvar i;
    generate
        for (i = 0; i < NUM_LANES; i++) begin : gen_lane_connections
            always_comb begin : connections
                for (int j = 0; j < LANE_ISSUE_W; j++) begin
                    lif[i].in.input_valid[j] = vif.lanes_in.lane_issue_ports[j].input_valid;
                    lif[i].in.v1[j] = vif.lanes_in.lane_issue_ports[j].v1[i*SLICE_W +: SLICE_W];
                    lif[i].in.v2[j] = vif.lanes_in.lane_issue_ports[j].v2[i*SLICE_W +: SLICE_W];
                    lif[i].in.usel[j]        = vif.lanes_in.lane_issue_ports[j].usel;
                    lif[i].in.vd[j]          = vif.lanes_in.lane_issue_ports[j].vd;
                    lif[i].in.rm[j]          = vif.lanes_in.lane_issue_ports[j].rm;
                    lif[i].in.mask[j]        = vif.lanes_in.lane_issue_ports[j].mask[i*2 + 1 -: SLICE_W];
                    lif[i].in.aluop[j]       = vif.lanes_in.lane_issue_ports[j].alu_op;
                end
            end
        end
    endgenerate

endmodule