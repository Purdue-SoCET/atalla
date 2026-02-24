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

endmodule