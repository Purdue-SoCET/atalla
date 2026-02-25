// BF16 Adder 
//By            : Mixuan Pan 
//Last Updated  : 2/17/2026 - Convert it to parametrizable bf16 adder 
//
//Module Summary:
//    BF16 adder with an option to pad one of the input mantissa to 23, making the input 32 bits long 
//    Subtraction is supported when the input signs differ

`timescale 1ns/1ps

module add_bf16 #(
    parameter MANT_B = 7  // size of bf2_in mantissa bits, default 7, could be 23 
)(
    input logic clk, nRST, start, stall, 
    input logic [15:0] bf1, 
    input logic [MANT_B+8:0] bf2,
    output logic [MANT_B+8:0] bf_out,
    output logic overflow, underflow, invalid, done 
);

    localparam logic [15:0] QNAN = 16'h7fc0; // quiet nan 
    localparam logic [14:0] INF = 15'h7f80; // inf 
    
    logic [15:0] bf1_in; 
    logic [MANT_B+8:0] bf2_in; 

    always_ff @(posedge clk, negedge nRST) begin 
        if (~nRST) begin
            bf1_in <= 0; 
            bf2_in <= 0; 
            done <= 0; 
        end else if (start & ~stall) begin
            bf1_in <= bf1; 
            bf2_in <= bf2; 
            done <= 1; 
        end 
    end

    // Special cases detection 
    logic is_nan, is_inf;

    // Check for NaN (all 1s in exponent and non-zero mantissa)
    assign is_nan = (&bf1_in[14:7] && |bf1_in[6:0]) | (&bf2_in[MANT_B+7:MANT_B] && |bf2_in[MANT_B-1:0]); 
    assign is_inf = (&bf1_in[14:7] && ~|bf1_in[6:0]) | (&bf2_in[MANT_B+7:MANT_B] && ~|bf2_in[MANT_B-1:0]); 
    assign invalid = is_nan; 

    // step 1: Compare exponents to determine which mantissa to shift for normalization.
    logic [MANT_B:0] smaller_exponent;
    logic [MANT_B:0] larger_exponent;
    logic exp_select;

    always_comb begin
        if(bf1_in[14:7] < bf2_in[MANT_B+7:MANT_B]) begin     // bf2 has a bigger exponent.
            smaller_exponent = bf1_in[14:7];
            larger_exponent = bf2_in[MANT_B+7:MANT_B];
            exp_select = 1'b0;
        end
        else begin                                  // bf1 has a bigger exponent.
            smaller_exponent = bf2_in[MANT_B+7:MANT_B];
            larger_exponent = bf1_in[14:7];
            exp_select = 1'b1;
        end
    end

    // step 2: Handle implicit mantissa bit for value == 0 case
        logic frac_leading_bit_bf1;
        logic frac_leading_bit_bf2;

        assign frac_leading_bit_bf1 = |bf1_in[14:7]; 
        assign frac_leading_bit_bf2 = |bf2_in[MANT_B+7:MANT_B]; 

    // step 3: Mantissa normalization. Shift the mantissa of the number with a smaller exponent to the right, by whatever the difference in exponents was.
    // aka, divide the mantissa so you can increase the exponent to match the larger one.
    logic [MANT_B:0] exp_diff; 
    logic [7:0] exp_max;
    logic [MANT_B+2:0] frac_shifted, frac_not_shifted;
    logic sign_shifted, sign_not_shifted;


    logic sticky_align; 
    logic [MANT_B+2:0] frac_to_shift; 

    always_comb begin
        exp_diff = larger_exponent - smaller_exponent;
        sticky_align = 0; 
        if(exp_select == 0) begin // bf2 had a bigger exponent: shift bf1.
            // ~|bf1_in[14:7] handles FTZ subnormals 
            if(exp_diff[MANT_B] | ~|bf1_in[14:7]) begin
                frac_shifted = {(MANT_B+3){1'b0}};
            end
            else begin
                frac_shifted = {frac_leading_bit_bf1, bf1_in[6:0], {(MANT_B-5){1'b0}}} >> exp_diff; 
            end
            sign_shifted = bf1_in[15];
            frac_not_shifted = ~|bf2_in[MANT_B+7:MANT_B] ? {(MANT_B+3){1'b0}} : {frac_leading_bit_bf2, bf2_in[MANT_B-1:0], 2'b0}; 
            sign_not_shifted = bf2_in[MANT_B+8];
            exp_max = bf2_in[MANT_B+7:MANT_B];
        end

        else begin                                      // bf1 had a bigger exponent: shift bf2.
            if(exp_diff[MANT_B] | ~|bf1_in[14:7]) begin
                frac_shifted = {(MANT_B+3){1'b0}};
            end
            else begin
                frac_shifted = {frac_leading_bit_bf2, bf2_in[MANT_B-1:0], {(MANT_B-5){1'b0}}} >> exp_diff;
            end
            sign_shifted = bf2_in[MANT_B+8];
            frac_not_shifted = ~|bf1_in[14:7] ? {(MANT_B+3){1'b0}} : {frac_leading_bit_bf1, bf1_in[6:0], 2'b0}; 
            sign_not_shifted = bf1_in[15];
            exp_max = bf1_in[14:7];
        end
    end

    // step 4: Add mantissae.

    // find which mantissa is bigger
    logic [MANT_B+2:0] smaller_mantissa, larger_mantissa;
    logic [MANT_B+3:0] mantissa_sum; // 11th bit is the mantissa overlow bit 
    logic larger_mantissa_sign;
    logic result_sign, signs_differ, mantissa_overflow;

    always_comb begin
        if(frac_shifted > frac_not_shifted) begin       // if the mantissae are equal, it doesnt matter what gets selected
            smaller_mantissa = frac_not_shifted;
            larger_mantissa = frac_shifted;
            larger_mantissa_sign = sign_shifted;
        end
        else begin
            smaller_mantissa = frac_shifted;
            larger_mantissa = frac_not_shifted;
            larger_mantissa_sign = sign_not_shifted;
        end

        signs_differ = sign_shifted ^ sign_not_shifted;
    end

    // register values here, before addition
    logic[MANT_B+2:0] smaller_mantissa_l, larger_mantissa_l;
    logic larger_mantissa_sign_l, sign_shifted_l, sign_not_shifted_l, signs_differ_l;
    logic[7:0] exp_max_l;

    always_ff @(posedge clk, negedge nRST) begin
        if(nRST == 1'b0) begin
            smaller_mantissa_l <= 0;
            larger_mantissa_l <= 0;
            exp_max_l <= 0;
            larger_mantissa_sign_l <= 0;
            signs_differ_l <= 0;
            sign_shifted_l <= 0;
            sign_not_shifted_l <= 0;
        end
        else begin
            smaller_mantissa_l <= smaller_mantissa;
            larger_mantissa_l <= larger_mantissa;
            exp_max_l <= exp_max;
            larger_mantissa_sign_l <= larger_mantissa_sign;
            signs_differ_l <= signs_differ;
            sign_shifted_l <= sign_shifted;
            sign_not_shifted_l <= sign_not_shifted;
        end
    end

    always_comb begin
        // logic: If the signs of the input operands are the same, simply add the two together.
        // The sign of the result will be the sign of both the inputs.
        // If one is positive and the other is negative, the result is the larger value minus the smaller value (using absolute value)
        // and the sign will be the sign of the larger operand.
        
        if(!signs_differ_l) begin
            mantissa_sum = smaller_mantissa_l + larger_mantissa_l;
            result_sign = sign_shifted_l & sign_not_shifted_l;
        end
        else begin
            mantissa_sum = larger_mantissa_l - smaller_mantissa_l;
            result_sign = larger_mantissa_sign_l;
        end

        if (~|bf1_in[14:0] & ~|bf2_in[MANT_B-6:0]) begin 
            result_sign = bf1_in[15] & bf2_in[MANT_B+8];
        end
        mantissa_overflow = mantissa_sum[MANT_B+3];  // Correct bit for overflow detection
    end

    /*
        Fixes for when mantissa sum is zero: equal mag subtractions
        When subtracting equal values (e.g., 1.0 - 1.0), mantissa_sum is all zeros.
        The normalizer doesn't handle this case — it returns shifted_amount=0, 
        leaving the exponent at the original value instead of producing zero.
    */
    logic result_is_zero;
    assign result_is_zero = ~|mantissa_sum;

    // Overflow/Underflow detection
    logic [7:0] exp_minus_shift_amount;

    always_comb begin
        // Overflow: If exponent becomes all 1's after normalization
        overflow = (exp_max_l == 8'hFF) || 
                (mantissa_overflow && (exp_max_l == 8'hFE));
        
        // Underflow: If exponent becomes zero or negative after normalization and shifting
        underflow = (exp_minus_shift_amount == 0) || 
                    (|exp_minus_shift_amount[7:6] && ~exp_minus_shift_amount[7]); // Check for negative result
    end

    // step 5: Re-normalization of mantissa sum.
    logic [MANT_B+1:0] normalized_mantissa_sum;
    logic [$clog2(MANT_B):0] norm_shift;
    
    left_shift_add_bf16 #(.MANT_B(MANT_B)) normalizer (
        .fraction(mantissa_sum[MANT_B+2:0]), 
        .result(normalized_mantissa_sum), 
        .shifted_amount(norm_shift));

    // step 6: Subtract exponents. 
    logic [7:0] u_exp1;
    logic [$clog2(MANT_B)+4:0] u_shifted_amount;
    logic [$clog2(MANT_B)+4:0] u_result;

    always_comb begin
        u_exp1           = exp_max_l;
        u_shifted_amount = {1'b0, {3'b0, norm_shift}};
        u_result         = $clog2(MANT_B) + 'd4 > 'd7 ?  {{($clog2(MANT_B) - 'd3){1'b0}}, u_exp1} - u_shifted_amount : u_exp1 - u_shifted_amount;
    end
    assign exp_minus_shift_amount = u_result[$clog2(MANT_B)+4:0];
    //------------------------------------------------------------------------------------

    // step 7: Rounding.
    reg [MANT_B+1:0] round_this;
    logic [7:0] exp_out;

    always_comb begin
        if (mantissa_overflow == 1) begin
            round_this = mantissa_sum[MANT_B+2:1];            
            exp_out    = exp_max_l + 1; // use for overflow case 
        end else begin
            round_this = normalized_mantissa_sum;
            exp_out    = exp_minus_shift_amount;
        end
    end

    // Adjusted rounding result width to 7 bits (BF16 fraction) and compute
    // an exponent adjustment if rounding carries into the exponent.
    logic [MANT_B-1:0] rounded_fraction;
    logic [7:0] exp_out_adj;

    // Rounding mode used: Round to Nearest, Tie to Even
    logic G, R, sticky, lsb;
    assign lsb = round_this[2];
    assign G = round_this[1];
    assign R = round_this[0];

    assign sticky = (mantissa_overflow ? |mantissa_sum[1:0] : 1'b0);

    // Compute rounding for 7-bit fraction: bits [8:2] are the candidate
    // fraction; bits [1:0] are guard/round, and bit [2] used earlier is
    // treated as sticky in the original layout. Use an 8-bit sum so we can
    // detect carry into exponent.
    logic [MANT_B:0] round_sum;
    logic roundup; 
    assign roundup = G & (R | lsb | sticky); // G & (R | round_this[2])
    assign round_sum = roundup ? {1'b0, round_this[MANT_B+1:2]} + 8'd1 : // increment candidate fraction (round up)
                       {1'b0, round_this[MANT_B+1:2]}; // 8-bit with zero MSB
    assign rounded_fraction = round_sum[MANT_B-1:0]; 
    assign exp_out_adj = exp_out + {7'b0, round_sum[MANT_B]};

    // final output 
    always_comb begin 
        // +inf & -inf 
        if (is_nan | (is_inf & (bf1_in[15] ^ bf2_in[MANT_B+8]))) begin 
            bf_out = QNAN; 
        // overflow 
        end else if (is_inf | (&bf1_in[14:8] & ~bf1_in[7] & &bf1_in[6:0] & |bf2_in[MANT_B+7:0]) | (&bf2_in[MANT_B+7:MANT_B+1] & ~bf2_in[MANT_B] & &bf2_in[MANT_B-1:0] & |bf1_in[14:0]) & ~(bf1_in[15] ^ bf2_in[MANT_B+8])) begin 
            bf_out = bf1_in[15] ? 16'hff80 : 16'h7F80;
        end else if (result_is_zero) begin
            // handle zero result from equal mag subtraction
            bf_out = {result_sign, 8'b0, {MANT_B{1'b0}}};
        // result after rounding 
        end else begin 
            bf_out = {result_sign, exp_out_adj, rounded_fraction};
        end
    end
endmodule
// blank last line for verilator & synthesis