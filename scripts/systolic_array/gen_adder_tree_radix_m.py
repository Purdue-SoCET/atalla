#!/usr/bin/env python3
import argparse
import math
import os

def generate_radix_m_tree(n, a, width=32, output_file=None):
    # a = Operands per stage (e.g., -a 8 means summing 8 inputs per stage)
    ext_bits = int(math.ceil(math.log2(n)))
    res_width = width + ext_bits
    
    if output_file:
        module_name = os.path.splitext(os.path.basename(output_file))[0]
    else:
        module_name = f"radix_tree_n{n}_a{a}"

    sv = []
    sv.append(f"// Generated {a}-way Adder Tree")
    sv.append(f"// N={n}, Operands per stage={a}")
    sv.append(f"module {module_name} (")
    sv.append(f"    input  logic clk, nRST,")
    sv.append(f"    input  logic [{width}-1:0] in [0:{n-1}],")
    sv.append(f"    output logic [{res_width}-1:0] out_sum")
    sv.append(f");\n")
    sv.append(f"    localparam int RES_W = {res_width};\n")

    # --- Initial Sign Extension ---
    sv.append(f"    logic [RES_W-1:0] ext_in [0:{n-1}];")
    sv.append(f"    always_comb begin")
    sv.append(f"        for (int i = 0; i < {n}; i++) begin")
    sv.append(f"            ext_in[i] = {{ {{{ext_bits}{{in[i][{width-1}]}}}}, in[i] }};")
    sv.append(f"        end")
    sv.append(f"    end\n")

    current_signals = [f"ext_in[{i}]" for i in range(n)]
    stage = 0
    
    while len(current_signals) > 1:
        next_signals = []
        sv.append(f"    // --- Stage {stage}: Reducing {len(current_signals)} signals ---")
        
        # Combinational Sums
        for i in range(0, len(current_signals), a):
            group = current_signals[i : i + a]
            group_name = f"s{stage}_g{i//a}"
            
            if len(group) > 1:
                sv.append(f"    logic [RES_W-1:0] {group_name}_comb;")
                sv.append(f"    assign {group_name}_comb = " + " + ".join(group) + ";")
                
                # Register for the group sum
                sv.append(f"    logic [RES_W-1:0] {group_name}_reg;")
                next_signals.append(f"{group_name}_reg")
            else:
                # Only 1 signal left in this group, pass it through
                sv.append(f"    logic [RES_W-1:0] {group_name}_pass;")
                next_signals.append(f"{group_name}_pass")

        # Flip-Flops
        sv.append(f"\n    always_ff @(posedge clk or negedge nRST) begin")
        sv.append(f"        if (!nRST) begin")
        for sig in next_signals:
            sv.append(f"            {sig} <= '0;")
        sv.append(f"        end else begin")
        
        # Assigning inputs/results to regs
        for idx, sig in enumerate(next_signals):
            start_idx = idx * a
            group = current_signals[start_idx : start_idx + a]
            if len(group) > 1:
                sv.append(f"            {sig} <= s{stage}_g{idx}_comb;")
            else:
                sv.append(f"            {sig} <= {group[0]};")
        
        sv.append(f"        end")
        sv.append(f"    end\n")
        
        current_signals = next_signals
        stage += 1

    sv.append(f"    assign out_sum = {current_signals[0]};")
    sv.append("endmodule")

    sv_out = "\n".join(sv)
    if output_file:
        with open(output_file, 'w') as f:
            f.write(sv_out)
        print(f"File saved to {output_file}")
    else:
        print(sv_out)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-n", type=int, required=True, help="Number of inputs")
    parser.add_argument("-a", type=int, required=True, help="Operands to sum per stage")
    parser.add_argument("-o", "--output", type=str, help="Output filename")
    args = parser.parse_args()
    generate_radix_m_tree(args.n, args.a, output_file=args.output)
