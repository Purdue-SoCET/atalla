// /*  Haejune Kwon - kwon196@purdue.edu */
// /*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "xbar_params.svh"
`include "xbar_if.sv"

import xbar_pkg::*;

module benes_singlecycle #(
    parameter int SIZE = 32,
    parameter int DWIDTH = 16,

    localparam int TAGWIDTH = $clog2(SIZE),
    localparam int STAGES = (2 * TAGWIDTH) - 1, // 9 for SIZE=32
    localparam int HALF = (SIZE >> 1),
    localparam int BITWIDTH = STAGES * HALF
) (
    xbar_if.xbar xif,
    input logic [BITWIDTH-1:0] control_bit
);

    logic [BITWIDTH-1:0] ctrl;
    logic [TAGWIDTH-1:0] perm [SIZE-1:0];

    benes #(.SIZE(SIZE), .DWIDTH(DWIDTH), .REGISTER_MASK('0)) DUT_BENES (xif, ctrl);
    cabbage_singlecycle #(.SIZE(SIZE)) DUT_CBG (.perm(perm), .ctrl(ctrl));

endmodule