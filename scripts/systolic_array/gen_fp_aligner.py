#!/usr/bin/env python3
import argparse
import math
import os

def generate_fp_aligner(n, tree_pipe_cfg, align_pipe, out_dir="."):
    filename = f"sysarr_{n}_aligner_tree_{tree_pipe_cfg}_reg_{align_pipe}"
    # filename = f"sysarr_{n}_aligner_tree"
    file_path = os.path.join(out_dir, f"{filename}.sv")
    
    sv = ["`timescale 1ns/1ps"]
    sv.append(f"module sysarr_{n}_aligner_tree #(")
    sv.append(f"    parameter EXPONENT_SIZE = 8,")
    sv.append(f"    parameter MANTISSA_SIZE = 23,")
    sv.append(f"    parameter NEW_MANT_WIDTH = 27")
    sv.append(f") (")
    sv.append(f"    input  logic clk, nRST,")
    sv.append(f"    input  logic [1+EXPONENT_SIZE+MANTISSA_SIZE-1:0] in_fp [0:{n-1}],")
    sv.append(f"    output logic [EXPONENT_SIZE-1:0] out_max_exp,")
    sv.append(f"    output logic [1:0] out_sticky,")
    sv.append(f"    output logic sign_out [0:{n-1}],")
    sv.append(f"    output logic [NEW_MANT_WIDTH-1:0] aligned_mant_out [0:{n-1}]")
    sv.append(f");\n")
    
    sv.append(f"    // --- Stage 0: Unpack & Append Hidden Bit ---")
    sv.append(f"    logic [EXPONENT_SIZE-1:0] exp_base [0:{n-1}];")
    sv.append(f"    logic sign_base [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] mant_base [0:{n-1}];\n")
    
    sv.append(f"    localparam PAD_WIDTH = NEW_MANT_WIDTH - MANTISSA_SIZE - 2;")
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            sign_base[i] = in_fp[i][EXPONENT_SIZE+MANTISSA_SIZE];")
    sv.append(f"            exp_base[i]  = in_fp[i][MANTISSA_SIZE +: EXPONENT_SIZE];")
    sv.append(f"            mant_base[i] = {{ 1'b0, (|exp_base[i]), in_fp[i][MANTISSA_SIZE-1:0], {{PAD_WIDTH{{1'b0}}}} }};")
    sv.append(f"        end")
    sv.append(f"    end\n")

    tree_levels = math.ceil(math.log2(n))
    pipeline_map = [int(x) == 1 for x in str(tree_pipe_cfg)]
    while len(pipeline_map) < tree_levels: pipeline_map.append(False) 

    sv.append(f"    // --- Max Exponent Tree (Tracking Max Exp and its Sign) ---")
    current_nodes = [f"exp_base[{i}]" for i in range(n)]
    current_signs = [f"sign_base[{i}]" for i in range(n)]
    
    total_tree_delays = 0
    for lvl in range(tree_levels):
        num_nodes = len(current_nodes)
        next_nodes = []
        next_signs = []
        sv.append(f"    // Level {lvl} (Nodes: {num_nodes})")
        
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
        
        if pipeline_map[lvl]:
            total_tree_delays += 1
            for node in next_nodes: sv.append(f"    logic [EXPONENT_SIZE-1:0] {node};")
            for sign_node in next_signs: sv.append(f"    logic {sign_node};")
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
        
        current_nodes = next_nodes
        current_signs = next_signs
        sv.append("")

    final_max_exp  = current_nodes[0]
    final_max_sign = current_signs[0]

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

    sv.append(f"    // --- Alignment, Sticky Logic, & 2's Complement ---")
    sv.append(f"    logic [EXPONENT_SIZE:0] shift_amt [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] pre_shifted_mant [0:{n-1}];")
    sv.append(f"    logic [NEW_MANT_WIDTH-1:0] final_shifted_mant_c [0:{n-1}];")
    sv.append(f"    logic is_shifted_out_nonzero [0:{n-1}];")
    sv.append(f"    logic op_bit [0:{n-1}];")
    sv.append(f"    logic has_pos_sticky;")
    sv.append(f"    logic has_neg_sticky;")
    sv.append(f"    logic [1:0] c_out_sticky;")
    sv.append(f"    logic sticky_applied;\n")

    sv.append(f"    always_comb begin")
    sv.append(f"        has_pos_sticky = 1'b0;")
    sv.append(f"        has_neg_sticky = 1'b0;")
    sv.append(f"        ")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            shift_amt[i] = {{1'b0, {final_max_exp}}} - {{1'b0, exp_dly[{total_tree_delays}][i]}};")
    sv.append(f"            op_bit[i] = sign_dly[{total_tree_delays}][i];")
    sv.append(f"            ")
    sv.append(f"            if (shift_amt[i] >= NEW_MANT_WIDTH) begin")
    sv.append(f"                is_shifted_out_nonzero[i] = |mant_dly[{total_tree_delays}][i];")
    sv.append(f"            end else begin")
    sv.append(f"                is_shifted_out_nonzero[i] = |(mant_dly[{total_tree_delays}][i] & ~({{NEW_MANT_WIDTH{{1'b1}}}} << shift_amt[i]));")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            if (is_shifted_out_nonzero[i]) begin")
    sv.append(f"                if (op_bit[i] == 1'b0) has_pos_sticky = 1'b1;")
    sv.append(f"                else                   has_neg_sticky = 1'b1;")
    sv.append(f"            end")
    sv.append(f"        end")
    sv.append(f"        ")
    sv.append(f"        c_out_sticky[0] = (has_pos_sticky ^ has_neg_sticky) & (has_pos_sticky | has_neg_sticky);")
    sv.append(f"        c_out_sticky[1] = has_neg_sticky;")
    sv.append(f"        sticky_applied = 1'b0;")
    sv.append(f"        ")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            if (shift_amt[i] >= NEW_MANT_WIDTH) begin")
    sv.append(f"                pre_shifted_mant[i] = '0;")
    sv.append(f"            end else begin")
    sv.append(f"                pre_shifted_mant[i] = mant_dly[{total_tree_delays}][i] >> shift_amt[i];")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            // FIXED: Inject sticky bit so the 2s complement and adder tree handle it perfectly")
    sv.append(f"            if (c_out_sticky[0] && !sticky_applied && (op_bit[i] == c_out_sticky[1])) begin")
    sv.append(f"                pre_shifted_mant[i][0] = 1'b1;")
    sv.append(f"                sticky_applied = 1'b1;")
    sv.append(f"            end")
    sv.append(f"            ")
    sv.append(f"            if (op_bit[i]) begin")
    sv.append(f"                final_shifted_mant_c[i] = ~pre_shifted_mant[i] + 1'b1;")
    sv.append(f"            end else begin")
    sv.append(f"                final_shifted_mant_c[i] = pre_shifted_mant[i];")
    sv.append(f"            end")
    sv.append(f"        end")
    sv.append(f"    end\n")

    if align_pipe:
        sv.append(f"    always_ff @(posedge clk or negedge nRST) begin")
        sv.append(f"        if (!nRST) begin")
        sv.append(f"            out_max_exp <= '0;")
        sv.append(f"            out_sticky <= '0;")
        sv.append(f"            for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                sign_out[i] <= '0;")
        sv.append(f"                aligned_mant_out[i] <= '0;")
        sv.append(f"            end")
        sv.append(f"        end else begin")
        sv.append(f"            out_max_exp <= {final_max_exp};")
        sv.append(f"            out_sticky <= c_out_sticky;")
        sv.append(f"            for (int i = 0; i < {n}; i++) begin")
        sv.append(f"                sign_out[i] <= sign_dly[{total_tree_delays}][i];")
        sv.append(f"                aligned_mant_out[i] <= final_shifted_mant_c[i];")
        sv.append(f"            end")
        sv.append(f"        end")
        sv.append(f"    end")
    else:
        sv.append(f"    assign out_max_exp = {final_max_exp};")
        sv.append(f"    assign out_sticky = c_out_sticky;")
        sv.append(f"    always_comb begin")
        sv.append(f"        for (int i = 0; i < {n}; i++) begin")
        sv.append(f"            sign_out[i] = sign_dly[{total_tree_delays}][i];")
        sv.append(f"            aligned_mant_out[i] = final_shifted_mant_c[i];")
        sv.append(f"        end")
        sv.append(f"    end")

    sv.append("endmodule")
    
    with open(file_path, "w") as f: f.write("\n".join(sv))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True)
    parser.add_argument("--tree-pipe", type=str, default="101")
    parser.add_argument("--align-pipe", type=int, default=1)
    parser.add_argument("--out-dir", type=str, default=".")
    args = parser.parse_args()
    
    os.makedirs(args.out_dir, exist_ok=True)
    generate_fp_aligner(args.n, args.tree_pipe, args.align_pipe, args.out_dir)

if __name__ == "__main__":
    main()