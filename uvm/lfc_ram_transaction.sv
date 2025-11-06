`ifndef LFC_RAM_TRANSACTION_SV
`define LFC_RAM_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class lfc_ram_transaction #(parameter NUM_BANKS = 4) extends uvm_sequence_item;
    logic n_rst;
    rand logic [NUM_BANKS-1:0][31:0] ram_mem_data; // check what to register as with param_utils
    logic [NUM_BANKS-1:0] ram_mem_complete;

    logic [NUM_BANKS-1:0] ram_mem_REN;
    logic [NUM_BANKS-1:0] ram_mem_WEN;
    logic [NUM_BANKS-1:0][31:0] ram_mem_addr;
    logic [NUM_BANKS-1:0][31:0] ram_mem_store;


    `uvm_object_utils_begin(lfc_ram_transaction) // change these to uvm_field_int if not a single bit signal
        `uvm_field_int(n_rst, UVM_DEFAULT)
        `uvm_field_int(ram_mem_data, UVM_DEFAULT)
        `uvm_field_int(ram_mem_complete, UVM_DEFAULT)
        `uvm_field_int(ram_mem_REN, UVM_DEFAULT)
        `uvm_field_int(ram_mem_WEN, UVM_DEFAULT)
        `uvm_field_int(ram_mem_addr, UVM_DEFAULT)
        `uvm_field_int(ram_mem_store, UVM_DEFAULT)
    `uvm_object_utils_end

    // no current randomization constraints

    function new(string name = "lfc_ram_transaction");
        super.new(name);
    endfunction

    function int input_equal(lfc_ram_transaction tx);
        int result;
        if((ram_mem_data == tx.ram_mem_data) && (ram_mem_complete == tx.ram_mem_complete)) begin
            result = 1;
        end
        else begin
            result = 0;
        end

        return result;
    endfunction

endclass

`endif