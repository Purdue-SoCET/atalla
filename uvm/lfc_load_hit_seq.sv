`ifndef lfc_load_hit_seq_SV
`define lfc_load_hit_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

localparam int NUM_TRANSACTIONS = 100;

class lfc_load_hit_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_load_hit_seq)

  function new(string name = "lfc_load_hit_seq");
    super.new(name);
  endfunction
  
  virtual task body();
  logic [NUM_TRANSACTIONS-1:0][31:0] saved_addrs;

  `uvm_info(get_type_name(), "lfc_load_hit_seq", UVM_MEDIUM)

  for(int i = 0; i < NUM_TRANSACTIONS; i++) begin
	    lfc_cpu_transaction req;
	    req = lfc_cpu_transaction #()::type_id::create("req");

	    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

	    start_item(req);
	      req.randomize();
	      req.n_rst              = 1'b1;
	      req.mem_in_rw_mode     = 1'b1; // 1 = write
	      req.dp_in_halt         = 1'b0;
	      saved_addrs[i] = req.mem_in_addr;

	      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
	       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
	    finish_item(req);
    end

    for(int i = 0; i < NUM_TRANSACTIONS; i++) begin
	    lfc_cpu_transaction req;
	    req = lfc_cpu_transaction #()::type_id::create("req");

	    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)

	    start_item(req);
	      req.n_rst              = 1'b1; 
	      req.mem_in_addr        = saved_addrs[i];
	      req.mem_in_rw_mode     = 1'b0;
	      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
	      req.dp_in_halt         = 1'b0;

	      `uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
		        req.mem_in_addr), UVM_LOW)
	    finish_item(req);
      end

   for(int i = 0; i < NUM_TRANSACTIONS; i++) begin
    lfc_cpu_transaction req;

    // write to address
    req = lfc_cpu_transaction #()::type_id::create("req");

    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

    start_item(req);
      req.randomize();
      req.n_rst              = 1'b1;
      req.mem_in_rw_mode     = 1'b1; // 1 = write
      req.dp_in_halt         = 1'b0;
      saved_addrs[i] = req.mem_in_addr;

      `uvm_info(get_type_name(), $sformatf("WRITE complete: addr=0x%0h data0x%0h",
       	        req.mem_in_addr, req.mem_in_store_value), UVM_LOW)
    finish_item(req);

    // immediate read from address
    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = saved_addrs[i];
      req.mem_in_rw_mode     = 1'b0;
      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
      req.dp_in_halt         = 1'b0;

      `uvm_info(get_type_name(), $sformatf("READ complete: addr=0x%0h",
	        req.mem_in_addr), UVM_LOW)
    finish_item(req);
   end
  endtask
endclass

`endif // lfc_load_hit_seq_SV
