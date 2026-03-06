`ifndef VREDUCTION_IF_VH
`define VREDUCTION_IF_VH
`include "vector_pkg.vh"


interface vreduction_if #(
);
    import vector_pkg::*;
    
    reduction_if_in_t in;
    reduction_if_out_t out;
    
    modport ruif (
        input in,
        output out
    );
    
endinterface

`endif