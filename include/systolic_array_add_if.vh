`ifndef SYSTOLIC_ARRAY_ADD_IF_VH
`define SYSTOLIC_ARRAY_ADD_IF_VH

interface systolic_array_add_if #(parameter data_w = 16);
  // Parameters
  // parameter data_w = 16;      //FP 16 for our implementation

  // Signals
  logic start;          // MAC unit start signal
  logic count;          // Count for adder pipelined execution
  logic [data_w-1:0] add_input1;            // Input weight value to be pre-loaded
  logic [data_w-1:0] add_input2;          // Input value to be multiplied
  logic [data_w-1:0] add_ouput;     // Input accumulate value from above

  // add Port for Array
  modport add(
    input  start, count, add_input1, add_input2,
    output add_ouput
  );
endinterface

`endif