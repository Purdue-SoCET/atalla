/*
  Saandiya, Myles, Nikhil
  mohan76@purdue.edu, mquerimi@purdue.edu, nvaidyan@purdue.edu

  GSAU Interface V1
*/

`ifndef GSAU_CONTROL_UNIT_IF_VH
`define GSAU_CONTROL_UNIT_IF_VH

`include "sys_arr_pkg.vh"
`include "vector_pkg.vh"

interface gsau_control_unit_if;
  import vector_pkg::*;   // reuse basic typedefs (data, addr, etc.)
  import sys_arr_pkg::*;  // systolic-specific typedefs

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////// Types ///////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////


  ////////////////////////////////////////////////////////////////////////////
  /////////////////////////////// Signals ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

    // VEGGIE FILE
    // From Veggie File to GSAU
    vreg_t        veg_vdata1;         // [512 bits] vector data vs1
    vreg_t        veg_vdata2;         // [512 bits] vector data vs2
    //logic         veg_valid_in;         // indicates vdata valid

    // From GSAU to Veggie File
    //logic         veg_ready_out;        // indicates ready for value

    // SCHEDULER 
    // From GSAU to Scheduler
    logic         sb_ready_out;         // ready to accept next instruction
    //logic         sb_valid_out;         // valid output for GSAU -> sb 
  
    // From Scheduler to GSAU
    logic [7:0]   sb_vdst;         // next destination reg
    logic         sb_valid_in;       // next scoreboard valid
    // logic         sb_ready_in;       // ready for next scoreboard sb -> GSAU
    logic         sb_weight;        // 1 bit signal for weight indication

    // WB BUFFER
    // From GSAU to WB Buffer
    vreg_t        wb_psum;          // partial sum output
    logic [7:0]   wb_wbdst;         // destination vector register for writeback
    //logic wb_valid;
    //logic         wb_ready_out;  // WB buffer ready to accept data GSAU -> wb
    logic         wb_valid_out;

    // From WB Buffer to GSAU
    //logic         wb_output_ready;  // WB buffer ready to accept data
    //logic         wb_valid_in;      // valid signal for psum output wb -> GSAU
    logic         wb_ready_in;


    // SYSTOLIC ARRAY 
    // GSAU To Systolic Array
    logic [(N * DW) - 1:0] sa_array_in;          // input data to systolic array
    logic [(N * DW) - 1:0] sa_array_in_partials; // partial sum inputs
    logic         sa_input_en;          // enable data input
    logic         sa_weight_en;         // enable weight load
    logic         sa_partial_en;        // enable partial sum load
    // logic         sa_output_ready;       // ready to accept output data
    logic         sa_ready_out;       // gsau ready to accept output data from SA (GSAU -> SA)
   // logic         sa_valid_out;       // gsau have valid data to SA (new) - not needed we have enable signals

    // From Systolic Array to GSAU
    logic [(N * DW) - 1:0] sa_array_output;      // output data
    //logic         sa_out_valid;         // output valid flag
    logic         sa_valid_in;         // output valid flag SA -> GSAU, i have valid output from SA
    logic         sa_ready_in;          // SA ready to accept data from GSAU (new)
    //logic         sa_fifo_has_space;    // to send activations

  ////////////////////////////////////////////////////////////////////////////
  ////////////////////////////// Modports ////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////

    //GSAU 
    modport gsau (
        // From Veggie File
        input  veg_vdata1, veg_vdata2,
        //output veg_ready_out,

        // Scheduler handshake (inputs from scheduler)
        input  sb_vdst, sb_valid_in, sb_weight,

        // From WB buffer
        input  wb_ready_in,

        // From Systolic Array
        input  sa_array_output, sa_valid_in, sa_ready_in,

        // Outputs from GSAU
        output wb_psum, wb_wbdst, wb_valid_out,
        output sb_ready_out, 
        output sa_array_in, sa_array_in_partials, sa_input_en, sa_weight_en, sa_partial_en, sa_ready_out
    );

    //Veggie File
    modport veggie (
        output veg_vdata1, veg_vdata2
        //input  veg_ready_out
    );

    //Scheduler
    modport scheduler (
        input  sb_ready_out,
        output sb_vdst, sb_valid_in, sb_weight
    );

    //WB Buffer
    modport wb_buffer (
        input  wb_psum, wb_wbdst, wb_valid_out,
        output wb_ready_in
    );

    //Systolic Array
    modport systolic_array (
        input  sa_array_in, sa_array_in_partials, sa_input_en, sa_weight_en, sa_partial_en, sa_ready_out,
        output sa_array_output, sa_valid_in, sa_ready_in
    );
  
endinterface
`endif