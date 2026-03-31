`ifndef DDR_CONTROLLER_IF_SV
`define DDR_CONTROLLER_IF_SV
`include "dram_pkg.svh"

interface ddr_controller_if;

// 2.5.2026 -> TASK - ADD MODPORTS - DONE
// 2.8.2026 -> TASK - FINISH MODPORTS BY 2.12 - DONE
// 2.12.2026 -> TASK - READ ID Q - DONE
// 2.26.2026 -> TASK - TYPEDEF 
import dram_pkg::*;

// // STRUCTS


// // SIGNALS

// AXI <-> WDQ
wdq_slot_t wdq_slot;
// CNTRL
//logic [7:0]                wstrb; // -> WQ
//logic [2:0]                wlen; // -> WQ
logic                      wvalid; // -> WQ 
logic                      bwready; // -> WQ
logic                      wlast; // -> WQ




// AXI <-> LQ
lstq_slot_t  lq_slot; // -> LQ
// CNTRL
logic       arvalid; // -> LQ
logic       arready; // -> AXI
logic       rvalid;  // -> AXI 
logic [1:0] rresp;   // -> AXI 
logic       rready;  // -> LQ

// AXI <-> STQ
lstq_slot_t stq_slot; // -> STQ
// CNTRL
logic awvalid; // -> STQ
logic awready; // -> AXI

// STQ/LQ <-> FRONTEND ARBITER
logic request_l, request_s; // -> ARB
logic address_l, address_s; // -> ARB
logic grant_l,   grant_s;   // -> STQ

// FRONTEND ARBITER <-> BQ
bq_slot_t                  fe_bq_slot; // -> BQ
bq_slot_t [BANK_NUM-1:0]   bq_slot; // -> FSM
// CONTROL SIGNALS
logic [BANK_GROUP_BITS-1:0]  fe_bg; // -> BQ
logic [BANK_BITS-1:0]        fe_b;  // -> BQ
logic                        fe_write_bq; // -> BQ
logic [BANK_NUM-1:0]         fe_full; // -> FE & FSM

// BQ <-> COMMAND FSM
logic [$clog2(BANK_NUM)-1:0] bq_pop; // -> FSM
logic [BANK_NUM-1:0]         bq_ready; // -> FSM
logic [BANK_GROUP_BITS-1:0]  bq_bg; // -> BQ
logic [BANK_BITS-1:0]        bq_b;  // -> BQ

// COMMAND FSM -> BACKEND ARBITER
logic [BANK_GROUP_BITS-1:0][$clog2(BANK_NUM)-1:0] be_bg; 
logic [BANK_BITS-1:0][$clog2(BANK_NUM)-1:0]       be_b; // 2*16
logic [ROW_BITS-1:0][BANK_NUM-1:0]                be_r; // 15*16
logic [COLUMN_BITS-1:0][BANK_NUM-1:0]             be_c; // 10*16
logic [$clog2(ID_NUM)-1:0][$clog2(BANK_NUM)-1:0]  be_id; // 4*16
logic [BANK_NUM-1:0]                      be_arb;
logic [BANK_NUM-1:0]                      be_queue_ready;
logic [2:0]                                       be_len;
fsm_t [BANK_NUM-1:0]                              be_cmd; 

// BACKEND ARBITER -> READ_ID_QUEUE
logic                      be_push_id; 
logic [$clog2(ID_NUM)-1:0] be_rid;
logic [2:0]                be_rlen;

// BACKEND ARBITER -> WDATA_QUEUE
logic [$clog2(ID_NUM)-1:0] be_wid, be_write; 

// AXI -> READ_ID_QUEUE
logic                      rq_rready;
logic [$clog2(ID_NUM)-1:0] rq_rid, rq_rvalid;
logic [2:0]                rq_rlen; 

// WDATA_QUEUE_WRAPPER -> AXI 
logic wready;
logic bwvalid;
logic [1:0] bwresp;
logic [$clog2(ID_NUM)-1:0] bwid;

// WDATA_QUEUE_WRAPPER -> DRAM
logic [63:0] ddr_wdata_data;
logic  ddr_wdata_en;
logic [7:0] ddr_wdata_mask;
logic ddr_we;

// WDATA_QUEUE_WRAPPER -> WDATA_QUEUE
logic [$clog2(ID_NUM)-1:0] wrap_bw_arb;

// // MODPORTS



modport axi_sub ( 
    // LQ -> AXI
    input arready, 
    // STQ -> AXI
    awready, 
    // WDATA_QUEUE -> AXI
    wready, bwvalid, bwresp, bwid,
    // AXI -> WDATA_QUEUE
    output  wdq_slot, bwready,
    // AXI -> LQ
    arvalid, lq_slot, 
    // AXI -> STQ
    awvalid, stq_slot
);

modport stq ( 
    // AXI -> STQ
    input awvalid, stq_slot,
    // ARB -> STQ
    grant_s, 
    // STQ -> AXI
    output awready,
    // STQ -> ARB
    address_s, request_s  
);

modport lq (
    //AXI -> LQ
    input arvalid, lq_slot, 
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
    fe_bg, fe_b, fe_bq_slot, fe_write_bq
);

modport bq (
    // ARB -> BQ (DATA)
    input fe_bg, fe_b, fe_bq_slot, 
    // ARB -> BQ (CNTRL)
    fe_write_bq,
    // FSM -> BQ (CNTRL)
    bq_pop, // Not a big deal, but confirm with Adrian that this is the concat of {b,bg}
    // BQ -> ARB (CNTRL)
    output fe_full, 
    // BQ -> FSM (CNTRL)
    bq_ready, bq_bg, bq_b,
    // BQ -> FSM (DATA)
    bq_slot
);

modport read_id_queue ( 
    //BQ -> FSM
    input  be_push_id, be_rid, be_rlen, rready,
    output rq_rid, rq_rvalid, rq_rlen
);


modport wdata_wrapper (

    // AXI_WRITE_CHANNEL -> WRAPPER
    input wdq_slot, bwready, wvalid, wlast, 
    // BAACKEND_ARBITER -> WRAPPER
    be_wid, be_write,

    
    // WRAPPER -> AXI_WRITE AND RESPONSE CHANNEL
    output wready, bwvalid, bwresp, bwid,
    // WRAPPER -> DRAM
    ddr_wdata_data, ddr_wdata_en, ddr_wdata_mask, ddr_we
);

modport command_fsm (
    //BQ -> FSM
    input bq_ready, bq_bg, bq_b, bq_slot,
    //BE -> FSM
    cg,
    //FSM -> BE 
    output be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready
);

modport backend_arb (
    //FSM -> BE
    input be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready, be_len,
    //BE -> FSM
    output be_arb, 
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //BE -> R_ID_QUEUE
    be_rid, be_push_id, be_rlen
);


// // BIND MODPORTS

modport barb_prop (
    //FSM -> BE
    input be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready,
    //BE -> FSM
    be_arb, 
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //BE -> R_ID_QUEUE
    be_rid, be_push_id, be_rlen
);

modport wdq_prop (
    //AXI -> WDATA_QUEUE
    input  wdq_slot, bwready,
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //WDATA_QUEUE -> WRAPPER
    wready, bwvalid, bwresp, bwid, 
    //WDATA_QUEUE -> WRAPPER
    ddr_wdata_data, ddr_wdata_en, ddr_wdata_mask, ddr_we  
);

endinterface

`endif // DDR_CONTROLLER_IF_SV
