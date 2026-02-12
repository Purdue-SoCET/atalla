`timescale 1ns/1ps

module adder (
    input  logic a,
    input  logic b,
    output logic sum
);
    assign sum = a ^ b;
endmodule
