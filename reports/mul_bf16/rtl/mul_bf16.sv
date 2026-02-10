`timescale 1ns/1ps
// bf16 multiplier module 
// Made by Mixuan Pan and Vinay Pundith 
// Last Modified: 2/3, 2026 by Mixuan Pan for 1M test cases handling 

module mul_bf16(
    input logic clk, nRST, start, 
    input logic [15:0] a, b, 
    output logic [15:0] result, 
    output logic done, mul_ovf, mul_unf
    );
    
    logic lat1_ready;               // Signals to denote when the value is ready at each stage of the multiply unit pipeline.
    assign done = lat1_ready;                   // Mul result is ready when the value-latch register is ready - everything downstream of that is combinational.
    // Register 1: Latches input values.
    // Register 2: Latches mantissa multiplication output before going into exponent addition logic.

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
    localparam logic [15:0] QNAN = 16'h7FC0; // Quiet NaN
    localparam logic [15:0] POS_INF = 16'h7F80; // Positive Infinity

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
                // a is nan 
                is_nan = 1'b1; 
            end else begin 
                // b is inf 
                b_inf = 1'b1; 
            end
        end
    end

    // Step 1: Multiply mantissa bits.

    // Step 1.1: determine the "implilcit" leading bit of FP mantissa section prior to feeding it through multiplier
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
    // With a wallace tree multiplier, this takes two clock cycles (contains one latch in it).
    // logic mul_ready;
    logic [9:0] mul_product;
    logic mul_carryout;
    logic mul_round_loss;

    wallacetree_8b wallaca (
        .a({frac_leading_bit_fp1, a_latched[6:0]}),
        .b({frac_leading_bit_fp2, b_latched[6:0]}),
        .result(mul_product),
        .overflow(mul_carryout),
        .round_loss(mul_round_loss)
    );

    // Step 2: Exponent addition, result rounding. All combinational, result is ready in this cycle.
    
    // step 2.1: calculate sign of result. Simple XOR
    logic mul_sign_result;
    assign mul_sign_result = a_latched[15] ^ b_latched[15];

    // Step 2.2: Add exponent bits, taking into account overflow from mantissa multiplication
    logic [7:0] exp_sum;
    logic ovf, unf;
    adder_8b add_EXPs (
        .carry(mul_carryout),
        .exp1 (a_latched[14:7]),
        .exp2 (b_latched[14:7]),
        .sum  (exp_sum), 
        .ovf  (ovf),
        .unf  (unf)
    );

    // Step 2.3: Shift multiply product bits if an overflow occurred during mantissa multiplication (exponent was incremented, now divide mantissa by 2 to match)
    // logic [15:0] mul_result; 
               // this variable will hold the final multiplication result
    logic [8:0] mul_frac_product;
    assign mul_frac_product = mul_carryout ? mul_product[9:1] : mul_product[8:0];

    // Step 2.4: Rounding.
    // this logic could potentially result in an edge case where if the mul significand is all 1's, rounding will cause it to become 0
    logic [7:0] mul_significand_rounded;        // 8th bit will indicate overflow from rounding
    always_comb begin
        if(mul_frac_product[1] & (mul_frac_product[0] | mul_round_loss | mul_frac_product[2]))
            mul_significand_rounded = {1'b0, mul_frac_product[8:2]} + 1;
        else
            mul_significand_rounded = {1'b0, mul_frac_product[8:2]};
    end

    // Concatenation to produce final result.
    
    logic a_sub, b_sub; // subnormal inputs 
    assign a_sub = ~|a_latched[14:7];
    assign b_sub = ~|b_latched[14:7];


    logic boundary_case; // roundup + subnormal = smallest value 0080 
    assign boundary_case = unf & mul_significand_rounded[7]; 

    logic [7:0] mul_final_exp;
    assign mul_final_exp = boundary_case ? 8'h01 : (mul_product == 0) ? 0 : mul_significand_rounded[7] ? exp_sum + 1 : exp_sum;
    assign mul_unf = (unf) | ~|mul_final_exp;
    assign mul_ovf = ~mul_unf & (ovf | &mul_final_exp | (mul_carryout & ~|exp_sum[7:1] & exp_sum[0])); // if the final exp is all 1's and we need to round up, that also causes overflow

    assign result =  nan ? QNAN :   
                     inf ? {mul_sign_result, POS_INF[14:0]} : 
                     a_sub || b_sub ? {mul_sign_result, 15'b0} :  // subnormal inputs or output 
                     mul_ovf ? {mul_sign_result, POS_INF[14:0]} :
                     mul_unf ? {mul_sign_result, 15'b0} :
                     {mul_sign_result, mul_final_exp, mul_significand_rounded[6:0]};

endmodule
// required next line after endmodule for some verilog parsers
