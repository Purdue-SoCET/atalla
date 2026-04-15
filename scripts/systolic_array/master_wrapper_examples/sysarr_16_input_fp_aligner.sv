`timescale 1ns/1ps
module sysarr_16_input_fp_aligner #(
    parameter EXPONENT_SIZE = 8,
    parameter MANTISSA_SIZE = 23,
    parameter NEW_MANT_WIDTH = 27
) (
    input  logic clk, nRST,
    input  logic [1+EXPONENT_SIZE+MANTISSA_SIZE-1:0] in_fp [0:15],
    output logic [EXPONENT_SIZE-1:0] out_max_exp,
    output logic sign_out [0:15],
    output logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:15]
);

    // --- Stage 0: Unpack & Append Hidden Bit ---
    logic [EXPONENT_SIZE-1:0] exp_base [0:15];
    logic sign_base [0:15];
    logic [NEW_MANT_WIDTH-1:0] mant_base [0:15];

    always_comb begin
        for (int i = 0; i < 16; i++) begin
            sign_base[i] = in_fp[i][EXPONENT_SIZE+MANTISSA_SIZE];
            exp_base[i]  = in_fp[i][MANTISSA_SIZE +: EXPONENT_SIZE];
            // Add hidden bit if exp > 0, append precision bits
            mant_base[i] = { (|exp_base[i]), in_fp[i][MANTISSA_SIZE-1:0], {3{1'b0}} };
        end
    end

    // --- Max Exponent Tree ---
    // Level 0 (Nodes: 16)
    logic [EXPONENT_SIZE-1:0] max_l0_n0_c;
    assign max_l0_n0_c = (exp_base[0] > exp_base[1]) ? exp_base[0] : exp_base[1];
    logic [EXPONENT_SIZE-1:0] max_l0_n1_c;
    assign max_l0_n1_c = (exp_base[2] > exp_base[3]) ? exp_base[2] : exp_base[3];
    logic [EXPONENT_SIZE-1:0] max_l0_n2_c;
    assign max_l0_n2_c = (exp_base[4] > exp_base[5]) ? exp_base[4] : exp_base[5];
    logic [EXPONENT_SIZE-1:0] max_l0_n3_c;
    assign max_l0_n3_c = (exp_base[6] > exp_base[7]) ? exp_base[6] : exp_base[7];
    logic [EXPONENT_SIZE-1:0] max_l0_n4_c;
    assign max_l0_n4_c = (exp_base[8] > exp_base[9]) ? exp_base[8] : exp_base[9];
    logic [EXPONENT_SIZE-1:0] max_l0_n5_c;
    assign max_l0_n5_c = (exp_base[10] > exp_base[11]) ? exp_base[10] : exp_base[11];
    logic [EXPONENT_SIZE-1:0] max_l0_n6_c;
    assign max_l0_n6_c = (exp_base[12] > exp_base[13]) ? exp_base[12] : exp_base[13];
    logic [EXPONENT_SIZE-1:0] max_l0_n7_c;
    assign max_l0_n7_c = (exp_base[14] > exp_base[15]) ? exp_base[14] : exp_base[15];
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            max_l0_n0_r <= '0;
            max_l0_n1_r <= '0;
            max_l0_n2_r <= '0;
            max_l0_n3_r <= '0;
            max_l0_n4_r <= '0;
            max_l0_n5_r <= '0;
            max_l0_n6_r <= '0;
            max_l0_n7_r <= '0;
        end else begin
            max_l0_n0_r <= max_l0_n0_c;
            max_l0_n1_r <= max_l0_n1_c;
            max_l0_n2_r <= max_l0_n2_c;
            max_l0_n3_r <= max_l0_n3_c;
            max_l0_n4_r <= max_l0_n4_c;
            max_l0_n5_r <= max_l0_n5_c;
            max_l0_n6_r <= max_l0_n6_c;
            max_l0_n7_r <= max_l0_n7_c;
        end
    end
    logic [EXPONENT_SIZE-1:0] max_l0_n0_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n1_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n2_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n3_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n4_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n5_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n6_r;
    logic [EXPONENT_SIZE-1:0] max_l0_n7_r;

    // Level 1 (Nodes: 8)
    logic [EXPONENT_SIZE-1:0] max_l1_n0_c;
    assign max_l1_n0_c = (max_l0_n0_r > max_l0_n1_r) ? max_l0_n0_r : max_l0_n1_r;
    logic [EXPONENT_SIZE-1:0] max_l1_n1_c;
    assign max_l1_n1_c = (max_l0_n2_r > max_l0_n3_r) ? max_l0_n2_r : max_l0_n3_r;
    logic [EXPONENT_SIZE-1:0] max_l1_n2_c;
    assign max_l1_n2_c = (max_l0_n4_r > max_l0_n5_r) ? max_l0_n4_r : max_l0_n5_r;
    logic [EXPONENT_SIZE-1:0] max_l1_n3_c;
    assign max_l1_n3_c = (max_l0_n6_r > max_l0_n7_r) ? max_l0_n6_r : max_l0_n7_r;

    // Level 2 (Nodes: 4)
    logic [EXPONENT_SIZE-1:0] max_l2_n0_c;
    assign max_l2_n0_c = (max_l1_n0_c > max_l1_n1_c) ? max_l1_n0_c : max_l1_n1_c;
    logic [EXPONENT_SIZE-1:0] max_l2_n1_c;
    assign max_l2_n1_c = (max_l1_n2_c > max_l1_n3_c) ? max_l1_n2_c : max_l1_n3_c;
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            max_l2_n0_r <= '0;
            max_l2_n1_r <= '0;
        end else begin
            max_l2_n0_r <= max_l2_n0_c;
            max_l2_n1_r <= max_l2_n1_c;
        end
    end
    logic [EXPONENT_SIZE-1:0] max_l2_n0_r;
    logic [EXPONENT_SIZE-1:0] max_l2_n1_r;

    // Level 3 (Nodes: 2)
    logic [EXPONENT_SIZE-1:0] max_l3_n0_c;
    assign max_l3_n0_c = (max_l2_n0_r > max_l2_n1_r) ? max_l2_n0_r : max_l2_n1_r;

    // --- Payload Delay Matching (Latency: 2 cycles) ---
    logic sign_dly  [0:2][0:15];
    logic [EXPONENT_SIZE-1:0] exp_dly   [0:2][0:15];
    logic [NEW_MANT_WIDTH-1:0] mant_dly [0:2][0:15];

    always_comb begin
        for (int i = 0; i < 16; i++) begin
            sign_dly[0][i] = sign_base[i];
            exp_dly[0][i]  = exp_base[i];
            mant_dly[0][i] = mant_base[i];
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            for (int d = 1; d <= 2; d++) begin
                for (int i = 0; i < 16; i++) begin
                    sign_dly[d][i] <= '0;
                    exp_dly[d][i]  <= '0;
                    mant_dly[d][i] <= '0;
                end
            end
        end else begin
            for (int d = 1; d <= 2; d++) begin
                for (int i = 0; i < 16; i++) begin
                    sign_dly[d][i] <= sign_dly[d-1][i];
                    exp_dly[d][i]  <= exp_dly[d-1][i];
                    mant_dly[d][i] <= mant_dly[d-1][i];
                end
            end
        end
    end

    // --- Alignment & Shift ---
    logic [EXPONENT_SIZE:0] shift_amt [0:15];
    logic [NEW_MANT_WIDTH-1:0] shifted_mant_c [0:15];
    logic sticky_bit [0:15];

    always_comb begin
        for (int i = 0; i < 16; i++) begin
            shift_amt[i] = max_l3_n0_c - exp_dly[2][i];
            // Determine if any 1s are shifted out (Sticky bit approximation)
            sticky_bit[i] = |(mant_dly[2][i] & ~({NEW_MANT_WIDTH{1'b1}} << shift_amt[i]));
            
            if (shift_amt[i] >= NEW_MANT_WIDTH) begin
                shifted_mant_c[i] = '0;
            end else begin
                shifted_mant_c[i] = mant_dly[2][i] >> shift_amt[i];
                shifted_mant_c[i][0] = shifted_mant_c[i][0] | sticky_bit[i]; // OR sticky into LSB
            end
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            out_max_exp <= '0;
            for (int i = 0; i < 16; i++) begin
                sign_out[i] <= '0;
                aligned_mant_out[i] <= '0;
            end
        end else begin
            out_max_exp <= max_l3_n0_c;
            for (int i = 0; i < 16; i++) begin
                sign_out[i] <= sign_dly[2][i];
                aligned_mant_out[i] <= shifted_mant_c[i];
            end
        end
    end
endmodule