`ifndef LFC_SCOREBOARD_SV
`define LFC_SCOREBOARD_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"
`include "lfc_uuid_transaction.sv" // ARCHITECTURAL BOUNDARY EXCEPTION: see lfc_environment.sv

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

  // block_status events; used for UUID cross-time linkage check
  uvm_analysis_export#(lfc_cpu_transaction) actual_uuid_cmp_export;

  // ARCHITECTURAL BOUNDARY EXCEPTION: receives (bank, uuid) from active monitor
  uvm_analysis_export#(lfc_uuid_transaction) actual_miss_export;

  // FIFOs
  uvm_tlm_analysis_fifo#(lfc_cpu_transaction) expected_cpu_fifo;
  uvm_tlm_analysis_fifo#(lfc_cpu_transaction) actual_cpu_fifo;

  uvm_tlm_analysis_fifo#(lfc_ram_transaction) expected_ram_req_fifo [NUM_BANKS];
  uvm_tlm_analysis_fifo#(lfc_ram_transaction) actual_ram_req_fifo   [NUM_BANKS];

  uvm_tlm_analysis_fifo#(lfc_ram_transaction) expected_ram_cmp_fifo;
  uvm_tlm_analysis_fifo#(lfc_ram_transaction) actual_ram_cmp_fifo;

  uvm_tlm_analysis_fifo#(lfc_cpu_transaction) actual_uuid_cmp_fifo;
  uvm_tlm_analysis_fifo#(lfc_uuid_transaction) actual_miss_fifo;

  // UUID inflight table: inflight_uuid[bank][uuid] = 1 when in-flight
  bit inflight_uuid [NUM_BANKS][bit [3:0]];

  int match_count;
  int mismatch_count;

  // Per-category counters
  int cpu_miss_match;
  int cpu_hit_match;
  int cpu_hit_mismatch;
  int ram_req_match;
  int ram_req_mismatch;
  int ram_cmp_match;
  int ram_cmp_mismatch;
  int uuid_link_match;
  int uuid_link_mismatch;
  int unmatched_expected_hits;

  function new(string name, uvm_component parent);
    super.new(name, parent);
    match_count    = 0;
    mismatch_count = 0;
    cpu_miss_match         = 0;
    cpu_hit_match          = 0;
    cpu_hit_mismatch       = 0;
    ram_req_match          = 0;
    ram_req_mismatch       = 0;
    ram_cmp_match          = 0;
    ram_cmp_mismatch       = 0;
    uuid_link_match        = 0;
    uuid_link_mismatch     = 0;
    unmatched_expected_hits = 0;
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

    actual_uuid_cmp_export = new("actual_uuid_cmp_export", this);
    actual_miss_export     = new("actual_miss_export",     this);

    expected_cpu_fifo     = new("expected_cpu_fifo",     this);
    actual_cpu_fifo       = new("actual_cpu_fifo",       this);

    expected_ram_cmp_fifo = new("expected_ram_cmp_fifo", this);
    actual_ram_cmp_fifo   = new("actual_ram_cmp_fifo",   this);

    actual_uuid_cmp_fifo = new("actual_uuid_cmp_fifo", this);
    actual_miss_fifo     = new("actual_miss_fifo",      this);
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

    actual_uuid_cmp_export.connect(actual_uuid_cmp_fifo.analysis_export);
    actual_miss_export.connect(actual_miss_fifo.analysis_export);
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

      // Misses: observed only, not counted in match/mismatch totals
      if (!act.hit) begin
        `uvm_info("SB", $sformatf("CPU MISS addr=%h stall=%0b uuid=%0h", act.mem_in_addr, act.stall, act.mem_out_uuid), UVM_LOW)
        cpu_miss_match++;
        continue;
      end

      // Hits: pull the expected and compare
      expected_cpu_fifo.get(exp);

      if (exp == null) begin
        `uvm_error("SB", "Null expected CPU transaction")
        continue;
      end

      `uvm_info("SB", $sformatf("CPU HIT addr=%h hit_load=%h", act.mem_in_addr, act.hit_load), UVM_LOW)

      if (exp.hit !== act.hit) begin
        mismatch_count++;
        cpu_hit_mismatch++;
        `uvm_error("SB",
          $sformatf("HIT mismatch addr=%h exp=%0b act=%0b",
          act.mem_in_addr, exp.hit, act.hit))
        continue;
      end

      if (!act.mem_in_rw_mode) begin
        if (exp.hit_load !== act.hit_load) begin
          mismatch_count++;
          cpu_hit_mismatch++;
          `uvm_error("SB",
            $sformatf("LOAD mismatch addr=%h exp=%h act=%h",
            act.mem_in_addr, exp.hit_load, act.hit_load))
          continue;
        end
      end

      match_count++;
      cpu_hit_match++;
      `uvm_info("SB",
        $sformatf("CPU match addr=%h hit=%0b stall=%0b",
        act.mem_in_addr, act.hit, act.stall),
        UVM_LOW)
    end
  endtask

  // ============================================================
  // MISS UUID RECORDING
  // ============================================================
  // Records (bank, uuid, addr) at miss time for cross-time linkage check.

  function int get_bank(bit [31:0] addr);
    return addr[5:4];
  endfunction

  task record_miss_uuids();
    lfc_uuid_transaction tr;
    forever begin
      actual_miss_fifo.get(tr);
      if (tr == null) continue;
      `uvm_info("SB", $sformatf("UUID INFLIGHT record bank=%0d uuid=%0h", tr.bank, tr.uuid), UVM_LOW)
      inflight_uuid[tr.bank][tr.uuid] = 1; // just mark as in-flight; addr not needed for linkage check
    end
  endtask

  // ============================================================
  // RAM REQUEST COMPARISON, one task per bank
  // ============================================================
  // Expected REQs arrive at CPU request time; actual REN fires much later.
  // Using an address-keyed pending set instead of in-order FIFO pairing.

  bit pending_ram_req        [NUM_BANKS][bit [31:0]]; // expected arrived, waiting for actual
  bit pending_actual_ram_req [NUM_BANKS][bit [31:0]]; // actual arrived early, waiting for expected

  task compare_ram_req_bank(int b);
    lfc_ram_transaction tr;
    fork
      forever begin // expected side
        expected_ram_req_fifo[b].get(tr);
        if (tr == null) continue;
        if (pending_actual_ram_req[b].exists(tr.ram_mem_addr[b])) begin
          // actual already arrived; match it now
          pending_actual_ram_req[b].delete(tr.ram_mem_addr[b]);
          match_count++;
          ram_req_match++;
          `uvm_info("SB", $sformatf("RAM REQ match bank=%0d addr=%h (expected late)", b, tr.ram_mem_addr[b]), UVM_LOW)
        end else begin
          pending_ram_req[b][tr.ram_mem_addr[b]] = 1;
        end
      end
      forever begin // actual side
        actual_ram_req_fifo[b].get(tr);
        if (tr == null) continue;
        if (pending_ram_req[b].exists(tr.ram_mem_addr[b])) begin
          pending_ram_req[b].delete(tr.ram_mem_addr[b]);
          match_count++;
          ram_req_match++;
          `uvm_info("SB", $sformatf("RAM REQ match bank=%0d addr=%h", b, tr.ram_mem_addr[b]), UVM_LOW)
        end else begin
          // expected not yet arrived; store actual and wait
          pending_actual_ram_req[b][tr.ram_mem_addr[b]] = 1;
          `uvm_info("SB", $sformatf("RAM REQ actual bank=%0d addr=%h arrived before expected, buffering", b, tr.ram_mem_addr[b]), UVM_LOW)
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
              ram_cmp_mismatch++;
              `uvm_error("SB",
                $sformatf("RAM CMP mismatch bank=%0d: exp complete=%0b act complete=%0b",
                b, exp.ram_mem_complete[b], act.ram_mem_complete[b]))
            end else if (exp.ram_mem_addr[b] !== act.ram_mem_addr[b]) begin
              ok = 0;
              mismatch_count++;
              ram_cmp_mismatch++;
              `uvm_error("SB",
                $sformatf("RAM CMP ADDR mismatch bank=%0d: exp=%h act=%h",
                b, exp.ram_mem_addr[b], act.ram_mem_addr[b]))
            end
          end
        end
        if (ok) begin
          match_count++;
          ram_cmp_match++;
          `uvm_info("SB", "RAM CMP match", UVM_LOW)
        end
      end
    end
  endtask

  // ============================================================
  // UUID CROSS-TIME LINKAGE CHECK
  // ============================================================
  // On block_status[b]: verify uuid_block[b] was previously recorded as in-flight at miss time (via the active monitor's uuid_miss_ap).

  task compare_uuid_cmp();
    lfc_cpu_transaction tr;

    forever begin
      actual_uuid_cmp_fifo.get(tr);
      if (tr == null) continue;

      for (int b = 0; b < NUM_BANKS; b++) begin
        if (tr.block_status[b]) begin
          if ($isunknown(tr.uuid_block[b])) begin
            mismatch_count++;
            uuid_link_mismatch++;
            `uvm_error("SB", $sformatf("UUID LINK bank=%0d: uuid_block is unknown on block_status", b))
          end else if (inflight_uuid[b].exists(tr.uuid_block[b])) begin
            match_count++;
            uuid_link_match++;
            `uvm_info("SB",
              $sformatf("UUID LINK match bank=%0d uuid=%0h", b, tr.uuid_block[b]),
              UVM_LOW)
            inflight_uuid[b].delete(tr.uuid_block[b]);
          end else begin
            mismatch_count++;
            uuid_link_mismatch++;
            `uvm_error("SB",
              $sformatf("UUID LINK bank=%0d uuid=%0h completed but was never recorded at miss time",
              b, tr.uuid_block[b]))
          end
        end
      end
    end
  endtask

  task run_phase(uvm_phase phase);
    fork
      compare_cpu();
      compare_ram_req_bank(0);
      compare_ram_req_bank(1);
      compare_ram_req_bank(2);
      compare_ram_req_bank(3);
      compare_ram_cmp();
      record_miss_uuids();
      compare_uuid_cmp();
    join
  endtask

  // Drain leftover expected entries: these represent cases where the predictor expected a hit but the DUT never produced one (predictor predicts hit but DUT misses).
  function void check_phase(uvm_phase phase);
    lfc_cpu_transaction exp;
    int leftover = 0;
    // Drain actual RAM REQs that never got a matching expected: true mismatches
    for (int b = 0; b < NUM_BANKS; b++) begin
      foreach (pending_actual_ram_req[b][addr]) begin
        mismatch_count++;
        ram_req_mismatch++;
        `uvm_error("SB", $sformatf("RAM REQ unmatched actual bank=%0d addr=%h (no expected ever arrived)", b, addr))
      end
    end
    while (expected_cpu_fifo.try_get(exp)) begin
      leftover++;
      mismatch_count++;
      cpu_hit_mismatch++;
      unmatched_expected_hits++;
      `uvm_error("SB",
        $sformatf("Unmatched expected HIT addr=%h hit_load=%h (DUT never produced this hit)",
        exp.mem_in_addr, exp.hit_load))
    end
    if (leftover > 0)
      `uvm_info("SB", $sformatf("%0d unmatched expected hits drained", leftover), UVM_LOW)
  endfunction

  function void report_phase(uvm_phase phase);
    string s;
    s = "\n------------------------------------------------------------\n";
    s = {s, "  SCOREBOARD SUMMARY\n"};
    s = {s, "------------------------------------------------------------\n"};
    s = {s, $sformatf("  Total Matches   : %0d\n", match_count)};
    s = {s, $sformatf("  Total Mismatches: %0d\n", mismatch_count)};
    s = {s, "------------------------------------------------------------\n"};
    s = {s, $sformatf("  CPU Misses (observed): %0d\n", cpu_miss_match)};
    s = {s, "  (not included in match/mismatch totals)\n"};
    s = {s, "------------------------------------------------------------\n"};
    s = {s, $sformatf("  CPU Hit   matches   : %0d    mismatches: %0d\n", cpu_hit_match, cpu_hit_mismatch)};
    s = {s, $sformatf("    (unmatched expected hits: %0d)\n", unmatched_expected_hits)};
    s = {s, $sformatf("  RAM REQ   matches   : %0d    mismatches: %0d\n", ram_req_match, ram_req_mismatch)};
    s = {s, $sformatf("  RAM CMP   matches   : %0d    mismatches: %0d\n", ram_cmp_match, ram_cmp_mismatch)};
    s = {s, $sformatf("  UUID LINK matches   : %0d    mismatches: %0d\n", uuid_link_match, uuid_link_mismatch)};
    s = {s, "------------------------------------------------------------"};
    `uvm_info("SCOREBOARD", s, UVM_NONE)
  endfunction

endclass

`endif



