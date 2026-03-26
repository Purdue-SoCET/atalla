module sysarr_32_input_fp_adder #(
    parameter NUM_INPUTS       = 32,
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
    // log2(32) = 5 bits of integer overflow growth. +1 for carry buffer.
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 6; 
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + MANTISSA_SIZE; 
    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1); 
    localparam IN_WIDTH       = 1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE;

    // =================================================================================
    // STAGE 1: DAZ, Exceptions, and Initial Sort (32 -> 8)
    // =================================================================================
    logic [IN_WIDTH-1:0]         st1_data [32];
    logic [IN_EXPONENT_SIZE-1:0] st1_e2 [8];
    logic [4:0]                  st1_i2 [8];
    logic                        st1_spec_case;
    logic [RES_WIDTH-1:0]        st1_spec_res;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_spec_case <= 0; st1_spec_res <= 0;
            for(int i=0; i<32; i++) st1_data[i] <= 0;
            for(int i=0; i<8;  i++) begin st1_e2[i] <= 0; st1_i2[i] <= 0; end
        end else begin
            logic c_is_nan_any, c_any_pos_inf, c_any_neg_inf;
            logic [IN_WIDTH-1:0] daz [32];
            logic [IN_EXPONENT_SIZE-1:0] e0 [32], e1 [16], e2 [8];
            logic [4:0]                  i0 [32], i1 [16], i2 [8];

            c_is_nan_any = 0; c_any_pos_inf = 0; c_any_neg_inf = 0;
            
            for (int i=0; i<32; i++) begin 
                daz[i] = (in_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ? 
                         {in_data[i][IN_WIDTH-1], {(IN_WIDTH-1){1'b0}}} : in_data[i];
                e0[i] = daz[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE]; 
                i0[i] = 5'(i); 
                
                if (&e0[i] && |daz[i][IN_MANTISSA_SIZE-1 : 0]) c_is_nan_any = 1;
                if (&e0[i] && ~daz[i][IN_WIDTH-1] && ~|daz[i][IN_MANTISSA_SIZE-1 : 0]) c_any_pos_inf = 1;
                if (&e0[i] &&  daz[i][IN_WIDTH-1] && ~|daz[i][IN_MANTISSA_SIZE-1 : 0]) c_any_neg_inf = 1;
                
                st1_data[i] <= daz[i];
            end

            if (c_is_nan_any || (c_any_pos_inf && c_any_neg_inf)) begin
                st1_spec_case <= 1; st1_spec_res <= {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; 
            end else if (c_any_pos_inf) begin
                st1_spec_case <= 1; st1_spec_res <= {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
            end else if (c_any_neg_inf) begin
                st1_spec_case <= 1; st1_spec_res <= {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
            end else begin
                st1_spec_case <= 0; st1_spec_res <= 0;
            end

            for (int i=0; i<16; i++) begin
                if (e0[2*i] >= e0[2*i+1]) begin e1[i] = e0[2*i]; i1[i] = i0[2*i]; end
                else                      begin e1[i] = e0[2*i+1]; i1[i] = i0[2*i+1]; end
            end
            for (int i=0; i<8; i++) begin
                if (e1[2*i] >= e1[2*i+1]) begin st1_e2[i] <= e1[2*i]; st1_i2[i] <= i1[2*i]; end
                else                      begin st1_e2[i] <= e1[2*i+1]; st1_i2[i] <= i1[2*i+1]; end
            end
        end
    end

    // =================================================================================
    // STAGE 2: Mid Sort (8 -> 2)
    // =================================================================================
    logic [IN_WIDTH-1:0]         st2_data [32];
    logic [IN_EXPONENT_SIZE-1:0] st2_e4 [2];
    logic [4:0]                  st2_i4 [2];
    logic                        st2_spec_case; logic [RES_WIDTH-1:0] st2_spec_res;

    always_ff @(posedge clk) begin
        logic [IN_EXPONENT_SIZE-1:0] e3 [4]; logic [4:0] i3 [4];
        for (int i=0; i<4; i++) begin
            if (st1_e2[2*i] >= st1_e2[2*i+1]) begin e3[i] = st1_e2[2*i]; i3[i] = st1_i2[2*i]; end
            else                              begin e3[i] = st1_e2[2*i+1]; i3[i] = st1_i2[2*i+1]; end
        end
        for (int i=0; i<2; i++) begin
            if (e3[2*i] >= e3[2*i+1]) begin st2_e4[i] <= e3[2*i]; st2_i4[i] <= i3[2*i]; end
            else                      begin st2_e4[i] <= e3[2*i+1]; st2_i4[i] <= i3[2*i+1]; end
        end
        for(int i=0; i<32; i++) st2_data[i] <= st1_data[i];
        st2_spec_case <= st1_spec_case; st2_spec_res <= st1_spec_res;
    end

    // =================================================================================
    // STAGE 3: Final Sort (2 -> 1)
    // =================================================================================
    logic [IN_WIDTH-1:0]         st3_data [32];
    logic [IN_EXPONENT_SIZE-1:0] st3_max_exp;
    logic [4:0]                  st3_max_idx;
    logic                        st3_spec_case; logic [RES_WIDTH-1:0] st3_spec_res;

    always_ff @(posedge clk) begin
        if (st2_e4[0] >= st2_e4[1]) begin st3_max_exp <= st2_e4[0]; st3_max_idx <= st2_i4[0]; end
        else                        begin st3_max_exp <= st2_e4[1]; st3_max_idx <= st2_i4[1]; end
        for(int i=0; i<32; i++) st3_data[i] <= st2_data[i];
        st3_spec_case <= st2_spec_case; st3_spec_res <= st2_spec_res;
    end

    // =================================================================================
    // STAGE 4: Calculate Shift & Base Mantissa
    // =================================================================================
    logic [IN_EXPONENT_SIZE:0]   st4_sh [32];
    logic [NEW_MANT_WIDTH-1:0]   st4_m_base [32];
    logic                        st4_sign_diff [32];
    logic [IN_EXPONENT_SIZE-1:0] st4_max_exp;
    logic                        st4_max_sign;
    logic                        st4_spec_case; logic [RES_WIDTH-1:0] st4_spec_res;

    always_ff @(posedge clk) begin
        for (int i=0; i<32; i++) begin
            st4_m_base[i] <= { (st3_data[i][IN_WIDTH-2 -: IN_EXPONENT_SIZE] != 0), st3_data[i][IN_MANTISSA_SIZE-1 : 0], {(MANTISSA_SIZE-IN_MANTISSA_SIZE){1'b0}}, {PRECISION_BITS{1'b0}} };
            st4_sh[i] <= st3_max_exp - st3_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE];
            
            if (5'(i) == st3_max_idx) st4_sign_diff[i] <= 1'b0;
            else                      st4_sign_diff[i] <= st3_data[i][IN_WIDTH-1] ^ st3_data[st3_max_idx][IN_WIDTH-1];
        end
        st4_max_exp <= st3_max_exp;
        st4_max_sign <= st3_data[st3_max_idx][IN_WIDTH-1];
        st4_spec_case <= st3_spec_case; st4_spec_res <= st3_spec_res;
    end

    // =================================================================================
    // STAGE 5: Barrel Shift & Parallel Hot-Ones Counter
    // =================================================================================
    logic [SUM_WIDTH:0]          st5_op [32];
    logic [5:0]                  st5_hot_ones;
    logic [IN_EXPONENT_SIZE-1:0] st5_exp;
    logic                        st5_sign;
    logic                        st5_spec_case; logic [RES_WIDTH-1:0] st5_spec_res;

    always_ff @(posedge clk) begin
        for (int i=0; i<32; i++) begin
            st5_op[i] <= st4_sign_diff[i] ? ~{6'b0, (st4_m_base[i] >> st4_sh[i])} : {6'b0, (st4_m_base[i] >> st4_sh[i])};
        end
        // Synthesis easily maps this into a tiny 5-level half-adder tree (perfect for 1GHz)
        st5_hot_ones <= st4_sign_diff[0] + st4_sign_diff[1] + st4_sign_diff[2] + st4_sign_diff[3] + st4_sign_diff[4] + st4_sign_diff[5] + st4_sign_diff[6] + st4_sign_diff[7] + 
                        st4_sign_diff[8] + st4_sign_diff[9] + st4_sign_diff[10]+ st4_sign_diff[11]+ st4_sign_diff[12]+ st4_sign_diff[13]+ st4_sign_diff[14]+ st4_sign_diff[15]+
                        st4_sign_diff[16]+ st4_sign_diff[17]+ st4_sign_diff[18]+ st4_sign_diff[19]+ st4_sign_diff[20]+ st4_sign_diff[21]+ st4_sign_diff[22]+ st4_sign_diff[23]+
                        st4_sign_diff[24]+ st4_sign_diff[25]+ st4_sign_diff[26]+ st4_sign_diff[27]+ st4_sign_diff[28]+ st4_sign_diff[29]+ st4_sign_diff[30]+ st4_sign_diff[31];
                        
        st5_exp <= st4_max_exp; st5_sign <= st4_max_sign;
        st5_spec_case <= st4_spec_case; st5_spec_res <= st4_spec_res;
    end

    // =================================================================================
    // STAGE 6: CSA Tree Levels 1, 2, 3 (32 Vectors -> 10 Vectors)
    // =================================================================================
    logic [SUM_WIDTH:0] st6_vec [10];
    logic [5:0] st6_hot_ones; logic [IN_EXPONENT_SIZE-1:0] st6_exp; logic st6_sign, st6_spec_case; logic [RES_WIDTH-1:0] st6_spec_res;

    always_ff @(posedge clk) begin
        logic [SUM_WIDTH:0] L2[22], L3[15], L4[10];
        
        // Level 1: 32 -> 22 (10 FAs, 2 Pass)
        for(int i=0; i<10; i++) begin
            L2[2*i]   = st5_op[3*i] ^ st5_op[3*i+1] ^ st5_op[3*i+2];
            L2[2*i+1] = ((st5_op[3*i] & st5_op[3*i+1]) | (st5_op[3*i+1] & st5_op[3*i+2]) | (st5_op[3*i] & st5_op[3*i+2])) << 1;
        end
        L2[20] = st5_op[30]; L2[21] = st5_op[31];

        // Level 2: 22 -> 15 (7 FAs, 1 Pass)
        for(int i=0; i<7; i++) begin
            L3[2*i]   = L2[3*i] ^ L2[3*i+1] ^ L2[3*i+2];
            L3[2*i+1] = ((L2[3*i] & L2[3*i+1]) | (L2[3*i+1] & L2[3*i+2]) | (L2[3*i] & L2[3*i+2])) << 1;
        end
        L3[14] = L2[21];

        // Level 3: 15 -> 10 (5 FAs, 0 Pass)
        for(int i=0; i<5; i++) begin
            L4[2*i]   = L3[3*i] ^ L3[3*i+1] ^ L3[3*i+2];
            L4[2*i+1] = ((L3[3*i] & L3[3*i+1]) | (L3[3*i+1] & L3[3*i+2]) | (L3[3*i] & L3[3*i+2])) << 1;
        end
        
        for(int i=0; i<10; i++) st6_vec[i] <= L4[i];
        
        st6_hot_ones <= st5_hot_ones; st6_exp <= st5_exp; st6_sign <= st5_sign;
        st6_spec_case <= st5_spec_case; st6_spec_res <= st5_spec_res;
    end

    // =================================================================================
    // STAGE 7: CSA Tree Levels 4, 5, 6 (10 Vectors -> 4 Vectors)
    // =================================================================================
    logic [SUM_WIDTH:0] st7_vec [4];
    logic [5:0] st7_hot_ones; logic [IN_EXPONENT_SIZE-1:0] st7_exp; logic st7_sign, st7_spec_case; logic [RES_WIDTH-1:0] st7_spec_res;

    always_ff @(posedge clk) begin
        logic [SUM_WIDTH:0] L5[7], L6[5], L7[4];
        
        // Level 4: 10 -> 7 (3 FAs, 1 Pass)
        for(int i=0; i<3; i++) begin
            L5[2*i]   = st6_vec[3*i] ^ st6_vec[3*i+1] ^ st6_vec[3*i+2];
            L5[2*i+1] = ((st6_vec[3*i] & st6_vec[3*i+1]) | (st6_vec[3*i+1] & st6_vec[3*i+2]) | (st6_vec[3*i] & st6_vec[3*i+2])) << 1;
        end
        L5[6] = st6_vec[9];

        // Level 5: 7 -> 5 (2 FAs, 1 Pass)
        for(int i=0; i<2; i++) begin
            L6[2*i]   = L5[3*i] ^ L5[3*i+1] ^ L5[3*i+2];
            L6[2*i+1] = ((L5[3*i] & L5[3*i+1]) | (L5[3*i+1] & L5[3*i+2]) | (L5[3*i] & L5[3*i+2])) << 1;
        end
        L6[4] = L5[6];

        // Level 6: 5 -> 4 (1 FA, 2 Pass)
        L7[0] = L6[0] ^ L6[1] ^ L6[2];
        L7[1] = ((L6[0] & L6[1]) | (L6[1] & L6[2]) | (L6[0] & L6[2])) << 1;
        L7[2] = L6[3];
        L7[3] = L6[4];

        for(int i=0; i<4; i++) st7_vec[i] <= L7[i];
        
        st7_hot_ones <= st6_hot_ones; st7_exp <= st6_exp; st7_sign <= st6_sign;
        st7_spec_case <= st6_spec_case; st7_spec_res <= st6_spec_res;
    end

    // =================================================================================
    // STAGE 8: CSA Tree Levels 7, 8 (4 Vectors -> 2 Vectors)
    // =================================================================================
    logic [SUM_WIDTH:0] st8_sum, st8_carry;
    logic [5:0] st8_hot_ones; logic [IN_EXPONENT_SIZE-1:0] st8_exp; logic st8_sign, st8_spec_case; logic [RES_WIDTH-1:0] st8_spec_res;

    always_ff @(posedge clk) begin
        logic [SUM_WIDTH:0] L8[3], L9[2];
        
        // Level 7: 4 -> 3 (1 FA, 1 Pass)
        L8[0] = st7_vec[0] ^ st7_vec[1] ^ st7_vec[2];
        L8[1] = ((st7_vec[0] & st7_vec[1]) | (st7_vec[1] & st7_vec[2]) | (st7_vec[0] & st7_vec[2])) << 1;
        L8[2] = st7_vec[3];

        // Level 8: 3 -> 2 (1 FA, 0 Pass)
        L9[0] = L8[0] ^ L8[1] ^ L8[2];
        L9[1] = ((L8[0] & L8[1]) | (L8[1] & L8[2]) | (L8[0] & L8[2])) << 1;

        st8_sum <= L9[0]; st8_carry <= L9[1];
        st8_hot_ones <= st7_hot_ones; st8_exp <= st7_exp; st8_sign <= st7_sign;
        st8_spec_case <= st7_spec_case; st8_spec_res <= st7_spec_res;
    end

    // =================================================================================
    // STAGE 9: Final CPA Magnitude Addition
    // =================================================================================
    logic [SUM_WIDTH-1:0]        st9_mag;
    logic                        st9_sign, st9_spec_case;
    logic [IN_EXPONENT_SIZE-1:0] st9_exp;
    logic [RES_WIDTH-1:0]        st9_spec_res;

    always_ff @(posedge clk) begin
        logic signed [SUM_WIDTH+1:0] raw_sum;
        raw_sum = $signed({1'b0, st8_sum}) + $signed(st8_carry) + $signed({{(SUM_WIDTH-5){1'b0}}, st8_hot_ones});
        
        if (raw_sum[SUM_WIDTH]) begin
            st9_mag  <= SUM_WIDTH'(~raw_sum + 1'b1);
            st9_sign <= ~st8_sign;
        end else begin
            st9_mag  <= SUM_WIDTH'(raw_sum[SUM_WIDTH-1:0]);
            st9_sign <= st8_sign;
        end
        st9_exp <= st8_exp; st9_spec_case <= st8_spec_case; st9_spec_res <= st8_spec_res;
    end

    // =================================================================================
    // STAGE 10: Leading Zero Detection (LZD)
    // =================================================================================
    logic [$clog2(SUM_WIDTH):0]  st10_lzd;
    logic [SUM_WIDTH-1:0]        st10_mag;
    logic                        st10_sign, st10_spec_case;
    logic [IN_EXPONENT_SIZE-1:0] st10_exp;
    logic [RES_WIDTH-1:0]        st10_spec_res;

    always_ff @(posedge clk) begin
        logic [SUM_WIDTH-1:0] scan; logic [$clog2(SUM_WIDTH):0] lzd_cnt;
        scan = st9_mag; lzd_cnt = 0;
        
        for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
            if ((scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                lzd_cnt += (1 << i);
                scan <<= (1 << i);
            end
        end
        
        st10_lzd <= lzd_cnt; st10_mag <= st9_mag; st10_sign <= st9_sign; 
        st10_exp <= st9_exp; st10_spec_case <= st9_spec_case; st10_spec_res <= st9_spec_res;
    end

    // =================================================================================
    // STAGE 11: Normalization, Bounds, and Output Pack
    // =================================================================================
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            out_data <= 0;
        end else begin
            logic [SUM_WIDTH-1:0] norm; logic signed [EXPONENT_SIZE+2:0] e_final;
            
            norm = st10_mag << st10_lzd;
            // +6 accounts for the 6 extra integer bits added to SUM_WIDTH for the 32 inputs
            e_final = $signed({2'b00, st10_exp}) + 6 - $signed({2'b00, st10_lzd}) + BIAS_DIFF;

            if (st10_spec_case) begin
                out_data <= st10_spec_res;
            end else if (st10_mag == 0 || e_final <= 0) begin
                out_data <= 0; 
            end else if (e_final >= MAX_EXP) begin
                out_data <= {st10_sign, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
            end else begin
                out_data <= {st10_sign, e_final[EXPONENT_SIZE-1:0], norm[SUM_WIDTH-2 -: MANTISSA_SIZE]};
            end
        end
    end

endmodule
