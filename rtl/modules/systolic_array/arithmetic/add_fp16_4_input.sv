`include "systolic_array_4_input_adder_if.vh"

module add_fp16_4_input #(
    parameter MANTISSA_SIZE     = 10, // Input Mantissa Width
    parameter EXPONENT_SIZE     = 5,
    parameter OUT_MANTISSA_SIZE = 10, // Output Mantissa Width (New Parameter)
    parameter PRECISION_BITS    = 22 
) (
    input logic clk, 
    input logic nRST,
    systolic_array_4_input_adder_if.add add
);
    // Ensure internal width covers the larger of input or output mantissa to prevent precision loss before rounding
    localparam MAX_MANT_SIZE = (MANTISSA_SIZE > OUT_MANTISSA_SIZE) ? MANTISSA_SIZE : OUT_MANTISSA_SIZE;
    localparam NEW_MANT_WIDTH = 1 + MAX_MANT_SIZE + PRECISION_BITS + 1; 
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 2; 
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + OUT_MANTISSA_SIZE; // Total width of result

    // Internal Signal Declarations
    logic [15:0] a_daz, b_daz, c_daz, d_daz;
    logic [EXPONENT_SIZE-1:0] exp_a, exp_b, exp_c, exp_d;
    logic [MANTISSA_SIZE-1:0] frac_a, frac_b, frac_c, frac_d;
    logic sign_a, sign_b, sign_c, sign_d;
    
    // Sorting signals
    logic [EXPONENT_SIZE-1:0] exp_p, exp_m, exp_r, exp_n, exp_x, exp_y, exp_mx, exp_nx;
    logic [MANTISSA_SIZE-1:0] frac_p, frac_m, frac_r, frac_n, frac_x, frac_y, frac_mx, frac_nx;
    logic sign_p, sign_m, sign_r, sign_n, sign_x, sign_y, sign_mx, sign_nx;
    
    // Align signals
    logic [EXPONENT_SIZE-1:0] exp_x_eff, exp_y_eff, exp_mx_eff, exp_nx_eff;
    logic [EXPONENT_SIZE:0]   y_shift, m_shift, n_shift;
    logic [NEW_MANT_WIDTH-1:0] x_mant, y_shifted, m_shifted, n_shifted;
    logic [NEW_MANT_WIDTH-1:0] y_mant_base, m_mant_base, n_mant_base;
    logic sticky_y, sticky_m, sticky_n;
    logic y_op, m_op, n_op;
    
    // Exception signals
    logic is_nan_any, special_case, any_pos_inf, any_neg_inf;
    logic [RES_WIDTH-1:0] special_result; // Scaled to output width

    // --- Pipeline Stage 1 Registers (Compressed Vectors) ---
    logic [EXPONENT_SIZE-1:0]  st1_a_e;
    logic st1_a_s, st1_align_sticky, st1_special_case;
    logic [RES_WIDTH-1:0] st1_special_result;
    logic [SUM_WIDTH:0] st1_sum_vec;
    logic [SUM_WIDTH:0] st1_carry_vec;
    logic [1:0]         st1_hot_ones; 

    // --- Stage 2 Signals ---
    logic signed [SUM_WIDTH+1:0] raw_sum;
    logic [SUM_WIDTH-1:0] mag_sum;
    logic res_sign;

    // --- Pipeline Stage 2 Registers (Result Magnitude ONLY) ---
    logic [EXPONENT_SIZE-1:0] st2_exp_base;
    logic [SUM_WIDTH-1:0]      st2_sum_mag;
    logic [RES_WIDTH-1:0]      st2_spec_res;
    logic st2_res_sign, st2_sticky, st2_special;

    // --- Stage 3 Signals ---
    logic [SUM_WIDTH-1:0]      lzd_scan;
    logic [$clog2(SUM_WIDTH):0] lead_zeros; 
    logic [SUM_WIDTH-1:0]      norm_val;
    
    // Output specific signals
    logic [OUT_MANTISSA_SIZE-1:0] raw_mant, final_mant;
    logic [OUT_MANTISSA_SIZE:0]   rounded_mant_int;
    logic signed [EXPONENT_SIZE+2:0] final_exp_calc;
    logic guard_bit, round_bit, sticky_bit, round_up;
    logic [RES_WIDTH-1:0] result_out;

    // =================================================================================
    // STAGE 1: Sort, Align, and COMPRESS
    // =================================================================================
    logic [SUM_WIDTH:0] op_x, op_y, op_m, op_n;
    logic [SUM_WIDTH:0] csa_s1, csa_c1, csa_s2, csa_c2;

    always_comb begin : stage1_logic
        // -- Standard Sorting & Exception Logic --
        a_daz = (add.a[14:10] == 0) ? {add.a[15], 15'd0} : add.a;
        b_daz = (add.b[14:10] == 0) ? {add.b[15], 15'd0} : add.b;
        c_daz = (add.c[14:10] == 0) ? {add.c[15], 15'd0} : add.c;
        d_daz = (add.d[14:10] == 0) ? {add.d[15], 15'd0} : add.d;
        {sign_a, exp_a, frac_a} = a_daz; {sign_b, exp_b, frac_b} = b_daz;
        {sign_c, exp_c, frac_c} = c_daz; {sign_d, exp_d, frac_d} = d_daz;

        is_nan_any = (&exp_a & |frac_a) | (&exp_b & |frac_b) | (&exp_c & |frac_c) | (&exp_d & |frac_d);
        any_pos_inf = (&exp_a & ~sign_a & ~|frac_a) | (&exp_b & ~sign_b & ~|frac_b) | (&exp_c & ~sign_c & ~|frac_c) | (&exp_d & ~sign_d & ~|frac_d);
        any_neg_inf = (&exp_a &  sign_a & ~|frac_a) | (&exp_b &  sign_b & ~|frac_b) | (&exp_c &  sign_c & ~|frac_c) | (&exp_d &  sign_d & ~|frac_d);
        
        special_case = 0; special_result = 0; 
        if (is_nan_any || (any_pos_inf && any_neg_inf)) begin
            special_case = 1; 
            // NaN: Sign=1, Exp=All 1s, Mant=100...0
            special_result = {1'b1, {EXPONENT_SIZE{1'b1}}, 1'b1, {(OUT_MANTISSA_SIZE-1){1'b0}}};
        end else if (any_pos_inf) begin
            special_case = 1; 
            // +Inf
            special_result = {1'b0, {EXPONENT_SIZE{1'b1}}, {OUT_MANTISSA_SIZE{1'b0}}};
        end else if (any_neg_inf) begin
            special_case = 1; 
            // -Inf
            special_result = {1'b1, {EXPONENT_SIZE{1'b1}}, {OUT_MANTISSA_SIZE{1'b0}}};
        end

        // Sort
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

        // Align
        exp_x_eff = (exp_x == 0) ? 1 : exp_x; exp_y_eff = (exp_y == 0) ? 1 : exp_y;
        exp_mx_eff = (exp_mx == 0) ? 1 : exp_mx; exp_nx_eff = (exp_nx == 0) ? 1 : exp_nx;
        y_shift = exp_x_eff - exp_y_eff; m_shift = exp_x_eff - exp_mx_eff; n_shift = exp_x_eff - exp_nx_eff;

        // Note: Inputs still use MANTISSA_SIZE, internal math uses NEW_MANT_WIDTH
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

        // -- COMPRESS (CSA Tree) --
        op_x = {2'b00, x_mant};
        op_y = y_op ? ~{2'b00, y_shifted} : {2'b00, y_shifted};
        op_m = m_op ? ~{2'b00, m_shifted} : {2'b00, m_shifted};
        op_n = n_op ? ~{2'b00, n_shifted} : {2'b00, n_shifted};

        csa_s1 = op_x ^ op_y ^ op_m;
        csa_c1 = (op_x & op_y) | (op_y & op_m) | (op_m & op_x);
        csa_s2 = csa_s1 ^ (csa_c1 << 1) ^ op_n;
        csa_c2 = (csa_s1 & (csa_c1 << 1)) | ((csa_c1 << 1) & op_n) | (op_n & csa_s1);
    end

    // Pipeline Stage 1 Flip-Flops
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_a_s <= 0; st1_a_e <= 0; st1_align_sticky <= 0;
            st1_special_case <= 0; st1_special_result <= 0;
            st1_sum_vec <= 0; st1_carry_vec <= 0; st1_hot_ones <= 0;
        end else begin
            st1_a_s <= sign_x; st1_a_e <= exp_x; 
            st1_align_sticky <= sticky_y | sticky_m | sticky_n;
            st1_special_case <= special_case; st1_special_result <= special_result;
            st1_sum_vec   <= csa_s2;
            st1_carry_vec <= csa_c2;
            st1_hot_ones  <= (y_op + m_op + n_op);
        end
    end

    // =================================================================================
    // STAGE 2: Final Add (Critical Path Isolation)
    // =================================================================================
    always_comb begin : stage2_logic
        raw_sum = $signed(st1_sum_vec) + $signed(st1_carry_vec << 1) + $signed({{(SUM_WIDTH){1'b0}}, st1_hot_ones});

        if (raw_sum[SUM_WIDTH]) begin
            mag_sum = ~raw_sum + 1'b1;
            res_sign = ~st1_a_s;
        end else begin
            mag_sum = raw_sum;
            res_sign = st1_a_s;
        end
    end

    // Pipeline Stage 2 Flip-Flops
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st2_sum_mag <= 0; st2_res_sign <= 0; st2_exp_base <= 0;
            st2_sticky <= 0; st2_special <= 0; st2_spec_res <= 0;
        end else begin
            st2_sum_mag <= mag_sum; st2_res_sign <= res_sign;
            st2_exp_base <= st1_a_e; st2_sticky <= st1_align_sticky;
            st2_special <= st1_special_case; st2_spec_res <= st1_special_result;
        end
    end

    // =================================================================================
    // STAGE 3: LZD, Normalization and Rounding
    // =================================================================================
    always_comb begin : stage3_logic
        // 1. Tree-based LZD
        if (st2_sum_mag == 0) begin
            lzd_scan = 0;
            lead_zeros = SUM_WIDTH - 1;
        end else begin
            lzd_scan = st2_sum_mag;
            lead_zeros = 0;
            for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
                if ((lzd_scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                    lead_zeros = lead_zeros + (1 << i);
                    lzd_scan = lzd_scan << (1 << i);
                end
            end
        end

        // 2. Normalization
        norm_val = st2_sum_mag << lead_zeros;
        
        // 3. Rounding (Updated for OUT_MANTISSA_SIZE)
        // norm_val[SUM_WIDTH-1] is the Hidden Bit (1).
        // The mantissa bits start at [SUM_WIDTH-2].
        
        // Extract raw mantissa based on the configured Output size
        raw_mant   = norm_val[SUM_WIDTH-2 -: OUT_MANTISSA_SIZE];
        guard_bit  = norm_val[SUM_WIDTH-2 - OUT_MANTISSA_SIZE];
        round_bit  = norm_val[SUM_WIDTH-3 - OUT_MANTISSA_SIZE];
        // Sticky bit is everything remaining below the round bit
        sticky_bit = (|norm_val[SUM_WIDTH-4-OUT_MANTISSA_SIZE : 0]) | st2_sticky;

        round_up = guard_bit & (round_bit | sticky_bit | raw_mant[0]);
        rounded_mant_int = raw_mant + round_up;
        
        // Handle overflow (e.g., 1.111 -> 10.000)
        final_mant = rounded_mant_int[OUT_MANTISSA_SIZE] ? 0 : rounded_mant_int[OUT_MANTISSA_SIZE-1:0];
        
        // Exponent Adjustment
        final_exp_calc = $signed({2'b00, st2_exp_base}) + 2 - $signed({2'b00, lead_zeros}) + $signed({10'd0, rounded_mant_int[OUT_MANTISSA_SIZE]});

        // 4. Output Packing
        if (st2_sum_mag == 0) result_out = {st2_res_sign, {RES_WIDTH-1{1'b0}}};
        else if (final_exp_calc >= MAX_EXP) result_out = {st2_res_sign, {EXPONENT_SIZE{1'b1}}, {OUT_MANTISSA_SIZE{1'b0}}}; 
        else if (final_exp_calc <= 0)  result_out = {st2_res_sign, {RES_WIDTH-1{1'b0}}};
        else result_out = {st2_res_sign, final_exp_calc[EXPONENT_SIZE-1:0], final_mant};

        if (st2_special) result_out = st2_spec_res;
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) add.out <= 0;
        else add.out <= result_out;
    end

endmodule