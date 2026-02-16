class lane_sequencer extends uvm_sequencer #(lane_txn);
  `uvm_component_utils(lane_sequencer)

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

endclass