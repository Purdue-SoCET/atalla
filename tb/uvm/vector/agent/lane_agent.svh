class lane_agent extends uvm_agent;

  `uvm_component_utils(lane_agent)

  lane_driver    driver;
  lane_monitor   monitor;
  lane_sequencer sequencer;

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    driver    = lane_driver::type_id::create("driver", this);
    monitor   = lane_monitor::type_id::create("monitor", this);
    sequencer = lane_sequencer::type_id::create("sequencer", this);

  endfunction

  function void connect_phase(uvm_phase phase);
    driver.seq_item_port.connect(sequencer.seq_item_export);
  endfunction

endclass