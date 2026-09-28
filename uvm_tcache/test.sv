import uvm_pkg::*;
`include "uvm_macros.svh"
`include "tc_environment.sv"

class test extends uvm_test;
    `uvm_component_utils(test)

    tc_environment env;
    virtual tc_if vif;

    function new(string name = "test", uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        `uvm_info("Test", "Build Phase", UVM_LOW)

        env = tc_environment::type_id::create("env", this);

        // Retrieve and send interface down
        if (!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
            `uvm_fatal("Test", "No virtual interface for this test")
        end
        uvm_config_db#(virtual tc_if)::set(this, "env.tmu_active_agent.*", "tc_vif", vif);
    endfunction

    task run_phase(uvm_phase phase);
        // uvm_root::set_timeout(2000ns, 1);
        phase.raise_objection(this, "Starting sequence in main phase");
        phase.drop_objection(this, "Finished in main phase");
    endtask

endclass
