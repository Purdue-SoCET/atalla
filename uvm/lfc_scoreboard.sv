`ifndef LFC_SCOREBOARD_SV
`define LFC_SCOREBOARD_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"

class lfc_scoreboard extends uvm_scoreboard;
    `uvm_component_utils(lfc_scoreboard)

    // Analysis exports
    uvm_analysis_export#(lfc_cpu_transaction) expected_cpu_export;
    uvm_analysis_export#(lfc_cpu_transaction) actual_cpu_export;
    uvm_analysis_export#(lfc_ram_transaction) expected_ram_export;
    uvm_analysis_export#(lfc_ram_transaction) actual_ram_export;

    // FIFOs
    uvm_tlm_analysis_fifo#(lfc_cpu_transaction) expected_cpu_fifo;
    uvm_tlm_analysis_fifo#(lfc_cpu_transaction) actual_cpu_fifo;
    uvm_tlm_analysis_fifo#(lfc_ram_transaction) expected_ram_fifo;
    uvm_tlm_analysis_fifo#(lfc_ram_transaction) actual_ram_fifo;

    int m_matches;
    int m_mismatches;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        m_matches = 0;
        m_mismatches = 0;
    endfunction: new

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        expected_cpu_export = new("expected_cpu_export", this);
        actual_cpu_export   = new("actual_cpu_export", this);
        expected_ram_export = new("expected_ram_export", this);
        actual_ram_export   = new("actual_ram_export", this);
        expected_cpu_fifo   = new("expected_cpu_fifo", this);
        actual_cpu_fifo     = new("actual_cpu_fifo", this);
        expected_ram_fifo   = new("expected_ram_fifo", this);
        actual_ram_fifo     = new("actual_ram_fifo", this);
    endfunction: build_phase

    function void connect_phase(uvm_phase phase);
        expected_cpu_export.connect(expected_cpu_fifo.analysis_export);
        actual_cpu_export.connect(actual_cpu_fifo.analysis_export);
        expected_ram_export.connect(expected_ram_fifo.analysis_export);
        actual_ram_export.connect(actual_ram_fifo.analysis_export);
    endfunction: connect_phase

    task run_phase(uvm_phase phase);
        //TODO elaborate comparison logic
    
        lfc_cpu_transaction exp_tx, act_tx;
        forever begin
            expected_cpu_fifo.get(exp_tx);
            actual_cpu_fifo.get(act_tx);
            if (exp_tx == null || act_tx == null) begin
              `uvm_error("SCOREBOARD", "Received null transaction")
              continue;
            end
            
            if ($isunknown(act_tx.stall) || $isunknown(act_tx.hit)) begin
                `uvm_warning("SCOREBOARD", $sformatf("Skipping tx with unknown values: uuid=%0d", act_tx.mem_out_uuid))
                continue;
            end
            
            if ($isunknown(exp_tx.mem_out_uuid)) begin
                `uvm_warning("SCOREBOARD", $sformatf("Skipping exp_tx with unknown UUID: %0d", exp_tx.mem_out_uuid))
                continue;
            end
            // UUID match check
            if (exp_tx.mem_out_uuid !== act_tx.mem_out_uuid) begin
                m_mismatches++;
                `uvm_error("SCOREBOARD", $sformatf("UUID mismatch: Expected %0d, Got %0d", exp_tx.mem_out_uuid, act_tx.mem_out_uuid))
                continue;
            end

            // Stall check
            if (exp_tx.stall !== act_tx.stall) begin
                m_mismatches++;
                `uvm_error("SCOREBOARD", $sformatf("STALL mismatch (uuid=%0d): Expected %0b, Got %0b",
                    exp_tx.mem_out_uuid, exp_tx.stall, act_tx.stall))
            end else begin
                m_matches++;
                `uvm_info("SCOREBOARD", $sformatf("STALL match (uuid=%0d): stall=%0b", act_tx.mem_out_uuid, act_tx.stall), UVM_LOW)
            end
        end
    endtask: run_phase

    function void report_phase(uvm_phase phase);
    // TODO elaborate reporting
        `uvm_info("Scoreboard", $sformatf("Matches:    %0d", m_matches), UVM_NONE)
        `uvm_info("Scoreboard", $sformatf("Mismatches: %0d", m_mismatches), UVM_NONE)
    endfunction: report_phase

endclass: lfc_scoreboard

`endif