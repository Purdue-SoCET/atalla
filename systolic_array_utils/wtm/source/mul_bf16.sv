
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

endmodule
