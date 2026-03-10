`timescale 1ns/1ps
`include "sMult_if.sv"

module mult_wrapper (
    input logic clk,
    input logic nRST,

    sMult_if.mainport portmap
);

typedef enum {start, latch, done} state;
state n_state, cur_state;

logic [31:0] cur_input_1, cur_input_2, latched_input1, latched_input2, nlatched_input1, nlatched_input2, src2;
logic [63:0] mult_output;
logic latched_sMult, nlatched_sMult, cur_sMult;
logic counter_enable, counter_clear;
logic [7:0] nlatchedRD, latchedRD;
logic [6:0] latency, current_count;
logic [31:0] cur_imm, nlatched_imm, latched_imm;
logic cur_imm_src, nlatched_imm_src, latched_imm_src;
logic ready_latch;

assign ready_latch = cur_sMult && portmap.valid_in;

flex_counter #(.N(7)) counter (.clk(clk), .nrst(nRST), .enable(counter_enable), .clear(counter_clear), .count(current_count));

wt_mult#(.SIGNED(1)) MULTIPLIER (.CLK(clk), .nRST(nRST), .ready(ready_latch), .a(cur_input_1), .b(src2), .done(), .out(mult_output), .reduce_partial_prods());

always_comb begin
    latency = 1;
    portmap.data_out = 32'b0;
    src2 = cur_input_2;
    if(cur_sMult == 1) begin
        latency = 2;
        portmap.data_out = mult_output[31:0];
        if(cur_imm_src) begin
            src2 = cur_imm;
        end
    end
end

always_comb begin
    n_state = cur_state;
    nlatched_input1 = latched_input1;
    cur_input_1 = portmap.input1;
    nlatched_input2 = latched_input2;
    cur_input_2 = portmap.input2;

    nlatched_sMult = latched_sMult;
    cur_sMult = portmap.valid_in && (4'b1101 == portmap.scalar_type_enable) ? 1 : 0;

    nlatched_imm_src = latched_imm_src;
    cur_imm_src = portmap.imm_src;

    nlatched_imm = latched_imm;
    cur_imm = portmap.imm;

    portmap.ready_in = 1'b1;
    portmap.valid_out = 1'b0;

    nlatchedRD = latchedRD;
    portmap.rdOut = portmap.rdIn;

    counter_enable = 1'b0;
    counter_clear = 1'b0;

    case (cur_state)
        start: begin
            if(portmap.valid_in) begin
                n_state = latch;
                if(latency-1 == 0) begin
                    n_state = done;
                end
            end
            nlatched_input1 = portmap.input1;
            nlatched_input2 = portmap.input2;

            nlatched_imm_src = portmap.imm_src;
            nlatched_imm = portmap.imm;

            nlatched_sMult = portmap.valid_in && (4'b1101 == portmap.scalar_type_enable) ? 1 : 0;

            nlatchedRD = portmap.rdIn;
        end
        latch: begin
            if(latency-2 == current_count) begin
                n_state = done;
            end
            counter_enable = 1'b1;

            portmap.ready_in = 1'b0;
            portmap.valid_out = 1'b0;

            cur_input_1 = latched_input1;
            cur_input_2 = latched_input2;

            cur_imm_src = latched_imm_src;
            cur_imm = latched_imm;

            cur_sMult = latched_sMult;

            portmap.rdOut = latchedRD;
        end
        done: begin
            if(portmap.ready_out) begin
                n_state = start;
            end
            counter_clear = 1'b1;

            portmap.ready_in = 1'b0;
            portmap.valid_out = 1'b1;

            cur_input_1 = latched_input1;
            cur_input_2 = latched_input2;

            cur_imm_src = latched_imm_src;
            cur_imm = latched_imm;

            cur_sMult = latched_sMult;

            portmap.rdOut = latchedRD;
        end
    endcase
end

always_ff @(posedge clk, negedge nRST) begin
    if(!nRST) begin
        latched_input1 <= 16'b0;
        latched_input2 <= 16'b0;
        latched_sMult <= 1'b0;
        cur_state <= start;
        latchedRD <= 8'b0;
        latched_imm_src <= 1'b0;
        latched_imm <= 32'b0;
    end
    else begin
        latched_input1 <= nlatched_input1;
        latched_input2 <= nlatched_input2;
        latched_sMult <= nlatched_sMult;
        cur_state <= n_state;
        latchedRD <= nlatchedRD;
        latched_imm_src <= nlatched_imm_src;
        latched_imm <= nlatched_imm;
    end
end



endmodule