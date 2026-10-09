`ifndef SYSTOLIC_ARRAY_SCOREBOARD_SVH
`define SYSTOLIC_ARRAY_SCOREBOARD_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"
class systolic_array_scoreboard #(parameter N = 4, parameter WIDTH = 16) extends uvm_scoreboard;
    `uvm_component_param_utils(systolic_array_scoreboard #(N, WIDTH))
    
    // fifos for transactions to store
    uvm_tlm_analysis_fifo #(systolic_array_transaction #(N, WIDTH)) exp_fifo;
    uvm_tlm_analysis_fifo #(systolic_array_transaction #(N, WIDTH)) act_fifo;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    virtual function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        exp_fifo = new("exp_fifo", this);
        act_fifo = new("act_fifo", this);
    endfunction

    virtual task run_phase(uvm_phase phase);
        systolic_array_transaction #(N, WIDTH) exp_tr;
        systolic_array_transaction #(N, WIDTH) act_tr;
        bit match;

        super.run_phase(phase);

        forever begin
            exp_fifo.get(exp_tr);
            act_fifo.get(act_tr);

            match = 1;

            for (int i = 0; i < N*N; i++) begin
                if (exp_tr.output_matrix[i] !== act_tr.output_matrix[i]) begin
                    match = 0;
                    `uvm_error("Scoreboard failed", $sformatf("Mismatch @ index %0d Expected: 16'h%0h -- Actual: 16'h%0h", i, exp_tr.output_matrix[i], act_tr.output_matrix[i]))
                end
            end

            if (match) begin
                `uvm_info("Scoreboard passed", $sformatf("Successfully matched %0dx%0d matrix output", N, N), UVM_LOW)
            end
        end
    endtask
endclass

`endif