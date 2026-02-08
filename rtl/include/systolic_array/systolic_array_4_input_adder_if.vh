`ifndef SYSTOLIC_ARRAY_4_INPUT_ADDER_IF_VH
`define SYSTOLIC_ARRAY_4_INPUT_ADDER_IF_VH

interface systolic_array_4_input_adder_if #(
    parameter EXPONENT_SIZE = 5, //5 for FP16, 8 for BF16
    parameter MANTISSA_SIZE = 10 //10 for FP16, 7 for BF16
    parameter PRECISION_BITS = 3 
);
    localparam WIDTH = MANTISSA_SIZE + EXPONENT_SIZE + 1;

    logic [WIDTH - 1:0] a, b, c, d, out;

  modport add(
    input  a, b, c, d, 
    output out
  );
endinterface

`endif