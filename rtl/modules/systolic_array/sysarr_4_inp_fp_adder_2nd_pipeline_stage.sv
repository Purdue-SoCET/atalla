// second pipeline stage of 4 input fp16/bf16 parameterized adder.
// by: Tarakanath Peddi, February 2026

module sysarr_4inp_fp_adder_2nd_pipeline_state #(parameter FRACTION_SIZE = 10, parameter EXPONENT_SIZE = 5, parameter PRECISION_BITS = 3) (
    input logic clk, nRST,
    input logic a_s, b_op, c_op, d_op,
    input logic b_sb, c_sb, d_sb, 
    input logic [EXPONENT_SIZE - 1:0] a_e,
    input logic [FRACTION_SIZE + PRECISION_BITS - 1:0] a_f, b_f, c_f, d_f, // these include the precision bits
    output logic [FRACTION_SIZE + PRECISION_BITS - 1:0] sum_i,
    output logic result_s, 
    output logic [EXPONENT_SIZE - 1:0] a_e_out,
    output logic [3:0] num_leading_zeros,
    output logic sticky_bit 
);  
    localparam WIDTH = FRACTION_SIZE + PRECISION_BITS;

    logic [WIDTH - 1:0] b_inv, c_inv, d_inv; 
    logic [WIDTH - 1:0] s1, c1; // adder immediate variables
    logic [WIDTH - 1:0] s2, c2;
    logic overall_sb; // overall sticky bit calculated
    logic next_result_s;
    logic [3:0] next_num_leading_zeros;
    logic [WIDTH - 1:0] next_sum_i;
    logic [WIDTH - 1:0] raw_sum;
    logic has_pos_sb, has_neg_sb;

    always_ff @( posedge clk, negedge nRST ) begin 
        if(~nRST) begin
            a_e_out <= 0;
            result_s <= 0;
            sum_i <= 0;
            num_leading_zeros <= 0;
            sticky_bit <= 0;
        end else begin
            a_e_out <= a_e;
            result_s <= next_result_s;
            sum_i <= next_sum_i;
            num_leading_zeros <= next_num_leading_zeros;
            sticky_bit <= overall_sb;
        end
    end

    // 2's complement inversion if *_op == 1
    assign b_inv = (b_op) ? ~b_f : b_f;
    assign c_inv = (c_op) ? ~c_f : c_f;
    assign d_inv = (d_op) ? ~d_f : d_f;

    // overall sticky bit calculator
    assign has_pos_sb = (b_sb && !b_op) || (c_sb && !c_op) || (d_sb && !d_op);
    assign has_neg_sb = (b_sb && b_op)  || (c_sb && c_op)  || (d_sb && d_op);

    always_comb begin
        if (has_pos_sb && has_neg_sb) overall_sb = 1'b0;
        else if (has_pos_sb || has_neg_sb) overall_sb = 1'b1;
        else overall_sb = 1'b0;
    end
    
    // 4 input adder (Carry Save Adder)

    genvar i;

    // stage 1: compress a, b, c
    generate
        for (i = 0; i < WIDTH; i++) begin : loop_s1
            full_adder fa_1 (
                .a   (a_f[i]),
                .b   (b_inv[i]),
                .c   (c_inv[i]),
                .sum (s1[i]),
                .co  (c1[i])
            );
        end
    endgenerate

    // stage 2: compress s1, d, and shifted c1
    generate
        for (i = 0; i < WIDTH; i++) begin : loop_s2
            if (i == 0) begin
                full_adder fa_2 (
                    .a   (s1[i]),
                    .b   (d_inv[i]),
                    .c   (1'b0),
                    .sum (s2[i]),
                    .co  (c2[i])
                );
            end else begin
                full_adder fa_2 (
                    .a   (s1[i]),
                    .b   (d_inv[i]),
                    .c   (c1[i-1]),
                    .sum (s2[i]),
                    .co  (c2[i])
                );
            end
        end
    endgenerate

    // stage 3: final addition
    // s2 + (c2 << 1) + (c1[msb] << width)
    assign raw_sum = {2'b0, s2} + 
                     {1'b0, c2, 1'b0} + 
                     {1'b0, c1[WIDTH-1], {WIDTH{1'b0}}} +
                     (b_op + c_op + d_op);

    // 2's complement inversion of sum if sign is negative:
    assign next_result_s = a_s ^ raw_sum[WIDTH - 1];
    assign next_sum_i = (next_result_s) ? ~raw_sum + 1 : raw_sum;

    // leading zero detector
    always_comb begin
        next_num_leading_zeros = WIDTH;

        for (int k = WIDTH - 1; k >= 0; k--) begin
            if (next_sum_i[k]) begin
                next_num_leading_zeros = (WIDTH - 1) - k;
                break;
            end
        end
    end
endmodule

// full adder module to use in Carry Save Adder 
module full_adder (
    input  logic a, b, c,
    output logic sum, co
);
    assign sum = a ^ b ^ c;
    assign co  = (a & b) | (b & c) | (a & c);
endmodule