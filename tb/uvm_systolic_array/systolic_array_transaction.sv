// transaction for systolic array
//

`ifndef SYSTOLIC_ARRAY_TRANSACTION_SV
`define SYSTOLIC_ARRAY_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_transaction #(parameter N = 4, parameter WIDTH = 16) extends uvm_sequence_item; //random inputs
	rand bit [WIDTH-1:0] weight_matrix [N*N];
    	rand bit [WIDTH-1:0] input_matrix [N*N];
    	rand bit [WIDTH-1:0] partial_matrix [N*N]; 

	bit [WIDTH-1:0] ouptut_matrix [N*N];

	`uvm_object_param_utils_begin(systolic_array_transaction #(N, WIDTH)) //initialization
		`uvm_field_sarray_int(weight_matrix, UVM_ALL_ON)
		`uvm_field_sarray_int(input_matrix, UVM_ALL_ON)
		`uvm_field_sarray_int(partial_matrix, UVM_ALL_ON)		
		`uvm_field_sarray_int(output_matrix, UVM_ALL_ON)
  	`uvm_object_utils_end

	function new(string name = "systolic_array_transaction");
		super.new(name);
	endfunction

	constraint bf16
	{
		// to be added
	}






endclass


`endif
