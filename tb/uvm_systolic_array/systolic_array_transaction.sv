// transaction for systolic array
//

`ifndef SYSTOLIC_ARRAY_TRANSACTION_SV
`define SYSTOLIC_ARRAY_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_transaction #(parameter N = 4, parameter WIDTH = 16) extends uvm_sequence_item; //random inputs
	rand bit weight_en; 
	rand bit input_en;
	rand bit partial_en;
	rand bit [$clog2(N)-1:0] row_in_en;
	rand bit [$clog2(N)-1:0] row_ps_en;
	rand bit [N*WIDTH-1:0] array_in;
	rand bit [N*WIDTH-1:0] array_in_partials;
	rand bit ignore_fifo; // for edge case testing
	rand bit allow_illegal; // for edge case testing 

	bit out_en; //outputs
	// two status signals - not per transaction so not sure to include
	// bit drained;
	// bit fifo_has_space;
	bit [$clog2(N)-1:0] row_out;
	bit [N*WIDTH-1:0] array_output;

	`uvm_object_param_utils_begin(systolic_array_transaction #(N, WIDTH)) //initialization
		`uvm_field_int(weight_en, UVM_ALL_ON)
    		`uvm_field_int(input_en, UVM_ALL_ON)
    		`uvm_field_int(partial_en, UVM_ALL_ON)
    		`uvm_field_int(row_in_en, UVM_ALL_ON)
    		`uvm_field_int(row_ps_en, UVM_ALL_ON)
    		`uvm_field_int(array_in, UVM_ALL_ON)
    		`uvm_field_int(array_in_partials, UVM_ALL_ON)
    		`uvm_field_int(out_en, UVM_ALL_ON)
    		`uvm_field_int(drained,UVM_ALL_ON)
    		`uvm_field_int(fifo_has_space, UVM_ALL_ON)
    		`uvm_field_int(row_out, UVM_ALL_ON)
    		`uvm_field_int(array_output, UVM_ALL_ON)
  	`uvm_object_utils_end

	function new(string name = "systolic_array_transaction");
		super.new(name);
	endfunction

	constraint illegal_behavior 
	{
		!allow_illegal -> !(weight_en && input_en);
		!allow_illegal -> !(weight_en && partial_en);
		!allow_illegal -> !(input_en && partial_en);
	}


	constraint row_bounds
	{
		row_in_en < N;
		row_ps_en < N;
	}
	
	constraint input_fifo {soft (ignore_fifo == 0);}

	constraint bf16
	{
		// still looking into floats
	}

	// need to add more constraints still thinking of them




endclass


`endif
