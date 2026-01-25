`timescale 1ns/1ps

module addsub_bf16 (
    input  logic        clk,
    input  logic        nRST,
    input  logic        sub,        // 0 = add, 1 = subtract
    input  logic [15:0] bf1_in,
    input  logic [15:0] bf2_in,
    output logic [15:0] bf_out,
    output logic        overflow,
    output logic        underflow,
    output logic        invalid
);

    // Flip sign bit of bf2 if subtraction
    logic [15:0] bf2_eff;

    assign bf2_eff = sub ? {~bf2_in[15], bf2_in[14:0]} : bf2_in;

    // Reuse existing BF16 adder
    add_bf16 u_add_bf16 (
        .clk       (clk),
        .nRST      (nRST),
        .bf1_in    (bf1_in),
        .bf2_in    (bf2_eff),
        .bf_out    (bf_out),
        .overflow  (overflow),
        .underflow (underflow),
        .invalid   (invalid)
    );

endmodule
