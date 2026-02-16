/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"
`include "axi_bus_if.sv"

import axi_bus_pkg::*;

module axi_write_arbiter (
    input logic CLK,
    input logic nRST,
    axi_bus_if.write_arbiter arbw_if
);

    typedef enum logic [2:0] {
        IDLE,
        SP0_GRANTED,
        SP1_GRANTED,
        D_GRANTED
    } arbitration;

   arbitration state, next_state;
   logic [AWGRANT-1:0] next_grant_sel;
   logic [AWLEN-1:0] counter, next_counter; // might have to be [AWLEN:0] to acocunt for 16th beat 

   always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
            arbw_if.aw_grant <= '0;
            counter <= '0;
        end
        else begin 
            state <= next_state;
            arbw_if.aw_grant <= next_grant_sel;
            counter <= next_counter; 
        end
    end

    always_comb begin : NEXT_STATE_LOGIC
        next_state = state;
        next_grant_sel = '0;
        next_counter = '0;
        if(!arbw_if.sp0_req_w && !arbw_if.sp1_req_w && !arbw_if.d_req_w) begin
            next_state = IDLE;
            next_grant_sel = '0;
            next_counter = '0;
        end else begin
            case(state)
                IDLE: begin
                    if      (!arbw_if.skid_ready_w) begin next_state = IDLE;        next_grant_sel = '0;             end 
                    else if (arbw_if.sp0_req_w)     begin next_state = SP0_GRANTED; next_grant_sel = {1'b1, SP0};    next_counter = arbw_if.sp0_len_w; end
                    else if (arbw_if.sp1_req_w)     begin next_state = SP1_GRANTED; next_grant_sel = {1'b1, SP1};    next_counter = arbw_if.sp1_len_w; end
                    else if (arbw_if.d_req_w)       begin next_state = D_GRANTED;   next_grant_sel = {1'b1, DCACHE}; next_counter = arbw_if.d_len_w;   end
                end 
                SP0_GRANTED: begin 
                    if      (!arbw_if.skid_ready_w) begin next_state = SP0_GRANTED; next_grant_sel = {1'b0, SP0};    next_counter = counter;           end
                    else if (counter != '0)         begin next_state = SP0_GRANTED; next_grant_sel = {1'b1, SP0};    next_counter = counter - 1;       end 
                    else if (arbw_if.sp1_req_w)     begin next_state = SP1_GRANTED; next_grant_sel = {1'b1, SP1};    next_counter = arbw_if.sp1_len_w; end
                    else if (arbw_if.d_req_w)       begin next_state = D_GRANTED;   next_grant_sel = {1'b1, DCACHE}; next_counter = arbw_if.d_len_w;   end 
                    else if (arbw_if.sp0_req_w)     begin next_state = SP0_GRANTED; next_grant_sel = {1'b1, SP0};    next_counter = arbw_if.sp0_len_w; end 
                end 
                SP1_GRANTED: begin 
                    if      (!arbw_if.skid_ready_w) begin next_state = SP1_GRANTED; next_grant_sel = {1'b0, SP1};    next_counter = counter;           end
                    else if (counter != '0)         begin next_state = SP1_GRANTED; next_grant_sel = {1'b1, SP1};    next_counter = counter - 1;       end 
                    else if (arbw_if.d_req_w)       begin next_state = D_GRANTED;   next_grant_sel = {1'b1, DCACHE}; next_counter = arbw_if.d_len_w;   end 
                    else if (arbw_if.sp0_req_w)     begin next_state = SP0_GRANTED; next_grant_sel = {1'b1, SP0};    next_counter = arbw_if.sp0_len_w; end 
                    else if (arbw_if.sp1_req_w)     begin next_state = SP1_GRANTED; next_grant_sel = {1'b1, SP1};    next_counter = arbw_if.sp1_len_w; end 
                end
                D_GRANTED: begin 
                    if      (!arbw_if.skid_ready_w) begin next_state = D_GRANTED;   next_grant_sel = {1'b0, DCACHE}; next_counter = counter;           end 
                    else if (counter != '0)         begin next_state = D_GRANTED;   next_grant_sel = {1'b1, DCACHE}; next_counter = counter - 1;       end 
                    else if (arbw_if.sp0_req_w)     begin next_state = SP0_GRANTED; next_grant_sel = {1'b1, SP0};    next_counter = arbw_if.sp0_len_w; end
                    else if (arbw_if.sp1_req_w)     begin next_state = SP1_GRANTED; next_grant_sel = {1'b1, SP1};    next_counter = arbw_if.sp1_len_w; end
                    else if (arbw_if.d_req_w)       begin next_state = D_GRANTED;   next_grant_sel = {1'b1, DCACHE}; next_counter = arbw_if.d_len_w;   end
                end 
            endcase
        end 
    end 
endmodule