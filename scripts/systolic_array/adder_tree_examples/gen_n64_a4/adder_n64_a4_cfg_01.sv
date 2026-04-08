// Auto-generated Adder Tree | Configuration: 01 (1=Reg, 0=Comb)
// Number of Inputs: 64 | Radix: 4
module adder_n64_a4_cfg_01 #(
    parameter int WIDTH = 32  // Parameterizable Input Width
) (
    input  logic clk, nRST,
    input  logic [WIDTH-1:0] in [0:63],
    output logic [(WIDTH + 6)-1:0] out_sum
);

    localparam int EXT_BITS = 6;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] current_sigs [0:63];
    always_comb begin
        for (int i = 0; i < 64; i++) begin
            current_sigs[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
        end
    end

    // --- Level 0 reduction ---
    logic [EXT_WIDTH-1:0] l0_g0_comb = current_sigs[0] + current_sigs[1] + current_sigs[2] + current_sigs[3];
    logic [EXT_WIDTH-1:0] l0_g1_comb = current_sigs[4] + current_sigs[5] + current_sigs[6] + current_sigs[7];
    logic [EXT_WIDTH-1:0] l0_g2_comb = current_sigs[8] + current_sigs[9] + current_sigs[10] + current_sigs[11];
    logic [EXT_WIDTH-1:0] l0_g3_comb = current_sigs[12] + current_sigs[13] + current_sigs[14] + current_sigs[15];
    logic [EXT_WIDTH-1:0] l0_g4_comb = current_sigs[16] + current_sigs[17] + current_sigs[18] + current_sigs[19];
    logic [EXT_WIDTH-1:0] l0_g5_comb = current_sigs[20] + current_sigs[21] + current_sigs[22] + current_sigs[23];
    logic [EXT_WIDTH-1:0] l0_g6_comb = current_sigs[24] + current_sigs[25] + current_sigs[26] + current_sigs[27];
    logic [EXT_WIDTH-1:0] l0_g7_comb = current_sigs[28] + current_sigs[29] + current_sigs[30] + current_sigs[31];
    logic [EXT_WIDTH-1:0] l0_g8_comb = current_sigs[32] + current_sigs[33] + current_sigs[34] + current_sigs[35];
    logic [EXT_WIDTH-1:0] l0_g9_comb = current_sigs[36] + current_sigs[37] + current_sigs[38] + current_sigs[39];
    logic [EXT_WIDTH-1:0] l0_g10_comb = current_sigs[40] + current_sigs[41] + current_sigs[42] + current_sigs[43];
    logic [EXT_WIDTH-1:0] l0_g11_comb = current_sigs[44] + current_sigs[45] + current_sigs[46] + current_sigs[47];
    logic [EXT_WIDTH-1:0] l0_g12_comb = current_sigs[48] + current_sigs[49] + current_sigs[50] + current_sigs[51];
    logic [EXT_WIDTH-1:0] l0_g13_comb = current_sigs[52] + current_sigs[53] + current_sigs[54] + current_sigs[55];
    logic [EXT_WIDTH-1:0] l0_g14_comb = current_sigs[56] + current_sigs[57] + current_sigs[58] + current_sigs[59];
    logic [EXT_WIDTH-1:0] l0_g15_comb = current_sigs[60] + current_sigs[61] + current_sigs[62] + current_sigs[63];
    // --- Level 1 reduction ---
    logic [EXT_WIDTH-1:0] l1_g0_comb = l0_g0_comb + l0_g1_comb + l0_g2_comb + l0_g3_comb;
    logic [EXT_WIDTH-1:0] l1_g1_comb = l0_g4_comb + l0_g5_comb + l0_g6_comb + l0_g7_comb;
    logic [EXT_WIDTH-1:0] l1_g2_comb = l0_g8_comb + l0_g9_comb + l0_g10_comb + l0_g11_comb;
    logic [EXT_WIDTH-1:0] l1_g3_comb = l0_g12_comb + l0_g13_comb + l0_g14_comb + l0_g15_comb;

    // --- Pipeline Register Stage (Post-Level 1) ---
    logic [EXT_WIDTH-1:0] l1_reg_0;
    logic [EXT_WIDTH-1:0] l1_reg_1;
    logic [EXT_WIDTH-1:0] l1_reg_2;
    logic [EXT_WIDTH-1:0] l1_reg_3;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            l1_reg_0 <= '0;
            l1_reg_1 <= '0;
            l1_reg_2 <= '0;
            l1_reg_3 <= '0;
        end else begin
            l1_reg_0 <= l1_g0_comb;
            l1_reg_1 <= l1_g1_comb;
            l1_reg_2 <= l1_g2_comb;
            l1_reg_3 <= l1_g3_comb;
        end
    end

    // --- Level 2 reduction ---
    logic [EXT_WIDTH-1:0] l2_g0_comb = l1_reg_0 + l1_reg_1 + l1_reg_2 + l1_reg_3;
    assign out_sum = l2_g0_comb;
endmodule