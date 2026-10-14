`ifndef TC_BASIC_SEQUENCE_SV
`define TC_BASIC_SEQUENCE_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../texture_mapping_unit/tc_tmu_transaction.sv"

class tc_basic_sequence extends uvm_sequence#(tc_tmu_transaction);
  `uvm_object_utils(tc_basic_sequence)

  function new(string name = "tc_basic_sequence");
    super.new(name);
  endfunction

  virtual task body();
    tc_tmu_transaction req;
    
    `uvm_info(get_type_name(), "Starting basic READ sequence...", UVM_MEDIUM)

    req = tc_tmu_transaction::type_id::create("req");

    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)

    start_item(req);
      req.randomize();
      req.n_rst     = 1'b1;
      req.tmu_valid = 1'b1; 

    `uvm_info(get_type_name(),
      $sformatf("sending READ: base_addr = 0x%0h", req.base_addr),
      UVM_LOW)
    finish_item(req);

    `uvm_info(get_type_name(), "completed READ", UVM_LOW) 
  endtask
endclass

`endif // TC_BASIC_SEQUENCE_SV
