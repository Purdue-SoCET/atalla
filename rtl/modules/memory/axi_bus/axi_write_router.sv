/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_router (
    input logic CLK,
    input logic nRST,
    axi_bus_if.subordinate_to_b b_i_if,
    axi_bus_if.b_to_sp0         sp0_b_o_if,
    axi_bus_if.b_to_sp1         sp1_b_o_if,
    axi_bus_if.b_to_d           d_b_o_if
);

    // define skid buffers
    b_payload_t sp0_skid_buffer [0:WRR_DEPTH-1];
    b_payload_t sp1_skid_buffer [0:WRR_DEPTH-1];
    b_payload_t d_skid_buffer   [0:WRR_DEPTH-1];

    // define both wr and rd ptrs for skid buffers
    logic [WRR_PTR_WIDTH-1:0] sp0_wr_ptr, sp0_rd_ptr;
    logic [WRR_PTR_WIDTH-1:0] sp1_wr_ptr, sp1_rd_ptr;
    logic [WRR_PTR_WIDTH-1:0] d_wr_ptr, d_rd_ptr;

    // logic to determine sp0 skid buffer full or empty
    logic sp0_skid_full, sp0_skid_empty;
    assign sp0_skid_full = (sp0_wr_ptr + 1'b1 == sp0_rd_ptr);
    assign sp0_skid_empty = (sp0_wr_ptr == sp0_rd_ptr);

    // logic to determine sp1 skid buffer full or empty
    logic sp1_skid_full, sp1_skid_empty;
    assign sp1_skid_full = (sp1_wr_ptr + 1'b1 == sp1_rd_ptr);
    assign sp1_skid_empty = (sp1_wr_ptr == sp1_rd_ptr);

    // logic to determine d$ skid buffer full or empty 
    logic d_skid_full, d_skid_empty;
    assign d_skid_full = (d_wr_ptr + 1'b1 == d_rd_ptr);
    assign d_skid_empty = (d_wr_ptr == d_rd_ptr);

    // logic to set ready to the subordiante for valid ready handshake (checks mid bits and specific skid buffer to set ready)
    always_comb begin 
        b_i_if.b_i_ready = 0;
        if ((b_i_if.b_i.id[MID_BID-1:BID] == SP0) && !(sp0_skid_full)) begin 
            b_i_if.b_i_ready = 1;
        end
        else if ((b_i_if.b_i.id[MID_BID-1:BID] == SP1) && !(sp1_skid_full)) begin 
            b_i_if.b_i_ready = 1;
        end
        else if ((b_i_if.b_i.id[MID_BID-1:BID] == DCACHE) && !(d_skid_full)) begin 
            b_i_if.b_i_ready = 1;
        end
    end 

    // valid ready handshake to and from subordinate
    assign skid_push = (b_i_if.b_i_valid && b_i_if.b_i_ready);

    // subordinate mux and write into skid buffer
    always_ff @(posedge CLK, negedge nRST) begin 
        if (!nRST) begin 
            sp0_wr_ptr <= '0;
            sp1_wr_ptr <= '0;
            d_wr_ptr <= '0;
        end 
        else begin
            if(skid_push) begin 
                // drive response to sp0
                if (b_i_if.b_i.id[MID_BID-1:BID] == SP0) begin 
                    sp0_skid_buffer[sp0_wr_ptr].valid <= b_i_if.b_i_valid;
                    sp0_skid_buffer[sp0_wr_ptr].id    <= b_i_if.b_i.id[BID-1:0];
                    sp0_skid_buffer[sp0_wr_ptr].resp  <= b_i_if.b_i.resp;
                    sp0_wr_ptr <= sp0_wr_ptr + 1'b1;
                end 
                // drive response to sp1
                else if (b_i_if.b_i.id[MID_BID-1:BID] == SP1) begin 
                    sp1_skid_buffer[sp1_wr_ptr].valid <= b_i_if.b_i_valid;
                    sp1_skid_buffer[sp1_wr_ptr].id    <= b_i_if.b_i.id[BID-1:0];
                    sp1_skid_buffer[sp1_wr_ptr].resp  <= b_i_if.b_i.resp;
                    sp1_wr_ptr <= sp1_wr_ptr + 1'b1;
                end 
                // drive response to d$
                else if (b_i_if.b_i.id[MID_BID-1:BID] == DCACHE) begin
                    d_skid_buffer[d_wr_ptr].valid <= b_i_if.b_i_valid;
                    d_skid_buffer[d_wr_ptr].id    <= b_i_if.b_i.id[BID-1:0];
                    d_skid_buffer[d_wr_ptr].resp  <= b_i_if.b_i.resp;
                    d_wr_ptr <= d_wr_ptr + 1'b1;
                end
            end 
        end 
    end


    always_ff @(posedge CLK, negedge nRST) begin 
        if(!nRST) begin 
            sp0_rd_ptr <= '0;
            sp1_rd_ptr <= '0;
            d_rd_ptr <= '0;
        end
        else begin 
            if (!sp0_skid_empty && sp0_b_o_if.b_sp0_o_ready) begin
                sp0_skid_buffer[sp0_rd_ptr].valid <= 1'b0;
                sp0_rd_ptr <= sp0_rd_ptr + 1'b1;
            end 
            else if (!sp1_skid_empty && sp1_b_o_if.b_sp1_o_ready) begin 
                sp1_skid_buffer[sp1_rd_ptr].valid <= 1'b0;
                sp1_rd_ptr <= sp1_rd_ptr + 1'b1;
            end 
            else if (!sp1_skid_empty && d_b_o_if.b_d_o_ready) begin 
                d_skid_buffer[d_rd_ptr].valid <= 1'b0;
                d_rd_ptr <= d_rd_ptr + 1'b1;
            end 
        end 
    end

    // b channel to sp0 
    assign sp0_b_o_if.b_sp0_o_valid = sp0_skid_buffer[sp0_rd_ptr].valid;
    assign sp0_b_o_if.b_sp0_o.id    = sp0_skid_buffer[sp0_rd_ptr].id;
    assign sp0_b_o_if.b_sp0_o.resp  = sp0_skid_buffer[sp0_rd_ptr].resp;

    // b channel to sp1
    assign sp1_b_o_if.b_sp1_o_valid = sp1_skid_buffer[sp1_rd_ptr].valid;
    assign sp1_b_o_if.b_sp1_o.id    = sp1_skid_buffer[sp1_rd_ptr].id;
    assign sp0_b_o_if.b_sp1_o.resp  = sp1_skid_buffer[sp1_rd_ptr].resp;
    
    // b channel to d$ 
    assign d_b_o_if.b_d_o_valid   = d_skid_buffer[d_rd_ptr].valid;
    assign d_b_o_if.b_d_o.id      = d_skid_buffer[d_rd_ptr].id;
    assign d_b_o_if.b_d_o.resp    = d_skid_buffer[d_rd_ptr].resp;
    
endmodule