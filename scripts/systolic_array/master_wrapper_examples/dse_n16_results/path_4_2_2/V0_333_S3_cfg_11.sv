`timescale 1ns/1ps
module V0_333_S3_cfg_11 #(parameter int WIDTH = 32) (
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

    // --- Stage 0: 4-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c = cur[0] + cur[1] + cur[2] + cur[3];
    logic [EXT_WIDTH-1:0] s0_g1_c = cur[4] + cur[5] + cur[6] + cur[7];
    logic [EXT_WIDTH-1:0] s0_g2_c = cur[8] + cur[9] + cur[10] + cur[11];
    logic [EXT_WIDTH-1:0] s0_g3_c = cur[12] + cur[13] + cur[14] + cur[15];

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            s0_g0_r <= '0;
            s0_g1_r <= '0;
            s0_g2_r <= '0;
            s0_g3_r <= '0;
        end else begin
            s0_g0_r <= s0_g0_c;
            s0_g1_r <= s0_g1_c;
            s0_g2_r <= s0_g2_c;
            s0_g3_r <= s0_g3_c;
        end
    end

    logic [EXT_WIDTH-1:0] s0_g0_r;
    logic [EXT_WIDTH-1:0] s0_g1_r;
    logic [EXT_WIDTH-1:0] s0_g2_r;
    logic [EXT_WIDTH-1:0] s0_g3_r;

    // --- Stage 1: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c = s0_g0_r + s0_g1_r;
    logic [EXT_WIDTH-1:0] s1_g1_c = s0_g2_r + s0_g3_r;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            s1_g0_r <= '0;
            s1_g1_r <= '0;
        end else begin
            s1_g0_r <= s1_g0_c;
            s1_g1_r <= s1_g1_c;
        end
    end

    logic [EXT_WIDTH-1:0] s1_g0_r;
    logic [EXT_WIDTH-1:0] s1_g1_r;

    // --- Stage 2: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s2_g0_c = s1_g0_r + s1_g1_r;
    logic [EXT_WIDTH-1:0] s2_g0_r = s2_g0_c;

    assign out_sum = s2_g0_r;
endmodule