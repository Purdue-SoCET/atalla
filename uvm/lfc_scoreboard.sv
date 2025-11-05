import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"

class scoreboard extends uvm_scoreboard;
    `uvm_component_utils(scoreboard)

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
    
        lfc_cpu_transaction expected_tx, actual_tx;
        forever begin
            expected_cpu_fifo.get(expected_tx);
            actual_cpu_fifo.get(actual_tx);
            if (expected_tx.stall == actual_tx.stall) begin
                m_matches++;
                `uvm_info("Scoreboard", "CPU stalled correctly", UVM_LOW)
            end else begin
                m_mismatches++;
                `uvm_error("Scoreboard", "CPU stalled incorrectly")
            end
        end
    endtask: run_phase

    function void report_phase(uvm_phase phase);
    // TODO elaborate reporting
        `uvm_info("Scoreboard", $sformatf("Matches:    %0d", m_matches), UVM_NONE)
        `uvm_info("Scoreboard", $sformatf("Mismatches: %0d", m_mismatches), UVM_NONE)
    endfunction: report_phase

endclass: scoreboard
