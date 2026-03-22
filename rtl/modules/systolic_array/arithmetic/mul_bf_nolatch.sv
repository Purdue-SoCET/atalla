`timescale 1ns/1ps
// bf16 combinational multiplier -> exact FP32 product (no rounding, no latching)
// Derived from mul_bf by stripping all registers.
// BF16 inputs, FP32 output for exact accumulation path.

module mul_bf_nolatch (
    input  logic [15:0] a, b,
    output logic [31:0] result,
    output logic mul_ovf, mul_unf
);

    // Step 0: Edge cases detection
    localparam logic [31:0] QNAN    = 32'h7FC00000;
    localparam logic [31:0] POS_INF = 32'h7F800000;

    logic inf, nan, is_nan, a_inf, b_inf;
    assign nan = is_nan | (a_inf & ~|b[14:7]) | (b_inf & ~|a[14:7]);
    assign inf = ~nan & (a_inf | b_inf);

    always_comb begin : nan_inf_detection
        a_inf  = 1'b0;
        b_inf  = 1'b0;
        is_nan = 1'b0;

        if (&a[14:7]) begin
            if (|a[6:0]) is_nan = 1'b1;
            else         a_inf  = 1'b1;
        end
        if (&b[14:7]) begin
            if (|b[6:0]) is_nan = 1'b1;
            else         b_inf  = 1'b1;
        end
    end

    // Step 1: Implicit leading bits
    logic frac_leading_bit_fp1, frac_leading_bit_fp2;
    assign frac_leading_bit_fp1 = |a[14:7];
    assign frac_leading_bit_fp2 = |b[14:7];

    // Step 1.2: Wallace tree multiply (8x8 -> 16-bit exact product)
    logic [15:0] mant_product;
    wtm_bf wallaca (
        .a({frac_leading_bit_fp1, a[6:0]}),
        .b({frac_leading_bit_fp2, b[6:0]}),
        .product(mant_product)
    );

    // Step 2: Exponent addition, mantissa formatting
    logic mul_sign_result;
    assign mul_sign_result = a[15] ^ b[15];

    logic norm_shift;
    assign norm_shift = mant_product[15];

    logic signed [9:0] exp_sum_raw;
    assign exp_sum_raw = {2'b0, a[14:7]} + {2'b0, b[14:7]}
                         - 10'sd127 + {9'b0, norm_shift};

    logic [22:0] frac_fp32;
    assign frac_fp32 = norm_shift ? {mant_product[14:0], 8'b0}
                                  : {mant_product[13:0], 9'b0};

    // Overflow / Underflow
    logic ovf, unf;
    assign ovf = (~exp_sum_raw[9]) & (exp_sum_raw[8] | (exp_sum_raw[7:0] >= 8'd255));
    assign unf = exp_sum_raw[9] | (~|exp_sum_raw[8:0]);

    logic a_sub, b_sub;
    assign a_sub = ~|a[14:7];
    assign b_sub = ~|b[14:7];

    logic [7:0] exp_fp32;
    assign exp_fp32 = exp_sum_raw[7:0];

    assign mul_unf = ~ovf & unf & ~a_sub & ~b_sub;
    assign mul_ovf = ~mul_unf & ovf & ~a_sub & ~b_sub;

    // Final FP32 result (purely combinational)
    assign result = nan     ? QNAN :
                    inf     ? {mul_sign_result, POS_INF[30:0]} :
                    a_sub || b_sub ? {mul_sign_result, 31'b0} :
                    mul_ovf ? {mul_sign_result, POS_INF[30:0]} :
                    mul_unf ? {mul_sign_result, 31'b0} :
                    {mul_sign_result, exp_fp32, frac_fp32};

endmodule
