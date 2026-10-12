`include "exp_if.vh"

module exp (
    input logic CLK,
    input logic nRST,
    exp_if.exif exif
);

    localparam int EXPONENT_W = 8;
    localparam int MANTISSA_W = 7;

    typedef logic [EXPONENT_W-1:0] exponent_t;
    typedef logic [MANTISSA_W-1:0] mantissa_t;
    typedef logic [MANTISSA_W+EXPONENT_W:0] bf16_t;

    localparam bf16_t POSITIVE_INF = 16'h7f80;
    localparam bf16_t QUIET_NAN = 16'h7fc0;

    localparam exponent_t EXPONENT_BIAS = 8'h7f;
    localparam exponent_t EXPONENT_NON_FINITE = 8'hff;

    localparam int LOG_2_E_W = 15;
    localparam int FRAC_W = 14;
    // Fixed point representation of round(log2(e) * 2^FRAC_W)
    localparam logic [LOG_2_E_W-1:0] LOG_2_E = 15'h5c55;

    localparam int SHIFT_AMT_W = 5;
    typedef logic [SHIFT_AMT_W-1:0] shift_amt_t;
    localparam shift_amt_t MAX_LEFT_SHIFT = 5'd8;
    localparam shift_amt_t MAX_RIGHT_SHIFT = 5'd24;

    localparam int SHIFTED_PROD_W = MANTISSA_W + LOG_2_E_W + int'(MAX_LEFT_SHIFT) + 1;

    localparam int LUT_SIZE = 128;
    typedef mantissa_t [LUT_SIZE-1:0] lut_array_t;
    // LUT values are the mantissa bits of 2^(i/LUT_SIZE) for i in [0, LUT_SIZE)
    localparam lut_array_t LUT = '{
                                    7'h7E, 7'h7D, 7'h7B, 7'h7A, 7'h79, 7'h77, 7'h76, 7'h75,
                                    7'h73, 7'h72, 7'h71, 7'h6F, 7'h6E, 7'h6D, 7'h6C, 7'h6A,
                                    7'h69, 7'h68, 7'h66, 7'h65, 7'h64, 7'h63, 7'h62, 7'h60,
                                    7'h5F, 7'h5E, 7'h5D, 7'h5B, 7'h5A, 7'h59, 7'h58, 7'h57,
                                    7'h56, 7'h54, 7'h53, 7'h52, 7'h51, 7'h50, 7'h4F, 7'h4E,
                                    7'h4D, 7'h4B, 7'h4A, 7'h49, 7'h48, 7'h47, 7'h46, 7'h45,
                                    7'h44, 7'h43, 7'h42, 7'h41, 7'h40, 7'h3F, 7'h3E, 7'h3D,
                                    7'h3C, 7'h3A, 7'h39, 7'h38, 7'h37, 7'h36, 7'h36, 7'h35,
                                    7'h34, 7'h33, 7'h32, 7'h31, 7'h30, 7'h2F, 7'h2E, 7'h2D,
                                    7'h2C, 7'h2B, 7'h2A, 7'h29, 7'h28, 7'h27, 7'h26, 7'h25,
                                    7'h25, 7'h24, 7'h23, 7'h22, 7'h21, 7'h20, 7'h1F, 7'h1E,
                                    7'h1E, 7'h1D, 7'h1C, 7'h1B, 7'h1A, 7'h19, 7'h19, 7'h18,
                                    7'h17, 7'h16, 7'h15, 7'h14, 7'h14, 7'h13, 7'h12, 7'h11,
                                    7'h10, 7'h10, 7'h0F, 7'h0E, 7'h0D, 7'h0D, 7'h0C, 7'h0B,
                                    7'h0A, 7'h0A, 7'h09, 7'h08, 7'h07, 7'h07, 7'h06, 7'h05,
                                    7'h04, 7'h04, 7'h03, 7'h02, 7'h02, 7'h01, 7'h00, 7'h00
                                  };

    localparam int LUT_ADDR_W = $clog2(LUT_SIZE);

    localparam int EXPONENT_PART_W = SHIFTED_PROD_W - FRAC_W - LUT_ADDR_W + 1;
    localparam logic signed [EXPONENT_PART_W-1:0] SATURATION_EXP = EXPONENT_PART_W'(8'hff);
    localparam logic signed [EXPONENT_PART_W-1:0] UNDERFLOW_EXP = -EXPONENT_PART_W'(8'h8);
    localparam logic signed [EXPONENT_PART_W-1:0] SUBNORMAL_EXP = EXPONENT_PART_W'(8'h0);

    localparam int SUBNORMAL_MANTISSA_SHIFT_W = 5;

    logic [LUT_ADDR_W-1:0] lut_addr;
    mantissa_t lut_out;
    assign lut_out = LUT[lut_addr];

    logic sign_in;
    exponent_t exponent_in;
    mantissa_t mantissa_in;
    assign {sign_in, exponent_in, mantissa_in} = exif.in.operand;

    logic [MANTISSA_W:0] mant_comp;
    exponent_t adj_exp;
    logic signed [EXPONENT_W:0] shift_val;

    /*
     * Adjust exponent and mantissa for subnormal numbers and
     * compute raw shift value for scaling.
     */
    always_comb begin : subnormal_adjust
        if (exponent_in) begin
            mant_comp = {1'b1, mantissa_in};
            adj_exp = exponent_in;
        end else begin
            mant_comp = {mantissa_in, 1'b0};
            adj_exp = 8'h1;
        end
        shift_val = adj_exp - EXPONENT_BIAS;
    end

    logic [MANTISSA_W+LOG_2_E_W:0] raw_prod;
    /*
     * Multiplication operator is being used intentionally because we need
     * an 8x15 multiplier. Since the 15 bit signal is a constant, the synthesis
     * tool can aggresively optimize it.
     */
    assign raw_prod = mant_comp * LOG_2_E;

    shift_amt_t shift_amt;
    logic [SHIFTED_PROD_W-1:0] shifted_prod;

    /*
     * Barrel shifter to scale the product. Clamped to avoid overflow issues.
     */
    always_comb begin : barrel_shifter
        if (shift_val >= 0) begin
            shift_amt = (shift_val > MAX_LEFT_SHIFT) ? MAX_LEFT_SHIFT : shift_val[SHIFT_AMT_W-1:0];
            shifted_prod = raw_prod << shift_amt;
        end else begin
            shift_amt = (-shift_val > MAX_RIGHT_SHIFT) ? MAX_RIGHT_SHIFT : -shift_val[SHIFT_AMT_W-1:0];
            shifted_prod = raw_prod >> shift_amt;
        end
    end

    logic signed [SHIFTED_PROD_W-FRAC_W+1:0] rounded_prod;
    logic signed [EXPONENT_PART_W-1:0] exponent_part;
    assign rounded_prod = shifted_prod[SHIFTED_PROD_W-1:FRAC_W] + shifted_prod[FRAC_W-1];
    assign {exponent_part, lut_addr} = sign_in ? -rounded_prod : rounded_prod;

    bf16_t result;
    logic signed [EXPONENT_PART_W-1:0] final_exponent;
    mantissa_t subnormal_mantissa;

    /*
     * Final result assembly. Handles NaN, Infinity, Saturation, Underflow, and Subnormal cases.
     */
    always_comb begin : result_logic
        final_exponent = exponent_part + EXPONENT_BIAS;
        subnormal_mantissa = {1'b1, lut_out} >> (1'b1 - final_exponent[SUBNORMAL_MANTISSA_SHIFT_W-1:0]);

        if (exponent_in == EXPONENT_NON_FINITE) begin
            if (mantissa_in) begin : nan
                result = QUIET_NAN;
            end else begin : infinity
                result = sign_in ? 16'h0 : POSITIVE_INF;
            end
        end else if (final_exponent >= SATURATION_EXP) begin : saturation
            result = POSITIVE_INF;
        end else if (final_exponent <= SUBNORMAL_EXP) begin
            if (final_exponent <= UNDERFLOW_EXP) begin : underflow
                result = 16'h0;
            end else begin : subnormal
                result = {1'b0, {EXPONENT_W{1'b0}}, subnormal_mantissa};
            end
        end else begin : normal
            result = {1'b0, final_exponent[EXPONENT_W-1:0], lut_out};
        end
    end

    /*
     * Handshake logic using valid-ready protocol.
     */
    assign exif.out.ready_in = !exif.out.valid_out || exif.in.ready_out;
    always_ff @(posedge CLK or negedge nRST) begin : valid_ready
        if (!nRST) begin
            exif.out.valid_out <= 1'b0;
            // exif.out.result does not have a reset value
        end else if (exif.out.ready_in) begin
            exif.out.valid_out <= exif.in.valid_in;
            if (exif.in.valid_in) begin
                exif.out.result <= result;
            end
        end
    end

endmodule
