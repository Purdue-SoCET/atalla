// lfc_ram_passive_monitor.svh
`ifndef LFC_RAM_PASSIVE_MONITOR_SV
`define LFC_RAM_PASSIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"

// --- Replace these with your real types if needed ---
typedef virtual lfc_if.ram lfc_ram_vif_t1;
//typedef lfc_cpu_item       cpu_txn_t;

class lfc_ram_passive_monitor extends uvm_monitor;
  `uvm_component_utils(lfc_ram_passive_monitor)

  // analysis port to scoreboard/subscribers
  //uvm_analysis_port #(cpu_txn_t) ap;

  // optional: virtual interface handle
  lfc_ram_vif_t1 vif;

  uvm_analysis_port#(lfc_ram_transaction) result_ap;

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    result_ap = new("result", this);
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
    super.run_phase(phase);

    forever begin
      @(posedge vif.clk);

      for (int b = 0; b < vif.NUM_BANKS; b++) begin
        // sample read or write
        if (vif.ram_mem_REN[b] || vif.ram_mem_WEN[b]) begin
          lfc_ram_transaction tr;
          tr = lfc_ram_transaction::type_id::create($sformatf("ram_tr_bank%0d", b));

          // capture from interface
          tr.ram_mem_REN[b]   = vif.ram_mem_REN[b];
          tr.ram_mem_WEN[b]   = vif.ram_mem_WEN[b];
          tr.ram_mem_addr[b]  = vif.ram_mem_addr[b];
          tr.ram_mem_store[b] = vif.ram_mem_store[b];
          tr.ram_mem_data[b]  = vif.ram_mem_data[b];
          tr.ram_mem_complete[b] = vif.ram_mem_complete[b];

          // send to scoreboard or subscribers
          result_ap.write(tr);

          `uvm_info("RAM_MON",
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
      end
    end
  endtask

endclass

`endif
