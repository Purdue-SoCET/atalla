`ifndef FU_GEMM_IF_VH
`define FU_GEMM_IF_VH
`include "isa_types.vh"
`include "datapath_types.vh"

interface fu_gemm_if;
    import isa_pkg::*;
    import datapath_pkg::*;

    //Inputs from fetch
    logic [31:0] fetch_p; //from fetch instruction
    
    //These would be outputs from the GEMM function
    matbits_t rs1, rs2, rs3, rd; //tells the systolic array which values to multiply together

    //Inputs to latch
    logic flush, freeze;

    //-----------------------------
    //Inputs for enable
    logic GEMM_enable;
    logic ls_enable;

    //Inputs for new weights
    logic ls_in; //if ls_in[0] == 1, then load

    //Outputs for new weights
    logic new_weights;
    
    modport GEMM (
        input fetch_p, flush, freeze, GEMM_enable, ls_enable, ls_in,
        output rs1, rs2, rs3, rd, new_weights
    );

    modport tb (
        input rs1, rs2, rs3, rd, new_weights,
        output fetch_p, flush, freeze, GEMM_enable, ls_enable, ls_in
    );

endinterface
`endif
