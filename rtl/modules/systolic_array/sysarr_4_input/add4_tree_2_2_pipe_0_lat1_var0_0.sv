`timescale 1ns/1ps
module add4_tree_2_2_pipe_0_lat1_var0_0 #(parameter int WIDTH = 32) (
    input logic clk, nRST,
    input logic [WIDTH-1:0] in [0:3],
    output logic [(WIDTH + 2)-1:0] out_sum
);

    localparam int EXT_BITS = 2;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] cur [0:3];
    always_comb begin
        for (int i = 0; i < 4; i++)
            cur[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
    end

    // --- Stage 0: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s0_g0_c;
    assign s0_g0_c = cur[0] + cur[1];
    logic [EXT_WIDTH-1:0] s0_g1_c;
    assign s0_g1_c = cur[2] + cur[3];
    logic [EXT_WIDTH-1:0] s0_g0_r;
    logic [EXT_WIDTH-1:0] s0_g1_r;
    assign s0_g0_r = s0_g0_c;
    assign s0_g1_r = s0_g1_c;

    // --- Stage 1: 2-way Reduction ---
    logic [EXT_WIDTH-1:0] s1_g0_c;
    assign s1_g0_c = s0_g0_r + s0_g1_r;
    logic [EXT_WIDTH-1:0] s1_g0_r;
    assign s1_g0_r = s1_g0_c;

    assign out_sum = s1_g0_r;
endmodule