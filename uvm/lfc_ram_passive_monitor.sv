// lfc_ram_passive_monitor.svh
`ifndef LFC_RAM_PASSIVE_MONITOR_SV
`define LFC_RAM_PASSIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"

typedef virtual lfc_if lfc_ram_vif_t1;   // remove ram port to test

class lfc_ram_passive_monitor #(parameter NUM_BANKS = 4) extends uvm_monitor;
  `uvm_component_utils(lfc_ram_passive_monitor)

  lfc_ram_vif_t1 vif;

  uvm_analysis_port#(lfc_ram_transaction) result_ap [NUM_BANKS];

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    for (int b = 0; b < NUM_BANKS; b++)
      result_ap[b] = new($sformatf("result_ap_%0d", b), this);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    //ap = new("ap", this);
    // optional: get VIF from config_db
    if(!uvm_config_db#(lfc_ram_vif_t1)::get(this, "", "lfc_vif", vif)) begin    // change "lfc_vif" to ram modport
      `uvm_fatal("Monitor", "No virtual interface specified for this monitor instance")
    end
  endfunction

  // minimal placeholder; add your sampling here
  virtual task run_phase(uvm_phase phase);
    logic [NUM_BANKS-1:0] old_ram_mem_REN = '0; 
    logic [NUM_BANKS-1:0] old_ram_mem_WEN = '0;
    super.run_phase(phase);

    forever begin
      @(posedge vif.clk);

      for (int b = 0; b < vif.NUM_BANKS; b++) begin
        // sample read or write
        if ((vif.ram_mem_REN[b] === 1'b1 && old_ram_mem_REN[b] !== 1'b1) ||
            (vif.ram_mem_WEN[b] === 1'b1 && old_ram_mem_WEN[b] !== 1'b1)) begin
          lfc_ram_transaction tr;
          tr = lfc_ram_transaction #()::type_id::create($sformatf("ram_tr_bank%0d", b));

          // capture from interface
          tr.ram_mem_REN[b]   = vif.ram_mem_REN[b];
          tr.ram_mem_WEN[b]   = vif.ram_mem_WEN[b];
          tr.ram_mem_addr[b]  = vif.ram_mem_addr[b];
          tr.ram_mem_store[b] = vif.ram_mem_store[b];
          tr.ram_mem_data[b]  = vif.ram_mem_data[b];
          tr.ram_mem_complete[b] = vif.ram_mem_complete[b];

          // send only to this bank's port
          result_ap[b].write(tr);

          `uvm_info("RAM_PASSIVE_MON",
            $sformatf("Captured bank=%0d REN=%0b WEN=%0b addr=0x%08h store=0x%08h data=0x%08h complete=%0b",
                      b,
                      vif.ram_mem_REN[b],
                      vif.ram_mem_WEN[b],
                      vif.ram_mem_addr[b],
                      vif.ram_mem_store[b],
                      vif.ram_mem_data[b],
                      vif.ram_mem_complete[b]),
            UVM_LOW)
        end
	old_ram_mem_REN[b] = vif.ram_mem_REN[b];
	old_ram_mem_WEN[b] = vif.ram_mem_WEN[b];
      end
    end
  endtask

endclass

`endif

