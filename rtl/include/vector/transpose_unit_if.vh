`ifndef TRANSPOSE_UNIT_IF_SV
`define TRANSPOSE_UNIT_IF_SV
`include "vector_pkg.vh"

interface transpose_unit_if #(
);
  import vector_pkg::*;

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