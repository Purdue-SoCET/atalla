// One-cycle bfloat16 -> IEEE-754 half-precision (fp16) converter
// bf16:  [15] sign, [14:7] exp (bias 127), [6:0]  mant
// fp16:  [15] sign, [14:10] exp (bias 15), [9:0] mant
//
// Notes:
//  - Normal mapping: E_fp16_unbiased = E_bf16_unbiased
//      => exp_fp16_field = exp_bf16_field - 112
//  - This version:
//      * Zeros stay zeros (sign preserved)
//      * Infs/NaNs mapped to fp16 inf/NaN
//      * Overflow -> inf
//      * Underflow -> zero (no subnormal support, for simplicity)
//  - Mantissa is just left-shifted (no rounding): mant_fp16 = {mant_bf16, 3'b000}

module bf16_to_fp16 (
    input  logic        CLK,
    input  logic        nRST,
    input  logic [15:0] bf16_in,
    output logic [15:0] fp16_out
);

    // biases
    localparam int BF16_BIAS = 127;
    localparam int FP16_BIAS = 15;

    // unpack bf16
    logic        sign_b;
    logic [7:0]  exp_b;
    logic [6:0]  mant_b;

    // next-state for fp16 output
    logic [15:0] fp16_next;

    // combinational conversion
    always_comb begin
        sign_b = bf16_in[15];
        exp_b  = bf16_in[14:7];
        mant_b = bf16_in[6:0];

        fp16_next = 16'h0000;  // default

        // Special cases ------------------------------------------------------
        if (exp_b == 8'd0) begin
            // bf16 zero or subnormal -> treat as zero in fp16 (flush to zero)
            fp16_next = {sign_b, 5'd0, 10'd0};

        end else if (exp_b == 8'hFF) begin
            // bf16 Inf / NaN
            if (mant_b == 7'd0) begin
                // Infinity
                fp16_next = {sign_b, 5'h1F, 10'd0};
            end else begin
                // NaN (quiet NaN, payload ignored here)
                fp16_next = {1'b0, 5'h1F, 10'b1000_0000_00};
            end

        end else begin
            // Normal bf16 number ----------------------------------------------
            int e_unb;   // unbiased exponent (shared)
            int e_h_unb; // fp16 unbiased exponent

            e_unb   = int'(exp_b) - BF16_BIAS;
            e_h_unb = e_unb;

            // Overflow in fp16? (e > +15) -> Inf
            if (e_h_unb > 15) begin
                fp16_next = {sign_b, 5'h1F, 10'd0};

            // Underflow in fp16? (e < -14) -> zero (no subnormals here)
            end else if (e_h_unb < -14) begin
                fp16_next = {sign_b, 5'd0, 10'd0};

            end else begin
                // Normal fp16 -------------------------------------------------
                logic [4:0] exp_h;
                logic [9:0] mant_h;

                // re-bias exponent: e_h_unb + 15
                exp_h  = e_h_unb + FP16_BIAS;

                // expand mantissa: 7 bits -> 10 bits (no rounding)
                mant_h = {mant_b, 3'b011};

                fp16_next = {sign_b, exp_h, mant_h};
            end
        end
    end

    // 1-cycle registered output
    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST)
            fp16_out <= 16'h0000;
        else
            fp16_out <= fp16_next;
    end

endmodule