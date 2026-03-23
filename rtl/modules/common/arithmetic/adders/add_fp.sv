`timescale 1ps/1ps
// Parameterizable FP Adder with FTZ/DAZ mode
// Original by Vinay, modified by Myles
//
// LATENCY parameter controls pipeline depth:
//   0: Purely combinational (no clock). Equivalent to old add_fp_1c.
//   1: Combinational core + 1 output register.
//   2: Pipeline reg between alignment/compare and add stages + output reg.
//      Equivalent to old add_fp. Supports start/stall/done.
//
// Parameters:
//   MANT_W  - mantissa width (default 10 for FP16)
//   EXP_W   - exponent width (default 5 for FP16)
//   LATENCY - pipeline depth (0, 1, or 2)
//
// Submodule: normalize_fp

module add_fp #(
    parameter MANT_W   = 10,
    parameter EXP_W    = 5,
    parameter LATENCY  = 0,
    localparam FP_W    = 1 + EXP_W + MANT_W,
    localparam GUARD   = 2,
    localparam FRAC_W  = 1 + MANT_W + GUARD,
    localparam SUM_W   = FRAC_W + 1,
    localparam NORM_SHIFT_W = $clog2(FRAC_W) + 1
) (
    input  logic             clk,    // unused when LATENCY=0
    input  logic             nRST,   // unused when LATENCY=0
    input  logic             start,  // unused when LATENCY<2
    input  logic             stall,  // unused when LATENCY<2
    input  logic             sub,    // 1 for sub, 0 for add
    input  logic [FP_W-1:0]  fp1_in,
    input  logic [FP_W-1:0]  fp2_in,
    output logic [FP_W-1:0]  fp_out,
    output logic             done    // unused when LATENCY<2
);

    logic [FP_W-1:0] fp_out_comb;

    // DAZ: Flush subnormal inputs to signed zero
    // For subtraction, negate fp2_in by flipping its sign bit
    logic [FP_W-1:0] a, b;
    always_comb begin : daz_flush
        a = fp1_in;
        b = sub ? {~fp2_in[FP_W-1], fp2_in[FP_W-2:0]} : fp2_in;

        if ((a[FP_W-2:MANT_W] == '0) && (a[MANT_W-1:0] != '0)) a[FP_W-2:0] = '0;
        if ((b[FP_W-2:MANT_W] == '0) && (b[MANT_W-1:0] != '0)) b[FP_W-2:0] = '0;
    end

    // Special case detection
    logic is_nan_a, is_nan_b, is_inf_a, is_inf_b;
    logic special_case;
    logic [FP_W-1:0] special_result;

    localparam [EXP_W-1:0] EXP_ALL_ONES = {EXP_W{1'b1}};
    localparam [FP_W-1:0]  CANONICAL_NAN = {1'b0, EXP_ALL_ONES, 1'b1, {(MANT_W-1){1'b0}}};

    always_comb begin : special_case_detect
        special_case   = 1'b0;
        special_result = '0;

        is_nan_a = (a[FP_W-2:MANT_W] == EXP_ALL_ONES) && (a[MANT_W-1:0] != '0);
        is_nan_b = (b[FP_W-2:MANT_W] == EXP_ALL_ONES) && (b[MANT_W-1:0] != '0);
        is_inf_a = (a[FP_W-2:MANT_W] == EXP_ALL_ONES) && (a[MANT_W-1:0] == '0);
        is_inf_b = (b[FP_W-2:MANT_W] == EXP_ALL_ONES) && (b[MANT_W-1:0] == '0);

        if (is_nan_a || is_nan_b) begin
            special_case   = 1'b1;
            special_result = CANONICAL_NAN;
        end
        else if (is_inf_a && is_inf_b) begin
            if (a[FP_W-1] == b[FP_W-1]) begin
                special_case   = 1'b1;
                special_result = a;
            end else begin
                special_case   = 1'b1;
                special_result = CANONICAL_NAN;
            end
        end
        else if (is_inf_a) begin
            special_case   = 1'b1;
            special_result = a;
        end
        else if (is_inf_b) begin
            special_case   = 1'b1;
            special_result = b;
        end
    end

    // Steps 1-3: Exponent compare, implicit bit, alignment
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

        mant_lo_aligned    = '0;
        sticky_align_local = 1'b0;
        sticky_lost        = 1'b0;
        mask_align         = '0;

        if (exp_diff >= FRAC_W[EXP_W-1:0]) begin
            mant_lo_aligned    = '0;
            mant_lo_aligned[0] = |mant_lo;
            sticky_lost        = 1'b0;
        end
        else if (exp_diff == '0) begin
            mant_lo_aligned = mant_lo;
            sticky_lost     = 1'b0;
        end
        else begin
            mant_lo_aligned    = mant_lo >> exp_diff;
            mask_align         = ({{(FRAC_W-1){1'b0}}, 1'b1} << exp_diff) - {{(FRAC_W-1){1'b0}}, 1'b1};
            sticky_align_local = |(mant_lo & mask_align);
            sticky_lost        = sticky_align_local & mant_lo_aligned[0];
            mant_lo_aligned[0] = mant_lo_aligned[0] | sticky_align_local;
        end

        frac_not_shifted = mant_hi;
        frac_shifted     = mant_lo_aligned;
        sign_not_shifted = high_op[FP_W-1];
        sign_shifted     = low_op[FP_W-1];
    end

    // Step 4a: Mantissa magnitude compare
    logic [FRAC_W-1:0] smaller_mantissa, larger_mantissa;
    logic larger_mantissa_sign;
    logic signs_differ;
    logic sub_has_lost_sticky;
    logic sub_has_added_sticky;

    always_comb begin : mantissa_compare
        if (frac_shifted > frac_not_shifted) begin
            smaller_mantissa    = frac_not_shifted;
            larger_mantissa     = frac_shifted;
            larger_mantissa_sign = sign_shifted;
            sub_has_lost_sticky = 1'b0;
            sub_has_added_sticky = 1'b0;
        end
        else begin
            smaller_mantissa    = frac_shifted;
            larger_mantissa     = frac_not_shifted;
            larger_mantissa_sign = sign_not_shifted;
            sub_has_lost_sticky = sticky_lost;
            sub_has_added_sticky = sticky_align_local & ~sticky_lost;
        end

        signs_differ = sign_shifted ^ sign_not_shifted;
    end

    // Pipeline register (LATENCY=2 only)
    // For LATENCY 0/1 these are pass-through wires.
    logic [FRAC_W-1:0]  smaller_mantissa_q, larger_mantissa_q;
    logic                larger_mantissa_sign_q, sign_shifted_q, sign_not_shifted_q, signs_differ_q;
    logic [EXP_W-1:0]   exp_max_q;
    logic                special_case_q;
    logic [FP_W-1:0]    special_result_q;
    logic                sub_has_lost_sticky_q;
    logic                sub_has_added_sticky_q;
    logic                start_q;

    generate
        if (LATENCY <= 1) begin : gen_pipe_comb
            assign smaller_mantissa_q     = smaller_mantissa;
            assign larger_mantissa_q      = larger_mantissa;
            assign exp_max_q              = exp_max;
            assign larger_mantissa_sign_q = larger_mantissa_sign;
            assign signs_differ_q         = signs_differ;
            assign sign_shifted_q         = sign_shifted;
            assign sign_not_shifted_q     = sign_not_shifted;
            assign special_case_q         = special_case;
            assign special_result_q       = special_result;
            assign sub_has_lost_sticky_q  = sub_has_lost_sticky;
            assign sub_has_added_sticky_q = sub_has_added_sticky;
            assign start_q               = start;
        end
        else begin : gen_pipe_reg
            always_ff @(posedge clk, negedge nRST) begin : pipeline_reg
                if (nRST == 1'b0) begin
                    smaller_mantissa_q     <= '0;
                    larger_mantissa_q      <= '0;
                    exp_max_q              <= '0;
                    larger_mantissa_sign_q <= '0;
                    signs_differ_q         <= '0;
                    sign_shifted_q         <= '0;
                    sign_not_shifted_q     <= '0;
                    special_case_q         <= '0;
                    special_result_q       <= '0;
                    sub_has_lost_sticky_q  <= '0;
                    sub_has_added_sticky_q <= '0;
                    start_q                <= '0;
                end
                else if (stall) begin
                    smaller_mantissa_q     <= smaller_mantissa_q;
                    larger_mantissa_q      <= larger_mantissa_q;
                    exp_max_q              <= exp_max_q;
                    larger_mantissa_sign_q <= larger_mantissa_sign_q;
                    signs_differ_q         <= signs_differ_q;
                    sign_shifted_q         <= sign_shifted_q;
                    sign_not_shifted_q     <= sign_not_shifted_q;
                    special_case_q         <= special_case_q;
                    special_result_q       <= special_result_q;
                    sub_has_lost_sticky_q  <= sub_has_lost_sticky_q;
                    sub_has_added_sticky_q <= sub_has_added_sticky_q;
                    start_q                <= start_q;
                end
                else begin
                    smaller_mantissa_q     <= smaller_mantissa;
                    larger_mantissa_q      <= larger_mantissa;
                    exp_max_q              <= exp_max;
                    larger_mantissa_sign_q <= larger_mantissa_sign;
                    signs_differ_q         <= signs_differ;
                    sign_shifted_q         <= sign_shifted;
                    sign_not_shifted_q     <= sign_not_shifted;
                    special_case_q         <= special_case;
                    special_result_q       <= special_result;
                    sub_has_lost_sticky_q  <= sub_has_lost_sticky;
                    sub_has_added_sticky_q <= sub_has_added_sticky;
                    start_q                <= start;
                end
            end
        end
    endgenerate

    // Step 4b: Mantissa add/sub
    logic [SUM_W-1:0] mantissa_sum;
    logic result_sign, mantissa_overflow;

    always_comb begin : mantissa_add
        if (!signs_differ_q) begin
            mantissa_sum = smaller_mantissa_q + larger_mantissa_q;
            result_sign  = sign_shifted_q & sign_not_shifted_q;
        end
        else begin
            mantissa_sum = larger_mantissa_q - smaller_mantissa_q;
            result_sign  = larger_mantissa_sign_q;
        end

        mantissa_overflow = mantissa_sum[SUM_W-1];
    end

    // Step 5: Re-normalization
    logic [FRAC_W-1:0] normalized_mantissa_sum;
    logic [NORM_SHIFT_W-1:0] norm_shift;

    normalize_fp #(
        .WIDTH(FRAC_W)
    ) normalizer (
        .fraction(mantissa_sum[FRAC_W-1:0]),
        .result(normalized_mantissa_sum),
        .shifted_amount(norm_shift)
    );

    // Step 6: FTZ - signed exponent arithmetic
    logic signed [EXP_W+1:0] exp_norm_s;

    always_comb begin : exp_adjust
        if (normalized_mantissa_sum == '0)
            exp_norm_s = '0;
        else
            exp_norm_s = $signed({{2{1'b0}}, exp_max_q}) - $signed({{(EXP_W+2-NORM_SHIFT_W){1'b0}}, norm_shift});
    end

    // Step 7: Rounding with FTZ underflow detection
    localparam ROUND_W = MANT_W + 2;
    logic [ROUND_W-1:0] round_this;
    logic [EXP_W:0] exp_base;
    logic ftz_under;

    always_comb begin : rounding_prep
        if (mantissa_overflow == 1) begin
            round_this    = mantissa_sum[FRAC_W-1:1];
            round_this[0] = round_this[0] | mantissa_sum[0];
            exp_base      = exp_max_q + 1;
            ftz_under     = 1'b0;
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
        if (signs_differ_q && sub_has_lost_sticky_q && round_this[1] && !round_this[0]) begin
            round_inc = 1'b0;
        end
        else if (signs_differ_q && sub_has_added_sticky_q && round_this[1] && !round_this[0]) begin
            round_inc = 1'b1;
        end
        else begin
            // Normal rounding: round to nearest even
            round_inc = round_this[1] & (round_this[0] | round_this[2]);
        end

        frac_sum         = {1'b0, round_this[ROUND_W-1:2]} + {{MANT_W{1'b0}}, round_inc};
        frac_carry       = frac_sum[MANT_W];
        exp_out          = exp_base + {{EXP_W{1'b0}}, frac_carry};
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
            exp_out_final         = EXP_ALL_ONES;
            rounded_fraction_final = '0;
        end else begin
            exp_out_final         = exp_out[EXP_W-1:0];
            rounded_fraction_final = rounded_fraction;
        end
    end

    // Apply FTZ and handle exact cancellation
    always_comb begin : final_output
        if (special_case_q) begin
            fp_out_comb = special_result_q;
        end else if (mantissa_sum == '0) begin
            fp_out_comb = {result_sign, {(FP_W-1){1'b0}}};
        end else if (ftz_under) begin
            fp_out_comb = {result_sign, {(FP_W-1){1'b0}}};
        end else begin
            fp_out_comb = {result_sign, exp_out_final, rounded_fraction_final};
        end
    end

    // Output register and done logic
    generate
        if (LATENCY == 0) begin : gen_out_comb
            assign fp_out = fp_out_comb;
            assign done   = 1'b0;
        end
        else if (LATENCY == 1) begin : gen_out_1c
            always_ff @(posedge clk) begin
                if (!nRST)
                    fp_out <= '0;
                else
                    fp_out <= fp_out_comb;
            end
            assign done = 1'b0;
        end
        else begin : gen_out_2c
            always_ff @(posedge clk) begin
                if (!nRST)
                    fp_out <= '0;
                else if (!stall)
                    fp_out <= fp_out_comb;
            end
            assign done = start_q & ~stall;
        end
    endgenerate

endmodule
