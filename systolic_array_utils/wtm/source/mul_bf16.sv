`timescale 1ns/1ps
/* verilator lint_off UNUSEDSIGNAL */
module mul_bf16(input logic clk, nRST, 
                input logic start,
                input logic [15:0] bf1_in, bf2_in,
                output logic [15:0] bf_out,
                output logic overflow, underflow, invalid, done);
/* verilator lint_on UNUSEDSIGNAL */

localparam BIAS = 8'd127; // bf16 bias amount 

logic is_zero; 
logic [8:0] exponent_sum; // 9 bits to handle overflow
logic [7:0] final_exponent;
logic frac_leading_bit_bf1, frac_leading_bit_bf2;
logic [15:0] mantissa_product; // stable wtm product 
logic wtm_start, wtm_valid;

logic G, R, sticky; // rounding bits 

// Special cases 
assign invalid = &bf1_in[14:7] || &bf1_in[14:7]; 
assign is_zero = (~|bf1_in[14:0]) || (~|bf2_in[14:0]); 

// exponent bits 
assign bf_out[15] = bf1_in[15] ^ bf2_in[15]; // sign bit 
assign exponent_sum = bf1_in[14:7] + bf2_in[14:7] - BIAS; // add the exponents and subtract bias
assign final_exponent = mantissa_product[15] ? exponent_sum[7:0] + 1 : exponent_sum[7:0]; // MSB of mantissa product serves as a mantissa overflow indicator 
assign bf_out[14:7] = is_zero ? 0 : invalid ? 8'hFF : final_exponent; 

// overflow and underflow detection 
assign overflow = (exponent_sum[8] && !exponent_sum[7]) || // Positive overflow
              (final_exponent == 8'hFF && !invalid);    // Max exponent but not NaN
assign underflow = exponent_sum[8] && exponent_sum[7];     // If exponent becomes too small (negative) after normalization

// Handle mantissas and implicit bits for the WTM 
assign frac_leading_bit_bf1 = (|bf1_in[14:7]) ? 1'b1 : 1'b0; // Add implicit 1 for normalized numbers
assign frac_leading_bit_bf2 = (|bf2_in[14:7]) ? 1'b1 : 1'b0;

// rounding 
assign G = mantissa_product[15] ? mantissa_product[8] : mantissa_product[7]; 
assign R = mantissa_product[15] ? mantissa_product[7] : mantissa_product[6]; 
assign sticky = mantissa_product[15] ? |mantissa_product[6:0] : |mantissa_product[5:0]; 

// mantissa bits 
assign bf_out[6:0] = invalid && (|bf1_in[6:0] || |bf2_in[6:0]) ? 7'h80 : invalid || is_zero ? 7'h00 : 
    {mantissa_product[15], G && (R || sticky)} == 2'b00 ? mantissa_product[14:8] : 
    {mantissa_product[15], G && (R || sticky)} == 2'b01 ? mantissa_product[14:8] + 1 : 
    {mantissa_product[15], G && (R || sticky)} == 2'b10 ? mantissa_product[15:9] : mantissa_product[15:9] + 1; 

// Wallace Tree Multiplier
always_ff @(posedge clk or negedge nRST) begin
    if (!nRST) begin
        wtm_start <= 1'b0; 
        done <= 1'b0; 
    end else begin
        // Pulse WTM start when external `start` is asserted (one-cycle).
        // `wtm_valid` (from WTM) will go high when the product is ready; we
        // forward that as the module `done` output (one-cycle pulse when WTM
        // asserts done).
        wtm_start <= start;
        done <= wtm_valid;
    end
end

wtm_bf16_mantissa wtm (
    .clk(clk),
    .nRST(nRST),
    .en(wtm_start), 
    .A_in({frac_leading_bit_bf1, bf1_in[6:0]}),
    .B_in({frac_leading_bit_bf2, bf2_in[6:0]}),
    .S_out(mantissa_product),
    .done(wtm_valid) 
);

// // step 3: Normalize the mantissa product and adjust exponent
// logic mantissa_overflow;
// logic [6:0] normalized_mantissa;
// logic [7:0] final_exponent;

// always_comb begin
//     // Check if we need to shift right (product >= 2.0)
//     // use the registered, stable product from the synchronous WTM
//     mantissa_overflow = mantissa_product[15];
    
//     if (mantissa_overflow) begin
//         normalized_mantissa = mantissa_product[15:9];
//         final_exponent = exponent_sum[7:0] + 8'd1;
//     end else begin
//         normalized_mantissa = mantissa_product[14:8];
//         final_exponent = exponent_sum[7:0];
//     end
    
//     // Handle special cases
//     if (is_nan1 || is_nan2 || (is_zero1 && is_inf2) || (is_zero2 && is_inf1)) begin
//         // Return NaN
//         final_exponent = 8'hFF;
//         normalized_mantissa = 7'h80; // Non-zero mantissa for NaN
//     end else if (is_inf1 || is_inf2) begin
//         // Return infinity
//         final_exponent = 8'hFF;
//         normalized_mantissa = 7'h00;
//     end else if (is_zero1 || is_zero2) begin
//         // Return zero
//         final_exponent = 8'h00;
//         normalized_mantissa = 7'h00;
//     end
// end

// // Overflow/Underflow detection
// always_comb begin
//     // Overflow: If exponent becomes all 1's or larger after normalization
//     overflow = (exponent_sum[8] && !exponent_sum[7]) || // Positive overflow
//               (final_exponent == 8'hFF && !invalid);    // Max exponent but not NaN
    
//     // Underflow: If exponent becomes too small (negative) after normalization
//     underflow = exponent_sum[8] && exponent_sum[7];     // Negative exponent
// end

// // step 4: Rounding
// // For BF16 multiplication, extract 9 bits for rounding (7-bit mantissa + guard + round)
// logic [8:0] round_this;

// always_comb begin
//     if (mantissa_overflow == 1) begin
//         // mantissa_product[15:9] are the 7-bit mantissa
//         // mantissa_product[8] is guard bit
//         // mantissa_product[7] is round bit  
//         // mantissa_product[6:0] are sticky bits
//         round_this = mantissa_product[15:7];  // 9 bits: [mantissa(7) | guard(1) | round(1)]
//     end else begin
//         // mantissa_product[14:8] are the 7-bit mantissa
//         // mantissa_product[7] is guard bit
//         // mantissa_product[6] is round bit
//         // mantissa_product[5:0] are sticky bits
//         round_this = mantissa_product[14:6];  // 9 bits: [mantissa(7) | guard(1) | round(1)]
//     end
// end

// // For rounding, compute sticky bit from remaining bits
// logic sticky_bit_rounding;
// always_comb begin
//     if (mantissa_overflow == 1) begin
//         sticky_bit_rounding = |mantissa_product[6:0];
//     end else begin
//         sticky_bit_rounding = |mantissa_product[5:0];
//     end
// end

// // Rounding mode: Round to Nearest, Tie to Even
// logic G;
// logic R;
// assign G = round_this[1];  // Guard bit
// assign R = round_this[0];  // Round bit

// // Compute rounding for 7-bit fraction
// logic [7:0] round_sum;
// logic [6:0] rounded_fraction;
// logic [7:0] exp_out_adj;

// always_comb begin
//     // Default: no rounding increment
//     round_sum = {1'b0, round_this[8:2]}; // 8-bit with zero MSB (bits [8:2] = mantissa[6:0])

//     // Round to nearest, ties to even
//     // Round up when: G and (R or sticky) OR exact tie (G && ~R && ~sticky) and LSB==1
//     if (G && (R || sticky_bit_rounding || (~R && ~sticky_bit_rounding && round_sum[0] == 1'b1))) begin
//         // increment candidate fraction (round up)
//         round_sum = round_sum + 8'd1;
//     end

//     // rounded_fraction is the lower 7 bits; if MSB of round_sum is set,
//     // we carried into the exponent and must bump it.
//     rounded_fraction = round_sum[6:0];
//     exp_out_adj = final_exponent + {7'b0, round_sum[7]};
// end

// // Final output packing: sign(1) + exponent(8) + fraction(7) = 16 bits
// assign bf_out[14:0] = {exp_out_adj, rounded_fraction};

endmodule
