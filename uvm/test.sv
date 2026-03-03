import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_environment.sv"
`include "lfc_basic_sequence.sv"
`include "lfc_wr_sequence.sv"

`include "lfc_load_hit_seq.sv"
`include "lfc_load_miss_seq.sv"

`include "lfc_miss_coalesce_seq.sv"
`include "lfc_MSHR_overflow_seq.sv"
`include "lfc_multiple_miss_seq.sv"
`include "lfc_store_hit_seq.sv"


class test extends uvm_test;
    `uvm_component_utils(test)

    localparam NUM_BANKS = 4;

    lfc_environment env;
    virtual lfc_if vif;
    lfc_basic_sequence basic_seq;
    lfc_wr_sequence wr_seq;

    lfc_store_hit_seq store_hit_seq;
    lfc_miss_coalesce_seq miss_coal;
    lfc_MSHR_overflow_seq mshr_overflow_seq;
    lfc_multiple_miss_seq multiple_miss_seq;

    lfc_load_hit_seq load_hit;
    lfc_load_miss_seq load_miss;

    function new(string name = "test", uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        `uvm_info("Test", "Build Phase", UVM_LOW)

        env = lfc_environment#(.NUM_BANKS(NUM_BANKS))::type_id::create("env", this);
        basic_seq = lfc_basic_sequence::type_id::create("basic_seq", this);
        wr_seq = lfc_wr_sequence::type_id::create("wr_seq", this);

        load_hit = lfc_load_hit_seq::type_id::create("load_hit", this);
        load_miss = lfc_load_miss_seq::type_id::create("load_miss", this);
        miss_coal = lfc_miss_coalesce_seq::type_id::create("miss_coal", this);
        mshr_overflow_seq = lfc_MSHR_overflow_seq::type_id::create("mshr_overflow_seq", this);
        multiple_miss_seq = lfc_multiple_miss_seq::type_id::create("multiple_miss_seq", this);
        store_hit_seq = lfc_store_hit_seq::type_id::create("store_hit_seq", this);

        // Retrieve and send interface down
        if (!uvm_config_db#(virtual lfc_if)::get(this, "", "lfc_vif", vif)) begin
            `uvm_fatal("Test", "No virtual interface for this test")
        end
        uvm_config_db#(virtual lfc_if)::set(this, "env.cpu_active_agent.*", "lfc_vif", vif);
    endfunction

    task run_phase(uvm_phase phase);
        // uvm_root::set_timeout(2000ns, 1);
        phase.raise_objection(this, "Starting sequence in main phase");
        $display("%t Starting sequence run_phase", $time);
        //basic_seq.start(env.cpu_active_agent.sqr);
        //#1000ns;
        //load_hit.start(env.cpu_active_agent.sqr);
        //#1000ns;
        load_miss.start(env.cpu_active_agent.sqr);
        #1000ns;
        // miss_coal.start(env.cpu_active_agent.sqr);
        // #1000ns;
        // mshr_overflow_seq.start(env.cpu_active_agent.sqr);
        // #1000ns;
        //multiple_miss_seq.start(env.cpu_active_agent.sqr);
        //#1000ns;
        //store_hit_seq.start(env.cpu_active_agent.sqr);
        //#1000ns;
        // wr_seq.start(env.cpu_active_agent.sqr);
        // #1000ns;
        phase.drop_objection(this, "Finished in main phase");
    endtask

endclass
