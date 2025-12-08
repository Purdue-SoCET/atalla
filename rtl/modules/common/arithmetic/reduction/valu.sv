`include "reduction_types.vh"
`include "valu_if.vh"

module valu (
    input  logic CLK,
    input  logic nRST,
    valu_if.valu_if alu
);

import reduction_pkg::*;

function automatic logic bf16_gt (
    input logic [15:0] a,
    input logic [15:0] b
);
    // detect NaNs
    logic a_nan = (&a[14:7]) && (|a[6:0]);
    logic b_nan = (&b[14:7]) && (|b[6:0]);

    if (a_nan || b_nan)
        return 1'b0; // don't claim a > b if NaN present

    // Different signs: positive is always greater
    if (a[15] != b[15])
        return (b[15] == 1'b1);  // a is positive → a > b

    // Same sign:
    if (a[15] == 1'b0)
        // both positive → compare normally
        return (a[14:0] > b[14:0]);
    else
        // both negative → reversed comparison
        return (a[14:0] < b[14:0]);
endfunction

logic [15:0] bf1_in, bf2_in, bf_out;
logic op;
logic overflow, underflow, invalid;

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

logic [15:0] value_a_s1, value_b_s1;
logic [15:0] value_a_s2, value_b_s2;

logic [1:0] alu_op_s1, alu_op_s2;

logic any_nan_s1, any_nan_s2;

logic valid_s1, valid_s2;

logic fire_in, fire_out;

// Accept new input only when not holding unconsumed result
assign alu.out.ready_in = alu.in.ready_out;

assign fire_in  = alu.in.valid_in  & alu.out.ready_in;
assign fire_out = alu.out.valid_out & alu.in.ready_out;

logic a_is_nan_raw, b_is_nan_raw, any_nan_raw;

always_comb begin
    a_is_nan_raw = (&alu.in.operand1[14:7]) && (|alu.in.operand1[6:0]);
    b_is_nan_raw = (&alu.in.operand2[14:7]) && (|alu.in.operand2[6:0]);
    any_nan_raw  = a_is_nan_raw | b_is_nan_raw;

    // adder inputs driven from stage-1 registers
    bf1_in = value_a_s1;
    bf2_in = value_b_s1;

    // use registered opcode so adder sees same control as operands
    op = (alu_op_s1 == SUB ||
          alu_op_s1 == MIN ||
          alu_op_s1 == MAX);
end

always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        value_a_s1 <= '0;
        value_b_s1 <= '0;
        alu_op_s1  <= 2'b00;
        any_nan_s1 <= 1'b0;
        valid_s1   <= 1'b0;
    end else begin
        if (fire_in) begin
            value_a_s1 <= alu.in.operand1;
            value_b_s1 <= alu.in.operand2;
            alu_op_s1  <= alu.in.alu_op;
            any_nan_s1 <= any_nan_raw;
        end
        valid_s1 <= fire_in;
    end
end

always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        value_a_s2 <= '0;
        value_b_s2 <= '0;
        alu_op_s2  <= 2'b00;
        any_nan_s2 <= 1'b0;
        valid_s2   <= 1'b0;
    end else begin
        value_a_s2 <= value_a_s1;
        value_b_s2 <= value_b_s1;
        alu_op_s2  <= alu_op_s1;
        any_nan_s2 <= any_nan_s1;
        valid_s2   <= valid_s1;
    end
end

logic [15:0] result_next;

always_comb begin
    if (any_nan_s2) begin
        result_next = 16'h7FC0; // canonical BF16 qNaN
    end
    else begin
        unique case (alu_op_s2)

            SUM, SUB: begin
                // use adder output
                result_next = bf_out;
            end

            MIN: begin
                // if a > b → min is b
                result_next = bf16_gt(value_a_s2, value_b_s2)
                               ? value_b_s2 
                               : value_a_s2;
            end

            MAX: begin
                // if a > b → max is a
                result_next = bf16_gt(value_a_s2, value_b_s2)
                               ? value_a_s2 
                               : value_b_s2;
            end

            default: begin
                result_next = 16'h0000;
            end

        endcase
    end
end

logic [15:0] result_reg;

always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        alu.out.valid_out <= 1'b0;
        result_reg        <= 16'h0000;
    end else begin
        if (alu.out.valid_out && alu.in.ready_out)
            alu.out.valid_out <= 1'b0;

        if (valid_s2 && !alu.out.valid_out) begin
            result_reg        <= result_next;
            alu.out.valid_out <= 1'b1;
        end
    end
end

// Drive result
assign alu.out.result = result_reg;

endmodule