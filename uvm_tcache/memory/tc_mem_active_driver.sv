`ifndef TC_MEM_ACTIVE_DRIVER_SV
`define TC_MEM_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "../tc_if.sv"
`include "tc_mem_transaction.sv"
`include "../tc_types.sv"

class mem_model;
  logic [ADDR_WIDTH-1:0][DATA_WIDTH-1:0] mem;
  logic [ADDR_WIDTH-1:0] present_addrs;

  function logic [DATA_WIDTH-1:0] read(logic [ADDR_WIDTH-1:0] addr);
    logic [DATA_WIDTH-1:0] data_out;
    if (present_addrs[addr] == 1'b1) begin
      return mem[addr];
    end else begin
      `uvm_info("MEM_DRV", "mem did not exist", UVM_MEDIUM)
      data_out = $urandom_range(2147483648); // will change if DATA_WIDTH changes
      mem[addr] = data_out;
      present_addrs[addr] = 1'b1;
      return data_out;
    end
  endfunction
endclass

class tc_mem_active_driver extends uvm_driver#(tc_mem_transaction);
  `uvm_component_utils(tc_mem_active_driver)

  localparam LAT = 3;

  virtual tc_if vif;
  mem_model mem;

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    if (!uvm_config_db#(virtual tc_if)::get(this, "", "tc_vif", vif)) begin
      `uvm_fatal("Driver", "No virtual interface specified for this test instance");
    end
  endfunction

  task DUT_reset();
    @(posedge vif.clk);
    vif.n_rst = 0;
    @(posedge vif.clk);
    vif.n_rst = 1;
    @(posedge vif.clk);
  endtask

  virtual task run_phase(uvm_phase phase);
    forever begin
      if (vif.mem_valid) begin
        vif.mem_data = mem.read(vif.mem_addr);
        repeat(LAT) @(negedge vif.clk);
        vif.mem_ready = 1'b1;

        @(negedge vif.clk);
        vif.mem_ready = 1'b0;
        vif.mem_data = '0;
      end else begin
        @(negedge vif.clk);
      end
    end

  endtask

endclass

`endif
