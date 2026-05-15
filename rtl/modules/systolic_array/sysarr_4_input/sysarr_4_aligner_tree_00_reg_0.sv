`timescale 1ns/1ps
module sysarr_4_aligner_tree_00_reg_0 #(
    parameter EXPONENT_SIZE = 8,
    parameter MANTISSA_SIZE = 23,
    parameter NEW_MANT_WIDTH = 27
) (
    input  logic clk, nRST,
    input  logic [1+EXPONENT_SIZE+MANTISSA_SIZE-1:0] in_fp [0:3],
    output logic [EXPONENT_SIZE-1:0] out_max_exp,
    output logic [1:0] out_sticky,
    output logic sign_out [0:3],
    output logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:3]
);

    // --- Stage 0: Unpack & Append Hidden Bit ---
    logic [EXPONENT_SIZE-1:0] exp_base [0:3];
    logic sign_base [0:3];
    logic [NEW_MANT_WIDTH-1:0] mant_base [0:3];

    localparam PAD_WIDTH = NEW_MANT_WIDTH - MANTISSA_SIZE - 2;
    always_comb begin
        for (int i = 0; i < 4; i++) begin
            sign_base[i] = in_fp[i][EXPONENT_SIZE+MANTISSA_SIZE];
            exp_base[i]  = in_fp[i][MANTISSA_SIZE +: EXPONENT_SIZE];
            mant_base[i] = { 1'b0, (|exp_base[i]), in_fp[i][MANTISSA_SIZE-1:0], {PAD_WIDTH{1'b0}} };
        end
    end

    // --- Max Exponent Tree (Tracking Max Exp and its Sign) ---
    // Level 0 (Nodes: 4)
    logic [EXPONENT_SIZE-1:0] max_l0_n0_c;
    logic sign_max_l0_n0_c;
    assign max_l0_n0_c = (exp_base[0] > exp_base[1]) ? exp_base[0] : exp_base[1];
    assign sign_max_l0_n0_c = (exp_base[0] > exp_base[1]) ? sign_base[0] : sign_base[1];
    logic [EXPONENT_SIZE-1:0] max_l0_n1_c;
    logic sign_max_l0_n1_c;
    assign max_l0_n1_c = (exp_base[2] > exp_base[3]) ? exp_base[2] : exp_base[3];
    assign sign_max_l0_n1_c = (exp_base[2] > exp_base[3]) ? sign_base[2] : sign_base[3];

    // Level 1 (Nodes: 2)
    logic [EXPONENT_SIZE-1:0] max_l1_n0_c;
    logic sign_max_l1_n0_c;
    assign max_l1_n0_c = (max_l0_n0_c > max_l0_n1_c) ? max_l0_n0_c : max_l0_n1_c;
    assign sign_max_l1_n0_c = (max_l0_n0_c > max_l0_n1_c) ? sign_max_l0_n0_c : sign_max_l0_n1_c;

    // --- Payload Delay Matching (Latency: 0 cycles) ---
    logic sign_dly  [0:0][0:3];
    logic [EXPONENT_SIZE-1:0] exp_dly   [0:0][0:3];
    logic [NEW_MANT_WIDTH-1:0] mant_dly [0:0][0:3];

    always_comb begin
        for (int i = 0; i < 4; i++) begin
            sign_dly[0][i] = sign_base[i];
            exp_dly[0][i]  = exp_base[i];
            mant_dly[0][i] = mant_base[i];
        end
    end

    // --- Alignment, Sticky Logic, & 2's Complement ---
    logic [EXPONENT_SIZE:0] shift_amt [0:3];
    logic [NEW_MANT_WIDTH-1:0] pre_shifted_mant [0:3];
    logic [NEW_MANT_WIDTH-1:0] final_shifted_mant_c [0:3];
    logic is_shifted_out_nonzero [0:3];
    logic op_bit [0:3];
    logic has_pos_sticky;
    logic has_neg_sticky;
    logic [1:0] c_out_sticky;
    logic sticky_applied;

    always_comb begin
        has_pos_sticky = 1'b0;
        has_neg_sticky = 1'b0;
        
        for (int i = 0; i < 4; i++) begin
            shift_amt[i] = {1'b0, max_l1_n0_c} - {1'b0, exp_dly[0][i]};
            op_bit[i] = sign_dly[0][i];
            
            if (shift_amt[i] >= NEW_MANT_WIDTH) begin
                is_shifted_out_nonzero[i] = |mant_dly[0][i];
            end else begin
                is_shifted_out_nonzero[i] = |(mant_dly[0][i] & ~({NEW_MANT_WIDTH{1'b1}} << shift_amt[i]));
            end
            
            if (is_shifted_out_nonzero[i]) begin
                if (op_bit[i] == 1'b0) has_pos_sticky = 1'b1;
                else                   has_neg_sticky = 1'b1;
            end
        end
        
        c_out_sticky[0] = (has_pos_sticky ^ has_neg_sticky) & (has_pos_sticky | has_neg_sticky);
        c_out_sticky[1] = has_neg_sticky;
        sticky_applied = 1'b0;
        
        for (int i = 0; i < 4; i++) begin
            if (shift_amt[i] >= NEW_MANT_WIDTH) begin
                pre_shifted_mant[i] = '0;
            end else begin
                pre_shifted_mant[i] = mant_dly[0][i] >> shift_amt[i];
            end
            
            // FIXED: Inject sticky bit so the 2s complement and adder tree handle it perfectly
            if (c_out_sticky[0] && !sticky_applied && (op_bit[i] == c_out_sticky[1])) begin
                pre_shifted_mant[i][0] = 1'b1;
                sticky_applied = 1'b1;
            end
            
            if (op_bit[i]) begin
                final_shifted_mant_c[i] = ~pre_shifted_mant[i] + 1'b1;
            end else begin
                final_shifted_mant_c[i] = pre_shifted_mant[i];
            end
        end
    end

    assign out_max_exp = max_l1_n0_c;
    assign out_sticky = c_out_sticky;
    always_comb begin
        for (int i = 0; i < 4; i++) begin
            sign_out[i] = sign_dly[0][i];
            aligned_mant_out[i] = final_shifted_mant_c[i];
        end
    end
endmodule