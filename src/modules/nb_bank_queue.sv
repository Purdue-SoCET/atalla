`timescale 1ns/1ps
`include "ddr_controller_if.vh"
`include "dram_pkg.vh"

module nb_bank_queue(
    input logic CLK, nRST,
    ddr_controller_if.bq bqif
);
    // 2/21 - TODO: Depth of queue + size of each bank slot?
    import dram_pkg::*;
    local parameter DEPTH = 8;
    word_t [DEPTH:0] bank_queue;
    logic wen, ren;
    logic [$clog2(DEPTH-1):0] waddr, raddr, n_waddr, n_raddr; 

    // 2/21 - TODO: Reset value?
    always_ff @(posedge CLK, negedge nRST) begin : ASSIGN_RW
        if (~nRST) begin
            waddr <= 'b0;
            raddr <= 'b0;
        end else begin
            waddr <= n_waddr;
            raddr <= n_raddr;
        end
    end

    // 2/21: TODO: Offset per increment + push/pop logic
    always_comb begin : UPDATE_WADDR
        n_waddr = waddr;
        if (wen) begin
            // n_waddr = waddr;
            // 
        end
    end

    always_comb begin : UPDATE_RADDR
        n_raddr = raddr;
        if (ren) begin
            // n_raddr = raddr;
            // 
        end
    end

    // 2/21: TODO: full/empty
    assign bqif.fe_full = ((waddr + 1) == raddr);

endmodule