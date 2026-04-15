/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_top(
    input logic CLK,
    input logic nRST,
    axi_bus_if.write_path wr_path_if
);

    // LOCAL INTERFACE INSTANCE 
    axi_bus_if arb_if(CLK, nRST);
    axi_bus_if drv_if(CLK, nRST);
    axi_bus_if b_if(CLK, nRST);

    // SCRATCHPAD0 (SP0) WRITE MANAGER INTERMEDIATE SIGNALS
    logic head_sp0_awvalid, head_sp0_wvalid, aw_sp0_pop, w_sp0_pop;
    sub_aw_channel_t head_sp0_aw;
    sub_w_channel_t  head_sp0_w;

    // SCRATCHPAD1 (SP1) WRITE MANAGER INTERMEDIATE SIGNALS
    logic head_sp1_awvalid, head_sp1_wvalid, aw_sp1_pop, w_sp1_pop;
    sub_aw_channel_t head_sp1_aw;
    sub_w_channel_t  head_sp1_w;

    // DCACHE WRITE MANAGER INTERMEDIATE SIGNALS
    logic head_d_awvalid, head_d_wvalid, aw_d_pop, w_d_pop;
    sub_aw_channel_t head_d_aw;
    sub_w_channel_t  head_d_w;

    // logic regarding single ready/valid to actual master
    logic sp0_in_burst;
    logic sp1_in_burst;
    logic d_in_burst;
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            sp0_in_burst <= 1'b0;
        end else begin
            // start of a new burst
            if (!sp0_in_burst && wr_path_if.sp0_i_valid && wr_path_if.sp0_wr_ready) begin
                if (!wr_path_if.w_sp0_i.last)
                    sp0_in_burst <= 1'b1;
            end
            // end of current burst
            else if (sp0_in_burst && wr_path_if.w_sp0_i.last) begin
                sp0_in_burst <= 1'b0;
            end
        end
    end
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            sp1_in_burst <= 1'b0;
        end else begin
            // start of a new burst
            if (!sp1_in_burst && wr_path_if.sp1_i_valid && wr_path_if.sp1_wr_ready) begin
                if (!wr_path_if.w_sp1_i.last)
                    sp1_in_burst <= 1'b1;
            end
            // end of current burst
            else if (sp1_in_burst && wr_path_if.w_sp1_i.last) begin
                sp1_in_burst <= 1'b0;
            end
        end
    end
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            d_in_burst <= 1'b0;
        end else begin
            // start of a new burst
            if (!d_in_burst && wr_path_if.d_i_valid && wr_path_if.d_wr_ready) begin
                if (!wr_path_if.w_d_i.last)
                    d_in_burst <= 1'b1;
            end
            // end of current burst
            else if (d_in_burst && wr_path_if.w_d_i.last) begin
                d_in_burst <= 1'b0;
            end
        end
    end

    logic sp0_mgr_awvalid, sp1_mgr_awvalid, d_mgr_awvalid;
    logic sp0_mgr_wvalid,  sp1_mgr_wvalid, d_mgr_wvalid;

    assign sp0_mgr_awvalid = wr_path_if.sp0_i_valid && !sp0_in_burst;
    assign sp0_mgr_wvalid  = wr_path_if.sp0_i_valid || sp0_in_burst;
    assign sp1_mgr_awvalid = wr_path_if.sp1_i_valid && !sp1_in_burst;
    assign sp1_mgr_wvalid  = wr_path_if.sp1_i_valid || sp1_in_burst;
    assign d_mgr_awvalid   = wr_path_if.d_i_valid && !d_in_burst;
    assign d_mgr_wvalid    = wr_path_if.d_i_valid || d_in_burst;

    // SCRATCHPAD0 (SP0) WRITE MANAGER
    axi_write_manager #(
        .MASTER_ID(SP0)
    ) SP0_MGR ( 
        .CLK(CLK),
        .nRST(nRST),
        // From Master AW channel
        //.awvalid(wr_path_if.aw_sp0_i_valid),
        .awvalid(sp0_mgr_awvalid),
        .awid(wr_path_if.aw_sp0_i.id),
        .awaddr(wr_path_if.aw_sp0_i.addr),
        .awlen(wr_path_if.aw_sp0_i.len),
        .awsize(wr_path_if.aw_sp0_i.size),
        .awburst(wr_path_if.aw_sp0_i.burst),
        // To Master AW channel
        //.awready(wr_path_if.aw_sp0_i_ready),
        // From Master W channel
        .wvalid(sp0_mgr_wvalid),
        .wid(wr_path_if.w_sp0_i.id),
        .wdata(wr_path_if.w_sp0_i.data),
        .wstrb(wr_path_if.w_sp0_i.strb),
        .wlast(wr_path_if.w_sp0_i.last),
        // To Master W channel
        //.wready(wr_path_if.w_sp0_i_ready),
        // From Write Driver 
        .aw_pop(aw_sp0_pop),
        .w_pop(w_sp0_pop),
        // To AW Mux (Write Driver)
        .head_awvalid(head_sp0_awvalid),
        .head_addr(head_sp0_aw.addr),
        .head_awid(head_sp0_aw.mid_id),
        .head_len(head_sp0_aw.len),
        .head_size(head_sp0_aw.size),
        .head_burst(head_sp0_aw.burst),
        // To W Mux (Write Driver)
        .head_wvalid(head_sp0_wvalid),
        .head_wid(head_sp0_w.mid_id),
        .head_data(head_sp0_w.data),
        .head_strb(head_sp0_w.strb),
        .head_last(head_sp0_w.last),
        .wr_ready(wr_path_if.sp0_wr_ready)
    );

    // SCRATCHPAD1 (SP1) WRITE MANAGER
    axi_write_manager #(
        .MASTER_ID(SP1)
    ) SP1_MGR ( 
        .CLK(CLK),
        .nRST(nRST),
        // From Master AW channel
        .awvalid(sp1_mgr_awvalid),
        .awid(wr_path_if.aw_sp1_i.id),
        .awaddr(wr_path_if.aw_sp1_i.addr),
        .awlen(wr_path_if.aw_sp1_i.len),
        .awsize(wr_path_if.aw_sp1_i.size),
        .awburst(wr_path_if.aw_sp1_i.burst),
        // To Master AW channel
        //.awready(wr_path_if.aw_sp1_i_ready),
        // From Master W channel
        .wvalid(sp1_mgr_wvalid),
        .wid(wr_path_if.w_sp1_i.id),
        .wdata(wr_path_if.w_sp1_i.data),
        .wstrb(wr_path_if.w_sp1_i.strb),
        .wlast(wr_path_if.w_sp1_i.last),
        // To Master W channel
        //.wready(wr_path_if.w_sp1_i_ready),
        // From Write Driver 
        .aw_pop(aw_sp1_pop),
        .w_pop(w_sp1_pop),
        // To AW Mux (Write Driver)
        .head_awvalid(head_sp1_awvalid),
        .head_addr(head_sp1_aw.addr),
        .head_awid(head_sp1_aw.mid_id),
        .head_len(head_sp1_aw.len),
        .head_size(head_sp1_aw.size),
        .head_burst(head_sp1_aw.burst),
        // To W Mux (Write Driver)
        .head_wvalid(head_sp1_wvalid),
        .head_wid(head_sp1_w.mid_id),
        .head_data(head_sp1_w.data),
        .head_strb(head_sp1_w.strb),
        .head_last(head_sp1_w.last),
        .wr_ready(wr_path_if.sp1_wr_ready)
    );
    
    // DCACHE WRITE MANAGER
    axi_write_manager #(
        .MASTER_ID(DCACHE)
    ) DCACHE_MGR ( 
        .CLK(CLK),
        .nRST(nRST),
        // From Master AW channel
        .awvalid(d_mgr_awvalid),
        .awid(wr_path_if.aw_d_i.id),
        .awaddr(wr_path_if.aw_d_i.addr),
        .awlen(wr_path_if.aw_d_i.len),
        .awsize(wr_path_if.aw_d_i.size),
        .awburst(wr_path_if.aw_d_i.burst),
        // To Master AW channel
        //.awready(wr_path_if.aw_d_i_ready),
        // From Master W channel
        .wvalid(d_mgr_wvalid),
        .wid(wr_path_if.w_d_i.id),
        .wdata(wr_path_if.w_d_i.data),
        .wstrb(wr_path_if.w_d_i.strb),
        .wlast(wr_path_if.w_d_i.last),
        // To Master W channel
        //.wready(wr_path_if.w_d_i_ready),
        // From Write Driver 
        .aw_pop(aw_d_pop),
        .w_pop(w_d_pop),
        // To AW Mux (Write Driver)
        .head_awvalid(head_d_awvalid),
        .head_addr(head_d_aw.addr),
        .head_awid(head_d_aw.mid_id),
        .head_len(head_d_aw.len),
        .head_size(head_d_aw.size),
        .head_burst(head_d_aw.burst),
        // To W Mux (Write Driver)
        .head_wvalid(head_d_wvalid),
        .head_wid(head_d_w.mid_id),
        .head_data(head_d_w.data),
        .head_strb(head_d_w.strb),
        .head_last(head_d_w.last),
        .wr_ready(wr_path_if.d_wr_ready)
    );

    // WRITE ARBITER
    axi_write_arbiter WRITE_ARB (
        .CLK(CLK),
        .nRST(nRST),
        .arbw_if(arb_if)
    );

    // WRITE DRIVER 
    axi_write_driver WRITE_DRV (
        .CLK(CLK),
        .nRST(nRST),
        .wdrv_if(drv_if)
    );

    // WRITE ROUTER
    axi_write_router WRITE_ROUTER (
        .CLK(CLK),
        .nRST(nRST),
        .b_i_if    (b_if), // subordinate_to_b
        .sp0_b_o_if(b_if), // b_to_sp0
        .sp1_b_o_if(b_if), // b_to_sp1
        .d_b_o_if  (b_if)  // b_to_d
    );

    // SP0 MANAGER -> WRITE ARBITER
    assign arb_if.sp0_req_w = head_sp0_awvalid && head_sp0_wvalid;
    assign arb_if.sp0_len_w = head_sp0_aw.len;

    // SP1 MANAGER -> WRITE ARBITER
    assign arb_if.sp1_req_w = head_sp1_awvalid && head_sp1_wvalid;
    assign arb_if.sp1_len_w = head_sp1_aw.len;

    // D$ MANAGER -> WIRTE ARBITER
    assign arb_if.d_req_w = head_d_awvalid && head_d_wvalid;
    assign arb_if.d_len_w = head_d_aw.len;

    // WRITE ARBITER -> SP0 MANAGER
    assign aw_sp0_pop = arb_if.aw_sp0_pop;

    // WRITE ARBITER -> SP1 MANAGER
    assign aw_sp1_pop = arb_if.aw_sp1_pop;

    // WRITE ARBITER -> D$ MANAGER
    assign aw_d_pop = arb_if.aw_d_pop;

    // WRITE ARBITER -> WRITE DRIVER
    assign drv_if.aw_grant = arb_if.aw_grant;

    // WRITE DRIVER -> WRITE ARBITER
    assign arb_if.skid_ready_w = drv_if.skid_ready_w;
    assign arb_if.w_fire = drv_if.w_fire;

    // SP0 MANAGER -> WRITE DRIVER
    assign drv_if.head_sp0_awvalid = head_sp0_awvalid;
    assign drv_if.head_sp0_aw_o.addr = head_sp0_aw.addr;
    assign drv_if.head_sp0_aw_o.mid_id = head_sp0_aw.mid_id;
    assign drv_if.head_sp0_aw_o.len = head_sp0_aw.len;
    assign drv_if.head_sp0_aw_o.size = head_sp0_aw.size;
    assign drv_if.head_sp0_aw_o.burst = head_sp0_aw.burst;
    assign drv_if.head_sp0_wvalid = head_sp0_wvalid;
    assign drv_if.head_sp0_w_o.mid_id = head_sp0_w.mid_id;
    assign drv_if.head_sp0_w_o.data = head_sp0_w.data; 
    assign drv_if.head_sp0_w_o.strb = head_sp0_w.strb; 
    assign drv_if.head_sp0_w_o.last = head_sp0_w.last; 

    // SP1 MANAGER -> WRITE DRIVER
    assign drv_if.head_sp1_awvalid = head_sp1_awvalid;
    assign drv_if.head_sp1_aw_o.addr = head_sp1_aw.addr;
    assign drv_if.head_sp1_aw_o.mid_id = head_sp1_aw.mid_id;
    assign drv_if.head_sp1_aw_o.len = head_sp1_aw.len;
    assign drv_if.head_sp1_aw_o.size = head_sp1_aw.size;
    assign drv_if.head_sp1_aw_o.burst = head_sp1_aw.burst;
    assign drv_if.head_sp1_wvalid = head_sp1_wvalid;
    assign drv_if.head_sp1_w_o.mid_id = head_sp1_w.mid_id;
    assign drv_if.head_sp1_w_o.data = head_sp1_w.data; 
    assign drv_if.head_sp1_w_o.strb = head_sp1_w.strb; 
    assign drv_if.head_sp1_w_o.last = head_sp1_w.last; 

    // D$ MANAGER -> WRITE DRIVER
    assign drv_if.head_d_awvalid = head_d_awvalid;
    assign drv_if.head_d_aw_o.addr = head_d_aw.addr;
    assign drv_if.head_d_aw_o.mid_id = head_d_aw.mid_id;
    assign drv_if.head_d_aw_o.len = head_d_aw.len;
    assign drv_if.head_d_aw_o.size = head_d_aw.size;
    assign drv_if.head_d_aw_o.burst = head_d_aw.burst;
    assign drv_if.head_d_wvalid = head_d_wvalid;
    assign drv_if.head_d_w_o.mid_id = head_d_w.mid_id;
    assign drv_if.head_d_w_o.data = head_d_w.data; 
    assign drv_if.head_d_w_o.strb = head_d_w.strb; 
    assign drv_if.head_d_w_o.last = head_d_w.last; 

    // WRITE DRIVER -> SP0 MANAGER
    assign w_sp0_pop = drv_if.w_sp0_pop;

    // WRITE DRIVER -> SP1 MANAGER
    assign w_sp1_pop = drv_if.w_sp1_pop;

    // WRITE DRIVER -> D$ MANAGER
    assign w_d_pop = drv_if.w_d_pop;

    // WRITE DRIVER -> SUBORDINATE
    assign wr_path_if.aw_o_valid  = drv_if.aw_o_valid;
    assign wr_path_if.aw_o.addr   = drv_if.aw_o.addr;
    assign wr_path_if.aw_o.mid_id = drv_if.aw_o.mid_id;
    assign wr_path_if.aw_o.size   = drv_if.aw_o.size;
    assign wr_path_if.aw_o.len    = drv_if.aw_o.len;
    assign wr_path_if.aw_o.burst  = drv_if.aw_o.burst;

    assign wr_path_if.w_o_valid  = drv_if.w_o_valid;
    assign wr_path_if.w_o.mid_id = drv_if.w_o.mid_id;
    assign wr_path_if.w_o.data   = drv_if.w_o.data;
    assign wr_path_if.w_o.last   = drv_if.w_o.last;
    assign wr_path_if.w_o.strb   = drv_if.w_o.strb;

    // SUBORDINATE -> WRITE DRIVER
    assign drv_if.aw_o_ready = wr_path_if.aw_o_ready;
    assign drv_if.w_o_ready  = wr_path_if.w_o_ready;

    // SUBORDINATE -> WRITE ROUTER
    assign b_if.b_i_valid = wr_path_if.b_i_valid;
    assign b_if.b_i.id = wr_path_if.b_i.id;
    assign b_if.b_i.resp =wr_path_if.b_i.resp;

    // WRITE ROUTER -> SUBORDINATE 
    assign wr_path_if.b_i_ready = b_if.b_i_ready;

    // WRITE ROUTER -> SP0 MANAGER
    assign wr_path_if.b_sp0_o_valid = b_if.b_sp0_o_valid;
    assign wr_path_if.b_sp0_o.id = b_if.b_sp0_o.id;
    assign wr_path_if.b_sp0_o.resp =  b_if.b_sp0_o.resp;

    // SP0 MANAGER -> WRITE ROUTER
    assign b_if.b_sp0_o_ready = wr_path_if.b_sp0_o_ready;

    // WRITE ROUTER -> SP1 MANAGER
    assign wr_path_if.b_sp1_o_valid = b_if.b_sp1_o_valid;
    assign wr_path_if.b_sp1_o.id = b_if.b_sp1_o.id;
    assign wr_path_if.b_sp1_o.resp =  b_if.b_sp1_o.resp;

    // SP1 MANAGER -> WRITE ROUTER
    assign b_if.b_sp1_o_ready = wr_path_if.b_sp1_o_ready;

    // WRITE ROUTER -> D$ MANAGER
    assign wr_path_if.b_d_o_valid = b_if.b_d_o_valid;
    assign wr_path_if.b_d_o.id = b_if.b_d_o.id;
    assign wr_path_if.b_d_o.resp =  b_if.b_d_o.resp;

    // D$ MANAGER -> WRITE ROUTER
    assign b_if.b_d_o_ready = wr_path_if.b_d_o_ready;


endmodule