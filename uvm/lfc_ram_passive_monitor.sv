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
    lfc_ram_transaction tr;
    @(posedge vif.clk);
    for (int i = 0; i < vif.NUM_BANKS; i++) begin
      if (vif.ram_mem_REN[i] || vif.ram_mem_WEN[i]) begin
        tr = lfc_ram_transaction::type_id::create($sformatf("tr_bank%0d", i));  // create transaction per bank
        tr.bank  = i;
        tr.addr  = vif.ram_mem_addr[i];
        tr.data  = vif.ram_mem_store[i];
        tr.write = vif.ram_mem_WEN[i];
        result_ap.write(tr);
        `uvm_info(get_type_name(),
          $sformatf("Captured RAM TXN: bank=%0d addr=0x%0h data=0x%0h write=%0b",
                    i, tr.addr, tr.data, tr.write),
          UVM_LOW)
      end
    end
  end
  endtask

endclass

`endif
