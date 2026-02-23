`include "vector_pkg.vh"
`include "vreduction_alu_if.vh"

module vreduction_alu (
    input logic CLK,
    input logic nRST,
    vreduction_alu_if.vralu vraluif
);

import vector_pkg::*;

// Signals for addsub_bf16
logic [15:0] bf1_in, bf2_in, bf_out;
logic op;  // 0 for add, 1 for sub
logic overflow, underflow, invalid;

// Instantiate addsub_bf16 instead of vaddsub
addsub_bf16 adder (
    .clk(CLK),
    .nRST(nRST),
    .bf1_in(bf1_in),
    .bf2_in(bf2_in),
    .op(op),
    .bf_out(bf_out),
    .overflow(overflow),
    .underflow(underflow),
    .invalid(invalid)
);

// Pipeline registers to match the 2-cycle adder latency
logic [15:0] value_a_s1, value_a_s2;
logic [15:0] value_b_s1, value_b_s2;
logic [1:0] alu_op_s1, alu_op_s2;
logic any_nan_s1, any_nan_s2;

// NaN detection
logic a_is_nan, b_is_nan, any_nan;

always_comb begin
    a_is_nan = (&vraluif.value_a[14:7]) && (|vraluif.value_a[6:0]);
    b_is_nan = (&vraluif.value_b[14:7]) && (|vraluif.value_b[6:0]);
    any_nan = a_is_nan | b_is_nan;
end

// Stage 0: Adder/subtractor control
always_comb begin
    bf1_in = vraluif.value_a;
    bf2_in = vraluif.value_b;
    
    // For MIN/MAX, we need to subtract to compare
    op = (vraluif.alu_op == ALU_MLT || vraluif.alu_op == ALU_MGT) ? 1'b1 : 1'b0;
end

// Pipeline Stage 1: Register inputs
always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        value_a_s1 <= '0;
        value_b_s1 <= '0;
        alu_op_s1 <= 2'b00;
        any_nan_s1 <= '0;
    end else begin
        value_a_s1 <= vraluif.value_a;
        value_b_s1 <= vraluif.value_b;
        alu_op_s1 <= vraluif.alu_op;
        any_nan_s1 <= any_nan;
    end
end

// Pipeline Stage 2: Register again to align with adder output
always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        value_a_s2 <= '0;
        value_b_s2 <= '0;
        alu_op_s2 <= 2'b00;
        any_nan_s2 <= '0;
    end else begin
        value_a_s2 <= value_a_s1;
        value_b_s2 <= value_b_s1;
        alu_op_s2 <= alu_op_s1;
        any_nan_s2 <= any_nan_s1;
    end
end

// Output multiplexing based on operation
always_comb begin
    if (any_nan_s2) begin
        // If any input was NaN, output NaN (BF16 NaN format)
        vraluif.value_out = 16'h7FC0;
    end
    else if (alu_op_s2 == ALU_ADD) begin
        // For SUM, use the adder result directly
        vraluif.value_out = bf_out;
    end
    else if (alu_op_s2 == ALU_MLT) begin
        // For MIN: if (a-b) is negative, a is smaller
        if (bf_out[15]) begin
            vraluif.value_out = value_a_s2;
        end else begin
            vraluif.value_out = value_b_s2;
        end
    end
    else if (alu_op_s2 == ALU_MGT) begin
        // For MAX: if (a-b) is negative, b is larger
        if (bf_out[15]) begin
            vraluif.value_out = value_b_s2;
        end else begin
            vraluif.value_out = value_a_s2;
        end
    end
    else begin
        vraluif.value_out = 16'h0000;
    end
end

endmodule