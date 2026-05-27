#!/usr/bin/env python3

# Generates self-contained top level wrapper modules for design exploration of a n-input fused adder

# Usage:   
#   1) To generate a single wrapper for a specific adder tree configuration:
#       python master_wrapper_gen.py -n 16 --adder-path 4_4_2 --adder-cfg 10 --tree-pipe 101 --align-pipe 1
#   2) To generate wrappers for ALL DSE configurations with a variety of aligner pipeline options:
#       python master_wrapper_gen.py -n 16 --wrap-all

# Options: 
#   -n: Number of inputs to the adder
#   --radices: Allowed radix shapes for the DSE (default: 2,4,8,15)
#   --tree-pipe: Aligner Max Tree pipeline config (e.g. 101)
#   --align-pipe: Aligner output register (1=yes, 0=no)
#   --adder-path: Specific reduction path to wrap (e.g., 4_4_2)
#   --adder-cfg: Pipeline config for the adder path (e.g., 10)


import argparse
import subprocess
import sys
import os
import math
import csv
import shutil
import glob
from itertools import product

def run_cmd(cmd):
    script_name = os.path.basename(cmd[1])
    print(f"--> Executing: {script_name} {' '.join(cmd[2:])}")
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"FAILED: {script_name}\nError: {result.stderr}")
        sys.exit(1)
    return result.stdout

def generate_top_wrapper(n, adder_module_name, adder_src_path, aligner_src_path, align_pipe, align_tree_pipe_str, adder_path, adder_cfg_str, out_dir="."):
    top_module_name_dir = f"sysarr_{n}_TOP_path_{adder_path}_addCfg_{adder_cfg_str}_alignTree_{align_tree_pipe_str}_alignReg_{align_pipe}"
    top_module_name = f"sysarr_{n}_input_fp_adder"
    wrapper_dir = os.path.join(out_dir, top_module_name_dir)
    os.makedirs(wrapper_dir, exist_ok=True)

    file_path = os.path.join(wrapper_dir, f"{top_module_name}.sv")
    aligner_module_name = f"sysarr_{n}_aligner_tree"

    GROWTH = math.ceil(math.log2(n))
    align_tree_lat = str(align_tree_pipe_str).count('1')
    align_lat = align_pipe + align_tree_lat
    adder_lat = str(adder_cfg_str).count('1')
    
    total_latency = align_lat + adder_lat + 3
    SYNC_EXP = adder_lat + 2
    SYNC_EXC = align_lat + adder_lat + 2 
    
    sv = [
        "`timescale 1ns/1ps",
        "// =================================================================================",
        f"// MODULE: {top_module_name}",
        "// DESCRIPTION: Top-level parameterized wrapper for the Systolic Array FP Adder",
        "// ",
        "// CONFIGURATION:",
        f"// - Number of Inputs: {n}",
        f"// - Adder Tree Path: {adder_path} (Radices used at each reduction stage)",
        f"// - Adder Tree Pipeline Config: {adder_cfg_str}",
        f"// - Aligner Max-Tree Pipeline Config: {align_tree_pipe_str}",
        f"// - Aligner Output Pipeline: {'Yes (1 cycle)' if align_pipe else 'No (0 cycles)'}",
        "// ",
        "// LATENCY BREAKDOWN:",
        f"// - FP Aligner: {align_lat} cycles",
        f"// - Adder Tree: {adder_lat} cycles",
        "// - Magnitude Extraction: 1 cycle",
        "// - LZD & Normalization: 1 cycle",
        "// - Output Packing: 1 cycle",
        "// ---------------------------------------------------------",
        f"// TOTAL PIPELINE LATENCY: {total_latency} clock cycles",
        "// =================================================================================",
        f"module {top_module_name} #(",
        "    parameter MANTISSA_SIZE    = 23, // Internal Mantissa Width",
        "    parameter EXPONENT_SIZE    = 8,  // Internal Exponent Width",
        "    parameter IN_MANTISSA_SIZE = 7,  // Input/Output Mantissa Width",
        "    parameter IN_EXPONENT_SIZE = 8,  // Input/Output Exponent Width",
        "    parameter PRECISION_BITS   = 3,",
        "    parameter GRS              = 1",
        ") (",
        "    input  logic clk, nRST,",
        f"    input  logic [IN_MANTISSA_SIZE + IN_EXPONENT_SIZE:0] in [0:{n-1}],",
        "    output logic [EXPONENT_SIZE + MANTISSA_SIZE:0] result",
        ");",
        "",
        "    // =================================================================================",
        "    // 1. PARAMETERS & PIPELINE SYNC DEFINITIONS",
        "    // =================================================================================",
        "    localparam NEW_MANT_WIDTH = MANTISSA_SIZE + PRECISION_BITS + 2;",
        f"    localparam GROWTH         = {GROWTH};",
        "    localparam SUM_WIDTH      = NEW_MANT_WIDTH + GROWTH;",
        "    localparam BIAS_DIFF      = (1 << (EXPONENT_SIZE - 1)) - 1 - ((1 << (IN_EXPONENT_SIZE - 1)) - 1);",
        "    localparam MAX_EXP        = (1 << EXPONENT_SIZE) - 1;",
        "",
        f"    localparam SYNC_EXC = {SYNC_EXC}; // Delay for exceptions (Aligner + Adder + LZD)",
        f"    localparam SYNC_EXP = {SYNC_EXP}; // Delay for max_exp (Adder + LZD)",
        "",
        "    // =================================================================================",
        "    // 2. STRICT TOP-DOWN LOGIC DECLARATIONS",
        "    // =================================================================================",
        "    // Stage 1",
        "    logic c_is_nan, c_any_inf_p, c_any_inf_n, c_spec_case;",
        "    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] c_spec_res;",
        f"    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] in_daz [0:{n-1}];",
        "",
        "    // Stage A & B",
        "    logic [EXPONENT_SIZE-1:0] w_max_exp;",
        "    logic [1:0] w_overall_sticky;",
        f"    logic w_signs [0:{n-1}];",
        f"    logic [NEW_MANT_WIDTH-1:0] w_aligned_mants [0:{n-1}];",
        "    logic [SUM_WIDTH-1:0] w_tree_sum_raw;",
        "",
        "    // Pipeline Delays",
        "    logic [SYNC_EXC-1:0] spec_case_pipe;",
        "    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] spec_res_pipe [0:SYNC_EXC-1];",
        "    logic [EXPONENT_SIZE-1:0] max_exp_pipe [0:SYNC_EXP-1];",
        "    logic [1:0] sticky_pipe [0:SYNC_EXP-1];",
        "    logic final_sign_pipe;",
        "    logic [1:0] aligned_sticky_for_mag;",
        "",
        "    // Stage 3",
        "    logic [SUM_WIDTH-1:0] abs_sum;",
        "    logic final_sign;",
        "",
        "    // Stage 4",
        "    logic [$clog2(SUM_WIDTH)-1:0] c_lzd_count;",
        "    logic [SUM_WIDTH-1:0] c_normalized_sum;",
        "    logic [$clog2(SUM_WIDTH)-1:0] lzd_count;",
        "    logic [SUM_WIDTH-1:0] normalized_sum;",
        "    logic [SUM_WIDTH-1:0] lzd_scan;",
        "",
        "    // Stage 5",
        "    logic         guard_bit;",
        "    logic         round_bit;",
        "    logic         sticky_bit;",
        "    logic         l_bit;",
        "    logic         round_up;",
        "    logic [MANTISSA_SIZE:0] rounded_mant_int;",
        "    logic [MANTISSA_SIZE-1:0] final_mant;",
        "    logic signed [EXPONENT_SIZE+1:0] final_exp_calc;",
        "    logic [EXPONENT_SIZE + MANTISSA_SIZE:0] final_out_data;",
        "    logic signed [$clog2(SUM_WIDTH)+1:0] adjusted_lead_zeros;",
        "    logic [SUM_WIDTH-1:0] temp_norm_val;",
        "",
        "    // =================================================================================",
        "    // 3. LOGIC IMPLEMENTATION",
        "    // =================================================================================",
        "    // STAGE 1: Exception Detection & DAZ (Combinational)",
        "    always_comb begin",
        "        c_is_nan = 0; c_any_inf_p = 0; c_any_inf_n = 0;",
        f"        for (int i=0; i<{n}; i++) begin",
        "            in_daz[i] = (in[i][IN_MANTISSA_SIZE +: IN_EXPONENT_SIZE] == 0) ?",
        "                        {in[i][IN_EXPONENT_SIZE+IN_MANTISSA_SIZE], {(MANTISSA_SIZE + EXPONENT_SIZE){1'b0}}} :",
        "                        {in[i], {(MANTISSA_SIZE - IN_MANTISSA_SIZE){1'b0}}};",
        "",
        "            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && (|in_daz[i][MANTISSA_SIZE-1:0])) c_is_nan = 1;",
        "            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && !(|in_daz[i][MANTISSA_SIZE-1:0]) && !in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]) c_any_inf_p = 1;",
        "            if ((&in_daz[i][MANTISSA_SIZE +: EXPONENT_SIZE]) && !(|in_daz[i][MANTISSA_SIZE-1:0]) &&  in_daz[i][EXPONENT_SIZE+MANTISSA_SIZE]) c_any_inf_n = 1;",
        "        end",
        "        c_spec_case = c_is_nan || c_any_inf_p || c_any_inf_n;",
        "        if (c_is_nan || (c_any_inf_p && c_any_inf_n)) c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, 1'b1, {(MANTISSA_SIZE-1){1'b0}}}; // NaN",
        "        else if (c_any_inf_p) c_spec_res = {1'b0, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // +Inf",
        "        else c_spec_res = {1'b1, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}}; // -Inf",
        "    end",
        "",
        "    // STAGE A & B: Aligner and Adder Tree",
        f"    {aligner_module_name} #(",
        "        .EXPONENT_SIZE(EXPONENT_SIZE),",
        "        .MANTISSA_SIZE(MANTISSA_SIZE),",
        "        .NEW_MANT_WIDTH(NEW_MANT_WIDTH)",
        "    ) aligner_inst (",
        "        .clk(clk), .nRST(nRST), .in_fp(in_daz),",
        "        .out_max_exp(w_max_exp), .out_sticky(w_overall_sticky), .sign_out(w_signs), .aligned_mant_out(w_aligned_mants)",
        "    );",
        "",
        f"    add{args.n}_tree #(",
        "        .WIDTH(NEW_MANT_WIDTH)",
        "    ) adder_tree_inst (",
        "        .clk(clk), .nRST(nRST), .in(w_aligned_mants), .out_sum(w_tree_sum_raw)",
        "    );",
        ""
    ]
    
    if adder_lat == 0:
        sv.append("    assign aligned_sticky_for_mag = w_overall_sticky;")
    else:
        sv.append(f"    assign aligned_sticky_for_mag = sticky_pipe[{adder_lat - 1}];")

    sv.append("    // STAGE 3: Magnitude Extraction")
    sv.append("    always_ff @(posedge clk) begin")
    sv.append("        if (w_tree_sum_raw[SUM_WIDTH-1]) begin")
    sv.append("            final_sign <= 1'b1;")
    sv.append("            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b0)) begin")
    sv.append("                abs_sum <= ~w_tree_sum_raw;")
    sv.append("            end else begin")
    sv.append("                abs_sum <= ~w_tree_sum_raw + 1'b1;")
    sv.append("            end")
    sv.append("        end else if (w_tree_sum_raw == '0) begin")
    sv.append("            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b1)) begin")
    sv.append("                final_sign <= 1'b1;")
    sv.append("                abs_sum  <= '0;")
    sv.append("            end else begin")
    sv.append("                final_sign <= 1'b0;")
    sv.append("                abs_sum  <= '0;")
    sv.append("            end")
    sv.append("        end else begin")
    sv.append("            final_sign <= 1'b0;")
    sv.append("            if (aligned_sticky_for_mag[0] && (aligned_sticky_for_mag[1] == 1'b1)) begin")
    sv.append("                abs_sum <= w_tree_sum_raw - 1'b1;")
    sv.append("            end else begin")
    sv.append("                abs_sum <= w_tree_sum_raw;")
    sv.append("            end")
    sv.append("        end")
    sv.append("    end")
    sv.append("")
    sv.append("    // STAGE 4: LZD & Normalization (Pipelined)")
    sv.append("    always_comb begin")
    sv.append("        if (~|abs_sum) begin")
    sv.append("            lzd_scan = 0;")
    sv.append("            c_lzd_count = SUM_WIDTH - 1;")
    sv.append("        end else begin")
    sv.append("            lzd_scan = abs_sum;")
    sv.append("            c_lzd_count = 0;")
    sv.append("            for (int i = $clog2(SUM_WIDTH)-1; i >= 0; i--) begin")
    sv.append("                if ((lzd_scan >> (SUM_WIDTH - (1 << i))) == 0) begin")
    sv.append("                    c_lzd_count = c_lzd_count + (1 << i);")
    sv.append("                    lzd_scan = lzd_scan << (1 << i);")
    sv.append("                end")
    sv.append("            end")
    sv.append("        end")
    sv.append("        c_normalized_sum = abs_sum << c_lzd_count;")
    sv.append("    end")
    sv.append("")
    sv.append("    always_ff @(posedge clk) begin")
    sv.append("        lzd_count <= c_lzd_count;")
    sv.append("        normalized_sum <= c_normalized_sum;")
    sv.append("    end")
    sv.append("")
    sv.append("    // PIPELINE DELAY REGISTERS (Dynamic Syncing)")
    sv.append("    always_ff @(posedge clk) begin")
    sv.append("        spec_case_pipe <= {spec_case_pipe[SYNC_EXC-2:0], c_spec_case};")
    sv.append("        spec_res_pipe[0] <= c_spec_res;")
    sv.append("        for (int i=1; i<SYNC_EXC; i++) spec_res_pipe[i] <= spec_res_pipe[i-1];")
    sv.append("")
    sv.append("        max_exp_pipe[0] <= w_max_exp;")
    sv.append("        sticky_pipe[0]  <= w_overall_sticky;")
    sv.append("        for (int i=1; i<SYNC_EXP; i++) begin")
    sv.append("            max_exp_pipe[i] <= max_exp_pipe[i-1];")
    sv.append("            sticky_pipe[i]  <= sticky_pipe[i-1];")
    sv.append("        end")
    sv.append("")
    sv.append("        final_sign_pipe <= final_sign;")
    sv.append("    end")
    sv.append("")
    sv.append("    // STAGE 5: Exponent Calculation & Output Packing")
    sv.append("    always_comb begin")
    sv.append("        temp_norm_val = normalized_sum;")
    sv.append("")
    sv.append("        if (GRS == 1 && (MANTISSA_SIZE > (IN_MANTISSA_SIZE + 3)) || PRECISION_BITS >= 3) begin")
    sv.append("            guard_bit = temp_norm_val[SUM_WIDTH-2-MANTISSA_SIZE];")
    sv.append("            round_bit = temp_norm_val[SUM_WIDTH-3-MANTISSA_SIZE];")
    sv.append("            l_bit     = temp_norm_val[SUM_WIDTH-1-MANTISSA_SIZE];")
    sv.append("            ")
    sv.append("            if (lzd_count >= PRECISION_BITS) begin")
    sv.append("                temp_norm_val[lzd_count] = 1'b0;")
    sv.append("                sticky_bit = |temp_norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0];")
    sv.append("            end else begin")
    sv.append("                sticky_bit = (|temp_norm_val[SUM_WIDTH-4-MANTISSA_SIZE : 0]) | sticky_pipe[SYNC_EXP-1][0];")
    sv.append("            end")
    sv.append("            ")
    sv.append("            round_up = guard_bit & (round_bit | sticky_bit | l_bit);")
    sv.append("            rounded_mant_int = temp_norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE] + round_up;")
    sv.append("        end else begin")
    sv.append("            guard_bit = 0; round_bit = 0; sticky_bit = sticky_pipe[SYNC_EXP-1][0]; l_bit = 0; round_up = 0;")
    sv.append("            rounded_mant_int = {1'b0, temp_norm_val[SUM_WIDTH-2 -: MANTISSA_SIZE]};")
    sv.append("        end")
    sv.append("")
    sv.append("        adjusted_lead_zeros = $signed({1'b0, lzd_count}) - (rounded_mant_int[MANTISSA_SIZE] ? 1 : 0);")
    sv.append("        final_mant = rounded_mant_int[MANTISSA_SIZE-1:0];")
    sv.append("")
    sv.append("        final_exp_calc = $signed({1'b0, max_exp_pipe[SYNC_EXP-1]}) + $signed({1'b0, BIAS_DIFF}) + GROWTH + 1 - adjusted_lead_zeros;")
    sv.append("        ")
    sv.append("        if (~|normalized_sum || max_exp_pipe[SYNC_EXP-1] == 0) begin")
    sv.append("            final_out_data = '0;")
    sv.append("        end else if (final_exp_calc <= 0) begin")
    sv.append("            final_out_data = {final_sign_pipe, {(EXPONENT_SIZE+MANTISSA_SIZE){1'b0}}};")
    sv.append("        end else if (final_exp_calc >= MAX_EXP) begin")
    sv.append("            final_out_data = {final_sign_pipe, {EXPONENT_SIZE{1'b1}}, {MANTISSA_SIZE{1'b0}}};")
    sv.append("        end else begin")
    sv.append("            final_out_data = {final_sign_pipe, final_exp_calc[EXPONENT_SIZE-1:0], final_mant};")
    sv.append("        end")
    sv.append("    end")
    sv.append("")
    sv.append("    always_ff @(posedge clk) begin")
    sv.append("        if (spec_case_pipe[SYNC_EXC-1]) ")
    sv.append("            result <= spec_res_pipe[SYNC_EXC-1];")
    sv.append("        else ")
    sv.append("            result <= final_out_data;")
    sv.append("    end")
    sv.append("")
    sv.append("endmodule")

    with open(file_path, "w") as f:
        f.write("\n".join(sv))

    if os.path.exists(adder_src_path):
        shutil.copy(adder_src_path, wrapper_dir)
        os.rename(os.path.join(wrapper_dir, os.path.basename(adder_src_path)), os.path.join(wrapper_dir, f"add{args.n}_tree.sv"))
        # rename adder tree file that was just copied to wrapper_dirto add32_tree.sv
    if os.path.exists(aligner_src_path):
        shutil.copy(aligner_src_path, wrapper_dir)
        os.rename(os.path.join(wrapper_dir, os.path.basename(aligner_src_path)), os.path.join(wrapper_dir, f"sysarr_{args.n}_aligner_tree.sv"))

if __name__ == "__main__":
    script_dir = os.path.dirname(os.path.abspath(__file__))
    aligner_path = os.path.join(script_dir, "gen_fp_aligner.py")
    adder_path   = os.path.join(script_dir, "gen_adder_tree_path_radix.py")

    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True, help="Number of inputs")
    parser.add_argument("--radices", type=str, default="2,4,8,15", help="Allowed radix shapes for the DSE")
    parser.add_argument("--tree-pipe", type=str, default=None, help="Aligner Max Tree pipeline config (e.g. 101)")
    parser.add_argument("--align-pipe", type=int, default=1, help="Aligner payload register (1=yes, 0=no)")
    parser.add_argument("--adder-path", type=str, default=None, help="Specific reduction path to wrap (e.g., 4_4_2)")
    parser.add_argument("--adder-cfg", type=str, default=None, help="Pipeline config for the adder path (e.g., 10)")
    parser.add_argument("--wrap-all", action="store_true", help="Generate wrappers for ALL DSE configurations")
    args = parser.parse_args()

    if args.tree_pipe is None:
        args.tree_pipe = "1" * math.ceil(math.log2(args.n))
    if args.adder_path is None and not args.wrap_all:
        args.adder_path = "_".join(["2"] * math.ceil(math.log2(args.n)))
    if args.adder_cfg is None and not args.wrap_all:
        args.adder_cfg = "0" * (len(args.adder_path.split('_')) - 1)

    dse_base_dir = f"dse_n{args.n}_results"
    aligner_base_dir = f"generated_aligners_{args.n}"

    run_cmd([sys.executable, adder_path, "-n", str(args.n), "--radices", args.radices])

    csv_file = os.path.join(dse_base_dir, "design_explorer_summary.csv")
    try:
        with open(csv_file, 'r') as f:
            reader = list(csv.DictReader(f))
    except FileNotFoundError:
        print(f"FAILED: Could not locate DSE output file at {csv_file}")
        sys.exit(1)

    generated_count = 0

    if args.wrap_all:
        align_levels = math.ceil(math.log2(args.n))
        align_tree_combos = ["".join(x) for x in product(['0', '1'], repeat=align_levels)]
        align_pipe_combos = [1]
        
        total_combos = len(align_tree_combos) * len(align_pipe_combos) * len(reader)
        print(f"--> --wrap-all passed. Exploring {len(align_tree_combos) * len(align_pipe_combos)} aligner configs against {len(reader)} adder configs (Total Top-Level Wrappers: {total_combos})...")

        for t_str in align_tree_combos:
            for a_pipe in align_pipe_combos:
                run_cmd([sys.executable, aligner_path, "-n", str(args.n), 
                         "--tree-pipe", t_str, "--align-pipe", str(a_pipe),
                         "--out-dir", aligner_base_dir])

        for row in reader:
            found_adder_module = os.path.basename(row['Filename']).replace('.sv', '')
            adder_src_location = os.path.join(dse_base_dir, row['Filename'])

            for t_str in align_tree_combos:
                for a_pipe in align_pipe_combos:
                    aligner_src_location = os.path.join(aligner_base_dir, f"sysarr_{args.n}_aligner_tree_{t_str}_reg_{a_pipe}.sv")
                    generate_top_wrapper(
                        n=args.n, 
                        adder_module_name=found_adder_module, 
                        adder_src_path=adder_src_location,
                        aligner_src_path=aligner_src_location,
                        align_pipe=a_pipe, 
                        align_tree_pipe_str=t_str, 
                        adder_path=row['Path'],
                        adder_cfg_str=row['Config'],
                        out_dir=f"master_modules_{args.n}"
                    )
                    generated_count += 1
                    
        print(f"--> [SUCCESS] {generated_count} Top-Level Wrappers successfully isolated in 'master_wrapper_examples/'")
        
    else:
        run_cmd([sys.executable, aligner_path, "-n", str(args.n), 
                 "--tree-pipe", args.tree_pipe, "--align-pipe", str(args.align_pipe),
                 "--out-dir", aligner_base_dir])

        found_adder_module = None
        adder_src_location = None
        for row in reader:
            if row['Path'] == args.adder_path and row['Config'] == args.adder_cfg:
                found_adder_module = os.path.basename(row['Filename']).replace('.sv', '')
                adder_src_location = os.path.join(dse_base_dir, row['Filename'])
                break

        if not found_adder_module:
            print(f"FAILED: Could not find an adder module matching Path='{args.adder_path}' and Config='{args.adder_cfg}'.")
            sys.exit(1)

        aligner_src_location = os.path.join(aligner_base_dir, f"sysarr_{args.n}_aligner_tree_{args.tree_pipe}_reg_{args.align_pipe}.sv")
        
        generate_top_wrapper(
            n=args.n, 
            adder_module_name=found_adder_module, 
            adder_src_path=adder_src_location,
            aligner_src_path=aligner_src_location,
            align_pipe=args.align_pipe, 
            align_tree_pipe_str=args.tree_pipe, 
            adder_path=args.adder_path,
            adder_cfg_str=args.adder_cfg,
            out_dir=f"master_modules_{args.n}"
        )
        print(f"--> [SUCCESS] Top-Level Wrapper successfully isolated in 'master_wrapper_examples/'")

    print("--> Cleaning up temporary generated modules...")
    if os.path.exists(dse_base_dir):
        shutil.rmtree(dse_base_dir)
    if os.path.exists(aligner_base_dir):
        shutil.rmtree(aligner_base_dir)
    print("--> Cleanup complete! All wrapper projects are perfectly self-contained.")