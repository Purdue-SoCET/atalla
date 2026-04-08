// Auto-generated Adder Tree | Configuration: 11 (1=Reg, 0=Comb)
// Number of Inputs: 32 | Radix: 4
module adder_n32_a4_cfg_11 #(
    parameter int WIDTH = 32  // Parameterizable Input Width
) (
    input  logic clk, nRST,
    input  logic [WIDTH-1:0] in [0:31],
    output logic [(WIDTH + 5)-1:0] out_sum
);

    localparam int EXT_BITS = 5;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] current_sigs [0:31];
    always_comb begin
        for (int i = 0; i < 32; i++) begin
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

    // --- Pipeline Register Stage (Post-Level 0) ---
    logic [EXT_WIDTH-1:0] l0_reg_0;
    logic [EXT_WIDTH-1:0] l0_reg_1;
    logic [EXT_WIDTH-1:0] l0_reg_2;
    logic [EXT_WIDTH-1:0] l0_reg_3;
    logic [EXT_WIDTH-1:0] l0_reg_4;
    logic [EXT_WIDTH-1:0] l0_reg_5;
    logic [EXT_WIDTH-1:0] l0_reg_6;
    logic [EXT_WIDTH-1:0] l0_reg_7;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            l0_reg_0 <= '0;
            l0_reg_1 <= '0;
            l0_reg_2 <= '0;
            l0_reg_3 <= '0;
            l0_reg_4 <= '0;
            l0_reg_5 <= '0;
            l0_reg_6 <= '0;
            l0_reg_7 <= '0;
        end else begin
            l0_reg_0 <= l0_g0_comb;
            l0_reg_1 <= l0_g1_comb;
            l0_reg_2 <= l0_g2_comb;
            l0_reg_3 <= l0_g3_comb;
            l0_reg_4 <= l0_g4_comb;
            l0_reg_5 <= l0_g5_comb;
            l0_reg_6 <= l0_g6_comb;
            l0_reg_7 <= l0_g7_comb;
        end
    end

    // --- Level 1 reduction ---
    logic [EXT_WIDTH-1:0] l1_g0_comb = l0_reg_0 + l0_reg_1 + l0_reg_2 + l0_reg_3;
    logic [EXT_WIDTH-1:0] l1_g1_comb = l0_reg_4 + l0_reg_5 + l0_reg_6 + l0_reg_7;

    // --- Pipeline Register Stage (Post-Level 1) ---
    logic [EXT_WIDTH-1:0] l1_reg_0;
    logic [EXT_WIDTH-1:0] l1_reg_1;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            l1_reg_0 <= '0;
            l1_reg_1 <= '0;
        end else begin
            l1_reg_0 <= l1_g0_comb;
            l1_reg_1 <= l1_g1_comb;
        end
    end

    // --- Level 2 reduction ---
    logic [EXT_WIDTH-1:0] l2_g0_comb = l1_reg_0 + l1_reg_1;
    assign out_sum = l2_g0_comb;
endmodule