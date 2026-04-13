/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_driver(
    input logic CLK,
    input logic nRST,
    axi_bus_if.write_driver wdrv_if
);

    // Define AW and W skid Buffer
    aw_payload_t aw_skid_buffer [0:WDRV_DEPTH_AW-1];
    w_payload_t  w_skid_buffer  [0:WDRV_DEPTH_W-1];

    // Define AW and W pointers
    logic [WDRV_PTR_WIDTH_AW-1:0] aw_wr_ptr, aw_rd_ptr;
    logic [WDRV_PTR_WIDTH_W-1:0] w_wr_ptr, w_rd_ptr;

    // logic to determine of aw/w full or empty
    logic aw_skid_full, aw_skid_empty;
    logic w_skid_full, w_skid_empty;
    logic [WDRV_PTR_WIDTH_W-1:0] w_wr_ptr_next;
    assign aw_skid_full  = (aw_wr_ptr + 1'b1 == aw_rd_ptr);
    assign aw_skid_empty = (aw_wr_ptr == aw_rd_ptr);
    assign w_wr_ptr_next = (w_wr_ptr == WDRV_DEPTH_W-1) ? '0 : (w_wr_ptr + 1'b1); // to fix issue where w full not being detected 
    assign w_skid_full   = (w_wr_ptr_next == w_rd_ptr);
    assign w_skid_empty  = (w_wr_ptr == w_rd_ptr);

    logic aw_fire, aw_sent; // checks if aw request has been set so count down of beats can continue
    logic same_txn_sp0, same_txn_sp1, same_txn_d; // enforces aw + w in lockstep
    logic aw_loaded; // checks if aw request has been loaded into the skid buffer
    logic aw_load_this_cycle;
    assign aw_load_this_cycle =
        wdrv_if.aw_grant[MID] &&
        (
        ((wdrv_if.aw_grant[MID-1:0] == SP0)    && !aw_skid_full && !aw_loaded && wdrv_if.head_sp0_awvalid) ||
        ((wdrv_if.aw_grant[MID-1:0] == SP1)    && !aw_skid_full && !aw_loaded && wdrv_if.head_sp1_awvalid) ||
        ((wdrv_if.aw_grant[MID-1:0] == DCACHE) && !aw_skid_full && !aw_loaded && wdrv_if.head_d_awvalid)
    );

    always_ff@(posedge CLK, negedge nRST) begin 
        if(!nRST) begin
            aw_wr_ptr <= '0;
            w_wr_ptr <= '0;
            aw_rd_ptr <= '0;
            w_rd_ptr <= '0;
            // should we set valid bits low upon reset? look into this
            for (int i = 0; i < WDRV_DEPTH_AW; i++) begin 
                aw_skid_buffer[i].valid <= 1'b0;
            end
            for (int i = 0; i < WDRV_DEPTH_W; i++) begin 
                w_skid_buffer[i].valid <= 1'b0;
            end
            aw_loaded <= 1'b0;
        end 
        else begin 
            if (wdrv_if.aw_grant[MID]) begin // checking if aw_grant valid bit is high
                if (wdrv_if.aw_grant[MID-1:0] == SP0) begin
                    if(!aw_skid_full && !aw_sent && wdrv_if.head_sp0_awvalid && !aw_loaded) begin
                        aw_skid_buffer[aw_wr_ptr].valid  <= wdrv_if.head_sp0_awvalid;
                        aw_skid_buffer[aw_wr_ptr].addr   <= wdrv_if.head_sp0_aw_o.addr;
                        aw_skid_buffer[aw_wr_ptr].mid_id <= wdrv_if.head_sp0_aw_o.mid_id;
                        aw_skid_buffer[aw_wr_ptr].size   <= wdrv_if.head_sp0_aw_o.size;
                        aw_skid_buffer[aw_wr_ptr].len    <= wdrv_if.head_sp0_aw_o.len;
                        aw_skid_buffer[aw_wr_ptr].burst  <= wdrv_if.head_sp0_aw_o.burst;
                        aw_wr_ptr <= aw_wr_ptr + 1'b1;
                        aw_loaded <= 1'b1;
                    end
                    if(!w_skid_full && wdrv_if.head_sp0_wvalid && same_txn_sp0) begin
                        w_skid_buffer[w_wr_ptr].valid    <= wdrv_if.head_sp0_wvalid;
                        w_skid_buffer[w_wr_ptr].mid_id   <= wdrv_if.head_sp0_w_o.mid_id;
                        w_skid_buffer[w_wr_ptr].data     <= wdrv_if.head_sp0_w_o.data;
                        w_skid_buffer[w_wr_ptr].last     <= wdrv_if.head_sp0_w_o.last;
                        w_skid_buffer[w_wr_ptr].strb     <= wdrv_if.head_sp0_w_o.strb;
                        if (w_wr_ptr == WDRV_DEPTH_W-1) begin  
                            w_wr_ptr <= '0; // to fix bug where ptr counts up to 3 instead of doing 0->1->2->0
                        end 
                        else begin 
                            w_wr_ptr <= w_wr_ptr + 1'b1;
                        end
                    end 
                end
                else if (wdrv_if.aw_grant[MID-1:0] == SP1) begin
                    if (!aw_skid_full && !aw_sent && wdrv_if.head_sp1_awvalid && !aw_loaded) begin
                        aw_skid_buffer[aw_wr_ptr].valid  <= wdrv_if.head_sp1_awvalid;
                        aw_skid_buffer[aw_wr_ptr].addr   <= wdrv_if.head_sp1_aw_o.addr;
                        aw_skid_buffer[aw_wr_ptr].mid_id <= wdrv_if.head_sp1_aw_o.mid_id;
                        aw_skid_buffer[aw_wr_ptr].size   <= wdrv_if.head_sp1_aw_o.size;
                        aw_skid_buffer[aw_wr_ptr].len    <= wdrv_if.head_sp1_aw_o.len;
                        aw_skid_buffer[aw_wr_ptr].burst  <= wdrv_if.head_sp1_aw_o.burst;
                        aw_wr_ptr <= aw_wr_ptr + 1'b1;
                        aw_loaded <= 1'b1;
                    end
                    if (!w_skid_full && wdrv_if.head_sp1_wvalid && same_txn_sp1) begin
                        w_skid_buffer[w_wr_ptr].valid    <= wdrv_if.head_sp1_wvalid;
                        w_skid_buffer[w_wr_ptr].mid_id   <= wdrv_if.head_sp1_w_o.mid_id;
                        w_skid_buffer[w_wr_ptr].data     <= wdrv_if.head_sp1_w_o.data;
                        w_skid_buffer[w_wr_ptr].last     <= wdrv_if.head_sp1_w_o.last;
                        w_skid_buffer[w_wr_ptr].strb     <= wdrv_if.head_sp1_w_o.strb;
                        if (w_wr_ptr == WDRV_DEPTH_W-1) begin  
                            w_wr_ptr <= '0; // to fix bug where ptr counts up to 3 instead of doing 0->1->2->0
                        end 
                        else begin 
                            w_wr_ptr <= w_wr_ptr + 1'b1;
                        end
                    end 
                end
                else if (wdrv_if.aw_grant[MID-1:0] == DCACHE) begin
                    if(!aw_skid_full && !aw_sent && wdrv_if.head_d_awvalid && !aw_loaded) begin
                        aw_skid_buffer[aw_wr_ptr].valid  <= wdrv_if.head_d_awvalid;
                        aw_skid_buffer[aw_wr_ptr].addr   <= wdrv_if.head_d_aw_o.addr;
                        aw_skid_buffer[aw_wr_ptr].mid_id <= wdrv_if.head_d_aw_o.mid_id;
                        aw_skid_buffer[aw_wr_ptr].size   <= wdrv_if.head_d_aw_o.size;
                        aw_skid_buffer[aw_wr_ptr].len    <= wdrv_if.head_d_aw_o.len;
                        aw_skid_buffer[aw_wr_ptr].burst  <= wdrv_if.head_d_aw_o.burst;
                        aw_wr_ptr <= aw_wr_ptr + 1'b1;
                        aw_loaded <= 1'b1;
                    end 
                    if (!w_skid_full && wdrv_if.head_d_wvalid && same_txn_d) begin
                        w_skid_buffer[w_wr_ptr].valid    <= wdrv_if.head_d_wvalid;
                        w_skid_buffer[w_wr_ptr].mid_id   <= wdrv_if.head_d_w_o.mid_id;
                        w_skid_buffer[w_wr_ptr].data     <= wdrv_if.head_d_w_o.data;
                        w_skid_buffer[w_wr_ptr].last     <= wdrv_if.head_d_w_o.last;
                        w_skid_buffer[w_wr_ptr].strb     <= wdrv_if.head_d_w_o.strb;
                        if (w_wr_ptr == WDRV_DEPTH_W-1) begin  
                            w_wr_ptr <= '0; // to fix bug where ptr counts up to 3 instead of doing 0->1->2->0
                        end 
                        else begin 
                            w_wr_ptr <= w_wr_ptr + 1'b1;
                        end
                    end
                end
            end
            if (wdrv_if.w_fire && !w_skid_empty) begin
                w_skid_buffer[w_rd_ptr].valid <= 1'b0;
                //w_rd_ptr <= w_rd_ptr + 1'b1;
                if (w_rd_ptr == WDRV_DEPTH_W-1) begin  
                    w_rd_ptr <= '0; // to fix bug where ptr counts up to 3 instead of doing 0->1->2->0
                end 
                else begin 
                    w_rd_ptr <= w_rd_ptr + 1'b1;
                end
            end
            if (aw_fire && !aw_skid_empty) begin 
                aw_skid_buffer[aw_rd_ptr].valid <= 1'b0;
            end
            if(wdrv_if.w_fire && !aw_skid_empty && w_skid_buffer[w_rd_ptr].last) begin
                aw_rd_ptr <= aw_rd_ptr + 1'b1;
                aw_loaded <= 0;
            end
        end 
    end

    assign same_txn_sp0 = (!aw_sent && (wdrv_if.head_sp0_w_o.mid_id == wdrv_if.head_sp0_aw_o.mid_id)) || (aw_sent && (wdrv_if.head_sp0_w_o.mid_id == aw_skid_buffer[aw_rd_ptr].mid_id));
    assign same_txn_sp1 = (!aw_sent && (wdrv_if.head_sp1_w_o.mid_id == wdrv_if.head_sp1_aw_o.mid_id)) || (aw_sent && (wdrv_if.head_sp1_w_o.mid_id == aw_skid_buffer[aw_rd_ptr].mid_id));
    assign same_txn_d = (!aw_sent && (wdrv_if.head_d_w_o.mid_id == wdrv_if.head_d_aw_o.mid_id)) || (aw_sent && (wdrv_if.head_d_w_o.mid_id == aw_skid_buffer[aw_rd_ptr].mid_id));
    
    // logic to read valid/ready from aw skid buffer
    assign aw_fire = (aw_skid_buffer[aw_rd_ptr].valid && wdrv_if.aw_o_ready);

    // logic to read valid/ready from w skid buffer
    assign wdrv_if.w_fire = (w_skid_buffer[w_rd_ptr].valid && wdrv_if.w_o_ready && (aw_fire || aw_sent));

    assign wdrv_if.skid_ready_w = !aw_skid_full && !w_skid_full;

    always_ff@(posedge CLK, negedge nRST) begin 
        if (!nRST) begin 
            aw_sent <= '0;
        end 
        else begin 
            aw_sent <= aw_fire | aw_sent;
            if (wdrv_if.w_fire && w_skid_buffer[w_rd_ptr].last) begin 
                aw_sent <= '0;
            end
        end 
    end 

    assign wdrv_if.w_sp0_pop = (wdrv_if.aw_grant[MID] && 
                               (wdrv_if.aw_grant[MID-1:0] == SP0) && 
                               !w_skid_full && wdrv_if.head_sp0_wvalid && same_txn_sp0);
    
    assign wdrv_if.w_sp1_pop = (wdrv_if.aw_grant[MID] && 
                               (wdrv_if.aw_grant[MID-1:0] == SP1) && 
                               !w_skid_full && wdrv_if.head_sp1_wvalid && same_txn_sp1);

    assign wdrv_if.w_d_pop   = (wdrv_if.aw_grant[MID] && 
                               (wdrv_if.aw_grant[MID-1:0] == DCACHE) && 
                               !w_skid_full && wdrv_if.head_d_wvalid && same_txn_d);

    assign wdrv_if.aw_o_valid  = aw_skid_buffer[aw_rd_ptr].valid;
    assign wdrv_if.aw_o.addr   = aw_skid_buffer[aw_rd_ptr].addr;
    assign wdrv_if.aw_o.mid_id = aw_skid_buffer[aw_rd_ptr].mid_id;
    assign wdrv_if.aw_o.size   = aw_skid_buffer[aw_rd_ptr].size;
    assign wdrv_if.aw_o.len    = aw_skid_buffer[aw_rd_ptr].len;
    assign wdrv_if.aw_o.burst  = aw_skid_buffer[aw_rd_ptr].burst;

    assign wdrv_if.w_o_valid   = w_skid_buffer[w_rd_ptr].valid && (aw_fire || aw_sent); // ensures the w beats doesnt run off without the aw req
    assign wdrv_if.w_o.mid_id  = w_skid_buffer[w_rd_ptr].mid_id;
    assign wdrv_if.w_o.data    = w_skid_buffer[w_rd_ptr].data;
    assign wdrv_if.w_o.last    = w_skid_buffer[w_rd_ptr].last;
    assign wdrv_if.w_o.strb    = w_skid_buffer[w_rd_ptr].strb;

endmodule