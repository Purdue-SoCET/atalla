`ifndef SYSTOLIC_ARRAY_TEST_SVH
`define SYSTOLIC_ARRAY_TEST_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_test extends uvm_test;
    `uvm_component_param_utils(systolic_array_test #(N, WIDTH))

    int N = 4;
    int WIDTH = 16;

    systolic_array_env #(4, 16) env;

    function new(string name = "systolic_array_test", uvm_component parent = null);
        super.new(name, parent);
    endfunction

    virtual function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = systolic_array_env #(N, WIDTH)::type_id::create("env", this);
    endfunction

    virtual task run_phase(uvm_phase phase);
        systolic_array_sequence #(N, WIDTH) seq;
        phase.raise_objection(this);

        seq = systolic_array_sequence #(N, WIDTH)::type_id::create("seq");
        `uvm_info("Test", "Starting sequence", UVM_LOW)

        seq.start(env.agent.sequencer);
        `uvm_info("Test", "Sequence complete", UVM_LOW)
        phase.drop_objection(this);
    endtask

endclass
`endif