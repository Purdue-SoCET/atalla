`ifndef TC_TMU_PASSIVE_AGENT_SV
`define TC_TMU_PASSIVE_AGENT_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_tmu_passive_monitor.sv"

class tc_tmu_passive_agent extends uvm_agent;
    `uvm_component_utils(tc_tmu_passive_agent)
    tc_tmu_passive_monitor mon;

    function new(string name, uvm_component parent = null);
        super.new(name, parent);
    endfunction

    virtual function void build_phase(uvm_phase phase);
        mon = tc_tmu_passive_monitor::type_id::create("mon", this);
    endfunction

endclass

`endif
