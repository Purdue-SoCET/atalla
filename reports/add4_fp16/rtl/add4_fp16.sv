`timescale 1ps/1ps

// 4-input FP16 Adder using balanced 2-level tree made by myles !! 
// out = (a + b) + (c + d)
// Latency: 2 cycles (each add_fp16 is 1 cycle

module add4_fp16 (
    input  logic        clk,
    input  logic        nRST,
    input  logic        start,
    input  logic        stall,
    input  logic [15:0] a,
    input  logic [15:0] b,
    input  logic [15:0] c,
    input  logic [15:0] d,
    output logic [15:0] fp_out,
    output logic        done
);

    logic [15:0] ab, cd;
    logic done_ab, done_cd;

    // Stage 1: parallel additions (a+b) and (c+d)
    add_fp16 u_ab (
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .stall(stall),
        .sub(1'b0),
        .fp1_in(a),
        .fp2_in(b),
        .fp_out(ab),
        .done(done_ab)
    );

    add_fp16 u_cd (
        .clk(clk),
        .nRST(nRST),
        .start(start),
        .stall(stall),
        .sub(1'b0),
        .fp1_in(c),
        .fp2_in(d),
        .fp_out(cd),
        .done(done_cd)
    );

    // Stage 2: final sum (ab + cd), starts when stage1 completes
    add_fp16 u_sum (
        .clk(clk),
        .nRST(nRST),
        .start(done_ab),  // Both done_ab and done_cd should align
        .stall(stall),
        .sub(1'b0),
        .fp1_in(ab),
        .fp2_in(cd),
        .fp_out(fp_out),
        .done(done)
    );

endmodule
