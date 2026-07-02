/*
  Nikhil Vaidyanath - nvaidyan@purdue.edu
  Vector Core Shifting Unit Interface
*/

`ifndef SHIFTING_UNIT_IF_VH
`define SHIFTING_UNIT_IF_VH

`include "vector_pkg.vh"
`include "shifting_unit_pkg.vh"

interface shifting_unit_if;
  import vector_pkg::*;
  import shifting_unit_pkg::*;

  // Struct instances
  shifting_unit_inputs_t  inputs;
  shifting_unit_outputs_t outputs;

  // Individual signals for direct access
  vreg_t                              veg_vdata;
  shift_direction_t                   direction;
  logic [$clog2(NUM_ELEMENTS)-1:0]    shift_amount;
  logic                               valid_in;
  logic                               ready_in;
  vreg_t                              shifted_vdata;
  logic                               ready_out;
  logic                               valid_out;

  // Connect individual signals to struct members
  always_comb begin
    // Pack individual signals into input struct
    inputs.veg_vdata     = veg_vdata;
    inputs.direction     = direction;
    inputs.shift_amount  = shift_amount;
    inputs.valid_in   = valid_in;
    inputs.ready_in  = ready_in;
    
    // Unpack output struct into individual signals
    shifted_vdata = outputs.shifted_vdata;
    ready_out   = outputs.ready_out;
    valid_out  = outputs.valid_out;
  end

  // Constants for backward compatibility with testbench
  //localparam shift_direction_t LEFT = SHIFT_LEFT;
  //localparam shift_direction_t RIGHT = SHIFT_RIGHT;

  modport shift_u (
    input  veg_vdata, direction, shift_amount, valid_in, ready_in, inputs,
    output shifted_vdata, ready_out, valid_out, outputs
  );
endinterface
`endif // SHIFTING_UNIT_IF_VH