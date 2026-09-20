`timescale 1ps/1ps

// Parameterizable FP Combinational Adder with FTZ/DAZ mode FOR MAC
// og by Vinay modified by Myles
// This is the core computation module - no input latching or stall logic.
//
// Parameters:
//   MANT_W - mantissa width (default 10 for FP16)
//   EXP_W  - exponent width (default 5 for FP16)

module add_fp16_1c #(
    parameter MANT_W = 10,
    parameter EXP_W = 5,
    localparam FP_W = 1 + EXP_W + MANT_W,
    localparam GUARD = 2,
    localparam FRAC_W = 1 + MANT_W + GUARD,
    localparam SUM_W = FRAC_W + 1,
    localparam NORM_SHIFT_W = $clog2(FRAC_W) + 1
) (
    input logic clk,
    input logic nRST,
    input logic sub, // 1 for sub, 0 for add
    input logic [FP_W-1:0] fp1_in,
    input logic [FP_W-1:0] fp2_in,
    output logic [FP_W-1:0] fp_out
);

// DAZ: Flush subnormal inputs to signed zero at the very front
// For subtraction, negate fp2_in by flipping its sign bit
logic [FP_W-1:0] a, b;
always_comb begin : daz_flush
    a = fp1_in;
    b = sub ? {~fp2_in[FP_W-1], fp2_in[FP_W-2:0]} : fp2_in;

    // DAZ: exp==0 and mant!=0 -> +-0 (keep sign)
    if ((a[FP_W-2:MANT_W] == '0) && (a[MANT_W-1:0] != '0)) a[FP_W-2:0] = '0;
    if ((b[FP_W-2:MANT_W] == '0) && (b[MANT_W-1:0] != '0)) b[FP_W-2:0] = '0;
end

// Special case detection
logic is_nan_a, is_nan_b, is_inf_a, is_inf_b;
logic special_case;
logic [FP_W-1:0] special_result;

localparam [EXP_W-1:0] EXP_ALL_ONES = {EXP_W{1'b1}};
localparam [FP_W-1:0] CANONICAL_NAN = {1'b0, EXP_ALL_ONES, 1'b1, {(MANT_W-1){1'b0}}};

always_comb begin : special_case_detect
    special_case = 1'b0;
    special_result = '0;

    is_nan_a = (a[FP_W-2:MANT_W] == EXP_ALL_ONES) && (a[MANT_W-1:0] != '0);
    is_nan_b = (b[FP_W-2:MANT_W] == EXP_ALL_ONES) && (b[MANT_W-1:0] != '0);

    is_inf_a = (a[FP_W-2:MANT_W] == EXP_ALL_ONES) && (a[MANT_W-1:0] == '0);
    is_inf_b = (b[FP_W-2:MANT_W] == EXP_ALL_ONES) && (b[MANT_W-1:0] == '0);

    if (is_nan_a || is_nan_b) begin
        special_case = 1'b1;
        special_result = CANONICAL_NAN;
    end
    else if (is_inf_a && is_inf_b) begin
        if (a[FP_W-1] == b[FP_W-1]) begin
            special_case = 1'b1;
            special_result = a;
        end
        else begin
            special_case = 1'b1;
            special_result = CANONICAL_NAN;
        end
    end
    else if (is_inf_a) begin
        special_case = 1'b1;
        special_result = a;
    end
    else if (is_inf_b) begin
        special_case = 1'b1;
        special_result = b;
    end
end

// step 1-3: Combined exponent compare, implicit bit, and alignment (single path)
logic op_swap;
logic [FP_W-1:0] high_op, low_op;
logic [EXP_W-1:0] high_exp, low_exp;
logic [FRAC_W-1:0] mant_hi, mant_lo;
logic [FRAC_W-1:0] mant_lo_aligned;
logic [FRAC_W-1:0] mask_align;
logic sticky_align_local;
logic sticky_lost;
logic [EXP_W-1:0] exp_diff, exp_max;
logic [FRAC_W-1:0] frac_shifted, frac_not_shifted;
logic sign_shifted, sign_not_shifted;

always_comb begin : align_operands
    op_swap = (a[FP_W-2:MANT_W] < b[FP_W-2:MANT_W]);
    high_op = op_swap ? b : a;
    low_op  = op_swap ? a : b;

    high_exp = high_op[FP_W-2:MANT_W];
    low_exp  = low_op[FP_W-2:MANT_W];

    exp_diff = high_exp - low_exp;
    exp_max  = high_exp;

    mant_hi = {(|high_exp), high_op[MANT_W-1:0], {GUARD{1'b0}}};
    mant_lo = {(|low_exp),  low_op[MANT_W-1:0],  {GUARD{1'b0}}};

    mant_lo_aligned = '0;
    sticky_align_local = 1'b0;
    sticky_lost = 1'b0;
    mask_align = '0;

    if (exp_diff >= FRAC_W[EXP_W-1:0]) begin
        mant_lo_aligned = '0;
        mant_lo_aligned[0] = |mant_lo;
        sticky_lost = 1'b0;
    end
    else if (exp_diff == '0) begin
        mant_lo_aligned = mant_lo;
        sticky_lost = 1'b0;
    end
    else begin
        mant_lo_aligned = mant_lo >> exp_diff;
        mask_align = ({{(FRAC_W-1){1'b0}}, 1'b1} << exp_diff) - {{(FRAC_W-1){1'b0}}, 1'b1};
        sticky_align_local = |(mant_lo & mask_align);
        sticky_lost = sticky_align_local & mant_lo_aligned[0];
        mant_lo_aligned[0] = mant_lo_aligned[0] | sticky_align_local;
    end

    frac_not_shifted = mant_hi;
    frac_shifted = mant_lo_aligned;
    sign_not_shifted = high_op[FP_W-1];
    sign_shifted = low_op[FP_W-1];
end

// step 4: Add mantissae
logic [FRAC_W-1:0] smaller_mantissa, larger_mantissa;
logic [SUM_W-1:0] mantissa_sum;
logic larger_mantissa_sign;
logic result_sign, signs_differ, mantissa_overflow;
logic sub_has_lost_sticky;
logic sub_has_added_sticky;

always_comb begin : mantissa_compare
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

    signs_differ = sign_shifted ^ sign_not_shifted;
end

always_comb begin : mantissa_add
    if (!signs_differ) begin
        mantissa_sum = smaller_mantissa + larger_mantissa;
        result_sign = sign_shifted & sign_not_shifted;
    end
    else begin
        mantissa_sum = larger_mantissa - smaller_mantissa;
        result_sign = larger_mantissa_sign;
    end

    mantissa_overflow = mantissa_sum[SUM_W-1];
end

// step 5: Re-normalization of mantissa sum
logic [FRAC_W-1:0] normalized_mantissa_sum;
logic [NORM_SHIFT_W-1:0] norm_shift;
left_shift #(
    .WIDTH(FRAC_W)
) normalizer (
    .fraction(mantissa_sum[FRAC_W-1:0]),
    .result(normalized_mantissa_sum),
    .shifted_amount(norm_shift)
);

// step 6: FTZ - Use signed exponent arithmetic to prevent wraparound
logic signed [EXP_W+1:0] exp_norm_s;

always_comb begin : exp_adjust
    if (normalized_mantissa_sum == '0)
        exp_norm_s = '0;
    else
        exp_norm_s = $signed({{2{1'b0}}, exp_max}) - $signed({{(EXP_W+2-NORM_SHIFT_W){1'b0}}, norm_shift});
end

// step 7: Rounding with FTZ underflow detection
localparam ROUND_W = MANT_W + 2;
logic [ROUND_W-1:0] round_this;
logic [EXP_W:0] exp_base;
logic ftz_under;

always_comb begin : rounding_prep
    if (mantissa_overflow == 1) begin
        round_this = mantissa_sum[FRAC_W-1:1];
        round_this[0] = round_this[0] | mantissa_sum[0];
        exp_base   = exp_max + 1;
        ftz_under  = 1'b0;
    end else begin
        round_this = normalized_mantissa_sum[FRAC_W-2:0];
        if (exp_norm_s <= 0) begin
            exp_base  = '0;
            ftz_under = 1'b1;
        end else begin
            exp_base  = exp_norm_s[EXP_W:0];
            ftz_under = 1'b0;
        end
    end
end

// Rounding with sticky bits and carry handling
logic round_inc;
logic [MANT_W:0] frac_sum;
logic frac_carry;
logic [EXP_W:0] exp_out;
logic [MANT_W-1:0] rounded_fraction;

always_comb begin : rounding_logic
    if (signs_differ && sub_has_lost_sticky && round_this[1] && !round_this[0]) begin
        round_inc = 1'b0;
    end
    else if (signs_differ && sub_has_added_sticky && round_this[1] && !round_this[0]) begin
        round_inc = 1'b1;
    end
    else begin
        round_inc = round_this[1] & (round_this[0] | round_this[2]);
    end

    frac_sum = {1'b0, round_this[ROUND_W-1:2]} + {{MANT_W{1'b0}}, round_inc};
    frac_carry = frac_sum[MANT_W];
    exp_out = exp_base + {{EXP_W{1'b0}}, frac_carry};
    rounded_fraction = frac_carry ? '0 : frac_sum[MANT_W-1:0];
end

// Final output with FTZ and overflow handling
localparam [EXP_W-1:0] EXP_MAX_VAL = EXP_ALL_ONES - 1;
logic overflow;
logic [EXP_W-1:0] exp_out_final;
logic [MANT_W-1:0] rounded_fraction_final;

always_comb begin : overflow_check
    overflow = (exp_out > {{1'b0}, EXP_MAX_VAL});

    if (overflow) begin
        exp_out_final = EXP_ALL_ONES;
        rounded_fraction_final = '0;
    end else begin
        exp_out_final = exp_out[EXP_W-1:0];
        rounded_fraction_final = rounded_fraction;
    end
end

logic [FP_W - 1:0] fp_out_comb;

// Apply FTZ and handle exact cancellation
always_comb begin : final_output
    if (special_case) begin
        fp_out_comb = special_result;
    end else if (mantissa_sum == '0) begin
        fp_out_comb = {result_sign, {(FP_W-1){1'b0}}};
    end else if (ftz_under) begin
        fp_out_comb = {result_sign, {(FP_W-1){1'b0}}};
    end else begin
        fp_out_comb = {result_sign, exp_out_final, rounded_fraction_final};
    end
end

// Output latch
always_ff @(posedge clk, negedge nRST) begin
    if (~nRST) begin
        fp_out <= '0;
    end else begin
        fp_out <= fp_out_comb;
    end
end

endmodule
