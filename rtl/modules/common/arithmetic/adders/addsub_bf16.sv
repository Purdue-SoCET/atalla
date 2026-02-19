`timescale 1ns/1ps

// BF16 adder/subtractor (round-to-nearest-even).
// NOTE: Subtraction is implemented as bf1 + (-bf2) via bf2_eff.

module addsub_bf16 (
    input  logic clk,
    input  logic nRST,
    input  logic [15:0] bf1_in,
    input  logic [15:0] bf2_in,
    input  logic op, // 0 = add, 1 = sub
    output logic [15:0] bf_out,
    output logic overflow,
    output logic underflow,
    output logic invalid
);

    logic [15:0] bf2_eff;

    // For subtraction, flip bf2's sign bit.
    assign bf2_eff = {op ? ~bf2_in[15] : bf2_in[15], bf2_in[14:0]};

    add_bf16 add_sub (
        .clk(clk),
        .nRST(nRST),
        .bf1_in(bf1_in),
        .bf2_in(bf2_eff),
        .bf_out(bf_out),
        .overflow(overflow),
        .underflow(underflow),
        .invalid(invalid)
        );

endmodule