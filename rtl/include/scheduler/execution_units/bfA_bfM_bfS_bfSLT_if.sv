`ifndef BFA_BFM_BFS_BFSLT_IF_VH
`define BFA_BFM_BFS_BFSLT_IF_VH

interface bfA_bfM_bfS_bfSLT_if;

    logic [15:0] bf1_in, bf2_in;
    logic [7:0] rdIn;
    logic ready_in, valid_in, add, sub, mult, slt;

    logic [15:0] bf_out;
    logic [7:0] rdOut;
    logic valid_out, ready_out;

    modport mainport (
        input bf1_in, bf2_in, rdIn, valid_in, add, sub, mult, slt, ready_out,
        output bf_out, valid_out, ready_in, rdOut
    );

    modport tb (
        input bf_out, valid_out, ready_in, rdOut,
        output bf1_in, bf2_in, rdIn, valid_in, add, sub, mult, slt, ready_out
    );

endinterface
`endif
