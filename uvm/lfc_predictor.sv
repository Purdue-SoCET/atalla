`ifndef LFC_PREDICTOR_SV
`define LFC_PREDICTOR_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"
`include "lfc_ram_transaction.sv"

`uvm_analysis_imp_decl(_cpu)
`uvm_analysis_imp_decl(_ram)

class lfc_predictor extends uvm_component;
  `uvm_component_utils(lfc_predictor)

  parameter NUM_BANKS  = 4;
  parameter UUID_SIZE  = 4;
  parameter MAX_MSHR   = 8;
  parameter CACHE_LINES = 256;

  uvm_analysis_imp_cpu #(lfc_cpu_transaction, lfc_predictor) cpu_imp;
  uvm_analysis_imp_ram #(lfc_ram_transaction, lfc_predictor) ram_imp;

  uvm_analysis_port #(lfc_cpu_transaction) pred_cpu_ap;

  // One RAM request port per bank, plus one completion port
  uvm_analysis_port #(lfc_ram_transaction) pred_ram_req_ap [NUM_BANKS];
  uvm_analysis_port #(lfc_ram_transaction) pred_ram_cmp_ap;

  parameter BLOCK_SIZE  = 4;

  bit [31:0] data_model [0:CACHE_LINES-1];
  bit        valid      [0:CACHE_LINES-1];
  int        mshr_occupancy [NUM_BANKS];

  bit        uuid_in_flight [0:(1<<UUID_SIZE)-1];
  bit [31:0] uuid_addr_map  [0:(1<<UUID_SIZE)-1];
  int        uuid_bank_map  [0:(1<<UUID_SIZE)-1];
  int        uuid_index_map [0:(1<<UUID_SIZE)-1];
  int        fill_word_count [0:(1<<UUID_SIZE)-1];

  function new(string name, uvm_component parent);
    super.new(name,parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    cpu_imp = new("cpu_imp", this);
    ram_imp = new("ram_imp", this);

    pred_cpu_ap     = new("pred_cpu_ap", this);
    pred_ram_cmp_ap = new("pred_ram_cmp_ap", this);
    for (int b = 0; b < NUM_BANKS; b++)
      pred_ram_req_ap[b] = new($sformatf("pred_ram_req_ap_%0d", b), this);

    initialize_model();
  endfunction

  function void initialize_model();
    foreach(data_model[i]) data_model[i] = '0;
    foreach(valid[i]) valid[i] = 0;
    foreach(mshr_occupancy[i]) mshr_occupancy[i] = 0;
    foreach(uuid_in_flight[i]) uuid_in_flight[i] = 0;
    foreach(uuid_addr_map[i])  uuid_addr_map[i]  = 0;
    foreach(uuid_bank_map[i])  uuid_bank_map[i]  = -1;
    foreach(uuid_index_map[i]) uuid_index_map[i] = -1;
    foreach(fill_word_count[i]) fill_word_count[i]  = 0;
  endfunction

  function void write_cpu(lfc_cpu_transaction cpu_t);
    lfc_cpu_transaction out_tx;
    out_tx = lfc_cpu_transaction#(NUM_BANKS,UUID_SIZE)::type_id::create("out_tx");
    out_tx.copy(cpu_t);

    handle_cpu_request(cpu_t, out_tx);
    update_stall(out_tx);
    `uvm_info("PRED", $sformatf("write_cpu: addr=%h rw=%0b -> hit=%0b valid[%0d]=%0b", cpu_t.mem_in_addr, cpu_t.mem_in_rw_mode, out_tx.hit, get_index(cpu_t.mem_in_addr), valid[get_index(cpu_t.mem_in_addr)]), UVM_LOW)

    // Only emit on hit, misses are emitted in handle_fill_completion when block fills
    if (out_tx.hit) begin
      pred_cpu_ap.write(out_tx);
    end
  endfunction

  function void handle_cpu_request(
        lfc_cpu_transaction cpu_t,
        ref lfc_cpu_transaction out_tx);

    int index = get_index(cpu_t.mem_in_addr);
    int bank  = get_bank(cpu_t.mem_in_addr);

    if (valid[index]) begin
      process_hit(cpu_t, out_tx, index);
    end else begin
      process_miss(cpu_t, out_tx, index, bank);
    end
  endfunction

  function void process_hit(
        lfc_cpu_transaction cpu_t,
        ref lfc_cpu_transaction out_tx,
        int index);

    out_tx.hit = 1;
    out_tx.mem_out_uuid = 0;

    if (cpu_t.mem_in_rw_mode) begin
      data_model[index] = cpu_t.mem_in_store_value;
      valid[index] = 1;
    end else begin
      out_tx.hit_load = data_model[index];
    end
  endfunction

  function void process_miss(
        lfc_cpu_transaction cpu_t,
        ref lfc_cpu_transaction out_tx,
        int index,
        int bank);

    int new_uuid;
    lfc_ram_transaction exp_req;
    bit [31:0] block_base_addr;
    out_tx.hit = 0;

    // DUT strips bank bits from index when issuing to RAM:
    // ram_addr = addr_t'{tag, {2'b0, index[9:6]}, count_FSM, 0}
    // = {addr[31:10], 2'b0, addr[9:6], 4'b0} (word 0)
    block_base_addr = {cpu_t.mem_in_addr[31:10], 2'b0, cpu_t.mem_in_addr[9:6], 4'b0};

    // Check for secondary miss, same block already in flight, DUT coalesces these
    for (int u = 0; u < (1<<UUID_SIZE); u++) begin
      if (uuid_in_flight[u] && uuid_addr_map[u] == block_base_addr) begin
        `uvm_info("PRED", $sformatf("COALESCE uuid=%0d addr=%h", u, block_base_addr), UVM_LOW)
        out_tx.mem_out_uuid = u;
        return;
      end
    end

    new_uuid = allocate_uuid();
    if (new_uuid == -1) begin
      `uvm_info("PRED", "UUID pool full, DUT is also stalling new misses", UVM_LOW)
      return;
    end

    uuid_in_flight[new_uuid] = 1;
    uuid_addr_map[new_uuid]  = block_base_addr;
    uuid_bank_map[new_uuid]  = bank;
    uuid_index_map[new_uuid] = index;
    mshr_occupancy[bank]++;
    out_tx.mem_out_uuid = new_uuid;
    `uvm_info("PRED", $sformatf("ALLOC uuid=%0d bank=%0d addr=%h mshr_occ=%0d", new_uuid, bank, block_base_addr, mshr_occupancy[bank]), UVM_LOW)

    // For write misses, the written word is pre-filled in the MSHR and skips RAM read.
    // The data_model is updated now; valid[] is set when all RAM words arrive (at FREE).
    if (cpu_t.mem_in_rw_mode) begin
      fill_word_count[new_uuid] = 1; // one word already supplied by the store
      data_model[index] = cpu_t.mem_in_store_value; // store the written value
    end

    // Emit expected REN for only the words that will come from RAM
    for (int w = 0; w < BLOCK_SIZE; w++) begin
      // Skip the written word for write misses (DUT sets write_status and won't issue REN)
      if (cpu_t.mem_in_rw_mode && w == cpu_t.mem_in_addr[3:2]) continue;
      exp_req = lfc_ram_transaction#(NUM_BANKS)::type_id::create("exp_req");
      exp_req.ram_mem_REN[bank]      = 1;
      exp_req.ram_mem_WEN[bank]      = 0;
      exp_req.ram_mem_addr[bank]     = block_base_addr + (w * 4);
      exp_req.ram_mem_complete[bank] = 0;
      pred_ram_req_ap[bank].write(exp_req);
    end

  endfunction

  function int allocate_uuid();
    for (int i = 0; i < (1<<UUID_SIZE); i++)
      if (!uuid_in_flight[i])
        return i;
    return -1;
  endfunction

  function void update_stall(ref lfc_cpu_transaction out_tx);
    int bank = get_bank(out_tx.mem_in_addr);
    out_tx.stall = (mshr_occupancy[bank] >= MAX_MSHR);
  endfunction

  function void write_ram(lfc_ram_transaction ram_t);
    `uvm_info("PRED", $sformatf("write_ram: complete=%b data=%h", ram_t.ram_mem_complete, ram_t.ram_mem_data), UVM_LOW)
    handle_fill_completion(ram_t);
    pred_ram_cmp_ap.write(ram_t);
  endfunction

  function void handle_fill_completion(lfc_ram_transaction ram_t);
    for (int b = 0; b < NUM_BANKS; b++) begin
      if (ram_t.ram_mem_complete[b]) begin
        for (int u = 0; u < (1<<UUID_SIZE); u++) begin
          if (uuid_in_flight[u] && uuid_bank_map[u] == b) begin
            fill_word_count[u]++;
            `uvm_info("PRED", $sformatf("WORD uuid=%0d bank=%0d word=%0d/%0d", u, b, fill_word_count[u], BLOCK_SIZE), UVM_LOW)
            if (fill_word_count[u] == BLOCK_SIZE) begin
              bit [31:0] block_base = uuid_addr_map[u];
              int index = uuid_index_map[u];
              data_model[index] = ram_t.ram_mem_data[b];
              valid[index]      = 1;
              uuid_in_flight[u] = 0;
              uuid_bank_map[u]  = -1;
              uuid_index_map[u] = -1;
              fill_word_count[u] = 0;
              mshr_occupancy[b]--;
              `uvm_info("PRED", $sformatf("FREE uuid=%0d bank=%0d addr=%h mshr_occ=%0d", u, b, block_base, mshr_occupancy[b]), UVM_LOW)
            end
            break;
          end
        end
      end
    end
  endfunction

  function int get_index(bit [31:0] addr);
    return addr[9:4];
  endfunction

  function int get_bank(bit [31:0] addr);
    return addr[5:4];
  endfunction

endclass

`endif

