`include "systolic_array_4_input_adder_if.vh"

module sysarr_4_input_fp_adder #(
    parameter MANTISSA_SIZE = 10,
    parameter EXPONENT_SIZE = 5,
    parameter PRECISION_BITS = 3
) (
    input logic clk, 
    input logic nRST,
    systolic_array_4_input_adder_if.add add
);
    localparam NEW_MANT_WIDTH = 1 + MANTISSA_SIZE + PRECISION_BITS + 1;
    localparam WIDTH = MANTISSA_SIZE + PRECISION_BITS + 2;

    // =================================================================================
    // STAGE 1: Sorting, Alignment, and Special Case Detection
    // =================================================================================
    
    logic [15:0] a_daz, b_daz, c_daz, d_daz;
    logic [EXPONENT_SIZE-1:0] exp_a, exp_b, exp_c, exp_d;
    logic [MANTISSA_SIZE-1:0] frac_a, frac_b, frac_c, frac_d;
    logic sign_a, sign_b, sign_c, sign_d;

    logic [EXPONENT_SIZE-1:0] exp_p, exp_m, exp_r, exp_n, exp_x, exp_y, exp_mx, exp_nx;
    logic [MANTISSA_SIZE-1:0] frac_p, frac_m, frac_r, frac_n, frac_x, frac_y, frac_mx, frac_nx;
    logic sign_p, sign_m, sign_r, sign_n, sign_x, sign_y, sign_mx, sign_nx;

    logic [EXPONENT_SIZE-1:0] exp_x_eff, exp_y_eff, exp_mx_eff, exp_nx_eff;
    logic [EXPONENT_SIZE-1:0] y_shift, m_shift, n_shift;
    logic [NEW_MANT_WIDTH-1:0] x_mant, y_shifted, m_shifted, n_shifted;
    logic y_op, m_op, n_op;
    logic is_nan_a, is_nan_b, is_nan_c, is_nan_d;
    logic is_inf_a, is_inf_b, is_inf_c, is_inf_d;
    logic special_case;
    logic [15:0] special_result;

    // --- Pipeline Register 1 ---
    logic st1_a_s;
    logic st1_b_op, st1_c_op, st1_d_op;
    logic [EXPONENT_SIZE - 1:0] st1_a_e;
    logic [NEW_MANT_WIDTH - 1:0] st1_x_f, st1_y_f, st1_m_f, st1_n_f;
    logic st1_special_case;
    logic [15:0] st1_special_result;

    function automatic logic [NEW_MANT_WIDTH-1:0] shift_right_sticky(
        input logic [NEW_MANT_WIDTH-1:0] mant,
        input logic [EXPONENT_SIZE-1:0] shift_amt
    );
        logic [NEW_MANT_WIDTH-1:0] result;
        logic sticky;
        if (shift_amt == 0) begin
            result = mant;
        end else if (shift_amt >= NEW_MANT_WIDTH) begin
            result = '0;
            result[0] = |mant;
        end else begin
            result = mant >> shift_amt;
            sticky = |(mant & ((1 << shift_amt) - 1));
            if (sticky || result[0]) result[0] = 1'b1;
        end
        return result;
    endfunction

    always_comb begin : stage1_combinational
        // 1. DAZ
        a_daz = add.a; if ((add.a[14:10] == 0) && (add.a[9:0] != 0)) a_daz = {add.a[15], 15'd0};
        b_daz = add.b; if ((add.b[14:10] == 0) && (add.b[9:0] != 0)) b_daz = {add.b[15], 15'd0};
        c_daz = add.c; if ((add.c[14:10] == 0) && (add.c[9:0] != 0)) c_daz = {add.c[15], 15'd0};
        d_daz = add.d; if ((add.d[14:10] == 0) && (add.d[9:0] != 0)) d_daz = {add.d[15], 15'd0};

        // 2. Unpack
        sign_a = a_daz[15]; exp_a = a_daz[14 -: EXPONENT_SIZE]; frac_a = a_daz[MANTISSA_SIZE-1:0];
        sign_b = b_daz[15]; exp_b = b_daz[14 -: EXPONENT_SIZE]; frac_b = b_daz[MANTISSA_SIZE-1:0];
        sign_c = c_daz[15]; exp_c = c_daz[14 -: EXPONENT_SIZE]; frac_c = c_daz[MANTISSA_SIZE-1:0];
        sign_d = d_daz[15]; exp_d = d_daz[14 -: EXPONENT_SIZE]; frac_d = d_daz[MANTISSA_SIZE-1:0];

        // 3. Special Case Detection
        special_case = 1'b0; special_result = 16'h0000;
        is_nan_a = (exp_a == {EXPONENT_SIZE{1'b1}}) && (frac_a != 0);
        is_nan_b = (exp_b == {EXPONENT_SIZE{1'b1}}) && (frac_b != 0);
        is_nan_c = (exp_c == {EXPONENT_SIZE{1'b1}}) && (frac_c != 0);
        is_nan_d = (exp_d == {EXPONENT_SIZE{1'b1}}) && (frac_d != 0);
        is_inf_a = (exp_a == {EXPONENT_SIZE{1'b1}}) && (frac_a == 0);
        is_inf_b = (exp_b == {EXPONENT_SIZE{1'b1}}) && (frac_b == 0);
        is_inf_c = (exp_c == {EXPONENT_SIZE{1'b1}}) && (frac_c == 0);
        is_inf_d = (exp_d == {EXPONENT_SIZE{1'b1}}) && (frac_d == 0);

        if (is_nan_a || is_nan_b || is_nan_c || is_nan_d) begin
            special_case = 1'b1; special_result = 16'h7E00;
        end else if (is_inf_a || is_inf_b || is_inf_c || is_inf_d) begin
            logic has_pos_inf = (is_inf_a && !sign_a) || (is_inf_b && !sign_b) || (is_inf_c && !sign_c) || (is_inf_d && !sign_d);
            logic has_neg_inf = (is_inf_a && sign_a) || (is_inf_b && sign_b) || (is_inf_c && sign_c) || (is_inf_d && sign_d);
            if (has_pos_inf && has_neg_inf) begin special_case = 1'b1; special_result = 16'h7E00; end 
            else if (has_pos_inf) begin special_case = 1'b1; special_result = 16'h7C00; end 
            else begin special_case = 1'b1; special_result = 16'hFC00; end
        end

        // 4. Sorting
        if (exp_a >= exp_b) begin exp_p = exp_a; frac_p = frac_a; sign_p = sign_a; exp_m = exp_b; frac_m = frac_b; sign_m = sign_b; end 
        else begin exp_p = exp_b; frac_p = frac_b; sign_p = sign_b; exp_m = exp_a; frac_m = frac_a; sign_m = sign_a; end
        if (exp_c >= exp_d) begin exp_r = exp_c; frac_r = frac_c; sign_r = sign_c; exp_n = exp_d; frac_n = frac_d; sign_n = sign_d; end 
        else begin exp_r = exp_d; frac_r = frac_d; sign_r = sign_d; exp_n = exp_c; frac_n = frac_c; sign_n = sign_c; end
        if (exp_p >= exp_r) begin 
            exp_x = exp_p; frac_x = frac_p; sign_x = sign_p; exp_y = exp_r; frac_y = frac_r; sign_y = sign_r; 
            exp_mx = exp_m; frac_mx = frac_m; sign_mx = sign_m; exp_nx = exp_n; frac_nx = frac_n; sign_nx = sign_n; 
        end else begin 
            exp_x = exp_r; frac_x = frac_r; sign_x = sign_r; exp_y = exp_p; frac_y = frac_p; sign_y = sign_p; 
            exp_mx = exp_n; frac_mx = frac_n; sign_mx = sign_n; exp_nx = exp_m; frac_nx = frac_m; sign_nx = sign_m; 
        end

        // 5. Calculate Shifts (Denormal aware)
        exp_x_eff  = (exp_x == 0)  ? {{EXPONENT_SIZE-1{1'b0}}, 1'b1} : exp_x;
        exp_y_eff  = (exp_y == 0)  ? {{EXPONENT_SIZE-1{1'b0}}, 1'b1} : exp_y;
        exp_mx_eff = (exp_mx == 0) ? {{EXPONENT_SIZE-1{1'b0}}, 1'b1} : exp_mx;
        exp_nx_eff = (exp_nx == 0) ? {{EXPONENT_SIZE-1{1'b0}}, 1'b1} : exp_nx;

        y_shift = exp_x_eff - exp_y_eff;
        m_shift = exp_x_eff - exp_mx_eff;
        n_shift = exp_x_eff - exp_nx_eff;

        // 6. Shift and Align
        x_mant = {(|exp_x), frac_x, {PRECISION_BITS{1'b0}}, 1'b0};
        y_shifted = shift_right_sticky({(|exp_y), frac_y, {PRECISION_BITS{1'b0}}, 1'b0}, y_shift);
        m_shifted = shift_right_sticky({(|exp_mx), frac_mx, {PRECISION_BITS{1'b0}}, 1'b0}, m_shift);
        n_shifted = shift_right_sticky({(|exp_nx), frac_nx, {PRECISION_BITS{1'b0}}, 1'b0}, n_shift);

        // 7. Determine Operations
        y_op = sign_x ^ sign_y;
        m_op = sign_x ^ sign_mx;
        n_op = sign_x ^ sign_nx;
    end

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            st1_a_s <= '0; st1_a_e <= '0;
            st1_x_f <= '0; st1_y_f <= '0; st1_m_f <= '0; st1_n_f <= '0;
            st1_b_op <= '0; st1_c_op <= '0; st1_d_op <= '0;
            st1_special_case <= '0; st1_special_result <= '0;
        end else begin
            st1_a_s <= sign_x; st1_a_e <= exp_x;
            st1_x_f <= x_mant; st1_y_f <= y_shifted; st1_m_f <= m_shifted; st1_n_f <= n_shifted;
            st1_b_op <= y_op; st1_c_op <= m_op; st1_d_op <= n_op;
            st1_special_case <= special_case; st1_special_result <= special_result;
        end
    end

    // =================================================================================
    // STAGE 2: Carry Save Adder Tree & Summation
    // =================================================================================
    
    logic [WIDTH-1:0] a_f_st2, b_f_st2, c_f_st2, d_f_st2;
    logic [WIDTH-1:0] b_inv, c_inv, d_inv;
    logic [WIDTH-1:0] s1, c1, s2, c2;
    logic signed [WIDTH+1:0] magnitude_sum;
    logic [WIDTH:0] corrected_sum;
    logic next_result_s;
    logic [3:0] next_num_leading_zeros;
    logic [1:0] next_right_shift_radix;

    logic [WIDTH:0] st2_sum_i; 
    logic st2_result_s;
    logic [EXPONENT_SIZE - 1:0] st2_a_e_out;
    logic [3:0] st2_num_leading_zeros;
    logic [1:0] st2_right_shift_radix;
    logic st2_special_case;
    logic [15:0] st2_special_result;

    always_comb begin : stage2_combinational
        a_f_st2 = st1_x_f[NEW_MANT_WIDTH-1:1];
        b_f_st2 = st1_y_f[NEW_MANT_WIDTH-1:1];
        c_f_st2 = st1_m_f[NEW_MANT_WIDTH-1:1];
        d_f_st2 = st1_n_f[NEW_MANT_WIDTH-1:1];

        // 2's Complement Inversion
        b_inv = st1_b_op ? (~b_f_st2 + 1) : b_f_st2;
        c_inv = st1_c_op ? (~c_f_st2 + 1) : c_f_st2;
        d_inv = st1_d_op ? (~d_f_st2 + 1) : d_f_st2; 

        // Carry Save Adder Tree
        // Layer 1
        for (int i=0; i<WIDTH; i++) begin
            s1[i] = a_f_st2[i] ^ b_inv[i] ^ c_inv[i];
            c1[i] = (a_f_st2[i] & b_inv[i]) | (b_inv[i] & c_inv[i]) | (a_f_st2[i] & c_inv[i]);
        end
        // Layer 2
        for (int i=0; i<WIDTH; i++) begin
            logic c_val = (i == 0) ? 1'b0 : c1[i-1];
            // FIX: Uses d_inv correctly
            s2[i] = s1[i] ^ d_inv[i] ^ c_val;
            c2[i] = (s1[i] & d_inv[i]) | (d_inv[i] & c_val) | (s1[i] & c_val);
        end

        // Final Addition
        magnitude_sum = $signed({1'b0, s2}) + $signed({c2, 1'b0});

        // Sign Correction
        next_result_s = st1_a_s ^ magnitude_sum[WIDTH+1];
        corrected_sum = next_result_s ? (~magnitude_sum + 1'b1) : magnitude_sum;

        // Right Shift Logic
        if (corrected_sum[WIDTH]) next_right_shift_radix = 2'd2; 
        else if (corrected_sum[WIDTH-1]) next_right_shift_radix = 2'd1; 
        else next_right_shift_radix = 2'd0;

        // Leading Zero Detection
        next_num_leading_zeros = 4'hF;
        for (int k = MANTISSA_SIZE + PRECISION_BITS; k >= 0; k--) begin
            if (corrected_sum[k]) begin
                next_num_leading_zeros = (MANTISSA_SIZE + PRECISION_BITS - k);   
                break;
            end
        end
    end

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            st2_sum_i <= '0; st2_result_s <= '0; st2_a_e_out <= '0;
            st2_num_leading_zeros <= '0; st2_right_shift_radix <= '0;
            st2_special_case <= '0; st2_special_result <= '0;
        end else begin
            st2_sum_i <= {corrected_sum[WIDTH:1], corrected_sum[0] | st1_y_f[0] | st1_m_f[0] | st1_n_f[0]};
            st2_result_s <= next_result_s;
            st2_a_e_out <= st1_a_e;
            st2_num_leading_zeros <= next_num_leading_zeros;
            st2_right_shift_radix <= next_right_shift_radix;
            st2_special_case <= st1_special_case;
            st2_special_result <= st1_special_result;
        end
    end

    // =================================================================================
    // STAGE 3: Normalization and Rounding
    // =================================================================================
    
    logic [MANTISSA_SIZE+PRECISION_BITS:0] sum_reg_st3;
    logic [MANTISSA_SIZE+PRECISION_BITS:0] shifted_sum; 
    logic [MANTISSA_SIZE-1:0] unrounded_mantissa; 
    logic [MANTISSA_SIZE:0] rounded_mantissa_internal;
    logic guard, round, sticky; 
    logic round_up;
    logic overflow; 
    logic [MANTISSA_SIZE-1:0] final_mantissa;
    logic signed [EXPONENT_SIZE+1:0] new_exponent_internal; 
    logic [EXPONENT_SIZE-1:0] new_exponent;
    logic inf;
    logic [EXPONENT_SIZE+MANTISSA_SIZE:0] final_sum_next;

    always_comb begin : stage3_combinational
        sum_reg_st3 = st2_sum_i[MANTISSA_SIZE+PRECISION_BITS:0];

        if (st2_right_shift_radix != 0) shifted_sum = sum_reg_st3 >> st2_right_shift_radix; 
        else shifted_sum = sum_reg_st3 << st2_num_leading_zeros; 

        unrounded_mantissa = shifted_sum[MANTISSA_SIZE+PRECISION_BITS-1:PRECISION_BITS];
        guard = shifted_sum[PRECISION_BITS]; 
        round = shifted_sum[PRECISION_BITS-1];
        sticky = |shifted_sum[PRECISION_BITS-2:0]; 
        
        round_up = guard & (round | sticky | unrounded_mantissa[0]);
        rounded_mantissa_internal = unrounded_mantissa + round_up; 
        overflow = rounded_mantissa_internal[MANTISSA_SIZE];

        if (overflow) final_mantissa = {MANTISSA_SIZE{1'b0}};
        else final_mantissa = rounded_mantissa_internal[MANTISSA_SIZE-1:0];

        new_exponent_internal = $signed({2'b0, st2_a_e_out}) + $signed({{(EXPONENT_SIZE+1){1'b0}}, overflow}) + $signed({2'b0, st2_right_shift_radix});
        if (st2_right_shift_radix == 0) new_exponent_internal = new_exponent_internal - $signed({2'b0, st2_num_leading_zeros});

        inf = 0; 
        if ($signed(new_exponent_internal) >= $signed({2'b0, {EXPONENT_SIZE{1'b1}}}) ) begin
            inf = 1'b1; new_exponent = {EXPONENT_SIZE{1'b1}};
        end else if ($signed(new_exponent_internal) <= 0) begin
            new_exponent = {EXPONENT_SIZE{1'b0}};
        end else begin
            new_exponent = new_exponent_internal[EXPONENT_SIZE-1:0];
        end

        if (st2_special_case) final_sum_next = st2_special_result;
        else if (inf) final_sum_next = {st2_result_s, new_exponent, {MANTISSA_SIZE{1'b0}}};
        else final_sum_next = {st2_result_s, new_exponent, final_mantissa};
    end

    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) add.out <= '0;
        else add.out <= final_sum_next;
    end

endmodule