`include "sqrt_if.vh"

module sqrt_bf16_wrapper (
    input logic CLK,
    input logic nRST,
    input logic [15:0] sqrt_operand,
    input logic sqrt_valid_in,
    input logic sqrt_ready_out,
    output logic [15:0] sqrt_result,
    output logic sqrt_valid_out,
    output logic sqrt_ready_in
);
    
    sqrt_if srif();

    always_comb begin
        srif.in.operand = sqrt_operand;
        srif.in.valid_in = sqrt_valid_in;
        srif.in.ready_out = sqrt_ready_out;
        sqrt_result = srif.out.result;
        sqrt_valid_out = srif.out.valid_out;
        sqrt_ready_in = srif.out.ready_in;
    end

    sqrt_bf16 dut (
        .CLK(CLK),
        .nRST(nRST),
        .srif(srif)
    );

endmodule
