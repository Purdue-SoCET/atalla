`timescale 1ns/1ps
`include "bfA_bfM_bfS_bfSLT_if.sv"

module addsub_bf16_wrapper (
    input  logic        clk,
    input  logic        nRST,

    bfA_bfM_bfS_bfSLT_if.mainport portmap
);

typedef enum {start, latch, done} state;
state n_state, cur_state;

logic [15:0] add_sub_slt_output, mult_output;
logic [15:0] updated_bf_2_in, cur_bf_1, cur_bf_2, latched_bf1, latched_bf2, nlatched_bf1, nlatched_bf2;
logic latched_add, nlatched_add, cur_add;
logic latched_sub, nlatched_sub, cur_sub;
logic latched_mult, nlatched_mult, cur_mult;
logic latched_slt, nlatched_slt, cur_slt;
logic counter_enable, counter_clear;
logic [7:0] nlatchedRD, latchedRD;
logic [3:0] latency, current_count;
logic mult_start;

assign mult_start = portmap.valid_in && cur_mult;

flex_counter counter (.clk(clk), .nrst(nRST), .enable(counter_enable), .clear(counter_clear), .count(current_count));

add_bf16_scalar adder_subber (.clk(clk), .nRST(nRST), .bf1_in(cur_bf_1), .bf2_in(updated_bf_2_in), .bf_out(add_sub_slt_output), .overflow(), .underflow(), .invalid());
mul_bf16_scalar multiplier (.clk(clk), .nRST(nRST), .start(mult_start), .a(cur_bf_1), .b(updated_bf_2_in), .result(mult_output), .done());


always_comb begin
    updated_bf_2_in = cur_bf_2;
    latency = 1;
    portmap.bf_out = 16'b0;
    if(cur_add == 1) begin
        updated_bf_2_in = cur_bf_2;
        latency = 1;
        portmap.bf_out = add_sub_slt_output;
    end else if(cur_sub == 1) begin
        updated_bf_2_in[15] = ~cur_bf_2[15];
        latency = 1;
        portmap.bf_out = add_sub_slt_output;
    end else if(cur_mult == 1) begin
        updated_bf_2_in = cur_bf_2;
        portmap.bf_out = mult_output;
        latency = 1;
    end else if(cur_slt == 1) begin
        updated_bf_2_in[15] = ~cur_bf_2[15];
        if(add_sub_slt_output[15] == 1) begin
            portmap.bf_out = 16'b1;
        end
        latency = 1;
    end
end

always_comb begin
    n_state = cur_state;
    nlatched_bf1 = latched_bf1;
    cur_bf_1 = portmap.bf1_in;
    nlatched_bf2 = latched_bf2;
    cur_bf_2 = portmap.bf2_in;

    nlatched_add = latched_add;
    cur_add = portmap.valid_in && (4'b0010 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_sub = latched_sub;
    cur_sub = portmap.valid_in && (4'b0011 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_mult = latched_mult;
    cur_mult = portmap.valid_in && (4'b0100 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_slt = latched_slt;
    cur_slt = portmap.valid_in && (4'b0101 == portmap.scalar_type_enable) ? 1 : 0;

    portmap.ready_in = 1'b1;
    portmap.valid_out = 1'b0;

    nlatchedRD = latchedRD;
    portmap.rdOut = portmap.rdIn;

    counter_enable = 1'b0;
    counter_clear = 1'b0;

    case (cur_state)
        start: begin
            if(portmap.valid_in) begin
                portmap.ready_in = 1'b0;
                n_state = latch;
                if(latency-1 == 0) begin
                    n_state = done;
                end
            end
            nlatched_bf1 = portmap.bf1_in;
            nlatched_bf2 = portmap.bf2_in;

            nlatched_add = portmap.valid_in && (4'b0010 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_sub = portmap.valid_in && (4'b0011 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_mult = portmap.valid_in && (4'b0100 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_slt = portmap.valid_in && (4'b0101 == portmap.scalar_type_enable) ? 1 : 0;

            nlatchedRD = portmap.rdIn;
        end
        latch: begin
            if(latency-2 == current_count) begin
                n_state = done;
            end
            counter_enable = 1'b1;

            portmap.ready_in = 1'b0;
            portmap.valid_out = 1'b0;

            cur_bf_1 = latched_bf1;
            cur_bf_2 = latched_bf2;

            cur_add = latched_add;
            cur_sub = latched_sub;
            cur_mult = latched_mult;
            cur_slt = latched_slt;

            portmap.rdOut = latchedRD;
        end
        done: begin
            if(portmap.ready_out) begin
                n_state = start;
            end
            counter_clear = 1'b1;

            portmap.ready_in = 1'b0;
            portmap.valid_out = 1'b1;

            cur_bf_1 = latched_bf1;
            cur_bf_2 = latched_bf2;

            cur_add = latched_add;
            cur_sub = latched_sub;
            cur_mult = latched_mult;
            cur_slt = latched_slt;

            portmap.rdOut = latchedRD;
        end
    endcase
end

always_ff @(posedge clk, negedge nRST) begin
    if(!nRST) begin
        latched_bf1 <= 16'b0;
        latched_bf2 <= 16'b0;
        latched_add <= 1'b0;
        latched_sub <= 1'b0;
        latched_mult <= 1'b0;
        latched_slt <= 1'b0;
        cur_state <= start;
        latchedRD <= 8'b0;
    end
    else begin
        latched_bf1 <= nlatched_bf1;
        latched_bf2 <= nlatched_bf2;
        latched_add <= nlatched_add;
        latched_sub <= nlatched_sub;
        latched_mult <= nlatched_mult;
        latched_slt <= nlatched_slt;
        cur_state <= n_state;
        latchedRD <= nlatchedRD;
    end
end



endmodule