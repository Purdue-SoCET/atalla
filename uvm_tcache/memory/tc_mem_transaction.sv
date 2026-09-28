`ifndef TC_MEM_TRANSACTION_SV
`define TC_MEM_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class tc_mem_transaction extends uvm_sequence_item;

    // Reset Input
    logic n_rst;

    // Mem Inputs
    logic [31:0] mem_addr;

    // Mem Outputs
    logic [31:0] mem_data;

    `uvm_object_utils_begin(tc_mem_transaction)
      `uvm_field_int(n_rst, UVM_DEFAULT)
      `uvm_field_int(mem_addr, UVM_DEFAULT)
      `uvm_field_int(mem_data, UVM_DEFAULT)
    `uvm_object_utils_end

    function new(string name = "tc_mem_transaction");
        super.new(name);
    endfunction

endclass

`endif
