module sysarr_n_input_fp_adder #(
    parameter NUM_INPUTS       = 8,  
    parameter MANTISSA_SIZE    = 23, 
    parameter EXPONENT_SIZE    = 8,  
    parameter IN_MANTISSA_SIZE = 23,  
    parameter IN_EXPONENT_SIZE = 8,  
    parameter PRECISION_BITS   = 0,
    parameter EXTRA_STAGES     = 3 
) (
    input  logic clk, 
    input  logic nRST,
    input  logic [NUM_INPUTS-1:0][1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE - 1 : 0] in_data,
    output logic [1 + EXPONENT_SIZE + MANTISSA_SIZE - 1 : 0] out_data
);

    localparam NEW_MANT_WIDTH = MANTISSA_SIZE + PRECISION_BITS + 1;
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 2; 
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + MANTISSA_SIZE; 
    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1); 
    localparam IN_WIDTH       = 1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE; 
    localparam HOT_ONES_W     = $clog2(NUM_INPUTS + 1); 

    // --- Tree Sorting Parameters ---
    localparam LEVELS = $clog2(NUM_INPUTS);
    localparam P      = 1 << LEVELS; // Next power of 2 for tree padding base
    localparam IDX_W  = (LEVELS == 0) ? 1 : LEVELS; // Safe width for index signals

    // Internal Arrays for N inputs
    logic [IN_WIDTH-1:0]           daz_in       [NUM_INPUTS];
    logic [IN_EXPONENT_SIZE-1:0]   exp          [NUM_INPUTS];
    logic [IN_MANTISSA_SIZE-1:0]   frac         [NUM_INPUTS];
    logic                          sign         [NUM_INPUTS];
    
    // Binary Tree Signals for Sorting
    logic [IN_EXPONENT_SIZE-1:0]   tree_exp [LEVELS+1][P];
    logic [IDX_W-1:0]              tree_idx [LEVELS+1][P];

    // Align & Shift signals
    logic [IN_EXPONENT_SIZE-1:0]   max_exp, max_exp_eff;
    logic [IDX_W-1:0]              max_idx;
    logic                          sign_max;
    
    logic [IN_EXPONENT_SIZE:0]     shift        [NUM_INPUTS];
    logic [NEW_MANT_WIDTH-1:0]     mant_base    [NUM_INPUTS];
    logic [NEW_MANT_WIDTH-1:0]     shifted_mant [NUM_INPUTS];
    logic                          sticky       [NUM_INPUTS];
    logic                          op_sign_diff [NUM_INPUTS];
    logic [SUM_WIDTH:0]            op           [NUM_INPUTS];

    // Exception signals
    logic is_nan_any, any_pos_inf, any_neg_inf, special_case;
    logic [RES_WIDTH-1:0] special_result;

    // CSA Tree Arrays
    logic [SUM_WIDTH:0] csa_s [NUM_INPUTS];
    logic [SUM_WIDTH:0] csa_c [NUM_INPUTS];

    // --- Pipeline Stage 1 Registers ---
    logic [IN_EXPONENT_SIZE-1:0] st1_a_e;
    logic st1_a_s, st1_align_sticky, st1_special_case;
    logic [RES_WIDTH-1:0]        st1_special_result;
    logic [SUM_WIDTH:0]          st1_sum_vec;
    logic [SUM_WIDTH:0]          st1_carry_vec;
    logic [HOT_ONES_W-1:0]       st1_hot_ones; 

    // --- Stage 2 Signals & Registers ---
    logic signed [SUM_WIDTH+1:0] raw_sum;
    logic [SUM_WIDTH-1:0]        mag_sum;
    logic                        res_sign;

    logic [IN_EXPONENT_SIZE-1:0] st2_exp_base;
    logic [SUM_WIDTH-1:0]        st2_sum_mag;
    logic [RES_WIDTH-1:0]        st2_spec_res;
    logic                        st2_res_sign, st2_sticky, st2_special;

    // --- Stage 3 Signals ---
    logic [SUM_WIDTH-1:0]        lzd_scan;
    logic [$clog2(SUM_WIDTH):0]  lead_zeros; 
    logic [SUM_WIDTH-1:0]        norm_val;
    logic [MANTISSA_SIZE-1:0]    final_mant;
    logic signed [EXPONENT_SIZE+2:0] final_exp_calc;
    logic [RES_WIDTH-1:0]        result_out;

    // =================================================================================
    // STAGE 1: Extract, Tree Sort (Find Max), Align, and COMPRESS
    // =================================================================================
    always_comb begin : stage1_logic
        is_nan_any = 0; any_pos_inf = 0; any_neg_inf = 0;

        // 1. DAZ Conversion, Decomposition, and Exception Checking
        for (int i = 0; i < NUM_INPUTS; i++) begin
            daz_in[i] = (in_data[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ? 
                        {in_data[i][IN_WIDTH-1], {(IN_WIDTH-1){1'b0}}} : in_data[i];
            
            sign[i] = daz_in[i][IN_WIDTH-1];
            exp[i]  = daz_in[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE];
            frac[i] = daz_in[i][IN_MANTISSA_SIZE-1 : 0];

            if (&exp[i] & |frac[i]) is_nan_any = 1;
            if (&exp[i] & ~sign[i] & ~|frac[i]) any_pos_inf = 1;
            if (&exp[i] &  sign[i] & ~|frac[i]) any_neg_inf = 1;
        end

        // 2. BINARY TREE to find Maximum Exponent and its Index
        // Populate the leaves (Level 0) with padding for non-powers of 2
        for (int i = 0; i < P; i++) begin
            if (i < NUM_INPUTS) begin
                tree_exp[0][i] = exp[i];
                tree_idx[0][i] = i[IDX_W-1:0];
            end else begin
                tree_exp[0][i] = 0; 
                tree_idx[0][i] = 0;
            end
        end

        // Build the reduction tree
        for (int lvl = 0; lvl < LEVELS; lvl++) begin
            for (int i = 0; i < (P >> (lvl + 1)); i++) begin
                if (tree_exp[lvl][2*i] >= tree_exp[lvl][2*i + 1]) begin
                    tree_exp[lvl+1][i] = tree_exp[lvl][2*i];
                    tree_idx[lvl+1][i] = tree_idx[lvl][2*i];
                end else begin
                    tree_exp[lvl+1][i] = tree_exp[lvl][2*i + 1];
                    tree_idx[lvl+1][i] = tree_idx[lvl][2*i + 1];
                end
            end
        end

        // Output of the tree
        max_exp = tree_exp[LEVELS][0];
        max_idx = tree_idx[LEVELS][0];
        sign_max = sign[max_idx];

        // 3. Resolve Special Cases
        special_case = 0; special_result = 0; 
        if (is_nan_any || (any_pos_inf && any_neg_inf)) begin
            special_case = 1; 
            special_result = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; 
        end else if (any_pos_inf) begin
            special_case = 1; 
            special_result = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end else if (any_neg_inf) begin
            special_case = 1; 
            special_result = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        end

        // 4. Align and Shift
        max_exp_eff = (max_exp == 0) ? 1 : max_exp;
        
        for (int i = 0; i < NUM_INPUTS; i++) begin
            mant_base[i] = { (|exp[i]), frac[i], {(MANTISSA_SIZE-IN_MANTISSA_SIZE){1'b0}}, {PRECISION_BITS{1'b0}} };
            shift[i] = max_exp_eff - ((exp[i] == 0) ? 1 : exp[i]);
            
            sticky[i] = |(mant_base[i] & ~({NEW_MANT_WIDTH{1'b1}} << shift[i]));
            shifted_mant[i] = (shift[i] >= NEW_MANT_WIDTH) ? 0 : (mant_base[i] >> shift[i]);
            
            op_sign_diff[i] = sign_max ^ sign[i];

            if (i[IDX_W-1:0] == max_idx) begin
                op[i] = {3'b000, shifted_mant[i]};
            end else begin
                op[i] = op_sign_diff[i] ? ~{3'b000, shifted_mant[i]} : {3'b000, shifted_mant[i]};
            end
        end

        // 5. Compress (Synthesis tools easily rebalance this logic into a tree)
        csa_s[0] = op[0];
        csa_c[0] = 0;
        for (int i = 1; i < NUM_INPUTS; i++) begin
            csa_s[i] = csa_s[i-1] ^ (csa_c[i-1] << 1) ^ op[i];
            csa_c[i] = (csa_s[i-1] & (csa_c[i-1] << 1)) | ((csa_c[i-1] << 1) & op[i]) | (op[i] & csa_s[i-1]);
        end
    end

    // Pipeline Stage 1 Flip-Flops
    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            st1_a_s <= 0; st1_a_e <= 0; st1_align_sticky <= 0;
            st1_special_case <= 0; st1_special_result <= 0;
            st1_sum_vec <= 0; st1_carry_vec <= 0; st1_hot_ones <= 0;
        end else begin
            st1_a_s <= sign_max; 
            st1_a_e <= max_exp; 
            
            st1_align_sticky <= 0;
            for (int i=0; i<NUM_INPUTS; i++) begin
                if (i[IDX_W-1:0] != max_idx) st1_align_sticky <= st1_align_sticky | sticky[i];
            end

            st1_special_case <= special_case; 
            st1_special_result <= special_result;
            st1_sum_vec   <= csa_s[NUM_INPUTS-1];
            st1_carry_vec <= csa_c[NUM_INPUTS-1];
            
            st1_hot_ones <= 0;
            for (int i=0; i<NUM_INPUTS; i++) begin
                if (i[IDX_W-1:0] != max_idx && op_sign_diff[i]) st1_hot_ones <= st1_hot_ones + 1'b1;
            end
        end
    end

    // =================================================================================
    // STAGE 2: Final Add (Critical Path Isolation)
    // =================================================================================
    always_comb begin : stage2_logic
        raw_sum = $signed({1'b0, st1_sum_vec}) + $signed(st1_carry_vec << 1) + $signed({{(SUM_WIDTH){1'b0}}, st1_hot_ones});

        if (raw_sum[SUM_WIDTH]) begin
            mag_sum = SUM_WIDTH'(~raw_sum + 1'b1);
            res_sign = ~st1_a_s;
        end else begin
            mag_sum = SUM_WIDTH'(raw_sum[SUM_WIDTH-1:0]);
            res_sign = st1_a_s;
        end
    end

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

        norm_val = st2_sum_mag << lead_zeros;
        final_mant = norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE];
        
        final_exp_calc = $signed({2'b00, st2_exp_base}) + 2 - $signed({2'b00, lead_zeros}) + BIAS_DIFF;

        if (st2_sum_mag == 0 || final_exp_calc <= 0 || st2_exp_base == 0) result_out = {1'b0, {RES_WIDTH-1{1'b0}}};
        else if (final_exp_calc >= MAX_EXP) result_out = {st2_res_sign, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
        else result_out = {st2_res_sign, final_exp_calc[EXPONENT_SIZE-1:0], final_mant};

        if (st2_special) result_out = st2_spec_res;
    end

    // =================================================================================
    // EXTRA PIPELINE STAGES (For Synthesis Retiming in Genus)
    // =================================================================================
    
    // Genus-compatible retime attribute.
    // Note: To guarantee execution, ensure retiming is enabled in your synthesis TCL script.
    (* retime *) logic [RES_WIDTH-1:0] pipe_regs [EXTRA_STAGES+1];

    always_ff @(posedge clk) begin
        // Leaving these registers un-reset allows the Genus retiming engine to move 
        // them backward/forward across your combinational logic without altering functionality.
        pipe_regs[0] <= result_out; 
        for (int i = 1; i <= EXTRA_STAGES; i++) begin
            pipe_regs[i] <= pipe_regs[i-1];
        end
    end

    assign out_data = pipe_regs[EXTRA_STAGES];

endmodule
