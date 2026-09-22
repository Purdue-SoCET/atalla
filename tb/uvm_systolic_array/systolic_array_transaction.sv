// transaction for systolic array
//

'ifndef SYSTOLIC_ARRAY_TRANSACTION_SV
'define SYSTOLIC_ARRAY_TRANSACTION_SV

import uvm_pkg::*;
'include "uvm_macros.svh"

class systolic_array_transaction #(parameter int N = 4, parameter int WIDTH = 16) extends uvm_sequence_item;
	rand bit weight_en;
	rand bit input_en;
	rand bit partial_en;
	rand bit [$clog2(N)-1:0] row_in_en;
	rand bit [$clog2(N)-1:0] row_ps_en;
	rand bit [N*WIDTH-1:0] array_in;
	rand bit [N*WIDTH-1:0] array_in_partials;

	bit out_en;
	bit drained;
	bit fifo_has_space;
	bit [$clog2(N)-1:0] row_out;
	bit [N*WIDTH-1:0] array_output;

	`uvm_object_param_utils_begin(systolic_array_transaction #(N, WIDTH))
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

	function new(string = "systolic_array_transation");
		super.new(name);
	endfunction

	constraint c_mode_exclusive
	{
		(weight_en + input_en) <= 1; // shouldn't load weight and input at same time
	}

	constraint c_row_in_en_range {row_in_en < N;}// keep rows within dimensions
  	constraint c_row_ps_en_range {row_ps_en < N;} 

	// need to add more constraints still thinking of them




endclass


'endif
