`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module frontend_wrapper (
    input logic CLK, nRST,
    ddr_controller_if.frontend_tb fe
);

    ddr_controller_if feif();

    // Connect TB-driven signals into internal interface
    assign feif.awvalid = fe.awvalid;
    assign feif.awaddr  = fe.awaddr;
    assign feif.awid    = fe.awid;
    assign feif.awlen   = fe.awlen;

    assign feif.arvalid = fe.arvalid;
    assign feif.araddr  = fe.araddr;
    assign feif.arid    = fe.arid;
    assign feif.arlen   = fe.arlen;

    assign feif.fe_full = fe.fe_full;

    // Connect internal interface outputs back to TB
    assign fe.awready    = feif.awready;
    assign fe.arready    = feif.arready;
    assign fe.request_l  = feif.request_l;
    assign fe.request_s  = feif.request_s;
    assign fe.lq_slot    = feif.lq_slot;
    assign fe.stq_slot   = feif.stq_slot;
    assign fe.grant_l    = feif.grant_l;
    assign fe.grant_s    = feif.grant_s;
    assign fe.fe_bg      = feif.fe_bg;
    assign fe.fe_b       = feif.fe_b;
    assign fe.fe_r       = feif.fe_r;
    assign fe.fe_c       = feif.fe_c;
    assign fe.fe_write   = feif.fe_write;
    assign fe.fe_id      = feif.fe_id;
    assign fe.fe_len     = feif.fe_len;
    assign fe.fe_write_bq = feif.fe_write_bq;

    // Instantiate front-end modules
    store_queue STQ (
        .CLK(CLK),
        .nRST(nRST),
        .stq(feif.stq)
    );

    load_queue LQ (
        .CLK(CLK),
        .nRST(nRST),
        .lq(feif.lq)
    );

    frontend_arb ARB (
        .CLK(CLK),
        .nRST(nRST),
        .arb(feif.arb)
    );

endmodule
