`ifndef lfc_miss_coalesce_seq_SV
`define lfc_miss_coalesce_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_miss_coalesce_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_miss_coalesce_seq)

  localparam int NUM_TESTS = 25;

  function new(string name = "lfc_miss_coalesce_seq");
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
	//req.down_time = 2;
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

	// coalesced miss
	req = lfc_cpu_transaction #()::type_id::create("req");

	start_item(req);
	assert(req.randomize() with {
		mem_in_addr.index == address.index;
	});	
	req.dp_in_halt = 1'b0;
	//req.down_time = 2;
	`uvm_info(get_type_name(), "Expecting miss", UVM_MEDIUM)
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

`endif // lfc_miss_coalesce_seq_SV
