`ifndef SYSTOLIC_ARRAY_CONTROL_UNIT_IF_VH
`define SYSTOLIC_ARRAY_CONTROL_UNIT_IF_VH

interface systolic_array_control_unit_if #(parameter array_dim = 4, parameter data_w = 16);
  // Parameters
  // parameter array_dim = 4;    //4x4 systolic array
  // parameter data_w = 16;      //FP 16 for our implementation

  // Signals
  logic weight_en;        // Current input bus is for array weights
  logic input_en;         // Current input bus is for array inputs
  logic partial_en;       // Memory is sending partial sums
  logic fifo_has_space;   // FIFOS can load more inputs 
  logic input_type;       // Inputs are weights/inputs
  logic input_load;       // Load inputs into certain FIFOs
  logic weight_load;      // Load weights into certain row of MACS
  logic partials_load;    // Load partials into certain FIFOs
  logic MAC_start;           // Start signals for all MACs
  logic MAC_count;           // Count signals for all MACs
  logic add_start;           // Start signals for all partial sum adders
  logic add_count;           // Count signals for all partial sum adders
  logic [array_dim-1:0] fifo_enable;       // enable signal for FIFOS (MAC take 0 instead of fifo value)
  logic [array_dim-1:0] ps_fifo_enable;    // enable signal for partial sum FIFOS (add take 0 instead of fifo value)
  logic [array_dim-1:0] fifo_shift;       // Shift signal for FIFOS
  logic [array_dim-1:0] ps_fifo_shift;    // Shift signal for partial sum FIFOS
  logic [$clog2(array_dim):0] iteration_in;       // Which iteration is the inst inside the systolic array
  logic [$clog2(array_dim):0] iteration_out;      // Which iteration is the inst coming out of the systolic array
  logic [$clog2(array_dim)-1:0] input_row;          // Which FIFO to load input into
  logic [$clog2(array_dim)-1:0] weight_row;         // Whi ch MAC row to load weights into
  logic [$clog2(array_dim)-1:0] partials_row;       // Which FIFO to load partials into
  logic [$clog2(array_dim)-1:0] row_en;             // Row enable for inputs/weights & partial sums
  logic [$clog2(array_dim)-1:0] row_out;            // Which row the systolic array is outputing

  // Control Unit Ports
  modport control_unit(
    input  weight_en, input_en, partial_en, row_en,
    output fifo_has_space, fifo_enable, ps_fifo_enable, fifo_shift, ps_fifo_shift, iteration_in, iteration_out, input_type, input_load, input_row, weight_load, weight_row, partials_load, partials_row, row_out, MAC_start, MAC_count, add_start, add_count
  );
endinterface

`endif