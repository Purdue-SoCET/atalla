`timescale 1ps/1ps
// FP16 Pipelined Adder for Vector Core
// Input latch stage + add_fp core instantiation
//
// Timing: reg > (add_fp: comb > reg > comb > reg) (3-cycle latency, stall-able)
// Submodule: add_fp
//   Cycle 0: input latch (fp1_lat, fp2_lat, sub_lat)
//   Cycle 1-2: add_fp core (1 pipeline reg + 1 output reg inside)
//
// Parameters:
//   MANT_W - mantissa width (default 10 for FP16)
//   EXP_W  - exponent width (default 5 for FP16)

module add_fp16_VC #(
    parameter MANT_W = 10,
    parameter EXP_W  = 5,
    localparam FP_W  = 1 + EXP_W + MANT_W
) (
    input logic clk,
    input logic nRST,
    input logic start,
    input logic stall,
    input logic sub,
    input logic [FP_W-1:0] fp1_in,
    input logic [FP_W-1:0] fp2_in,
    output logic [FP_W-1:0] fp_out,
    output logic done
);

    // Cycle 0: Input Latch
    logic [FP_W-1:0] fp1_lat, fp2_lat;
    logic sub_lat;
    logic stage0_valid;

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            fp1_lat <= '0;
            fp2_lat <= '0;
            sub_lat <= '0;
            stage0_valid <= '0;
        end
        else if (stall) begin
            fp1_lat <= fp1_lat;
            fp2_lat <= fp2_lat;
            sub_lat <= sub_lat;
            stage0_valid <= stage0_valid;
        end
        else begin
            fp1_lat <= fp1_in;
            fp2_lat <= fp2_in;
            sub_lat <= sub;
            stage0_valid <= start;
        end
    end

    // Adder core
    add_fp #(
        .MANT_W(MANT_W),
        .EXP_W(EXP_W)
    ) addy (
        .clk(clk),
        .nRST(nRST),
        .stall(stall),
        .start(stage0_valid),
        .sub(sub_lat),
        .fp1_in(fp1_lat),
        .fp2_in(fp2_lat),
        .fp_out(fp_out),
        .done(done)
    );

endmodule
