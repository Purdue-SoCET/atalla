`timescale 1ns/1ps
// FP16 Pipelined Multiplier for Vector Core 
// Input latch stage + core instantiation
// Author : Myles Querimit (Reference Vinay Pundith)
// passes all SoftFloat vectors after subnormal boundary rounding fix

module mul_fp16_VC(
    input logic clk,
    input logic nRST,
    input logic start,
    input logic stall,
    input logic [15:0] a, b,
    output logic [15:0] result,
    output logic done
);

    // Cycle 1: Input Latch
    logic [15:0] a_lat, b_lat;
    logic stage0_valid;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            a_lat <= '0;
            b_lat <= '0;
            stage0_valid <= '0;
        end
        else if (stall) begin
            a_lat <= a_lat;
            b_lat <= b_lat;
            stage0_valid <= stage0_valid;
        end
        else begin
            a_lat <= a;
            b_lat <= b;
            stage0_valid <= start;
        end
    end

    // multiply core 
    mul_fp16 multy (
        .clk(clk),
        .nRST(nRST),
        .stall(stall),
        .start(stage0_valid),
        .a(a_lat),
        .b(b_lat),
        .result(result),
        .done(done)
    );

endmodule
