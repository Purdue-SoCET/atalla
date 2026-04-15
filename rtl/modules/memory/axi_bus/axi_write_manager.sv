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
    //axi_bus_if.write_manager    wrmgr_if
    // From Master AW channel
    input logic                 awvalid,
    input logic [AWID-1:0]      awid,
    input logic [AWADDR-1:0]    awaddr,
    input logic [AWLEN-1:0]     awlen, 
    input logic [AWSIZE-1:0]    awsize,
    input logic [AWBURST-1:0]   awburst,
    // To Master AW channel
    //output logic                awready,
    // From Master W channel
    input logic                 wvalid,
    input logic [WID-1:0]       wid,
    input logic [WDATA-1:0]     wdata,
    input logic [WSTRB-1:0]     wstrb,
    input logic                 wlast,
    // To Master W channel
    //output logic                wready,
    // From Write controller
    input logic                 aw_pop,
    input logic                 w_pop,
    // To AW Mux
    output logic                head_awvalid,
    output logic [AWADDR-1:0]   head_addr,
    output logic [MID_AWID-1:0] head_awid,
    output logic [AWLEN-1:0]    head_len,
    output logic [AWSIZE-1:0]   head_size,
    output logic [AWBURST-1:0]  head_burst,
    // To W Mux
    output logic                head_wvalid,
    output logic [MID_WID-1:0]  head_wid,
    output logic [WDATA-1:0]    head_data,
    output logic [WSTRB-1:0]    head_strb,
    output logic                head_last,
    // to actual manager unit (single ready)
    output logic                wr_ready
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
logic [W_PTR_WIDTH-1:0] w_count;

// logic to count the number of available w slots and send out fifo
assign w_count = (w_wr_ptr >= w_rd_ptr) ? w_wr_ptr - w_rd_ptr : W_DEPTH - (w_rd_ptr - w_wr_ptr);
assign wr_ready = (!aw_full && (((W_DEPTH-1) - w_count) >= 8));

// logic to determine if fifo is empty or full
assign aw_full = (aw_wr_ptr + 1'b1 == aw_rd_ptr);
assign aw_empty = (aw_wr_ptr == aw_rd_ptr);
assign w_full = (w_wr_ptr + 1'b1 == w_rd_ptr);
assign w_empty = (w_wr_ptr == w_rd_ptr);

// logic to enable ready signal for handshake
logic awready, wready;
assign awready = (!aw_full);
assign wready = (!w_full);

// valid ready handshake
assign aw_push = (awvalid && awready);
assign w_push  = (wvalid && wready);

// aw write 
always_ff@(posedge CLK, negedge nRST) begin 
    if(!nRST) begin 
        aw_wr_ptr <= '0;
        aw_rd_ptr <= '0;
        for (int i = 0; i < AW_DEPTH; i++) begin 
            aw_fifo[i].valid <= 1'b0; // this could be a bug ?? only valid should be cleared  (update fixed but needs tested)
        end 
    end 
    else begin 
        if(aw_push) begin
            assert(awvalid == awready)
                else $error("valid or ready not high");
            aw_fifo[aw_wr_ptr].valid  <= awvalid;
            aw_fifo[aw_wr_ptr].addr   <= awaddr;
            aw_fifo[aw_wr_ptr].mid_id <= {MASTER_ID, awid};
            aw_fifo[aw_wr_ptr].size   <= awsize;
            aw_fifo[aw_wr_ptr].len    <= awlen;
            aw_fifo[aw_wr_ptr].burst  <= awburst;
            aw_wr_ptr <= aw_wr_ptr + 1'b1;
        end 
        if (!aw_empty && aw_pop) begin 
            aw_fifo[aw_rd_ptr].valid <= 1'b0;
            aw_rd_ptr <= aw_rd_ptr + 1;
        end 
    end 
end

// w write or w read
always_ff@(posedge CLK, negedge nRST) begin 
    if(!nRST) begin 
        w_wr_ptr <= '0;
        w_rd_ptr <= '0;
        for (int i = 0; i < W_DEPTH; i++) begin
            w_fifo[i].valid <= 1'b0;
        end
    end 
    else begin 
        if(w_push) begin
            assert(wvalid == wready)
                else $error("w ready or valid not high");
            w_fifo[w_wr_ptr].valid  <= wvalid;
            w_fifo[w_wr_ptr].mid_id <= {MASTER_ID, wid};
            w_fifo[w_wr_ptr].data   <= wdata;
            w_fifo[w_wr_ptr].last   <= wlast;
            w_fifo[w_wr_ptr].strb   <= wstrb;
            w_wr_ptr <= w_wr_ptr + 1'b1;
        end 
        if (!w_empty && w_pop) begin 
            w_fifo[w_rd_ptr].valid <= 1'b0;
            w_rd_ptr <= w_rd_ptr + 1;
        end 
    end 
end

// aw outputs 
assign head_awvalid = aw_fifo[aw_rd_ptr].valid;
assign head_addr    = aw_fifo[aw_rd_ptr].addr;
assign head_awid    = aw_fifo[aw_rd_ptr].mid_id;
assign head_size    = aw_fifo[aw_rd_ptr].size;
assign head_len     = aw_fifo[aw_rd_ptr].len;
assign head_burst   = aw_fifo[aw_rd_ptr].burst;

// w outputs 
assign head_wvalid = w_fifo[w_rd_ptr].valid;
assign head_wid    = w_fifo[w_rd_ptr].mid_id;
assign head_data   = w_fifo[w_rd_ptr].data;
assign head_strb   = w_fifo[w_rd_ptr].strb;
assign head_last   = w_fifo[w_rd_ptr].last;

// property aw_wrt_pointer;
//     @(posedge CLK)
//     awvalid && awready |=> (aw_wr_ptr == ($past(aw_wr_ptr) + 1'b1));
// endproperty

// assert property (aw_wrt_pointer)
//     else $error("aw write pointer did not increment");

// property w_wrt_pointer;
//     @(posedge CLK)
//     wvalid && wready |=> (w_wr_ptr == ($past(w_wr_ptr) + 1'b1));
// endproperty

// assert property (w_wrt_pointer)
//     else $error("w write pointer did not increment");



endmodule