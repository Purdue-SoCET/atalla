`ifndef DDR_CONTROLLER_IF_SV
`define DDR_CONTROLLER_IF_SV

interface ddr_controller_if;

// 2.5.2026 -> TASK - ADD MODPORTS - DONE
// 2.8.2026 -> TASK - FINISH MODPORTS BY 2.12 - DONE
// 2.12.2026 -> TASK - READ ID Q - DONE
// 2.26.2026 -> TASK - TYPEDEF 
`include "dram_pkg.svh"
import dram_pkg::*;

// NOTE: bq_slot_t and lstq_slot_t are defined in dram_pkg

// AXI -> WDATA_QUEUE
logic [7:0] wstrb;
logic wvalid;
logic [63:0] wdata;
logic [$clog2(ID_NUM)-1:0] wid;
logic [2:0] wlen; // -> Write Queue
logic wready;
logic bwvalid;
logic [1:0] bwresp;
logic [$clog2(ID_NUM)-1:0] bwid; // -> AXI
logic bwready; // -> Write Queue

// AXI -> LQ
logic arvalid;
logic [31:0] araddr;
logic [$clog2(ID_NUM)-1:0] arid;
logic [2:0] arlen; // -> LQ
logic arready; // -> AXI
logic rvalid;
logic [63:0] rdata;
logic [$clog2(ID_NUM)-1:0] rid;
logic [1:0] rresp; // -> AXI
logic rready; // -> LQ

// AXI -> STQ
logic awvalid;
logic [31:0] awaddr;
logic [$clog2(ID_NUM)-1:0] awid;
logic [2:0] awlen;
logic awready;

// STQ/LQ -> FRONTEND ARBITER
logic request_l, request_s;
lstq_slot_t lq_slot, stq_slot;
logic grant_l, grant_s;

// FRONTEND ARBITER -> BQ
// DATA IN
logic [BANK_GROUP_BITS-1:0] fe_bg;
logic [BANK_BITS-1:0]      fe_b;
logic [ROW_BITS-1:0]       fe_r;
logic [COLUMN_BITS-1:0]    fe_c;
logic fe_write;
logic [$clog2(ID_NUM)-1:0] fe_id;
logic [3:0] fe_len;
// CONTROL SIGNALS
logic fe_write_bq;
logic [BANK_NUM-1:0] fe_full; // [QUEUE_SIZE-1:0]

// BANK QUEUE -> COMMAND FSM
logic       [$clog2(BANK_NUM)-1:0] bq_pop; // BANK_NUM
bq_slot_t   [BANK_NUM-1:0] bq_slot; // bq_r, bq_c, bq_rw, bq_id; // 4*16
logic       [BANK_NUM-1:0] bq_ready;

// COMMAND FSM -> BACKEND ARBITER
logic [$clog2(BANK_NUM)-1:0]  be_arb;
logic [$clog2(BANK_NUM)-1:0]  be_queue_ready;
logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_bg;
logic [BANK_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_b; // 2*16
logic [ROW_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_r; // 15*16
logic [COLUMN_BITS-1:0][$clog2(BANK_NUM)-1:0]  be_c; // 10*16
logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  be_id; // 4*16
logic [4:0] be_cmd; // cmd_t width

// BACKEND ARBITER -> READ_ID_QUEUE
logic be_push_id;
logic [$clog2(ID_NUM)-1:0] be_rid;
logic [2:0] be_rlen;

// BACKEND ARBITER -> WDATA_QUEUE
logic [$clog2(ID_NUM)-1:0] be_wid;
logic be_write;

// AXI -> READ_ID_QUEUE
logic rq_rvalid;
logic [$clog2(ID_NUM)-1:0] rq_rid;
logic [2:0] rq_rlen;
logic dqs_strobe;
logic dqs_done; 

// WDATA_QUEUE -> DRAM
logic [63:0] ddr_wdata_data;
logic ddr_wdata_en;
logic [7:0] ddr_wdata_mask;
logic ddr_we;


// TODO: axi_sub modport needs arsize, arburst, awsize, awburst signals declared
// modport axi_sub ( 
//     input arready, wready, awready,
//     bwvalid, bwresp, bwid,
//     output wstrb, wvalid, wdata, wid, wlen, bwready,
//     arvalid, araddr, arid, arlen,
//     awvalid, awaddr, awid, awlen
// );

modport stq ( // AXI -> STQ
    input awvalid, awaddr, awid, awlen,
    // ARB -> STQ
    grant_s, 
    // STQ -> AXI
    output awready,
    // STQ -> ARB
    stq_slot, request_s  
);

modport lq (
    //AXI -> LQ
    input arvalid, araddr, arid, arlen, 
    //ARB -> LQ
    grant_l, 
    //LQ -> AXI
    output arready, 
    //LQ -> ARB
    lq_slot, request_l

);

modport arb (
    //STQ -> ARB
    input request_s, stq_slot,
    //LQ -> ARB
    request_l, lq_slot,
    //BQ -> ARB
    fe_full, 
    //ARB -> LQ
    output grant_l,
    //ARB -> STQ
    grant_s, 
    //ARB -> BQ
    fe_bg, fe_b, fe_r, fe_c, fe_write, fe_id, fe_len, fe_write_bq
);

modport bq (
    // ARB -> BQ (DATA)
    input fe_bg, fe_b, fe_c, fe_r, fe_write, fe_id, fe_len, 
    // ARB -> BQ (CNTRL)
    fe_write_bq,
    // FSM -> BQ (CNTRL)
    bq_pop, 
    // BQ -> ARB (CNTRL)
    output fe_full, 
    // BQ -> FSM (CNTRL)
    bq_ready, 
    // BQ -> FSM (DATA)
    bq_slot
);

modport read_id_queue (
    //BQ -> FSM
    input be_push_id, be_rid, be_rlen, dqs_done, rready,
    output rq_rvalid, rq_rid, rq_rlen
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

// TODO: command_fsm modport needs bq_rw, bq_bg, bq_b, bq_r, bq_c, bq_id signals
// (these were replaced by bq_slot struct — update modport when implementing FSM)
// modport command_fsm (
//     input     bq_rw, bq_ready, bq_bg, bq_b, bq_r, bq_c, bq_id,
//     be_arb,
//     output be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready
// );

modport backend_arb (
    //FSM -> BE
    input be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready,
    //BE -> FSM
    output be_arb, 
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //BE -> R_ID_QUEUE
    be_rid, be_push_id, be_rlen
);

modport frontend_tb (
    // TB drives AXI write channel -> STQ
    output awvalid, awaddr, awid, awlen,
    // TB drives AXI read channel -> LQ
    arvalid, araddr, arid, arlen,
    // TB emulates BQ backpressure
    fe_full,
    // TB monitors STQ -> AXI
    input awready,
    // TB monitors LQ -> AXI
    arready,
    // TB monitors internal queue -> arb
    request_l, request_s, lq_slot, stq_slot,
    grant_l, grant_s,
    // TB monitors ARB -> BQ
    fe_bg, fe_b, fe_r, fe_c, fe_write, fe_id, fe_len, fe_write_bq
);


endinterface

`endif // DDR_CONTROLLER_IF_SV