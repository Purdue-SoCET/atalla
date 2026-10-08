//monitor first draft
`ifndef SYSTOLIC_ARRAY_MONITOR_SVH
`define SYSTOLIC_ARRAY_MONITOR_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_monitor #(parameter N = 4, parameter WIDTH = 16) extends uvm_monitor;

  `uvm_component_param_utils(systolic_array_monitor #(N, WIDTH))

  //virtual interface and analysis port
  virtual systolic_array_if #(N, WIDTH) vif; 
  uvm_analysis_port #(systolic_array_transaction #(N, WIDTH)) ap;

  function new(string name = "systolic_array_monitor", uvm_component parent = null);
    super.new(name, parent);
    ap = new("ap", this);
  endfunction

  function void build_phase (uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(virtual systolic_array_if #(N, WIDTH))::get(this, "", "vif", vif)) begin
      `uvm_fatal(get_type_name(), "Virtual interface not found in uvm_config_db")
    end
  endfunction

  task run_phase(uvm_phase phase);
    systolic_array_transaction #(N, WIDTH) trans;

    //row tracking variables
    bit[N-1:0] weight_seen;
    bit[N-1:0] input_seen;
    bit[N-1:0] partial_seen;
    bit[N-1:0] output_seen;

    int weight_row;
    
    //initialize 
    trans = null;
    weight_seen = '0;
    input_seen = '0;
    partial_seen = '0;
    output_seen = '0;
    weight_row = '0;

    forever begin
      @(posedge vif.clk); 

      //initialize 
      if (!vif.n_rst) begin
        trans = null;
        weight_seen = '0;
        input_seen = '0;
        partial_seen = '0;
        output_seen = '0;
        weight_row = '0;
      end

      else begin

        if (vif.monitor.weight_en || vif.monitor.input_en || vif.monitor.partial_en || vif.monitor.out_en) begin
          trans = systolic_array_transaction #(N, WIDTH)::type_id::create("trans");
        end

        if (trans != null) begin

          //weight rows
          if (vif.weight_en) begin
            if (weight_row < N) begin 
              for (int c = 0; c < N; c++) begin //check for space
                trans.weight_matrix[weight_row*N + c] = vif.array_in[c*WIDTH +: WIDTH]; //convert to index and select weight bits
              end

              weight_seen[weight_row] = 1'b1;
              weight_row++;
            end
            else begin 
              `uvm_error("WEIGHTS", "Extra weight row received")
            end
          end

          //input rows
          if (vif.input_en) begin
            if (vif.row_in_en < N) begin
              for (int c = 0; c < N; c++) begin
                trans.input_matrix[vif.row_in_en*N + c] = vif.array_in[c*WIDTH +: WIDTH];
              end

              input_seen[vif.row_in_en] = 1'b1;
            end
            else begin
              `uvm_error("INPUT_ROW", "Input row index out of range")
            end
          end

          //partial rows
          if (vif.partial_en) begin
            if (vif.row_ps_en < N) begin
              for (int c = 0; c < N; c++) begin
                trans.partial_matrix[vif.row_ps_en*N + c] = vif.array_in_partials[c*WIDTH +: WIDTH];
              end
              
              partial_seen[vif.row_ps_en] = 1'b1;
            end
            else begin
              `uvm_error("PARTIAL_ROW", "Partial-sum row index out of range")
            end
          end

          //output rows
          if (vif.out_en) begin
            if (vif.row_out < N) begin
              if (output_seen[vif.row_out]) begin
                `uvm_error("OUTPUT_ROW", "Duplicate output row received")
              end
              else begin
                for (int c = 0; c < N; c++) begin
                  trans.output_matrix[vif.row_out*N + c] = vif.array_output[c*WIDTH +: WIDTH];
                end

                output_seen[vif.row_out] = 1'b1;
              end
            end
            else begin
              `uvm_error("OUTPUT_ROW", "Output row index out of range")
            end
          end

          //only after all rows are collected, then we write
          if ((&weight_seen) && (&input_seen) && (&partial_seen) && (&output_seen)) begin
            ap.write(trans);

          // Wait for next transaction
            trans = null;
            weight_seen  = '0;
            input_seen   = '0;
            partial_seen = '0;
            output_seen  = '0;
            weight_row   = 0;
          end
        end
        
        else if (vif.out_en) begin
          `uvm_error("UNEXPECTED_OUTPUT", "Output received with no active transaction")
        end
      end
    end
endtask

endclass
`endif
