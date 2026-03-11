`ifndef SYSTOLIC_ARRAY_n_INPUT_ADDER_IF_VH
`define SYSTOLIC_ARRAY_n_INPUT_ADDER_IF_VH

interface systolic_array_n_input_adder_if #(
    parameter NUM_INPUTS       = 4,  
    parameter MANTISSA_SIZE     = 23, // Input Mantissa Width
    parameter EXPONENT_SIZE     = 8,
    parameter IN_MANTISSA_SIZE = 10, // Output Mantissa Width (New Parameter)
    parameter IN_EXPONENT_SIZE = 5,
    parameter PRECISION_BITS    = 0 
);
    localparam WIDTH = IN_MANTISSA_SIZE + IN_EXPONENT_SIZE + 1;
    localparam OUTPUT_WIDTH = MANTISSA_SIZE + EXPONENT_SIZE + 1;
    logic [WIDTH - 1:0] a, b, c, d;
    logic [OUTPUT_WIDTH - 1:0] out;

    modport add(
      input  a, b, c, d, 
      output out
    );
endinterface

`endif
