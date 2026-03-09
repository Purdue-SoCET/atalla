`include "div_if.vh"

module div_pipelined (
    input logic CLK, nRST,
    div_if.dvif divif
);

// PARAMETERS
    localparam [7:0] BIAS = 8'h7F;
    localparam [7:0] EXP_INF = 8'hFF;
    localparam [15:0] TWO = 16'h4000;
    localparam [15:0] qNaN = 16'h7FC0;

// PIPELINE SHIFT REGISTERS
    // p_valid[1:5] tracks where the valid data is in the 4-stage loop
    logic [5:1] p_valid, p_is_iter2, p_is_spec, p_sign, p_sub_bound;
    logic signed [9:0] p_exp_diff [5:1];
    logic [15:0] p_spec_res [5:1];

    logic [15:0] reg_outn, reg_outd, reg_subout;
    logic [15:0] delay_n1_3, delay_n1_4, delay_n1_5;
    logic [15:0] ip_outn, ip_outd, ip_subout;

    logic stage2_done, loopback_req, accept_new;
    logic global_stall;

    // Data is ONLY done when it has completed Iteration 2. 
    // Special cases ride the pipeline for the full 2 iterations to guarantee inorder output
    assign stage2_done = p_valid[2] && p_is_iter2[2];

    // Iteration 1 data always loops back to start Iteration 2
    assign loopback_req = p_valid[5]; 


    // OUTPUT LOGIC
    assign divif.out.valid_out = stage2_done;

    logic signed [9:0] raw_exp;
    logic [7:0] final_exp;
    logic [15:0] calculated_fin;

    // Splice the final mathematical answer
    assign raw_exp = p_exp_diff[2] + {2'b00, reg_outn[14:7]};
    always_comb begin
        if (raw_exp >= 10'sd255) final_exp = EXP_INF; 
        else if (raw_exp <= 10'sd0 || p_sub_bound[2]) final_exp = 8'h00; 
        else final_exp = raw_exp[7:0];
    end
    
    assign calculated_fin = (final_exp == 8'h00) ? {p_sign[2], 15'h0000} : {p_sign[2], final_exp, reg_outn[6:0]};
    assign divif.out.result = p_is_spec[2] ? p_spec_res[2] : calculated_fin;
    assign global_stall = stage2_done && !divif.in.ready_out;
    
    assign divif.out.ready_in = (nRST == 1'b1) ? (!loopback_req && !global_stall) : 1'b0;
    assign accept_new = divif.in.valid_in && divif.out.ready_in;

// STAGE 0: The Arbiter & Combinational Pre-Compute
    logic op1_is_zero, op2_is_zero, op1_is_inf, op2_is_inf, op1_is_nan, op2_is_nan, op1_op2_same, op2_is_one;
    logic in_is_special;
    logic [15:0] in_special_res;
    logic in_sign, in_sub_bound;
    logic signed [9:0] in_exp_diff;
    logic [15:0] new_muln, new_muld, new_f;
    
    // 1. Math Setup
    assign new_muln = (divif.in.operand1[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand1[6:0]};
    assign new_muld = (divif.in.operand2[14:7] == 8'h00) ? 16'h8000 : {1'b0, BIAS, divif.in.operand2[6:0]};
    assign new_f = 16'h7EF3 - new_muld; 
    assign in_sign = divif.in.operand1[15] ^ divif.in.operand2[15];
    assign in_exp_diff = {2'b00, divif.in.operand1[14:7]} - {2'b00, divif.in.operand2[14:7]};
    assign in_sub_bound = (in_exp_diff == -10'sd126) && (divif.in.operand1[6:0] < divif.in.operand2[6:0]);

    // 2. Edge Case Detection
    assign op1_is_zero = (divif.in.operand1[14:7] == 8'h00);
    assign op2_is_zero = (divif.in.operand2[14:7] == 8'h00);
    assign op1_is_inf = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] == 7'h00);
    assign op2_is_inf = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] == 7'h00);
    assign op1_is_nan = (divif.in.operand1[14:7] == 8'hFF) && (divif.in.operand1[6:0] != 7'h00);
    assign op2_is_nan = (divif.in.operand2[14:7] == 8'hFF) && (divif.in.operand2[6:0] != 7'h00);
    assign op1_op2_same = (divif.in.operand1[14:0] == divif.in.operand2[14:0]);
    assign op2_is_one = (divif.in.operand2[14:0] == 15'h3F80);

    always_comb begin
        in_is_special  = 1'b1;
        in_special_res = {in_sign, 15'h0000};
        if (op1_is_nan || op2_is_nan) in_special_res = qNaN;
        else if ((op1_is_zero && op2_is_zero) || (op1_is_inf && op2_is_inf)) in_special_res = qNaN;
        else if (op2_is_zero) in_special_res = {in_sign, 8'hFF, 7'h00};
        else if (op2_is_inf) in_special_res = {in_sign, 15'h0000};
        else if (op1_is_zero) in_special_res = {in_sign, 15'h0000};
        else if (op1_is_inf) in_special_res = {in_sign, 8'hFF, 7'h00};
        else if (op1_op2_same && !op2_is_zero) in_special_res = {in_sign, 15'h3F80};
        else if (op2_is_one) in_special_res = {in_sign, divif.in.operand1[14:0]};
        else in_is_special = 1'b0; 
    end

    // 3. The Arbiter Multiplexer
    logic nxt_v0, nxt_iter2, nxt_spec, nxt_sub_bound, nxt_sign;
    logic [15:0] nxt_muln, nxt_muld, nxt_f, nxt_spec_res; logic signed [9:0] nxt_exp_diff;

    always_comb begin
        if (loopback_req) begin
            // Iteration 2 Traffic (Priority)
            nxt_v0 = 1'b1;
            nxt_iter2 = 1'b1; 
            nxt_muln = delay_n1_5;
            nxt_muld = 16'h0000;
            nxt_f = reg_subout;
            nxt_sign = p_sign[5];
            nxt_exp_diff = p_exp_diff[5];
            nxt_sub_bound = p_sub_bound[5]; 
            nxt_spec = p_is_spec[5];
            nxt_spec_res = p_spec_res[5];
        end else if (accept_new) begin
            // Iteration 1 Traffic (New Inputs)
            nxt_v0 = 1'b1;
            nxt_iter2 = 1'b0; 
            nxt_muln = new_muln;
            nxt_muld = new_muld;
            nxt_f = new_f;
            nxt_sign = in_sign;
            nxt_exp_diff = in_exp_diff;
            nxt_sub_bound = in_sub_bound;
            nxt_spec = in_is_special;
            nxt_spec_res = in_special_res;
        end else begin
            // Pipeline Bubble
            nxt_v0 = 1'b0;
            nxt_iter2 = 1'b0; 
            nxt_muln = 16'h0;
            nxt_muld = 16'h0;
            nxt_f = 16'h0;
            nxt_sign = 1'b0;
            nxt_exp_diff = 10'sd0;
            nxt_sub_bound = 1'b0; 
            nxt_spec = 1'b0;
            nxt_spec_res = 16'h0;
        end
    end

// Main CAROUSEL
    always_ff @(posedge CLK, negedge nRST) begin
        if (~nRST) begin
            p_valid <= 5'b0000;
            reg_outn <= 0;
            reg_outd <= 0;
            reg_subout <= 0;
            delay_n1_3 <= 0;
            delay_n1_4 <= 0;
            delay_n1_5 <= 0;
        end else if (!global_stall) begin
            // --- STAGE 1 (Entering Multipliers) ---
            p_valid[1] <= nxt_v0;
            p_is_iter2[1] <= nxt_iter2;
            p_is_spec[1] <= nxt_spec;
            p_sign[1] <= nxt_sign;
            p_exp_diff[1] <= nxt_exp_diff;
            p_sub_bound[1] <= nxt_sub_bound;
            p_spec_res[1] <= nxt_spec_res;
            
            // --- STAGE 2 (Leaving Multipliers) ---
            p_valid[2] <= p_valid[1];
            p_is_iter2[2] <= p_is_iter2[1];
            p_is_spec[2] <= p_is_spec[1];
            p_sign[2] <= p_sign[1];
            p_exp_diff[2] <= p_exp_diff[1];
            p_sub_bound[2] <= p_sub_bound[1];
            p_spec_res[2] <= p_spec_res[1];
            reg_outn <= ip_outn; // Lock in the multiplier result
            reg_outd <= ip_outd; 

            // --- STAGE 3 (Entering Subtractor FF1) ---
            p_valid[3] <= p_valid[2] && !stage2_done; 
            p_is_iter2[3] <= p_is_iter2[2];
            p_is_spec[3] <= p_is_spec[2];
            p_sign[3] <= p_sign[2];
            p_exp_diff[3] <= p_exp_diff[2];
            p_sub_bound[3] <= p_sub_bound[2];
            p_spec_res[3] <= p_spec_res[2];
            delay_n1_3 <= reg_outn; 

            // --- STAGE 4 (Entering Subtractor FF2) ---
            p_valid[4] <= p_valid[3];
            p_is_iter2[4] <= p_is_iter2[3];
            p_is_spec[4] <= p_is_spec[3];
            p_sign[4] <= p_sign[3];
            p_exp_diff[4] <= p_exp_diff[3];
            p_sub_bound[4] <= p_sub_bound[3];
            p_spec_res[4] <= p_spec_res[3];
            delay_n1_4 <= delay_n1_3;

            // --- STAGE 5 (Leaving Subtractor) ---
            p_valid[5] <= p_valid[4];
            p_is_iter2[5] <= p_is_iter2[4];
            p_is_spec[5] <= p_is_spec[4];
            p_sign[5] <= p_sign[4];
            p_exp_diff[5] <= p_exp_diff[4];
            p_sub_bound[5] <= p_sub_bound[4];
            p_spec_res[5] <= p_spec_res[4];
            reg_subout <= ip_subout; // Lock in the final subtractor result
            delay_n1_5 <= delay_n1_4;
        end
    end

    // HARDWARE BLOCKS
    
    mul_bf16 mul_numerator (
        .clk(CLK), 
        .nRST(nRST),
        .start(!global_stall),
        .a(nxt_muln),
        .b(nxt_f),
        .result(ip_outn),
        .done()
    );

    mul_bf16 mul_denominator (
        .clk(CLK), 
        .nRST(nRST),
        .start(!global_stall),
        .a(nxt_muld),
        .b(nxt_f),
        .result(ip_outd),
        .done()
    );

    addsub_bf16 sub (
        .clk(CLK),
        .nRST(nRST),
        .start(!global_stall),
        .stall(global_stall),
        .bf1_in(TWO),
        .bf2_in(reg_outd),
        .op(1'b1),
        .bf_out(ip_subout),
        .overflow(),
        .underflow(),
        .invalid(),
        .done()
    );

endmodule