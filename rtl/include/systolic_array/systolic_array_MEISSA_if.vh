`ifndef SYSTOLIC_ARRAY_MEISSA_IF_VH
`define SYSTOLIC_ARRAY_MEISSA_IF_VH

`include "sys_arr_pkg.vh"
`include "vector_pkg.vh"

interface systolic_array_MEISSA_if;
  import vector_pkg::*;
  import sys_arr_pkg::*;

  ////////////////////////////////////////////////////////////////////////////
  /////////////////////////////// Signals ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

    // To multipliers
    vreg_t        sa_array_in;          // input data to systolic array
    // vreg_t        sa_array_in_partials; // partial sum inputs
    logic         sa_input_en;          // enable data input
    logic         sa_weight_en;         // enable weight load
    // logic         sa_partial_en;        // enable partial sum load
    // logic         sa_output_ready;       // ready to accept output data

    // From multipliers
    logic [DW-1:0] mul_prod [N-1:0][N-1:0];      // output data
    // logic         sa_out_valid;            // output valid flag
    // logic         sa_fifo_has_space;    // to send activations

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////// Modports ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

    // Multipliers
    modport mul_grid (
        input  sa_array_in, sa_input_en, sa_weight_en,
        output mul_prod //sa_array_output, sa_out_valid, sa_fifo_has_space
    );
  
endinterface
`endif