`ifndef lfc_load_hit_seq_SV
`define lfc_load_hit_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_load_hit_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_load_hit_seq)

  function new(string name = "lfc_load_hit_seq");
    super.new(name);
  endfunction

  virtual task body();
    lfc_cpu_transaction req;
    
    logic [31:0] saved_addr;
    logic [31:0] saved_data;

    `uvm_info(get_type_name(), "lfc_load_hit_seq", UVM_MEDIUM)

    req = lfc_cpu_transaction::type_id::create("req");

    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

    saved_addr = 32'h1000;
    saved_data = 32'hDEADBEEF;

    start_item(req);
      req.n_rst              = 1'b1;
      req.mem_in_addr        = saved_addr;
      req.mem_in_rw_mode     = 1'b1; // 1 = write
      req.mem_in_store_value = saved_data;
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("WRITE complete: addr=0x%0h data=0x%0h", saved_addr, saved_data),
      UVM_LOW)
    
    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)
    

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = saved_addr;
      req.mem_in_rw_mode     = 1'b0;
      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("READ request sent: addr=0x%0h", saved_addr),
      UVM_LOW)

  endtask
endclass

`endif // lfc_load_hit_seq_SV