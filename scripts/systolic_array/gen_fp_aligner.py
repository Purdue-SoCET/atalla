#!/usr/bin/env python3
import argparse
import math
import os

# Usage: python gen_fp_aligner.py -n 8 --tree-pipe 101 --align-pipe 1
# --tree-pipe defines pipelines after each level of the max tree (1=pipe, 0=comb)
# --align-pipe adds a register after the mantissas are shifted

def generate_fp_aligner(n, tree_pipe_cfg, align_pipe, out_dir="."):
    EXP_SIZE = 8
    MANT_SIZE = 23
    PREC_BITS = 3 # Guard, Round, Sticky
    NEW_MANT_WIDTH = MANT_SIZE + PREC_BITS + 1 # +1 for hidden bit
    
    filename = f"sysarr_{n}_input_fp_aligner"
    file_path = os.path.join(out_dir, f"{filename}.sv")
    
    sv = ["`timescale 1ns/1ps"]
    sv.append(f"module {filename} #(")
    sv.append(f"    parameter EXPONENT_SIZE = {EXP_SIZE},")
    sv.append(f"    parameter MANTISSA_SIZE = {MANT_SIZE},")
    sv.append(f"    parameter NEW_MANT_WIDTH = {NEW_MANT_WIDTH}")
    sv.append(f") (")
    sv.append(f"    input  logic clk, nRST,")
    sv.append(f"    input  logic [1+EXPONENT_SIZE+MANTISSA_SIZE-1:0] in_fp [0:{n-1}],")
    sv.append(f"    output logic [EXPONENT_SIZE-1:0] out_max_exp,")
    sv.append(f"    output logic sign_out [0:{n-1}],")
    sv.append(f"    output logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:{n-1}]")
    sv.append(f");\n")
    
    # 1. Unpack Inputs and handle IEEE 754 hidden bit
    sv.append(f"    // --- Stage 0: Unpack & Append Hidden Bit ---")
    sv.append(f"    logic [EXPONENT_SIZE-1:0] exp_base [0:{n-1}];")
    sv.append(f"    logic sign_base [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] mant_base [0:{n-1}];\n")
    
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            sign_base[i] = in_fp[i][EXPONENT_SIZE+MANTISSA_SIZE];")
    sv.append(f"            exp_base[i]  = in_fp[i][MANTISSA_SIZE +: EXPONENT_SIZE];")
    sv.append(f"            // Add hidden bit if exp > 0, append precision bits")
    sv.append(f"            mant_base[i] = {{ (|exp_base[i]), in_fp[i][MANTISSA_SIZE-1:0], {{{PREC_BITS}{{1'b0}}}} }};")
    sv.append(f"        end")
    sv.append(f"    end\n")

    # 2. Max Exponent Tree (Now propagates the sign of the max exponent)
    tree_levels = math.ceil(math.log2(n))
    pipeline_map = [int(x) == 1 for x in str(tree_pipe_cfg)]
    while len(pipeline_map) < tree_levels:
        pipeline_map.append(False) # Pad with combinational if string is too short

    sv.append(f"    // --- Max Exponent Tree (Tracking Max Exp and its Sign) ---")
    current_nodes = [f"exp_base[{i}]" for i in range(n)]
    current_signs = [f"sign_base[{i}]" for i in range(n)]
    
    total_tree_delays = 0
    
    for lvl in range(tree_levels):
        num_nodes = len(current_nodes)
        next_nodes = []
        next_signs = []
        sv.append(f"    // Level {lvl} (Nodes: {num_nodes})")
        
        # Combinational compares
        for i in range(0, num_nodes, 2):
            node_name = f"max_l{lvl}_n{i//2}"
            sv.append(f"    logic [EXPONENT_SIZE-1:0] {node_name}_c;")
            sv.append(f"    logic sign_{node_name}_c;")
            if i + 1 < num_nodes:
                sv.append(f"    assign {node_name}_c = ({current_nodes[i]} > {current_nodes[i+1]}) ? {current_nodes[i]} : {current_nodes[i+1]};")
                sv.append(f"    assign sign_{node_name}_c = ({current_nodes[i]} > {current_nodes[i+1]}) ? {current_signs[i]} : {current_signs[i+1]};")
            else:
                sv.append(f"    assign {node_name}_c = {current_nodes[i]};")
                sv.append(f"    assign sign_{node_name}_c = {current_signs[i]};")
            
            next_nodes.append(f"{node_name}_r" if pipeline_map[lvl] else f"{node_name}_c")
            next_signs.append(f"sign_{node_name}_r" if pipeline_map[lvl] else f"sign_{node_name}_c")
        
        # Pipelining
        if pipeline_map[lvl]:
            total_tree_delays += 1
            sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
            sv.append(f"        if (!nRST) begin")
            for i in range(len(next_nodes)):
                sv.append(f"            {next_nodes[i]} <= '0;")
                sv.append(f"            {next_signs[i]} <= '0;")
            sv.append(f"        end else begin")
            for i in range(0, num_nodes, 2):
                node_name = f"max_l{lvl}_n{i//2}"
                sv.append(f"            {node_name}_r <= {node_name}_c;")
                sv.append(f"            sign_{node_name}_r <= sign_{node_name}_c;")
            sv.append(f"        end")
            sv.append(f"    end")
            for node in next_nodes:
                 sv.append(f"    logic [EXPONENT_SIZE-1:0] {node};")
            for sign_node in next_signs:
                 sv.append(f"    logic {sign_node};")
        
        current_nodes = next_nodes
        current_signs = next_signs
        sv.append("")

    final_max_exp  = current_nodes[0]
    final_max_sign = current_signs[0]

    # 3. Delay Payload to match Max Tree
    sv.append(f"    // --- Payload Delay Matching (Latency: {total_tree_delays} cycles) ---")
    sv.append(f"    logic sign_dly  [0:{total_tree_delays}][0:{n-1}];")
    sv.append(f"    logic [EXPONENT_SIZE-1:0] exp_dly   [0:{total_tree_delays}][0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] mant_dly [0:{total_tree_delays}][0:{n-1}];\n")
    
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            sign_dly[0][i] = sign_base[i];")
    sv.append(f"            exp_dly[0][i]  = exp_base[i];")
    sv.append(f"            mant_dly[0][i] = mant_base[i];")
    sv.append(f"        end")
    sv.append(f"    end\n")

    if total_tree_delays > 0:
        sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
        sv.append(f"        if (!nRST) begin")
        sv.append(f"            for (int d = 1; d <= {total_tree_delays}; d++) begin")
        sv.append(f"                for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                    sign_dly[d][i] <= '0;")
        sv.append(f"                    exp_dly[d][i]  <= '0;")
        sv.append(f"                    mant_dly[d][i] <= '0;")
        sv.append(f"                end")
        sv.append(f"            end")
        sv.append(f"        end else begin")
        sv.append(f"            for (int d = 1; d <= {total_tree_delays}; d++) begin")
        sv.append(f"                for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                    sign_dly[d][i] <= sign_dly[d-1][i];")
        sv.append(f"                    exp_dly[d][i]  <= exp_dly[d-1][i];")
        sv.append(f"                    mant_dly[d][i] <= mant_dly[d-1][i];")
        sv.append(f"                end")
        sv.append(f"            end")
        sv.append(f"        end")
        sv.append(f"    end\n")

    # 4. Alignment, Sticky Logic (US10514891B1), and 2's Complement
    sv.append(f"    // --- Alignment, Sticky Logic, & 2's Complement ---")
    sv.append(f"    logic [EXPONENT_SIZE:0] shift_amt [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] pre_shifted_mant [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] final_shifted_mant_c [0:{n-1}];")
    sv.append(f"    logic is_shifted_out_nonzero [0:{n-1}];")
    sv.append(f"    logic op_bit [0:{n-1}];")
    sv.append(f"    logic has_pos_sticky;")
    sv.append(f"    logic has_neg_sticky;")
    sv.append(f"    logic overall_sticky_active;")
    sv.append(f"    logic overall_sticky_sign;")
    sv.append(f"    logic sticky_applied;\n")

    sv.append(f"    always_comb begin")
    sv.append(f"        has_pos_sticky = 1'b0;")
    sv.append(f"        has_neg_sticky = 1'b0;")
    sv.append(f"        ")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            shift_amt[i] = {final_max_exp} - exp_dly[{total_tree_delays}][i];")
    sv.append(f"            op_bit[i] = {final_max_sign} ^ sign_dly[{total_tree_delays}][i];")
    sv.append(f"            ")
    sv.append(f"            // Check if any 1s are shifted out")
    sv.append(f"            if (shift_amt[i] >= NEW_MANT_WIDTH) begin")
    sv.append(f"                is_shifted_out_nonzero[i] = |mant_dly[{total_tree_delays}][i];")
    sv.append(f"            end else begin")
    sv.append(f"                is_shifted_out_nonzero[i] = |(mant_dly[{total_tree_delays}][i] & ~({{NEW_MANT_WIDTH{{1'b1}}}} << shift_amt[i]));")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            // Categorize sticky bit by sign relative to max exponent")
    sv.append(f"            if (is_shifted_out_nonzero[i]) begin")
    sv.append(f"                if (op_bit[i] == 1'b0) has_pos_sticky = 1'b1;")
    sv.append(f"                else                   has_neg_sticky = 1'b1;")
    sv.append(f"            end")
    sv.append(f"        end")
    sv.append(f"        ")
    sv.append(f"        // Overall sticky is 0 if mixed signs exist. Matches sign if homogenous.")
    sv.append(f"        overall_sticky_active = (has_pos_sticky ^ has_neg_sticky) & (has_pos_sticky | has_neg_sticky);")
    sv.append(f"        overall_sticky_sign   = has_neg_sticky;")
    sv.append(f"        sticky_applied        = 1'b0;")
    sv.append(f"        ")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            // Standard Shift")
    sv.append(f"            if (shift_amt[i] >= NEW_MANT_WIDTH) begin")
    sv.append(f"                pre_shifted_mant[i] = '0;")
    sv.append(f"            end else begin")
    sv.append(f"                pre_shifted_mant[i] = mant_dly[{total_tree_delays}][i] >> shift_amt[i];")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            // Apply overall sticky bit to the first matching operand")
    sv.append(f"            if (overall_sticky_active && !sticky_applied && (op_bit[i] == overall_sticky_sign)) begin")
    sv.append(f"                pre_shifted_mant[i][0] = 1'b1;")
    sv.append(f"                sticky_applied = 1'b1;")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            // Apply 2's Complement if sign differs from max exponent operand")
    sv.append(f"            if (op_bit[i]) begin")
    sv.append(f"                final_shifted_mant_c[i] = ~pre_shifted_mant[i] + 1'b1;")
    sv.append(f"            end else begin")
    sv.append(f"                final_shifted_mant_c[i] = pre_shifted_mant[i];")
    sv.append(f"            end")
    sv.append(f"        end")
    sv.append(f"    end\n")

    # 5. Output mapping / Alignment Pipeline
    if align_pipe:
        sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
        sv.append(f"        if (!nRST) begin")
        sv.append(f"            out_max_exp <= '0;")
        sv.append(f"            for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                sign_out[i] <= '0;")
        sv.append(f"                aligned_mant_out[i] <= '0;")
        sv.append(f"            end")
        sv.append(f"        end else begin")
        sv.append(f"            out_max_exp <= {final_max_exp};")
        sv.append(f"            for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                sign_out[i] <= sign_dly[{total_tree_delays}][i];")
        sv.append(f"                aligned_mant_out[i] <= final_shifted_mant_c[i];")
        sv.append(f"            end")
        sv.append(f"        end")
        sv.append(f"    end")
    else:
        sv.append(f"    assign out_max_exp = {final_max_exp};")
        sv.append(f"    always_comb begin")
        sv.append(f"        for (int i = 0; i < {n}; i++) begin")
        sv.append(f"            sign_out[i] = sign_dly[{total_tree_delays}][i];")
        sv.append(f"            aligned_mant_out[i] = final_shifted_mant_c[i];")
        sv.append(f"        end")
        sv.append(f"    end")

    sv.append("endmodule")
    
    with open(file_path, "w") as f:
        f.write("\n".join(sv))
    print(f"Generated module at: {file_path}")

def main():
    parser = argparse.ArgumentParser(description="Generate parameterized FP alignment module.")
    parser.add_argument("-n", type=int, required=True, help="Number of FP inputs")
    parser.add_argument("--tree-pipe", type=str, default="", help="Binary string: 1=pipe, 0=comb for each tree level (e.g. 101)")
    parser.add_argument("--align-pipe", type=int, default=1, help="1 to register outputs after shift, 0 for combinational")
    args = parser.parse_args()
    
    generate_fp_aligner(args.n, args.tree_pipe, args.align_pipe)

if __name__ == "__main__":
    main()