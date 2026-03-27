// mixed_pipelined_adder_tree.sv
// Parameterized binary adder tree for MEISSA systolic array column reduction.
// Sums N FP16 products and injects an external partial sum (psum_in).
`include "sys_arr_pkg.vh" // for compute num tree levels function

module mixed_pipelined_adder_tree #(
    parameter int N           = 4,    // Number of inputs to sum (MUST be a power of 2), does not include psum
    // parameter int DATA_WIDTH  = 16,   // Element width; must match adder module (FP16 = 16)
    // parameter bit FINAL_LEVEL_ADD2 = 0,
    // parameter int FP_BF = 1           // Determine whether to use FP16 (1) or BF16 (0)
    localparam int ACC_WIDTH = IS_FP16 ? DW : DW_ACC,
    localparam int MANTISSA_SIZE = IS_FP16 ? 10 : 23,
    localparam int EXPONENT_SIZE = IS_FP16 ? 5 : 8
)(
    input  logic                    clk,
    input  logic                    nRST,
    input  logic                    stall,
    input  logic [N - 1:0] [ACC_WIDTH-1:0] terms_in,   // Products from one column
    input  logic [ACC_WIDTH-1:0]   psum_in,         // Partial sum; must be valid alongside terms_in
    output logic [ACC_WIDTH-1:0]   sum_out          // Final result = sum(terms_in) + psum_in
);

    // localparam int TREE_DEPTH = compute_tree_levels(N);

    localparam int TREE_DEPTH = ($clog2(N) + 1) >> 1;

    // Inter-stage wires
    // stage_data[l][k]  – data at tree level l, element k
    logic [TREE_DEPTH:0][N - 1:0][ACC_WIDTH-1:0] stage_data;

    assign stage_data[0] = terms_in;

    // Binary reduction tree  
    generate
        for (genvar l = 0; l < TREE_DEPTH; l++) begin : tree_level
            localparam int num_quads = N >> (2 * (l + 1));
            localparam int in_cnt = N >> (2 * l);

            for (genvar k = 0; k < num_quads; k++) begin : quads

                if (IS_FP16) begin: four_input_fp16_adder
                    // sysarr_4_input_fp_adder #(
                    //     // .MANTISSA_SIZE(10), // Input Mantissa Width
                    //     // .EXPONENT_SIZE(5),
                    //     // .OUT_MANTISSA_SIZE(10), // Output Mantissa Width (New Parameter)
                    //     // .PRECISION_BITS(22),
                    //     // .WIDTH(16)
                    //     // .WIDTH(DW_ACC)
                    // ) u_4_fp_adder (
                    //     .clk    (clk),
                    //     .nRST   (nRST),
                    //     .a(stage_data[l][4*k]),
                    //     .b(stage_data[l][4*k+1]),
                    //     .c(stage_data[l][4*k+2]),
                    //     .d(stage_data[l][4*k+3]),
                    //     .out(stage_data[l+1][k])
                    // );

                    add_fp16_4_input_no_if u_adder_fp16_4_input (
                        .clk    (clk),
                        .nRST   (nRST),
                        // .sub    (1'b0),
                        .a (stage_data[l][4*k]),
                        .b (stage_data[l][4*k+1]),
                        .c (stage_data[l][4*k+2]),
                        .d (stage_data[l][4*k+3]),
                        .out (stage_data[l + 1][k])
                    );
                end else begin: four_input_bf16_adder
                    sysarr_4_input_fp_adder_no_if #(
                        .MANTISSA_SIZE(MANTISSA_SIZE),
                        .EXPONENT_SIZE(EXPONENT_SIZE),
                        .IN_MANTISSA_SIZE(MANTISSA_SIZE),
                        .IN_EXPONENT_SIZE(EXPONENT_SIZE)
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
                // if (FP_BF) begin: two_input_fp16_adder
                    // add_fp16 u_2_adder (
                    //     .clk    (clk),
                    //     .nRST   (nRST),
                    //     .start  (1'b1),
                    //     .stall  (stall),
                    //     .sub    (1'b0),
                    //     .fp1_in (stage_data[l][0]),
                    //     .fp2_in (stage_data[l][1]),
                    //     .fp_out (stage_data[l+1][0]),
                    //     .done   ()
                    // );
                
                add_fp16_1c #(
                    .MANT_W(MANTISSA_SIZE),
                    .EXP_W(EXPONENT_SIZE)
                ) u_add (
                        .clk    (clk),
                        .nRST   (nRST),
                        .sub    (1'b0),
                        .fp1_in (stage_data[l][0]),
                        .fp2_in (stage_data[l][1]),
                        .fp_out (stage_data[l + 1][0])
                );
                // end else begin: two_input_bf16_adder
                    // add_bf16 u_2_adder (
                    //     .clk    (clk),
                    //     .nRST   (nRST),
                    //     .start  (1'b1),
                    //     .stall  (stall),
                    //     .sub    (1'b0),
                    //     .bf1 (stage_data[l][0]),
                    //     .bf2 (stage_data[l][1]),
                    //     .bf_out (stage_data[l+1][0]),
                    //     .overflow(), 
                    //     .underflow(), 
                    //     .invalid(), 
                    //     .done   ()
                    // );

                //     add_fp16_1c #(
                //         .MANT_W(23),
                //         .EXP_W(8)
                //     ) u_add (
                //         .clk    (clk),
                //         .nRST   (nRST),
                //         .sub    (1'b0),
                //         .fp1_in (stage_data[l][0]),
                //         .fp2_in (stage_data[l][1]),
                //         .fp_out (stage_data[l + 1][0])
                //     );
                // end
            end
        end
    endgenerate

    // Final addition :  sum_out = tree_result + psum_delayed
    // if (FP_BF) begin: final_add_fp16
    //     add_fp16 u_psum_add (
    //         .clk    (clk),
    //         .nRST   (nRST),
    //         .start  (1'b1),
    //         .stall  (stall),
    //         .sub    (1'b0),
    //         .fp1_in (stage_data[TREE_DEPTH][0]),
    //         .fp2_in (psum_in),
    //         .fp_out (sum_out),
    //         .done   ()
    //     );
    // end else begin: final_add_bf16
    //     add_bf16 u_psum_add (
    //         .clk    (clk),
    //         .nRST   (nRST),
    //         .start  (1'b1),
    //         .stall  (stall),
    //         .bf1 (stage_data[TREE_DEPTH][0]),
    //         .bf2 (psum_in),
    //         .bf_out (sum_out),
    //         .overflow(), 
    //         .underflow(), 
    //         .invalid(), 
    //         .done   ()
    //     );
    // end 

    assign sum_out = stage_data[TREE_DEPTH][0];

endmodule
