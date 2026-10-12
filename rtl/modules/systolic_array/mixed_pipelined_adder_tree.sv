// mixed_pipelined_adder_tree.sv
// Parameterized binary adder tree for MEISSA systolic array column reduction.
// Sums N FP16 products and injects an external partial sum (psum_in).
`include "sys_arr_pkg.vh" // for compute num tree levels function

module mixed_pipelined_adder_tree #(
    parameter int N           = 4,    // Number of inputs to sum (MUST be a power of 2), does not include psum
    parameter int DATA_WIDTH  = 16,   // Element width; must match adder module (FP16 = 16)
    parameter int FP_BF = 1           // Determine whether to use FP16 (1) or BF16 (0)
)(
    input  logic                    clk,
    input  logic                    nRST,
    input  logic                    stall,
    input  logic [N - 1:0] [DATA_WIDTH-1:0] terms_in,   // Products from one column
    input  logic [DATA_WIDTH-1:0]   psum_in,         // Partial sum; must be valid alongside terms_in
    output logic [DATA_WIDTH-1:0]   sum_out          // Final result = sum(terms_in) + psum_in
);

    localparam int TREE_DEPTH = compute_tree_levels(N);

    // Inter-stage wires
    // stage_data[l][k]  – data at tree level l, element k
    logic [TREE_DEPTH:0][N - 1:0][DATA_WIDTH-1:0] stage_data;

    assign stage_data[0] = terms_in;

    // Binary reduction tree  
    generate
        for (genvar l = 0; l < TREE_DEPTH; l++) begin : tree_level
            localparam int num_quads = N >> (2 * (l + 1));
            localparam int in_cnt = N >> (2 * l);

            for (genvar k = 0; k < num_quads; k++) begin : quads

                if (FP_BF) begin: four_adder_fp16
                    sysarr_4_input_fp_adder #(
                        .MANTISSA_SIZE(10), // Input Mantissa Width
                        .EXPONENT_SIZE(5),
                        .OUT_MANTISSA_SIZE(10), // Output Mantissa Width (New Parameter)
                        .PRECISION_BITS(22),
                        .WIDTH(16)
                    ) u_4_fp_adder (
                        .clk    (clk),
                        .nRST   (nRST),
                        .a(stage_data[l][4*k]),
                        .b(stage_data[l][4*k+1]),
                        .c(stage_data[l][4*k+2]),
                        .d(stage_data[l][4*k+3]),
                        .out(stage_data[l+1][k])
                    );
                end else begin: four_adder_bf16
                    sysarr_4_input_fp_adder #(
                        .MANTISSA_SIZE(7), // Input Mantissa Width
                        .EXPONENT_SIZE(8),
                        .OUT_MANTISSA_SIZE(7), // Output Mantissa Width (New Parameter)
                        .PRECISION_BITS(15),
                        .WIDTH(16)
                    ) u_4_bf_adder (
                        .clk    (clk),
                        .nRST   (nRST),
                        .a(stage_data[l][4*k]),
                        .b(stage_data[l][4*k+1]),
                        .c(stage_data[l][4*k+2]),
                        .d(stage_data[l][4*k+3]),
                        .out(stage_data[l+1][k])
                    );
                end
            end
            if (in_cnt == 2) begin
                if (FP_BF) begin: two_adder_fp16
                    add_fp16 u_2_adder (
                        .clk    (clk),
                        .nRST   (nRST),
                        .start  (1'b1),
                        .stall  (stall),
                        .sub    (1'b0),
                        .fp1_in (stage_data[l][0]),
                        .fp2_in (stage_data[l][1]),
                        .fp_out (stage_data[l+1][0]),
                        .done   ()
                    );
                end else begin: two_adder_bf16
                    add_bf16 u_2_adder (
                        .clk    (clk),
                        .nRST   (nRST),
                        .start  (1'b1),
                        .stall  (stall),
                        .sub    (1'b0),
                        .bf1 (stage_data[l][0]),
                        .bf2 (stage_data[l][1]),
                        .bf_out (stage_data[l+1][0]),
                        .overflow(), 
                        .underflow(), 
                        .invalid(), 
                        .done   ()
                    );
                end
            end
        end
    endgenerate

    // Final addition :  sum_out = tree_result + psum_delayed
    if (FP_BF) begin: final_add_fp16
        add_fp16 u_psum_add (
            .clk    (clk),
            .nRST   (nRST),
            .start  (1'b1),
            .stall  (stall),
            .sub    (1'b0),
            .fp1_in (stage_data[TREE_DEPTH][0]),
            .fp2_in (psum_in),
            .fp_out (sum_out),
            .done   ()
        );
    end else begin: final_add_bf16
        add_bf16 u_psum_add (
            .clk    (clk),
            .nRST   (nRST),
            .start  (1'b1),
            .stall  (stall),
            .bf1 (stage_data[TREE_DEPTH][0]),
            .bf2 (psum_in),
            .bf_out (sum_out),
            .overflow(), 
            .underflow(), 
            .invalid(), 
            .done   ()
        );
    end 

endmodule