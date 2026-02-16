class lane_sequence extends uvm_sequence #(lane_txn);
  `uvm_object_utils(lane_sequence)

  function new(string name = "lane_sequence");
    super.new(name);
  endfunction

  task body();
    lane_txn txn;

    txn = lane_txn::type_id::create("txn");
    start_item(txn);
    assert(txn.randomize());
    finish_item(txn);

  endtask

endclass