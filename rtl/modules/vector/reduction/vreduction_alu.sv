`include "vector_pkg.vh"
`include "vreduction_alu_if.vh"

module vreduction_alu (
    input logic CLK,
    input logic nRST,
    vreduction_alu_if.vralu vraluif
);

import vector_pkg::*;

// BF16 format parameters for add_fp
localparam int BF16_MANT_W = 7;
localparam int BF16_EXP_W  = 8;

// Signals for add_fp
logic [15:0] bf1_in, bf2_in, bf_out;
logic op;  // 0 for add, 1 for sub

//  add_fp parameterized for BF16.
// add_fp has a single pipeline register splitting its datapath, so bf_out is
// valid 1 cycle after the inputs. the operand/op/NaN side is delayed by one
// matching register stage below so the output mux sees them together.
add_fp #(
    .MANT_W(BF16_MANT_W),
    .EXP_W (BF16_EXP_W)
) adder (
    .clk   (CLK),
    .nRST  (nRST),
    .start (1'b1),
    .stall (1'b0),
    .sub   (op),
    .fp1_in(bf1_in),
    .fp2_in(bf2_in),
    .fp_out(bf_out),
    .done  ()
);

// Shadow pipeline matching the 1-cycle adder latency
logic [15:0] value_a_s1;
logic [15:0] value_b_s1;
alu_op_t     alu_op_s1;
logic        any_nan_s1;
logic a_is_nan, b_is_nan, any_nan;

// NaN detection (BF16: exp = bits [14:7], mantissa = bits [6:0])
always_comb begin
    a_is_nan = (&vraluif.value_a[14:7]) && (|vraluif.value_a[6:0]);
    b_is_nan = (&vraluif.value_b[14:7]) && (|vraluif.value_b[6:0]);
    any_nan = a_is_nan | b_is_nan;
end

// Adder/subtractor control
always_comb begin
    bf1_in = vraluif.value_a;
    bf2_in = vraluif.value_b;

    // For MIN/MAX, we need to subtract to compare
    op = (vraluif.alu_op == ALU_MLT || vraluif.alu_op == ALU_MGT) ? 1'b1 : 1'b0;
end

// pipeline 1: delay operands/op/NaN for align w out
always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        value_a_s1 <= '0;
        value_b_s1 <= '0;
        alu_op_s1  <= ALU_ADD;
        any_nan_s1 <= '0;
    end else begin
        value_a_s1 <= vraluif.value_a;
        value_b_s1 <= vraluif.value_b;
        alu_op_s1  <= vraluif.alu_op;
        any_nan_s1 <= any_nan;
    end
end

// output mux
always_comb begin
    if (any_nan_s1) begin
        // If any input was NaN, output NaN (BF16 NaN format)
        vraluif.value_out = 16'h7FC0;
    end
    else if (alu_op_s1 == ALU_ADD) begin
        // For SUM, use the adder result directly
        vraluif.value_out = bf_out;
    end
    else if (alu_op_s1 == ALU_MLT) begin
        // For MIN: if (a-b) is negative, a is smaller
        if (bf_out[15]) begin
            vraluif.value_out = value_a_s1;
        end else begin
            vraluif.value_out = value_b_s1;
        end
    end
    else if (alu_op_s1 == ALU_MGT) begin
        // For MAX: if (a-b) is negative, b is larger
        if (bf_out[15]) begin
            vraluif.value_out = value_b_s1;
        end else begin
            vraluif.value_out = value_a_s1;
        end
    end
    else begin
        vraluif.value_out = 16'h0000;
    end
end

endmodule
