/*
  Eric Villasenor
  evillase@gmail.com

  register file interface
*/
`ifndef REGISTER_FILE_IF_VH
`define REGISTER_FILE_IF_VH

// all types
`include "cpu_types_pkg.vh"

interface register_file_if;
  // import types
  import cpu_types_pkg::*;

  logic     WEN;
  regbits_t wsel, rsel1, rsel2;
  word_t    wdat, rdat1, rdat2;

  // register file ports
  modport rf (
    input   WEN, wsel, rsel1, rsel2, wdat,
    output  rdat1, rdat2
  );
  // register file tb
  modport tb (
    input   rdat1, rdat2,
    output  WEN, wsel, rsel1, rsel2, wdat
  );
endinterface

`endif //REGISTER_FILE_IF_VH