/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_manager #(
    parameter logic [MID-1:0] MASTER_ID = '0
)(
    input logic                 CLK,
    input logic                 nRST,
    axi_bus_if.write_manager    wrmgr_if
    // From Master AW channel
    // input logic                 awvalid,
    // input logic [AWID-1:0]      awid,
    // input logic [AWADDR-1:0]    awaddr,
    // input logic [AWLEN-1:0]     awlen, 
    // input logic [AWSIZE-1:0]    awsize,
    // input logic [AWBURST-1:0]   awburst,
    // // To Master AW channel
    // output logic                awready,
    // // From Master W channel
    // input logic                 wvalid,
    // input logic [WID-1:0]       wid,
    // input logic [WDATA-1:0]     wdata,
    // input logic [WSTRB-1:0]     wstrb,
    // input logic                 wlast,
    // // To Master W channel
    // output logic                wready,
    // // From Write controller
    // input logic                 aw_pop,
    // input logic                 w_pop,
    // // To AW Mux
    // output logic                head_awvalid,
    // output logic [AWADDR-1:0]   head_addr,
    // output logic [MID_AWID-1:0] head_awid,
    // output logic [AWLEN-1:0]    head_len,
    // output logic [AWSIZE-1:0]   head_size,
    // output logic [AWBURST-1:0]  head_burst,
    // // To W Mux
    // output logic                head_wvalid,
    // output logic [MID_WID-1:0]  head_wid,
    // output logic [WDATA-1:0]    head_data,
    // output logic [WSTRB-1:0]    head_strb,
    // output logic                head_last
);

// initializing both fifo structrues 
aw_payload_t aw_fifo [0:AW_DEPTH-1];
w_payload_t  w_fifo [0:W_DEPTH-1];

// initializing both wr and rd ptrs for fifo structure
logic [AW_PTR_WIDTH-1:0] aw_wr_ptr, aw_rd_ptr;
logic [W_PTR_WIDTH-1 :0] w_wr_ptr,  w_rd_ptr;

// initializing fifo based signals
logic aw_full, aw_empty;
logic w_full,  w_empty;
logic aw_push;
logic w_push;

// logic to determine if fifo is empty or full
assign aw_full = (aw_wr_ptr + 1'b1 == aw_rd_ptr);
assign aw_empty = (aw_wr_ptr == aw_rd_ptr);
assign w_full = (w_wr_ptr + 1'b1 == w_rd_ptr);
assign w_empty = (w_wr_ptr == w_rd_ptr);

// logic to enable ready signal for handshake
assign wrmgr_if.awready = (!aw_full);
assign wrmgr_if.wready = (!w_full);

// valid ready handshake
assign aw_push = (wrmgr_if.awvalid && wrmgr_if.awready);
assign w_push  = (wrmgr_if.wvalid && wrmgr_if.wready);

// aw write 
always_ff@(posedge CLK, negedge nRST) begin 
    if(!nRST) begin 
        aw_wr_ptr <= '0;
    end 
    else begin 
        if(aw_push) begin
            aw_fifo[aw_wr_ptr].valid  <= wrmgr_if.awvalid;
            aw_fifo[aw_wr_ptr].addr   <= wrmgr_if.aw_gen_i.addr;
            aw_fifo[aw_wr_ptr].mid_id <= {MASTER_ID, wrmgr_if.aw_gen_i.id};
            aw_fifo[aw_wr_ptr].size   <= wrmgr_if.aw_gen_i.size;
            aw_fifo[aw_wr_ptr].len    <= wrmgr_if.aw_gen_i.len;
            aw_fifo[aw_wr_ptr].burst  <= wrmgr_if.aw_gen_i.burst;
        end 
    end 
end

// aw read
always_ff@(posedge CLK, negedge nRST) begin
    if(!nRST) begin 
        aw_rd_ptr <= '0;
    end
    else begin 
        if (!aw_empty && wrmgr_if.aw_pop) begin 
            aw_rd_ptr <= aw_rd_ptr + 1;
        end 
    end 
end 

// w write
always_ff@(posedge CLK, negedge nRST) begin 
    if(!nRST) begin 
        w_wr_ptr <= '0;
    end 
    else begin 
        if(w_push) begin
            w_fifo[w_wr_ptr].valid  <= wrmgr_if.wvalid;
            w_fifo[w_wr_ptr].mid_id <= {MASTER_ID, wrmgr_if.w_gen_i.id};
            w_fifo[w_wr_ptr].data   <= wrmgr_if.w_gen_i.data;
            w_fifo[w_wr_ptr].last   <= wrmgr_if.w_gen_i.last;
            w_fifo[w_wr_ptr].strb   <= wrmgr_if.w_gen_i.strb;
        end 
    end 
end

// w read
always_ff@(posedge CLK, negedge nRST) begin
    if(!nRST) begin 
        w_rd_ptr <= '0;
    end
    else begin 
        if (!w_empty && wrmgr_if.w_pop) begin 
            w_rd_ptr <= w_rd_ptr + 1;
        end 
    end 
end 

// aw outputs 
assign wrmgr_if.head_awvalid     = aw_fifo[aw_rd_ptr].valid;
assign wrmgr_if.head_aw_o.addr   = aw_fifo[aw_rd_ptr].addr;
assign wrmgr_if.head_aw_o.mid_id = aw_fifo[aw_rd_ptr].mid_id;
assign wrmgr_if.head_aw_o.size   = aw_fifo[aw_rd_ptr].size;
assign wrmgr_if.head_aw_o.len    = aw_fifo[aw_rd_ptr].len;
assign wrmgr_if.head_aw_o.burst  = aw_fifo[aw_rd_ptr].burst;

// w outputs 
assign wrmgr_if.head_wvalid     = w_fifo[w_rd_ptr].valid;
assign wrmgr_if.head_w_o.mid_id = w_fifo[w_rd_ptr].mid_id;
assign wrmgr_if.head_w_o.data   = w_fifo[w_rd_ptr].data;
assign wrmgr_if.head_w_o.strb   = w_fifo[w_rd_ptr].strb;
assign wrmgr_if.head_w_o.last   = w_fifo[w_rd_ptr].last;

endmodule