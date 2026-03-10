`ifndef lfc_load_hit_seq_SV
`define lfc_load_hit_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

`include "../src/include/cache_types_pkg.svh"

class lfc_load_hit_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_load_hit_seq)

  localparam int NUM_TESTS = 25;

  function new(string name = "lfc_load_hit_seq");
    super.new(name);
  endfunction
  
  virtual task body();
  lfc_cpu_transaction req;
  addr_t address;

  `uvm_info(get_type_name(), "lfc_load_hit_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TESTS; i++) begin // test 25 random blocks

	// initial block write
	req = lfc_cpu_transaction #()::type_id::create("req");
	
	`uvm_info(get_type_name(), "Sending Write transaction...", UVM_MEDIUM)

	start_item(req);
	  req.randomize();
	  req.n_rst = 1'b1;
	  req.mem_in_rw_mode = 1'b1;
	  req.mem_in_addr.index = i % NUM_SETS;
	  req.mem_in_addr.tag = i;
	  req.mem_in_addr.block_offset = '0;
	  req.mem_in_addr.byte_offset = '0;
	  req.dp_in_halt = 1'b0;
	  address = req.mem_in_addr;

	  `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	finish_item(req);

	for(int j = 0; j < BLOCK_SIZE; j++) begin // 4 reads to block that was just written to
		req = lfc_cpu_transaction #()::type_id::create("req");
	
		`uvm_info(get_type_name(), "Sending Read transaction...", UVM_MEDIUM)

		start_item(req);
		  req.n_rst = 1'b1;
		  req.mem_in_rw_mode = 1'b0;
		  req.dp_in_halt = 1'b0;
		  req.mem_in_store_value = 32'hCAFEBABE; // doesn't matter for reads
		  req.mem_in_addr = address;
		  req.mem_in_addr.block_offset = j;

		  `uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	       	        req.mem_in_addr), UVM_LOW)
		finish_item(req);
	end
  end
  endtask
endclass

`endif // lfc_load_hit_seq_SV
