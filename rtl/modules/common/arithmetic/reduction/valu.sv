`include "reduction_types.vh"
`include "valu_if.vh"

module valu (
    input  logic CLK,
    input  logic nRST,
    valu_if.valu valuif
);

import reduction_pkg::*;


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



logic fire_in, fire_out;

// ready_in is high when we are not holding a valid output
assign valuif.ready_in = !valuif.valid_out;

assign fire_in  = valuif.valid_in  & valuif.ready_in;
assign fire_out = valuif.valid_out & valuif.ready_out;

logic a_is_nan_raw, b_is_nan_raw, any_nan_raw;

always_comb begin
    a_is_nan_raw = (&valuif.operand1[14:7]) && (|valuif.operand1[6:0]);
    b_is_nan_raw = (&valuif.operand2[14:7]) && (|valuif.operand2[6:0]);
    any_nan_raw  = a_is_nan_raw | b_is_nan_raw;

    // adder inputs driven from stage-1 registers (so adder receives registered values)
    bf1_in = value_a_s1;
    bf2_in = value_b_s1;

    op = (valuif.alu_op == VR_SUB ||
          valuif.alu_op == VR_MIN ||
          valuif.alu_op == VR_MAX);
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
            value_a_s1 <= valuif.operand1;
            value_b_s1 <= valuif.operand2;
            alu_op_s1  <= valuif.alu_op;
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
        case (alu_op_s2)
            VR_SUM, VR_SUB: result_next = bf_out;
            VR_MIN:         result_next = (bf_out[15] ? value_a_s2 : value_b_s2);
            VR_MAX:         result_next = (bf_out[15] ? value_b_s2 : value_a_s2);
            default:        result_next = 16'h0000;
        endcase
    end
end

logic [15:0] result_reg;

always_ff @(posedge CLK or negedge nRST) begin
    if (!nRST) begin
        valuif.valid_out <= 1'b0;
        result_reg       <= 16'h0000;
    end else begin
        // If downstream accepted the result, clear valid_out
        if (valuif.valid_out && valuif.ready_out) begin
            valuif.valid_out <= 1'b0;
        end
        if (valid_s2 && !valuif.valid_out) begin
            result_reg       <= result_next;
            valuif.valid_out <= 1'b1;
        end
    end
end

// Drive interface result from registered output
assign valuif.result = result_reg;

endmodule
