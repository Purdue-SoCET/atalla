`ifndef TRANSPOSE_UNIT_IF_SV
`define TRANSPOSE_UNIT_IF_SV

interface transpose_unit_if #(
    parameter int VEC_LEN = 32, 
    parameter int DATA_W  = 16
);

  typedef struct packed {
    logic valid_in, ready_in, push_req, pop_req;
    logic [VEC_LEN-1:0][DATA_W-1:0] vec_in;
  } vtransp_in_t;

  typedef struct packed {
    logic valid_out, ready_out;
    logic [VEC_LEN-1:0][DATA_W-1:0] vec_out;
  } vtransp_out_t;

  vtransp_in_t in;
  vtransp_out_t out;

  modport transpose (
    input  in,
    output out
  );

  modport tb (
    input out, 
    output in
  );

endinterface

`endif