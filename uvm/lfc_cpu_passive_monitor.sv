// lfc_cpu_passive_monitor.svh
`ifndef LFC_CPU_PASSIVE_MONITOR_SVH
`define LFC_CPU_PASSIVE_MONITOR_SVH

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"

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

  int loop_counter;
  virtual task run_phase(uvm_phase phase);
    super.run_phase(phase);
    prev_tx = lfc_cpu_transaction::type_id::create("prev_tx");
    
    loop_counter = 0;
    forever begin
        lfc_cpu_transaction tx;
        @(posedge vif.clk);
        tx = lfc_cpu_transaction::type_id::create("tx");

        tx.mem_out_uuid = vif.mem_out_uuid;
        tx.stall = vif.stall;
        tx.hit = vif.hit;
        tx.hit_load = vif.hit_load;
        tx.block_status = vif.block_status;
        tx.uuid_block = vif.uuid_block;
        tx.dp_out_flushed = vif.dp_out_flushed;

        if(!tx.stall && loop_counter > 0) begin
          if(tx.hit == 1 && prev_tx.hit == 0) begin // if new hit, send to scoreboad
            result_ap.write(tx);
          end 

          for(int i = 0; i < tx.NUM_BANKS; i++) begin
            if(tx.block_status[i] && !prev_tx.block_status[i]) begin // uuid is valid, new cache miss, send to scoreboad
              result_ap.write(tx);
            end
          end
        end

        prev_tx.copy(tx); // check for hit on every clock cycle
        loop_counter++;
    end
  endtask

endclass

`endif // LFC_CPU_ACTIVE_MONITOR_SVH
