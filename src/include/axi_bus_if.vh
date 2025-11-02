/*  Aryan Kadakia - kadakia0@purdue.edu */

`ifndef AXI_BUS_IF_VH
`define AXI_BUS_IF_VH

`include "axi_bus_pkg.vh"

interface address_mapper_if;
    // import types 
    import axi_bus_pkg::*;

    // channel structs 
    ar_channel_t ar_i;
    ar_channel_t ar_o; 
    r_channel_t  r_i;
    r_channel_t  r_o;
    aw_channel_t aw_i;
    aw_channel_t aw_o;
    w_channel_t  w_i;
    w_channel_t  w_o;
    b_channel_t  b_i;
    b_channel_t  b_o;

    // read arbiter signals 
    logic [2:0] ar_req;
    logic [2:0] ar_grant;

    // write arbiter signals
    logic [2:0] aw_req;
    logic [2:0] aw_grant;

    // MASTER (I$, D$, SP) <=> AR QUEUE <=> SUBORDINATE (Controller)
    modport ar_queue (
        // From Master 
        input ar_i.valid, ar_i.addr, ar_i.id, ar_i.size, ar_i.len, ar_i.burst,

        // To Master 
        output ar_i.ready,

        // From Arbiter
        input ar_grant, 

        // To Arbiter 
        output ar_req,

        // To Subordinate 
        output ar_o.valid, ar_o.addr, ar_o.mid_id, ar_o.size, ar_o.len, ar_o.burst
    );

    // AR QUEUE <=> AR ARBITER
    modport ar_arb (
        input ar_req, ar_o.ready,
        output ar_grant
    );

    // MASTER (D$, SP) <=> AW QUEUE <=> SUBORDINATE (Controller)
    modport aw_queue (
        // From Master
        input aw_i.valid, aw_i.addr, aw_i.id, aw_i.size, aw_i.len, aw_i.burst,

        // To Master
        output aw_i.ready,

        // From Arbiter
        input aw_grant,

        // To Arbiter 
        output aw_req,

        // To Subordinate
        output aw_o.valid, aw_o.addr, aw_o.mid_id, aw_o.size, aw_o.len, aw_o.burst
    );

    // AW QUEUE <=> AW ARBITER
    modport aw_arb (
        input aw_req, aw_o.ready,
        output aw_grant
    );

    // MASTER (D$, SP) <=> W QUEUE <=> SUBORDINATE (Controller)
    modport w_queue (
        // From Master
        input w_i.valid, w_i.data, w_i.id, w_i.last, w_i.strb,
        output w_i.ready,
        
        // To Subordiante
        output w_o.valid, w_o.data, w_o.mid_id, w_o.last, w_o.strb
    );
    
    // SUBORDINATE <=> READ RESPONSE ROUTER <=> MASTER
    modport rresp_router (
        // From Subordinate
        input r_i.valid, r_i.data, r_i.mid_id, r_i.resp, r_i.last,
        output r_i.ready,
        
        // To Masters
        input r_o.ready,
        output r_o.valid, r_o.data, r_o.id, r_o.resp, r_o.last
    );

    // SUBORDINATE <=> WRITE RESPONSE ROUTER <=> MASTER
    modport wresp_router (
        // From subordinate 
        input b_i.valid, b_i.mid_id, b_i.resp, 
        output b_i.ready,
        
        // To masters 
        input b_o.ready,
        output b_o.valid, b_o.id, b_o.resp
    );

endinterface
`endif // AXI_BUS_IF_VH