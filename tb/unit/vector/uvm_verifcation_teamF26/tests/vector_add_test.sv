
class vector_add_test extends vector_base_test;
    `uvm_component_utils(vector_add_test)

    // Constructor
    function new(string name = "vector_add_test",
                 uvm_component parent = null);
        super.new(name, parent);
    endfunction

    // Run phase
    task run_phase(uvm_phase phase);

        lane_add_sequence add_seq;

        // Prevent UVM from ending the test early
        phase.raise_objection(this);

        // Create ADD sequence using UVM factory
        add_seq = lane_add_sequence::type_id::create("add_seq");

        `uvm_info("VECTOR_ADD_TEST", "Starting vector ADD sequence", UVM_MEDIUM)

        // Start sequence on lane agent sequencer
        add_seq.start(env.lane_agt.sequencer);

        `uvm_info("VECTOR_ADD_TEST", "ADD sequence completed", UVM_MEDIUM)

        // Allow UVM to finish
        phase.drop_objection(this);
    endtask

endclass
