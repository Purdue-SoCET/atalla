// Auto-generated Adder Tree | Configuration: 1 (1=Reg, 0=Comb)
// Number of Inputs: 128 | Radix: 32
module adder_n128_a32_cfg_1 #(
    parameter int WIDTH = 32  // Parameterizable Input Width
) (
    input  logic clk, nRST,
    input  logic [WIDTH-1:0] in [0:127],
    output logic [(WIDTH + 7)-1:0] out_sum
);

    localparam int EXT_BITS = 7;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] current_sigs [0:127];
    always_comb begin
        for (int i = 0; i < 128; i++) begin
            current_sigs[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
        end
    end

    // --- Level 0 reduction ---
    logic [EXT_WIDTH-1:0] l0_g0_comb = current_sigs[0] + current_sigs[1] + current_sigs[2] + current_sigs[3] + current_sigs[4] + current_sigs[5] + current_sigs[6] + current_sigs[7] + current_sigs[8] + current_sigs[9] + current_sigs[10] + current_sigs[11] + current_sigs[12] + current_sigs[13] + current_sigs[14] + current_sigs[15] + current_sigs[16] + current_sigs[17] + current_sigs[18] + current_sigs[19] + current_sigs[20] + current_sigs[21] + current_sigs[22] + current_sigs[23] + current_sigs[24] + current_sigs[25] + current_sigs[26] + current_sigs[27] + current_sigs[28] + current_sigs[29] + current_sigs[30] + current_sigs[31];
    logic [EXT_WIDTH-1:0] l0_g1_comb = current_sigs[32] + current_sigs[33] + current_sigs[34] + current_sigs[35] + current_sigs[36] + current_sigs[37] + current_sigs[38] + current_sigs[39] + current_sigs[40] + current_sigs[41] + current_sigs[42] + current_sigs[43] + current_sigs[44] + current_sigs[45] + current_sigs[46] + current_sigs[47] + current_sigs[48] + current_sigs[49] + current_sigs[50] + current_sigs[51] + current_sigs[52] + current_sigs[53] + current_sigs[54] + current_sigs[55] + current_sigs[56] + current_sigs[57] + current_sigs[58] + current_sigs[59] + current_sigs[60] + current_sigs[61] + current_sigs[62] + current_sigs[63];
    logic [EXT_WIDTH-1:0] l0_g2_comb = current_sigs[64] + current_sigs[65] + current_sigs[66] + current_sigs[67] + current_sigs[68] + current_sigs[69] + current_sigs[70] + current_sigs[71] + current_sigs[72] + current_sigs[73] + current_sigs[74] + current_sigs[75] + current_sigs[76] + current_sigs[77] + current_sigs[78] + current_sigs[79] + current_sigs[80] + current_sigs[81] + current_sigs[82] + current_sigs[83] + current_sigs[84] + current_sigs[85] + current_sigs[86] + current_sigs[87] + current_sigs[88] + current_sigs[89] + current_sigs[90] + current_sigs[91] + current_sigs[92] + current_sigs[93] + current_sigs[94] + current_sigs[95];
    logic [EXT_WIDTH-1:0] l0_g3_comb = current_sigs[96] + current_sigs[97] + current_sigs[98] + current_sigs[99] + current_sigs[100] + current_sigs[101] + current_sigs[102] + current_sigs[103] + current_sigs[104] + current_sigs[105] + current_sigs[106] + current_sigs[107] + current_sigs[108] + current_sigs[109] + current_sigs[110] + current_sigs[111] + current_sigs[112] + current_sigs[113] + current_sigs[114] + current_sigs[115] + current_sigs[116] + current_sigs[117] + current_sigs[118] + current_sigs[119] + current_sigs[120] + current_sigs[121] + current_sigs[122] + current_sigs[123] + current_sigs[124] + current_sigs[125] + current_sigs[126] + current_sigs[127];

    // --- Pipeline Register Stage (Post-Level 0) ---
    logic [EXT_WIDTH-1:0] l0_reg_0;
    logic [EXT_WIDTH-1:0] l0_reg_1;
    logic [EXT_WIDTH-1:0] l0_reg_2;
    logic [EXT_WIDTH-1:0] l0_reg_3;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            l0_reg_0 <= '0;
            l0_reg_1 <= '0;
            l0_reg_2 <= '0;
            l0_reg_3 <= '0;
        end else begin
            l0_reg_0 <= l0_g0_comb;
            l0_reg_1 <= l0_g1_comb;
            l0_reg_2 <= l0_g2_comb;
            l0_reg_3 <= l0_g3_comb;
        end
    end

    // --- Level 1 reduction ---
    logic [EXT_WIDTH-1:0] l1_g0_comb = l0_reg_0 + l0_reg_1 + l0_reg_2 + l0_reg_3;
    assign out_sum = l1_g0_comb;
endmodule