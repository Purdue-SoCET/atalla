`ifndef BFA_BFM_BFS_BFSLT_IF_VH
`define BFA_BFM_BFS_BFSLT_IF_VH
`include "atalla_isa_types.vh"

interface bfA_bfM_bfS_bfSLT_if;
    import atalla_isa_pkg::*;

    logic [15:0] bf1_in, bf2_in;
    logic [7:0] rdIn;
    logic ready_in, valid_in;
    scalar_fu_enable_t scalar_type_enable;

    logic [15:0] bf_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport mainport (
        input bf1_in, bf2_in, rdIn, valid_in, scalar_type_enable, ready_out,
        output bf_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input bf_out, valid_out, ready_in, rdOut,
        output bf1_in, bf2_in, rdIn, valid_in, scalar_type_enable, ready_out
    );

endinterface
`endif
