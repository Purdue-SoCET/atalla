/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_PKG_VH
`define AXI_BUS_PKG_VH

package axi_bus_pkg;

    // Master 
    parameter NUM_MASTERS    = 4;
    parameter MID            = $clog2(4);
    parameter NUM_U_READS    = 4;      // Number of outstanding reads across UNITS (I$, D$, SP0, SP1)
    parameter NUM_U_WRITES   = 4;      // Number of outstanding writes across UNITS (D$, SP0, SP1)

    // AR Channel Widths
    parameter ARVALID        = 1;
    parameter ARADDR         = 32;
    parameter ARID           = $clog2(NUM_U_READS);
    parameter ARSIZE         = 3;
    parameter ARLEN          = 3; // changed from 4 to 3, describes how many beats in a transfer. 
    parameter ARBURST        = 2;
    parameter MID_ARID       = MID + ARID;
    parameter ARGRANT        = 3;

    // AR Manager Width
    parameter AR_DEPTH   = NUM_U_READS;
    parameter ADDR_WIDTH = $clog2(AR_DEPTH);

    // R Channel Widths
    parameter RDATA          = 64;
    parameter RID            = $clog2(NUM_U_READS);
    parameter RRESP          = 2;
    parameter MID_RID        = MID + RID;

    // AW Channel Width
    parameter AWADDR         = 32;
    parameter AWID           = $clog2(NUM_U_WRITES);
    parameter AWSIZE         = 3;
    parameter AWLEN          = 4;
    parameter AWBURST        = 2;
    parameter MID_AWID       = MID + AWID;

    // W Channel Width
    parameter WDATA          = 64;
    parameter WID            = $clog2(NUM_U_WRITES);
    parameter WSTRB          = 8;
    parameter MID_WID        = MID + WID;

    // B Channel Width
    parameter BID            = $clog2(NUM_U_WRITES);
    parameter BRESP          = 2;
    parameter MID_BID        = MID + BID;

    // Master IDs
    typedef enum logic [MID-1:0] {
        SP0              = 2'b00,
        SP1              = 2'b01,
        DCACHE           = 2'b10,
        ICAHCE           = 2'b11
    } mid_t;

    // RRESP options
    typedef enum logic [RRESP-1:0] {
        R_OKAY           = 2'b00,
        R_EXOKAY         = 2'b01,
        R_SLVERR         = 2'b10, 
        R_DECERR         = 2'b11
    } rresp_t;

    // BRESP options
    typedef enum logic [BRESP-1:0] {
        B_OKAY           = 2'b00,
        B_EXOKAY         = 2'b01,
        B_SLVERR         = 2'b10,
        B_DECERR         = 2'b11
    } bresp_t;

    // AR Channel 
    typedef struct packed {
        logic                valid;
        logic                ready;
        logic [ARADDR-1:0]   addr;
        logic [ARID-1:0]     id;     // Local (2-bit) ID: index within master
        logic [ARSIZE-1:0]   size;
        logic [ARLEN-1:0]    len;
        logic [ARBURST-1:0]  burst;
        logic [MID_ARID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
    } ar_channel_t;

    // AR Queue payload
    typedef struct packed {
        logic                valid;
        logic [ARADDR-1:0]   addr;
        logic [MID_ARID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
        logic [ARSIZE-1:0]   size;
        logic [ARLEN-1:0]    len;
        logic [ARBURST-1:0]  burst;
    } ar_payload_t;

    // R Channel 
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [RDATA-1:0]   data;
        logic [RID-1:0]     id;
        logic               last;
        rresp_t             resp;
        logic [MID_RID-1:0] mid_id;
    } r_channel_t;

    // AW Channel 
    typedef struct packed {
        logic                valid;
        logic                ready;
        logic [AWADDR-1:0]   addr;
        logic [AWID-1:0]     id;
        logic [AWSIZE-1:0]   size;
        logic [AWLEN-1:0]    len;
        logic [AWBURST-1:0]  burst;
        logic [MID_AWID-1:0] mid_id;
    } aw_channel_t;

    // W Channel 
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [WDATA-1:0]   data;
        logic [WID-1:0]     id;
        logic               last;
        logic [WSTRB-1:0]   strb;
        logic [MID_WID-1:0] mid_id;
    } w_channel_t;

    // B Channel
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [BID-1:0]     id;
        bresp_t             resp;
        logic [MID_BID-1:0] mid_id;
    } b_channel_t;

endpackage
`endif // AXI_BUS_PKG_VH

