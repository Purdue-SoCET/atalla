// lfc_cpu_active_monitor.svh
`ifndef LFC_CPU_ACTIVE_MONITOR_SV
`define LFC_CPU_ACTIVE_MONITOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"
`include "lfc_uuid_transaction.sv" // ARCHITECTURAL BOUNDARY EXCEPTION: active monitor -> scoreboard.

// --- Replace these with your real types if needed ---
typedef virtual lfc_if lfc_cpu_vif_t;   // TODO: interface
//typedef lfc_cpu_item       cpu_txn_t;       // TODO: sequence_item

class lfc_cpu_active_monitor extends uvm_monitor;
  `uvm_component_utils(lfc_cpu_active_monitor)

  // analysis port to scoreboard/subscribers
  //uvm_analysis_port #(lfc_cpu_transaction) lfc_ap;

  // optional: virtual interface handle
  lfc_cpu_vif_t vif;

  uvm_analysis_port#(lfc_cpu_transaction) lfc_ap;
  uvm_analysis_port#(lfc_uuid_transaction) uuid_miss_ap; // ARCHITECTURAL BOUNDARY EXCEPTION: active monitor -> scoreboard. Only used for UUID cross-time linkage check; carries (bank, uuid) at miss time.

  function new(string name, uvm_component parent = null);
    super.new(name, parent);
    lfc_ap = new("lfc_ap", this);
    uuid_miss_ap = new("uuid_miss_ap", this);
  endfunction

  virtual function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    //ap = new("ap", this);
    // optional: get VIF from config_db
    if(!uvm_config_db#(virtual lfc_if)::get(this, "", "lfc_vif", vif)) begin
      `uvm_fatal("CPU_ACTIVE_MON", "No virtual interface specified for this monitor instance")
    end
  endfunction

  // minimal placeholder; add your sampling here
  virtual task run_phase(uvm_phase phase);
    super.run_phase(phase);
    forever begin
      lfc_cpu_transaction tx;
      while(vif.mem_in !== 1'b1) @(negedge vif.clk); // new transaction when mem_in = 1
      	//if(vif.mem_in) begin
	      `uvm_info("CPU_ACTIVE_MON", "sending cpu active tx", UVM_LOW)
	      tx = lfc_cpu_transaction #()::type_id::create("tx");
	      tx.mem_in = 1;
	      tx.mem_in_addr = vif.mem_in_addr;
	      tx.mem_in_rw_mode = vif.mem_in_rw_mode;
	      tx.mem_in_store_value = vif.mem_in_store_value;
	      tx.dp_in_halt = vif.dp_in_halt;
	      @(negedge vif.clk);
	      lfc_ap.write(tx);
	      // ARCHITECTURAL BOUNDARY EXCEPTION: emit (bank, uuid) to scoreboard for UUID link check
	      if (vif.hit == 0) begin
	        lfc_uuid_transaction uuid_tx;
	        uuid_tx = lfc_uuid_transaction::type_id::create("uuid_tx");
	        uuid_tx.bank = (tx.mem_in_addr >> 4) & 3; // addr[5:4]
	        uuid_tx.uuid = vif.mem_out_uuid;
	        `uvm_info("CPU_ACTIVE_MON", $sformatf("UUID MISS captured: bank=%0d uuid=%0h addr=%h", uuid_tx.bank, uuid_tx.uuid, tx.mem_in_addr), UVM_LOW)
	        uuid_miss_ap.write(uuid_tx);
	      end
      //end
    end
  endtask

endclass

`endif // LFC_CPU_ACTIVE_MONITOR_SVH

