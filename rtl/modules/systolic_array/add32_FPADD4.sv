`include "systolic_array_4_input_adder_if.vh"

module add32_FPADD4 #(
    parameter MANTISSA_SIZE    = 23, // Internal accumulation precision
    parameter EXPONENT_SIZE    = 8,
    parameter PRECISION_BITS   = 0,
    parameter GRS              = 0
) (
    input  logic clk,
    input  logic nRST,
    input  logic [31:0][15:0] inputs, // 32 inputs (assuming BF16/FP32 packed in 32-bit)
    output logic [15:0]       out_bf16  // Final reduced output
);

    // Total width of internal FP32-like signals
    localparam RES_WIDTH = 1 + EXPONENT_SIZE + MANTISSA_SIZE;

    // -------------------------------------------------------------------------
    // Internal Interface Declarations
    // -------------------------------------------------------------------------
    
    // Stage 1: 8 interfaces (BF16 [7-bit mantissa] to FP32)
    systolic_array_4_input_adder_if #(
        .EXPONENT_SIZE(8), 
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_MANTISSA_SIZE(7), 
        .IN_EXPONENT_SIZE(8)
    ) stage1_if [7:0] ();

    // Stage 2: 2 interfaces (FP32 to FP32)
    systolic_array_4_input_adder_if #(
        .EXPONENT_SIZE(8), 
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_EXPONENT_SIZE(8)
    ) stage2_if [1:0] ();

    // Stage 3: 1 interface (Final reduction)
    systolic_array_4_input_adder_if #(
        .EXPONENT_SIZE(8), 
        .MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_EXPONENT_SIZE(8)
    ) stage3_if ();

    // -------------------------------------------------------------------------
    // STAGE 1: 8 Adders (Reduces 32 inputs to 8)
    // -------------------------------------------------------------------------
    generate
        for (genvar i = 0; i < 8; i++) begin : gen_s1
            sysarr_4_input_fp_adder #(
                .EXPONENT_SIZE(EXPONENT_SIZE), 
                .MANTISSA_SIZE(MANTISSA_SIZE),
                .IN_MANTISSA_SIZE(7), 
                .IN_EXPONENT_SIZE(8),
                .PRECISION_BITS(PRECISION_BITS), 
                .GRS(GRS)
            ) adder_s1 (
                .clk(clk), 
                .nRST(nRST), 
                .add(stage1_if[i])
            );
            // Connect 4 inputs per adder
            assign stage1_if[i].a = inputs[i*4 + 0];
            assign stage1_if[i].b = inputs[i*4 + 1];
            assign stage1_if[i].c = inputs[i*4 + 2];
            assign stage1_if[i].d = inputs[i*4 + 3];
        end
    endgenerate

    // -------------------------------------------------------------------------
    // STAGE 2: 2 Adders (Reduces 8 inputs to 2)
    // -------------------------------------------------------------------------
    generate
        for (genvar j = 0; j < 2; j++) begin : gen_s2
            sysarr_4_input_fp_adder #(
                .EXPONENT_SIZE(EXPONENT_SIZE), 
                .MANTISSA_SIZE(MANTISSA_SIZE),
                .IN_MANTISSA_SIZE(MANTISSA_SIZE), 
                .IN_EXPONENT_SIZE(8),
                .PRECISION_BITS(PRECISION_BITS), 
                .GRS(GRS)
            ) adder_s2 (
                .clk(clk), 
                .nRST(nRST), 
                .add(stage2_if[j])
            );
            // Connect outputs from Stage 1
            assign stage2_if[j].a = stage1_if[j*4 + 0].out;
            assign stage2_if[j].b = stage1_if[j*4 + 1].out;
            assign stage2_if[j].c = stage1_if[j*4 + 2].out;
            assign stage2_if[j].d = stage1_if[j*4 + 3].out;
        end
    endgenerate

    // -------------------------------------------------------------------------
    // STAGE 3: Final reduction (Reduces 2 inputs to 1)
    // -------------------------------------------------------------------------
    sysarr_4_input_fp_adder #(
        .EXPONENT_SIZE(EXPONENT_SIZE), 
        .MANTISSA_SIZE(MANTISSA_SIZE),
        .IN_MANTISSA_SIZE(MANTISSA_SIZE), 
        .IN_EXPONENT_SIZE(8),
        .PRECISION_BITS(PRECISION_BITS), 
        .GRS(GRS)
    ) adder_s3 (
        .clk(clk), 
        .nRST(nRST), 
        .add(stage3_if)
    );

    assign stage3_if.a = stage2_if[0].out;
    assign stage3_if.b = stage2_if[1].out;
    assign stage3_if.c = '0; // Tie off unused inputs
    assign stage3_if.d = '0;

    // -------------------------------------------------------------------------
    // Output Reduction (FP32 precision back to BF16)
    // -------------------------------------------------------------------------
    reducer #(
        .IN_EXP_W(8), 
        .IN_MANT_W(MANTISSA_SIZE), 
        .OUT_EXP_W(8), 
        .OUT_MANT_W(7)
    ) final_reduce (
        .fp_in(stage3_if.out), 
        .fp_out(out_bf16)
    );

endmodule