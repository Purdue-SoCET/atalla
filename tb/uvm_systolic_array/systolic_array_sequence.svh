// sequence for systolic array 
// generates and sends transactions to driver via sequencer
// referred to adder uvm 

`ifndef SYSTOLIC_ARRAY_SEQUENCE_SVH
`define SYSTOLIC_ARRAY_SEQUENCE_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class base_seq #(parameter N = 4, parameter WIDTH = 16) extends uvm_sequence #(systolic_array_transaction #(N, WIDTH));

    typedef systolic_array_transaction #(N, WIDTH) transaction_type; // typdef eliminates syntax err
    transaction_type req;

    `uvm_object_param_utils(base_seq #(N, WIDTH))

    function new(string name = "base_seq");
        super.new(name);
    endfunction

    task body();
        `uvm_info(get_type_name(), "Base seq: Inside Body", UVM_LOW);  // from adder uvm 
        `uvm_do(req)
    endtask

endclass

`endif
