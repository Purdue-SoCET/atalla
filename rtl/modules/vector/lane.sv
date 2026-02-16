// ------------------------------------------------------------
// lane.sv
// Lane wrapper: Lane unit
// Owner: Jacob Walter
// ------------------------------------------------------------
`include "lane_in.vh"
`include "functional_unit_if.vh"
`include "vector_pkg.vh"


module lane #(

) (
    input  logic        CLK,
    input  logic        nRST,
    lane_if.lif         lif
);
    import vector_pkg::*;

    //Functional Unit instanciation
    functional_unit_if fu_interfaces [LANE_FU_COUNT]();
    alu_FU alu (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[0])
    );
    mult_FU mult (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[1])
    );
    div_FU div (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[2])
    );
    exp_FU exp (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[3])
    );
    sqrt_FU sqrt (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[4])
    );


    //connect the two input ports to every single FU
    always_comb begin : input_bus_connection
        for (int i = 0; i < LANE_FU_COUNT; i++) begin //iterate over each FU's interface
            for (int j = 0; j < LANE_ISSUE_W; j++) begin //iterate over all input ports
                fu_interfaces[i].in.ports[j].input_valid =  lif.in.input_valid[j];
                fu_interfaces[i].in.ports[j].v1 =           lif.in.v1[j];
                fu_interfaces[i].in.ports[j].v2 =           lif.in.v2[j];
                fu_interfaces[i].in.ports[j].usel =         lif.in.usel[j];
                fu_interfaces[i].in.ports[j].vd =           lif.in.vd[j];
                fu_interfaces[i].in.ports[j].rm =           lif.in.rm[j];
                fu_interfaces[i].in.ports[j].mask =         lif.in.mask[j];
                fu_interfaces[i].in.ports[j].alu_op =       lif.in.aluop[j];
                
            end
            fu_interfaces[i].in.wb_ready =  lif.in.rc_ready[i]; //ready singals from writeback
            lif.out.units[i] =              fu_interfaces[i].out;

        end
    end
    

endmodule
