`ifndef SYSTOLIC_ARRAY_TB_PKG_SV
`define SYSTOLIC_ARRAY_TB_PKG_SV

package systolic_array_tb_pkg;

    import uvm_pkg::*;
    `include "uvm_macros.svh"

    `include "systolic_array_transaction.svh"
    `include "systolic_array_sequence.svh"
    `include "systolic_array_sequencer.svh"
    `include "systolic_array_driver.svh"
    `include "systolic_array_monitor.svh"
    `include "systolic_array_predictor.svh"
    `include "systolic_array_scoreboard.svh"
    `include "systolic_array_agent.svh"
    `include "systolic_array_env.svh"
    `include "systolic_array_base_test.svh"
endpackage

`endif