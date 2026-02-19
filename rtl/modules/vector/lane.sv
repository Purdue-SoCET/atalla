// ------------------------------------------------------------
// lane.sv
// Lane wrapper: Lane unit
// Owner: Jacob Walter
// ------------------------------------------------------------
`include "lane_if.vh"
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
    /*
    alu_FU alu (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[0])
    );
    */
    mul_FU mult (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[1])
    );
    /*
    div_FU div (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[2])
    );
    */
    /*
    exp_FU exp (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[3])
    );
    */
    sqrt_FU sqrt (
        .CLK(CLK),
        .nRST(nRST),
        .fuif(fu_interfaces[4])
    );


    //connect the two input ports to every single FU
    genvar i, j;
    generate
        for (i = 0; i < LANE_FU_COUNT; i++) begin : fu_connections
            for (j = 0; j < LANE_ISSUE_W; j++) begin : port_connections
                assign fu_interfaces[i].in.ports[j].input_valid = lif.in.input_valid[j];
                assign fu_interfaces[i].in.ports[j].v1 =          lif.in.v1[j];
                assign fu_interfaces[i].in.ports[j].v2 =          lif.in.v2[j];
                assign fu_interfaces[i].in.ports[j].usel =        lif.in.usel[j];
                assign fu_interfaces[i].in.ports[j].vd =          lif.in.vd[j];
                assign fu_interfaces[i].in.ports[j].rm =          lif.in.rm[j];
                assign fu_interfaces[i].in.ports[j].mask =        lif.in.mask[j];
                assign fu_interfaces[i].in.ports[j].alu_op =      lif.in.aluop[j];
            end
            
            assign fu_interfaces[i].in.wb_ready = lif.in.ready[i];
            assign lif.out.units[i] = fu_interfaces[i].out;
        end
    endgenerate
    

endmodule
