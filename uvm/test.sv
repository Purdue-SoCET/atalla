import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_environment.sv"
`include "lfc_basic_sequence.sv"
`include "lfc_wr_sequence.sv"

class test extends uvm_test;
    `uvm_component_utils(test)

    lfc_environment env;
    virtual lfc_if vif;
    lfc_basic_sequence basic_seq;
    lfc_wr_sequence wr_seq;

    function new(string name = "test", uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        `uvm_info("Test", "Build Phase", UVM_LOW)

        env = lfc_environment::type_id::create("env", this);
        basic_seq = lfc_basic_sequence::type_id::create("basic_seq", this);
        wr_seq = lfc_wr_sequence::type_id::create("wr_seq", this);

        // Retrieve and send interface down
        if (!uvm_config_db#(virtual lfc_if)::get(this, "", "lfc_vif", vif)) begin
            `uvm_fatal("Test", "No virtual interface for this test")
        end
        uvm_config_db#(virtual lfc_if)::set(this, "env.cpu_active_ag.*", "lfc_if", vif);

        super.build_phase(phase);
    endfunction

    task run_phase(uvm_phase phase);
        phase.raise_objection(this, "Starting sequence in main phase");
        $display("%t Starting sequence run_phase", $time);
        //basic_seq.start(env.cpu_active_agent.sqr);
        //#100ns;
        wr_seq.start(env.cpu_active_agent.sqr);
        #100ns;
        phase.drop_objection(this, "Finished in main phase");
    endtask

endclass
