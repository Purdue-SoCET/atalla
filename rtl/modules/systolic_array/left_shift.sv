`timescale 1ns/1ps

// Leading-one normalizer using staged logarithmic shifter
// Replaces casez priority encoder with O(log n) mux tree
//
// By: Joe Nasti (original), Myles (optimized)
// 
// Module Summary:
//   Left shifts an unsigned 13-bit value until the MSB is '1'
//   Returns the normalized result and shift amount
//
// Structure: 4-stage shifter (+8, +4, +2, +1)
//   Each stage checks if upper bits are zero, conditionally shifts
//   Total depth: 4 levels of mux + OR-reduce per stage
//
// Special case: fraction==0 returns shift=0 (guarded upstream in adder)

module left_shift (
    input  logic [12:0] fraction,
    output logic [12:0] result,
    output logic [3:0]  shifted_amount
);

    // Zero detection - handle explicitly to avoid returning 15
    logic is_zero;
    assign is_zero = (fraction == 13'b0);

    // Stage signals
    logic [12:0] s0, s1, s2, s3;
    logic [3:0] amt;

    // Stage 0: Check if top 8 bits are zero, shift by 8 if so
    // For 13-bit input, check bits [12:5] (8 bits)
    logic shift8;
    assign shift8 = (fraction[12:5] == 8'b0);
    assign s0 = shift8 ? {fraction[4:0], 8'b0} : fraction;
    assign amt[3] = shift8;

    // Stage 1: Check if top 4 bits are zero, shift by 4 if so
    logic shift4;
    assign shift4 = (s0[12:9] == 4'b0);
    assign s1 = shift4 ? {s0[8:0], 4'b0} : s0;
    assign amt[2] = shift4;

    // Stage 2: Check if top 2 bits are zero, shift by 2 if so
    logic shift2;
    assign shift2 = (s1[12:11] == 2'b0);
    assign s2 = shift2 ? {s1[10:0], 2'b0} : s1;
    assign amt[1] = shift2;

    // Stage 3: Check if top bit is zero, shift by 1 if so
    logic shift1;
    assign shift1 = (s2[12] == 1'b0);
    assign s3 = shift1 ? {s2[11:0], 1'b0} : s2;
    assign amt[0] = shift1;

    // Output with zero guard: return 0 shift for zero input
    assign result = s3;
    assign shifted_amount = is_zero ? 4'd0 : amt;

endmodule
