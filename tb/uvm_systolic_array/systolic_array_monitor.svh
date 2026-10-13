`ifndef SYSTOLIC_ARRAY_MONITOR_SVH
`define SYSTOLIC_ARRAY_MONITOR_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_monitor #(parameter N = 4, parameter WIDTH = 16) extends uvm_monitor;

  `uvm_component_param_utils(systolic_array_monitor #(N, WIDTH))

  virtual systolic_array_tb_if vif;

  uvm_analysis_port #(systolic_array_transaction #(N, WIDTH)) ap_in;
  uvm_analysis_port #(systolic_array_transaction #(N, WIDTH)) ap_out;

  function new(
    string name = "systolic_array_monitor",
    uvm_component parent = null
  );
    super.new(name, parent);
    ap_in  = new("ap_in", this);
    ap_out = new("ap_out", this);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    if (!uvm_config_db#(virtual systolic_array_tb_if)::get(
        this, "", "vif", vif)) begin
      `uvm_fatal(
        get_type_name(),
        "Virtual interface not found in uvm_config_db"
      )
    end
  endfunction

  task run_phase(uvm_phase phase);
    systolic_array_transaction #(N, WIDTH) in_trans;
    systolic_array_transaction #(N, WIDTH) out_trans;
    int w_row = 0, i_row = 0, o_row = 0;
    in_trans  = systolic_array_transaction #(N, WIDTH)::type_id::create("in_trans");
    out_trans = systolic_array_transaction #(N, WIDTH)::type_id::create("out_trans");

    forever begin
    // changed monitor - you were creating a new transaction every clock cycle thats no bueno
      @(posedge vif.clk);
      if (!vif.n_rst) begin
        w_row = 0; i_row = 0; o_row = 0;
        continue;
      end

      // collecting weights
      if (vif.bus.sa_weight_en && w_row < N) begin
        for (int c = 0; c < N; c++) begin
            in_trans.weight_matrix[w_row*N + c] = vif.bus.sa_array_in[c*WIDTH +: WIDTH];
          end
          w_row++;
      end


      // collecting inputs
      if (vif.bus.sa_input_en && i_row < N) begin
        for (int c = 0; c < N; c++)
          in_trans.input_matrix[i_row*N + c] = vif.bus.sa_array_in[c*WIDTH +: WIDTH];
        i_row++;
      end

      if (w_row == N && i_row == N) begin
        ap_in.write(in_trans);
        in_trans = systolic_array_transaction #(N, WIDTH)::type_id::create("in_trans");
        w_row = 0; i_row = 0;
      end

      // Collect outputs
      if (vif.bus.sa_valid_in && vif.bus.sa_ready_out) begin
        for (int c = 0; c < N; c++)
          out_trans.output_matrix[o_row*N + c] = vif.bus.sa_array_output[c*WIDTH +: WIDTH];
        o_row++;
        if (o_row == N) begin
          ap_out.write(out_trans);
          out_trans = systolic_array_transaction #(N, WIDTH)::type_id::create("out_trans");
          o_row = 0;
        end
      end
      
    end
  endtask

endclass

`endif
