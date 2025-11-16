`ifndef DIV_IF_VH
`define DIV_IF_VH

interface div_if #(
  parameter int EXP_WIDTH = 8,
  parameter int MANT_WIDTH = 7
);

  localparam int WIDTH = EXP_WIDTH + MANT_WIDTH;

  typedef struct packed {
    logic valid_in, ready_out;
    logic [WIDTH:0] operand1;
    logic [WIDTH:0] operand2;
  } div_in_t;

  typedef struct packed {
    logic valid_out, ready_in;
    logic [WIDTH:0] result;
  } div_out_t;

  div_in_t  in;
  div_out_t out;

  modport div (
    input  in,
    output out
  );

  modport tb (
    input  out,
    output in
  );

endinterface

`endif
