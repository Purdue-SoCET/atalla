`ifndef FUST_G_IF_VH
`define FUST_G_IF_VH
`include "datapath_types.vh"

interface fust_g_if;
  import datapath_pkg::*;

  // Inputs from dispatch
  logic en;
  //logic fu; //dont need op idx with 1 row in FUST
  fust_g_t n_fust;

  // Outputs of stage
  fust_g_t fust;
    
  modport FUSTG (
      input en, fu, n_fust,
      output fust
  );

endinterface
`endif
