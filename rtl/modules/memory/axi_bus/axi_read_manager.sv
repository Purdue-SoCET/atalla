/*  
    Aryan Kadakia - kadakia0@purdue.edu
    Xinyu Liu - liuxinyujames@gmail.com
*/
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;

module axi_read_manager #(
    parameter logic [MID-1:0] MASTER_ID = 1
)(
    input logic                 CLK,
    input logic                 nRST,
    // From Master
    input logic                 arvalid, // master ready to send read request
    input master_ar_channel_t   master_in,
    // To Master
    output logic                arready, // manager valid to take signal
    // From Read Controller
    input  logic                pop, // AR channel ready to take 
    // To Read Mux
    output sub_ar_channel_t     manager_out,
    output logic req
);

sub_ar_channel_t fifo [AR_DEPTH];
logic wrap_table [AR_DEPTH];
logic [AR_PTR_WIDTH:0] wr_ptr, rd_ptr; // wr -> write in fifo; rd -> read from fifo

logic full, empty;
assign full  = (wr_ptr[AR_PTR_WIDTH-1:0] == rd_ptr[AR_PTR_WIDTH-1:0]) && (wr_ptr[AR_PTR_WIDTH] != rd_ptr[AR_PTR_WIDTH]);
assign empty = (wr_ptr[AR_PTR_WIDTH-1:0] == rd_ptr[AR_PTR_WIDTH-1:0]) && (wr_ptr[AR_PTR_WIDTH] == rd_ptr[AR_PTR_WIDTH]);

logic push;
assign arready = !full;
assign push = (arvalid & arready); 

// input from master
always_ff @ ( posedge CLK, negedge nRST ) begin
    if(!nRST) begin 
        wr_ptr <= '0;

        for (integer i=0; i<AR_DEPTH; i++) fifo[i] <= '0;
        
    end else begin
        if(push && !full) begin 
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].valid  <= 1'b1;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].addr <= master_in.addr;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].mid <= MASTER_ID;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].id <= master_in.id;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].size <= master_in.size;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].len <= master_in.len;
            fifo[wr_ptr[AR_PTR_WIDTH-1:0]].burst <= master_in.burst;
            wr_ptr <= wr_ptr + 1;
        end
    end 
end

// output to ar mux
always_ff @ ( posedge CLK, negedge nRST ) begin
    if(!nRST) begin 
        rd_ptr <= '0;
    end else begin
        if(!empty && pop) begin 
            rd_ptr <= rd_ptr + 1;
        end  
    end
end 

// output signal connection
assign manager_out = fifo[rd_ptr[AR_PTR_WIDTH-1:0]];
assign req = !empty;

endmodule