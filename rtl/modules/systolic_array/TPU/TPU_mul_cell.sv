import sys_arr_pkg::*;

module TPU_mul_cell #(
    parameter IS_FP16 = 1
)(
    input logic clk, nRST,
    input logic [DW-1:0] in,
    input logic weight_en,
    output logic [DW-1:0] result
);

logic [DW-1:0] weight;

always_ff@(posedge clk, negedge nRST) begin : weight_register
    if (!nRST) begin
        weight <= '0;
    end
    else begin
        if (weight_en) begin
            weight <= in;
        end
    end
end

generate
    genvar i;
    if(IS_FP16) begin: fp16_multiplier
        mul_fp16 u_mul_fp16 (
            .clk(clk),
            .nRST(nRST),
            .start(1'b1),
            .a(in),
            .b(weight),
            .result(result)
        );
    end
    else begin: bf16_multiplier
        mul_bf16 u_mul_bf16 (
            .clk(clk),
            .nRST(nRST),
            .start(1'b1),
            .a(in),
            .b(weight),
            .result(result)
        );
    end
endgenerate

endmodule