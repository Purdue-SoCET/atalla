module sysarr_8_input_fp_adder #(
    parameter NUM_INPUTS       = 8,
    parameter MANTISSA_SIZE    = 23, 
    parameter EXPONENT_SIZE    = 8,
    parameter IN_MANTISSA_SIZE = 23,
    parameter IN_EXPONENT_SIZE = 8,
    parameter PRECISION_BITS   = 0
) (
    input  logic clk, 
    input  logic nRST,
    input  logic [NUM_INPUTS-1:0][1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE - 1 : 0] in_data,
    output logic [1 + EXPONENT_SIZE + MANTISSA_SIZE - 1 : 0] out_data
);

    localparam NEW_MANT_WIDTH = MANTISSA_SIZE + PRECISION_BITS + 1;
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 4; // Extra bits for 8-input growth
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + MANTISSA_SIZE; 
    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1); 
    localparam IN_WIDTH       = 1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE;

    // =================================================================================
    // STAGE 1: Extract, DAZ, Exception Check & Sort
    // =================================================================================
    logic [IN_WIDTH-1:0]         daz_data [8];
    logic [IN_EXPONENT_SIZE-1:0] exp_arr [8];
    logic [2:0]                  idx_arr [8];
    
    // Exception signals
    logic c_is_nan_any, c_any_pos_inf, c_any_neg_inf, c_spec_case;
    logic [RES_WIDTH-1:0] c_spec_res;

    // Tree signals
    logic [IN_EXPONENT_SIZE-1:0] e1 [4], e2 [2], c_max_exp;
    logic [2:0]                  i1 [4], i2 [2], c_max_idx;

    // Registers
    logic [IN_EXPONENT_SIZE-1:0] st1_max_exp;
    logic [2:0]                  st1_max_idx;
    logic [IN_WIDTH-1:0]         st1_data [8];
    logic                        st1_spec_case;
    logic [RES_WIDTH-1:0]        st1_spec_res;

    always_comb begin : stage1_sort_comb
        c_is_nan_any = 0; c_any_pos_inf = 0; c_any_neg_inf = 0;
        
        for (int i=0; i<8; i++) begin 
            // 1. DAZ Conversion
            daz_data[i] = (in_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ? 
                          {in_data[i][IN_WIDTH-1], {(IN_WIDTH-1){1'b0}}} : in_data[i];
            
            exp_arr[i] = daz_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE]; 
            idx_arr[i] = 3'(i); 
            
            // 2. Exception Detection
            if (&exp_arr[i] && |daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_is_nan_any = 1;
            if (&exp_arr[i] && ~daz_data[i][IN_WIDTH-1] && ~|daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_any_pos_inf = 1;
            if (&exp_arr[i] &&  daz_data[i][IN_WIDTH-1] && ~|daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_any_neg_inf = 1;
        end

        // Special Case Resolution
        c_spec_case = 0; c_spec_res = 0;
        if (c_is_nan_any || (c_any_pos_inf && c_any_neg_inf)) begin
            c_spec_case = 1; 
            // Note: If your specific testbench expects 7D00 for NaN instead of 7E00, adjust the payload below
            c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; 
        end else if (c_any_pos_inf) begin
            c_spec_case = 1; 
            c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end else if (c_any_neg_inf) begin
            c_spec_case = 1; 
            c_spec_res = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end

        // Layer 1
        for (int i=0; i<4; i++) begin
            if (exp_arr[2*i] >= exp_arr[2*i+1]) begin e1[i] = exp_arr[2*i]; i1[i] = idx_arr[2*i]; end
            else                                begin e1[i] = exp_arr[2*i+1]; i1[i] = idx_arr[2*i+1]; end
        end
        // Layer 2
        for (int i=0; i<2; i++) begin
            if (e1[2*i] >= e1[2*i+1]) begin e2[i] = e1[2*i]; i2[i] = i1[2*i]; end
            else                      begin e2[i] = e1[2*i+1]; i2[i] = i1[2*i+1]; end
        end
        // Layer 3
        if (e2[0] >= e2[1]) begin c_max_exp = e2[0]; c_max_idx = i2[0]; end
        else                begin c_max_exp = e2[1]; c_max_idx = i2[1]; end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_max_exp <= 0; st1_max_idx <= 0;
            st1_spec_case <= 0; st1_spec_res <= 0;
            for(int i=0; i<8; i++) st1_data[i] <= 0;
        end else begin
            st1_max_exp <= c_max_exp; 
            st1_max_idx <= c_max_idx;
            st1_spec_case <= c_spec_case;
            st1_spec_res <= c_spec_res;
            for(int i=0; i<8; i++) st1_data[i] <= daz_data[i]; // Forward DAZ data
        end
    end

    // =================================================================================
    // STAGE 2: Align and 8-input CSA Compression
    // =================================================================================
    logic [SUM_WIDTH:0]        op [8];
    logic [IN_EXPONENT_SIZE:0] sh [8];
    logic [NEW_MANT_WIDTH-1:0] m_base [8];
    logic                      sign_diff [8];
    logic                      c_sticky;
    logic [3:0]                c_hot_ones;
    
    // CSA Tree Wires
    logic [SUM_WIDTH:0] s1_0, c1_0, s1_1, c1_1;
    logic [SUM_WIDTH:0] s2_0, c2_0, s2_1, c2_1;
    logic [SUM_WIDTH:0] s3_0, c3_0;
    logic [SUM_WIDTH:0] s4_0, c4_0;

    // Registers
    logic [SUM_WIDTH:0]          st2_sum_vec, st2_carry_vec;
    logic [IN_EXPONENT_SIZE-1:0] st2_exp;
    logic                        st2_sign_max, st2_sticky;
    logic [3:0]                  st2_hot_ones;
    logic                        st2_spec_case;
    logic [RES_WIDTH-1:0]        st2_spec_res;

    always_comb begin : stage2_align_comb
        c_sticky = 0;
        
        for (int i=0; i<8; i++) begin
            m_base[i]    = { (st1_data[i][IN_WIDTH-2 -: IN_EXPONENT_SIZE] != 0), st1_data[i][IN_MANTISSA_SIZE-1 : 0], {(MANTISSA_SIZE-IN_MANTISSA_SIZE){1'b0}}, {PRECISION_BITS{1'b0}} };
            sh[i]        = st1_max_exp - st1_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE];
            sign_diff[i] = st1_data[i][IN_WIDTH-1] ^ st1_data[st1_max_idx][IN_WIDTH-1];
            
            if (3'(i) == st1_max_idx) begin
                op[i] = {4'b0000, m_base[i]};
                sign_diff[i] = 1'b0; 
            end else begin
                c_sticky |= |(m_base[i] & ~({NEW_MANT_WIDTH{1'b1}} << sh[i]));
                op[i] = sign_diff[i] ? ~{4'b0000, (m_base[i] >> sh[i])} : {4'b0000, (m_base[i] >> sh[i])};
            end
        end

        c_hot_ones = {3'b0, sign_diff[0]} + {3'b0, sign_diff[1]} + {3'b0, sign_diff[2]} + {3'b0, sign_diff[3]} + 
                     {3'b0, sign_diff[4]} + {3'b0, sign_diff[5]} + {3'b0, sign_diff[6]} + {3'b0, sign_diff[7]};

        s1_0 = op[0] ^ op[1] ^ op[2];                     c1_0 = (op[0]&op[1]) | (op[1]&op[2]) | (op[0]&op[2]);
        s1_1 = op[3] ^ op[4] ^ op[5];                     c1_1 = (op[3]&op[4]) | (op[4]&op[5]) | (op[3]&op[5]);
        s2_0 = s1_0 ^ (c1_0<<1) ^ s1_1;                   c2_0 = (s1_0&(c1_0<<1)) | ((c1_0<<1)&s1_1) | (s1_0&s1_1);
        s2_1 = (c1_1<<1) ^ op[6] ^ op[7];                 c2_1 = ((c1_1<<1)&op[6]) | (op[6]&op[7]) | ((c1_1<<1)&op[7]);
        s3_0 = s2_0 ^ (c2_0<<1) ^ s2_1;                   c3_0 = (s2_0&(c2_0<<1)) | ((c2_0<<1)&s2_1) | (s2_0&s2_1);
        s4_0 = s3_0 ^ (c3_0<<1) ^ (c2_1<<1);              c4_0 = (s3_0&(c3_0<<1)) | ((c3_0<<1)&(c2_1<<1)) | (s3_0&(c2_1<<1));
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st2_sum_vec <= 0; st2_carry_vec <= 0; st2_exp <= 0;
            st2_sign_max <= 0; st2_sticky <= 0; st2_hot_ones <= 0;
            st2_spec_case <= 0; st2_spec_res <= 0;
        end else begin
            st2_sum_vec   <= s4_0;
            st2_carry_vec <= c4_0;
            st2_exp       <= st1_max_exp;
            st2_sign_max  <= st1_data[st1_max_idx][IN_WIDTH-1];
            st2_sticky    <= c_sticky;
            st2_hot_ones  <= c_hot_ones;
            st2_spec_case <= st1_spec_case;
            st2_spec_res  <= st1_spec_res;
        end
    end

    // =================================================================================
    // STAGE 3: Final Magnitude Addition (CPA)
    // =================================================================================
    logic signed [SUM_WIDTH+1:0] c_raw_sum;
    logic [SUM_WIDTH-1:0]        c_mag_sum;
    logic                        c_res_sign;

    // Registers
    logic [SUM_WIDTH-1:0]        st3_mag_sum;
    logic                        st3_res_sign, st3_sticky;
    logic [IN_EXPONENT_SIZE-1:0] st3_exp;
    logic                        st3_spec_case;
    logic [RES_WIDTH-1:0]        st3_spec_res;

    always_comb begin : stage3_add_comb
        c_raw_sum = $signed({1'b0, st2_sum_vec}) + $signed(st2_carry_vec << 1) + $signed({{(SUM_WIDTH-3){1'b0}}, st2_hot_ones});
        
        if (c_raw_sum[SUM_WIDTH]) begin
            c_mag_sum  = SUM_WIDTH'(~c_raw_sum + 1'b1);
            c_res_sign = ~st2_sign_max;
        end else begin
            c_mag_sum  = SUM_WIDTH'(c_raw_sum[SUM_WIDTH-1:0]);
            c_res_sign = st2_sign_max;
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st3_mag_sum <= 0; st3_res_sign <= 0; 
            st3_exp <= 0; st3_sticky <= 0;
            st3_spec_case <= 0; st3_spec_res <= 0;
        end else begin
            st3_mag_sum   <= c_mag_sum;
            st3_res_sign  <= c_res_sign;
            st3_exp       <= st2_exp;
            st3_sticky    <= st2_sticky;
            st3_spec_case <= st2_spec_case;
            st3_spec_res  <= st2_spec_res;
        end
    end

    // =================================================================================
    // STAGE 4: Leading Zero Detection (LZD)
    // =================================================================================
    logic [SUM_WIDTH-1:0]       c_scan;
    logic [$clog2(SUM_WIDTH):0] c_lzd;

    // Registers
    logic [$clog2(SUM_WIDTH):0]  st4_lzd;
    logic [SUM_WIDTH-1:0]        st4_mag;
    logic                        st4_sign, st4_sticky;
    logic [IN_EXPONENT_SIZE-1:0] st4_exp;
    logic                        st4_spec_case;
    logic [RES_WIDTH-1:0]        st4_spec_res;

    always_comb begin : stage4_lzd_comb
        c_scan = st3_mag_sum;
        c_lzd = 0;
        for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
            if ((c_scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                c_lzd = c_lzd + (1 << i);
                c_scan = c_scan << (1 << i);
            end
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st4_lzd <= 0; st4_mag <= 0; st4_sign <= 0; 
            st4_exp <= 0; st4_sticky <= 0;
            st4_spec_case <= 0; st4_spec_res <= 0;
        end else begin
            st4_lzd       <= c_lzd;
            st4_mag       <= st3_mag_sum;
            st4_sign      <= st3_res_sign;
            st4_exp       <= st3_exp;
            st4_sticky    <= st3_sticky;
            st4_spec_case <= st3_spec_case;
            st4_spec_res  <= st3_spec_res;
        end
    end

    // =================================================================================
    // STAGE 5: Normalization, Exceptions, and Output Packing
    // =================================================================================
    logic [SUM_WIDTH-1:0]           c_norm;
    logic signed [EXPONENT_SIZE+2:0] c_e_final;

    always_comb begin : stage5_norm_comb
        c_norm = st4_mag << st4_lzd;
        c_e_final = $signed({2'b00, st4_exp}) + 4 - $signed({2'b00, st4_lzd}) + BIAS_DIFF;
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            out_data <= 0;
        end else begin
            // 1. Exception Override
            if (st4_spec_case) begin
                out_data <= st4_spec_res;
            end 
            // 2. Zero Check
            else if (st4_mag == 0 || c_e_final <= 0) begin
                out_data <= 0;
            end 
            // 3. Overflow (Inf)
            else if (c_e_final >= MAX_EXP) begin
                out_data <= {st4_sign, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}};
            end 
            // 4. Normal Path
            else begin
                out_data <= {st4_sign, c_e_final[EXPONENT_SIZE-1:0], c_norm[SUM_WIDTH-2 -: MANTISSA_SIZE]};
            end
        end
    end

endmodule
