`timescale 1ps/1ps
// FP16 Combinational Multiplier with DAZ/FTZ and special case handling
// core computation module - no input latching.
// Original - Vinay | Modified - Myles

module mul_fp16_1c (
    input logic clk,
    input logic nRST,
    input logic [15:0] a, b,
    output logic [15:0] result
);

    // Extract fields for readability
    logic [4:0] exp_a, exp_b;
    logic [9:0] mant_a, mant_b;
    assign exp_a = a[14:10];
    assign exp_b = b[14:10];
    assign mant_a = a[9:0];
    assign mant_b = b[9:0];

    // Step 0: Special value detection (for DAZ/FTZ and IEEE special cases)
    logic a_exp_zero, b_exp_zero;
    logic a_exp_max, b_exp_max;
    logic a_mant_zero, b_mant_zero;
    assign a_exp_zero = (exp_a == 5'b0);
    assign b_exp_zero = (exp_b == 5'b0);
    assign a_exp_max = (exp_a == 5'h1F);
    assign b_exp_max = (exp_b == 5'h1F);
    assign a_mant_zero = (mant_a == 10'b0);
    assign b_mant_zero = (mant_b == 10'b0);

    // Combined special value flags
    logic a_is_zero, b_is_zero;
    logic a_is_special, b_is_special;           // Inf or NaN (exp==31)
    logic any_nan, any_inf, any_zero;
    logic inf_times_zero;

    assign a_is_zero = a_exp_zero;              // DAZ: exp=0 means zero
    assign b_is_zero = b_exp_zero;
    assign a_is_special = a_exp_max;            // exp==31 means Inf or NaN
    assign b_is_special = b_exp_max;

    // Combine checks to reduce mux complexity
    assign any_nan = (a_is_special & ~a_mant_zero) | (b_is_special & ~b_mant_zero);
    assign any_inf = (a_is_special & a_mant_zero) | (b_is_special & b_mant_zero);
    assign any_zero = a_is_zero | b_is_zero;
    assign inf_times_zero = ((a_is_special & a_mant_zero) & b_is_zero) |
                            ((b_is_special & b_mant_zero) & a_is_zero);

    // Step 1: Multiply mantissa bits.

    // Step 1.1: determine the "implicit" leading bit of FP mantissa section
    // If the exponent bits are zero, the implicit bit is 0, else its 1.
    logic frac_leading_bit_fp1;
    logic frac_leading_bit_fp2;
    assign frac_leading_bit_fp1 = ~a_exp_zero;
    assign frac_leading_bit_fp2 = ~b_exp_zero;

    // Step 1.2: Multiply mantissae with wallace tree multiplier.
    logic [12:0] mul_product;
    logic mul_carryout;
    logic mul_round_loss;

    wallacetree_11b wallaca (
        .a({frac_leading_bit_fp1, a[9:0]}),
        .b({frac_leading_bit_fp2, b[9:0]}),
        .result(mul_product),
        .overflow(mul_carryout),
        .round_loss(mul_round_loss)
    );

    // Step 2: Exponent addition, result rounding. All combinational.

    // Step 2.1: calculate sign of result. Simple XOR
    logic mul_sign_result;
    assign mul_sign_result = a[15] ^ b[15];

    // Step 2.2: Add exponent bits, taking into account overflow from mantissa multiplication
    logic [4:0] exp_sum;
    logic exp_ovf, exp_unf;
    adder_5b add_EXPs (
        .carry(mul_carryout),
        .exp1 (a[14:10]),
        .exp2 (b[14:10]),
        .sum  (exp_sum),
        .ovf  (exp_ovf),
        .unf  (exp_unf)
    );

    // Step 2.3: Shift multiply product bits if an overflow occurred during mantissa multiplication
    // Also extract g/r.s bits for rounding
    logic [9:0] mul_frac_normalized;
    logic guard_bit, round_bit, sticky_bit;
    always_comb begin
        if(mul_carryout) begin
            // Product >= 2.0, shift right by 1
            mul_frac_normalized = mul_product[12:3];
            guard_bit = mul_product[2];
            round_bit = mul_product[1];
            sticky_bit = mul_product[0] | mul_round_loss;
        end
        else if (exp_unf && (exp_sum == 5'd0)) begin
            // Subnormal boundary: shift right 1 more for 0.1xxx format
            mul_frac_normalized = mul_product[12:3];
            guard_bit = mul_product[2];
            round_bit = mul_product[1];
            sticky_bit = mul_product[0] | mul_round_loss;
        end
        else begin
            // Product in [1.0, 2.0), no shift needed
            mul_frac_normalized = mul_product[11:2];
            guard_bit = mul_product[1];
            round_bit = mul_product[0];
            sticky_bit = mul_round_loss;
        end
    end

    // Step 2.4: Rounding (round to nearest, ties to even)
    logic round_up;
    logic [10:0] mul_significand_rounded;       // 11th bit will indicate overflow
    assign round_up = guard_bit & (round_bit | sticky_bit | mul_frac_normalized[0]);
    assign mul_significand_rounded = {1'b0, mul_frac_normalized} + {10'b0, round_up};

    // Step 2.5: Overflow/Underflow detection using adder_5b signals
    logic exp_overflow, exp_underflow;
    logic boundary_case;
    // Overflow: adder signals when result exp >= 31 (infinity)
    assign exp_overflow = exp_ovf | (~exp_unf & mul_significand_rounded[10] & (exp_sum == 5'd30));
    // Underflow: adder signals when result exp <= 0 (subnormal -> flush to zero)
    // Exception: if rounding overflow pushes exp from 0 to 1, it's valid (boundary_case)
    assign boundary_case = exp_unf & (exp_sum == 5'd0) & mul_significand_rounded[10];
    assign exp_underflow = exp_unf & ~boundary_case;

    // Step 2.6: Calculate final exponent
    logic [4:0] mul_final_exp;
    logic mul_product_valid;
    assign mul_product_valid = (mul_product != 13'b0) | mul_carryout;
    always_comb begin
        if(~mul_product_valid)
            mul_final_exp = 5'b0;
        else if(boundary_case)
            mul_final_exp = 5'd1;               // Rounding pushed result from subnormal to smallest normal
        else
            mul_final_exp = mul_significand_rounded[10] ? exp_sum + 5'd1 : exp_sum;
    end

    // Step 2.7: FTZ check - flush subnormal results to zero
    logic result_is_subnormal;
    assign result_is_subnormal = ~exp_overflow & ~exp_underflow & mul_product_valid &
                                  (mul_final_exp == 5'b0) & (mul_significand_rounded[9:0] != 10'b0);

    // Step 3: Output mux with special case handling (optimized)
    logic has_special_case;
    logic [15:0] special_result;

    assign has_special_case = any_nan | inf_times_zero | any_inf | any_zero |
                              exp_overflow | exp_underflow | result_is_subnormal;

    // Determine special case result
    always_comb begin
        if (any_nan | inf_times_zero)
            special_result = 16'h7E00;          // NaN or Inf*0 -> qNaN
        else if (any_inf)
            special_result = {mul_sign_result, 5'h1F, 10'b0};  // Inf * finite = Inf
        else if (any_zero | exp_overflow)
            special_result = {mul_sign_result, any_zero ? 15'b0 : {5'h1F, 10'b0}};  // Zero or Overflow->Inf
        else
            special_result = {mul_sign_result, 15'b0};  // Underflow/FTZ -> Zero
    end

    logic [15:0] result_comb;

    // Final 2-way mux instead of 7-way
    assign result_comb = has_special_case ? special_result :
                    {mul_sign_result, mul_final_exp, mul_significand_rounded[9:0]};

    always_ff @(posedge clk, negedge nRST) begin
        if (~nRST) begin
            result <= '0;
        end else begin
            result <= result_comb;
        end
    end

endmodule
