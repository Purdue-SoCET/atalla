`ifndef lfc_store_hit_seq_SV
`define lfc_store_hit_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_store_hit_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_store_hit_seq)
  
  localparam NUM_TESTS = 100;

  function new(string name = "lfc_store_hit_seq");
    super.new(name);
  endfunction

  virtual task body();
  logic [31:0] prev_addr;

  `uvm_info(get_type_name(), "lfc_load_hit_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TESTS; i++) begin // TODO: only getting ~5 hits of an expected 100 hits (maybe most of our addresses are invalid?)
	    lfc_cpu_transaction req;
	    lfc_cpu_transaction re_req;
            
	    req = lfc_cpu_transaction #()::type_id::create("req");
            re_req = lfc_cpu_transaction #()::type_id::create("re_req");
	    
            // initial write (miss)
	    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

	    start_item(req);
	      req.randomize();
	      req.n_rst              = 1'b1;
	      req.mem_in_rw_mode     = 1'b1; // 1 = write
	      req.dp_in_halt         = 1'b0;
	      prev_addr = req.mem_in_addr;

	      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
	       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	    finish_item(req);
	    
	    // secondary write (hit)
	    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

	    start_item(re_req);
	      re_req.randomize();
	      re_req.n_rst              = 1'b1;
	      re_req.mem_in_rw_mode     = 1'b1; // 1 = write
	      re_req.dp_in_halt         = 1'b0;
	      re_req.mem_in_addr = prev_addr; // use previous address to ensure hit

	      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
	       	        re_req.mem_in_addr, re_req.mem_in_store_value), UVM_LOW)
	    finish_item(re_req);
  end
  endtask
endclass

`endif // lfc_store_hit_seq_SV
