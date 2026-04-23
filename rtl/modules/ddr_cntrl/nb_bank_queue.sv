`timescale 1ns/1ps
`include "dram_pkg.svh"
`include "ddr_controller_if.sv"

/*
    logic [BANK_GROUP_BITS-1:0] fe_bg, [$clog2(BANK_NUM)-1:0] fe_b, [ROW_BITS-1:0] fe_r, [COLUMN_BITS-1:0] fe_c;
    logic fe_read, fe_write;
    logic [$clog2(ID_NUM)-1:0] fe_id;
    logic fe_write_bq;
    logic [$clog2(BANK_NUM)-1:0] fe_full; // [QUEUE_SIZE-1:0]
*/
module nb_bank_queue(
    input logic CLK, nRST,
    ddr_controller_if.bq bqif
);
    `include "dram_pkg.svh"
    import dram_pkg::*;

    logic [BANK_NUM-1:0] b_wsel, b_rsel;

    // bq_bg and bq_b are legacy scalar signals; the per-bank FSM derives its
    // own bank index from the generate loop, so these are tied off here.
    assign bqif.bq_bg = '0;
    assign bqif.bq_b  = '0;

    genvar i;
    generate 
        for (i = 0; i < BANK_NUM; i++) begin
            logic bq_empty;

            // Assign the write/read selection signal
            assign b_wsel[i] = ({bqif.fe_b, bqif.fe_bg} == i) && bqif.fe_write_bq;
            assign b_rsel[i] = bqif.bq_pop[i]; // bq_pop is a one-hot mask, not an index

            // FWFT=1: bq_slot[i] reflects the head entry combinationally as soon
            // as data is written, without requiring a prior rd_en pulse.
            // The FSM reads bq_slot[i] combinationally while bq_ready[i] is high.
            sync_fifo #(.DEPTH(BANK_NUM), .DWIDTH($bits(bq_slot_t)), .FWFT(1)) bq_fifo_gen ( 
                .clk(CLK), .rstn(nRST),
                .wr_en(b_wsel[i]),
                .din(bqif.fe_bq_slot),
                .rd_en(b_rsel[i]),
                .dout(bqif.bq_slot[i]), 
                .full(bqif.fe_full[i]),
                .empty(bq_empty)
            );

            assign bqif.bq_ready[i] = !bq_empty;

        end

    endgenerate

endmodule