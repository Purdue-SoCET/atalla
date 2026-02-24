`ifndef V_WB_ARBITER_IF
`define V_WB_ARBITER_IF

`include "vector_pkg.vh"
//`include "scpad_pkg.sv"

interface v_wb_arbiter_if;
  import vector_pkg::*;

  // Top level signals
  logic CLK, nRST;

  //Vector outputs
  vector_if_gsau_out_t vector_if_gsau_out;
  vector_if_reduction_out_t vector_if_reduction_out;
  vector_if_lanes_out_t vector_if_lanes_out;
  vector_if_vlsu_out_t vector_if_vlsu_out; //Is this incomplete in the package??

  //Veggie interfaces
  veggie_out_t veggie_out;
  veggie_in_t veggie_in;
  
  //Vector ready interface (contains all ready signals)
  vector_if_wb_ready_t vector_if_wb_ready;

  modport v_wb_arbiter_if (
    // input CLK, nRST,

    //Outputs from vector functional units are inputs to the writeback stage
    input vector_if_gsau_out,
    input vector_if_reduction_out,
    input vector_if_lanes_out,
    input vector_if_vlsu_out,

    //Output from veggie is input to the writeback stage
    input veggie_out,

    output veggie_in, //Input to veggie
    output vector_if_wb_ready //Input to all FUs of Vcore
  );

endinterface

`endif
