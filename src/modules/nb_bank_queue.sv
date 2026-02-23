`timescale 1ns/1ps
`include "ddr_controller_if.vh"
`include "dram_pkg.vh"

/*
    logic [BANK_GROUP_BITS-1:0] fe_bg, [$clog2(BANK_NUM)-1:0] fe_b, [ROW_BITS-1:0] fe_r, [COLUMN_BITS-1:0] fe_c;
    logic fe_read, fe_write;
    logic [$clog2(ID_NUM)-1:0] fe_id;
    logic fe_write_bq;
    logic [$clog2(BANK_NUM)-1:0] fe_full; // [QUEUE_SIZE-1:0]
*/

typedef struct packed {
    logic [ROW_BITS-1:0] row;
    logic [COLUMN_BITS-1:0] column;
    logic write;
    logic [$clog2(ID_NUM)-1:0] id_addr;
} bq_slot_t;

module nb_bank_queue(
    input logic CLK, nRST,
    ddr_controller_if.bq bqif
);
    // 2/23 - TODO: QUEUE_SIZE?
    import dram_pkg::*;
    local parameter QUEUE_SIZE = 8;
    logic [BANK_GROUP_BITS-1:0][$clog2(QUEUE_SIZE-1):0] waddr, raddr, n_waddr, n_raddr; 
    bq_slot_t [BANK_GROUP_BITS-1:0][QUEUE_SIZE-1:0] bqfifo, n_bqfifo;

    always_ff @(posedge CLK, negedge nRST) begin : ASSIGN_RW
        if (~nRST) begin
            waddr <= 'b0;
            raddr <= 'b0;
            bqfifo <= 'b0;
        end else begin
            waddr <= n_waddr;
            raddr <= n_raddr;
            bqfifo <= n_bqfifo;
        end
    end

    // 2/23: TODO: push/pop logic
    always_comb begin : UPDATE_FIFO
        n_raddr = raddr;
        n_waddr = waddr;
        n_bqfifo = bqfifo;

        // Read Write check
        if (bqif.fe_write && bqif.fe_read) begin


        end

        else if (bqif.fe_write) begin
            
            n_waddr = waddr + 1;
        end

        else if (bqif.fe_read) begin
            
            n_raddr = raddr + 1;
        end
    end

    assign bqif.fe_full = ((waddr + 1) == raddr);
    assign bqif.bq_ready = (waddr == 'b0);

endmodule