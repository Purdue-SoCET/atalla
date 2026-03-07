`timescale 1ns/1ps
// bf16 multiplier module -> exact FP32 product (no rounding)
// Made by Mixuan Pan and Vinay Pundith 
// Last Modified: BF16 inputs, FP32 output for exact accumulation path. (myles "agentic" querimit)

module mul_bf (
    input logic clk, nRST, start, 
    input logic [15:0] a, b, 
    output logic [31:0] result, 
    output logic done, mul_ovf, mul_unf
    );
    
    logic lat1_ready;               // Signals to denote when the value is ready at each stage of the multiply unit pipeline.
    assign done = lat1_ready;                   // Mul result is ready when the value-latch register is ready - everything downstream of that is combinational.

    // Register 1: latch input values.
    logic [15:0] a_latched, b_latched;
    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            a_latched <= 0;
            b_latched <= 0;
            lat1_ready <= 0;
        end
        else begin
            a_latched <= a_latched;
            b_latched <= b_latched;
            lat1_ready <= 0;

            if(start == 1'b1) begin
                a_latched <= a;
                b_latched <= b;
                lat1_ready <= 1;
            end
        end
    end

    // Step 0: Edge cases detection 
    localparam logic [31:0] QNAN = 32'h7FC00000; // Quiet NaN (FP32)
    localparam logic [31:0] POS_INF = 32'h7F800000; // Positive Infinity (FP32)

    logic inf, nan, is_nan, a_inf, b_inf; 
    assign nan = is_nan | (a_inf & ~|b_latched[14:7]) | (b_inf & ~|a_latched[14:7]); 
    assign inf = ~nan & (a_inf | b_inf); 

    always_comb begin: nan_inf_detection 
        a_inf = 1'b0; 
        b_inf = 1'b0;  
        is_nan= 1'b0; 

        // a detection 
        if (&a_latched[14:7]) begin 
            if (|a_latched[6:0]) begin 
                // a is nan 
                is_nan = 1'b1; 
            end else begin 
                // a is inf 
                a_inf = 1'b1; 
            end
        end

        // b detection 
        if (&b_latched[14:7]) begin 
            if (|b_latched[6:0]) begin 
                // b is nan 
                is_nan = 1'b1; 
            end else begin 
                // b is inf 
                b_inf = 1'b1; 
            end
        end
    end

    // Step 1: Multiply mantissa bits.

    // Step 1.1: determine the "implicit" leading bit of FP mantissa section prior to feeding it through multiplier
    // If the exponent bits are zero, the implicit bit is 0, else its 1.

    logic frac_leading_bit_fp1;
    logic frac_leading_bit_fp2;
    always_comb begin
        if(a_latched[14:7] == 8'b0)begin
            frac_leading_bit_fp1 = 1'b0;
        end
        else begin
            frac_leading_bit_fp1 = 1'b1;
        end

        if(b_latched[14:7] == 8'b0)begin
            frac_leading_bit_fp2 = 1'b0;
        end
        else begin
            frac_leading_bit_fp2 = 1'b1;
        end
    end

    // Step 1.2: Multiply mantissae.
    // 8x8 wallace tree, full 16-bit exact product. No truncation.
    logic [15:0] mant_product;

    wtm_bf wallaca (
        .a({frac_leading_bit_fp1, a_latched[6:0]}),
        .b({frac_leading_bit_fp2, b_latched[6:0]}),
        .product(mant_product)
    );

    // Step 2: Exponent addition, mantissa formatting. All combinational.
    
    // Step 2.1: calculate sign of result. Simple XOR
    logic mul_sign_result;
    assign mul_sign_result = a_latched[15] ^ b_latched[15];

    // Step 2.2: Exponent math (9-bit to catch overflow/underflow)
    logic norm_shift;
    assign norm_shift = mant_product[15]; // 1 if 1.xxx * 1.xxx >= 2.0

    logic signed [9:0] exp_sum_raw;
    assign exp_sum_raw = {2'b0, a_latched[14:7]} + {2'b0, b_latched[14:7]}
                         - 10'sd127 + {9'b0, norm_shift};

    // Step 2.3: Mantissa -> FP32 23-bit fraction
    logic [22:0] frac_fp32;
    assign frac_fp32 = norm_shift ? {mant_product[14:0], 8'b0}
                                  : {mant_product[13:0], 9'b0};

    // Step 2.4: Overflow / Underflow detection
    logic ovf, unf;
    // Overflow: exponent >= 255
    assign ovf = (~exp_sum_raw[9]) & (exp_sum_raw[8] | (exp_sum_raw[7:0] >= 8'd255));
    // Underflow: exponent <= 0 (signed negative or zero)
    assign unf = exp_sum_raw[9] | (~|exp_sum_raw[8:0]);

    // Subnormal inputs 
    logic a_sub, b_sub;
    assign a_sub = ~|a_latched[14:7];
    assign b_sub = ~|b_latched[14:7];

    logic [7:0] exp_fp32;
    assign exp_fp32 = exp_sum_raw[7:0];

    assign mul_unf = ~ovf & unf & ~a_sub & ~b_sub;
    assign mul_ovf = ~mul_unf & ovf & ~a_sub & ~b_sub;

    // Concatenation to produce final FP32 result.
    assign result =  nan ? QNAN :   
                     inf ? {mul_sign_result, POS_INF[30:0]} : 
                     a_sub || b_sub ? {mul_sign_result, 31'b0} :  // subnormal inputs flush to zero (FTZ/DAZ)
                     mul_ovf ? {mul_sign_result, POS_INF[30:0]} :
                     mul_unf ? {mul_sign_result, 31'b0} :
                     {mul_sign_result, exp_fp32, frac_fp32};
                
endmodule
// required next line after endmodule for some verilog parsers