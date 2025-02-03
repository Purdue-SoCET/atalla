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
    logic new_weight;
    fu_gemm_t gemm_matrix_num

    modport GEMM (
        input gemm_enable, ls_enable, rs1_in, rs2_in, rs3_in, rd_in,
        output new_weight, gemm_matrix_num
    );

    modport tb (
        input new_weight, gemm_matrix_num,
        output gemm_enable, ls_enable, rs1_in, rs2_in, rs3_in, rd_in
    );

endinterface
`endif
