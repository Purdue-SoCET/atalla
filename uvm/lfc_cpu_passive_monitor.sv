// lfc_cpu_passive_monitor.svh
`ifndef LFC_CPU_PASSIVE_MONITOR_SV
`define LFC_CPU_PASSIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"
`include "lfc_cpu_transaction.sv"

// --- Replace these with your real types if needed ---
//typedef virtual lfc_if lfc_cpu_vif_t; 
//typedef lfc_cpu_item       cpu_txn_t;     

class lfc_cpu_passive_monitor extends uvm_monitor;
  `uvm_component_utils(lfc_cpu_passive_monitor)

  // analysis port to scoreboard/subscribers
  //uvm_analysis_port #(cpu_txn_t) ap;

  // optional: virtual interface handle
  virtual lfc_if vif;
  lfc_cpu_transaction prev_tx;

  uvm_analysis_port#(lfc_cpu_transaction) result_ap;

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    result_ap = new("result", this);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    //ap = new("ap", this);
    // optional: get VIF from config_db
    if(!uvm_config_db#(virtual lfc_if)::get(this, "", "lfc_vif", vif)) begin
      `uvm_fatal("Monitor", "No virtual interface specified for this monitor instance")
    end
  endfunction

  int has_run_once;
 virtual task run_phase(uvm_phase phase);
  super.run_phase(phase);
  prev_tx = lfc_cpu_transaction::type_id::create("prev_tx");
  has_run_once = 0;

  `uvm_info("CPU_MON", "Entered run_phase of CPU monitor", UVM_LOW)

  forever begin
    lfc_cpu_transaction tx;
    @(posedge vif.clk);
    tx = lfc_cpu_transaction::type_id::create("tx");

    tx.mem_out_uuid     = vif.mem_out_uuid;
    tx.stall            = vif.stall;
    tx.hit              = vif.hit;
    tx.hit_load         = vif.hit_load;
    tx.block_status     = vif.block_status;
    tx.uuid_block       = vif.uuid_block;
    tx.dp_out_flushed   = vif.dp_out_flushed;

    `uvm_info("CPU_MON", $sformatf("Sampled: uuid=%0d stall=%0b hit=%0b flushed=%0b",
                  tx.mem_out_uuid, tx.stall, tx.hit, tx.dp_out_flushed), UVM_LOW)

    if (has_run_once > 0 && vif.n_rst) begin
      if (!$isunknown(tx.stall) && !$isunknown(tx.hit)) begin
        result_ap.write(tx);
        `uvm_info("CPU_MON", $sformatf("Sent tx: uuid=%0h stall=%0b hit=%0b flushed=%0b",
                    tx.mem_out_uuid, tx.stall, tx.hit, tx.dp_out_flushed), UVM_LOW)
      end
    end

    prev_tx.copy(tx);
    if (has_run_once == 0) has_run_once++;
  end
endtask


endclass

`endif // LFC_CPU_ACTIVE_MONITOR_SVH