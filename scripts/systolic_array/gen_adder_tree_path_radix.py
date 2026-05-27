#!/usr/bin/env python3
import argparse
import math
import os
import statistics
import csv
from itertools import product

# This script generates a variety of adder tree configurations based on specified parameters and evaluates their metrics.
# Usage: python gen_adder_tree_path_radix.py -n 16 --radices 2,4,8,15 
# the --radices option specifies the n-input adders available for the tree (ex, 2, 4, 8 allows a + b, a + b + c + d, etc...)

# Directory structure:
# dse_n[inputs]_results/
#   path_[radix_path]/
#     add[N]_tree_[path]_pipe_[pipeline_config]_lat[latency]_var[variance].sv


def find_normalized_paths(current_n, allowed_radices, current_path, all_paths):
    if current_n == 1:
        if current_path not in all_paths:
            all_paths.append(list(current_path))
        return
    for a in allowed_radices:
        actual_a = min(a, current_n)
        if (actual_a / a) < 0.5 and current_n > a:
            continue
        next_n = math.ceil(current_n / actual_a)
        if next_n < current_n:
            current_path.append(actual_a)
            find_normalized_paths(next_n, allowed_radices, current_path, all_paths)
            current_path.pop()

def calculate_metrics(n, a_list, pipeline_map):
    total_adders = 0
    total_regs = 0
    current_n = n
    depths = []
    current_depth = 1

    for level, a in enumerate(a_list):
        num_groups = current_n // a
        remainder = current_n % a
        total_adders += num_groups * (a - 1)
        if remainder > 1:
            total_adders += (remainder - 1)
            
        next_n = math.ceil(current_n / a)
        if level < len(pipeline_map) and pipeline_map[level]:
            total_regs += next_n
            depths.append(current_depth)
            current_depth = 1
        else:
            current_depth += 1
        current_n = next_n
    
    depths.append(current_depth)
    variance = round(statistics.variance(depths), 3) if len(depths) > 1 else 0.0
    return total_adders, total_regs, variance, depths

def generate_sv(n, a_list, pipeline_map, directory, filename):
    log2_n = math.ceil(math.log2(n))
    file_path = os.path.join(directory, f"{filename}.sv")
    
    sv = ["`timescale 1ns/1ps"]
    sv.append(f"module add{n}_tree #(parameter int WIDTH = 32) (")
    sv.append(f"    input logic clk, nRST,")
    sv.append(f"    input logic [WIDTH-1:0] in [0:{n-1}],")
    sv.append(f"    output logic [(WIDTH + {log2_n})-1:0] out_sum")
    sv.append(f");\n")
    
    sv.append(f"    localparam int EXT_BITS = {log2_n};")
    sv.append(f"    localparam int EXT_WIDTH = WIDTH + EXT_BITS;\n")

    sv.append(f"    logic [EXT_WIDTH-1:0] cur [0:{n-1}];")
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++)")
    sv.append(f"            cur[i] = {{ {{EXT_BITS{{in[i][WIDTH-1]}}}}, in[i] }};")
    sv.append(f"    end\n")

    current_pool = [f"cur[{i}]" for i in range(n)]
    
    for level, a in enumerate(a_list):
        next_pool = []
        sv.append(f"    // --- Stage {level}: {a}-way Reduction ---")
        
        # 1. Logic Generation (Declare first, then assign)
        for i in range(0, len(current_pool), a):
            group = current_pool[i : i + a]
            node = f"s{level}_g{i//a}"
            if len(group) > 1:
                sv.append(f"    logic [EXT_WIDTH-1:0] {node}_c;")
                sv.append(f"    assign {node}_c = " + " + ".join(group) + ";")
                next_pool.append(f"{node}_r")
            else:
                # Signal is a leftover - prepare it for a bypass register
                next_pool.append(f"{node}_r")

        # 2. Register/Bypass Generation
        if level < len(pipeline_map) and pipeline_map[level]:
            # Declare sequential signals
            for sig in next_pool: 
                sv.append(f"    logic [EXT_WIDTH-1:0] {sig};")
                
            sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
            sv.append(f"        if (!nRST) begin")
            for sig in next_pool: sv.append(f"            {sig} <= '0;")
            sv.append(f"        end else begin")
            
            for i in range(0, len(current_pool), a):
                group = current_pool[i : i + a]
                node = f"s{level}_g{i//a}"
                if len(group) > 1:
                    sv.append(f"            {node}_r <= {node}_c;")
                else:
                    # BYPASS REGISTER: Force leftovers to wait 1 cycle
                    sv.append(f"            {node}_r <= {group[0]};")
            sv.append(f"        end")
            sv.append(f"    end\n")
        else:
            # Combinatorial path: map _r names to _c or raw signals
            # Declare combinatorial pass-through signals
            for i in range(0, len(current_pool), a):
                node = f"s{level}_g{i//a}"
                sv.append(f"    logic [EXT_WIDTH-1:0] {node}_r;")
                
            for i in range(0, len(current_pool), a):
                group = current_pool[i : i + a]
                node = f"s{level}_g{i//a}"
                if len(group) > 1:
                    sv.append(f"    assign {node}_r = {node}_c;")
                else:
                    sv.append(f"    assign {node}_r = {group[0]};")
        
        current_pool = next_pool
        sv.append("")

    sv.append(f"    assign out_sum = {current_pool[0]};")
    sv.append("endmodule")
    with open(file_path, "w") as f: f.write("\n".join(sv))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True)
    parser.add_argument("--radices", type=str, default="2,4,8,15")
    args = parser.parse_args()
    
    allowed = sorted([int(x) for x in args.radices.split(",")], reverse=True)
    all_paths = []
    find_normalized_paths(args.n, allowed, [], all_paths)
    
    base_dir = f"dse_n{args.n}_results"
    os.makedirs(base_dir, exist_ok=True)
    
    summary_data = []

    for path in all_paths:
        path_str = "_".join(map(str, path))
        path_dir = os.path.join(base_dir, f"path_{path_str}")
        os.makedirs(path_dir, exist_ok=True)
        
        num_slots = len(path) - 1
        combos = list(product([True, False], repeat=num_slots))
        
        for combo in combos:
            adders, regs, var, depths = calculate_metrics(args.n, path, combo)
            cfg_str = "".join(['1' if x else '0' for x in combo])
            safe_var = str(var).replace('.', '_')
            latency = len(depths)
            
            # --- NEW NAMING CONVENTION ---
            fname = f"add{args.n}_tree_{path_str}_pipe_{cfg_str}_lat{latency}_var{safe_var}"
            # fname = f"add{args.n}_tree"
            
            generate_sv(args.n, path, combo, path_dir, fname)
            
            summary_data.append({
                "Path": path_str, "Config": cfg_str, "Variance": var,
                "Latency_Cycles": latency, "Logic_Depths": str(depths),
                "Total_Adders": adders, "Total_Reg_Signals": regs,
                "Filename": f"path_{path_str}/{fname}.sv"
            })

    csv_path = os.path.join(base_dir, "design_explorer_summary.csv")
    with open(csv_path, 'w', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=summary_data[0].keys())
        writer.writeheader()
        writer.writerows(summary_data)

    print(f"DSE Complete! Summary at: {csv_path}")

if __name__ == "__main__":
    main()