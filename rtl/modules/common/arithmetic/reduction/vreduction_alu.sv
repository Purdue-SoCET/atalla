`include "reduction_types.vh"
`include "vreduction_alu_if.vh"

module vreduction_alu (
    input  logic CLK,
    input  logic nRST,
    vreduction_alu_if.vralu vraluif
);

import reduction_pkg::*;

function automatic logic bf16_gt(input logic [15:0] a, b);
    // Extract fields
    logic sa, sb;
    logic [7:0] ea, eb;
    logic [6:0] ma, mb;

    sa = a[15];
    sb = b[15];
    ea = a[14:7];
    eb = b[14:7];
    ma = a[6:0];
    mb = b[6:0];

    // Signed zero check
    if ((ea == 0 && ma == 0) && (eb == 0 && mb == 0))
        return 1'b0;

    // Different signs → easy
    if (sa != sb)
        return sb;   // if b has sign=1 → a > b

    // Same sign → compare fields
    if (sa == 1'b0) begin
        // Positive: normal ordering
        if (ea != eb) return (ea > eb);
        else return (ma > mb);
    end else begin
        // Negative: reversed ordering
        if (ea != eb) return (ea < eb);
        else return (ma < mb);
    end
endfunction


// Signals for addsub_bf16 (adder-only)
logic [15:0] bf1_in, bf2_in, bf_out;
logic op;  
logic overflow, underflow, invalid;

// Instantiate your BF16 adder (used ONLY for SUM)
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

// Pipeline regs
logic [15:0] value_a_s1, value_a_s2;
logic [15:0] value_b_s1, value_b_s2;
logic [1:0]  alu_op_s1, alu_op_s2;
logic any_nan_s1, any_nan_s2;

// NaN detect
logic a_is_nan, b_is_nan, any_nan;

always_comb begin
    a_is_nan = (&vraluif.value_a[14:7]) && (|vraluif.value_a[6:0]);
    b_is_nan = (&vraluif.value_b[14:7]) && (|vraluif.value_b[6:0]);
    any_nan = a_is_nan | b_is_nan;
end

// Stage 0: Adder only for SUM
always_comb begin
    bf1_in = vraluif.value_a;
    bf2_in = vraluif.value_b;
    op = 1'b0;          // Your adder only supports add
end

// Pipeline stage 1
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

// Pipeline stage 2
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

// Final output
always_comb begin
    if (any_nan_s2) begin
        vraluif.value_out = 16'h7FC0;
    end
    else if (alu_op_s2 == SUM) begin
        vraluif.value_out = bf_out;
    end
    else if (alu_op_s2 == MIN) begin
        if (bf16_gt(value_a_s2, value_b_s2))
            vraluif.value_out = value_b_s2;  // a>b → b is smaller
        else
            vraluif.value_out = value_a_s2;
    end
    else if (alu_op_s2 == MAX) begin
        if (bf16_gt(value_a_s2, value_b_s2))
            vraluif.value_out = value_a_s2;  // a>b → a is larger
        else
            vraluif.value_out = value_b_s2;
    end
    else begin
        vraluif.value_out = 16'h0000;
    end
end

endmodule
