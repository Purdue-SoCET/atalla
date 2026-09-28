`ifndef TC_MEM_ACTIVE_SQR_SV
`define TC_MEM_ACTIVE_SQR_SV

`include "uvm_macros.svh"
`include "tc_mem_transaction.sv"

import uvm_pkg::*;

class tc_mem_active_sqr extends uvm_sequencer#(tc_mem_transaction);
    `uvm_component_utils(tc_mem_active_sqr);

    function new(string name = "tc_mem_active_sqr", uvm_component parent);
        super.new(name, parent);
        `uvm_info("MEM_SQR", "Constructor", UVM_HIGH)
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        `uvm_info("MEM_SQR", "Build Phase", UVM_HIGH)
    endfunction

    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        `uvm_info("MEM_SQR", "Connect Phase", UVM_HIGH)
    endfunction

endclass

`endif
