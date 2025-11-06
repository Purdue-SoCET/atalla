`ifndef LFC_RAM_ACTIVE_DRIVER_SV
`define LFC_RAM_ACTIVE_DRIVER_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_if.sv"
`include "lfc_ram_transaction.sv"


class ram_model;
  parameter int NUM_BANKS = 4;
  bit [31:0] mem [longint unsigned];  // key = {bank, addr}

  function longint unsigned flat_addr(int bank, bit [31:0] addr);
    return (longint'(bank) << 32) | addr;
  endfunction

  function void write(int bank, bit [31:0] addr, bit [31:0] data);
    mem[flat_addr(bank, addr)] = data;
  endfunction

  function bit [31:0] read(int bank, bit [31:0] addr);
    if (mem.exists(flat_addr(bank, addr)))
      return mem[flat_addr(bank, addr)];
    else
      return '0;
  endfunction
endclass











class lfc_ram_active_driver extends uvm_driver#(lfc_cpu_transaction);
    `uvm_component_utils(lfc_ram_active_driver)

    virtual lfc_if vif;
    ram_model m_ram;
    localparam int MEM_LATENCY = 5; // latency in cycles if we need this

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

    virtual task run_phase(uvm_phase phase);
    lfc_ram_transaction tr;
    @(posedge vif.n_rst);

    forever begin
        //  bank REN/WEN
        @(posedge vif.clk);
        for (int b = 0; b < vif.NUM_BANKS; b++) begin
        if (vif.ram_mem_REN[b]) begin
            tr = lfc_ram_transaction::type_id::create($sformatf("READ_bank%0d", b));
            tr.bank_id = b;
            tr.write   = 0;
            tr.addr    = vif.ram_mem_addr[b];
            tr.data    = m_ram.read(b, tr.addr);

            // simulate delay - returning data
            repeat (MEM_LATENCY) @(posedge vif.clk);
            vif.ram_mem_data[b]     = tr.data;
            vif.ram_mem_complete[b] = 1'b1;
            @(posedge vif.clk);
            vif.ram_mem_complete[b] = 1'b0;

            `uvm_info("RAM_DRV",
            $sformatf("READ bank=%0d addr=0x%08h data=0x%08h",
                        b, tr.addr, tr.data),
            UVM_MEDIUM)
        end
        else if (vif.ram_mem_WEN[b]) begin
            tr = lfc_ram_transaction::type_id::create($sformatf("WRITE_bank%0d", b));
            tr.bank_id = b;
            tr.write   = 1;
            tr.addr    = vif.ram_mem_addr[b];
            tr.data    = vif.ram_mem_store[b];
            m_ram.write(b, tr.addr, tr.data);

            // simulate write done
            repeat (MEM_LATENCY) @(posedge vif.clk);
            vif.ram_mem_complete[b] = 1'b1;
            @(posedge vif.clk);
            vif.ram_mem_complete[b] = 1'b0;

            `uvm_info("RAM_DRV",
            $sformatf("WRITE bank=%0d addr=0x%08h data=0x%08h",
                        b, tr.addr, tr.data),
            UVM_MEDIUM)
        end
        end
    end
    endtask

endclass

`endif