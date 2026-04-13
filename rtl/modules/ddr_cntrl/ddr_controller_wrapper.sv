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
    assign top.rvalid = cif.rvalid;
    assign top.rdata  = cif.rdata;
    assign top.rid    = cif.rid;
    assign top.rlast  = cif.rlast;
    assign top.rresp  = cif.rresp;

    // In Outs for the data transfer unit to DRAM
    assign top.DQ = cif.DQ;
    assign top.DQS_t = cif.DQS_t;
    assign top.DQS_c = cif.DQS_c;
    assign top.DM_n = cif.DM_n;

    // ================================================================
    // Internal interface -> External outputs (to DRAM)
    // ================================================================

    // Write Data Path (WDQ Wrapper -> DRAM)
    // assign top.ddr_wdata_data = cif.ddr_wdata_data;
    // assign top.ddr_wdata_en   = cif.ddr_wdata_en;
    // assign top.ddr_wdata_mask = cif.ddr_wdata_mask;
    // assign top.ddr_we         = cif.ddr_we;

    // Command Path (Backend Arbiter -> Signal Generator)
    // assign top.be_arb = cif.be_arb;
    // assign top.be_cmd = cif.be_cmd;

    // Address Path (Command FSM -> Signal Generator)
    // assign top.be_r  = cif.be_r;
    // assign top.be_c  = cif.be_c;
    // assign top.be_b  = cif.be_b;
    // assign top.be_bg = cif.be_bg;
    // assign top.be_id = cif.be_id;

    // // Init Status
    // assign top.init_done       = cif.init_done;
    // assign top.init_state      = cif.init_state;
    // assign top.next_init_state = cif.next_init_state;

    // Outputs to Signal Generator
    assign top.ACT_n = cif.ACT_n;
    assign top.RAS_n_A16 = cif.RAS_n_A16;
    assign top.CAS_n_A15 = cif.CAS_n_A15;
    assign top.WE_n_A14 = cif.WE_n_A14;
    assign top.ALERT_n = cif.ALERT_n;
    assign top.PARITY = cif.PARITY;
    assign top.RESET_n = cif.RESET_n;
    assign top.TEN = cif.TEN;
    assign top.CS_n = cif.CS_n;
    assign top.CKE = cif.CKE;
    assign top.ODT = cif.ODT;
    assign top.C = cif.C;
    assign top.BG = cif.BG;
    assign top.BA = cif.BA;
    assign top.ADDR = cif.ADDR;
    assign top.ADDR_17 = cif.ADDR_17;
    assign top.PWR = cif.PWR;
    assign top.VREF_CA = cif.VREF_CA;
    assign top.VREF_DQ = cif.VREF_DQ;
    assign top.ZQ = cif.ZQ;

    // Wdata queue and inputs to data transfer unit
    assign cif.wr_en = cif.ddr_wdata_mask; // this is byte level, need to change this
    assign cif.memstore = cif.ddr_wdata_data;


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

    // Signal Generator
    signal_gen SG (
        .CLK  (CLK),
        .nRST (nRST),
        .sgif (cif.signal_gen)
    );

    data_transfer data_trans (
        .CLK  (CLK),
        .nRST (nRST),
        .dtif (cif.data_transfer)
    );

    // Read ID Queue
    nb_read_id_queue RID_Q (
        .CLK  (CLK),
        .nRST (nRST),
        .r_id_queue (cif.read_id_queue)
    );

    // Read Data wrapper
    nb_rdata_wrapper RDQ_WRAP (
        .CLK  (CLK),
        .nRST (nRST),
        .rdw (cif.rdata_wrapper)
    )
/*
    // Initialization State Machine
    init_state INIT (
        .CLK  (CLK),
        .nRST (nRST),
        .isif (cif.init_ctrl)
    );
*/
endmodule
