/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_IF_VH
`define AXI_BUS_IF_VH

`include "axi_bus_pkg.vh"

interface axi_bus_if;
    // import types 
    import axi_bus_pkg::*;

    // channel structs 
    ar_channel_t ar_sp0_i; // Scratchpad0 AR channel
    ar_channel_t ar_sp1_i; // Scratchpad1 AR channel
    ar_channel_t ar_d_i;   // D$ AR channel
    ar_channel_t ar_i_i;   // I$ AR channel
    ar_channel_t ar_o;     // Controller AR channel
    r_channel_t  r_i;      // Controller R channel
    r_channel_t  r_sp0_o;  // Scratchpad0 R channel
    r_channel_t  r_sp1_o;  // Scratchpad1 R channel
    r_channel_t  r_d_o;    // D$ R channel
    r_channel_t  r_i_o;    // I$ R channel
    aw_channel_t aw_sp0_i; // Scratchpad0 AW channel
    aw_channel_t aw_sp1_i; // Scratchpad1 AW channel
    aw_channel_t aw_d_i;   // D$ AW channel
    aw_channel_t aw_o;     // Controller AW channel
    w_channel_t  w_sp0_i;  // Scratchpad0 W channel
    w_channel_t  w_sp1_i;  // Scratchpad1 W channel
    w_channel_t  w_d_i;    // D$ W channel
    w_channel_t  w_o;      // Controller W channel
    b_channel_t  b_i;      // Controller B channel
    b_channel_t  b_sp0_o;  // Scratchpad0 B channel
    b_channel_t  b_sp1_o;  // Scratchpad1 B channel
    b_channel_t  b_d_o;    // D$ B channel

    // read arbiter signals 
    logic sp0_req_r, sp1_req_r, d_req_r, i_req_r, skid_ready_r;
    logic [2:0] ar_grant;

    // write arbiter signals
    logic sp0_req_w, sp1_req_w, d_req_w, skid_ready_w;
    logic [2:0] aw_grant;

    // MASTER <=> SP0 AR MANAGER
    modport ar_sp0_manager (
        // From Master 
        input ar_sp0_i.valid, ar_sp0_i.addr, ar_sp0_i.id, ar_sp0_i.size, ar_sp0_i.len, ar_sp0_i.burst,

        // To Master 
        output ar_sp0_i.ready
    );

    // MASTER <=> SP1 AR MANAGER
    modport ar_sp1_manager (
        // From Master 
        input ar_sp1_i.valid, ar_sp1_i.addr, ar_sp1_i.id, ar_sp1_i.size, ar_sp1_i.len, ar_sp1_i.burst,

        // To Master 
        output ar_sp1_i.ready
    );

    // MASTER <=> D$ AR MANAGER
    modport ar_d_manager (
        // From Master 
        input ar_d_i.valid, ar_d_i.addr, ar_d_i.id, ar_d_i.size, ar_d_i.len, ar_d_i.burst,

        // To Master 
        output ar_d_i.ready
    );

    // MASTER <=> D$ AR MANAGER
    modport ar_i_manager (
        // From Master 
        input ar_i_i.valid, ar_i_i.addr, ar_i_i.id, ar_i_i.size, ar_i_i.len, ar_i_i.burst,

        // To Master 
        output ar_i_i.ready
    );

    // DRAM CONTROLLER <=> READ SKID BUFFER
    modport ar_to_subordinate (
        // To Subordinate
        output ar_o.valid, ar_o.addr, ar_o.mid_id, ar_o.size, ar_o.len, ar_o.burst,

        // From Subordinate
        input ar_o.ready

    );

    // DRAM CONTROLLER <=> READ RESPONSE ROUTER
    modport subordinate_to_r (
        // To Subordinate
        output r_i.ready, 

        // From Subordinate
        input r_i.valid, r_i.data, r_i.mid_id, r_i.last, r_i.resp
    );

    // DRAM CONTROLLER <=> WRITE SKID BUFFER
    modport aw_to_subordinate (
        // To Subordinate
        output aw_o.valid, aw_o.addr, aw_o.mid_id, aw_o.size, aw_o.len, aw_o.burst,

        // From Subordinate
        input aw_o.ready
    );

    // DRAM CONTROLLER <=> WRITE SKID BUFFER
    modport w_to_subordinate (
        // To Subordinate
        output w_o.valid, w_o.data, w_o.mid_id, w_o.last, w_o.strb,

        // From Subordinate
        input w_o.ready
    );

    // DRAM CONTROLLER <=> WRITE RESPONSE ROUTER
    modport subordinate_to_b (
        // To Subordinate
        output b_i.ready,

        // From Subordinate
        input b_i.valid, b_i.mid_id, b_i.resp
    );

    // AR MANAGERS <=> READ ARBITER
    modport read_arbiter (
        // From Manager
        input sp0_req, sp1_req, d_req, i_req,

        // From Skid Buffer
        input skid_ready,

        // To Read Mux/AR Manager 
        output ar_grant
    );

    // AW QUEUE <=> AW ARBITER
    modport aw_arb (
        input aw_req, aw_o.ready,
        output aw_grant
    );

endinterface
`endif // AXI_BUS_IF_VH