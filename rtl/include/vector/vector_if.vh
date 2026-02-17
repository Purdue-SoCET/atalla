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

  //systolic array connection
  gsau_sys_in_t sysarr_in;
  gsau_sys_out_t sysarr_out;

  //schedular to vlsu
  vector_if_vlsu_in_t vlsu_in;
  //vlsu to writeback
  vector_if_vlsu_out_t vlsu_out;

  //scpad connection
  vlsu_sp_in_t sp_in;
  vlsu_sp_out_t sp_out

  //schedular to lanes
  vector_if_lanes_in_t lanes_in;
  //lanes to writeback
  vector_if_lanes_out_t lanes_out;

  modport gsau (
    input gsau_in,
    output gsau_out
  );

  modport sysarr (
    input sysarr_in,
    output sysarr_out
  );

  modport vlsu (
    input vlsu_in,
    output vlsu_out
  );

  modport scpad (
    input sp_in,
    output sp_out
  );

  modport lanes (
    input lanes_in,
    output lanes_out
  )

  modport vif (
    input gsau_in,
    input sysarr_in,
    input vlsu_in,
    input sp_in,
    input lanes_in,
    output gsau_out,
    output sysarr_out,
    output vlsu_out,
    output sp_out,
    output lanes_out
  );

endinterface

`endif
