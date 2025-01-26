`ifndef FU_GEMM_IF_VH
`define FU_GEMM_IF_VH
`include "types_pkg.vh"

interface fu_gemm_if;
    import types_pkg::*;

    //Inputs from fetch
    logic [31:0] fetch_p; //from fetch instruction
    
    //These would be outputs from the GEMM function
    regbits_t rs1, rs2, rs3, rd; //tells the systolic array which values to multiply together

    //Inputs to latch
    logic flush, freeze;
    
    modport GEMM (
        input fetch_p, flush, freeze,
        output rs1, rs2, rs3, rd
    );
    modport tb (
        input rs1, rs2, rs3, rd,
        output fetch_p, flush, freeze
    );

endinterface
`endif
