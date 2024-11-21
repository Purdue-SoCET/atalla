`ifndef SYSTOLIC_ARRAY_CONTROL_UNIT_IF_VH
`define SYSTOLIC_ARRAY_CONTROL_UNIT_IF_VH

interface systolic_array_control_unit_if;
  // Parameters
  parameter array_dim = 4;    //4x4 systolic array
  parameter data_w = 16;      //FP 16 for our implementation

  // Signals
  logic weight_en;        // Current input bus is for array weights
  logic input_en;         // Current input bus is for array inputs
  logic partial_en;       // Memory is sending partial sums
  logic fifo_has_space;   // FIFOS can load more inputs 
  logic input_type;       // Inputs are weights/inputs
  logic input_load;       // Load inputs into certain FIFOs
  logic weight_load;      // Load weights into certain row of MACS
  logic partials_load;    // Load partials into certain FIFOs
  logic start;           // Start signals for all MACs
  logic count;           // Count signals for all MACs
  logic [$clog2(array_dim)-1:0]input_row;          // Which FIFO to load input into
  logic [$clog2(array_dim)-1:0]weight_row;         // Which MAC row to load weights into
  logic [$clog2(array_dim)-1:0]partials_row;       // Which FIFO to load partials into
  logic [$clog2(array_dim)-1:0] row_en;            // Row enable for inputs/weights & partial sums
  logic [$clog2(array_dim)-1:0] row_out;           // Which row the systolic array is outputing

  // Control Unit Ports
  modport control_unit(
    input  weight_en, input_en, partial_en, row_en, array_in, array_in_partials,
    output drained, fifo_has_space, row_out, array_output
  );
endinterface

`endif