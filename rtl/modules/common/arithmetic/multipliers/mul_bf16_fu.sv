// ------------------------------------------------------------
// mul_bf16_fu.sv
// Ready-Valid wrapper around mul_bf16
// not paramaterizeable
// Owner: Jacob Walter
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "mul_if.vh"

module mul_bf16_fu (
    input  logic  CLK,
    input  logic  nRST,
    mul_if.mif    mif
);
    import vector_pkg::*;
    logic        mul_start;
    logic [15:0] mul_result;
    logic        mul_done;
    logic        mul_stall;

    logic [15:0] result_reg;
    logic        result_valid;

    assign mul_stall = result_valid && !mif.in.ready_out;
    assign mul_start = mif.in.valid_in && mif.out.ready_in;

    mul_bf16 mul (
        .clk   (CLK),
        .nRST  (nRST),
        .start (mul_start),
        .stall (mul_stall),
        .a     (mif.in.operand1),
        .b     (mif.in.operand2),
        .result(mul_result),
        .done  (mul_done)
    );

    

    // Output assignments
    assign mif.out.result    = result_reg;
    assign mif.out.valid_out = result_valid;
    assign mif.out.ready_in  = !(result_valid && !mif.in.ready_out);

    always_ff @(posedge CLK or negedge nRST) begin
        if (!nRST) begin
            result_reg   <= '0;
            result_valid <= 1'b0;
        end else begin
            if (mul_done && (result_valid && mif.in.ready_out)) begin
                result_reg   <= mul_result;
                result_valid <= 1'b1;
            end
            else if (mul_done) begin
                result_reg   <= mul_result;
                result_valid <= 1'b1;
            end
            else if (result_valid && mif.in.ready_out) begin
                result_valid <= 1'b0;
            end
        end
    end

endmodule