`timescale 1ns/1ps
module sysarr_32_input_fp_aligner #(
    parameter EXPONENT_SIZE = 8,
    parameter MANTISSA_SIZE = 23,
    parameter NEW_MANT_WIDTH = 27
) (
    input  logic clk, nRST,
    input  logic [1+EXPONENT_SIZE+MANTISSA_SIZE-1:0] in_fp [0:31],
    output logic [EXPONENT_SIZE-1:0] out_max_exp,
    output logic sign_out [0:31],
    output logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:31]
);

    // --- Stage 0: Unpack & Append Hidden Bit ---
    logic [EXPONENT_SIZE-1:0] exp_base [0:31];
    logic sign_base [0:31];
    logic [NEW_MANT_WIDTH-1:0] mant_base [0:31];

    always_comb begin
        for (int i = 0; i < 32; i++) begin
            sign_base[i] = in_fp[i][EXPONENT_SIZE+MANTISSA_SIZE];
            exp_base[i]  = in_fp[i][MANTISSA_SIZE +: EXPONENT_SIZE];
            // Add hidden bit if exp > 0, append precision bits
            mant_base[i] = { (|exp_base[i]), in_fp[i][MANTISSA_SIZE-1:0], {3{1'b0}} };
        end
    end

    // --- Max Exponent Tree (Tracking Max Exp and its Sign) ---
    // Level 0 (Nodes: 32)
    logic [EXPONENT_SIZE-1:0] max_l0_n0_c;
    logic sign_max_l0_n0_c;
    assign max_l0_n0_c = (exp_base[0] > exp_base[1]) ? exp_base[0] : exp_base[1];
    assign sign_max_l0_n0_c = (exp_base[0] > exp_base[1]) ? sign_base[0] : sign_base[1];
    logic [EXPONENT_SIZE-1:0] max_l0_n1_c;
    logic sign_max_l0_n1_c;
    assign max_l0_n1_c = (exp_base[2] > exp_base[3]) ? exp_base[2] : exp_base[3];
    assign sign_max_l0_n1_c = (exp_base[2] > exp_base[3]) ? sign_base[2] : sign_base[3];
    logic [EXPONENT_SIZE-1:0] max_l0_n2_c;
    logic sign_max_l0_n2_c;
    assign max_l0_n2_c = (exp_base[4] > exp_base[5]) ? exp_base[4] : exp_base[5];
    assign sign_max_l0_n2_c = (exp_base[4] > exp_base[5]) ? sign_base[4] : sign_base[5];
    logic [EXPONENT_SIZE-1:0] max_l0_n3_c;
    logic sign_max_l0_n3_c;
    assign max_l0_n3_c = (exp_base[6] > exp_base[7]) ? exp_base[6] : exp_base[7];
    assign sign_max_l0_n3_c = (exp_base[6] > exp_base[7]) ? sign_base[6] : sign_base[7];
    logic [EXPONENT_SIZE-1:0] max_l0_n4_c;
    logic sign_max_l0_n4_c;
    assign max_l0_n4_c = (exp_base[8] > exp_base[9]) ? exp_base[8] : exp_base[9];
    assign sign_max_l0_n4_c = (exp_base[8] > exp_base[9]) ? sign_base[8] : sign_base[9];
    logic [EXPONENT_SIZE-1:0] max_l0_n5_c;
    logic sign_max_l0_n5_c;
    assign max_l0_n5_c = (exp_base[10] > exp_base[11]) ? exp_base[10] : exp_base[11];
    assign sign_max_l0_n5_c = (exp_base[10] > exp_base[11]) ? sign_base[10] : sign_base[11];
    logic [EXPONENT_SIZE-1:0] max_l0_n6_c;
    logic sign_max_l0_n6_c;
    assign max_l0_n6_c = (exp_base[12] > exp_base[13]) ? exp_base[12] : exp_base[13];
    assign sign_max_l0_n6_c = (exp_base[12] > exp_base[13]) ? sign_base[12] : sign_base[13];
    logic [EXPONENT_SIZE-1:0] max_l0_n7_c;
    logic sign_max_l0_n7_c;
    assign max_l0_n7_c = (exp_base[14] > exp_base[15]) ? exp_base[14] : exp_base[15];
    assign sign_max_l0_n7_c = (exp_base[14] > exp_base[15]) ? sign_base[14] : sign_base[15];
    logic [EXPONENT_SIZE-1:0] max_l0_n8_c;
    logic sign_max_l0_n8_c;
    assign max_l0_n8_c = (exp_base[16] > exp_base[17]) ? exp_base[16] : exp_base[17];
    assign sign_max_l0_n8_c = (exp_base[16] > exp_base[17]) ? sign_base[16] : sign_base[17];
    logic [EXPONENT_SIZE-1:0] max_l0_n9_c;
    logic sign_max_l0_n9_c;
    assign max_l0_n9_c = (exp_base[18] > exp_base[19]) ? exp_base[18] : exp_base[19];
    assign sign_max_l0_n9_c = (exp_base[18] > exp_base[19]) ? sign_base[18] : sign_base[19];
    logic [EXPONENT_SIZE-1:0] max_l0_n10_c;
    logic sign_max_l0_n10_c;
    assign max_l0_n10_c = (exp_base[20] > exp_base[21]) ? exp_base[20] : exp_base[21];
    assign sign_max_l0_n10_c = (exp_base[20] > exp_base[21]) ? sign_base[20] : sign_base[21];
    logic [EXPONENT_SIZE-1:0] max_l0_n11_c;
    logic sign_max_l0_n11_c;
    assign max_l0_n11_c = (exp_base[22] > exp_base[23]) ? exp_base[22] : exp_base[23];
    assign sign_max_l0_n11_c = (exp_base[22] > exp_base[23]) ? sign_base[22] : sign_base[23];
    logic [EXPONENT_SIZE-1:0] max_l0_n12_c;
    logic sign_max_l0_n12_c;
    assign max_l0_n12_c = (exp_base[24] > exp_base[25]) ? exp_base[24] : exp_base[25];
    assign sign_max_l0_n12_c = (exp_base[24] > exp_base[25]) ? sign_base[24] : sign_base[25];
    logic [EXPONENT_SIZE-1:0] max_l0_n13_c;
    logic sign_max_l0_n13_c;
    assign max_l0_n13_c = (exp_base[26] > exp_base[27]) ? exp_base[26] : exp_base[27];
    assign sign_max_l0_n13_c = (exp_base[26] > exp_base[27]) ? sign_base[26] : sign_base[27];
    logic [EXPONENT_SIZE-1:0] max_l0_n14_c;
    logic sign_max_l0_n14_c;
    assign max_l0_n14_c = (exp_base[28] > exp_base[29]) ? exp_base[28] : exp_base[29];
    assign sign_max_l0_n14_c = (exp_base[28] > exp_base[29]) ? sign_base[28] : sign_base[29];
    logic [EXPONENT_SIZE-1:0] max_l0_n15_c;
    logic sign_max_l0_n15_c;
    assign max_l0_n15_c = (exp_base[30] > exp_base[31]) ? exp_base[30] : exp_base[31];
    assign sign_max_l0_n15_c = (exp_base[30] > exp_base[31]) ? sign_base[30] : sign_base[31];

    // Level 1 (Nodes: 16)
    logic [EXPONENT_SIZE-1:0] max_l1_n0_c;
    logic sign_max_l1_n0_c;
    assign max_l1_n0_c = (max_l0_n0_c > max_l0_n1_c) ? max_l0_n0_c : max_l0_n1_c;
    assign sign_max_l1_n0_c = (max_l0_n0_c > max_l0_n1_c) ? sign_max_l0_n0_c : sign_max_l0_n1_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n1_c;
    logic sign_max_l1_n1_c;
    assign max_l1_n1_c = (max_l0_n2_c > max_l0_n3_c) ? max_l0_n2_c : max_l0_n3_c;
    assign sign_max_l1_n1_c = (max_l0_n2_c > max_l0_n3_c) ? sign_max_l0_n2_c : sign_max_l0_n3_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n2_c;
    logic sign_max_l1_n2_c;
    assign max_l1_n2_c = (max_l0_n4_c > max_l0_n5_c) ? max_l0_n4_c : max_l0_n5_c;
    assign sign_max_l1_n2_c = (max_l0_n4_c > max_l0_n5_c) ? sign_max_l0_n4_c : sign_max_l0_n5_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n3_c;
    logic sign_max_l1_n3_c;
    assign max_l1_n3_c = (max_l0_n6_c > max_l0_n7_c) ? max_l0_n6_c : max_l0_n7_c;
    assign sign_max_l1_n3_c = (max_l0_n6_c > max_l0_n7_c) ? sign_max_l0_n6_c : sign_max_l0_n7_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n4_c;
    logic sign_max_l1_n4_c;
    assign max_l1_n4_c = (max_l0_n8_c > max_l0_n9_c) ? max_l0_n8_c : max_l0_n9_c;
    assign sign_max_l1_n4_c = (max_l0_n8_c > max_l0_n9_c) ? sign_max_l0_n8_c : sign_max_l0_n9_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n5_c;
    logic sign_max_l1_n5_c;
    assign max_l1_n5_c = (max_l0_n10_c > max_l0_n11_c) ? max_l0_n10_c : max_l0_n11_c;
    assign sign_max_l1_n5_c = (max_l0_n10_c > max_l0_n11_c) ? sign_max_l0_n10_c : sign_max_l0_n11_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n6_c;
    logic sign_max_l1_n6_c;
    assign max_l1_n6_c = (max_l0_n12_c > max_l0_n13_c) ? max_l0_n12_c : max_l0_n13_c;
    assign sign_max_l1_n6_c = (max_l0_n12_c > max_l0_n13_c) ? sign_max_l0_n12_c : sign_max_l0_n13_c;
    logic [EXPONENT_SIZE-1:0] max_l1_n7_c;
    logic sign_max_l1_n7_c;
    assign max_l1_n7_c = (max_l0_n14_c > max_l0_n15_c) ? max_l0_n14_c : max_l0_n15_c;
    assign sign_max_l1_n7_c = (max_l0_n14_c > max_l0_n15_c) ? sign_max_l0_n14_c : sign_max_l0_n15_c;

    // Level 2 (Nodes: 8)
    logic [EXPONENT_SIZE-1:0] max_l2_n0_c;
    logic sign_max_l2_n0_c;
    assign max_l2_n0_c = (max_l1_n0_c > max_l1_n1_c) ? max_l1_n0_c : max_l1_n1_c;
    assign sign_max_l2_n0_c = (max_l1_n0_c > max_l1_n1_c) ? sign_max_l1_n0_c : sign_max_l1_n1_c;
    logic [EXPONENT_SIZE-1:0] max_l2_n1_c;
    logic sign_max_l2_n1_c;
    assign max_l2_n1_c = (max_l1_n2_c > max_l1_n3_c) ? max_l1_n2_c : max_l1_n3_c;
    assign sign_max_l2_n1_c = (max_l1_n2_c > max_l1_n3_c) ? sign_max_l1_n2_c : sign_max_l1_n3_c;
    logic [EXPONENT_SIZE-1:0] max_l2_n2_c;
    logic sign_max_l2_n2_c;
    assign max_l2_n2_c = (max_l1_n4_c > max_l1_n5_c) ? max_l1_n4_c : max_l1_n5_c;
    assign sign_max_l2_n2_c = (max_l1_n4_c > max_l1_n5_c) ? sign_max_l1_n4_c : sign_max_l1_n5_c;
    logic [EXPONENT_SIZE-1:0] max_l2_n3_c;
    logic sign_max_l2_n3_c;
    assign max_l2_n3_c = (max_l1_n6_c > max_l1_n7_c) ? max_l1_n6_c : max_l1_n7_c;
    assign sign_max_l2_n3_c = (max_l1_n6_c > max_l1_n7_c) ? sign_max_l1_n6_c : sign_max_l1_n7_c;

    // Level 3 (Nodes: 4)
    logic [EXPONENT_SIZE-1:0] max_l3_n0_c;
    logic sign_max_l3_n0_c;
    assign max_l3_n0_c = (max_l2_n0_c > max_l2_n1_c) ? max_l2_n0_c : max_l2_n1_c;
    assign sign_max_l3_n0_c = (max_l2_n0_c > max_l2_n1_c) ? sign_max_l2_n0_c : sign_max_l2_n1_c;
    logic [EXPONENT_SIZE-1:0] max_l3_n1_c;
    logic sign_max_l3_n1_c;
    assign max_l3_n1_c = (max_l2_n2_c > max_l2_n3_c) ? max_l2_n2_c : max_l2_n3_c;
    assign sign_max_l3_n1_c = (max_l2_n2_c > max_l2_n3_c) ? sign_max_l2_n2_c : sign_max_l2_n3_c;

    // Level 4 (Nodes: 2)
    logic [EXPONENT_SIZE-1:0] max_l4_n0_c;
    logic sign_max_l4_n0_c;
    assign max_l4_n0_c = (max_l3_n0_c > max_l3_n1_c) ? max_l3_n0_c : max_l3_n1_c;
    assign sign_max_l4_n0_c = (max_l3_n0_c > max_l3_n1_c) ? sign_max_l3_n0_c : sign_max_l3_n1_c;

    // --- Payload Delay Matching (Latency: 0 cycles) ---
    logic sign_dly  [0:0][0:31];
    logic [EXPONENT_SIZE-1:0] exp_dly   [0:0][0:31];
    logic [NEW_MANT_WIDTH-1:0] mant_dly [0:0][0:31];

    always_comb begin
        for (int i = 0; i < 32; i++) begin
            sign_dly[0][i] = sign_base[i];
            exp_dly[0][i]  = exp_base[i];
            mant_dly[0][i] = mant_base[i];
        end
    end

    // --- Alignment, Sticky Logic, & 2's Complement ---
    logic [EXPONENT_SIZE:0] shift_amt [0:31];
    logic [NEW_MANT_WIDTH-1:0] pre_shifted_mant [0:31];
    logic [NEW_MANT_WIDTH-1:0] final_shifted_mant_c [0:31];
    logic is_shifted_out_nonzero [0:31];
    logic op_bit [0:31];
    logic has_pos_sticky;
    logic has_neg_sticky;
    logic overall_sticky_active;
    logic overall_sticky_sign;
    logic sticky_applied;

    always_comb begin
        has_pos_sticky = 1'b0;
        has_neg_sticky = 1'b0;
        
        for (int i = 0; i < 32; i++) begin
            shift_amt[i] = max_l4_n0_c - exp_dly[0][i];
            op_bit[i] = sign_max_l4_n0_c ^ sign_dly[0][i];
            
            // Check if any 1s are shifted out
            if (shift_amt[i] >= NEW_MANT_WIDTH) begin
                is_shifted_out_nonzero[i] = |mant_dly[0][i];
            end else begin
                is_shifted_out_nonzero[i] = |(mant_dly[0][i] & ~({NEW_MANT_WIDTH{1'b1}} << shift_amt[i]));
            end
            
            // Categorize sticky bit by sign relative to max exponent
            if (is_shifted_out_nonzero[i]) begin
                if (op_bit[i] == 1'b0) has_pos_sticky = 1'b1;
                else                   has_neg_sticky = 1'b1;
            end
        end
        
        // Overall sticky is 0 if mixed signs exist. Matches sign if homogenous.
        overall_sticky_active = (has_pos_sticky ^ has_neg_sticky) & (has_pos_sticky | has_neg_sticky);
        overall_sticky_sign   = has_neg_sticky;
        sticky_applied        = 1'b0;
        
        for (int i = 0; i < 32; i++) begin
            // Standard Shift
            if (shift_amt[i] >= NEW_MANT_WIDTH) begin
                pre_shifted_mant[i] = '0;
            end else begin
                pre_shifted_mant[i] = mant_dly[0][i] >> shift_amt[i];
            end
            
            // Apply overall sticky bit to the first matching operand
            if (overall_sticky_active && !sticky_applied && (op_bit[i] == overall_sticky_sign)) begin
                pre_shifted_mant[i][0] = 1'b1;
                sticky_applied = 1'b1;
            end
            
            // Apply 2's Complement if sign differs from max exponent operand
            if (op_bit[i]) begin
                final_shifted_mant_c[i] = ~pre_shifted_mant[i] + 1'b1;
            end else begin
                final_shifted_mant_c[i] = pre_shifted_mant[i];
            end
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            out_max_exp <= '0;
            for (int i = 0; i < 32; i++) begin
                sign_out[i] <= '0;
                aligned_mant_out[i] <= '0;
            end
        end else begin
            out_max_exp <= max_l4_n0_c;
            for (int i = 0; i < 32; i++) begin
                sign_out[i] <= sign_dly[0][i];
                aligned_mant_out[i] <= final_shifted_mant_c[i];
            end
        end
    end
endmodule