`timescale 1ns/1ps
`include "bfD_sD_bfInt_intBF_if.sv"
`include "div_if.vh"
`include "sqrt_if.sv"

module div_bf_scalar_convert_wrapper (
    input  logic        clk,
    input  logic        nRST,

    bfD_sD_bfInt_intBF_if.mainport portmap
);

typedef enum {start, latch, done} state;
state n_state, cur_state;

div_if divif ();
sqrt_if srif ();

logic [31:0] bf_int_output, scalar_div_output, scalar_mod_output;
logic [15:0] int_bf_output, bf_div_output, bf_sqrt_output;
logic [31:0] cur_input_1, cur_input_2, latched_input1, latched_input2, nlatched_input1, nlatched_input2, src2;
logic latched_BFdiv, nlatched_BFdiv, cur_BFdiv;
logic latched_Sdiv, nlatched_Sdiv, cur_Sdiv;
logic latched_Smod, nlatched_Smod, cur_Smod;
logic latched_BF_Int, nlatched_BF_Int, cur_BF_Int;
logic latched_Int_BF, nlatched_Int_BF, cur_Int_BF;
logic latched_sqrt, nlatched_sqrt, cur_sqrt;
logic counter_enable, counter_clear;
logic [7:0] nlatchedRD, latchedRD;
logic [6:0] latency, current_count;
logic [31:0] cur_imm, nlatched_imm, latched_imm;
logic cur_imm_src, nlatched_imm_src, latched_imm_src;
logic start_div_mod, latch_valid;
logic internal_temp;
logic cur_mask_move, nlatched_mask_move, latched_mask_move;

assign divif.in.operand1 = 16'h3f80;
assign divif.in.operand2 = cur_input_1[15:0];
assign divif.in.valid_in = (portmap.valid_in || latch_valid) && cur_BFdiv;
assign divif.in.ready_out = 1'b1;
assign bf_div_output = divif.out.result;

assign srif.in.operand = cur_input_1[15:0];
assign srif.in.valid_in = (portmap.valid_in || latch_valid) && cur_sqrt;
assign srif.in.ready_out = 1'b1;
assign bf_sqrt_output = srif.out.result;

flex_counter #(.N(7)) counter (.clk(clk), .nrst(nRST), .enable(counter_enable), .clear(counter_clear), .count(current_count));

assign start_div_mod = (cur_Sdiv || cur_Smod) && (portmap.valid_in);

div DIVIDER_BF16 (.CLK(clk), .nRST(nRST), .divif(divif));
bf_to_int BF_INT_CONV (.inputBF(cur_input_1[15:0]), .outputInt(bf_int_output));
int_to_bf INT_BF_CONV (.inputInt(cur_input_1), .outputBF(int_bf_output));
socetlib_shift_test_restore_divider DIVIDER_SCALAR (.CLK(clk), .nRST(nRST), .start(start_div_mod), .is_signed(1'b1), .dividend(cur_input_1), .divisor(src2), .quotient(scalar_div_output), .remainder(scalar_mod_output), .finished(internal_temp));
sqrt_bf16 BF16_SQRT (.CLK(clk), .nRST(nRST), .srif(srif));

always_comb begin
    latency = 1;
    portmap.data_out = 32'b0;
    src2 = cur_input_2;
    portmap.to_mask_out = 1'b0;
    if(cur_BFdiv == 1) begin
        latency = 11;
        portmap.data_out = {16'b0, bf_div_output};
    end else if(cur_Sdiv == 1) begin
        latency = 66;
        portmap.data_out = scalar_div_output;
        if(cur_imm_src) begin
            src2 = cur_imm;
        end
    end else if(cur_Smod == 1) begin
        latency = 66;
        portmap.data_out = scalar_mod_output;
        if(cur_imm_src) begin
            src2 = cur_imm;
        end
    end else if(cur_BF_Int == 1 && !cur_mask_move == 1) begin
        latency = 1;
        portmap.data_out = bf_int_output;
    end else if(cur_Int_BF == 1) begin
        latency = 1;
        portmap.data_out = {16'b0, int_bf_output};
    end else if(cur_sqrt == 1) begin
        latency = 11;
        portmap.data_out = {16'b0, bf_sqrt_output};
    end else if(cur_BF_Int == 1 && cur_mask_move == 1) begin
        latency = 1;
        portmap.data_out = cur_input_1;
        portmap.to_mask_out = 1;
    end
end

always_comb begin
    n_state = cur_state;
    nlatched_input1 = latched_input1;
    cur_input_1 = portmap.input1;
    nlatched_input2 = latched_input2;
    cur_input_2 = portmap.input2;

    nlatched_BFdiv = latched_BFdiv;
    cur_BFdiv = portmap.valid_in && (4'b0110 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_Sdiv = latched_Sdiv;
    cur_Sdiv = portmap.valid_in && (4'b0111 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_Smod = latched_Smod;
    cur_Smod = portmap.valid_in && (4'b1000 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_BF_Int = latched_BF_Int;
    cur_BF_Int = portmap.valid_in && (4'b1001 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_Int_BF = latched_Int_BF;
    cur_Int_BF = portmap.valid_in && (4'b1010 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_sqrt = latched_sqrt;
    cur_sqrt = portmap.valid_in && (4'b1111 == portmap.scalar_type_enable) ? 1 : 0;
    nlatched_mask_move = latched_mask_move;
    cur_mask_move = portmap.to_mask_in;

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
    latch_valid = 1'b0;

    case (cur_state)
        start: begin
            if(portmap.valid_in) begin
                portmap.ready_in = 1'b0;
                n_state = latch;
                if(latency-1 == 0) begin
                    n_state = done;
                end
            end
            nlatched_input1 = portmap.input1;
            nlatched_input2 = portmap.input2;

            nlatched_BFdiv = portmap.valid_in && (4'b0110 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_Sdiv = portmap.valid_in && (4'b0111 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_Smod = portmap.valid_in && (4'b1000 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_BF_Int = portmap.valid_in && (4'b1001 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_Int_BF = portmap.valid_in && (4'b1010 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_sqrt = portmap.valid_in && (4'b1111 == portmap.scalar_type_enable) ? 1 : 0;
            nlatched_mask_move = portmap.to_mask_in;

            nlatched_imm_src = portmap.imm_src;
            nlatched_imm = portmap.imm;

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

            cur_BFdiv = latched_BFdiv;
            cur_Sdiv = latched_Sdiv;
            cur_Smod = latched_Smod;
            cur_BF_Int = latched_BF_Int;
            cur_Int_BF = latched_Int_BF;
            cur_sqrt = latched_sqrt;
            cur_mask_move = latched_mask_move;

            cur_imm_src = latched_imm_src;
            cur_imm = latched_imm;

            portmap.rdOut = latchedRD;
            latch_valid = 1'b1;
        end
        done: begin
            if((portmap.ready_out && ~cur_mask_move) || (portmap.mask_ready_out && cur_mask_move)) begin
                n_state = start;
            end
            counter_clear = 1'b1;

            portmap.ready_in = 1'b0;
            portmap.valid_out = 1'b1;

            cur_input_1 = latched_input1;
            cur_input_2 = latched_input2;

            cur_BFdiv = latched_BFdiv;
            cur_Sdiv = latched_Sdiv;
            cur_Smod = latched_Smod;
            cur_BF_Int = latched_BF_Int;
            cur_Int_BF = latched_Int_BF;
            cur_sqrt = latched_sqrt;
            cur_mask_move = latched_mask_move;

            cur_imm_src = latched_imm_src;
            cur_imm = latched_imm;

            portmap.rdOut = latchedRD;
            latch_valid = 1'b0;
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
        latched_sqrt <= 1'b0;
        cur_state <= start;
        latchedRD <= 8'b0;
        latched_imm_src <= 1'b0;
        latched_imm <= 32'b0;
        latched_mask_move <= 1'b0;
    end
    else begin
        latched_input1 <= nlatched_input1;
        latched_input2 <= nlatched_input2;
        latched_BFdiv <= nlatched_BFdiv;
        latched_Sdiv <= nlatched_Sdiv;
        latched_Smod <= nlatched_Smod;
        latched_BF_Int <= nlatched_BF_Int;
        latched_Int_BF <= nlatched_Int_BF;
        latched_sqrt <= nlatched_sqrt;
        cur_state <= n_state;
        latchedRD <= nlatchedRD;
        latched_imm_src <= nlatched_imm_src;
        latched_imm <= nlatched_imm;
        latched_mask_move <= nlatched_mask_move;
    end
end



endmodule