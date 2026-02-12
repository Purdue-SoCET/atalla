/*  Aryan Kadakia - kadakia0@purdue.edu */
`timescale 1ps/1ps
`include "axi_bus_pkg.sv"

import axi_bus_pkg::*;

module axi_read_arbiter(
    input  logic        CLK,
    input  logic        nRST,
    input  logic        ready,
    input  logic        sp0_req,
    input  logic        sp1_req,
    input  logic        d_req,
    input  logic        i_req,
    output logic [ARGRANT-1:0] grant_sel
);

    typedef enum logic [2:0] {
        IDLE,
        SP0_GRANTED,
        SP1_GRANTED,
        D_GRANTED,
        I_GRANTED
    } arbitration;

    arbitration state, next_state;
    logic [2:0] next_grant_sel;

    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST) begin
            state <= IDLE;
            grant_sel <= '0;
        end
        else begin 
            state <= next_state;
            grant_sel <= next_grant_sel;
        end
    end

    always_comb begin : NEXT_STATE_LOGIC
        next_state = state;
        next_grant_sel = '0;
        if(!sp0_req && !sp1_req && !d_req && !i_req) begin 
            next_state = IDLE; // safe guard to return to idle if no pending requests, independent of ready
            next_grant_sel = 3'b000;
        end else begin 
            case(state)
                IDLE: begin
                    if      (!ready)  begin next_state = IDLE;        next_grant_sel = 3'b000; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; next_grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; next_grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   next_grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   next_grant_sel = 3'b111; end 
                    //else              begin next_state = IDLE;        next_grant_sel = 3'b000; end
                end
                SP0_GRANTED: begin
                    if      (!ready)  begin next_state = SP0_GRANTED; next_grant_sel = 3'b000; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; next_grant_sel = 3'b101; end 
                    else if (d_req)   begin next_state = D_GRANTED;   next_grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   next_grant_sel = 3'b111; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; next_grant_sel = 3'b100; end
                    //else              begin next_state = IDLE;        next_grant_sel = 3'b000; end
                end
                SP1_GRANTED: begin
                    if      (!ready)  begin next_state = SP1_GRANTED; next_grant_sel = 3'b001; end
                    else if (d_req)   begin next_state = D_GRANTED;   next_grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   next_grant_sel = 3'b111; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; next_grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; next_grant_sel = 3'b101; end 
                    //else              begin next_state = IDLE;        next_grant_sel = 3'b000; end
                end
                D_GRANTED: begin
                    if      (!ready)  begin next_state = D_GRANTED;   next_grant_sel = 3'b010; end 
                    else if (i_req)   begin next_state = I_GRANTED;   next_grant_sel = 3'b111; end 
                    else if (sp0_req) begin next_state = SP0_GRANTED; next_grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; next_grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   next_grant_sel = 3'b110; end
                    //else              begin next_state = IDLE;        next_grant_sel = 3'b000; end
                end
                I_GRANTED: begin
                    if      (!ready)  begin next_state = I_GRANTED;   next_grant_sel = 3'b011; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; next_grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; next_grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   next_grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   next_grant_sel = 3'b111; end
                    //else              begin next_state = IDLE;        next_grant_sel = 3'b000; end
                end 
            endcase
        end 
    end
    
endmodule