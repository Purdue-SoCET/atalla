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

  int match_count;
  int mismatch_count;

  function new(string name, uvm_component parent);
    super.new(name,parent);
    match_count = 0;
    mismatch_count = 0;
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    expected_cpu_export = new("expected_cpu_export", this);
    actual_cpu_export   = new("actual_cpu_export", this);
    expected_ram_export = new("expected_ram_export", this);
    actual_ram_export   = new("actual_ram_export", this);

    expected_cpu_fifo = new("expected_cpu_fifo", this);
    actual_cpu_fifo   = new("actual_cpu_fifo", this);
    expected_ram_fifo = new("expected_ram_fifo", this);
    actual_ram_fifo   = new("actual_ram_fifo", this);
  endfunction

  function void connect_phase(uvm_phase phase);
    expected_cpu_export.connect(expected_cpu_fifo.analysis_export);
    actual_cpu_export.connect(actual_cpu_fifo.analysis_export);
    expected_ram_export.connect(expected_ram_fifo.analysis_export);
    actual_ram_export.connect(actual_ram_fifo.analysis_export);
  endfunction

  // ============================================================
  // CPU COMPARISON
  // ============================================================

  task compare_cpu();
    lfc_cpu_transaction exp, act;

    forever begin
      expected_cpu_fifo.get(exp);
      actual_cpu_fifo.get(act);

      if (exp == null || act == null) begin
        `uvm_error("SB", "Null CPU transaction")
        continue;
      end

      // Skip unknowns
      if ($isunknown(act.hit) || $isunknown(act.stall))
        continue;

      // hit / miss correctness
      if (exp.hit !== act.hit) begin
        mismatch_count++;
        `uvm_error("SB",
          $sformatf("HIT mismatch addr=%h exp=%0b act=%0b",
          act.mem_in_addr, exp.hit, act.hit))
        continue;
      end

      // Log hit or miss
      if (act.hit)
        `uvm_info("SB", $sformatf("CPU HIT addr=%h hit_load=%h", act.mem_in_addr, act.hit_load), UVM_LOW)
      else
        `uvm_info("SB", $sformatf("CPU MISS addr=%h stall=%0b", act.mem_in_addr, act.stall), UVM_LOW)

      // load data correctness (only for reads)
      if (!act.mem_in_rw_mode && act.hit) begin
        if (exp.hit_load !== act.hit_load) begin
          mismatch_count++;
          `uvm_error("SB",
            $sformatf("LOAD mismatch addr=%h exp=%h act=%h",
            act.mem_in_addr, exp.hit_load, act.hit_load))
          continue;
        end
      end

      // Stall correctness
      if (exp.stall !== act.stall) begin
        mismatch_count++;
        `uvm_error("SB",
          $sformatf("STALL mismatch addr=%h exp=%0b act=%0b",
          act.mem_in_addr, exp.stall, act.stall))
        continue;
      end

      match_count++;
      `uvm_info("SB",
        $sformatf("CPU match addr=%h hit=%0b stall=%0b",
        act.mem_in_addr, act.hit, act.stall),
        UVM_LOW)
    end
  endtask

task compare_ram();
  lfc_ram_transaction exp, act;
  int b;
  bit ram_ok;

  forever begin
    expected_ram_fifo.get(exp);
    actual_ram_fifo.get(act);

    if (exp == null || act == null) begin
      `uvm_error("SB", "Null RAM transaction")
      continue;
    end

    ram_ok = 1; // assume match

    for (b = 0; b < NUM_BANKS; b = b + 1) begin
      // Check request phase (not complete)
      if (!act.ram_mem_complete[b]) begin
        if (exp.ram_mem_REN[b] !== act.ram_mem_REN[b] ||
            exp.ram_mem_WEN[b] !== act.ram_mem_WEN[b] ||
            exp.ram_mem_addr[b] !== act.ram_mem_addr[b]) begin
          ram_ok = 0;
          mismatch_count++;
          `uvm_error("SB", $sformatf("RAM request mismatch bank=%0d addr=%h exp: REN=%0b WEN=%0b act: REN=%0b WEN=%0b",
            b, act.ram_mem_addr[b],
            exp.ram_mem_REN[b], exp.ram_mem_WEN[b],
            act.ram_mem_REN[b], act.ram_mem_WEN[b]))
        end
      end

      // Log fill completions
      if (act.ram_mem_complete[b]) begin
        `uvm_info("SB", $sformatf("RAM FILL complete bank=%0d addr=%h data=%h",
          b, act.ram_mem_addr[b], act.ram_mem_data[b]), UVM_LOW)
      end
    end

    if (ram_ok) begin
      match_count++;
      `uvm_info("SB", "RAM transaction match", UVM_LOW);
    end
  end
endtask

  task run_phase(uvm_phase phase);
    fork
      compare_cpu();
      compare_ram();
    join
  endtask

  function void report_phase(uvm_phase phase);
    `uvm_info("SCOREBOARD",
      $sformatf("Matches: %0d  Mismatches: %0d",
      match_count, mismatch_count),
      UVM_NONE)
  endfunction

endclass

`endif
