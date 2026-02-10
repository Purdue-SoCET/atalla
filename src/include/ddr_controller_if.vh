`ifndef DDR_CONTROLLER_IF_VH
`define DDR_CONTROLLER_IF_VH

`include "dram_pkg.vh"

interface ddr_controller_if;

// 2.5.2025 -> TASK - ADD MODPORTS
// 2.8.2025 -> TASK - FINISH MODPORTS BY 2.12
import dram_pkg::*;

// AXI -> WRITE_QUEUE
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

// COMMAND FSM -> BACKEND ARBITER
logic be_arb;
logic be_queue_ready;
logic be_bg, be_b; // 2*16
logic be_r; // 15*16
logic be_c; // 10*16
logic be_id; // 4*16

// BACKEND ARBITER -> READ_ID_QUEUE
logic be_push_id, be_rid, be_rlen, be_rstrb;

// BACKEND ARBITER -> WDATA_QUEUE
logic be_wid, be_write; 

// AXI -> READ_ID_QUEUE
logic rready;
logic rq_rid, rq_rvalid, rq_rlen, rq_rstrb; 

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
    

);

modport read_id_queue (

);

modport write_id_queue (

);

modport command_fsm (

);

endinterface

`endif // DDR_CONTROLLER_IF_VH