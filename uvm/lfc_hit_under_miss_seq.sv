`ifndef lfc_hit_under_miss_seq_SV
`define lfc_hit_under_miss_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

`include "../src/include/cache_types_pkg.svh"

class lfc_hit_under_miss_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_hit_under_miss_seq)

  localparam int NUM_TESTS = 40;

  function new(string name = "lfc_hit_under_miss_seq");
    super.new(name);
  endfunction
  
  virtual task body();
  lfc_cpu_transaction req;
  addr_t address;

  `uvm_info(get_type_name(), "lfc_hit_under_miss_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TESTS; i++) begin

	// initial block pull
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	req.randomize();
	req.dp_in_halt = 1'b0;
	//req.down_time = 2;
	req.mem_in_rw_mode = 1'b0;
	address = req.mem_in_addr;
	if(req.mem_in_rw_mode == 1'b1) begin
		`uvm_info(get_type_name(), "ITER1: Sending Write transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	end else begin
		`uvm_info(get_type_name(), "ITER1: Sending Read transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	       	        req.mem_in_addr), UVM_LOW)
	end
	finish_item(req);

	// miss
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	/*assert(req.randomize() with {
		mem_in_addr.tag != address.tag;
		mem_in_addr.index != address.index;
	});*/
	assert(req.randomize() with {
		mem_in_addr.tag != address.tag;
    		mem_in_addr.index[BANKS_LEN-1:0] != address.index[BANKS_LEN-1:0];
	});
	req.dp_in_halt = 1'b0;
	//req.down_time = 2
	if(req.mem_in_rw_mode == 1'b1) begin
		`uvm_info(get_type_name(), "ITER2: Sending Write transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	end else begin
		`uvm_info(get_type_name(), "ITER2: Sending Read transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	       	        req.mem_in_addr), UVM_LOW)
	end
	finish_item(req);

	// hit under miss
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	assert(req.randomize() with {
		mem_in_addr == address;
	});	
	req.dp_in_halt = 1'b0;
	//req.down_time = 2;
	if(req.mem_in_rw_mode == 1'b1) begin
		`uvm_info(get_type_name(), "ITER3: Sending Write transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	end else begin
		`uvm_info(get_type_name(), "ITER3: Sending Read transaction...", UVM_MEDIUM)
		`uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	       	        req.mem_in_addr), UVM_LOW)
	end
	finish_item(req);
  end
  endtask
endclass

`endif // lfc_hit_under_miss_seq_SV
