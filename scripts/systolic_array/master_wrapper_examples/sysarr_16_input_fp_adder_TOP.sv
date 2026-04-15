`timescale 1ns/1ps
module sysarr_16_input_fp_adder_TOP (
    input  logic clk, nRST,
    input  logic [31:0] in_data [0:15],
    output logic [31:0] out_data
);

    // --- STAGE 1: Exception Detection & DAZ (Wrapper Logic) ---
    logic c_is_nan, c_any_inf_p, c_any_inf_n, c_spec_case;
    logic [31:0] c_spec_res;

    always_comb begin
        c_is_nan = 0; c_any_inf_p = 0; c_any_inf_n = 0;
        for (int i=0; i<16; i++) begin
            logic [7:0] e = in_data[i][30:23];
            logic [22:0] m = in_data[i][22:0];
            if (&e && |m)  c_is_nan = 1;
            if (&e && !|m && !in_data[i][31]) c_any_inf_p = 1;
            if (&e && !|m &&  in_data[i][31]) c_any_inf_n = 1;
        end
        c_spec_case = c_is_nan || (c_any_inf_p && c_any_inf_n);
        if (c_is_nan || (c_any_inf_p && c_any_inf_n)) c_spec_res = 32'h7FC00000; // NaN
        else if (c_any_inf_p) c_spec_res = 32'h7F800000; // +Inf
        else c_spec_res = 32'hFF800000; // -Inf
    end

    // --- STAGE A: Aligner (Instantiated from gen_fp_aligner.py) ---
    logic [7:0] w_max_exp;
    logic w_signs [0:15];
    logic [23:0] w_aligned_mants [0:15];

    sysarr_16_input_fp_aligner aligner_inst (
        .clk(clk), .nRST(nRST), .in_fp(in_data),
        .out_max_exp(w_max_exp), .sign_out(w_signs), .aligned_mant_out(w_aligned_mants)
    );

    // --- STAGE B: Adder Tree (Instantiated from DSE Results) ---
    logic [28:0] w_tree_sum_raw;
    V0_0_S2_cfg_101 adder_tree_inst (
        .clk(clk), .nRST(nRST), .in(w_aligned_mants), .out_sum(w_tree_sum_raw)
    );

    // --- STAGE 3: Normalization & LZD (Wrapper Logic) ---
    logic [28-1:0] abs_sum;
    logic final_sign;
    integer lzd_count;

    always_ff @(posedge clk) begin
        // Simple Magnitude Extraction
        if (w_tree_sum_raw[28]) begin abs_sum <= ~w_tree_sum_raw + 1; final_sign <= 1; end
        else begin abs_sum <= w_tree_sum_raw; final_sign <= 0; end
    end

    // LZD & Normalization Placeholder
    always_comb begin
        lzd_count = 0;
        for (int i=27; i>=0; i--) begin
            if (abs_sum[i]) begin lzd_count = {SUM_WIDTH-1} - i; break; end
        end
    end

    always_ff @(posedge clk) begin
        if (c_spec_case) out_data <= c_spec_res;
        else out_data <= {final_sign, w_max_exp, abs_sum[22:0]}; // Basic pack
    end

endmodule