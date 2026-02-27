

module exponential_unit (
    input logic clk, rst_n,
    input logic [15:0] x_in, // BF16 Input
    output logic [15:0] result_out, // BF16 Output
    output logic valid_out
);

    // Log2(e) ≈ 1.442695. Represented as Q4.12 fixed-point integer (1.442695 * 4096)
    localparam signed [15:0] LOG2_E_Q12 = 16'd5909; 
    
    // Overflow/Underflow bounds for e^x in BF16
    // BF16 max ≈ 3.38e38 (ln ≈ 88.7). BF16 min subnormal ≈ 9e-41 (ln ≈ -92)
    localparam signed [15:0] MAX_X_Q8 = 16'd22707;  // 88.7 * 256
    localparam signed [15:0] MIN_X_Q8 = -16'd23552; // -92.0 * 256

    // Stage 1: Converting BF16 to Q8.8 Fixed-Point
    
    logic sign_in;
    logic [7:0] exp_in;
    logic [6:0] mant_in;
    
    logic signed [15:0] x_fixed; 
    logic is_zero;

    logic signed [31:0] z_full;    // Full precision multiplier result
    logic signed [8:0]  z_int;     // Integer part of Z
    logic [6:0] z_frac;    // Fractional part of Z (used for LUT)
    logic stage2_zero;
    logic [6:0] lut_mantissa;

    int shift_val = exp_in - 127;
    logic [31:0] aligned;

    logic signed [9:0] final_exp; // Final exponent after adding bias

    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            x_fixed <= '0;
            is_zero <= 1'b0;
        end else begin
            sign_in <= x_in[15];
            exp_in  <= x_in[14:7];
            mant_in <= x_in[6:0];
            
            // Handle zero
            if (exp_in == 0 && mant_in == 0) begin
                is_zero <= 1'b1;
                x_fixed <= '0;
            end else begin
                is_zero <= 1'b0;
                // Float to Fixed Q8.8 conversion
                // Shift based on exponent bias (127) to align to Q8.8

                
                // Align the 8-bit value {1, mant_in} to Q8.8 space
                if (shift_val >= 0) begin
                    aligned = {24'b0, 1'b1, mant_in} << (shift_val + 1); //32 bits to prevent overflow
                end else begin
                    aligned = {24'b0, 1'b1, mant_in} >> (-shift_val - 1);
                end
                
                // Apply sign
                x_fixed <= sign_in ? -$signed(aligned[15:0]) : $signed(aligned[15:0]);
            end
        end
    end

    // Stage 2: Multiply by Log2(e) to split Integer/Fraction
    // Identity: e^x = 2^(x * log2(e))

    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            z_full <= '0;
            z_int <= '0;
            z_frac <= '0;
            stage2_zero <= 1'b0;
        end else begin
            stage2_zero <= is_zero;
            
            // Q8.8 * Q4.12 = Q12.20
            z_full <= (x_fixed * LOG2_E_Q12) + 32'h1000; // Add 0.5 for rounding 
            
            // Extract integer (shift right by 20 bits)
            z_int <= z_full[28:20]; 
            
            // Extract fraction (top 7 bits of the 20-bit fractional part)
            z_frac <= z_full[19:13]; 
        end
    end


    // Stage 3: Look-Up Table & Reconstruction
    
    // The LUT evaluates 2^(z_frac)
    bf16_exp_lut u_frac_lut (
        .addr_frac (z_frac),
        .mant_out  (lut_mantissa)
    );

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            result_out <= '0;
            valid_out  <= 1'b0;
        end else begin
            if (stage2_zero) begin
                // e^0 = 1.0 (BF16: 0x3F80)
                result_out <= 16'h3F80;
            end else begin
                // Reconstruct Exponent: Bias (127) + z_int
                // Ensure we handle the signed addition correctly
                final_exp = 10'd127 + z_int;
                
                // Overflow / Underflow clamping
                if (final_exp >= 255) begin
                    result_out <= 16'h7F80; // +Infinity
                end else if (final_exp <= 0) begin
                    result_out <= 16'h0000; // Underflow to 0
                end else begin
                    // Assemble final BF16 value: Sign is always 0 (e^x is always positive)
                    result_out <= {1'b0, final_exp[7:0], lut_mantissa};
                end
            end
            valid_out <= 1'b1;
        end
    end

endmodule