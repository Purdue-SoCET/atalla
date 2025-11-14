`ifndef LFC_PREDICTOR_SV
`define LFC_PREDICTOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"
`include "lfc_if.sv"



`uvm_analysis_imp_decl(_cpu)
`uvm_analysis_imp_decl(_ram)

// class lfc_predictor extends uvm_subscriber#(lfc_cpu_transaction, lfc_ram_transaction);
class lfc_predictor extends uvm_component#(lfc_cpu_transaction, lfc_ram_transaction);
    `uvm_component_utils(lfc_predictor)

    parameter NUM_BANKS = 4;
    parameter UUID_SIZE = 4;

    uvm_analysis_imp_cpu#(lfc_cpu_transaction, lfc_predictor) cpu_imp;
    uvm_analysis_imp_ram#(lfc_ram_transaction, lfc_predictor) ram_imp;

    uvm_analysis_port#(lfc_cpu_transaction) pred_cpu_ap;
    uvm_analysis_port#(lfc_ram_transaction) pred_ram_ap;

    // lfc_cpu_transaction output_cpu_tx;
    // lfc_ram_transaction output_ram_tx;

    // uvm_tlm_analysis_fifo#(lfc_cpu_transaction) expected_MSHR;
    int MSHR_occupancy = 0;
    logic [31:0] data_model [0:31];
    logic [31:0] data_is_in_cache = 32'b0;
    

    function new(string name, uvm_component parent = null);
        super.new(name, parent);
    endfunction: new

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        cpu_imp = new("cpu_imp", this);
        ram_imp = new("ram_imp", this);
        pred_cpu_ap = new("pred_cpu_ap", this);
        pred_ram_ap = new("pred_ram_ap", this);
    endfunction: build_phase

    // --------- CPU transaction analysis write method ---------
    function void write_cpu(lfc_cpu_transaction cpu_t);
        lfc_cpu_transaction out_cpu;
        out_cpu = lfc_cpu_transaction#(NUM_BANKS, UUID_SIZE)::type_id::create("out_cpu");
        out_cpu.copy(cpu_t);

        out_cpu.mem_out_uuid = 0; // value for write, should look into default read value
        out_cpu.hit = data_is_in_cache[cpu_t.mem_in_addr];
        if (out_cpu.hit) begin
        if (cpu_t.mem_in_rw_mode)
            data_model[cpu_t.mem_in_addr] = cpu_t.mem_in_store_value;
        else
            out_cpu.hit_load = data_model[cpu_t.mem_in_addr];
        end else begin
        MSHR_occupancy++;
        end

        out_cpu.stall = (MSHR_occupancy > 8);
        pred_cpu_ap.write(out_cpu);
    endfunction



    // --------- RAM transaction analysis write method ---------
    function void write_ram(lfc_ram_transaction ram_t);
        lfc_ram_transaction out_ram;
        out_ram = lfc_ram_transaction#(NUM_BANKS)::type_id::create("out_ram");
        out_ram.copy(ram_t);

        if (ram_t.ram_mem_complete && MSHR_occupancy > 0)
        MSHR_occupancy--;

        pred_ram_ap.write(out_ram);
    endfunction





    // function void write(lfc_cpu_transaction cpu_t, lfc_ram_transaction ram_t);
    //     output_cpu_tx = lfc_cpu_transaction#(NUM_BANKS, UUID_SIZE)::type_id::create("output_cpu_tx");
    //     output_ram_tx = lfc_ram_transaction#(NUM_BANKS)::type_id::create("output_ram_tx");
    //     output_cpu_tx.copy(cpu_t);
    //     output_ram_tx.copy(ram_t);

    //     // TODO: calculate expected outputs below

    //     cpu_t.hit = data_is_in_cache[cpu_t.mem_in_addr];

    //     if (cpu_t.hit) begin //  cache hit
    //         if (cpu_t.mem_in_rw_mode) begin // write
    //             data_model[cpu_t.mem_in_addr] = cpu_t.mem_in_store_value;
    //             data_is_in_cache[cpu_t.mem_in_addr] = 1'b1;
    //         end else begin // read
    //             cpu_t.hit_load = data_model[cpu_t.mem_in_addr];
    //             `uvm_info("predictor", $sformatf("if hit and doing read:    %0d", cpu_t.hit_load), UVM_NONE)
    //         end
    //     end
        
    //     if (!cpu_t.hit) begin // cache miss
    //         MSHR_occupancy++;

    //         // add transaction to a fifo
    //         // expected_MSHR.push(cpu_t)
    //     end 

    //     if (ram_t.ram_mem_complete) begin // a cache miss is being serviced
    //         MSHR_occupancy--;

    //         // remove transaction from fifo corresponding to ram_t.ram_mem_addr
    //         // expected_MSHR.pop[ram_t.ram_mem_addr];
    //     end

    //     if (MSHR_occupancy > 8) begin // overflow of MSHR buffer
    //         cpu_t.stall = 1;
    //     end else begin
    //         cpu_t.stall = 0;
    //     end

    //     pred_cpu_ap.write(output_cpu_tx);
    //     pred_ram_ap.write(output_ram_tx);
    // endfunction: write


    endclass: lfc_predictor

`endif