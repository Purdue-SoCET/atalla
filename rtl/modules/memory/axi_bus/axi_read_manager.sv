/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;

module axi_read_manager #(
    parameter logic [MID-1:0] MASTER_ID = '0
)(
    input logic                 CLK,
    input logic                 nRST,
    // From Master
    input logic                 arvalid,
    input logic [ARID-1:0]      arid,
    input logic [ARADDR-1 :0]   araddr,
    input logic [ARLEN-1  :0]   arlen,
    input logic [ARSIZE-1 :0]   arsize,
    input logic [ARBURST-1:0]   arburst,
    // To Master
    output logic                aready,
    // From Read Controller
    input  logic                pop, 
    // To Read Mux
    output logic                head_valid,
    output logic [ARADDR-1 :0]  head_addr,
    output logic [MID_ARID-1:0] head_id,
    output logic [ARSIZE-1 :0]  head_size,
    output logic [ARLEN-1  :0]  head_len,
    output logic [ARBURST-1:0]  head_burst
);

ar_payload_t fifo [0:AR_DEPTH-1];
logic [AR_PTR_WIDTH-1:0] wr_ptr, rd_ptr;

logic full, empty;
assign full  = (wr_ptr + 1'b1 == rd_ptr);
assign empty = (wr_ptr == rd_ptr);

logic push;
assign push = (arvalid & aready); 

always_ff@(posedge CLK, negedge nRST) begin
    if(!nRST) begin 
        wr_ptr <= '0;
    end else begin
        if(push && !full) begin 
            fifo[wr_ptr].valid  <= 1'b1;
            fifo[wr_ptr].addr   <= araddr;
            fifo[wr_ptr].mid_id <= {MASTER_ID, arid};
            fifo[wr_ptr].size   <= arsize;
            fifo[wr_ptr].len    <= arlen;
            fifo[wr_ptr].burst  <= arburst;
            wr_ptr <= wr_ptr + 1;
        end
    end 
end

always_ff@(posedge CLK, negedge nRST) begin
    if(!nRST) begin 
        rd_ptr <= '0;
    end else begin
        if(!empty && pop) begin 
            rd_ptr <= rd_ptr + 1;
        end  
    end
end 

assign aready = !full;

assign head_valid = !empty;
assign head_addr  = fifo[rd_ptr].addr;
assign head_id    = fifo[rd_ptr].mid_id;
assign head_size  = fifo[rd_ptr].size;
assign head_len   = fifo[rd_ptr].len;
assign head_burst = fifo[rd_ptr].burst;

endmodule