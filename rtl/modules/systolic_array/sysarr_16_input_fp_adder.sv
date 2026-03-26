module sysarr_16_input_fp_adder #(
    parameter NUM_INPUTS       = 16,
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
    // log2(16) = 4 bits of overflow growth. +1 for carry buffer.
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 5; 
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + MANTISSA_SIZE; 
    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1); 
    localparam IN_WIDTH       = 1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE;

    // =================================================================================
    // STAGE 1: DAZ, Exceptions, and Initial Sort (16 -> 4)
    // =================================================================================
    logic [IN_WIDTH-1:0]         daz_data [16];
    logic [IN_EXPONENT_SIZE-1:0] exp_arr [16];
    logic [3:0]                  idx_arr [16];
    
    logic c_is_nan_any, c_any_pos_inf, c_any_neg_inf, c_spec_case;
    logic [RES_WIDTH-1:0] c_spec_res;

    logic [IN_EXPONENT_SIZE-1:0] e1 [8], e2 [4];
    logic [3:0]                  i1 [8], i2 [4];

    logic [IN_WIDTH-1:0]         st1_data [16];
    logic [IN_EXPONENT_SIZE-1:0] st1_e2 [4];
    logic [3:0]                  st1_i2 [4];
    logic                        st1_spec_case;
    logic [RES_WIDTH-1:0]        st1_spec_res;

    always_comb begin
        c_is_nan_any = 0; c_any_pos_inf = 0; c_any_neg_inf = 0;
        
        for (int i=0; i<16; i++) begin 
            daz_data[i] = (in_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ? 
                          {in_data[i][IN_WIDTH-1], {(IN_WIDTH-1){1'b0}}} : in_data[i];
            exp_arr[i] = daz_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE]; 
            idx_arr[i] = 4'(i); 
            
            if (&exp_arr[i] && |daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_is_nan_any = 1;
            if (&exp_arr[i] && ~daz_data[i][IN_WIDTH-1] && ~|daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_any_pos_inf = 1;
            if (&exp_arr[i] &&  daz_data[i][IN_WIDTH-1] && ~|daz_data[i][IN_MANTISSA_SIZE-1 : 0]) c_any_neg_inf = 1;
        end

        c_spec_case = 0; c_spec_res = 0;
        if (c_is_nan_any || (c_any_pos_inf && c_any_neg_inf)) begin
            c_spec_case = 1; c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; 
        end else if (c_any_pos_inf) begin
            c_spec_case = 1; c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end else if (c_any_neg_inf) begin
            c_spec_case = 1; c_spec_res = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end

        // Tree Layer 1 (16 -> 8)
        for (int i=0; i<8; i++) begin
            if (exp_arr[2*i] >= exp_arr[2*i+1]) begin e1[i] = exp_arr[2*i]; i1[i] = idx_arr[2*i]; end
            else                                begin e1[i] = exp_arr[2*i+1]; i1[i] = idx_arr[2*i+1]; end
        end
        // Tree Layer 2 (8 -> 4)
        for (int i=0; i<4; i++) begin
            if (e1[2*i] >= e1[2*i+1]) begin e2[i] = e1[2*i]; i2[i] = i1[2*i]; end
            else                      begin e2[i] = e1[2*i+1]; i2[i] = i1[2*i+1]; end
        end
    end

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_spec_case <= 0; st1_spec_res <= 0;
            for(int i=0; i<16; i++) st1_data[i] <= 0;
            for(int i=0; i<4; i++) begin st1_e2[i] <= 0; st1_i2[i] <= 0; end
        end else begin
            st1_spec_case <= c_spec_case; st1_spec_res <= c_spec_res;
            for(int i=0; i<16; i++) st1_data[i] <= daz_data[i];
            for(int i=0; i<4; i++) begin st1_e2[i] <= e2[i]; st1_i2[i] <= i2[i]; end
        end
    end

    // =================================================================================
    // STAGE 2: Final Sort (4 -> 1)
    // =================================================================================
    logic [IN_EXPONENT_SIZE-1:0] e3 [2], c_max_exp;
    logic [3:0]                  i3 [2], c_max_idx;

    logic [IN_WIDTH-1:0]         st2_data [16];
    logic [IN_EXPONENT_SIZE-1:0] st2_max_exp;
    logic [3:0]                  st2_max_idx;
    logic                        st2_spec_case;
    logic [RES_WIDTH-1:0]        st2_spec_res;

    always_comb begin
        for (int i=0; i<2; i++) begin
            if (st1_e2[2*i] >= st1_e2[2*i+1]) begin e3[i] = st1_e2[2*i]; i3[i] = st1_i2[2*i]; end
            else                              begin e3[i] = st1_e2[2*i+1]; i3[i] = st1_i2[2*i+1]; end
        end
        if (e3[0] >= e3[1]) begin c_max_exp = e3[0]; c_max_idx = i3[0]; end
        else                begin c_max_exp = e3[1]; c_max_idx = i3[1]; end
    end

    always_ff @(posedge clk) begin
        st2_max_exp <= c_max_exp; st2_max_idx <= c_max_idx;
        st2_spec_case <= st1_spec_case; st2_spec_res <= st1_spec_res;
        for(int i=0; i<16; i++) st2_data[i] <= st1_data[i];
    end

    // =================================================================================
    // STAGE 3: Alignment and Inversion
    // =================================================================================
    logic [SUM_WIDTH:0]          st3_op [16];
    logic [4:0]                  st3_hot_ones;
    logic [IN_EXPONENT_SIZE-1:0] st3_exp;
    logic                        st3_sign_max;
    logic                        st3_spec_case;
    logic [RES_WIDTH-1:0]        st3_spec_res;

    always_ff @(posedge clk) begin
        logic [IN_EXPONENT_SIZE:0] sh;
        logic [NEW_MANT_WIDTH-1:0] m_base;
        logic                      sign_diff [16];
        logic [4:0]                hot_cnt;

        hot_cnt = 0;
        for (int i=0; i<16; i++) begin
            m_base = { (st2_data[i][IN_WIDTH-2 -: IN_EXPONENT_SIZE] != 0), st2_data[i][IN_MANTISSA_SIZE-1 : 0], {(MANTISSA_SIZE-IN_MANTISSA_SIZE){1'b0}}, {PRECISION_BITS{1'b0}} };
            sh = st2_max_exp - st2_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE];
            sign_diff[i] = st2_data[i][IN_WIDTH-1] ^ st2_data[st2_max_idx][IN_WIDTH-1];
            
            if (4'(i) == st2_max_idx) begin
                st3_op[i] <= {5'b0, m_base};
                sign_diff[i] = 1'b0; 
            end else begin
                st3_op[i] <= sign_diff[i] ? ~{5'b0, (m_base >> sh)} : {5'b0, (m_base >> sh)};
                hot_cnt += sign_diff[i];
            end
        end

        st3_hot_ones <= hot_cnt;
        st3_exp <= st2_max_exp;
        st3_sign_max <= st2_data[st2_max_idx][IN_WIDTH-1];
        st3_spec_case <= st2_spec_case;
        st3_spec_res <= st2_spec_res;
    end

    // =================================================================================
    // STAGE 4: 16-to-2 CSA Reduction Tree
    // =================================================================================
    logic [SUM_WIDTH:0]          st4_sum, st4_carry;
    logic [4:0]                  st4_hot_ones;
    logic [IN_EXPONENT_SIZE-1:0] st4_exp;
    logic                        st4_sign_max, st4_spec_case;
    logic [RES_WIDTH-1:0]        st4_spec_res;

    always_ff @(posedge clk) begin
        // Explicit 16-input reduction wires
        logic [SUM_WIDTH:0] s1_0, c1_0, s1_1, c1_1, s1_2, c1_2, s1_3, c1_3, s1_4, c1_4;
        logic [SUM_WIDTH:0] s2_0, c2_0, s2_1, c2_1, s2_2, c2_2;
        logic [SUM_WIDTH:0] s3_0, c3_0, s3_1, c3_1;
        logic [SUM_WIDTH:0] s4_0, c4_0, s4_1, c4_1;
        logic [SUM_WIDTH:0] s5_0, c5_0, s6_0, c6_0;

        // Level 1
        s1_0 = st3_op[0] ^ st3_op[1] ^ st3_op[2];       c1_0 = (st3_op[0]&st3_op[1]) | (st3_op[1]&st3_op[2]) | (st3_op[0]&st3_op[2]);
        s1_1 = st3_op[3] ^ st3_op[4] ^ st3_op[5];       c1_1 = (st3_op[3]&st3_op[4]) | (st3_op[4]&st3_op[5]) | (st3_op[3]&st3_op[5]);
        s1_2 = st3_op[6] ^ st3_op[7] ^ st3_op[8];       c1_2 = (st3_op[6]&st3_op[7]) | (st3_op[7]&st3_op[8]) | (st3_op[6]&st3_op[8]);
        s1_3 = st3_op[9] ^ st3_op[10] ^ st3_op[11];     c1_3 = (st3_op[9]&st3_op[10]) | (st3_op[10]&st3_op[11]) | (st3_op[9]&st3_op[11]);
        s1_4 = st3_op[12] ^ st3_op[13] ^ st3_op[14];    c1_4 = (st3_op[12]&st3_op[13]) | (st3_op[13]&st3_op[14]) | (st3_op[12]&st3_op[14]);
        
        // Level 2
        s2_0 = s1_0 ^ (c1_0<<1) ^ s1_1;                 c2_0 = (s1_0&(c1_0<<1)) | ((c1_0<<1)&s1_1) | (s1_0&s1_1);
        s2_1 = (c1_1<<1) ^ s1_2 ^ (c1_2<<1);            c2_1 = ((c1_1<<1)&s1_2) | (s1_2&(c1_2<<1)) | ((c1_1<<1)&(c1_2<<1));
        s2_2 = s1_3 ^ (c1_3<<1) ^ s1_4;                 c2_2 = (s1_3&(c1_3<<1)) | ((c1_3<<1)&s1_4) | (s1_3&s1_4);
        
        // Level 3
        s3_0 = s2_0 ^ (c2_0<<1) ^ s2_1;                 c3_0 = (s2_0&(c2_0<<1)) | ((c2_0<<1)&s2_1) | (s2_0&s2_1);
        s3_1 = (c2_1<<1) ^ s2_2 ^ (c2_2<<1);            c3_1 = ((c2_1<<1)&s2_2) | (s2_2&(c2_2<<1)) | ((c2_1<<1)&(c2_2<<1));
        
        // Level 4
        s4_0 = s3_0 ^ (c3_0<<1) ^ s3_1;                 c4_0 = (s3_0&(c3_0<<1)) | ((c3_0<<1)&s3_1) | (s3_0&s3_1);
        s4_1 = (c3_1<<1) ^ (c1_4<<1) ^ st3_op[15];      c4_1 = ((c3_1<<1)&(c1_4<<1)) | ((c1_4<<1)&st3_op[15]) | ((c3_1<<1)&st3_op[15]);
        
        // Level 5
        s5_0 = s4_0 ^ (c4_0<<1) ^ s4_1;                 c5_0 = (s4_0&(c4_0<<1)) | ((c4_0<<1)&s4_1) | (s4_0&s4_1);
        
        // Level 6
        s6_0 = s5_0 ^ (c5_0<<1) ^ (c4_1<<1);            c6_0 = (s5_0&(c5_0<<1)) | ((c5_0<<1)&(c4_1<<1)) | (s5_0&(c4_1<<1));

        st4_sum <= s6_0; st4_carry <= c6_0;
        st4_hot_ones <= st3_hot_ones; st4_exp <= st3_exp; st4_sign_max <= st3_sign_max;
        st4_spec_case <= st3_spec_case; st4_spec_res <= st3_spec_res;
    end

    // =================================================================================
    // STAGE 5: Final CPA Addition and Magnitude Extraction
    // =================================================================================
    logic [SUM_WIDTH-1:0]        st5_mag;
    logic                        st5_sign, st5_spec_case;
    logic [IN_EXPONENT_SIZE-1:0] st5_exp;
    logic [RES_WIDTH-1:0]        st5_spec_res;

    always_ff @(posedge clk) begin
        logic signed [SUM_WIDTH+1:0] raw_sum;
        raw_sum = $signed({1'b0, st4_sum}) + $signed(st4_carry << 1) + $signed({{(SUM_WIDTH-4){1'b0}}, st4_hot_ones});
        
        if (raw_sum[SUM_WIDTH]) begin
            st5_mag  <= SUM_WIDTH'(~raw_sum + 1'b1);
            st5_sign <= ~st4_sign_max;
        end else begin
            st5_mag  <= SUM_WIDTH'(raw_sum[SUM_WIDTH-1:0]);
            st5_sign <= st4_sign_max;
        end
        st5_exp <= st4_exp; st5_spec_case <= st4_spec_case; st5_spec_res <= st4_spec_res;
    end

    // =================================================================================
    // STAGE 6: Leading Zero Detection (LZD)
    // =================================================================================
    logic [$clog2(SUM_WIDTH):0]  st6_lzd;
    logic [SUM_WIDTH-1:0]        st6_mag;
    logic                        st6_sign, st6_spec_case;
    logic [IN_EXPONENT_SIZE-1:0] st6_exp;
    logic [RES_WIDTH-1:0]        st6_spec_res;

    always_ff @(posedge clk) begin
        logic [SUM_WIDTH-1:0] scan;
        logic [$clog2(SUM_WIDTH):0] lzd_cnt;
        
        scan = st5_mag; lzd_cnt = 0;
        for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
            if ((scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                lzd_cnt += (1 << i);
                scan <<= (1 << i);
            end
        end
        st6_lzd <= lzd_cnt; st6_mag <= st5_mag; st6_sign <= st5_sign; 
        st6_exp <= st5_exp; st6_spec_case <= st5_spec_case; st6_spec_res <= st5_spec_res;
    end

    // =================================================================================
    // STAGE 7: Normalization and Exponent Calc
    // =================================================================================
    logic [SUM_WIDTH-1:0]           st7_norm;
    logic signed [EXPONENT_SIZE+2:0] st7_e_final;
    logic                           st7_sign, st7_spec_case, st7_is_zero;
    logic [RES_WIDTH-1:0]           st7_spec_res;

    always_ff @(posedge clk) begin
        st7_norm <= st6_mag << st6_lzd;
        // +4 accounts for the 4 extra bits added to SUM_WIDTH for the 16 inputs
        st7_e_final <= $signed({2'b00, st6_exp}) + 4 - $signed({2'b00, st6_lzd}) + BIAS_DIFF;
        st7_is_zero <= (st6_mag == 0);
        st7_sign <= st6_sign; st7_spec_case <= st6_spec_case; st7_spec_res <= st6_spec_res;
    end

    // =================================================================================
    // STAGE 8: Rounding, Boundaries, and Output Packing
    // =================================================================================
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            out_data <= 0;
        end else begin
            if (st7_spec_case) begin
                out_data <= st7_spec_res;
            end else if (st7_is_zero || st7_e_final <= 0) begin
                out_data <= 0; // Underflow / Zero
            end else if (st7_e_final >= MAX_EXP) begin
                out_data <= {st7_sign, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // Overflow
            end else begin
                out_data <= {st7_sign, st7_e_final[EXPONENT_SIZE-1:0], st7_norm[SUM_WIDTH-2 -: MANTISSA_SIZE]};
            end
        end
    end

endmodule
