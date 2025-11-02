/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_PKG_VH
`define AXI_BUS_PKG_VH

package axi_bus_pkg;

    // Master 
    parameter NUM_MASTERS    = 4;
    parameter NUM_READS      = 16;          // Number of outstanding reads across entire system
    parameter NUM_WRITES     = 12;          // Number of outstanding writes across entire system
    parameter MID            = $clog2(4);
    parameter NUM_U_READS    = NUM_READS/NUM_MASTERS;      // Number of outstanding reads across UNITS (I$, D$, SP0, SP1)
    parameter NUM_U_WRITES   = NUM_WRITES/(NUM_MASTERS-1); // Number of outstanding writes across UNITS (D$, SP0, SP1)

    // AR Channel Widths
    parameter ARADDR         = 32;
    parameter ARID           = $clog2(NUM_U_READS);
    parameter ARSIZE         = 3;
    parameter ARLEN          = 4;
    parameter ARBURST        = 2;
    parameter ARID_MID       = ARID + MID;

    // R Channel Widths
    parameter RDATA          = 64;
    parameter RID            = $clog2(NUM_U_READS);
    parameter RRESP          = 2;
    parameter RID_MID        = RID + MID;

    // AW Channel Width
    parameter AWADDR         = 32;
    parameter AWID           = $clog2(NUM_U_WRITES);
    parameter AWSIZE         = 3;
    parameter AWLEN          = 4;
    parameter AWBURST        = 2;
    parameter AWID_MID       = AWID + MID;

    // W Channel Width
    parameter WDATA          = 64;
    parameter WID            = $clog2(NUM_U_WRITES);
    parameter WSTRB          = 8;
    parameter WID_MID        = WID + MID;

    // B Channel Width
    parameter BID            = $clog2(NUM_U_WRITES);
    parameter BRESP          = 2;
    parameter BID_MID        = BID + MID;

    // Master IDs
    typedef enum logic [MID-1:0] {
        ICACHE         = 2'b00,
        DCACHE         = 2'b01,
        SPO            = 2'b10,
        SP1            = 2'b11
    } mid_t;

        // RRESP options
    typedef enum logic [RRESP-1:0] {
        OKAY           = 2'b00,
        EXOKAY         = 2'b01,
        SLVERR         = 2'b10, 
        DECERR         = 2'b11
    } rresp_t;

    // BRESP options
    typedef enum logic [BRESP-1:0] {
        OKAY           = 2'b00,
        EXOKAY         = 2'b01,
        SLVERR         = 2'b10,
        DECERR         = 2'b11
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
        logic [ARID_MID-1:0] mid_id; // Global (4-bit) ID: {MASTER_ID, id}
    } ar_channel_t;

    // R Channel 
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [RDATA-1:0]   data;
        logic [RID-1:0]     id;
        logic               last;
        rresp_t             resp;
        logic [RID_MID-1:0] mid_id;
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
        logic [AWID_MID-1:0] mid_id;
    } aw_channel_t;

    // W Channel 
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [WDATA-1:0]   data;
        logic [WID-1:0]     id;
        logic               last;
        logic [WSTRB-1:0]   strb;
        logic [WID_MID-1:0] mid_id;
    } w_channel_t;

    // B Channel
    typedef struct packed {
        logic               valid;
        logic               ready;
        logic [BID-1:0]     id;
        bresp_t             resp;
        logic [BID_MID-1:0] mid_id;
    } b_channel_t;

endpackage
`endif // AXI_BUS_PKG_VH

