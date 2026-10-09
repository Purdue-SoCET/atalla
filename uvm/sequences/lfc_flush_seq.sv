`ifndef lfc_flush_seq_SV
`define lfc_flush_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_flush_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_flush_seq)

  function new(string name = "lfc_flush_seq");
    super.new(name);
  endfunction
  
  virtual task body();
  lfc_cpu_transaction req;
  lfc_cpu_transaction req_read;
  lfc_cpu_transaction req_write;

  `uvm_info(get_type_name(), "lfc_flush_seq", UVM_MEDIUM)

    for(int i = 0; i < 5; i++) begin // load some data into the cache
	    //lfc_cpu_transaction req;
	    req = lfc_cpu_transaction #()::type_id::create("req");

	    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

	    start_item(req);
	      req.randomize();
	      req.n_rst              = 1'b1;
	      req.mem_in_rw_mode     = 1'b1; // 1 = write
	      req.dp_in_halt         = 1'b0;

	      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
	       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	    finish_item(req);
    end

    // send halt signal
    //lfc_cpu_transaction req;
    req = lfc_cpu_transaction #()::type_id::create("req");

    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

    start_item(req);
      req.randomize();
      req.n_rst              = 1'b1;
      req.mem_in_rw_mode     = 1'b1; // 1 = write
      req.dp_in_halt         = 1'b1;

      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
    finish_item(req);

    // attempt a read
    //lfc_cpu_transaction req_read;
    req_read = lfc_cpu_transaction #()::type_id::create("req_read");

    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)

    start_item(req_read);
      req_read.randomize();
      req_read.n_rst              = 1'b1;
      req_read.mem_in_rw_mode     = 1'b0; // 1 = write
      req_read.mem_in_store_value = 32'hCAFEBABE; // doesn't matter for read
      req_read.dp_in_halt         = 1'b0;

      `uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
       	        req_read.mem_in_addr), UVM_LOW)
    finish_item(req_read);

    // attempt a write
    //lfc_cpu_transaction req_write;
    req_write = lfc_cpu_transaction #()::type_id::create("req_write");

    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

    start_item(req_write);
      req_write.randomize();
      req_write.n_rst              = 1'b1;
      req_write.mem_in_rw_mode     = 1'b1; // 1 = write
      req_write.dp_in_halt         = 1'b0;

      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req_write.mem_in_addr, req_write.mem_in_store_value), UVM_LOW)
    finish_item(req_write);

  endtask
endclass

`endif // lfc_flush_seq_SV
