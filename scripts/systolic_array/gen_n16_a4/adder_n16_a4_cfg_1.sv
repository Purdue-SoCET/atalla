// Auto-generated Adder Tree | Configuration: 1 (1=Reg, 0=Comb)
// Number of Inputs: 16 | Radix: 4
module adder_n16_a4_cfg_1 #(
    parameter int WIDTH = 32  // Parameterizable Input Width
) (
    input  logic clk, nRST,
    input  logic [WIDTH-1:0] in [0:15],
    output logic [(WIDTH + 4)-1:0] out_sum
);

    localparam int EXT_BITS = 4;
    localparam int EXT_WIDTH = WIDTH + EXT_BITS;

    logic [EXT_WIDTH-1:0] current_sigs [0:15];
    always_comb begin
        for (int i = 0; i < 16; i++) begin
            current_sigs[i] = { {EXT_BITS{in[i][WIDTH-1]}}, in[i] };
        end
    end

    // --- Level 0 reduction ---
    logic [EXT_WIDTH-1:0] l0_g0_comb = current_sigs[0] + current_sigs[1] + current_sigs[2] + current_sigs[3];
    logic [EXT_WIDTH-1:0] l0_g1_comb = current_sigs[4] + current_sigs[5] + current_sigs[6] + current_sigs[7];
    logic [EXT_WIDTH-1:0] l0_g2_comb = current_sigs[8] + current_sigs[9] + current_sigs[10] + current_sigs[11];
    logic [EXT_WIDTH-1:0] l0_g3_comb = current_sigs[12] + current_sigs[13] + current_sigs[14] + current_sigs[15];

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