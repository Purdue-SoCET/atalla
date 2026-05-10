`timescale 1ns/1ps
module V0_333_S3_cfg_11 #(parameter int WIDTH = 32) (
    input logic clk, nRST,
    input logic [WIDTH-1:0] in [0:31],
    output logic [(WIDTH + 5)-1:0] out_sum
);

    localparam int EXT_BITS = 5;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] cur [0:31];
    always_comb begin
        for (int i = 0; i < 32; i++)
            cur[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
    end

    // --- Stage 0: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c;
    assign s0_g0_c = cur[0] + cur[1];
    logic [EXT_WIDTH-1:0] s0_g1_c;
    assign s0_g1_c = cur[2] + cur[3];
    logic [EXT_WIDTH-1:0] s0_g2_c;
    assign s0_g2_c = cur[4] + cur[5];
    logic [EXT_WIDTH-1:0] s0_g3_c;
    assign s0_g3_c = cur[6] + cur[7];
    logic [EXT_WIDTH-1:0] s0_g4_c;
    assign s0_g4_c = cur[8] + cur[9];
    logic [EXT_WIDTH-1:0] s0_g5_c;
    assign s0_g5_c = cur[10] + cur[11];
    logic [EXT_WIDTH-1:0] s0_g6_c;
    assign s0_g6_c = cur[12] + cur[13];
    logic [EXT_WIDTH-1:0] s0_g7_c;
    assign s0_g7_c = cur[14] + cur[15];
    logic [EXT_WIDTH-1:0] s0_g8_c;
    assign s0_g8_c = cur[16] + cur[17];
    logic [EXT_WIDTH-1:0] s0_g9_c;
    assign s0_g9_c = cur[18] + cur[19];
    logic [EXT_WIDTH-1:0] s0_g10_c;
    assign s0_g10_c = cur[20] + cur[21];
    logic [EXT_WIDTH-1:0] s0_g11_c;
    assign s0_g11_c = cur[22] + cur[23];
    logic [EXT_WIDTH-1:0] s0_g12_c;
    assign s0_g12_c = cur[24] + cur[25];
    logic [EXT_WIDTH-1:0] s0_g13_c;
    assign s0_g13_c = cur[26] + cur[27];
    logic [EXT_WIDTH-1:0] s0_g14_c;
    assign s0_g14_c = cur[28] + cur[29];
    logic [EXT_WIDTH-1:0] s0_g15_c;
    assign s0_g15_c = cur[30] + cur[31];
    logic [EXT_WIDTH-1:0] s0_g0_r;
    logic [EXT_WIDTH-1:0] s0_g1_r;
    logic [EXT_WIDTH-1:0] s0_g2_r;
    logic [EXT_WIDTH-1:0] s0_g3_r;
    logic [EXT_WIDTH-1:0] s0_g4_r;
    logic [EXT_WIDTH-1:0] s0_g5_r;
    logic [EXT_WIDTH-1:0] s0_g6_r;
    logic [EXT_WIDTH-1:0] s0_g7_r;
    logic [EXT_WIDTH-1:0] s0_g8_r;
    logic [EXT_WIDTH-1:0] s0_g9_r;
    logic [EXT_WIDTH-1:0] s0_g10_r;
    logic [EXT_WIDTH-1:0] s0_g11_r;
    logic [EXT_WIDTH-1:0] s0_g12_r;
    logic [EXT_WIDTH-1:0] s0_g13_r;
    logic [EXT_WIDTH-1:0] s0_g14_r;
    logic [EXT_WIDTH-1:0] s0_g15_r;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            s0_g0_r <= '0;
            s0_g1_r <= '0;
            s0_g2_r <= '0;
            s0_g3_r <= '0;
            s0_g4_r <= '0;
            s0_g5_r <= '0;
            s0_g6_r <= '0;
            s0_g7_r <= '0;
            s0_g8_r <= '0;
            s0_g9_r <= '0;
            s0_g10_r <= '0;
            s0_g11_r <= '0;
            s0_g12_r <= '0;
            s0_g13_r <= '0;
            s0_g14_r <= '0;
            s0_g15_r <= '0;
        end else begin
            s0_g0_r <= s0_g0_c;
            s0_g1_r <= s0_g1_c;
            s0_g2_r <= s0_g2_c;
            s0_g3_r <= s0_g3_c;
            s0_g4_r <= s0_g4_c;
            s0_g5_r <= s0_g5_c;
            s0_g6_r <= s0_g6_c;
            s0_g7_r <= s0_g7_c;
            s0_g8_r <= s0_g8_c;
            s0_g9_r <= s0_g9_c;
            s0_g10_r <= s0_g10_c;
            s0_g11_r <= s0_g11_c;
            s0_g12_r <= s0_g12_c;
            s0_g13_r <= s0_g13_c;
            s0_g14_r <= s0_g14_c;
            s0_g15_r <= s0_g15_c;
        end
    end


    // --- Stage 1: 4-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c;
    assign s1_g0_c = s0_g0_r + s0_g1_r + s0_g2_r + s0_g3_r;
    logic [EXT_WIDTH-1:0] s1_g1_c;
    assign s1_g1_c = s0_g4_r + s0_g5_r + s0_g6_r + s0_g7_r;
    logic [EXT_WIDTH-1:0] s1_g2_c;
    assign s1_g2_c = s0_g8_r + s0_g9_r + s0_g10_r + s0_g11_r;
    logic [EXT_WIDTH-1:0] s1_g3_c;
    assign s1_g3_c = s0_g12_r + s0_g13_r + s0_g14_r + s0_g15_r;
    logic [EXT_WIDTH-1:0] s1_g0_r;
    logic [EXT_WIDTH-1:0] s1_g1_r;
    logic [EXT_WIDTH-1:0] s1_g2_r;
    logic [EXT_WIDTH-1:0] s1_g3_r;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            s1_g0_r <= '0;
            s1_g1_r <= '0;
            s1_g2_r <= '0;
            s1_g3_r <= '0;
        end else begin
            s1_g0_r <= s1_g0_c;
            s1_g1_r <= s1_g1_c;
            s1_g2_r <= s1_g2_c;
            s1_g3_r <= s1_g3_c;
        end
    end


    // --- Stage 2: 4-way Reduction ---
    logic [EXT_WIDTH-1:0] s2_g0_c;
    assign s2_g0_c = s1_g0_r + s1_g1_r + s1_g2_r + s1_g3_r;
    logic [EXT_WIDTH-1:0] s2_g0_r;
    assign s2_g0_r = s2_g0_c;

    assign out_sum = s2_g0_r;
endmodule