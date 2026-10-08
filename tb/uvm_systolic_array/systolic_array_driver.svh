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
  virtual systolic_array_if #(N, WIDTH) vif;

  // Constructor
  function new(string name = "driver", uvm_component parent = null);
    super.new(name, parent);
  endfunction

  // Build phase gets virtual interface 
  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual systolic_array_if)::get(this, "", "vif", vif)) begin
      `uvm_fatal(get_type_name(), "Virtual interface not found; not set at top level")
    end
  endfunction

  // Run phase 
  task run_phase(uvm_phase phase);
    // initialize the signals
    systolic_array_transaction #(N, WIDTH) req;  // not completely sure about declaring the transaction type 
    reset_all();
    forever begin
      seq_item_port.get_next_item(req); // get next transaction 
      wait (vif.n_rst === 1'b1); // wait for not reset to drive transaction 
      drive_trans(req); // drive the transaction item to DUT using interface 
      seq_item_port.item_done(); // Indicate that the transaction is done
    end
  endtask

  // fixed tasks to have ; not :

  // task format is output name input 

  // new task for checking if fifo full and waiting 
  task check_fifo();
    while (! vif.driver.fifo_has_space) begin 
      @(vif.driver);  // wait for clock edge to check if fifo has space 
    end
  endtask

  // need to repack each row of matrix into one word to send to sys_arr 
  task automatic bit [N*WIDTH-1:0] format_row(bit [WIDTH-1:0] my_matrix [N*N], int r);
    bit [N*WIDTH-1:0] row = '0; // set everything to 0
    for (int col = 0; col < N; col++) begin
      row[col*WIDTH +: WIDTH] = my_matrix[r*N + col];   // gather each row and put it in word 
    end
    return row;  // return the packed row 
  endtask

  // task for reseting inputs 
  task reset_all();
    @(vif.driver);  // syncs to clock edge defined in interface 
    vif.driver.weight_en <= '0;
    vif.driver.input_en <= '0;
    vif.driver.partial_en <= '0;
    vif.driver.row_in_en <= '0;
    vif.driver.row_ps_en <= '0;
    vif.driver.array_in <= '0;   
    vif.driver.array_in_partials <= '0;   
  endtask

  // task for driving transaction at clock edge 
  task drive_trans(systolic_array_transaction #(N, WIDTH) req);  // not sure about syntax 
    @(vif.driver);
    wait_for_space();  // wait for fifo to have space

    // load weights 
    for (int row = 0; row < N; row++) begin
      vif.driver.array_in <= format_row(req.weight_matrix, row);
      vif.driver.row_in_en <= row[$clog2(N)-1:0];
      vif.driver.weight_en <= 1'b1;
      @(vif.driver);
    end
    vif.driver.weight_en <= 1'b0;  // put low to not interfere with next transaction
    @(vif.driver); // maybe?

    // load inputs or partial sums
     for (int r = 0; r < N; r++) begin
      vif.driver.array_in <= format_row(req.input_matrix, r);
      vif.driver.row_in_en <= r[$clog2(N)-1:0];
      vif.driver.input_en <= 1'b1;
      vif.driver.array_in_partials <= format_row(req.partial_matrix, r);
      vif.driver.row_ps_en <= r[$clog2(N)-1:0];
      vif.driver.partial_en <= 1'b1;
      @(vif.driver);
    end
    vif.driver.input_en <= 1'b0;
    vif.driver.partial_en <= 1'b0;
    @(vif.driver);

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
