`ifndef V_WB_ARBITER_IF
`define V_WB_ARBITER_IF

`include "vector_pkg.vh"

interface v_wb_arbiter_if;
  import vector_pkg::*;

  // Top level signals
  logic CLK, nRST;

  //Input Signals (From result collector and others (VLSU, Reduction GSAU))
  vector_out_t vector_out;
  // DETAILS
  // todo will NEED TO ADD VLSU!!

  // typedef struct packed {
  //       // Lane Outputs (post Result Collector)
  //       vreg_t [LANE_FU_COUNT-1:0] result;
  //       logic  [LANE_FU_COUNT-1:0] valid_o;   // to WB Buffer
  //       logic  [LANE_FU_COUNT-1:0] ready_o;   // to SB
  //       vsel_t [LANE_FU_COUNT-1:0] vd;

  //       // Reduction Outputs
  //       vreg_t                     reduction_result;
  //       logic                      reduction_valid;
  //       vsel_t                     reduction_vd;

  //       // GSAU
  //       gsau_out_t                 gsau;
  //   } vector_out_t;

  // Output Signals (to veggie x4) 
  // TODO CHECK VEGGIE inputs to determine if i need to se write high or handshake with veggie
  veggie_in_t veggie_in;
  veggie_out_t veggie_out;
  // DETAILS
  // typedef struct packed {
        // VDATA Writes
    //     vsel_t [WRITE_PORTS-1:0] vd;
    //     vreg_t [WRITE_PORTS-1:0] vdata;
    //     logic  [WRITE_PORTS-1:0] WEN;

    //     // VDATA Reads
    //     vsel_t [READ_PORTS-1:0] vs;
    //     logic  [READ_PORTS-1:0] REN;

    //     // MASK Reads/Writes
    //     mask_sel_t [MASK_BANK_COUNT-1:0] vmd; 
    //     vmask_t    [MASK_BANK_COUNT-1:0] mvdata;
    //     logic      [MASK_BANK_COUNT-1:0] MWEN; // mask write enable

    //     // VMASK Reads
    //     mask_sel_t [MASK_BANK_COUNT-1:0] vms;
    //     logic      [MASK_BANK_COUNT-1:0] MREN; // mask read enable
    // } veggie_in_t;

  modport v_wb_arbiter_if (
    // input CLK, nRST,
    input vector_out,
    output veggie_in,
    output veggie_out
  );

endinterface

`endif