// second pipeline stage of 4 input fp16/bf16 parameterized adder.
// by: Tarakanath Peddi, February 2026

module sysarr_4inp_fp_adder_2nd_pipeline_state #(
    parameter MANTISSA_SIZE = 10,
    parameter EXPONENT_SIZE = 5,
    parameter PRECISION_BITS = 3
) (
    input logic clk, nRST,
    input logic a_s, b_op, c_op, d_op,
    input logic b_sb, c_sb, d_sb, 
    input logic [EXPONENT_SIZE - 1:0] a_e,
    input logic [MANTISSA_SIZE + PRECISION_BITS - 1:0] a_f, b_f, c_f, d_f, // these include the precision bits
    output logic [MANTISSA_SIZE + PRECISION_BITS - 1:0] sum_i,
    output logic result_s, 
    output logic [EXPONENT_SIZE - 1:0] a_e_out,
    output logic [3:0] num_leading_zeros,
);  

    localparam WIDTH = MANTISSA_SIZE + PRECISION_BITS;

    logic [WIDTH - 1:0] b_inv, c_inv, d_inv; 
    logic [WIDTH - 1:0] s1, c1; // adder immediate variables
    logic [WIDTH - 1:0] s2, c2;

    logic signed [2:0] signed_sb_sum;

    logic next_result_s;
    logic [3:0] next_num_leading_zeros;

    logic [WIDTH:0] magnitude_sum;
    logic [WIDTH:0] corrected_sum;

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
            sum_i <= corrected_sum[WIDTH-1:0];
            num_leading_zeros <= next_num_leading_zeros;
            sticky_bit <= (signed_sb_sum != 0);
        end
    end

    // 2's complement inversion if *_op == 1
    assign b_inv = (b_op) ? ~b_f : b_f;
    assign c_inv = (c_op) ? ~c_f : c_f;
    assign d_inv = (d_op) ? ~d_f : d_f;

    // overall sticky bit calculator
    always_comb begin
        signed_sb_sum = 0;
        if (b_sb) signed_sb_sum += b_op ? -1 : 1;
        if (c_sb) signed_sb_sum += c_op ? -1 : 1;
        if (d_sb) signed_sb_sum += d_op ? -1 : 1;
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
            full_adder fa_2 (
                .a   (s1[i]),
                .b   (d_inv[i]),
                .c   (i == 0 ? 1'b0 : c1[i-1]),
                .sum (s2[i]),
                .co  (c2[i])
            );
        end
    endgenerate

    // stage 3: final addition
    // s2 + (c2 << 1) + (c1[msb] << width)
    assign magnitude_sum =
          {1'b0, s2}
        + {c2, 1'b0}
        + {c1[WIDTH-1], {WIDTH{1'b0}}}
        + (b_op + c_op + d_op);

    // 2's complement inversion of sum if sign is negative:
    assign next_result_s = a_s ^ magnitude_sum[WIDTH];
    assign corrected_sum = next_result_s ? (~magnitude_sum + 1'b1)
                                         : magnitude_sum;

    // leading zero detector
    always_comb begin
        next_num_leading_zeros = 4'hF;

        for (int k = WIDTH - 1; k >= 0; k--) begin
            if (corrected_sum[k]) begin
                next_num_leading_zeros =
                    ((WIDTH - 1 - k) > 15) ? 4'hF : (WIDTH - 1 - k);
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
