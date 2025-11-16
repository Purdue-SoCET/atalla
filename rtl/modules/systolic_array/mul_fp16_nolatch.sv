`timescale 1ns/1ps
// need to add description

module mul_fp16_nolatch(input logic [15:0] a, b, output logic [15:0] result);

    logic frac_leading_bit_fp1;
    logic frac_leading_bit_fp2;
    always_comb begin
        if(a[14:10] == 5'b0)begin
            frac_leading_bit_fp1 = 1'b0;
        end
        else begin
            frac_leading_bit_fp1 = 1'b1;
        end

        if(b[14:10] == 5'b0)begin
            frac_leading_bit_fp2 = 1'b0;
        end
        else begin
            frac_leading_bit_fp2 = 1'b1;
        end
    end

    // Step 1.2: Multiply mantissae.
    // With a wallace tree multiplier, this takes two clock cycles (contains one latch in it).
    logic mul_ready;
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


    // Step 2: Exponent addition, result rounding. All combinational, result is ready in this cycle.
    
    // step 2.1: calculate sign of result. Simple XOR
    logic mul_sign_result;
    assign mul_sign_result = a[15] ^ b[15];

    // Step 2.2: Add exponent bits, taking into account overflow from mantissa multiplication
    logic [4:0] exp_sum;
    logic mul_ovf, mul_unf;
    adder_5b add_EXPs (
        .carry(mul_carryout),
        .exp1 (a[14:10]),
        .exp2 (b[14:10]),
        .sum  (exp_sum),
        .ovf  (mul_ovf),
        .unf  (mul_unf)
    );

    // Step 2.3: Shift multiply product bits if an overflow occurred during mantissa multiplication (exponent was incremented, now divide mantissa by 2 to match)
    // logic [15:0] mul_result; 
               // this variable will hold the final multiplication result
    logic [11:0] mul_frac_product;
    assign mul_frac_product = mul_carryout ? mul_product[12:1] : mul_product[11:0];

    // Step 2.4: Rounding.
    // edit 11/02/25: Fixed this! this logic could potentially result in an edge case where if the mul significand is all 1's, rounding will cause it to become 0
    logic [10:0] mul_significand_rounded;       // 11th bit will indicate overflow.
    always_comb begin
        if(mul_frac_product[1] & (mul_frac_product[0] | mul_round_loss | mul_frac_product[2]))
            mul_significand_rounded = {1'b0, mul_frac_product[11:2]} + 1;
        else
            mul_significand_rounded = {1'b0, mul_frac_product[11:2]};

    end

    // Concatenation to produce final result.
    logic [4:0] mul_final_exp;
    // if significand rounding overflowed, increase the exponent
    assign mul_final_exp = (mul_product == 0) ? 0 : mul_significand_rounded[10] ? exp_sum + 1 : exp_sum;
    assign result = {mul_sign_result, mul_final_exp, mul_significand_rounded[9:0]};

endmodule
