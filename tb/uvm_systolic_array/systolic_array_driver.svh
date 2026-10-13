// Driver for systolic array  
// Updated after transaction changed
// Drive randomized transactions to the systolic array through pin level activity using interface 
// Referred to UVM vlsiverify example for adder 

`ifndef SYSTOLIC_ARRAY_DRIVER_SVH
`define SYSTOLIC_ARRAY_DRIVER_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_driver #(parameter N = 4, parameter WIDTH = 16) extends uvm_driver #(systolic_array_transaction #(N, WIDTH));
  `uvm_component_param_utils(systolic_array_driver #(N, WIDTH))   // uvm_component_param_utils maybe use?

  // Virtual interface handle
  virtual systolic_array_tb_if vif;

  // Constructor
  function new(string name = "driver", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  // Build phase gets virtual interface 
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual systolic_array_tb_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal(get_type_name(), "Virtual interface not found; not set at top level")
    end
  endfunction

  // Run phase 
  task run_phase(uvm_phase phase);
    // initialize the signals
    systolic_array_transaction #(N, WIDTH) req;  // not completely sure about declaring the transaction type (maybe need to use typedef ??)
    reset_all();
    forever begin
      wait (vif.n_rst === 1'b1); // wait for not reset to get and drive transaction 
      seq_item_port.get_next_item(req); // get next transaction 
      drive_trans(req); // drive the transaction item to DUT using interface 
      seq_item_port.item_done(); // indicate that the transaction is done
    end
  endtask

  // fixed tasks to have ; not :

  // task format is output name input 

  // need to repack each row of matrix into one word to send to sys_arr 
  function automatic bit [N*WIDTH-1:0] format_row(bit [WIDTH-1:0] my_matrix [N*N], int r);
    bit [N*WIDTH-1:0] row = '0; // set everything to 0
    for (int col = 0; col < N; col++) begin
      row[col*WIDTH +: WIDTH] = my_matrix[r*N + col];   // gather each row and put it in word 
    end
    return row;  // return the packed row 
  endfunction

  // task for reseting inputs 
  task reset_all();
    @(posedge vif.clk);  // syncs to clock edge defined in interface 
    vif.bus.sa_weight_en <= 1'b0;
    vif.bus.sa_input_en <= 1'b0;
    vif.bus.sa_partial_en <= 1'b0;
    vif.bus.sa_array_in <= 1'b0;
    vif.bus.sa_array_in_partials <= 1'b0;   
    vif.bus.sa_ready_out <= 1'b1;
  endtask

  // task for driving transaction at clock edge 
  task drive_trans(systolic_array_transaction #(N, WIDTH) req);  // not sure about syntax 

    // load weights 
    for (int row = 0; row < N; row++) begin
      while (!vif.bus.sa_ready_in) begin // keep clocking until ready 
        @(posedge vif.clk);
      end
      vif.bus.sa_weight_en <= 1'b1;
      vif.bus.sa_array_in <= format_row(req.weight_matrix, row);
      @(posedge vif.clk); // maybe?
    end

    // put signals low 
    vif.bus.sa_weight_en <= 1'b0;  // put low to not interfere with next transaction
    vif.bus.sa_array_in <= '0;

    // load inputs or partial sums
     for (int r = 0; r < N; r++) begin
      while (!vif.bus.sa_ready_in) begin // keep clocking until ready 
        @(posedge vif.clk);
      end
      vif.bus.sa_input_en <= 1'b1;
      vif.bus.sa_array_in <= format_row(req.input_matrix, r);
      vif.bus.sa_partial_en <= 1'b1;
      vif.bus.sa_array_in_partials <= format_row(req.partial_matrix, r);
      @(posedge vif.clk);
    end

    // clearing signals put low 
    vif.bus.sa_input_en <= 1'b0;
    vif.bus.sa_array_in <= '0;
    vif.bus.sa_partial_en <= 1'b0;
    vif.bus.sa_array_in_partials <='0;

    // vif.driver.weight_en <= req.weight_en;
    // vif.driver.input_en <= req.input_en;
    // vif.driver.partial_en <= req.partial_en;
    // vif.driver.row_in_en <= req.row_in_en;
    // vif.driver.row_ps_en <= req.row_ps_en;
    // vif.driver.array_in <= req.array_in;          // maybe not needed 
    // vif.driver.array_in_partials <= req.array_in_partials;    // maybe not needed
  endtask

endclass

`endif

