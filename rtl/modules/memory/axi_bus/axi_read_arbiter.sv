`timescale 1ps/1ps
`include "axi_bus_pkg.sv"



module axi_read_arbiter
import axi_bus_pkg::*;
(
    input  logic        CLK,
    input  logic        nRST,
    input  logic        ready,
    input  logic        sp0_req,
    input  logic        sp1_req,
    input  logic        d_req,
    input  logic        i_req,
    output logic [ARGRANT-1:0] grant_sel
);
    logic ar_valid;
    assign ar_valid = sp0_req || sp1_req || d_req || i_req;

    typedef enum logic [2:0] {
        IDLE,
        SP0_GRANTED,
        SP1_GRANTED,
        D_GRANTED,
        I_GRANTED
    } arbitration;

    arbitration state, next_state;

    // Only state is registered now
    always_ff @(posedge CLK, negedge nRST) begin
        if(!nRST)
            state <= IDLE;
        else
            state <= next_state;
    end

    // grant_sel is now combinational — appears same cycle
    always_comb begin
        next_state = state;
        grant_sel  = '0;

        if(!ar_valid) begin
            next_state = IDLE;
            grant_sel  = 3'b000;
        end else begin
            case(state)
                IDLE: begin
                    if      (!ready)  begin next_state = IDLE;        grant_sel = 3'b000; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   grant_sel = 3'b111; end
                end
                SP0_GRANTED: begin
                    if      (!ready)  begin next_state = SP0_GRANTED; grant_sel = 3'b000; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   grant_sel = 3'b111; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; grant_sel = 3'b100; end
                end
                SP1_GRANTED: begin
                    if      (!ready)  begin next_state = SP1_GRANTED; grant_sel = 3'b001; end
                    else if (d_req)   begin next_state = D_GRANTED;   grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   grant_sel = 3'b111; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; grant_sel = 3'b101; end
                end
                D_GRANTED: begin
                    if      (!ready)  begin next_state = D_GRANTED;   grant_sel = 3'b010; end
                    else if (i_req)   begin next_state = I_GRANTED;   grant_sel = 3'b111; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   grant_sel = 3'b110; end
                end
                I_GRANTED: begin
                    if      (!ready)  begin next_state = I_GRANTED;   grant_sel = 3'b011; end
                    else if (sp0_req) begin next_state = SP0_GRANTED; grant_sel = 3'b100; end
                    else if (sp1_req) begin next_state = SP1_GRANTED; grant_sel = 3'b101; end
                    else if (d_req)   begin next_state = D_GRANTED;   grant_sel = 3'b110; end
                    else if (i_req)   begin next_state = I_GRANTED;   grant_sel = 3'b111; end
                end
                default: begin
                    next_state = IDLE;
                    grant_sel  = 3'b000;
                end
            endcase
        end
    end

endmodule
