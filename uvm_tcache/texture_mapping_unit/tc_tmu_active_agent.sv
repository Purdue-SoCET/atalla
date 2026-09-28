`ifndef TC_TMU_ACTIVE_AGENT_SV
`define TC_TMU_ACTIVE_AGENT_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_tmu_active_driver.sv"
`include "tc_tmu_active_monitor.sv"
`include "tc_tmu_active_sqr.sv"

class tc_tmu_active_agent extends uvm_agent;
    `uvm_component_utils(tc_tmu_active_agent)
    tc_tmu_active_sqr sqr;
    tc_tmu_active_driver drv;
    tc_tmu_active_monitor mon;

    function new(string name, uvm_component parent = null);
        super.new(name, parent);
    endfunction

    virtual function void build_phase(uvm_phase phase);
        sqr = tc_tmu_active_sqr::type_id::create("sqr", this);
        drv = tc_tmu_active_driver::type_id::create("drv", this);
        mon = tc_tmu_active_monitor::type_id::create("mon", this);
    endfunction

    virtual function void connect_phase(uvm_phase phase);
        drv.seq_item_port.connect(sqr.seq_item_export);
    endfunction

endclass

`endif
