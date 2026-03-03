// // BANK QUEUE -> COMMAND FSM
// logic [$clog2(BANK_NUM)-1:0] bq_pop; // 16
// logic [$clog2(BANK_NUM)-1:0] bq_rw; // 16
// logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0 ] bq_bg, [$clog2(BANK_NUM)-1:0][$clog2(BANK_NUM)-1:0]   bq_b; // 2*16
// logic [ROW_BITS-1:0][$clog2(BANK_NUM)-1:0] bq_r; // 15*16
// logic [COLUMN_BITS-1:0][$clog2(BANK_NUM)-1:0]  bq_c; // 10*16
// logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  bq_id; // 4*16
// logic [$clog2(BANK_NUM)-1:0] bq_ready ;

// // COMMAND FSM -> BACKEND ARBITER
// logic [$clog2(BANK_NUM)-1:0]  be_arb;
// logic [$clog2(BANK_NUM)-1:0]  be_queue_ready;
// logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_bg, [BANK_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_b; // 2*16
// logic [ROW_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_r; // 15*16
// logic [COLUMN_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_c; // 10*16
// logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  be_id; // 4*16
// logic [IDK] be_cmd; 

// modport command_fsm (
//     //BQ -> FSM
//     input     bq_rw, bq_ready, bq_bg, bq_b, bq_r, bq_c, bq_id,
//     //BE -> FSM
//     be_arb,
//     //FSM -> BE 
//     output be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready
// );

// FSM Top Level //

`include "ddr_controller_if.vh"
`include "dram_pkg.vh"

module cmd_fsm (
    input logic CLK, nRST, 
    ddr_controleer_if.command_fsm fsm
);


endmodule