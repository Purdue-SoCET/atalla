`timescale 1ns/1ps
// =================================================================================
// MODULE: sysarr_4_TOP_path_2_2_addCfg_0_alignTree_00_alignReg_0
// DESCRIPTION: Top-level parameterized wrapper for the Systolic Array FP Adder
// 
// CONFIGURATION:
// - Number of Inputs: 4
// - Adder Tree Path: 2_2 (Radices used at each reduction stage)
// - Adder Tree Pipeline Config: 0
// - Aligner Max-Tree Pipeline Config: 00
// - Aligner Output Pipeline: No (0 cycles)
// 
// LATENCY BREAKDOWN:
// - FP Aligner: 0 cycles
// - Adder Tree: 0 cycles
// - Magnitude Extraction: 1 cycle
// - LZD & Normalization: 1 cycle
// - Output Packing: 1 cycle
// ---------------------------------------------------------
// TOTAL PIPELINE LATENCY: 3 clock cycles
// =================================================================================
module sysarr_4_TOP_path_2_2_addCfg_0_alignTree_00_alignReg_0 #(
    parameter MANTISSA_SIZE    = 23, // Internal Mantissa Width
    parameter EXPONENT_SIZE    = 8,  // Internal Exponent Width
    parameter IN_MANTISSA_SIZE = 7,  // Input/Output Mantissa Width
    parameter IN_EXPONENT_SIZE = 8,  // Input/Output Exponent Width
    parameter PRECISION_BITS   = 0,
    parameter GRS              = 0
) (
    input  logic clk, nRST,
    input  logic [IN_MANTISSA_SIZE + IN_EXPONENT_SIZE:0] in [0:3],
    output logic [EXPONENT_SIZE + MANTISSA_SIZE:0] result
);

    // =================================================================================
    // 1. PARAMETERS & PIPELINE SYNC DEFINITIONS
    // =================================================================================
    localparam NEW_MANT_WIDTH = MANTISSA_SIZE + PRECISION_BITS + 2;
    localparam GROWTH         = 2;
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + GROWTH;
    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1);
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;

    localparam SYNC_EXC = 2; // Delay for exceptions (Aligner + Adder + LZD)
    localparam SYNC_EXP = 2; // Delay for max_exp (Adder + LZD)

    // =================================================================================
    // 2. STRICT TOP-DOWN LOGIC DECLARATIONS
    // =================================================================================
    // Stage 1
    logic c_is_nan, c_any_inf_p, c_any_inf_n, c_spec_case;
    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] c_spec_res;
    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] in_daz [0:3];

    // Stage A & B
    logic [EXPONENT_SIZE-1:0] w_max_exp;
    logic [1:0] w_overall_sticky;
    logic w_signs [0:3];
    logic [NEW_MANT_WIDTH-1:0] w_aligned_mants [0:3];
    logic [SUM_WIDTH-1:0] w_tree_sum_raw;

    // Pipeline Delays
    logic [SYNC_EXC-1:0] spec_case_pipe;
    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] spec_res_pipe [0:SYNC_EXC-1];
    logic [EXPONENT_SIZE-1:0] max_exp_pipe [0:SYNC_EXP-1];
    logic [1:0] sticky_pipe [0:SYNC_EXP-1];
    logic final_sign_pipe;
    logic [1:0] aligned_sticky_for_mag;

    // Stage 3
    logic [SUM_WIDTH-1:0] abs_sum;
    logic final_sign;

    // Stage 4
    logic [$clog2(SUM_WIDTH)-1:0] c_lzd_count;
    logic [SUM_WIDTH-1:0] c_normalized_sum;
    logic [$clog2(SUM_WIDTH)-1:0] lzd_count;
    logic [SUM_WIDTH-1:0] normalized_sum;
    logic [SUM_WIDTH-1:0] lzd_scan;

    // Stage 5
    logic         guard_bit;
    logic         round_bit;
    logic         sticky_bit;
    logic         l_bit;
    logic         round_up;
    logic [MANTISSA_SIZE:0] rounded_mant_int;
    logic [MANTISSA_SIZE-1:0] final_mant;
    logic signed [EXPONENT_SIZE+1:0] final_exp_calc;
    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] final_out_data;
    logic signed [$clog2(SUM_WIDTH)+1:0] adjusted_lead_zeros;
    logic [SUM_WIDTH-1:0] temp_norm_val;

    // =================================================================================
    // 3. LOGIC IMPLEMENTATION
    // =================================================================================
    // STAGE 1: Exception Detection & DAZ (Combinational)
    always_comb begin
        c_is_nan = 0; c_any_inf_p = 0; c_any_inf_n = 0;
        for (int i=0; i<4; i++) begin
            in_daz[i] = (in[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ?
                        {in[i][IN_EXPONENT_SIZE+IN_MANTISSA_SIZE], {(MANTISSA_SIZE + EXPONENT_SIZE){1'b0}}} :
                        {in[i], {(MANTISSA_SIZE - IN_MANTISSA_SIZE){1'b0}}};

            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && (|in_daz[i][MANTISSA_SIZE-1:0])) c_is_nan = 1;
            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && !(|in_daz[i][MANTISSA_SIZE-1:0]) && !in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]) c_any_inf_p = 1;
            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && !(|in_daz[i][MANTISSA_SIZE-1:0]) &&  in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]) c_any_inf_n = 1;
        end
        c_spec_case = c_is_nan || c_any_inf_p || c_any_inf_n;
        if (c_is_nan || (c_any_inf_p && c_any_inf_n)) c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; // NaN
        else if (c_any_inf_p) c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // +Inf
        else c_spec_res = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // -Inf
    end

    // STAGE A & B: Aligner and Adder Tree
    sysarr_4_aligner_tree_00_reg_0 #(
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .NEW_MANT_WIDTH(NEW_MANT_WIDTH)
    ) aligner_inst (
        .clk(clk), .nRST(nRST), .in_fp(in_daz),
        .out_max_exp(w_max_exp), .out_sticky(w_overall_sticky), .sign_out(w_signs), .aligned_mant_out(w_aligned_mants)
    );

    add4_tree_2_2_pipe_0_lat1_var0_0 #(
        .WIDTH(NEW_MANT_WIDTH)
    ) adder_tree_inst (
        .clk(clk), .nRST(nRST), .in(w_aligned_mants), .out_sum(w_tree_sum_raw)
    );

    assign aligned_sticky_for_mag = w_overall_sticky;
    // STAGE 3: Magnitude Extraction
    always_ff @(posedge clk) begin
        if (w_tree_sum_raw[SUM_WIDTH-1]) begin
            final_sign <= 1'b1;
            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b0)) begin
                abs_sum <= ~w_tree_sum_raw;
            end else begin
                abs_sum <= ~w_tree_sum_raw + 1'b1;
            end
        end else if (w_tree_sum_raw == '0) begin
            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b1)) begin
                final_sign <= 1'b1;
                abs_sum  <= '0;
            end else begin
                final_sign <= 1'b0;
                abs_sum  <= '0;
            end
        end else begin
            final_sign <= 1'b0;
            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b1)) begin
                abs_sum <= w_tree_sum_raw - 1'b1;
            end else begin
                abs_sum <= w_tree_sum_raw;
            end
        end
    end

    // STAGE 4: LZD & Normalization (Pipelined)
    always_comb begin
        if (~|abs_sum) begin
            lzd_scan = 0;
            c_lzd_count = SUM_WIDTH - 1;
        end else begin
            lzd_scan = abs_sum;
            c_lzd_count = 0;
            for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
                if ((lzd_scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                    c_lzd_count = c_lzd_count + (1 << i);
                    lzd_scan = lzd_scan << (1 << i);
                end
            end
        end
        c_normalized_sum = abs_sum << c_lzd_count;
    end

    always_ff @(posedge clk) begin
        lzd_count <= c_lzd_count;
        normalized_sum <= c_normalized_sum;
    end

    // PIPELINE DELAY REGISTERS (Dynamic Syncing)
    always_ff @(posedge clk) begin
        spec_case_pipe <= {spec_case_pipe[SYNC_EXC-2:0], c_spec_case};
        spec_res_pipe[0] <= c_spec_res;
        for (int i=1; i<SYNC_EXC; i++) spec_res_pipe[i] <= spec_res_pipe[i-1];

        max_exp_pipe[0] <= w_max_exp;
        sticky_pipe[0]  <= w_overall_sticky;
        for (int i=1; i<SYNC_EXP; i++) begin
            max_exp_pipe[i] <= max_exp_pipe[i-1];
            sticky_pipe[i]  <= sticky_pipe[i-1];
        end

        final_sign_pipe <= final_sign;
    end

    // STAGE 5: Exponent Calculation & Output Packing
    always_comb begin
        temp_norm_val = normalized_sum;

        if (GRS == 1 && (MANTISSA_SIZE > (IN_MANTISSA_SIZE + 3)) || PRECISION_BITS >= 3) begin
            guard_bit = temp_norm_val[SUM_WIDTH-2-MANTISSA_SIZE];
            round_bit = temp_norm_val[SUM_WIDTH-3-MANTISSA_SIZE];
            l_bit     = temp_norm_val[SUM_WIDTH-1-MANTISSA_SIZE];
            
            if (lzd_count >= PRECISION_BITS) begin
                temp_norm_val[lzd_count] = 1'b0;
                sticky_bit = |temp_norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0];
            end else begin
                sticky_bit = (|temp_norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]) | sticky_pipe[SYNC_EXP-1][0];
            end
            
            round_up = guard_bit & (round_bit | sticky_bit | l_bit);
            rounded_mant_int = temp_norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE] + round_up;
        end else begin
            guard_bit = 0; round_bit = 0; sticky_bit = sticky_pipe[SYNC_EXP-1][0]; l_bit = 0; round_up = 0;
            rounded_mant_int = {1'b0, temp_norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE]};
        end

        adjusted_lead_zeros = $signed({1'b0, lzd_count}) - (rounded_mant_int[MANTISSA_SIZE] ? 1 : 0);
        final_mant = rounded_mant_int[MANTISSA_SIZE-1:0];

        final_exp_calc = $signed({1'b0, max_exp_pipe[SYNC_EXP-1]}) + $signed({1'b0, BIAS_DIFF}) + GROWTH + 1 - adjusted_lead_zeros;
        
        if (~|normalized_sum || final_exp_calc <= 0 || max_exp_pipe[SYNC_EXP-1] == 0) begin
            final_out_data = '0;
        end else if (final_exp_calc >= MAX_EXP) begin
            final_out_data = {final_sign_pipe, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}};
        end else begin
            final_out_data = {final_sign_pipe, final_exp_calc[EXPONENT_SIZE-1:0], final_mant};
        end
    end

    always_ff @(posedge clk) begin
        if (spec_case_pipe[SYNC_EXC-1]) 
            result <= spec_res_pipe[SYNC_EXC-1];
        else 
            result <= final_out_data;
    end

endmodule