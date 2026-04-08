`timescale 1ns/1ps
module V0_5_S2_cfg_1 #(parameter int WIDTH = 32) (
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

    // --- Stage 0: 15-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c = cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + cur[5] + cur[6] + cur[7] + cur[8] + cur[9] + cur[10] + cur[11] + cur[12] + cur[13] + cur[14];

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            s0_g0_r <= '0;
            s0_g1_r <= '0;
        end else begin
            s0_g0_r <= s0_g0_c;
            s0_g1_r <= cur[15];
        end
    end

    logic [EXT_WIDTH-1:0] s0_g0_r;
    logic [EXT_WIDTH-1:0] s0_g1_r;

    // --- Stage 1: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c = s0_g0_r + s0_g1_r;
    logic [EXT_WIDTH-1:0] s1_g0_r = s1_g0_c;

    assign out_sum = s1_g0_r;
endmodule