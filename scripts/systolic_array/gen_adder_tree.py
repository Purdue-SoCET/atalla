#!/usr/bin/env python3
import argparse
import math
import os
from itertools import product

# This script generates SystemVerilog files for adder trees with various pipeline configurations.
# Usage: python3 gen_adder_tree.py -n <num_inputs> -a <radix>

def generate_verilog(n, a, pipeline_map, directory):
    """
    Generates a single SystemVerilog file with a specific pipeline configuration.
    The SV module itself is parameterizable for bit-width.
    """
    # Calculate how many extra bits we need to prevent overflow based on N
    log2_n = math.ceil(math.log2(n))
    
    # Create configuration string for the filename (e.g., 101)
    cfg_str = "".join(['1' if x else '0' for x in pipeline_map])
    mod_name = f"adder_n{n}_a{a}_cfg_{cfg_str}"
    file_path = os.path.join(directory, f"{mod_name}.sv")
    
    sv = [f"// Auto-generated Adder Tree | Configuration: {cfg_str} (1=Reg, 0=Comb)"]
    sv.append(f"// Number of Inputs: {n} | Radix: {a}")
    sv.append(f"module {mod_name} #(")
    sv.append(f"    parameter int WIDTH = 32  // Parameterizable Input Width")
    sv.append(f") (")
    sv.append(f"    input  logic clk, nRST,")
    sv.append(f"    input  logic [WIDTH-1:0] in [0:{n-1}],")
    sv.append(f"    output logic [(WIDTH + {log2_n})-1:0] out_sum")
    sv.append(f");\n")
    
    sv.append(f"    localparam int EXT_BITS = {log2_n};")
    sv.append(f"    localparam int EXT_WIDTH = WIDTH + EXT_BITS;\n")

    # Sign Extension Block
    sv.append(f"    logic [EXT_WIDTH-1:0] current_sigs [0:{n-1}];")
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            current_sigs[i] = {{ {{EXT_BITS{{in[i][WIDTH-1]}}}}, in[i] }};")
    sv.append(f"        end")
    sv.append(f"    end\n")

    current_pool = [f"current_sigs[{i}]" for i in range(n)]
    level = 0
    
    while len(current_pool) > 1:
        next_pool = []
        sv.append(f"    // --- Level {level} reduction ---")
        
        # Combinational logic for this level
        for i in range(0, len(current_pool), a):
            group = current_pool[i : i + a]
            node_name = f"l{level}_g{i//a}"
            if len(group) > 1:
                sv.append(f"    logic [EXT_WIDTH-1:0] {node_name}_comb = " + " + ".join(group) + ";")
                next_pool.append(f"{node_name}_comb")
            else:
                # If only one operand is left, it passes through to the next level
                next_pool.append(group[0])

        # Check the pipeline map to see if we flop after this level
        if len(next_pool) > 1 and level < len(pipeline_map):
            should_reg = pipeline_map[level]
            if should_reg:
                sv.append(f"\n    // --- Pipeline Register Stage (Post-Level {level}) ---")
                reg_pool = []
                for i, sig in enumerate(next_pool):
                    reg_name = f"l{level}_reg_{i}"
                    sv.append(f"    logic [EXT_WIDTH-1:0] {reg_name};")
                    reg_pool.append(reg_name)
                
                sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
                sv.append(f"        if (!nRST) begin")
                for r in reg_pool: sv.append(f"            {r} <= '0;")
                sv.append(f"        end else begin")
                for i, sig in enumerate(next_pool):
                    sv.append(f"            {reg_pool[i]} <= {sig};")
                sv.append(f"        end\n    end\n")
                next_pool = reg_pool
        
        current_pool = next_pool
        level += 1

    sv.append(f"    assign out_sum = {current_pool[0]};")
    sv.append("endmodule")
    
    with open(file_path, "w") as f:
        f.write("\n".join(sv))

def main():
    parser = argparse.ArgumentParser(description="Exhaustive Adder Tree Pipeline Generator")
    parser.add_argument("-n", type=int, required=True, help="Number of input operands")
    parser.add_argument("-a", type=int, required=True, help="Number of operands to sum per stage")
    args = parser.parse_args()

    # Calculate levels: log_a(n)
    num_levels = math.ceil(math.log(args.n, args.a))
    num_slots = num_levels - 1
    
    # Create the directory named according to n and a
    output_dir = f"gen_n{args.n}_a{args.a}"
    os.makedirs(output_dir, exist_ok=True)

    print(f"Directory: {output_dir}")
    print(f"Tree Depth: {num_levels} levels | Pipeline Slots: {num_slots}")
    print(f"Generating {2**num_slots} permutations...")

    # Generate all combinations of [True, False] for the available slots
    all_combos = list(product([True, False], repeat=num_slots))
    
    for combo in all_combos:
        generate_verilog(args.n, args.a, combo, output_dir)

    print("Success. All SystemVerilog files are parameterizable by WIDTH.")

if __name__ == "__main__":
    main()