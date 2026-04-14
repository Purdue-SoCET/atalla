#!/usr/bin/env python3
import argparse
import subprocess
import sys
import os
import math

def run_cmd(cmd):
    """Executes sub-scripts and captures output."""
    script_name = os.path.basename(cmd[1])
    print(f"--> Executing: {script_name}")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"FAILED: {script_name}\nError: {result.stderr}")
        sys.exit(1)
    return result.stdout

def generate_top_wrapper(n, adder_module_name, align_lat, tree_pipe_str, out_dir="."):
    # Ensure the output directory exists
    if not os.path.exists(out_dir):
        os.makedirs(out_dir)
        print(f"--> Created directory: {out_dir}")

    top_module_name = f"sysarr_{n}_input_fp_adder_TOP"
    file_path = os.path.join(out_dir, f"{top_module_name}.sv")
    
    # Matching widths
    EXP_W = 8
    MANT_W = 23
    PREC_BITS = 0 
    NEW_MANT_W = MANT_W + PREC_BITS + 1
    GROWTH = math.ceil(math.log2(n))
    SUM_WIDTH = NEW_MANT_W + GROWTH 

    # --- LATENCY CALCULATION ---
    # tree_pipe_str (e.g., "101") represents registers. Number of '1's = latency
    tree_lat = str(tree_pipe_str).count('1')
    
    sv = [
        "`timescale 1ns/1ps",
        f"module {top_module_name} (",
        "    input  logic clk, nRST,",
        f"    input  logic [31:0] in_data [0:{n-1}],",
        "    output logic [31:0] out_data",
        ");",
        "",
        "    // =================================================================================",
        "    // 1. PARAMETERS & LATENCY DEFINITIONS",
        "    // =================================================================================",
        "    localparam MANTISSA_SIZE = 23;",
        "    localparam EXPONENT_SIZE = 8;",
        f"    localparam SUM_WIDTH = {SUM_WIDTH};",
        f"    localparam SYNC_EXC = {align_lat + tree_lat + 2}; // Delay for exceptions",
        f"    localparam SYNC_EXP = {tree_lat + 2};             // Delay for max_exp",
        "",
        "    // =================================================================================",
        "    // STAGE 1: Exception Detection & DAZ (Combinational)",
        "    // =================================================================================",
        "    logic c_is_nan, c_any_inf_p, c_any_inf_n, c_spec_case;",
        "    logic [31:0] c_spec_res;",
        "",
        "    always_comb begin",
        "        c_is_nan = 0; c_any_inf_p = 0; c_any_inf_n = 0;",
        f"        for (int i=0; i<{n}; i++) begin",
        "            logic [7:0] e = in_data[i][30:23];",
        "            logic [22:0] m = in_data[i][22:0];",
        "            if (&e && |m)  c_is_nan = 1;",
        "            if (&e && !|m && !in_data[i][31]) c_any_inf_p = 1;",
        "            if (&e && !|m &&  in_data[i][31]) c_any_inf_n = 1;",
        "        end",
        "        c_spec_case = c_is_nan || (c_any_inf_p && c_any_inf_n);",
        "        if (c_is_nan || (c_any_inf_p && c_any_inf_n)) c_spec_res = 32'h7FC00000; // NaN",
        "        else if (c_any_inf_p) c_spec_res = 32'h7F800000; // +Inf",
        "        else c_spec_res = 32'hFF800000; // -Inf",
        "    end",
        "",
        "    // =================================================================================",
        "    // STAGE A & B: Aligner and Adder Tree",
        "    // =================================================================================",
        "    logic [7:0] w_max_exp;",
        f"    logic w_signs [0:{n-1}];",
        f"    logic [{NEW_MANT_W-1}:0] w_aligned_mants [0:{n-1}];",
        "",
        f"    sysarr_{n}_input_fp_aligner aligner_inst (",
        "        .clk(clk), .nRST(nRST), .in_fp(in_data),",
        "        .out_max_exp(w_max_exp), .sign_out(w_signs), .aligned_mant_out(w_aligned_mants)",
        "    );",
        "",
        f"    logic [SUM_WIDTH:0] w_tree_sum_raw;",
        f"    {adder_module_name} adder_tree_inst (",
        "        .clk(clk), .nRST(nRST), .in(w_aligned_mants), .out_sum(w_tree_sum_raw)",
        "    );",
        "",
        "    // =================================================================================",
        "    // STAGE 3: Magnitude Extraction",
        "    // =================================================================================",
        "    logic [SUM_WIDTH-1:0] abs_sum;",
        "    logic final_sign;",
        "",
        "    always_ff @(posedge clk) begin",
        "        if (w_tree_sum_raw[SUM_WIDTH]) begin", 
        "            abs_sum <= ~w_tree_sum_raw[SUM_WIDTH-1:0] + 1'b1;", 
        "            final_sign <= 1'b1;", 
        "        end else begin", 
        "            abs_sum <= w_tree_sum_raw[SUM_WIDTH-1:0];", 
        "            final_sign <= 1'b0;", 
        "        end",
        "    end",
        "",
        "    // =================================================================================",
        "    // STAGE 4: LZD & Normalization (Pipelined)",
        "    // =================================================================================",
        "    logic [$clog2(SUM_WIDTH)-1:0] c_lzd_count;",
        "    logic [SUM_WIDTH-1:0] c_normalized_sum;",
        "    logic [$clog2(SUM_WIDTH)-1:0] lzd_count;",
        "    logic [SUM_WIDTH-1:0] normalized_sum;",
        "",
        "    always_comb begin",
        "        c_lzd_count = 0;",
        "        c_normalized_sum = abs_sum;",
        "        for (int i = SUM_WIDTH-1; i >= 0; i--) begin",
        "            if (abs_sum[i]) begin",
        "                c_lzd_count = (SUM_WIDTH - 1) - i;",
        "                c_normalized_sum = abs_sum << ((SUM_WIDTH - 1) - i);",
        "                break;",
        "            end",
        "        end",
        "    end",
        "",
        "    always_ff @(posedge clk) begin",
        "        lzd_count <= c_lzd_count;",
        "        normalized_sum <= c_normalized_sum;",
        "    end",
        "",
        "    // =================================================================================",
        "    // PIPELINE DELAY REGISTERS (Dynamic Syncing)",
        "    // =================================================================================",
        "    logic [SYNC_EXC-1:0] spec_case_pipe;",
        "    logic [31:0] spec_res_pipe [0:SYNC_EXC-1];",
        "    logic [7:0] max_exp_pipe [0:SYNC_EXP-1];",
        "    logic final_sign_pipe;",
        "",
        "    always_ff @(posedge clk) begin",
        "        // Delay Exception Logic (From Cycle 0)",
        "        spec_case_pipe <= {spec_case_pipe[SYNC_EXC-2:0], c_spec_case};",
        "        spec_res_pipe[0] <= c_spec_res;",
        "        for (int i=1; i<SYNC_EXC; i++) spec_res_pipe[i] <= spec_res_pipe[i-1];",
        "",
        "        // Delay Max Exponent (From Aligner)",
        "        max_exp_pipe[0] <= w_max_exp;",
        "        for (int i=1; i<SYNC_EXP; i++) max_exp_pipe[i] <= max_exp_pipe[i-1];",
        "",
        "        // Delay Sign (1 cycle, to match LZD Pipeline)",
        "        final_sign_pipe <= final_sign;",
        "    end",
        "",
        "    // =================================================================================",
        "    // STAGE 5: Output Packing",
        "    // =================================================================================",
        "    always_ff @(posedge clk) begin",
        "        if (spec_case_pipe[SYNC_EXC-1]) ",
        "            out_data <= spec_res_pipe[SYNC_EXC-1];",
        "        else ",
        "            out_data <= {final_sign_pipe, (max_exp_pipe[SYNC_EXP-1] - lzd_count), normalized_sum[SUM_WIDTH-2 -: MANTISSA_SIZE]};",
        "    end",
        "",
        "endmodule"
    ]

    with open(file_path, "w") as f:
        f.write("\n".join(sv))
    print(f"--> [SUCCESS] Top-Level Wrapper generated: {file_path}")

if __name__ == "__main__":
    script_dir = os.path.dirname(os.path.abspath(__file__))
    aligner_path = os.path.join(script_dir, "gen_fp_aligner.py")
    adder_path   = os.path.join(script_dir, "gen_adder_tree_path_radix.py")

    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True)
    parser.add_argument("--radices", type=str, default="2,4,8")
    parser.add_argument("--tree-pipe", type=str, default="101")
    parser.add_argument("--align-pipe", type=int, default=1)
    parser.add_argument("--adder-cfg", type=str, default="101")
    args = parser.parse_args()

    run_cmd([sys.executable, aligner_path, "-n", str(args.n), 
             "--tree-pipe", args.tree_pipe, "--align-pipe", str(args.align_pipe)])

    run_cmd([sys.executable, adder_path, "-n", str(args.n), 
             "--radices", args.radices])

    # Note: Using your DSE's generated naming convention
    example_adder_mod = f"V0_0_S2_cfg_{args.adder_cfg}" 
    
    # PASS ALIGN AND TREE CONFIGS TO FUNCTION
    generate_top_wrapper(
        n=args.n, 
        adder_module_name=example_adder_mod, 
        align_lat=args.align_pipe, 
        tree_pipe_str=args.tree_pipe, 
        out_dir="master_wrapper_examples"
    )
