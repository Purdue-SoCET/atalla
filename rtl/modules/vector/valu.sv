`include "vector_types.vh"
`include "valu_if.vh"

module valu (
    input logic CLK,
    input logic nRST,
    valu_if.valu valuif
);

// import vector_pkg::*;
typedef enum logic [1:0] {
    VALU_ADD = 2'b00,
    VALU_SUB = 2'b01,
    VALU_GT  = 2'b10,
    VALU_LT  = 2'b11
} valu_op_t;

parameter int EXP_WIDTH = valuif.EXP_WIDTH;
parameter int MANT_WIDTH = valuif.MANT_WIDTH;
parameter int WIDTH = EXP_WIDTH + MANT_WIDTH;

logic [15:0] bf1_in, bf2_in, bf_out;
logic overflow, underflow, invalid;
addsub_bf16 adder (.clk(CLK), .nRST(nRST), .bf1_in(bf1_in), .bf2_in(bf2_in), .bf_out(bf_out),
               .overflow(overflow), .underflow(underflow), .invalid(invalid));

// Handshake logic
logic next_valid_out;
always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST) begin
        valuif.out.valid_out <= 1'b0;
        valuif.out.ready_in <= 1'b0;
        next_valid_out <= 1'b0;
    end else begin
        if (valuif.in.valid_in) next_valid_out <= 1'b1;
        else next_valid_out <= 1'b0;
        valuif.out.valid_out <= next_valid_out;
        valuif.out.ready_in <= 1'b1;
    end
end

// NaN detection
logic a_is_nan, b_is_nan;
always_comb begin
    a_is_nan = (&valuif.in.operand1[WIDTH-1 -: EXP_WIDTH]) && (|valuif.in.operand1[MANT_WIDTH-1:0]);
    b_is_nan = (&valuif.in.operand2[WIDTH-1 -: EXP_WIDTH]) && (|valuif.in.operand2[MANT_WIDTH-1:0]);
end

// Register inputs and output
logic any_nan;
logic [15:0] operand1, operand2;
logic [1:0] alu_op;
logic [15:0] next_result;
always_ff @(posedge CLK, negedge nRST) begin
    if (~nRST) begin
        any_nan <= 1'b0;
        operand1 <= 0;
        operand2 <= 0;
        alu_op <= 0;
        valuif.out.result <= 0;
    end else begin
        any_nan <= a_is_nan | b_is_nan;
        operand1 <= valuif.in.operand1;
        operand2 <= valuif.in.operand2;
        alu_op <= valuif.in.alu_op;
        valuif.out.result <= next_result;
    end
end

// Adder control
logic sub;
always_comb begin
    sub = (valuif.in.alu_op != VALU_ADD);
    bf1_in = valuif.in.operand1;
    bf2_in = sub ? {~valuif.in.operand2[WIDTH], valuif.in.operand2[WIDTH-1:0]} : valuif.in.operand2;
end

always_comb begin
    if (any_nan) begin
        next_result = {1'b0, {EXP_WIDTH{1'b1}}, 1'b1, {(MANT_WIDTH-1){1'b0}}};
    end else begin
        case (alu_op)
            VALU_ADD: next_result = bf_out;
            VALU_SUB: next_result = bf_out;
            VALU_GT: next_result = bf_out[WIDTH] ? operand1 : operand2;
            VALU_LT: next_result = bf_out[WIDTH] ? operand2 : operand1;
            default: next_result = 0;
        endcase
    end
end

endmodule