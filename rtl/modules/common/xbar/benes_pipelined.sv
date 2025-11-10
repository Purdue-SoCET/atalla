// /*  Haejune Kwon - kwon196@purdue.edu */
// /*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "xbar_params.svh"
`include "xbar_if.sv"

import xbar_pkg::*;

module benes_pipelined #(
    parameter int SIZE = 32,
    parameter int DWIDTH = 16,

    localparam int TAGWIDTH = $clog2(SIZE),
    localparam int STAGES = (2 * TAGWIDTH) - 1, 
    localparam int HALF = (SIZE >> 1),
    localparam int BITWIDTH = STAGES * HALF
) (
    xbar_if.xbar xif,
    input logic [BITWIDTH-1:0] control_bit
);

    logic [BITWIDTH-1:0] ctrl;
    logic [TAGWIDTH-1:0] perm [SIZE-1:0];

    cabbage_pipelined #(.SIZE(SIZE)) DUT_CBG (.clk(xif.clk), .n_rst(xif.n_rst), .perm(perm), .ctrl(ctrl));
    benes #(.SIZE(SIZE), .DWIDTH(DWIDTH), .REGISTER_MASK('1)) DUT_BENES (xif, ctrl);

endmodule