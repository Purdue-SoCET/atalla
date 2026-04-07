`ifndef lfc_MSHR_overflow_seq_SV
`define lfc_MSHR_overflow_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "../src/include/cache_types_pkg.svh"

class lfc_MSHR_overflow_seq extends uvm_sequence#(lfc_cpu_transaction);

  `uvm_object_utils(lfc_MSHR_overflow_seq)

  localparam int NUM_TESTS = 25;

  function new(string name = "lfc_MSHR_overflow_seq");
    super.new(name);
  endfunction

  virtual task body();
    lfc_cpu_transaction req;
    addr_t address;

    `uvm_info(get_type_name(), "lfc_miss_coalesce_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TESTS; i++) begin

	// initial miss
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	req.randomize();
	req.dp_in_halt = 1'b0;
	req.down_time = 0;
	req.wait_for_ram = 0;
	address = req.mem_in_addr;
	`uvm_info(get_type_name(), "Expecting miss", UVM_MEDIUM)
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

	// overflow buffer with subsequent misses to same bank
	for(int j = 0; j < MSHR_BUFFER_LEN; j++) begin
		req = lfc_cpu_transaction #()::type_id::create("req");
		
		start_item(req);
		if(j < MSHR_BUFFER_LEN / 2) begin
			assert(req.randomize() with {
				mem_in_addr.index == address.index;
				mem_in_addr.tag != address.tag;
			});
		end else begin
			assert(req.randomize() with {
				mem_in_addr.index == (address.index + 1);
				mem_in_addr.tag != address.tag;
			});
		end

		req.dp_in_halt = 1'b0;
		req.down_time = 0;
		req.wait_for_ram = 0;

		`uvm_info(get_type_name(), "Expecting miss", UVM_MEDIUM)
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

	end
  end
  endtask
endclass

`endif // lfc_MSHR_overflow_seq_SV
