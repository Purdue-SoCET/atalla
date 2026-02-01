`timescale 1ps/1ps

// FP16 Adder with FTZ/DAZ mode
// og by Vinay modified by Myles

module add_fp16 (
    input logic clk,
    input logic nRST,
    input logic start,
    input logic stall,
    input logic sub,              // 1 for subtraction, 0 for addition
    input logic [15:0] fp1_in,
    input logic [15:0] fp2_in,
    output logic [15:0] fp_out,
    output logic done
);

// DAZ: Flush subnormal inputs to signed zero at the very front
// For subtraction, negate fp2_in by flipping its sign bit
logic [15:0] a, b;
always_comb begin : daz_flush
    a = fp1_in;
    b = sub ? {~fp2_in[15], fp2_in[14:0]} : fp2_in;  // Flip sign for subtraction
    
    // DAZ: exp==0 and mant!=0 -> +-0 (keep sign)
    if ((a[14:10] == 5'd0) && (a[9:0] != 10'd0)) a[14:0] = 15'd0;
    if ((b[14:10] == 5'd0) && (b[9:0] != 10'd0)) b[14:0] = 15'd0;
end

// Special case detection
logic is_nan_a, is_nan_b, is_inf_a, is_inf_b;
logic special_case;
logic [15:0] special_result;

always_comb begin : special_case_detect
    special_case = 1'b0;
    special_result = 16'h0000;
    
    // NaN: exponent = 0x1F, mantissa != 0
    is_nan_a = (a[14:10] == 5'b11111) && (a[9:0] != 10'b0);
    is_nan_b = (b[14:10] == 5'b11111) && (b[9:0] != 10'b0);
    
    // Infinity: exponent = 0x1F, mantissa = 0
    is_inf_a = (a[14:10] == 5'b11111) && (a[9:0] == 10'b0);
    is_inf_b = (b[14:10] == 5'b11111) && (b[9:0] == 10'b0);
    
    // Determine special cases
    if (is_nan_a || is_nan_b) begin
        // NaN propagation - use canonical qNaN (same as adder now)
        special_case = 1'b1;
        special_result = 16'h7E00;  // Canonical positive quiet NaN
    end
    else if (is_inf_a && is_inf_b) begin
        if (a[15] == b[15]) begin
            // Same sign: Inf + Inf = Inf (same sign)
            special_case = 1'b1;
            special_result = a;  // Both are same, return either
        end
        else begin
            // Different signs: Inf - Inf = NaN
            special_case = 1'b1;
            special_result = 16'h7E00;  // canonical NaN
        end
    end
    else if (is_inf_a) begin
        // a is Inf, b is finite: result is Inf with sign of a
        special_case = 1'b1;
        special_result = a;
    end
    else if (is_inf_b) begin
        // b is Inf, a is finite: result is Inf with sign of b
        special_case = 1'b1;
        special_result = b;
    end
end

// step 1-3: Combined exponent compare, implicit bit, and alignment (single path)
logic op_swap;
logic [15:0] high_op, low_op;
logic [4:0] high_exp, low_exp;
logic [12:0] mant_hi, mant_lo;
logic [12:0] mant_lo_aligned;
logic sticky_align_local;
logic sticky_lost;  // True if sticky bits exist but weren't added (bit0 was already 1)
logic [4:0] exp_diff, exp_max;
logic [12:0] frac_shifted, frac_not_shifted;
logic sign_shifted, sign_not_shifted;

always_comb begin : align_operands
    // Pick operand with larger exponent as "high"
    op_swap = (a[14:10] < b[14:10]);
    high_op = op_swap ? b : a;
    low_op  = op_swap ? a : b;
    
    high_exp = high_op[14:10];
    low_exp  = low_op[14:10];
    
    exp_diff = high_exp - low_exp;
    exp_max  = high_exp;
    
    // Build mantissas with implicit bit (DAZ already handled upstream)
    mant_hi = {(|high_exp), high_op[9:0], 2'b00};
    mant_lo = {(|low_exp), low_op[9:0], 2'b00};
    
    // Align low mantissa with sticky injected into bit0
    mant_lo_aligned = 13'd0;
    sticky_align_local = 1'b0;
    sticky_lost = 1'b0;
    
    // Optimization C: Use shift-left-then-reduce for sticky (no subtract, no AND plane)
    if (exp_diff >= 5'd13) begin
        mant_lo_aligned = 13'd0;
        mant_lo_aligned[0] = |mant_lo;
        sticky_align_local = |mant_lo;
        sticky_lost = 1'b0;  // All bits go to sticky, nothing lost
    end
    else if (exp_diff == 5'd0) begin
        mant_lo_aligned = mant_lo;
        sticky_align_local = 1'b0;
        sticky_lost = 1'b0;
    end
    else begin
        mant_lo_aligned = mant_lo >> exp_diff;
        // Fast sticky: shift left to isolate bits that will be lost, then reduce
        sticky_align_local = |(mant_lo << (5'd13 - exp_diff));
        // Track if sticky bits exist but bit0 was already 1 (so OR doesn't add them)
        sticky_lost = sticky_align_local & mant_lo_aligned[0];
        mant_lo_aligned[0] = mant_lo_aligned[0] | sticky_align_local;
    end
    
    // Map to existing signal names for downstream compatibility
    frac_not_shifted = mant_hi;
    frac_shifted = mant_lo_aligned;
    sign_not_shifted = high_op[15];
    sign_shifted = low_op[15];
end

// step 4: Add mantissae
// Optimization B: Skip magnitude compare when signs are the same
logic [12:0] smaller_mantissa, larger_mantissa;
logic [13:0] mantissa_sum;
logic larger_mantissa_sign;
logic result_sign, signs_differ, mantissa_overflow;
logic sub_has_lost_sticky;  // True if subtrahend has lost sticky bits (result is too large)
logic sub_has_added_sticky; // True if subtrahend has added sticky bit (result is too small)

always_comb begin : mantissa_compare
    signs_differ = sign_shifted ^ sign_not_shifted;
    
    if (!signs_differ) begin
        // same sign: no magnitude compare needed, just add in aligned order
        larger_mantissa = frac_not_shifted;   // mant_hi (higher exponent)
        smaller_mantissa = frac_shifted;      // aligned low
        larger_mantissa_sign = sign_not_shifted;
        sub_has_lost_sticky = 1'b0;
        sub_has_added_sticky = 1'b0;
    end
    else begin
        // diff signs: must compare magnitudes for subtraction
        if (frac_shifted > frac_not_shifted) begin
            smaller_mantissa = frac_not_shifted;
            larger_mantissa = frac_shifted;
            larger_mantissa_sign = sign_shifted;
            sub_has_lost_sticky = 1'b0;
            sub_has_added_sticky = 1'b0;
        end
        else begin
            smaller_mantissa = frac_shifted;
            larger_mantissa = frac_not_shifted;
            larger_mantissa_sign = sign_not_shifted;
            sub_has_lost_sticky = sticky_lost;
            sub_has_added_sticky = sticky_align_local & ~sticky_lost;
        end
    end
end

// register values here, before addition
logic [12:0] smaller_mantissa_l, larger_mantissa_l;
logic larger_mantissa_sign_l, sign_shifted_l, sign_not_shifted_l, signs_differ_l;
logic [4:0] exp_max_l;
logic special_case_l;
logic [15:0] special_result_l;
logic sub_has_lost_sticky_l;  // Latched: subtrahend has lost sticky (result too large)
logic sub_has_added_sticky_l; // Latched: subtrahend has added sticky (result too small)
logic start_l;  // Latched start for done pulse generation

always_ff @(posedge clk, negedge nRST) begin : pipeline_reg
    if (nRST == 1'b0) begin
        smaller_mantissa_l <= 0;
        larger_mantissa_l <= 0;
        exp_max_l <= 0;
        larger_mantissa_sign_l <= 0;
        signs_differ_l <= 0;
        sign_shifted_l <= 0;
        sign_not_shifted_l <= 0;
        special_case_l <= 0;
        special_result_l <= 0;
        sub_has_lost_sticky_l <= 0;
        sub_has_added_sticky_l <= 0;
        start_l <= 0;
    end
    else begin
        if (stall) begin
            smaller_mantissa_l <= smaller_mantissa_l;
            larger_mantissa_l <= larger_mantissa_l;
            exp_max_l <= exp_max_l;
            larger_mantissa_sign_l <= larger_mantissa_sign_l;
            signs_differ_l <= signs_differ_l;
            sign_shifted_l <= sign_shifted_l;
            sign_not_shifted_l <= sign_not_shifted_l;
            special_case_l <= special_case_l;
            special_result_l <= special_result_l;
            sub_has_lost_sticky_l <= sub_has_lost_sticky_l;
            sub_has_added_sticky_l <= sub_has_added_sticky_l;
            start_l <= start_l;
        end
        else begin
            smaller_mantissa_l <= smaller_mantissa;
            larger_mantissa_l <= larger_mantissa;
            exp_max_l <= exp_max;
            larger_mantissa_sign_l <= larger_mantissa_sign;
            signs_differ_l <= signs_differ;
            sign_shifted_l <= sign_shifted;
            sign_not_shifted_l <= sign_not_shifted;
            special_case_l <= special_case;
            special_result_l <= special_result;
            sub_has_lost_sticky_l <= sub_has_lost_sticky;
            sub_has_added_sticky_l <= sub_has_added_sticky;
            start_l <= start;
        end
    end
end

// done is a 1-cycle pulse now
assign done = start_l & ~stall;

always_comb begin : mantissa_add
    if (!signs_differ_l) begin
        mantissa_sum = smaller_mantissa_l + larger_mantissa_l;
        result_sign = sign_shifted_l & sign_not_shifted_l;
    end
    else begin
        mantissa_sum = larger_mantissa_l - smaller_mantissa_l;
        result_sign = larger_mantissa_sign_l;
    end

    mantissa_overflow = mantissa_sum[13];
end

// step 5: Re-normalization of mantissa sum
logic [12:0] normalized_mantissa_sum;
logic [3:0] norm_shift;
left_shift normalizer (
    .fraction(mantissa_sum[12:0]),
    .result(normalized_mantissa_sum),
    .shifted_amount(norm_shift)
);


// step 6: FTZ - Use signed exponent arithmetic to prevent wraparound
logic signed [6:0] exp_norm_s;

always_comb begin : exp_adjust
    if (normalized_mantissa_sum == 13'd0) 
        exp_norm_s = 7'sd0;
    else 
        exp_norm_s = $signed({1'b0, exp_max_l}) - $signed({3'b0, norm_shift});
end


// step 7: Rounding with FTZ underflow detection
logic [11:0] round_this;
logic [5:0] exp_base;
logic ftz_under;

always_comb begin : rounding_prep
    if (mantissa_overflow == 1) begin
        round_this = mantissa_sum[12:1];
        round_this[0] = round_this[0] | mantissa_sum[0];
        exp_base   = exp_max_l + 1;
        ftz_under  = 1'b0;
    end else begin
        round_this = normalized_mantissa_sum[11:0];
        if (exp_norm_s <= 7'sd0) begin
            exp_base  = 6'd0;
            ftz_under = 1'b1;
        end else begin
            exp_base  = exp_norm_s[5:0];
            ftz_under = 1'b0;
        end
    end
end

// Rounding with sticky bits and carry handling (edge cases)
// For subtraction with sticky handling:
// - sub_has_lost_sticky: result is TOO LARGE, true is below computed so round DOWN
// - sub_has_added_sticky: result is TOO SMALL, true is above computed so round UP

// Optimization A: Fast carry detection using AND-tree instead of ripple carry
// This removes the LSB->MSB carry dependency from the exponent path
logic round_inc;
logic [9:0] frac_pre;
logic [9:0] frac_inc;
logic frac_carry_fast;
logic [5:0] exp_out;
logic [9:0] rounded_fraction;

always_comb begin : rounding_logic
    if (signs_differ_l && sub_has_lost_sticky_l && round_this[1] && !round_this[0]) begin
        // Subtraction case: guard=1, sticky=0, but subtrahend had lost sticky
        // True result is below computed (result is too large), so don't round up
        round_inc = 1'b0;
    end
    else if (signs_differ_l && sub_has_added_sticky_l && round_this[1] && !round_this[0]) begin
        // Subtraction case: guard=1, sticky=0, but subtrahend had added sticky
        // True result is above computed (result is too small), so force round up
        round_inc = 1'b1;
    end
    else begin
        // Normal rounding: round to nearest even
        round_inc = round_this[1] & (round_this[0] | round_this[2]);
    end
    
    frac_pre = round_this[11:2];
    
    // Fast carry: carry out of +1 happens iff all bits are 1 and we increment
    frac_carry_fast = round_inc & (&frac_pre);
    
    // Fraction still uses incrementer, but exponent no longer depends on carry chain
    frac_inc = frac_pre + {9'b0, round_inc};
    
    exp_out = exp_base + {5'd0, frac_carry_fast};
    rounded_fraction = frac_carry_fast ? 10'd0 : frac_inc;
end

// Final output with FTZ and overflow handling
logic overflow;
logic [4:0] exp_out_final;
logic [9:0] rounded_fraction_final;

always_comb begin : overflow_check
    overflow = (exp_out > 6'd30);
    
    if (overflow) begin
        exp_out_final = 5'b11111;
        rounded_fraction_final = 10'b0;
    end else begin
        exp_out_final = exp_out[4:0];
        rounded_fraction_final = rounded_fraction;
    end
end

// Apply FTZ and handle exact cancellation
always_comb begin : final_output
    if (special_case_l) begin
        fp_out = special_result_l;
    end else if (mantissa_sum == 14'd0) begin
        fp_out = {result_sign, 15'd0};
    end else if (ftz_under) begin
        fp_out = {result_sign, 15'd0};
    end else begin
        fp_out = {result_sign, exp_out_final, rounded_fraction_final};
    end
end

endmodule
