import sys_arr_pkg::*;

module TPU_mul_cell #(
    localparam int ACC_WIDTH = IS_FP16 ? DW : DW_ACC
)(
    input logic clk, nRST,
    input logic [DW-1:0] in,
    input logic weight_en,
    output logic [ACC_WIDTH-1:0] result
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
            .stall(1'b0),
            .result(result),
            .done()
        );
    end
    else begin: bf16_multiplier
            mul_bf u_mul_cell (
                .clk(clk),
                .nRST(nRST),
                .start(1'b1),
                .a(in),
                .b(weight),
                .result(result),
                .done(),
                .mul_ovf(),
                .mul_unf()
            );
    end
endgenerate

endmodule