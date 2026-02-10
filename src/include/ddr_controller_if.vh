`ifndef DDR_CONTROLLER_IF_VH
`define DDR_CONTROLLER_IF_VH

`include "dram_pkg.vh"

interface ddr_controller_if;

// 2.5.2025 -> TASK - ADD MODPORTS
// 2.8.2025 -> TASK - FINISH MODPORTS BY 2.12
import dram_pkg::*;

// AXI -> WDATA_QUEUE
logic wstrb, wvalid, wdata, wid, wlen; // -> Write Queue
logic wready, bwvalid, bwresp, bwid; // -> AXI
logic bwready; // -> Write Queue

// AXI -> LQ
logic arvalid, araddr, arid, arsize, arlen, arburst; // -> LQ
logic arready; // -> AXI
logic rvalid, rdata, rid, rlast, rresp; // -> AXI
logic rready; // -> LQ

// AXI -> STQ
logic awvalid, awaddr, awid, awsize, awlen, awburst;
logic awready;

// STQ/LQ -> FRONTEND ARBITER
logic request_l, request_s;
logic address_l, address_s;
logic grant_l, grant_s;

// FRONTEND ARBITER -> BQ
logic fe_bg, fe_b, fe_r, fe_c;
logic fe_read, fe_write;
logic fe_id;
logic fe_write_bq;
logic fe_full; // [QUEUE_SIZE-1:0]

// BANK QUEUE -> COMMAND FSM
logic bq_pop; // 16
logic bq_rw; // 16
logic bq_bg, bq_b; // 2*16
logic bq_r; // 15*16
logic bq_c; // 10*16
logic bq_id; // 4*16
logic bq_ready;

// COMMAND FSM -> BACKEND ARBITER
logic be_arb;
logic be_queue_ready;
logic be_bg, be_b; // 2*16
logic be_r; // 15*16
logic be_c; // 10*16
logic be_id; // 4*16
logic be_cmd; 

// BACKEND ARBITER -> READ_ID_QUEUE
logic be_push_id, be_rid, be_rlen, be_rstrb;

// BACKEND ARBITER -> WDATA_QUEUE
logic be_wid, be_write; 

// AXI -> READ_ID_QUEUE
logic rready;
logic rq_rid, rq_rvalid, rq_rlen, rq_rstrb; 

// WDATA_QUEUE -> DRAM
logic ddr_wdata_data;
logic ddr_wdata_en;
logic ddr_wdata_mask;
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
    address_l, request_l

);

modport arb (
    //STQ -> ARB
    input request_s, address_s,
    //LQ -> ARB
    request_l, address_l,
    //BQ -> ARB
    fe_full, 
    //ARB -> LQ
    output grant_l,
    //ARB -> STQ
    grant_s, 
    //ARB -> BQ
    fe_bg, fe_b, fe_r, fe_c, fe_write, fe_id, fe_write_bq
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