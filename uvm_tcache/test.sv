import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_environment.sv"

`include "sequences/tc_basic_sequence.sv"

class test extends uvm_test;
    `uvm_component_utils(test)

    tc_environment env;
    virtual tc_if vif;

    tc_basic_sequence basic_seq;

    function new(string name = "test", uvm_component parent);
        super.new(name, parent);
        $display("in test constructor!");
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        $display("in test build_phase!");
        `uvm_info("Test", "Build Phase", UVM_LOW)

        env = tc_environment::type_id::create("env", this);
        basic_seq = tc_basic_sequence::type_id::create("basic_seq", this);

        // Retrieve and send interface down
        if (!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
            `uvm_fatal("Test", "No virtual interface for this test")
        end
        uvm_config_db#(virtual tc_if)::set(this, "env.tmu_active_agent.*", "tc_vif", vif);
    endfunction

    task run_phase(uvm_phase phase);
        $display("in test run_phase!");
        // uvm_root::set_timeout(2000ns, 1);
        phase.raise_objection(this, "Starting sequence in main phase");
        
        `uvm_info("Test", "basic_seq starting", UVM_MEDIUM)
        basic_seq.start(env.tmu_active_agent.sqr);
        `uvm_info("Test", "basic_seq ended", UVM_MEDIUM)

        #5000;

        phase.drop_objection(this, "Finished in main phase");
    endtask

endclass
