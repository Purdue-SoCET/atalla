// // /*  Akshath Raghav Ravikiran - araviki@purdue.edu */

// `include "xbar_params.svh"
// `include "xbar_if.sv"

// import xbar_pkg::*;

// module benes_rom #(
//     parameter int SIZE = `BENES_SIZE,
//     parameter int DWIDTH = `BENES_DWIDTH,

//     parameter int TAGWIDTH = $clog2(SIZE),
//     parameter int STAGES = (2 * TAGWIDTH) - 1, 
//     parameter int HALF = (SIZE >> 1),
//     parameter int BITWIDTH = STAGES * HALF,

//     parameter logic [STAGES-2:0] REGISTER_MASK = `BENES_REGISTER_MASK
// ) (
//     xbar_if.xbar xif, 
//     input logic [4:0] h_idx, w_idx
// );

//     logic [BITWIDTH-1:0] cntrl;
//     logic [9:0] addr;

//     assign addr = {h_idx, w_idx};

//     // Note: Need to deal with xif.en having to be switched on for one more than expected for benes_core only. 
//     rom_bank #(.DWIDTH(BITWIDTH), .DEPTH(1024), .INIT_FILE("controlbits.mem")) u_rom (.clk(xif.clk), .en(xif.en), .addr(addr), .data(cntrl));
//     benes #(.SIZE(SIZE), .DWIDTH(DWIDTH)) u_benes_core (xif, cntrl); 

// endmodule
