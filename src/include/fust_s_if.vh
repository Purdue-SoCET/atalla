`ifndef FUST_S_IF_VH
`define FUST_S_IF_VH
`include "datapath_types.vh"

interface fust_s_if;
  import datapath_pkg::*;

  // Inputs from dispatch
  logic en;
  fu_s_t fu;
  fust_s_t n_fust;

  // Outputs of stage
  fust_s_t fust;
    
  modport FUSTS (
      input en, fu, n_fust,
      output fust
  );

endinterface
`endif
