// Driver for systolic array  
// Drive randomized transactions to the systolic array through pin level activity using interface 
// Referred to UVM vlsiverify example for adder 

`ifndef SYSTOLIC_ARRAY_DRIVER_SV
`define SYSTOLIC_ARRAY_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

class systolic_array_driver #(parameter N = 4, parameter WIDTH = 16) extends uvm_driver #(systolic_array_transaction #(N, WIDTH));
  `uvm_component_utils(systolic_array_driver #(N, WIDTH))

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
    systolic_array_transaction #(N, WIDTH) req;
    reset_all();
    forever begin
      seq_item_port.get_next_item(req); // get next transaction 
      drive_trans(req); // drive the transaction item to DUT using interface 
      seq_item_port.item_done(); // Indicate that the transaction is done
    end
  endtask

  // task for reseting inputs 
  task reset_all():
    @(vif.driver);  // syncs to clock edge 
    vif.driver.weight_en <= 1'b0;
    vif.driver.input_en <= 1'b0;
    vif.driver.partial_en <= 1'b0;
    vif.driver.row_in_en <= 1'b0;
    vif.driver.row_ps_en <= 1'b0;
    vif.driver.array_in <= 1'b0;
    vif.driver.array_in_partials <= 1'b0;
  endtask

  // task for driving transaction at clock edge 
  task drive_trans(systolic_array_transaction #(N, WIDTH) req):
    @(vif.driver);
    vif.driver.weight_en <= req.weight_en;
    vif.driver.input_en <= req.input_en;
    vif.driver.partial_en <= req.partial_en;
    vif.driver.row_in_en <= req.row_in_en;
    vif.driver.row_ps_en <= req.row_ps_en;
    vif.driver.array_in <= req.array_in;
    vif.driver.array_in_partials <= req.array_in_partials;
  endtask

endclass

`endif
