/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_PKG_SV
`define AXI_BUS_PKG_SV

package axi_bus_pkg;
    `include "axi_bus_params.svh"

    //////////////////////////////////////////////////////////////////////
    ///////////////////////// Derived Parameters /////////////////////////
    //////////////////////////////////////////////////////////////////////
    
    // Master ID Width
    localparam int MID            = $clog2(NUM_MASTERS);

    // AR Channel Widths
    localparam int ARADDR         = ADDR_WIDTH;
    localparam int ARID           = $clog2(NUM_U_READS);
    localparam int ARSIZE         = 3;
    localparam int ARLEN          = 4; // describes how many beats in a transfer. 
    localparam int ARBURST        = 2;
    localparam int MID_ARID       = MID + ARID;

    // R Channel Widths
    localparam int RDATA          = DATA_BEAT_WIDTH;
    localparam int RID            = $clog2(NUM_U_READS);
    localparam int RRESP          = 2;
    localparam int MID_RID        = MID + RID;

    // AW Channel Width
    localparam int AWADDR         = ADDR_WIDTH;
    localparam int AWID           = $clog2(NUM_U_WRITES);
    localparam int AWSIZE         = 3;
    localparam int AWLEN          = 4; // describes how many beats in a transfer.
    localparam int AWBURST        = 2;
    localparam int MID_AWID       = MID + AWID;

    // W Channel Width
    localparam int WDATA          = DATA_BEAT_WIDTH;
    localparam int WID            = $clog2(NUM_U_WRITES);
    localparam int WSTRB          = DATA_BEAT_WIDTH/8;    // 1 bit for each byte in data beat
    localparam int MID_WID        = MID + WID;

    // B Channel Width
    localparam int BID            = $clog2(NUM_U_WRITES);
    localparam int BRESP          = 2;
    localparam int MID_BID        = MID + BID;

    // READ Arbiter Width
    localparam int ARGRANT        = 1 + ARID; // 1 valid bit and then bits representing which master

    // WRITE Arbiter Width
    localparam int AWGRANT        = 1 + AWID; // 1 valid bit and then bits representing which master

    // AR Manager FIFO Width
    localparam int AR_DEPTH       = NUM_U_READS;
    localparam int AR_PTR_WIDTH   = $clog2(AR_DEPTH);

    // AW+W Manager AW FIFO Width
    localparam int AW_DEPTH       = NUM_U_WRITES;
    localparam int AW_PTR_WIDTH   = $clog2(AW_DEPTH); 

    // AW+W Manager W FIFO Width
    localparam int W_DEPTH        = NUM_U_WRITES*8;
    localparam int W_PTR_WIDTH   = $clog2(W_DEPTH); 

    //////////////////////////////////////////////////////////////////////
    ////////////////////////////////// Enums /////////////////////////////
    //////////////////////////////////////////////////////////////////////

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
        logic [ARADDR-1:0]   addr;
        logic [ARID-1:0]     id;     // Local (2-bit) ID: index within master
        logic [ARSIZE-1:0]   size;
        logic [ARLEN-1:0]    len;
        logic [ARBURST-1:0]  burst;
        logic [MID_ARID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
    } ar_channel_t;

    // R Channel 
    typedef struct packed {
        logic [RDATA-1:0]   data;
        logic [RID-1:0]     id;
        logic               last;
        rresp_t             resp;
        logic [MID_RID-1:0] mid_id;
    } r_channel_t;

    // AW Channel 
    typedef struct packed {
        logic [AWADDR-1:0]   addr;
        logic [AWID-1:0]     id;
        logic [AWSIZE-1:0]   size;
        logic [AWLEN-1:0]    len;
        logic [AWBURST-1:0]  burst;
        logic [MID_AWID-1:0] mid_id;
    } aw_channel_t;

    // W Channel 
    typedef struct packed {
        logic [WDATA-1:0]   data;
        logic [WID-1:0]     id;
        logic               last;
        logic [WSTRB-1:0]   strb;
        logic [MID_WID-1:0] mid_id;
    } w_channel_t;

    // B Channel
    typedef struct packed {
        logic [BID-1:0]     id;
        bresp_t             resp;
        logic [MID_BID-1:0] mid_id;
    } b_channel_t;

    // AR Payload
    typedef struct packed {
        logic                valid;
        logic [ARADDR-1:0]   addr;
        logic [MID_ARID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
        logic [ARSIZE-1:0]   size;
        logic [ARLEN-1:0]    len;
        logic [ARBURST-1:0]  burst;
    } ar_payload_t;

    // R Payload
    typedef struct packed {
        logic               valid;
        logic [RDATA-1:0]   data;
        logic [RID-1:0]     id;
        logic               last;
        rresp_t             resp;
    } r_payload_t;

    // AW Payload
    typedef struct packed {
        logic                valid;
        logic [AWADDR-1:0]   addr;
        logic [MID_AWID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
        logic [AWSIZE-1:0]   size;
        logic [AWLEN-1:0]    len;
        logic [AWBURST-1:0]  burst;
    } aw_payload_t;

    // W Payload
    typedef struct packed {
        logic                valid;
        logic [MID_ARID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
        logic [WDATA-1:0]    data;
        logic                last;
        logic [WSTRB-1:0]    strb;
    } w_payload_t;

    // B Payload
    typedef struct packed {
        logic               valid;
        logic [BID-1:0]     id;
        bresp_t             resp;
    } b_payload_t;

endpackage
`endif // AXI_BUS_PKG_SV