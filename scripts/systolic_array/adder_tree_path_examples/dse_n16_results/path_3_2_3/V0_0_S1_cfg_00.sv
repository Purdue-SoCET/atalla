`timescale 1ns/1ps
module V0_0_S1_cfg_00 #(parameter int WIDTH = 32) (
    input logic clk, nRST,
    input logic [WIDTH-1:0] in [0:15],
    output logic [(WIDTH + 4)-1:0] out_sum
);

    localparam int EXT_BITS = 4;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] cur [0:15];
    always_comb begin
        for (int i = 0; i < 16; i++)
            cur[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
    end

    // --- Stage 0: 3-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c = cur[0] + cur[1] + cur[2];
    logic [EXT_WIDTH-1:0] s0_g1_c = cur[3] + cur[4] + cur[5];
    logic [EXT_WIDTH-1:0] s0_g2_c = cur[6] + cur[7] + cur[8];
    logic [EXT_WIDTH-1:0] s0_g3_c = cur[9] + cur[10] + cur[11];
    logic [EXT_WIDTH-1:0] s0_g4_c = cur[12] + cur[13] + cur[14];
    logic [EXT_WIDTH-1:0] s0_g0_r = s0_g0_c;
    logic [EXT_WIDTH-1:0] s0_g1_r = s0_g1_c;
    logic [EXT_WIDTH-1:0] s0_g2_r = s0_g2_c;
    logic [EXT_WIDTH-1:0] s0_g3_r = s0_g3_c;
    logic [EXT_WIDTH-1:0] s0_g4_r = s0_g4_c;
    logic [EXT_WIDTH-1:0] s0_g5_r = cur[15];

    // --- Stage 1: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c = s0_g0_r + s0_g1_r;
    logic [EXT_WIDTH-1:0] s1_g1_c = s0_g2_r + s0_g3_r;
    logic [EXT_WIDTH-1:0] s1_g2_c = s0_g4_r + s0_g5_r;
    logic [EXT_WIDTH-1:0] s1_g0_r = s1_g0_c;
    logic [EXT_WIDTH-1:0] s1_g1_r = s1_g1_c;
    logic [EXT_WIDTH-1:0] s1_g2_r = s1_g2_c;

    // --- Stage 2: 3-way Reduction ---
    logic [EXT_WIDTH-1:0] s2_g0_c = s1_g0_r + s1_g1_r + s1_g2_r;
    logic [EXT_WIDTH-1:0] s2_g0_r = s2_g0_c;

    assign out_sum = s2_g0_r;
endmodule