module add_fp_4input_stage3 #(
    parameter EXPONENT_SIZE = 5,
    parameter MANTISSA_SIZE = 10,
    parameter PRECISION_BITS = 3
) (
    input logic [$clog2(MANTISSA_SIZE)-1:0] leading_zeros,
    input logic [MANTISSA_SIZE+PRECISION_BITS-1:0] sum,
    input logic sign,
    input logic [EXPONENT_SIZE - 1:0] exponent,
    input logic special_case,
    input logic [EXPONENT_SIZE+MANTISSA_SIZE:0] special_result,
    output logic [EXPONENT_SIZE+MANTISSA_SIZE:0] final_sum,
);

    // N-bit left shifter and sticky bit reassign
    logic [MANTISSA_SIZE+PRECISION_BITS-1:0] shifted_sum; 

    // Sets the sticky bit to zero if it is shifted into the mantissa
    always_comb begin : reset_sticky
        shifted_sum = sum << leading_zeros; 
        shifted_sum[0] = leading_zeros >= PRECISION_BITS ? 1'b0 : sum[0];
    end

    // rounding using FTZ

    // internal mantissa has extra bit for overflow detection   
    logic overflow; 
    logic [MANTISSA_SIZE-1:0] unrounded_mantissa; 
    logic [MANTISSA_SIZE:0] rounded_mantissa_internal;

    logic guard, round, sticky; 

    assign unrounded_mantissa = shifted_sum[MANTISSA_SIZE+PRECISION_BITS-1:PRECISION_BITS];
    assign guard = shifted_sum[2];
    assign round = shifted_sum[1];
    assign sticky = shifted_sum[0];

    logic round_up;     

    // If the guard bit is 1 and any of the round bit, sticky bit, or LSB of unrounded mantissa is 1, that means were are more than halfway 
    // to the next value, so round up
    assign round_up = guard & (round | sticky | unrounded_mantissa[0]);
    assign rounded_mantissa_internal = unrounded_mantissa + round_up; 
    assign overflow = rounded_mantissa_internal[MANTISSA_SIZE];

    // Final mantissa assignment
    // If overflow occurs, mantissa is set to 0 (implicit leading 1 will be added in exponent adjustment)
    logic [MANTISSA_SIZE-1:0] final_mantissa;
    always_comb begin
        if (overflow) begin
            final_mantissa = {MANTISSA_SIZE{1'b0}};
        end
        else begin
            final_mantissa = rounded_mantissa_internal[MANTISSA_SIZE-1:0];
        end
    end

    // Exponent recalculation with extra 2 bits for overflow and underflow detection. Used signed numbers for easier calculations
    logic signed [EXPONENT_SIZE+1:0] new_exponent_internal; 
    logic [EXPONENT_SIZE-1:0] new_exponent;
    logic inf;

    // new_exponent = exponent + overflow - leading_zeros
    assign new_exponent_internal = $signed({2'b0, exponent}) + $signed({{(EXPONENT_SIZE+1){1'b0}}, overflow}) - $signed({2'b0, leading_zeros});
    
    // Handle special cases like overflow to infinity and underflow to zero
    always_comb begin
        inf = 0; 
        new_exponent = new_exponent_internal[EXPONENT_SIZE-1:0];
        if ($signed(new_exponent_internal) >= $signed({2'b0, {EXPONENT_SIZE{1'b1}}}) ) begin
            inf = 1'b1; 
            new_exponent = {EXPONENT_SIZE{1'b1}};
        end
        else if ($signed(new_exponent_internal) <= 0) begin
            new_exponent = {EXPONENT_SIZE{1'b0}}; 
        end
    end

    // Final sum assignment. Depends on infinity, zero/subnormal, or normal number
    always_comb begin : final_mux
        if (special_case) begin
            final_result = special_result; 
        end
        else if (inf) begin
            final_sum = {sign, new_exponent, {MANTISSA_SIZE{1'b0}}};
        end
        else if (new_exponent == {EXPONENT_SIZE{1'b0}}) begin
            final_sum = {sign,new_exponent, {MANTISSA_SIZE{1'b0}}};
        end
        else begin
            final_sum = {sign, new_exponent, final_mantissa};
        end
    end

endmodule