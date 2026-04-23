`ifndef LFC_COVERAGE_SV
`define LFC_COVERAGE_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

//`uvm_analysis_imp_decl(_cpu)

class lfc_coverage extends uvm_subscriber #(lfc_cpu_transaction);
  `uvm_component_utils(lfc_coverage)
  
  parameter NUM_BANKS = 4;
  parameter UUID_SIZE = 4;
  parameter MAX_MSHR   = 8;
  parameter CACHE_LINES = 256;
  parameter BLOCK_SIZE  = 4;

  uvm_analysis_imp_cpu #(lfc_cpu_transaction, lfc_coverage) cpu_imp;
  
  lfc_cpu_transaction tx;

  covergroup cpu_cg;
	coverpoint tx.mem_in_addr {
		bins addr[32] = {[0:$]}; // range broken up into 32 bins
	}
	coverpoint tx.mem_in_rw_mode;
	coverpoint tx.hit;
	coverpoint tx.block_status {
		bins block0 = {1};
		bins block1 = {2};
		bins block2 = {4};
		bins block3 = {8};
	}	

	cross tx.mem_in_addr, tx.mem_in_rw_mode;
	cross tx.mem_in_addr, tx.hit;
	cross tx.block_status, tx.hit;
  endgroup

  function new(string name, uvm_component parent);
    super.new(name,parent);

    cpu_cg = new;
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    cpu_imp = new("cpu_imp", this);
  endfunction

  virtual function void write_cpu(lfc_cpu_transaction t);
 	write(t);
  endfunction

  virtual function void write(lfc_cpu_transaction t);
  	  `uvm_info("Cov", "received input cpu transaction", UVM_LOW)
	  tx = lfc_cpu_transaction#(NUM_BANKS, UUID_SIZE)::type_id::create("tx");
	  tx.copy(t);
	  cpu_cg.sample();
  endfunction

endclass

`endif



