`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module ddr_controller_wrapper (
    input logic CLK, nRST,
    ddr_controller_if.ddr_cntrl_top top
);

    import dram_pkg::*;

    // ================================================================
    // Internal interface instance (shared by all submodules)
    // ================================================================
    ddr_controller_if cif();

    // ================================================================
    // External inputs -> Internal interface
    // ================================================================

    // AW Channel (AXI -> STQ)
    assign cif.awvalid = top.awvalid;
    assign cif.awaddr  = top.awaddr;
    assign cif.awid    = top.awid;
    assign cif.awlen   = top.awlen;

    // AR Channel (AXI -> LQ)
    assign cif.arvalid = top.arvalid;
    assign cif.araddr  = top.araddr;
    assign cif.arid    = top.arid;
    assign cif.arlen   = top.arlen;

    // W Channel (AXI -> WDQ Wrapper)
    assign cif.wdq_slot = top.wdq_slot;
    assign cif.wvalid   = top.wvalid;
    assign cif.wlast    = top.wlast;

    // B Channel (AXI master response ready -> WDQ Wrapper)
    assign cif.bwready = top.bwready;

    // R Channel (AXI master read ready -> RID Queue)
    assign cif.rready = top.rready;

    // System
    assign cif.init_start = top.init_start;

    // ================================================================
    // Internal interface -> External outputs (to AXI)
    // ================================================================

    // AW Response (STQ -> AXI)
    assign top.awready = cif.awready;

    // AR Response (LQ -> AXI)
    assign top.arready = cif.arready;

    // W/B Response (WDQ Wrapper -> AXI)
    assign top.wready  = cif.wready;
    assign top.bwvalid = cif.bwvalid;
    assign top.bwresp  = cif.bwresp;
    assign top.bwid    = cif.bwid;

    // R Data (RID Queue -> AXI)
    assign top.rq_rvalid = cif.rq_rvalid;
    assign top.rq_rid    = cif.rq_rid;
    assign top.rq_rlen   = cif.rq_rlen;

    // ================================================================
    // Internal interface -> External outputs (to DRAM)
    // ================================================================

    // Write Data Path (WDQ Wrapper -> DRAM)
    assign top.ddr_wdata_data = cif.ddr_wdata_data;
    assign top.ddr_wdata_en   = cif.ddr_wdata_en;
    assign top.ddr_wdata_mask = cif.ddr_wdata_mask;
    assign top.ddr_we         = cif.ddr_we;

    // Command Path (Backend Arbiter -> Signal Generator)
    assign top.be_arb = cif.be_arb;
    assign top.be_cmd = cif.be_cmd;

    // Address Path (Command FSM -> Signal Generator)
    assign top.be_r  = cif.be_r;
    assign top.be_c  = cif.be_c;
    assign top.be_b  = cif.be_b;
    assign top.be_bg = cif.be_bg;
    assign top.be_id = cif.be_id;

    // Init Status
    assign top.init_done       = cif.init_done;
    assign top.init_state      = cif.init_state;
    assign top.next_init_state = cif.next_init_state;

    // ================================================================
    // Module Instantiations
    // ================================================================

    // Frontend: Store Queue (AXI AW -> STQ)
    store_queue STQ (
        .CLK  (CLK),
        .nRST (nRST),
        .stq  (cif.stq)
    );

    // Frontend: Load Queue (AXI AR -> LQ)
    load_queue LQ (
        .CLK  (CLK),
        .nRST (nRST),
        .lq   (cif.lq)
    );

    // Frontend: Arbiter + Address Mapper
    frontend_arb FE_ARB (
        .CLK  (CLK),
        .nRST (nRST),
        .arb  (cif.arb)
    );

    // Bank Queues [15:0]
    nb_bank_queue BQ (
        .CLK  (CLK),
        .nRST (nRST),
        .bqif (cif.bq)
    );

    // Command FSMs (16 per-bank fsm_mod instances)
    cmd_fsm CMD_FSM (
        .CLK  (CLK),
        .nRST (nRST),
        .fsm  (cif.command_fsm)
    );

    // Backend Arbiter
    nb_barb BARB (
        .CLK  (CLK),
        .nRST (nRST),
        .barb (cif.backend_arb)
    );

    // Refresh Counter
    refresh_counter REF_CNT (
        .CLK  (CLK),
        .nRST (nRST),
        .rcif (cif.refresh_cntrl)
    );

    // Write Data Queue Wrapper (8 per-ID queues)
    nb_wdata_queue_wrapper WDQ_WRAP (
        .CLK  (CLK),
        .nRST (nRST),
        .wdw  (cif.wdata_wrapper)
    );
/*
    // Read ID Queue
    nb_read_id_queue RID_Q (
        .CLK  (CLK),
        .nRST (nRST),
        .r_id_queue (cif.read_id_queue)
    );

    // Initialization State Machine
    init_state INIT (
        .CLK  (CLK),
        .nRST (nRST),
        .isif (cif.init_ctrl)
    );
*/
endmodule
