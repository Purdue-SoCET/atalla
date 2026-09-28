`ifndef TC_TMU_ACTIVE_SQR_SV
`define TC_TMU_ACTIVE_SQR_SV

`include "uvm_macros.svh"
`include "tc_tmu_transaction.sv"

import uvm_pkg::*;

class tc_tmu_active_sqr extends uvm_sequencer#(tc_tmu_transaction);
    `uvm_component_utils(tc_tmu_active_sqr);

    function new(string name = "tc_tmu_active_sqr", uvm_component parent);
        super.new(name, parent);
        `uvm_info("TMU_SQR", "Constructor", UVM_HIGH)
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        `uvm_info("TMU_SQR", "Build Phase", UVM_HIGH)
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        `uvm_info("TMU_SQR", "Connect Phase", UVM_HIGH)
    endfunction

endclass

`endif
