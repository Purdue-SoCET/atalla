
class lane_agent extends uvm_agent;

    `uvm_component_utils(lane_agent)

    lane_driver driver;
    lane_sequencer sequencer;

    function new(string name = "lane_agent",
                 uvm_component parent = null);
        super.new(name, parent);
    endfunction

    // Create UVM components
    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        driver = lane_driver::type_id::create("driver", this);
        sequencer = lane_sequencer::type_id::create("sequencer", this);
    endfunction

    // Connect driver to sequencer
    function void connect_phase(uvm_phase phase);
        super.connect_phase(phase);
        driver.seq_item_port.connect(sequencer.seq_item_export);
    endfunction

endclass
