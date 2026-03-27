`ifndef LFC_CPU_ACTIVE_DRIVER_SV
`define LFC_CPU_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"
`include "lfc_cpu_transaction.sv"

class lfc_cpu_active_driver extends uvm_driver#(lfc_cpu_transaction);
    `uvm_component_utils(lfc_cpu_active_driver)

    virtual lfc_if vif;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if(!uvm_config_db#(virtual lfc_if)::get(this, "", "lfc_vif", vif)) begin
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

    task run_phase(uvm_phase phase);
        lfc_cpu_transaction req_item;
	int down_time;

        DUT_reset(); // 3 clock cycles
        forever begin 
            seq_item_port.get_next_item(req_item);

	    down_time = req_item.down_time;
            vif.mem_in = 1'b1; // not random
            vif.mem_in_addr = req_item.mem_in_addr;
            vif.mem_in_rw_mode = req_item.mem_in_rw_mode; // not random
            vif.mem_in_store_value = req_item.mem_in_store_value;
            vif.dp_in_halt = req_item.dp_in_halt; // not random
            #(0.2ns);
            @(posedge vif.clk);
            vif.mem_in = 1'b0;
	    @(posedge vif.clk);
	    wait(!vif.stall)
	    if(req_item.wait_for_ram) wait(vif.ram_mem_REN == '0 && vif.ram_mem_WEN == '0);
	    seq_item_port.item_done();
	    repeat(down_time) @(posedge vif.clk);
        end
    endtask

endclass

`endif
