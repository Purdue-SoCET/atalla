module sysarr_32_input_adder #(
    parameter MANTISSA_SIZE     = 23, // Input Mantissa Width
    parameter EXPONENT_SIZE     = 8,
    parameter IN_MANTISSA_SIZE = 7, // Output Mantissa Width (New Parameter)
    parameter IN_EXPONENT_SIZE = 8,
    parameter PRECISION_BITS    = 0,
    parameter GRS = 0
) (
    input logic clk,
    input logic nRST, 
    input logic [IN_MANTISSA_SIZE + IN_EXPONENT_SIZE:0] in [31:0], // 32 inputs, each with a width of IN_MANTISSA_SIZE + IN_EXPONENT_SIZE
    output logic [EXPONENT_SIZE+MANTISSA_SIZE:0] result
);

    localparam NEW_MANT_WIDTH = MANTISSA_SIZE + PRECISION_BITS + 2;
    localparam SUM_WIDTH      = NEW_MANT_WIDTH + 5; 
    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;
    localparam RES_WIDTH      = 1 + EXPONENT_SIZE + MANTISSA_SIZE; // Total width of result
    localparam BIAS_DIFF       = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1); // Bias difference for exponent adjustment
    localparam IN_WIDTH = 1 + IN_EXPONENT_SIZE + IN_MANTISSA_SIZE; // Total width of input
    
    // Special case flags and expansion to output format
    
    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] in_daz [31:0]; // Aligned and expanded inputs for the adder
    
    logic [31:0] is_inf_pos, is_inf_neg, is_nan; // Special case flags for each input
    logic special_case;
    logic [RES_WIDTH-1:0] special_result; 

    assign result = result_out; 
    // =================================================================================
    // STAGE 1: Sort and align inputs
    // =================================================================================

    always_comb begin : daz_and_special

        special_case = 1'b0;
        special_result = {RES_WIDTH{1'b0}};

        for (int i = 0; i < 32; i++) begin
            in_daz[i] = (in[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ? {in[i][IN_EXPONENT_SIZE+IN_MANTISSA_SIZE], {(MANTISSA_SIZE + EXPONENT_SIZE){1'b0}}} : {in[i], {(MANTISSA_SIZE - IN_MANTISSA_SIZE){1'b0}}}; // Denormalize if exponent is zero, else keep as is

            // Correct Special Case Logic
            is_inf_pos[i] = (in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE] == {EXPONENT_SIZE{1'b1}}) & (in_daz[i][MANTISSA_SIZE-1:0] == 0) & (~in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]);

            is_inf_neg[i] = (in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE] == {EXPONENT_SIZE{1'b1}}) & (in_daz[i][MANTISSA_SIZE-1:0] == 0) & (in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]);

            is_nan[i] = (in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE] == {EXPONENT_SIZE{1'b1}}) & (in_daz[i][MANTISSA_SIZE-1:0] != 0);
        end 
        
        if (|is_nan || (|is_inf_neg && |is_inf_pos)) begin
            special_case = 1'b1;
            special_result = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; // Positive infinity
        end else if (|is_inf_pos) begin
            special_case = 1'b1;
            special_result = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // Positive infinity
        end else if (|is_inf_neg) begin
            special_case = 1'b1;
            special_result = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // Negative infinity
        end

    end

    // Stage 2 - Align mantissas and exponents to a common format for addition

    logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:31];
    logic [EXPONENT_SIZE-1:0] max_exp;
    logic [1:0] overall_sticky; 

    sysarr_32_input_fp_aligner #(
        .EXPONENT_SIZE(EXPONENT_SIZE),
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .NEW_MANT_WIDTH(NEW_MANT_WIDTH)
    ) align (
        .clk(clk),
        .nRST(nRST),
        .in_fp(in_daz),
        .out_max_exp(max_exp),
        .out_sticky(overall_sticky),
        .aligned_mant_out(aligned_mant_out)
    );

    // Stage 3 - Addition of aligned mantissas

    logic [SUM_WIDTH-1:0] out_sum, mag_sum; 
    logic res_sign; 

    add32_tree_2_2_2_2_2_pipe_0000_lat1_var0_0 #(
        .WIDTH(NEW_MANT_WIDTH)
    ) adder (
        .clk(clk),
        .nRST(nRST),
        .in(aligned_mant_out),
        .out_sum(out_sum)
    );  


    logic final_sticky_bit;

    always_comb begin: magnitude_and_sign
        final_sticky_bit = overall_sticky[0];

        if (out_sum[SUM_WIDTH-1]) begin
            res_sign = 1'b1;
            
            if (overall_sticky[0] && (overall_sticky[1] == 1'b0)) begin
                mag_sum = ~out_sum;
            end else begin
                mag_sum = ~out_sum + 1'b1;
            end

        end else if (out_sum == '0) begin
            
            if (overall_sticky[0] && (overall_sticky[1] == 1'b1)) begin
                res_sign = 1'b1;
                mag_sum  = '0; 
            end else begin
                res_sign = 1'b0;
                mag_sum  = '0;
            end

        end else begin
            res_sign = 1'b0;
            
            if (overall_sticky[0] && (overall_sticky[1] == 1'b1)) begin
                mag_sum = out_sum - 1'b1;
            end else begin
                mag_sum = out_sum;
            end
        end
    end

    logic [SUM_WIDTH-1:0] lzd_scan, norm_val;
    logic [$clog2(SUM_WIDTH)-1:0] lead_zeros;

    logic         guard_bit;
    logic         round_bit;
    logic         sticky_bit;
    logic         l_bit;
    logic         round_up;
    
    // Width is MANTISSA_SIZE + 1 to account for the rounding carry-out
    logic [MANTISSA_SIZE:0] rounded_mant_int; 
    
    // Final mantissa for packing
    logic [MANTISSA_SIZE-1:0] final_mant;

    // --- Exponent and Final Output Signals ---
    // Signed to safely handle potential underflow/overflow before clamping
    logic signed [EXPONENT_SIZE+1:0] final_exp_calc; 
    
    // The internal register that holds the final packed result
    logic [RES_WIDTH-1:0] result_out;

    always_comb begin: leading_zero_detector_and_final
        if (~|mag_sum) begin
            lzd_scan = 0; 
            lead_zeros = SUM_WIDTH - 1; 
        end else begin
            lzd_scan = mag_sum; 
            lead_zeros = 0;
            for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin
                if ((lzd_scan >> (SUM_WIDTH - (1 << i))) == 0) begin
                    lead_zeros = lead_zeros + (1 << i);
                    lzd_scan = lzd_scan << (1 << i);
                end
            end
        end

        norm_val = mag_sum << lead_zeros;

        if (GRS == 1 && (MANTISSA_SIZE > (IN_MANTISSA_SIZE + 3)) || PRECISION_BITS >= 3) begin
            // Generate GRS bits and modify rounding logic accordingly (not implemented in this snippet for brevity)
            guard_bit = norm_val[SUM_WIDTH-2-MANTISSA_SIZE];
            round_bit = norm_val[SUM_WIDTH-3-MANTISSA_SIZE];
            // sticky_bit = (|norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]);
            l_bit = norm_val[SUM_WIDTH-1-MANTISSA_SIZE];

            if (lead_zeros >= PRECISION_BITS) begin
                norm_val[lead_zeros] = 1'b0;
                sticky_bit = |norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0];
            end
            else begin
                sticky_bit = (|norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]) | overall_sticky;
            end

            round_up = guard_bit & (round_bit | sticky_bit | l_bit); // Round to even on tie

            rounded_mant_int = norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE] + round_up;
        end else begin
            // Standard rounding logic without GRS bits (already integrated into the existing logic)
            guard_bit = 0; round_bit = 0; sticky_bit = overall_sticky[0]; l_bit = 0; round_up = 0;
            rounded_mant_int = {1'b0, norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE]};  
        end
        
        // Handle overflow (e.g., 1.111 -> 10.000)
        // sticky_bit = (|norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]) | st2_sticky;
        lead_zeros = $signed({1'b0, lead_zeros}) - (rounded_mant_int[MANTISSA_SIZE] ? 1 : 0); // If we had a carry out, we effectively have one less leading zero
        final_mant = rounded_mant_int[MANTISSA_SIZE-1:0];

        // Exponent Adjustment
        final_exp_calc = $signed({1'b0, max_exp}) + $signed({1'b0, BIAS_DIFF}) + 6 - $signed({1'b0, lead_zeros});
        
        // 4. Output Packing
        if (special_case) result_out = special_result;
        else begin
            if (mag_sum == 0 || final_exp_calc <= 0 || max_exp == 0) result_out = {1'b0, {RES_WIDTH-1{1'b0}}};
            else if (final_exp_calc >= MAX_EXP) result_out = {res_sign, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; 
            else result_out = {res_sign, final_exp_calc[EXPONENT_SIZE-1:0], final_mant};
        end
    end


endmodule