class lane_txn extends uvm_sequence_item;

  rand bit [15:0] operand1;
  rand bit [15:0] operand2;
  rand bit [3:0]  fu_select;  // which FU (MUL, DIV, VALU, SQRT)
  rand bit        valid;

  `uvm_object_utils_begin(lane_txn)
    `uvm_field_int(operand1, UVM_ALL_ON)
    `uvm_field_int(operand2, UVM_ALL_ON)
    `uvm_field_int(fu_select, UVM_ALL_ON)
    `uvm_field_int(valid,    UVM_ALL_ON)
  `uvm_object_utils_end

  function new(string name="lane_txn");
    super.new(name);
  endfunction

endclass