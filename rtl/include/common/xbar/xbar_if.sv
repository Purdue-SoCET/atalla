`ifndef XBAR_IF_SV
`define XBAR_IF_SV

interface xbar_if #(
    parameter int SIZE = 32,
    parameter int DWIDTH = 16
) (input logic clk, input logic n_rst);
    `include "xbar_params.svh"

    import xbar_pkg::*;

    typedef struct packed {
        logic [DWIDTH-1:0] din;
        logic [$clog2(SIZE)-1:0] shift;
    } group_t;

    logic en;
    group_t in [SIZE-1:0]; 
    logic [DWIDTH-1:0] out [SIZE-1:0]; 
    
    modport xbar (
        input clk, n_rst,
        input en, in,
        output out
    );

    modport tb (
        input out,
        output clk, n_rst,
        output en, in
    );

endinterface

`endif 
