`ifndef RECIPROCAL_IF_VH
`define RECIPROCAL_IF_VH

interface reciprocal_if #(
  parameter int EXP_WIDTH = 8,
  parameter int MANT_WIDTH = 7
);

  localparam int WIDTH = EXP_WIDTH + MANT_WIDTH;

  typedef struct packed {
    logic valid_in, ready_in;
    logic [WIDTH:0] divisor;
  } div_in_t;

  typedef struct packed {
    logic valid_out, ready_out;
    logic [WIDTH:0] result;
  } div_out_t;

  div_in_t  in;
  div_out_t out;

  modport rif (
    input  in,
    output out
  );

endinterface

`endif