`timescale 1ns/1ps
// FP16 2 Multiplier with input and output latching NO STALL 
// Wraps mul_fp16_nolatch with registered inputs for use in vector core.
// For systolic array MAC use mul_fp16_nolatch directly.

module mul_fp16(input logic clk, input logic nRST, input logic start, input logic [15:0] a, b, output logic [15:0] result, output logic done);

    logic lat1_ready, lat2_ready;                           // Signal to denote when the value is ready at the latch stage.
    assign done = lat2_ready;                   // Mul result is ready when the value-latch register is ready - everything downstream of that is combinational.

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

    // Instantiate the combinational multiplier core
    logic [15:0] result_comb;
    mul_fp16_nolatch mul_core (.a(a_latched), .b(b_latched), .result(result_comb));

    // reg 2: latchout output 
    always_ff @(posedge clk, negedge nRST) begin
        if (nRST == 1'b0) begin
            result <= 0;
            lat2_ready <= 0;
        end 
        else begin
            result <= result_comb;
            lat2_ready <= lat1_ready;
        end
    end
endmodule
