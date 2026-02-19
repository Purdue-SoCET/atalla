`timescale 1ns/1ps

// BF16 adder/subtractor (round-to-nearest-even).
// NOTE: Subtraction is implemented as bf1 + (-bf2) via bf2_eff.

module addsub_bf16 (
    input  logic        clk,
    input  logic        nRST,
    input  logic [15:0] bf1_in,
    input  logic [15:0] bf2_in,
    input  logic        op,       // 0 = add, 1 = sub (bf1 + (-1)^op * bf2)
    output logic [15:0] bf_out,
    output logic        overflow,
    output logic        underflow,
    output logic        invalid
);

    // ----------------------------------------------------------------
    // Special cases: NaN / Inf / invalid
    // ----------------------------------------------------------------
    logic is_nan1, is_nan2, is_inf1, is_inf2;
    logic [15:0] bf2_eff;

    // For subtraction, flip bf2's sign bit.
    assign bf2_eff = {op ? ~bf2_in[15] : bf2_in[15], bf2_in[14:0]};

    always_comb begin
        // NaN: all 1s in exponent and non-zero mantissa
        is_nan1 = &bf1_in[14:7] && |bf1_in[6:0];
        is_nan2 = &bf2_eff[14:7] && |bf2_eff[6:0];

        // Inf: all 1s in exponent and zero mantissa
        is_inf1 = &bf1_in[14:7] && ~|bf1_in[6:0];
        is_inf2 = &bf2_eff[14:7] && ~|bf2_eff[6:0];

        // invalid for NaN, or +inf + -inf / -inf + +inf (after sign flip)
        invalid = is_nan1 || is_nan2 ||
                  (is_inf1 && is_inf2 && (bf1_in[15] != bf2_eff[15]));
    end

    // ----------------------------------------------------------------
    // Step 1: exponent compare (which one is "larger")
    // ----------------------------------------------------------------
    logic [7:0] smaller_exponent, larger_exponent;
    logic       exp_select;  // 0: bf2 has larger exp, 1: bf1 has larger exp

    always_comb begin
        if (bf1_in[14:7] < bf2_eff[14:7]) begin
            smaller_exponent = bf1_in[14:7];
            larger_exponent  = bf2_eff[14:7];
            exp_select       = 1'b0;  // bf2 is larger
        end else begin
            smaller_exponent = bf2_eff[14:7];
            larger_exponent  = bf1_in[14:7];
            exp_select       = 1'b1;  // bf1 is larger
        end
    end

    // ----------------------------------------------------------------
    // Step 2: implicit leading bit (normal vs subnormal)
    // ----------------------------------------------------------------
    logic frac_leading_bit_bf1;
    logic frac_leading_bit_bf2;

    always_comb begin
        frac_leading_bit_bf1 = (bf1_in[14:7] == 8'b0) ? 1'b0 : 1'b1;
        frac_leading_bit_bf2 = (bf2_eff[14:7] == 8'b0) ? 1'b0 : 1'b1;
    end

    // ----------------------------------------------------------------
    // Step 3: mantissa alignment (shift smaller exponent mantissa)
    // ----------------------------------------------------------------
    logic [7:0] exp_diff, exp_max;
    logic [9:0] frac_shifted, frac_not_shifted;
    logic       sign_shifted, sign_not_shifted;

    always_comb begin
        exp_diff = larger_exponent - smaller_exponent;

        if (exp_select == 0) begin
            // bf2 has bigger exponent → shift bf1
            if (exp_diff > 8'd9) begin
                // fully shifted out (10-bit mantissa including hidden + 2 G/R bits)
                frac_shifted = 10'b0;
            end else begin
                frac_shifted = {frac_leading_bit_bf1, bf1_in[6:0], 2'b00} >> exp_diff[3:0];
            end

            sign_shifted     = bf1_in[15];
            frac_not_shifted = {frac_leading_bit_bf2, bf2_eff[6:0], 2'b00};
            sign_not_shifted = bf2_eff[15];
            exp_max          = bf2_eff[14:7];

        end else begin
            // bf1 has bigger exponent → shift bf2
            if (exp_diff > 8'd9) begin
                frac_shifted = 10'b0;
            end else begin
                frac_shifted = {frac_leading_bit_bf2, bf2_eff[6:0], 2'b00} >> exp_diff[3:0];
            end

            sign_shifted     = bf2_eff[15];
            frac_not_shifted = {frac_leading_bit_bf1, bf1_in[6:0], 2'b00};
            sign_not_shifted = bf1_in[15];
            exp_max          = bf1_in[14:7];
        end
    end

    // ----------------------------------------------------------------
    // Step 4: choose larger/smaller mantissas and pipeline
    // ----------------------------------------------------------------
    logic [9:0] smaller_mantissa, larger_mantissa;
    logic [10:0] mantissa_sum;
    logic        larger_mantissa_sign;
    logic        result_sign, signs_differ, mantissa_overflow;

    always_comb begin
        if (frac_shifted > frac_not_shifted) begin
            smaller_mantissa       = frac_not_shifted;
            larger_mantissa        = frac_shifted;
            larger_mantissa_sign   = sign_shifted;
        end else begin
            smaller_mantissa       = frac_shifted;
            larger_mantissa        = frac_not_shifted;
            larger_mantissa_sign   = sign_not_shifted;
        end

        signs_differ = sign_shifted ^ sign_not_shifted;
    end

    // Pipeline registers before the add/sub
    logic [9:0] smaller_mantissa_l, larger_mantissa_l;
    logic       larger_mantissa_sign_l, sign_shifted_l, sign_not_shifted_l, signs_differ_l;
    logic [7:0] exp_max_l;
    logic       sticky_bit_l;       // pipelined sticky bit
    logic sticky_bit_unreg;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            smaller_mantissa_l     <= '0;
            larger_mantissa_l      <= '0;
            exp_max_l              <= '0;
            larger_mantissa_sign_l <= '0;
            signs_differ_l         <= '0;
            sign_shifted_l         <= '0;
            sign_not_shifted_l     <= '0;
            sticky_bit_l           <= '0;
        end else begin
            smaller_mantissa_l     <= smaller_mantissa;
            larger_mantissa_l      <= larger_mantissa;
            exp_max_l              <= exp_max;
            larger_mantissa_sign_l <= larger_mantissa_sign;
            signs_differ_l         <= signs_differ;
            sign_shifted_l         <= sign_shifted;
            sign_not_shifted_l     <= sign_not_shifted;
            sticky_bit_l           <= sticky_bit_unreg;
        end
    end

    // Do the actual add/sub on mantissas
    always_comb begin
        if (!signs_differ_l) begin
            mantissa_sum = smaller_mantissa_l + larger_mantissa_l;
            result_sign  = sign_shifted_l & sign_not_shifted_l;
        end else begin
            mantissa_sum = larger_mantissa_l - smaller_mantissa_l;
            result_sign  = larger_mantissa_sign_l;
        end

        mantissa_overflow = mantissa_sum[10];
    end

    // ----------------------------------------------------------------
    // Sticky bit computation (combinational, aligned with exp_diff)
    // ----------------------------------------------------------------
    logic [3:0] shift_amt;
    logic [9:0] mantissa_for_sticky;

    always_comb begin
        // Which operand was shifted?
        if (exp_select == 0)
            mantissa_for_sticky = {frac_leading_bit_bf1, bf1_in[6:0], 2'b00};
        else
            mantissa_for_sticky = {frac_leading_bit_bf2, bf2_eff[6:0], 2'b00};

        shift_amt = exp_diff[3:0];

        if (exp_diff == 0) begin
            sticky_bit_unreg = 1'b0;
        end
        else if (exp_diff > 8'd9) begin
            // everything shifted out: sticky is "was anything non-zero?"
            sticky_bit_unreg = |mantissa_for_sticky;
        end
        else begin
            // bits that got shifted out → sticky
            logic [9:0] mask;
            mask           = (10'b1 << shift_amt) - 1;
            sticky_bit_unreg = |(mantissa_for_sticky & mask);
        end
    end

    // ----------------------------------------------------------------
    // Overflow / underflow flags
    // ----------------------------------------------------------------
    logic [7:0] exp_minus_shift_amount;

    always_comb begin
        // Overflow: exponent hits max and mantissa overflows
        overflow = (exp_max_l == 8'hFF) ||
                   (mantissa_overflow && (exp_max_l == 8'hFE));

        // Underflow: exponent becomes zero or negative after normalization
        underflow = (exp_minus_shift_amount == 0) ||
                    (|exp_minus_shift_amount[7:6] && ~exp_minus_shift_amount[7]);
    end

    // ----------------------------------------------------------------
    // Step 5: normalize mantissa_sum via left_shift_bf16
    // ----------------------------------------------------------------
    logic [9:0] normalized_mantissa_sum;
    logic [3:0] norm_shift;

    left_shift normalizer (
        .fraction      (mantissa_sum[9:0]),
        .result        (normalized_mantissa_sum),
        .shifted_amount(norm_shift)
    );

    // ----------------------------------------------------------------
    // Step 6: adjust exponent based on normalization shift
    // ----------------------------------------------------------------
    logic [8:0] u_exp1;
    logic [7:0] u_shifted_amount;
    logic [8:0] u_result;

    always_comb begin
        u_exp1           = {1'b0, exp_max_l};
        u_shifted_amount = {1'b0, {3'b0, norm_shift}};
        u_result         = u_exp1 - u_shifted_amount;
    end

    assign exp_minus_shift_amount = u_result[7:0];

    // ----------------------------------------------------------------
    // Step 7: Rounding to nearest, ties to even
    // ----------------------------------------------------------------
    reg  [8:0] round_this;
    logic [7:0] exp_out;

    always_comb begin
        if (mantissa_overflow) begin
            // Use unnormalized sum, shift right one, bump exponent
            round_this = mantissa_sum[9:1];
            exp_out    = exp_max_l + 1;
        end else begin
            // Use normalized mantissa and adjusted exponent
            round_this = normalized_mantissa_sum[8:0];
            exp_out    = exp_minus_shift_amount;
        end
    end

    logic [15:0] round_out;
    logic        round_flag;
    logic [6:0]  rounded_fraction;
    logic [7:0]  exp_out_adj;

    // Guard / round bits
    logic G, R;
    assign G = round_this[1];
    assign R = round_this[0];

    logic [7:0] round_sum;

    always_comb begin
        round_flag = 1'b0;
        round_sum  = {1'b0, round_this[8:2]};  // candidate fraction (7 bits) with extra MSB

        // Round to nearest, ties to even, using sticky_bit_l
        if (G & (R | sticky_bit_l)) begin
            round_sum  = round_sum + 8'd1;
            round_flag = 1'b1;
        end

        rounded_fraction = round_sum[6:0];
        exp_out_adj      = exp_out + {7'b0, round_sum[7]}; // carry into exponent
    end

    // Final BF16 pack
    assign bf_out = {result_sign, exp_out_adj, rounded_fraction};

endmodule