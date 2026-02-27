`timescale 1ns/1ps
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
    `include "dram_pkg.sv"
    import dram_pkg::*;

    typedef struct packed {
        logic [ROW_BITS-1:0] row;
        logic [COLUMN_BITS-1:0] column;
        logic write;
        logic [$clog2(ID_NUM)-1:0] id_addr;
    } bq_slot_t;

    logic [$clog2(BANK_NUM)-1:0] b_wsel;
    logic [$clog2(BANK_NUM)-1:0] b_rsel;

    genvar i;
    generate 
        for (i = 0; i < BANK_NUM; i++) begin
            // Assign the write/read selection signal
            assign b_wsel[i] = (bqif.bq_b == i) && bqif.fe_write_bq;
            assign b_rsel[i] = (bqif.bq_pop == i);

            // Generate fifos
            sync_fifo #(.DEPTH(BANK_NUM), .DWIDTH($bits(bq_slot_t))) bq_fifo_gen ( // TODO: DEPTH NEEDS FINALIZATION
                .clk(CLK), .rstn(nRST),
                .wr_en(b_wsel[i]),
                .din({bqif.fe_r, bqif.fe_c, bqif.fe_write, bqif.fe_id}),
                .rd_en(b_rsel[i]),
                .dout({bqif.bq_r, bqif.bq_c, bqif.bq_rw, bqif.bq_id}),
                .full(bqif.fe_full[i]),
                .empty()
            );

            // Full
        end

    endgenerate

endmodule