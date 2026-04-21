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
logic [31:0]                araddr;  // -> LQ
logic [$clog2(ID_NUM)-1:0]  arid;    // -> LQ
logic [2:0]                 arlen;   // -> LQ
logic       arready; // -> AXI


// AXI <-> READ_PATH
logic       rvalid;  // -> AXI 
logic [1:0] rresp;   // -> AXI 
logic       rready;  // -> READ_PATH
logic rlast; // -> AXI READ CHANNEL
logic [$clog2(ID_NUM)-1:0] rid; // -> AXI READ CHANNEL
logic [63:0] rdata; // -> AXI READ CHANNEL

// AXI <-> STQ
lstq_slot_t stq_slot; // -> STQ
// CNTRL
logic awvalid; // -> STQ
logic [31:0]                awaddr;  // -> STQ
logic [$clog2(ID_NUM)-1:0]  awid;    // -> STQ
logic [2:0]                 awlen;   // -> STQ
logic awready; // -> AXI

// STQ/LQ <-> FRONTEND ARBITER
logic request_l, request_s; // -> ARB
logic grant_l,   grant_s;   // -> STQ

// FRONTEND ARBITER <-> BQ
bq_slot_t                  fe_bq_slot; // -> BQ
bq_slot_t [BANK_NUM-1:0]   bq_slot; // -> FSM
// DATA SIGNALS
logic [BANK_GROUP_BITS-1:0]  fe_bg; // -> BQ
logic [BANK_BITS-1:0]        fe_b;  // -> BQ
logic [ROW_BITS-1:0]         fe_r;  // -> BQ
logic [COLUMN_BITS-1:0]      fe_c;  // -> BQ
logic                        fe_write; // -> BQ
logic [$clog2(ID_NUM)-1:0]   fe_id; // -> BQ
logic [3:0]                  fe_len; // -> BQ
// CONTROL SIGNALS
logic                        fe_write_bq; // -> BQ
logic [BANK_NUM-1:0]         fe_full; // -> FE & FSM

// BQ <-> COMMAND FSM
logic [BANK_NUM-1:0]         bq_pop; // -> BQ (per-bank pop from FSM)
logic [BANK_NUM-1:0]         bq_ready; // -> FSM
logic [BANK_GROUP_BITS-1:0]  bq_bg; // -> BQ
logic [BANK_BITS-1:0]        bq_b;  // -> BQ

// COMMAND FSM -> BACKEND ARBITER
logic [BANK_NUM-1:0][BANK_GROUP_BITS-1:0]         be_bg; 
logic [BANK_NUM-1:0][BANK_BITS-1:0]               be_b; // 2*16
logic [BANK_NUM-1:0][ROW_BITS-1:0]                be_r; // 15*16
logic [BANK_NUM-1:0][COLUMN_BITS-1:0]             be_c; // 10*16
logic [BANK_NUM-1:0][$clog2(ID_NUM)-1:0]          be_id; // 4*16
logic [BANK_NUM-1:0]                              be_arb;
logic [BANK_NUM-1:0]                              be_queue_ready;
logic [2:0]                                       be_len;
fsm_t [BANK_NUM-1:0]                              be_cmd; 

// COMMAND FSM <-> FSM_MOD (per-bank internal signals)
logic                      fsm_rw;      // Read(0) / Write(1) from bank queue
logic [ROW_BITS-1:0]       fsm_r;       // Row address from bank queue
logic                      fsm_bqready; // Bank queue has a pending request
logic                      fsm_arb;     // Backend arbiter acknowledges this bank
logic                      fsm_ref;     // External refresh request
logic                      fsm_pop;     // Pop front entry from bank queue
logic                      fsm_ready;   // Command eligible for arbiter scheduling
fsm_t                      fsm_cmd;     // Current command

// REFRESH COUNTER <-> BACKEND ARBITER
logic                      rf_enable;   // Initialization done, enable counting
logic [BANK_NUM-1:0]       rf_done;     // Refresh command completed

// INIT STATE
logic                      init_start;      // Trigger to begin initialization
logic init_done;       // Initialization complete (restored for modport)
dram_state_t               init_state;      // Current initialization state
dram_state_t               next_init_state; // Next initialization state

// BACKEND ARBITER -> READ_ID_QUEUE
logic                      be_push_id; 
logic [$clog2(ID_NUM)-1:0] be_rid;
logic [2:0]                be_rlen;

// BACKEND ARBITER -> WDATA_QUEUE
logic [$clog2(ID_NUM)-1:0] be_wid;
logic be_write; 

// BACKEND ARBITER -> REF TIMER
// (restored below for modport)
logic ref_done;        // Refresh done (restored for modport)

// AXI -> READ_ID_QUEUE
//logic                      rq_rready;
logic [$clog2(ID_NUM)-1:0] rq_rid; //rq_rvalid;
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


// Signal generator signals pulled from Tri's branch:
//REFRESH request
    logic ref_re;

    //Signals interface between control unit and signal generator
    dram_state_t state, nstate; 
    logic [RANK_BITS-1:0] RA0;
    logic [BANK_GROUP_BITS-1:0] BG0;
    logic [BANK_BITS-1:0] BA0;
    logic [ROW_BITS-1:0] R0;
    logic [COLUMN_BITS-1:0] C0;

    //Interface between singal generator and DRAM
    logic ACT_n;
    logic RAS_n_A16;
    logic CAS_n_A15;
    logic WE_n_A14;
    logic ALERT_n;
    logic PARITY;
    logic RESET_n;
    logic TEN;
    logic CS_n;
    logic CKE;
    logic ODT;
    logic ZQ;
    logic PWR;
    logic VREF_CA;
    logic VREF_DQ;

    logic [RANK_BITS-1:0] C;
    logic [BANK_GROUP_BITS-1:0] BG;
    logic [BANK_BITS-1:0] BA;
    logic [ADDR_BITS-1:0] ADDR;
    logic ADDR_17;

    // Data transfer module signals
    logic wr_en, rd_en, clear;
    logic edge_flag;
    logic [WORD_W - 1: 0] memstore, memload;
    logic [2:0] COL_choice;
    wire [WORD_W - 1 :0] DQ;
    wire DQS_t, DQS_c, DM_n;

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
    input  be_push_id, be_rid, be_rlen,
    output rq_rid
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

modport rdata_wrapper (
    // AXI R Data path
    input rready, 
    // READ_ID_QUEUE -> RDATA_WRAPPER
    rq_rid,
    // Data Transfer
    memload, edge_flag,
    // AXI R Path
    output rvalid, rdata, rid, rlast, rresp
);

modport command_fsm (
    //BQ -> FSM
    input bq_ready, bq_bg, bq_b, bq_slot,
    //BE -> FSM
    be_arb,
    //REFRESH
    fsm_ref,
    //FSM -> BE 
    output be_r, be_c, be_b, be_bg, be_cmd, be_id, be_rlen, be_queue_ready,
    //FSM -> BQ
    bq_pop
);

modport fsm_mod (
    // Inputs from cmd_fsm (per-bank wiring)
    input  fsm_rw, fsm_r, fsm_bqready, fsm_arb, fsm_ref,
    // Outputs to cmd_fsm
    output fsm_pop, fsm_ready, fsm_cmd
);

modport backend_arb (
    //FSM -> BE
    input be_r, be_c, be_b, be_bg, be_cmd, be_id, be_queue_ready, be_len,
    //BE -> FSM
    output be_arb, 
    //BE -> WDATA_QUEUE
    be_wid, be_write, 
    //BE -> R_ID_QUEUE
    be_rid, be_push_id, be_rlen,
    //BE -> REFRESH COUNTER
    rf_enable, rf_done, init_done,
    
    //BE -> SIGNAL GEN
    ref_re, state, nstate, RA0, BG0, BA0, R0, C0
);

modport refresh_cntrl (
    //BE -> REFRESH COUNTER
    input rf_enable, ref_done,
    //REFRESH COUNTER -> FSM
    output fsm_ref
);

modport init_ctrl (
    //EXTERNAL -> INIT STATE
    input init_start,
    //INIT STATE -> SYSTEM
    output init_done, init_state, next_init_state
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

modport ddr_cntrl_top (
    // ===== INPUTS (FROM AXI) =====
    // AW Channel
    input awvalid, awaddr, awid, awlen,
    // AR Channel
    arvalid, araddr, arid, arlen,
    // W Channel
    wdq_slot, wvalid, wlast,
    // B Channel (AXI master ready for write response)
    bwready,
    // R Channel (AXI master ready for read data)
    rready,
    // System
    init_start,

    // ===== OUTPUTS (TO AXI) =====
    // AW Response
    output awready,
    // AR Response
    arready,
    // W/B Response (Write Data Wrapper -> AXI)
    wready, bwvalid, bwresp, bwid,
    // R Data (Read ID Queue -> AXI)
    rvalid, rdata, rid, rlast, rresp,


    // ===== OUTPUTS (TO DRAM) =====
    // Write Data Path (WDQ Wrapper -> DRAM)
    //ddr_wdata_data, ddr_wdata_en, ddr_wdata_mask, ddr_we,
    // Command Path (Signal gen -> DRAM)
    ACT_n, RAS_n_A16, CAS_n_A15, WE_n_A14, ALERT_n, PARITY, RESET_n, TEN, CS_n, CKE, ODT, C, BG, BA, ADDR, ADDR_17, PWR, VREF_CA, VREF_DQ, ZQ,
    //be_arb, be_cmd, be_r, be_c, be_b, be_bg, be_id,
    // Init Status
    //init_done, init_state, next_init_state
    inout DQ, DQS_t, DQS_c, DM_n

);

modport signal_gen (
        input ref_re,
        input state, nstate, RA0, BG0, BA0, R0, C0,
        output ACT_n, RAS_n_A16, CAS_n_A15, WE_n_A14, ALERT_n, PARITY, RESET_n, TEN, CS_n, CKE, ODT, C, BG, BA, ADDR, ADDR_17, PWR, VREF_CA, VREF_DQ, ZQ
    );

modport data_transfer (
        input wr_en, rd_en, clear, memstore, COL_choice,
        inout DQ, DQS_t, DQS_c, DM_n, // same names as above, so do not need to map
        output memload, edge_flag
    );

endinterface

`endif // DDR_CONTROLLER_IF_SV
