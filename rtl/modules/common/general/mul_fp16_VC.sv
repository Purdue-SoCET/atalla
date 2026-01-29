`timescale 1ns/1ps
// FP16 Pipelined Multiplier for Vector Core 
// 3-cycle latency using wallacetree_11b_2c (pipeline split inside wallace tree)
// Cycle 0: start=1, inputs sampled
// Cycle 1: Input latch 
// Cycle 2: WTM internal reg 
// Author : Myles Querimit (Reference Vinay Pundith)
// passes 999,997 out of 1 mil, the 3 wrong are boundry based on how hardware v numpy treats ftz 
// output diff is smallest subnormal in to zero (in mac it gets ftz next stage anyways but keep in mind) 

module mul_fp16_VC(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic [15:0] a, b,
    output logic [15:0] result,
    output logic done
);


    // Cycle 1: Input Latch
    logic [15:0] a_lat, b_lat;
    logic stage0_valid;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            a_lat <= '0;
            b_lat <= '0;
            stage0_valid <= '0;
        end
        else begin
            a_lat <= a;
            b_lat <= b;
            stage0_valid <= start;
        end
    end

    // Cycle 2: WTM stages 1-4 (combinational)

    // Extract fields from latched inputs
    logic [4:0] exp_a, exp_b;
    logic [9:0] mant_a, mant_b;
    assign exp_a = a_lat[14:10];
    assign exp_b = b_lat[14:10];
    assign mant_a = a_lat[9:0];
    assign mant_b = b_lat[9:0];

    // Special value detection (combinational, parallel with WTM)
    logic a_exp_zero, b_exp_zero;
    logic a_exp_max, b_exp_max;
    logic a_mant_zero, b_mant_zero;
    assign a_exp_zero = (exp_a == 5'b0);
    assign b_exp_zero = (exp_b == 5'b0);
    assign a_exp_max = (exp_a == 5'h1F);
    assign b_exp_max = (exp_b == 5'h1F);
    assign a_mant_zero = (mant_a == 10'b0);
    assign b_mant_zero = (mant_b == 10'b0);

    logic a_is_zero, b_is_zero;
    logic a_is_special, b_is_special;
    logic any_nan, any_inf, any_zero, inf_times_zero;
    
    assign a_is_zero = a_exp_zero;
    assign b_is_zero = b_exp_zero;
    assign a_is_special = a_exp_max;
    assign b_is_special = b_exp_max;
    assign any_nan = (a_is_special & ~a_mant_zero) | (b_is_special & ~b_mant_zero);
    assign any_inf = (a_is_special & a_mant_zero) | (b_is_special & b_mant_zero);
    assign any_zero = a_is_zero | b_is_zero;
    assign inf_times_zero = ((a_is_special & a_mant_zero) & b_is_zero) | 
                            ((b_is_special & b_mant_zero) & a_is_zero);

    // Sign calculation
    logic mul_sign;
    assign mul_sign = a_lat[15] ^ b_lat[15];

    // Implicit leading bits
    logic frac_leading_bit_fp1, frac_leading_bit_fp2;
    assign frac_leading_bit_fp1 = ~a_exp_zero;
    assign frac_leading_bit_fp2 = ~b_exp_zero;

    // Pipelined Wallace tree multiply (has internal register between stage4/5)
    logic [12:0] mul_product;
    logic mul_carryout;
    logic mul_round_loss;
    logic wtm_ready;

    wallacetree_11b_2c wallaca (
        .clk(clk),
        .nRST(nRST),
        .a({frac_leading_bit_fp1, a_lat[9:0]}),
        .b({frac_leading_bit_fp2, b_lat[9:0]}),
        .active(stage0_valid),
        .result(mul_product),
        .overflow(mul_carryout),
        .round_loss(mul_round_loss),
        .value_ready(wtm_ready)
    );

    // Register special case flags aligned with WTM internal register
    logic mul_sign_r1;
    logic any_nan_r1, any_inf_r1, any_zero_r1, inf_times_zero_r1;
    logic [4:0] exp_a_r1, exp_b_r1;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            mul_sign_r1 <= '0;
            any_nan_r1 <= '0;
            any_inf_r1 <= '0;
            any_zero_r1 <= '0;
            inf_times_zero_r1 <= '0;
            exp_a_r1 <= '0;
            exp_b_r1 <= '0;
        end
        else begin
            mul_sign_r1 <= mul_sign;
            any_nan_r1 <= any_nan;
            any_inf_r1 <= any_inf;
            any_zero_r1 <= any_zero;
            inf_times_zero_r1 <= inf_times_zero;
            exp_a_r1 <= exp_a;
            exp_b_r1 <= exp_b;
        end
    end

    // Cycle 3
    
    // Exponent addition (uses mul_carryout from WTM)
    logic [4:0] exp_sum;
    logic exp_ovf, exp_unf;
    
    adder_5b add_EXPs (
        .carry(mul_carryout),
        .exp1(exp_a_r1),
        .exp2(exp_b_r1),
        .sum(exp_sum),
        .ovf(exp_ovf),
        .unf(exp_unf)
    );

    // Normalization shift
    logic [9:0] mul_frac_normalized;
    logic guard_bit, round_bit, sticky_bit;
    always_comb begin
        if (mul_carryout) begin
            mul_frac_normalized = mul_product[12:3];
            guard_bit = mul_product[2];
            round_bit = mul_product[1];
            sticky_bit = mul_product[0] | mul_round_loss;
        end
        else begin
            mul_frac_normalized = mul_product[11:2];
            guard_bit = mul_product[1];
            round_bit = mul_product[0];
            sticky_bit = mul_round_loss;
        end
    end

    // Rounding
    logic round_up;
    logic [10:0] mul_significand_rounded;
    assign round_up = guard_bit & (round_bit | sticky_bit | mul_frac_normalized[0]);
    assign mul_significand_rounded = {1'b0, mul_frac_normalized} + {10'b0, round_up};

    // Overflow/Underflow
    logic exp_overflow, exp_underflow, boundary_case;
    assign exp_overflow = exp_ovf | (~exp_unf & mul_significand_rounded[10] & (exp_sum == 5'd30));
    assign boundary_case = exp_unf & (exp_sum == 5'd0) & mul_significand_rounded[10];
    assign exp_underflow = exp_unf & ~boundary_case;

    // Final exponent
    logic [4:0] mul_final_exp;
    logic mul_product_valid;
    assign mul_product_valid = (mul_product != 13'b0) | mul_carryout;
    always_comb begin
        if (~mul_product_valid)
            mul_final_exp = 5'b0;
        else if (boundary_case)
            mul_final_exp = 5'd1;
        else
            mul_final_exp = mul_significand_rounded[10] ? exp_sum + 5'd1 : exp_sum;
    end

    // FTZ check
    logic result_is_subnormal;
    assign result_is_subnormal = ~exp_overflow & ~exp_underflow & mul_product_valid & 
                                  (mul_final_exp == 5'b0) & (mul_significand_rounded[9:0] != 10'b0);

    // Output mux
    logic has_special_case;
    logic [15:0] special_result;
    
    assign has_special_case = any_nan_r1 | inf_times_zero_r1 | any_inf_r1 | any_zero_r1 | 
                              exp_overflow | exp_underflow | result_is_subnormal;
    
    always_comb begin
        if (any_nan_r1 | inf_times_zero_r1)
            special_result = 16'h7E00;
        else if (any_inf_r1)
            special_result = {mul_sign_r1, 5'h1F, 10'b0};
        else if (any_zero_r1 | exp_overflow)
            special_result = {mul_sign_r1, any_zero_r1 ? 15'b0 : {5'h1F, 10'b0}};
        else
            special_result = {mul_sign_r1, 15'b0};
    end
    
    // Combinational output (no output register)
    assign result = has_special_case ? special_result : 
                    {mul_sign_r1, mul_final_exp, mul_significand_rounded[9:0]};
    assign done = wtm_ready;

endmodule
