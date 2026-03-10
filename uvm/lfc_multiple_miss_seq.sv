`ifndef lfc_multiple_miss_seq_SV
`define lfc_multiple_miss_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

`include "../src/include/cache_types_pkg.svh"

class lfc_multiple_miss_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_multiple_miss_seq)

  localparam int NUM_TESTS = 100;

  function new(string name = "lfc_multiple_miss_seq");
    super.new(name);
  endfunction
  
  virtual task body();
  lfc_cpu_transaction req;

  `uvm_info(get_type_name(), "lfc_multiple_miss_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TESTS; i++) begin
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	req.randomize();
	req.n_rst = 1'b1;
	req.dp_in_halt = 0;
	if(req.mem_in_rw_mode == 1'b1) begin
		`uvm_info(get_type_name(), "Sending Write transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	end else begin
		`uvm_info(get_type_name(), "Sending Read transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	       	        req.mem_in_addr), UVM_LOW)
	end
	finish_item(req);
  end
  endtask
endclass

`endif // lfc_multiple_miss_seq_SV
