`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"
`include "gsau_control_unit_if.vh"
    import vector_pkg::*;

module vector_datapath_wrapper (
    input  logic                    CLK,
    input  logic                    nRST,

    input  vector_in_t  vector_in_i,
    output vector_out_t vector_out_o
);

    import reduction_pkg::*;

    vector_if vif();

    assign vif.vector_in = vector_in_i;

    assign vector_out_o = vif.vector_out;

    vector_datapath u_vector_datapath (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif)
    );

endmodule
