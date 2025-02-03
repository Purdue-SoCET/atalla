`ifndef FU_GEMM_IF_VH
`define FU_GEMM_IF_VH
`include "isa_types.vh"
`include "datapath_types.vh"

interface fu_gemm_if;
    import isa_pkg::*;
    import datapath_pkg::*;
    
    // Signals
    /*
        Inputs: 
        gemm_enable: From issue queue
        ls_enable: From issue queue
        rd_in: destination reg
        rs1_in: source reg
        rs2_in: source reg
        rs3_in: source reg
    */
    logic gemm_enable;
    logic ls_enable;
    matbits_t rs1_in, rs2_in, rs3_in, rd_in;

    /*
        Outputs: 
        new_weight: weights are new
        gemm_matrix_num: concatenation of {rd,rs3,rs2,rs1}
    */
    logic new_weights;
    fu_gemm_t gemm_matrix_num

    modport GEMM (
        input fetch_p, flush, freeze, gemm_enable, ls_enable, ls_in, gemm_hit,
        output rs1, rs2, rs3, rd, new_weights
    );

    modport tb (
        input rs1, rs2, rs3, rd, new_weights,
        output fetch_p, flush, freeze, gemm_enable, ls_enable, ls_in, gemm_hit
    );

endinterface
`endif
