`ifndef LFC_BASIC_SEQUENCE_SV
`define LFC_BASIC_SEQUENCE_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"


class lfc_basic_sequence extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_basic_sequence)

  function new(string name = "lfc_basic_sequence");
    super.new(name);
  endfunction

  virtual task body();
    lfc_cpu_transaction req;
    `uvm_info(get_type_name(), "Starting lfc_basic_sequence...", UVM_MEDIUM)

    req = lfc_cpu_transaction::type_id::create("req");

    req.n_rst             = 1'b1; //added
    req.mem_in_addr       = 32'h1000;
    req.mem_in_rw_mode    = 1'b1;        // 1 = write, 0 = read
    req.mem_in_store_value= 32'hDEADBEEF;
    req.dp_in_halt        = 1'b0;

    start_item(req);
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("Completed: addr=0x%0h data=0x%0h", req.mem_in_addr, req.mem_in_store_value),
      UVM_LOW)
  endtask
endclass



`endif // LFC_BASIC_SEQUENCE_SV