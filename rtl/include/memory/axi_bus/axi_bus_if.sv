/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_IF_SV
`define AXI_BUS_IF_SV

interface axi_bus_if(input logic CLK, input logic nRST);
    `include "axi_bus_params.svh"

    import axi_bus_pkg::*;

    // master side channel structs 
    master_ar_channel_t ar_sp0_i; // Scratchpad0 AR channel
    master_ar_channel_t ar_sp1_i; // Scratchpad1 AR channel
    master_ar_channel_t ar_d_i;   // D$ AR channel
    master_ar_channel_t ar_i_i;   // I$ AR channel
    master_r_channel_t  r_sp0_o;  // Scratchpad0 R channel
    master_r_channel_t  r_sp1_o;  // Scratchpad1 R channel
    master_r_channel_t  r_d_o;    // D$ R channel
    master_r_channel_t  r_i_o;    // I$ R channel
    master_aw_channel_t aw_sp0_i; // Scratchpad0 AW channel
    master_aw_channel_t aw_sp1_i; // Scratchpad1 AW channel
    master_aw_channel_t aw_d_i;   // D$ AW channel
    master_w_channel_t  w_sp0_i;  // Scratchpad0 W channel
    master_w_channel_t  w_sp1_i;  // Scratchpad1 W channel
    master_w_channel_t  w_d_i;    // D$ W channel
    master_b_channel_t  b_sp0_o;  // Scratchpad0 B channel
    master_b_channel_t  b_sp1_o;  // Scratchpad1 B channel
    master_b_channel_t  b_d_o;    // D$ B channel

    // general aw channel struct (master side)
    master_aw_channel_t aw_gen_i; // General AW Channel for Write Manager
    // general w channel struct (master side)
    master_w_channel_t w_gen_i; // General W Channel for Write Manager

    // subordinate side channel structs
    sub_ar_channel_t ar_o;     // Controller AR channel
    sub_r_channel_t  r_i;      // Controller R channel
    sub_aw_channel_t aw_o;     // Controller AW channel
    sub_w_channel_t  w_o;      // Controller W channel
    sub_b_channel_t  b_i;      // Controller B channel

    // general aw channel struct (subordinate side)
    sub_aw_channel_t head_aw_o; // General AW Channel for Write Manager
    // general w channel struct (subordinate side)
    sub_w_channel_t head_w_o; // General W Channel for Write Manager

    // read arbiter signals 
    logic sp0_req_r, sp1_req_r, d_req_r, i_req_r, skid_ready_r;
    logic [ARGRANT-1:0] ar_grant;

    // write arbiter signals
    logic sp0_req_w, sp1_req_w, d_req_w, skid_ready_w;
    logic [AWLEN-1:0] sp0_len_w, sp1_len_w, d_len_w;
    logic [AWGRANT-1:0] aw_grant;

    // SP0 & AR MANAGER READY/VALID
    logic ar_sp0_i_valid, ar_sp0_i_ready;

    // SP1 & AR MANAGER READY/VALID
    logic ar_sp1_i_valid, ar_sp1_i_ready;

    // D$ & AR MANAGER READY/VALID
    logic ar_d_i_valid, ar_d_i_ready;

    // I$ & AR MANAGER READY/VALID
    logic ar_i_i_valid, ar_i_i_ready;

    // DRAM CONTROLLER & READ SKID BUFFER READY/VALID
    logic ar_o_valid, ar_o_ready;

    // DRAM CONTROLLER & READ RESPONSE ROUTER READY/VALID
    logic r_i_valid, r_i_ready;

    // SP0 R Skid Buffer && SP0 READY/VALID
    logic r_sp0_o_valid, r_sp0_o_ready;

    // SP1 R Skid Buffer && SP1 READY/VALID
    logic r_sp1_o_valid, r_sp1_o_ready;

    // D$ R Skid Buffer && D$ READY/VALID
    logic r_d_o_valid, r_d_o_ready;

    // I$ R Skid Buffer && I$ READY/VALID
    logic r_i_o_valid, r_i_o_ready;

    // SP0 & AW_W MANAGER READY/VALID
    logic aw_sp0_i_valid, aw_sp0_i_ready, w_sp0_i_valid, w_sp0_i_ready;

    // SP1 & AW_W MANAGER READY/VALID
    logic aw_sp1_i_valid, aw_sp1_i_ready, w_sp1_i_valid, w_sp1_i_ready;

    // D$ & AW_W MANAGER READY/VALID
    logic aw_d_i_valid, aw_d_i_ready, w_d_i_valid, w_d_i_ready;

    // DRAM CONTROLLER & WRITE SKID BUFFER READY/VALID
    logic aw_o_valid, aw_o_ready, w_o_valid, w_o_ready;

    // DRAM CONTROLLER & WRITE RESPONSE ROUTER
    logic b_i_valid, b_i_ready;

    // SP0 B Skid Buffer && SP0 READY/VALID
    logic b_sp0_o_valid, b_sp0_o_ready;

    // SP1 B Skid Buffer && SP1 READY/VALID
    logic b_sp1_o_valid, b_sp1_o_ready;

    // D$ R Skid Buffer && D$ READY/VALID
    logic b_d_o_valid, b_d_o_ready;

    // WRITE MANAGER SIGNALS
    logic awvalid, awready; // GENERAL AW WRITE MANAGER READY/VALID
    logic wvalid, wready;   // GENERAL W WRITE MANAGER READY/VALID
    logic aw_pop, w_pop; 
    logic head_awvalid, head_wvalid;

    // test assertions
    property wrt_valid_ready;
        @(posedge CLK)
        (awvalid && !awready) |-> $stable(aw_gen_i);
    endproperty

    assert property (wrt_valid_ready)
        else $error("data changed during low ready");

    // ----------------------------------------------------------------------
    // READ PATH Definitions
    // ----------------------------------------------------------------------
    // MASTER <=> SP0 AR MANAGER
    modport ar_sp0_manager (
        // From Master 
        input ar_sp0_i_valid, ar_sp0_i,

        // To Master 
        output ar_sp0_i_ready
    );

    // MASTER <=> SP1 AR MANAGER
    modport ar_sp1_manager (
        // From Master 
        input ar_sp1_i_valid, ar_sp1_i,

        // To Master 
        output ar_sp1_i_ready
    );

    // MASTER <=> D$ AR MANAGER
    modport ar_d_manager (
        // From Master 
        input ar_d_i_valid, ar_d_i,

        // To Master 
        output ar_d_i_ready
    );

    // MASTER <=> I$ AR MANAGER
    modport ar_i_manager (
        // From Master 
        input ar_i_i_valid, ar_i_i,

        // To Master 
        output ar_i_i_ready
    );

    // DRAM CONTROLLER <=> READ SKID BUFFER
    modport ar_to_subordinate (
        // To Subordinate
        output ar_o_valid, ar_o,

        // From Subordinate
        input ar_o_ready
    );

    // DRAM CONTROLLER <=> READ RESPONSE ROUTER
    modport subordinate_to_r (
        // To Subordinate
        output r_i_ready, 

        // From Subordinate
        input r_i_valid, r_i
    );

    // SP0 R Skid Buffer <=> SP0
    modport r_to_sp0 (
        // To Master 
        output r_sp0_o_valid, r_sp0_o,

        // From Master
        input r_sp0_o_ready
    );

    // SP1 R Skid Buffer <=> SP1
    modport r_to_sp1 (
        // To Master 
        output r_sp1_o_valid, r_sp1_o,

        // From Master
        input r_sp1_o_ready
    );

    // D$ R Skid Buffer <=> D$
    modport r_to_d (
        // To Master 
        output r_d_o_valid, r_d_o,

        // From Master
        input r_d_o_ready
    );

    // I$ R Skid Buffer <=> I$
    modport r_to_i (
        // To Master 
        output r_i_o_valid, r_i_o,

        // From Master
        input r_i_o_ready
    );

    // AR MANAGERS <=> READ ARBITER
    modport read_arbiter (
        // From Manager
        input sp0_req_r, sp1_req_r, d_req_r, i_req_r,

        // From Skid Buffer
        input skid_ready_r,

        // To Read Mux
        output ar_grant
    );

    // ----------------------------------------------------------------------
    // WRITE PATH Definitions
    // ----------------------------------------------------------------------
    // MASTER <=> SP0 AW_W MANAGER
    modport aw_w_sp0_manager (
        // From Master 
        input aw_sp0_i_valid, aw_sp0_i, w_sp0_i_valid, w_sp0_i,

        // To Master 
        output aw_sp0_i_ready, w_sp0_i_ready
    );

    // MASTER <=> SP1 AW_W MANAGER
    modport aw_w_sp1_manager (
        // From Master 
        input aw_sp1_i_valid, aw_sp1_i, w_sp1_i_valid, w_sp1_i,

        // To Master 
        output aw_sp1_i_ready, w_sp1_i_ready
    );

    // MASTER <=> D$ AW_W MANAGER
    modport aw_w_d_manager (
        // From Master 
        input aw_d_i_valid, aw_d_i, w_d_i_valid, w_d_i,

        // To Master 
        output aw_d_i_ready, w_d_i_ready
    );

    // DRAM CONTROLLER <=> WRITE SKID BUFFER
    modport aw_to_subordinate (
        // To Subordinate
        output aw_o_valid, aw_o,

        // From Subordinate
        input aw_o_ready
    );

    // DRAM CONTROLLER <=> WRITE SKID BUFFER
    modport w_to_subordinate (
        // To Subordinate
        output w_o_valid, w_o,

        // From Subordinate
        input w_o_ready
    );

    // DRAM CONTROLLER <=> WRITE RESPONSE ROUTER
    modport subordinate_to_b (
        // To Subordinate
        output b_i_ready,

        // From Subordinate
        input b_i_valid, b_i
    );

    // SP0 B Skid Buffer <=> SP0
    modport b_to_sp0 (
        // To Master 
        output b_sp0_o_valid, b_sp0_o,

        // From Master
        input b_sp0_o_ready
    );

    // SP1 B Skid Buffer <=> SP1
    modport b_to_sp1 (
        // To Master 
        output b_sp1_o_valid, b_sp1_o,

        // From Master
        input b_sp1_o_ready
    );

    // D$ B Skid Buffer <=> D$
    modport b_to_d (
        // To Master 
        output b_d_o_valid, b_d_o,

        // From Master
        input b_d_o_ready
    );

    // WRITE ARBITER
    modport write_arbiter (
        // From Manager
        input sp0_req_w, sp1_req_w, d_req_w,
        input sp0_len_w, sp1_len_w, d_len_w,

        // From Skid Buffer
        input skid_ready_w,

        // To Read Mux/AR Manager 
        output aw_grant
    );

    // WRITE MANAGER
    modport write_manager (
        // From Master AW Channel
        input awvalid, aw_gen_i,
        // To Master AW Channel
        output awready,
        // From Master W Channel
        input wvalid, w_gen_i,
        // To Master W Channel
        output wready, 
        // From Write Controller
        input aw_pop, w_pop,
        // To AW MUX
        output head_awvalid, head_aw_o,
        // To W MUX
        output head_wvalid, head_w_o
    );

    // ----------------------------------------------------------------------
    // WRITE PATH TB Definitions
    // ----------------------------------------------------------------------
    // WRITE ARBITER TB
    modport write_arbiter_tb (
        // From Manager
        output sp0_req_w, sp1_req_w, d_req_w,
        output sp0_len_w, sp1_len_w, d_len_w,

        // From Skid Buffer
        output skid_ready_w,

        // To Read Mux/AR Manager 
        input aw_grant
    );

    // WRITE MANAGER TB
    modport write_manager_tb (
        // From Master AW Channel
        output awvalid, aw_gen_i,
        // To Master AW Channel
        input awready,
        // From Master W Channel
        output wvalid, w_gen_i,
        // To Master W Channel
        input wready, 
        // From Write Controller
        output aw_pop, w_pop,
        // To AW MUX
        input head_awvalid, head_aw_o,
        // To W MUX
        input head_wvalid, head_w_o 
    );

endinterface
`endif // AXI_BUS_IF_SV