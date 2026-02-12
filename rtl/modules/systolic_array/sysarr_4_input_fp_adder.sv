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
    // Internal Constants
    localparam NEW_MANT_WIDTH = 1 + MANTISSA_SIZE + PRECISION_BITS + 1; 
    localparam SUM_WIDTH = NEW_MANT_WIDTH + 2; 
    localparam LZD_WIDTH = $clog2(SUM_WIDTH + 1);

    // --- Module Level Declarations (Scoped correctly) ---
    logic [15:0] a_daz, b_daz, c_daz, d_daz;
    logic [EXPONENT_SIZE-1:0] exp_a, exp_b, exp_c, exp_d;
    logic [MANTISSA_SIZE-1:0] frac_a, frac_b, frac_c, frac_d;
    logic sign_a, sign_b, sign_c, sign_d;
    logic [EXPONENT_SIZE-1:0] exp_p, exp_m, exp_r, exp_n, exp_x, exp_y, exp_mx, exp_nx;
    logic [MANTISSA_SIZE-1:0] frac_p, frac_m, frac_r, frac_n, frac_x, frac_y, frac_mx, frac_nx;
    logic sign_p, sign_m, sign_r, sign_n, sign_x, sign_y, sign_mx, sign_nx;
    logic [EXPONENT_SIZE-1:0] exp_x_eff, exp_y_eff, exp_mx_eff, exp_nx_eff;
    logic [EXPONENT_SIZE:0] y_shift, m_shift, n_shift;
    logic [NEW_MANT_WIDTH-1:0] x_mant, y_shifted, m_shifted, n_shifted;
    logic [NEW_MANT_WIDTH-1:0] y_mant_base, m_mant_base, n_mant_base;
    logic sticky_y, sticky_m, sticky_n;
    logic y_op, m_op, n_op;
    logic is_nan_any, is_inf_any;
    logic special_case;
    logic [15:0] special_result;

    // Pipeline Stage 1 -> 2
    logic st1_a_s;
    logic [EXPONENT_SIZE-1:0] st1_a_e;
    logic [NEW_MANT_WIDTH-1:0] st1_x_f, st1_y_f, st1_m_f, st1_n_f;
    logic st1_b_op, st1_c_op, st1_d_op;
    logic st1_align_sticky;
    logic st1_special_case;
    logic [15:0] st1_special_result;

    // Stage 2 Logic Signals
    logic [SUM_WIDTH-1:0] sum_a, sum_b, sum_c, sum_d;
    logic [SUM_WIDTH-1:0] neg_b, neg_c, neg_d;
    logic [1:0] neg_count;
    logic signed [SUM_WIDTH-1:0] raw_sum;
    logic [SUM_WIDTH-1:0] mag_sum;
    logic res_sign;
    logic [LZD_WIDTH-1:0] lead_zeros;

    // Pipeline Stage 2 -> 3
    logic st2_res_sign;
    logic [EXPONENT_SIZE-1:0] st2_exp_base;
    logic [SUM_WIDTH-1:0] st2_sum_mag;
    logic st2_sticky;
    logic st2_special;
    logic [15:0] st2_spec_res;
    logic [LZD_WIDTH-1:0] st2_lzd;

    // Stage 3 Logic Signals
    logic [SUM_WIDTH-1:0] norm_val;
    logic [MANTISSA_SIZE-1:0] raw_mant;
    logic guard_bit, round_bit, sticky_bit;
    logic round_up;
    logic [MANTISSA_SIZE-1:0] final_mant;
    logic [MANTISSA_SIZE:0] rounded_mant_int;
    logic signed [EXPONENT_SIZE+2:0] final_exp_calc;
    logic [15:0] result_out;

    // =================================================================================
    // STAGE 1: ALIGNMENT
    // =================================================================================
    always_comb begin : stage1_logic
        a_daz = (add.a[14:10] == 0) ? {add.a[15], 15'd0} : add.a;
        b_daz = (add.b[14:10] == 0) ? {add.b[15], 15'd0} : add.b;
        c_daz = (add.c[14:10] == 0) ? {add.c[15], 15'd0} : add.c;
        d_daz = (add.d[14:10] == 0) ? {add.d[15], 15'd0} : add.d;

        {sign_a, exp_a, frac_a} = a_daz;
        {sign_b, exp_b, frac_b} = b_daz;
        {sign_c, exp_c, frac_c} = c_daz;
        {sign_d, exp_d, frac_d} = d_daz;

        is_nan_any = (&exp_a & |frac_a) | (&exp_b & |frac_b) | (&exp_c & |frac_c) | (&exp_d & |frac_d);
        is_inf_any = (&exp_a & ~|frac_a) | (&exp_b & ~|frac_b) | (&exp_c & ~|frac_c) | (&exp_d & ~|frac_d);
        
        special_case = 0;
        special_result = 0;
        if (is_nan_any) begin
            special_case = 1; special_result = 16'h7E00;
        end else if (is_inf_any) begin
            special_case = 1;
            if (((&exp_a && !sign_a) || (&exp_b && !sign_b)) && ((&exp_a && sign_a) || (&exp_b && sign_b))) 
                special_result = 16'h7E00;
            else if (sign_a | sign_b | sign_c | sign_d) special_result = 16'hFC00;
            else special_result = 16'h7C00;
        end

        // Sorting
        if (exp_a >= exp_b) begin exp_p=exp_a; frac_p=frac_a; sign_p=sign_a; exp_m=exp_b; frac_m=frac_b; sign_m=sign_b; end
        else                begin exp_p=exp_b; frac_p=frac_b; sign_p=sign_b; exp_m=exp_a; frac_m=frac_a; sign_m=sign_a; end
        if (exp_c >= exp_d) begin exp_r=exp_c; frac_r=frac_c; sign_r=sign_c; exp_n=exp_d; frac_n=frac_d; sign_n=sign_d; end
        else                begin exp_r=exp_d; frac_r=frac_d; sign_r=sign_d; exp_n=exp_c; frac_n=frac_c; sign_n=sign_c; end

        if (exp_p >= exp_r) begin
            exp_x=exp_p; frac_x=frac_p; sign_x=sign_p; exp_y=exp_r; frac_y=frac_r; sign_y=sign_r;
            exp_mx=exp_m; frac_mx=frac_m; sign_mx=sign_m; exp_nx=exp_n; frac_nx=frac_n; sign_nx=sign_n;
        end else begin
            exp_x=exp_r; frac_x=frac_r; sign_x=sign_r; exp_y=exp_p; frac_y=frac_p; sign_y=sign_p;
            exp_mx=exp_n; frac_mx=frac_n; sign_mx=sign_n; exp_nx=exp_m; frac_nx=frac_m; sign_nx=sign_m;
        end

        exp_x_eff  = (exp_x == 0) ? 1 : exp_x;
        exp_y_eff  = (exp_y == 0) ? 1 : exp_y;
        exp_mx_eff = (exp_mx == 0) ? 1 : exp_mx;
        exp_nx_eff = (exp_nx == 0) ? 1 : exp_nx;

        y_shift = exp_x_eff - exp_y_eff;
        m_shift = exp_x_eff - exp_mx_eff;
        n_shift = exp_x_eff - exp_nx_eff;

        x_mant      = { (|exp_x),  frac_x,  {PRECISION_BITS{1'b0}}, 1'b0 };
        y_mant_base = { (|exp_y),  frac_y,  {PRECISION_BITS{1'b0}}, 1'b0 };
        m_mant_base = { (|exp_mx), frac_mx, {PRECISION_BITS{1'b0}}, 1'b0 };
        n_mant_base = { (|exp_nx), frac_nx, {PRECISION_BITS{1'b0}}, 1'b0 };

        y_shifted = (y_shift >= NEW_MANT_WIDTH) ? 0 : (y_mant_base >> y_shift);
        sticky_y  = |(y_mant_base & ~({NEW_MANT_WIDTH{1'b1}} << y_shift));
        m_shifted = (m_shift >= NEW_MANT_WIDTH) ? 0 : (m_mant_base >> m_shift);
        sticky_m  = |(m_mant_base & ~({NEW_MANT_WIDTH{1'b1}} << m_shift));
        n_shifted = (n_shift >= NEW_MANT_WIDTH) ? 0 : (n_mant_base >> n_shift);
        sticky_n  = |(n_mant_base & ~({NEW_MANT_WIDTH{1'b1}} << n_shift));

        y_op = sign_x ^ sign_y; m_op = sign_x ^ sign_mx; n_op = sign_x ^ sign_nx;
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_a_s <= 0; st1_a_e <= 0; st1_x_f <= 0; st1_y_f <= 0; st1_m_f <= 0; st1_n_f <= 0;
            st1_b_op <= 0; st1_c_op <= 0; st1_d_op <= 0; st1_align_sticky <= 0;
            st1_special_case <= 0; st1_special_result <= 0;
        end else begin
            st1_a_s <= sign_x; st1_a_e <= exp_x; st1_x_f <= x_mant; st1_y_f <= y_shifted; 
            st1_m_f <= m_shifted; st1_n_f <= n_shifted; st1_b_op <= y_op; st1_c_op <= m_op; 
            st1_d_op <= n_op; st1_align_sticky <= sticky_y | sticky_m | sticky_n;
            st1_special_case <= special_case; st1_special_result <= special_result;
        end
    end

    // =================================================================================
    // STAGE 2: SUMMATION
    // =================================================================================
    always_comb begin : stage2_logic
        sum_a = {2'b00, st1_x_f}; sum_b = {2'b00, st1_y_f}; 
        sum_c = {2'b00, st1_m_f}; sum_d = {2'b00, st1_n_f};

        neg_b = st1_b_op ? ~sum_b : sum_b;
        neg_c = st1_c_op ? ~sum_c : sum_c;
        neg_d = st1_d_op ? ~sum_d : sum_d;
        neg_count = st1_b_op + st1_c_op + st1_d_op;

        raw_sum = $signed(sum_a) + $signed(neg_b) + $signed(neg_c) + $signed(neg_d) + $signed({{(SUM_WIDTH-2){1'b0}}, neg_count});

        if (raw_sum[SUM_WIDTH-1]) begin
            mag_sum = ~raw_sum + 1'b1;
            res_sign = ~st1_a_s;
        end else begin
            mag_sum = raw_sum;
            res_sign = st1_a_s;
        end

        lead_zeros = SUM_WIDTH;
        for (int i = SUM_WIDTH-1; i >= 0; i--) begin
            if (mag_sum[i]) begin
                lead_zeros = SUM_WIDTH - 1 - i;
                break;
            end
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st2_sum_mag <= 0; st2_lzd <= 0; st2_res_sign <= 0; st2_exp_base <= 0;
            st2_sticky <= 0; st2_special <= 0; st2_spec_res <= 0;
        end else begin
            st2_sum_mag <= mag_sum; st2_lzd <= lead_zeros; st2_res_sign <= res_sign;
            st2_exp_base <= st1_a_e; st2_sticky <= st1_align_sticky;
            st2_special <= st1_special_case; st2_spec_res <= st1_special_result;
        end
    end

    // =================================================================================
    // STAGE 3: NORMALIZATION & ROUNDING
    // =================================================================================
    always_comb begin : stage3_logic
        norm_val = st2_sum_mag << st2_lzd;
        
        raw_mant = norm_val[(SUM_WIDTH-2) -: MANTISSA_SIZE];
        guard_bit = norm_val[SUM_WIDTH-2 - MANTISSA_SIZE];
        round_bit = norm_val[SUM_WIDTH-3 - MANTISSA_SIZE];
        sticky_bit = (|norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]) | st2_sticky;

        round_up = guard_bit & (round_bit | sticky_bit | raw_mant[0]);
        rounded_mant_int = raw_mant + round_up;
        
        final_mant = rounded_mant_int[MANTISSA_SIZE] ? 0 : rounded_mant_int[MANTISSA_SIZE-1:0];
        final_exp_calc = $signed({2'b00, st2_exp_base}) + 2 - $signed({2'b00, st2_lzd}) + $signed({10'd0, rounded_mant_int[MANTISSA_SIZE]});

        if (st2_sum_mag == 0) result_out = {st2_res_sign, 15'd0};
        else if (final_exp_calc >= 31) result_out = {st2_res_sign, 5'b11111, 10'd0};
        else if (final_exp_calc <= 0)  result_out = {st2_res_sign, 15'd0};
        else result_out = {st2_res_sign, final_exp_calc[4:0], final_mant};

        if (st2_special) result_out = st2_spec_res;
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) add.out <= 0;
        else add.out <= result_out;
    end

endmodule