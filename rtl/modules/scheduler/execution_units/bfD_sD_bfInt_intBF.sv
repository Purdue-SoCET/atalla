`timescale 1ns/1ps
`include "bfD_sD_bfInt_intBF_if.sv"

module div_bf_scalar_convert_wrapper (
    input  logic        clk,
    input  logic        nRST,

    bfD_sD_bfInt_intBF_if.mainport portmap
);

typedef enum {start, latch, done} state;
state n_state, cur_state;

div_if divif

logic [31:0] bf_int_output, scalar_div_output, scalar_mod_output;
logic [15:0] int_bf_output, bf_div_output;
logic [31:0] cur_input_1, cur_input_2, latched_input1, latched_input2, nlatched_input1, nlatched_input2;
logic latched_BFdiv, nlatched_BFdiv, cur_BFdiv;
logic latched_Sdiv, nlatched_Sdiv, cur_Sdiv;
logic latched_Smod, nlatched_Smod, cur_Smod;
logic latched_BF_Int, nlatched_BF_Int, cur_BF_Int;
logic latched_Int_BF, nlatched_Int_BF, cur_Int_BF;
logic counter_enable, counter_clear;
logic [7:0] nlatchedRD, latchedRD;
logic [3:0] latency, current_count;
logic start_div_mod;

assign divif.in.operand1 = cur_input_1[15:0];
assign divif.in.operand2 = cur_input_2[15:0];
assign divif.in.valid_in = portmap.valid_in && cur_BFdiv;
assign bf_div_output = divif.out.result;

flex_counter counter (.clk(clk), .nrst(nRST), .enable(counter_enable), .clear(counter_clear), .count(current_count));

assign start_div_mod = (cur_Sdiv || cur_Smod) && portmap.valid_in;

div DIVIDER_BF16 (.CLK(clk), .nRST(nRST), .divif(divif));
bf_to_int BF_INT_CONV (.inputBF(cur_input_1[15:0]), .outputInt(bf_int_output));
int_to_bf INT_BF_CONV (.inputInt(cur_input_1), .outputBF(int_bf_output));
socetlib_radix4_divider DIVIDER_SCALAR (.CLK(clk), .nRST(nRST), .start(start_div_mod), .is_signed(1), .dividend(cur_input_1), .divisor(cur_input_2), .quotient(scalar_div_output), .remainder(scalar_mod_output), .finished());

always_comb begin
    latency = 1;
    portmap.data_out = 32'b0;
    if(cur_BFdiv == 1) begin
        latency = 15;
        portmap.data_out = {16'b0, bf_div_output};
    end else if(cur_Sdiv == 1) begin
        latency = 15;
        portmap.data_out = scalar_div_output;
    end else if(cur_Smod == 1) begin
        latency = 15;
        portmap.data_out = scalar_mod_output;
    end else if(cur_BF_Int == 1) begin
        latency = 1;
        portmap.data_out = bf_int_output;
    end else if(cur_Int_BF == 1) begin
        latency = 1;
        portmap.data_out = {16'b0, int_bf_output};
    end
end

always_comb begin
    n_state = cur_state;
    nlatched_bf1 = latched_bf1;
    cur_bf_1 = portmap.bf1_in;
    nlatched_bf2 = latched_bf2;
    cur_bf_2 = portmap.bf2_in;

    nlatched_add = latched_add;
    cur_add = portmap.add;
    nlatched_sub = latched_sub;
    cur_sub = portmap.sub;
    nlatched_mult = latched_mult;
    cur_mult = portmap.mult;
    nlatched_slt = latched_slt;
    cur_slt = portmap.slt;

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
            nlatched_bf1 = portmap.bf1_in;
            nlatched_bf2 = portmap.bf2_in;

            nlatched_add = portmap.add;
            nlatched_sub = portmap.sub;
            nlatched_mult = portmap.mult;
            nlatched_slt = portmap.slt;

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
        latched_input1 <= 16'b0;
        latched_input2 <= 16'b0;
        latched_BFdiv <= 1'b0;
        latched_Sdiv <= 1'b0;
        latched_Smod <= 1'b0;
        latched_BF_Int <= 1'b0;
        latched_Int_BF <= 1'b0;
        cur_state <= start;
        latchedRD <= 8'b0;
    end
    else begin
        latched_input1 <= nlatched_input1;
        latched_input2 <= nlatched_input2;
        latched_BFdiv <= nlatched_BFdiv;
        latched_Sdiv <= nlatched_Sdiv;
        latched_Smod <= nlatched_Smod;
        latched_BF_Int <= nlatched_BF_Int;
        latched_Int_BF <= nlatched_Int_BF;
        cur_state <= n_state;
        latchedRD <= nlatchedRD;
    end
end



endmodule