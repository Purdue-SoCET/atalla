`ifndef SYSTOLIC_ARRAY_PREDICTOR_SVH
`define SYSTOLIC_ARRAY_PREDICTOR_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

import "DPI-C" context function void predict_systolic_array_output(input int unsigned N, input shortint unsigned weight_matrix[], input shortint unsigned input_matrix[], output shortint unsigned output_matrix[]);

class systolic_array_predictor #(parameter N = 4, parameter WIDTH = 16) extends uvm_component;
	`uvm_component_param_utils(systolic_array_predictor #(N, WIDTH))
	
	uvm_analysis_imp #(systolic_array_transaction #(N, WIDTH), systolic_array_predictor) item_export;

	function new(string name, uvm_component parent);
        	super.new(name, parent);
        	item_export = new("item_export", this);
    	endfunction

	virtual function void write(systolic_array_transaction #(N, WIDTH) tr);
        	shortint unsigned weight_matrix [];
        	shortint unsigned input_matrix [];
        	shortint unsigned output_matrix [];

        	weight_matrix = new[N*N];
        	input_matrix = new[N*N];
        	output_matrix = new[N*N];

		foreach (tr.weight_matrix[i]) weight_matrix[i] = tr.weight_matrix[i];
        	foreach (tr.input_matrix[i]) input_matrix[i] = tr.input_matrix[i];
		// ignore partials
		
		predict_sysarr_output(N, weight_matrix, input_matrix, output_matrix);
		foreach (output_matrix[i]) tr.output_matrix[i] = output_matrix[i];


		`uvm_info("PREDICTOR", $sformatf("prediction worked"), UVM_HIGH)

	endfunction
endclass


`endif
