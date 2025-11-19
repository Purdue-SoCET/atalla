`timescale 1ns/1ps

// This module probably CANNOT handle subtraction!

module addsub_bf16(input logic clk, nRST, 
                input logic [15:0] bf1_in, bf2_in,
                input logic op, // 0 for add, 1 for sub
                output logic [15:0] bf_out,
                output logic overflow, underflow, invalid);

// Special cases detection
logic is_nan1, is_nan2, is_inf1, is_inf2;
logic sticky_bit;

assign bf2_in[15] = op ? ~bf2_in[15] : bf2_in[15]; // if subtraction, flip sign of bf2_in

always_comb begin
    // Check for NaN (all 1s in exponent and non-zero mantissa)
    is_nan1 = &bf1_in[14:7] && |bf1_in[6:0];
    is_nan2 = &bf2_in[14:7] && |bf2_in[6:0];
    
    // Check for infinity (all 1s in exponent and zero mantissa)
    is_inf1 = &bf1_in[14:7] && ~|bf1_in[6:0];
    is_inf2 = &bf2_in[14:7] && ~|bf2_in[6:0];
    
    // Set invalid flag for NaN inputs or inf-inf with same signs
    invalid = is_nan1 || is_nan2 || (is_inf1 && is_inf2 && (bf1_in[15] != bf2_in[15]));
end

// step 1: Compare exponents to determine which mantissa to shift for normalization.
logic [7:0] smaller_exponent;
logic [7:0] larger_exponent;
logic exp_select;

always_comb begin
    if(bf1_in[14:7] < bf2_in[14:7]) begin     // bf2 has a bigger exponent.
        smaller_exponent = bf1_in[14:7];
        larger_exponent = bf2_in[14:7];
        exp_select = 1'b0;
    end
    else begin                                  // bf1 has a bigger exponent.
        smaller_exponent = bf2_in[14:7];
        larger_exponent = bf1_in[14:7];
        exp_select = 1'b1;
    end
end


// step 2: Handle implicit mantissa bit for value == 0 case
    logic frac_leading_bit_bf1;
    logic frac_leading_bit_bf2;
    always_comb begin
        if(bf1_in[14:7] == 8'b0)
            frac_leading_bit_bf1 = 1'b0;
        else
            frac_leading_bit_bf1 = 1'b1;

        if(bf2_in[14:7] == 8'b0)
            frac_leading_bit_bf2 = 1'b0;
        else
            frac_leading_bit_bf2 = 1'b1;
    end

// step 3: Mantissa normalization. Shift the mantissa of the number with a smaller exponent to the right, by whatever the difference in exponents was.
// aka, divide the mantissa so you can increase the exponent to match the larger one.
logic [7:0] exp_diff, exp_max;
logic [9:0] frac_shifted, frac_not_shifted;
logic sign_shifted, sign_not_shifted;

always_comb begin
    exp_diff = larger_exponent - smaller_exponent;

    if(exp_select == 0) begin                       // bf2 had a bigger exponent: shift bf1.

        // Mantissa is only 10 bits (after appending two zeros and an implcit 1/0). If for normalization you have to shift by more than 13 bits, it's going to be zero.
        // So, i think i can make a shifter that only shifts by the lower 4 bits of exp_diff, and if we had to shift by more than that, just hard code a zero as the output.
        // QUESTION: does this mean i need to turn on an underflow flag?

        if(exp_diff[7]) begin
            frac_shifted = 10'b0;
        end
        else begin
            frac_shifted = {frac_leading_bit_bf1, bf1_in[6:0], 2'b00} >> exp_diff[3:0];
        end
        // rounding_loss = |({frac_leading_bit_bf1, floating_point1_in[9:0], 2'b00} & ((1 << unsigned_exp_diff) - 1));    // chatgpt gave me this - sticky 
        sign_shifted = bf1_in[15];
        frac_not_shifted = {frac_leading_bit_bf2, bf2_in[6:0], 2'b00};
        sign_not_shifted = bf2_in[15];
        exp_max = bf2_in[14:7];
    end

    else begin                                      // bf1 had a bigger exponent: shift bf2.
        if(exp_diff[7]) begin
            frac_shifted = 10'b0;
        end
        else begin
            frac_shifted = {frac_leading_bit_bf2, bf2_in[6:0], 2'b00} >> exp_diff[3:0];
        end
        // rounding_loss = |({frac_leading_bit_bf2, floating_point2_in[9:0], 2'b00} & ((1 << unsigned_exp_diff) - 1));
        sign_shifted = bf2_in[15];
        frac_not_shifted = {frac_leading_bit_bf1, bf1_in[6:0], 2'b00};
        sign_not_shifted = bf1_in[15];
        exp_max = bf1_in[14:7];
    end
end

// step 4: Add mantissae.

// find which mantissa is bigger
logic [9:0] smaller_mantissa, larger_mantissa;
logic [10:0] mantissa_sum; // 11th bit is the mantissa overlow bit 
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
logic[9:0] smaller_mantissa_l, larger_mantissa_l;
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

    mantissa_overflow = mantissa_sum[10];  // Correct bit for overflow detection
end

// Calculate sticky bit from shifted out bits
always_comb begin
    if (exp_select == 0) begin
        sticky_bit = |(({frac_leading_bit_bf1, bf1_in[6:0], 2'b00} & ((1 << exp_diff) - 1)));
    end else begin
        sticky_bit = |(({frac_leading_bit_bf2, bf2_in[6:0], 2'b00} & ((1 << exp_diff) - 1)));
    end
end

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

// screw all of this im gonna use the old inefficient module

// // step 5.1: Calculate the number of leading zeros in the value.
// // implementing leading-zero-detection (LZD) as a tree.
// logic z1, z2, z3;   // Split input into 3 chunks of 4 bits (or 5 for the last one) each, and check each one individually for where the leading zero is.
// assign z1 = |mantissa_sum[12:9];    // highest 1 is in upper 4 bits?
// assign z2 = |mantissa_sum[8:5];     // highest 1 is in the next 4 below?
// assign z3 = |mantissa_sum[4:0];     // or the lowest 4?

// logic[3:0] l1_loc_1, l1_loc_2, l1_loc_3;
// assign l1_loc_1 = (mantissa_sum[12] ? 0 : (mantissa_sum[11] ? 1 : (mantissa_sum[10] ? 2 : (mantissa_sum[9] ? 3 : 2))));
// assign l1_loc_2 = (mantissa_sum[8] ? 0 : (mantissa_sum[7] ? 1 : (mantissa_sum[6] ? 2 : (mantissa_sum[5] ? 3 : 2))));

// always_comb begin
//     if(|mantissa_sum[12:])
// end
logic [9:0] normalized_mantissa_sum;
logic [3:0] norm_shift;
left_shift normalizer(.fraction(mantissa_sum[9:0]), .result(normalized_mantissa_sum), .shifted_amount(norm_shift));



// step 6: Subtract exponents. I forgot why this exists. Transferred out of subtract.sv
logic [8:0] u_exp1, u_exp2;
logic [7:0] u_shifted_amount;
logic [8:0] u_result;


always_comb begin
    u_exp1           = {1'b0, exp_max_l};
    u_shifted_amount = {1'b0, {3'b0, norm_shift}};
    u_result         = u_exp1 - u_shifted_amount;
end
assign exp_minus_shift_amount = u_result[7:0];
//------------------------------------------------------------------------------------


// step 7: Rounding.
reg [8:0] round_this;
logic [7:0] exp_out;

always_comb begin
    // ovf = 0;
    // unf = 0;
    if (mantissa_overflow == 1) begin
        round_this = mantissa_sum[9:1];            // i forgot why we dont use the normalized sum here
        exp_out    = exp_max_l + 1; // use for overflow case 
        // if ((exp_max == 5'b11110) && (~unf_in)) ovf = 1;
    end else begin
        round_this = normalized_mantissa_sum[8:0];
        exp_out    = exp_minus_shift_amount;
        // if (({1'b0, exp_max} < {1'b0,norm_shift}) && (~ovf_in)) unf = 1;
    end
end

logic [15:0] round_out;
logic round_flag;               // retained: indicates rounding increment occurred
// Adjusted rounding result width to 7 bits (BF16 fraction) and compute
// an exponent adjustment if rounding carries into the exponent.
logic [6:0] rounded_fraction;
logic [7:0] exp_out_adj;

    // Rounding mode used: Round to Nearest, Tie to Even
    logic G;
    logic R;
    assign G = round_this[1];
    assign R = round_this[0];

    // Compute rounding for 7-bit fraction: bits [8:2] are the candidate
    // fraction; bits [1:0] are guard/round, and bit [2] used earlier is
    // treated as sticky in the original layout. Use an 8-bit sum so we can
    // detect carry into exponent.
    logic [7:0] round_sum;
    always_comb begin
        // Default
        round_flag = 0;
        round_sum = {1'b0, round_this[8:2]}; // 8-bit with zero MSB

        // if (G & (R | round_this[2])) begin
        if (G & (R | sticky_bit)) begin
            // increment candidate fraction (round up)
            round_sum = round_sum + 8'd1;
            round_flag = 1;
        end

        // rounded_fraction is the lower 7 bits; if MSB of round_sum is set,
        // we carried into the exponent and must bump it.
        rounded_fraction = round_sum[6:0];
        exp_out_adj = exp_out + {7'b0, round_sum[7]};
    end

    // Final output packing: sign(1) + exponent(8) + fraction(7) = 16 bits
    assign bf_out = {result_sign, exp_out_adj, rounded_fraction};

endmodule



