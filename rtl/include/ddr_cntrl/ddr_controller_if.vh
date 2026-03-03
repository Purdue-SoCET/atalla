`ifndef DDR_CONTROLLER_IF_VH
`define DDR_CONTROLLER_IF_VH

`include "dram_pkg.vh"

interface ddr_controller_if;

// 2.5.2025 -> TASK - ADD MODPORTS
// 2.8.2025 -> TASK - FINISH MODPORTS BY 2.12
import dram_pkg::*;

// AXI -> WDATA_QUEUE
logic [7:0] wstrb, wvalid, [63:0] wdata, [$clog2(ID_NUM)-1:0] wid, [2:0] wlen; // -> Write Queue
logic wready, bwvalid, [1:0] bwresp, [$clog2(ID_NUM)-1:0] bwid; // -> AXI
logic bwready; // -> Write Queue

// AXI -> LQ
logic arvalid, [31:0] araddr, [$clog2(ID_NUM)-1:0] arid, [2:0] arlen; // -> LQ
logic arready; // -> AXI
logic rvalid, [63:0] rdata, [$clog2(ID_NUM)-1:0] rid, [1:0] rresp; // -> AXI
logic rready; // -> LQ

// AXI -> STQ
logic awvalid, [31:0] awaddr, [$clog2(ID_NUM)-1:0] awid, [2:0] awlen;
logic awready;

// STQ/LQ -> FRONTEND ARBITER
logic request_l, request_s;
logic [31:0] address_l, address_s;
logic [3:0] len_l, len_s;
logic [$clog2(ID_NUM) - 1:0] id_l, id_s;
logic grant_l, grant_s;

// FRONTEND ARBITER -> BQ
logic [BANK_GROUP_BITS-1:0] fe_bg, [$clog2(BANK_NUM)-1:0] fe_b, [ROW_BITS-1:0] fe_r, [COLUMN_BITS-1:0] fe_c;
logic fe_read, fe_write;
logic [$clog2(ID_NUM)-1:0] fe_id;
logic fe_write_bq;
logic [2:0] fe_len;
logic [$clog2(BANK_NUM)-1:0] fe_full; // [QUEUE_SIZE-1:0]

// BANK QUEUE -> COMMAND FSM
logic [$clog2(BANK_NUM)-1:0] bq_pop; // 16
logic [$clog2(BANK_NUM)-1:0] bq_rw; // 16
logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0 ] bq_bg, [$clog2(BANK_NUM)-1:0][$clog2(BANK_NUM)-1:0]   bq_b; // 2*16
logic [ROW_BITS-1:0][$clog2(BANK_NUM)-1:0] bq_r; // 15*16
logic [COLUMN_BITS-1:0][$clog2(BANK_NUM)-1:0]  bq_c; // 10*16
logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  bq_id; // 4*16
logic [BANK_NUM-1:0] bq_ready ;

// FSM module signals - bq
logic fsm_pop;
logic fsm_rw;
logic [ROW_BITS-1:0] fsm_r;
logic [BANK_NUM-1] fsm_bqr;
// be_arbiter - FSM modules
logic fsm_arb;
logic 


// COMMAND FSM -> BACKEND ARBITER
logic [$clog2(BANK_NUM)-1:0]  be_arb;
logic [$clog2(BANK_NUM)-1:0]  be_queue_ready;
logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_bg, [BANK_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_b; // 2*16
logic [ROW_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_r; // 15*16
logic [COLUMN_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_c; // 10*16
logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  be_id; // 4*16
logic [IDK] be_cmd; 

// BACKEND ARBITER -> READ_ID_QUEUE
logic be_push_id, [$clog2(ID_NUM)-1:0] be_rid, [2:0] be_rlen;

// BACKEND ARBITER -> WDATA_QUEUE
logic [$clog2(ID_NUM)-1:0] be_wid, be_write; 

// AXI -> READ_ID_QUEUE
logic rready;
logic [$clog2(ID_NUM)-1:0] rq_rid, rq_rvalid, [2:0] rq_rlen; 

// WDATA_QUEUE -> DRAM
logic [63:0] ddr_wdata_data;
logic ddr_wdata_en;
logic [7:0] ddr_wdata_mask;
logic ddr_we;

modport axi_sub ( 
    // LQ -> AXI
    input arready, 
    // Write Queue -> AXI
    wready, 
    // STQ -> AXI
    awready, 
    // WDATA_QUEUE -> AXI
    wready, bwvalid, bwresp, bwid,
    // AXI -> WDATA_QUEUE
    output wstrb, wvalid, wdata, wid, wlen, bwready,
    // AXI -> LQ
    arvalid, araddr, arid, arsize, arlen, arburst, 
    // AXI -> STQ
    awvalid, awaddr, awid, awsize, awlen, awburst,
);

modport stq ( // AXI -> STQ
    input awvalid, awaddr, awid, awsize, awlen, awburst,
    // ARB -> STQ
    grant_s, 
    // STQ -> AXI
    output awready,
    // STQ -> ARB
    address_s, request_s  
);

modport lq (
    //AXI -> LQ
    input arvalid, araddr, arid, arsize, arlen, arburst, 
    //ARB -> LQ
    grant_l, 
    //LQ -> AXI
    output arready, 
    //STQ -> ARB
    address_l, request_l, len_l, id_l

);

modport arb (
    //STQ -> ARB
    input request_s, address_s, id_s, len_s,
    //LQ -> ARB
    request_l, address_l, id_l, len_l,
    //BQ -> ARB
    fe_full, 
    //ARB -> LQ
    output grant_l,
    //ARB -> STQ
    grant_s, 
    //ARB -> BQ
    fe_bg, fe_b, fe_r, fe_c, fe_write, fe_id, fe_write_bq, fe_len
);

modport bq (
    //ARB -> BQ
    input fe_bg, fe_b, fe_c, fe_r, fe_write, fe_id, fe_write_bq,
    //FSM -> BQ
    bq_pop, 
    //BQ -> ARB
    output fe_full, 
    //BQ -> FSM
    bq_rw, bq_ready, bq_bg, bq_b, bq_r, bq_c, bq_id

);

modport read_id_queue (
    //BQ -> FSM


);

modport wdata_queue (
    //AXI -> WDATA_QUEUE
    input wstrb, wvalid, wdata, wid, wlen, bwready,
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //WDATA_QUEUE -> AXI
    output wready, bwvalid, bwresp, bwid, 
    //WDATA_QUEUE -> DRAM
    ddr_wdata_data, ddr_wdata_en, ddr_wdata_mask, ddr_we
    
);

modport command_fsm (
    //BQ -> FSM
    input     bq_rw, bq_ready, bq_bg, bq_b, bq_r, bq_c, bq_id,
    //BE -> FSM
    be_arb,
    //FSM -> BE 
    output be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready
);

modport fsm_mod (
    //FSM -> FSMmod

    //FSMmod -> FSM
);

modport backend_arb (
    //FSM -> BE
    input be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready,
    //BE -> FSM
    output be_arb, 
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //BE -> R_ID_QUEUE
    be_rid, be_push_id, be_rlen
);

endinterface

`endif // DDR_CONTROLLER_IF_VH