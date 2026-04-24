// Each FU have its own modport or interface??
`ifndef VECTOR_IF_VH
`define VECTOR_IF_VH

`include "vector_pkg.vh"

interface vector_if;
  import vector_pkg::*;

  //schedular to gsau
  vector_if_gsau_in_t gsau_in;
  //gasu to writeback
  vector_if_gsau_out_t gsau_out;

  //schedular to vlsu
  vector_if_vlsu_in_t vlsu_in;
  //vlsu to writeback
  vector_if_vlsu_out_t vlsu_out;

  //schedular to lanes
  vector_if_lanes_in_t lanes_in;
  //lanes to writeback
  vector_if_lanes_out_t lanes_out;

  //traspose
  vtransp_in_t transpose_in;
  vtransp_out_t transpose_out;
  

  //unit ready and wb ready
  vector_if_unit_ready_t unit_ready_signals;
  vector_if_wb_ready_t wb_ready_signals;

  modport gsau (
    input gsau_in,
    output gsau_out
  );

  modport vlsu (
    input vlsu_in,
    output vlsu_out
  );

  modport lanes (
    input lanes_in,
    output lanes_out
  );

  modport transpose (
    input transpose_in,
    output transpose_out
  );

  modport vif (
    input gsau_in,
    input vlsu_in,
    input lanes_in,
    input transpose_in,
    output unit_ready_signals,
    output gsau_out,
    output vlsu_out,
    output lanes_out,
    output transpose_out,
    input wb_ready_signals
  );

  modport schedular (
    input gsau_in,
    input vlsu_in,
    input lanes_in,
    input unit_ready_signals
  );

  modport writeback (
    output gsau_out,
    output vlsu_out,
    output lanes_out,
    output wb_ready_signals
  );



endinterface

`endif
