`ifndef LFC_SCOREBOARD_SV
`define LFC_SCOREBOARD_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"

class lfc_scoreboard extends uvm_scoreboard;
  `uvm_component_utils(lfc_scoreboard)

  parameter NUM_BANKS = 4;

  // Analysis exports
  uvm_analysis_export#(lfc_cpu_transaction) expected_cpu_export;
  uvm_analysis_export#(lfc_cpu_transaction) actual_cpu_export;

  // RAM request check, one pair per bank
  uvm_analysis_export#(lfc_ram_transaction) expected_ram_req_export [NUM_BANKS];
  uvm_analysis_export#(lfc_ram_transaction) actual_ram_req_export   [NUM_BANKS];

  // RAM completion check
  uvm_analysis_export#(lfc_ram_transaction) expected_ram_cmp_export;
  uvm_analysis_export#(lfc_ram_transaction) actual_ram_cmp_export;

  // FIFOs
  uvm_tlm_analysis_fifo#(lfc_cpu_transaction) expected_cpu_fifo;
  uvm_tlm_analysis_fifo#(lfc_cpu_transaction) actual_cpu_fifo;

  uvm_tlm_analysis_fifo#(lfc_ram_transaction) expected_ram_req_fifo [NUM_BANKS];
  uvm_tlm_analysis_fifo#(lfc_ram_transaction) actual_ram_req_fifo   [NUM_BANKS];

  uvm_tlm_analysis_fifo#(lfc_ram_transaction) expected_ram_cmp_fifo;
  uvm_tlm_analysis_fifo#(lfc_ram_transaction) actual_ram_cmp_fifo;

  int match_count;
  int mismatch_count;

  function new(string name, uvm_component parent);
    super.new(name, parent);
    match_count    = 0;
    mismatch_count = 0;
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    expected_cpu_export = new("expected_cpu_export", this);
    actual_cpu_export   = new("actual_cpu_export",   this);

    for (int b = 0; b < NUM_BANKS; b++) begin
      expected_ram_req_export[b] = new($sformatf("expected_ram_req_export_%0d", b), this);
      actual_ram_req_export[b]   = new($sformatf("actual_ram_req_export_%0d",   b), this);
      expected_ram_req_fifo[b]   = new($sformatf("expected_ram_req_fifo_%0d",   b), this);
      actual_ram_req_fifo[b]     = new($sformatf("actual_ram_req_fifo_%0d",     b), this);
    end

    expected_ram_cmp_export = new("expected_ram_cmp_export", this);
    actual_ram_cmp_export   = new("actual_ram_cmp_export",   this);

    expected_cpu_fifo     = new("expected_cpu_fifo",     this);
    actual_cpu_fifo       = new("actual_cpu_fifo",       this);

    expected_ram_cmp_fifo = new("expected_ram_cmp_fifo", this);
    actual_ram_cmp_fifo   = new("actual_ram_cmp_fifo",   this);
  endfunction

  function void connect_phase(uvm_phase phase);
    expected_cpu_export.connect(expected_cpu_fifo.analysis_export);
    actual_cpu_export.connect(actual_cpu_fifo.analysis_export);

    for (int b = 0; b < NUM_BANKS; b++) begin
      expected_ram_req_export[b].connect(expected_ram_req_fifo[b].analysis_export);
      actual_ram_req_export[b].connect(actual_ram_req_fifo[b].analysis_export);
    end

    expected_ram_cmp_export.connect(expected_ram_cmp_fifo.analysis_export);
    actual_ram_cmp_export.connect(actual_ram_cmp_fifo.analysis_export);
  endfunction

  // ============================================================
  // CPU COMPARISON
  // ============================================================

  task compare_cpu();
    lfc_cpu_transaction exp, act;

    forever begin
      actual_cpu_fifo.get(act);

      if (act == null) begin
        `uvm_error("SB", "Null CPU transaction")
        continue;
      end

      if ($isunknown(act.hit) || $isunknown(act.stall))
        continue;

      // Miss-completions (block_status events) are not predicted, just log them
      if (!act.hit) begin
        `uvm_info("SB", $sformatf("CPU MISS addr=%h stall=%0b", act.mem_in_addr, act.stall), UVM_LOW)
        match_count++;
        continue;
      end

      // For hits, pull the expected and compare
      expected_cpu_fifo.get(exp);

      if (exp == null) begin
        `uvm_error("SB", "Null expected CPU transaction")
        continue;
      end

      `uvm_info("SB", $sformatf("CPU HIT addr=%h hit_load=%h", act.mem_in_addr, act.hit_load), UVM_LOW)

      if (exp.hit !== act.hit) begin
        mismatch_count++;
        `uvm_error("SB",
          $sformatf("HIT mismatch addr=%h exp=%0b act=%0b",
          act.mem_in_addr, exp.hit, act.hit))
        continue;
      end

      if (!act.mem_in_rw_mode) begin
        if (exp.hit_load !== act.hit_load) begin
          mismatch_count++;
          `uvm_error("SB",
            $sformatf("LOAD mismatch addr=%h exp=%h act=%h",
            act.mem_in_addr, exp.hit_load, act.hit_load))
          continue;
        end
      end

      match_count++;
      `uvm_info("SB",
        $sformatf("CPU match addr=%h hit=%0b stall=%0b",
        act.mem_in_addr, act.hit, act.stall),
        UVM_LOW)
    end
  endtask

  // ============================================================
  // RAM REQUEST COMPARISON, one task per bank
  // ============================================================
  // Expected REQs arrive at CPU request time; actual REN fires much later.
  // Using an address-keyed pending set instead of in-order FIFO pairing.

  bit pending_ram_req [NUM_BANKS][bit [31:0]];

  task compare_ram_req_bank(int b);
    lfc_ram_transaction tr;
    fork
      forever begin // expected side: add to pending set
        expected_ram_req_fifo[b].get(tr);
        if (tr == null) continue;
        pending_ram_req[b][tr.ram_mem_addr[b]] = 1;
      end
      forever begin // actual side: look up in pending set
        actual_ram_req_fifo[b].get(tr);
        if (tr == null) continue;
        if (pending_ram_req[b].exists(tr.ram_mem_addr[b])) begin
          pending_ram_req[b].delete(tr.ram_mem_addr[b]);
          match_count++;
          `uvm_info("SB", $sformatf("RAM REQ match bank=%0d addr=%h", b, tr.ram_mem_addr[b]), UVM_LOW)
        end else begin
          mismatch_count++;
          `uvm_error("SB",
            $sformatf("RAM REQ unexpected bank=%0d addr=%h (no matching expected)",
            b, tr.ram_mem_addr[b]))
        end
      end
    join
  endtask

  // ============================================================
  // RAM COMPLETION COMPARISON
  // ============================================================

  task compare_ram_cmp();
    lfc_ram_transaction exp, act;

    forever begin
      expected_ram_cmp_fifo.get(exp);
      actual_ram_cmp_fifo.get(act);

      if (exp == null || act == null) begin
        `uvm_error("SB", "Null RAM completion transaction")
        continue;
      end

      begin
        bit ok = 1;
        for (int b = 0; b < NUM_BANKS; b++) begin
          if (act.ram_mem_complete[b]) begin
            `uvm_info("SB",
              $sformatf("RAM FILL complete bank=%0d addr=%h data=%h",
              b, act.ram_mem_addr[b], act.ram_mem_data[b]),
              UVM_LOW)
            if (exp.ram_mem_complete[b] !== act.ram_mem_complete[b]) begin
              ok = 0;
              mismatch_count++;
              `uvm_error("SB",
                $sformatf("RAM CMP mismatch bank=%0d: exp complete=%0b act complete=%0b",
                b, exp.ram_mem_complete[b], act.ram_mem_complete[b]))
            end else if (exp.ram_mem_addr[b] !== act.ram_mem_addr[b]) begin
              ok = 0;
              mismatch_count++;
              `uvm_error("SB",
                $sformatf("RAM CMP ADDR mismatch bank=%0d: exp=%h act=%h",
                b, exp.ram_mem_addr[b], act.ram_mem_addr[b]))
            end
          end
        end
        if (ok) begin
          match_count++;
          `uvm_info("SB", "RAM CMP match", UVM_LOW)
        end
      end
    end
  endtask

  task run_phase(uvm_phase phase);
    fork
      compare_cpu();
      for (int b = 0; b < NUM_BANKS; b++) begin
        automatic int bank = b;
        compare_ram_req_bank(bank);
      end
      compare_ram_cmp();
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


