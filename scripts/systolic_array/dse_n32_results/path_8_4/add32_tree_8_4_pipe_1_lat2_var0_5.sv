`timescale 1ns/1ps
module add32_tree_8_4_pipe_1_lat2_var0_5 #(parameter int WIDTH = 32) (
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

    // --- Stage 0: 8-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c;
    assign s0_g0_c = cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + cur[5] + cur[6] + cur[7];
    logic [EXT_WIDTH-1:0] s0_g1_c;
    assign s0_g1_c = cur[8] + cur[9] + cur[10] + cur[11] + cur[12] + cur[13] + cur[14] + cur[15];
    logic [EXT_WIDTH-1:0] s0_g2_c;
    assign s0_g2_c = cur[16] + cur[17] + cur[18] + cur[19] + cur[20] + cur[21] + cur[22] + cur[23];
    logic [EXT_WIDTH-1:0] s0_g3_c;
    assign s0_g3_c = cur[24] + cur[25] + cur[26] + cur[27] + cur[28] + cur[29] + cur[30] + cur[31];
    logic [EXT_WIDTH-1:0] s0_g0_r;
    logic [EXT_WIDTH-1:0] s0_g1_r;
    logic [EXT_WIDTH-1:0] s0_g2_r;
    logic [EXT_WIDTH-1:0] s0_g3_r;
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


    // --- Stage 1: 4-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c;
    assign s1_g0_c = s0_g0_r + s0_g1_r + s0_g2_r + s0_g3_r;
    logic [EXT_WIDTH-1:0] s1_g0_r;
    assign s1_g0_r = s1_g0_c;

    assign out_sum = s1_g0_r;
endmodule