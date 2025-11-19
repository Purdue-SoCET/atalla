/*

Documentation comment block for vLSU.sv:

This SystemVerilog module implements a vector Load/Store Unit (vLSU) for the Atalla processor.
It manages vector load and store operations, interfacing with vector load/store from scratchpad to veggie file and vice versa.

If any issues in this module are found, please report them to the Atalla github repo, or feel free to open a PR with suggested fixes.
#VedanttheVerifier lol

*/

// Includes will go here:

// Interface File for vLSU
// `include "vls_if.vh"  Old include, will need to update and change.
// 'include
// New interface file will be called vlsu_if.vh

module vLSU #(parameter FIFO_DEPTH = 13, parameter VEC_LEN = 32)(
    input  logic    CLK,
    input  logic    nRST,
    vlsu_if.vlsu      vlsuif
);
    
    // Instantiate 2 Fifos here, one for Loading from Scratchpad(s) to Veggie File
    
    // Idk if FIFO empty will be a problem here
    // J put in interface signals for fifo stuff for now

    sync_fifo #(.FIFODEPTH(FIFO_DEPTH), .DATAWIDTH(16)) spad1_to_veggie_fifo (
        .nRST  (nRST), .CLK(CLK),
        .wr_en (), .shift(),
        .din   (), .dout(),
        .empty (), .full()
    );

    sync_fifo #(.FIFODEPTH(FIFO_DEPTH), .DATAWIDTH(16)) spad2_to_veggie_fifo (
        .nRST  (nRST), .CLK(CLK),
        .wr_en (), .shift(),
        .din   (), .dout(),
        .empty (), .full()
    );

    always_comb begin
        // Logic for managing the fifos and data flow between scratchpad(s) and veggie file

    end

    // When storing from Veggie File to Scratchpad(s), we can directly connect the veggie file output to scratchpad input, no need for a fifo.
    // Make sure to pass along the 

endmodule