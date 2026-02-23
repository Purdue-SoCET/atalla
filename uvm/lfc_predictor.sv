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
  uvm_analysis_port #(lfc_ram_transaction) pred_ram_ap;

  bit [31:0] data_model [0:CACHE_LINES-1];
  bit        valid      [0:CACHE_LINES-1];
  int        mshr_occupancy [NUM_BANKS];

  bit        uuid_in_flight [0:(1<<UUID_SIZE)-1];
  bit [31:0] uuid_addr_map  [0:(1<<UUID_SIZE)-1];

  function new(string name, uvm_component parent);
    super.new(name,parent);
  endfunction

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);

    cpu_imp = new("cpu_imp", this);
    ram_imp = new("ram_imp", this);

    pred_cpu_ap = new("pred_cpu_ap", this);
    pred_ram_ap = new("pred_ram_ap", this);

    initialize_model();
  endfunction

  function void initialize_model();
    foreach(data_model[i]) data_model[i] = '0;
    foreach(valid[i]) valid[i] = 0;
    foreach(mshr_occupancy[i]) mshr_occupancy[i] = 0;
    foreach(uuid_in_flight[i]) uuid_in_flight[i] = 0;
  endfunction

  function void write_cpu(lfc_cpu_transaction cpu_t);
    lfc_cpu_transaction out_tx;
    out_tx = lfc_cpu_transaction#(NUM_BANKS,UUID_SIZE)::type_id::create("out_tx");
    out_tx.copy(cpu_t);

    handle_cpu_request(cpu_t, out_tx);
    update_stall(out_tx);

    pred_cpu_ap.write(out_tx);
  endfunction

  function void handle_cpu_request(
        lfc_cpu_transaction cpu_t,
        ref lfc_cpu_transaction out_tx);

    int index  = get_index(cpu_t.mem_in_addr);
    int bank   = get_bank(cpu_t.mem_in_addr);

    if (valid[index]) begin
      process_hit(cpu_t, out_tx, index);
    end
    else begin
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
      // WRITE hit: update data
      data_model[index] = cpu_t.mem_in_store_value;
      valid[index] = 1;
    end
    else begin
      // READ hit: return cached data
      out_tx.hit_load = data_model[index];
    end

  endfunction

  function void process_miss(
        lfc_cpu_transaction cpu_t,
        ref lfc_cpu_transaction out_tx,
        int index,
        int bank);

    int new_uuid;
    lfc_ram_transaction exp_ram; // declare at top
    out_tx.hit = 0;

    // Allocate a UUID for this transaction
    new_uuid = allocate_uuid();
    if (new_uuid == -1) begin
      `uvm_error("PRED", "No UUID available!")
      return;
    end

    uuid_in_flight[new_uuid] = 1;
    uuid_addr_map[new_uuid]  = cpu_t.mem_in_addr;

    mshr_occupancy[bank]++;

    out_tx.mem_out_uuid = new_uuid;

    // WRITE-allocate policy: store value immediately
    if (cpu_t.mem_in_rw_mode) begin
      data_model[index] = cpu_t.mem_in_store_value;
      valid[index] = 1;
    end

    // Create predicted RAM transaction
    exp_ram = lfc_ram_transaction#(NUM_BANKS)::type_id::create("exp_ram");

    for (int b = 0; b < NUM_BANKS; b++) begin
      if (b == bank) begin
        if (cpu_t.mem_in_rw_mode) begin
          // CPU WRITE miss: write-allocate
          exp_ram.ram_mem_REN[b]  = 0;
          exp_ram.ram_mem_WEN[b]  = 1;
          exp_ram.ram_mem_data[b] = cpu_t.mem_in_store_value;
        end
        else begin
          // CPU READ miss: fetch from RAM
          exp_ram.ram_mem_REN[b]  = 1;
          exp_ram.ram_mem_WEN[b]  = 0;
          exp_ram.ram_mem_data[b] = 0;
        end
        exp_ram.ram_mem_addr[b] = cpu_t.mem_in_addr;
        exp_ram.ram_mem_complete[b] = 0;
      end
      else begin
        // other banks are idle
        exp_ram.ram_mem_REN[b]  = 0;
        exp_ram.ram_mem_WEN[b]  = 0;
        exp_ram.ram_mem_addr[b] = 0;
        exp_ram.ram_mem_data[b] = 0;
        exp_ram.ram_mem_complete[b] = 0;
      end
    end

    // Send predicted RAM transaction to scoreboard
    pred_ram_ap.write(exp_ram);

  endfunction

  function int allocate_uuid();
    for (int i=0;i<(1<<UUID_SIZE);i++)
      if (!uuid_in_flight[i])
        return i;
    return -1;
  endfunction

  function void update_stall(ref lfc_cpu_transaction out_tx);
    int bank = get_bank(out_tx.mem_in_addr);
    out_tx.stall = (mshr_occupancy[bank] >= MAX_MSHR);
  endfunction

  function void write_ram(lfc_ram_transaction ram_t);
    lfc_ram_transaction out_tx;
    out_tx = lfc_ram_transaction#(NUM_BANKS)::type_id::create("out_ram");
    out_tx.copy(ram_t);

    handle_fill_completion(ram_t);

    pred_ram_ap.write(out_tx);
  endfunction

  function void handle_fill_completion(lfc_ram_transaction ram_t);
    for (int b=0;b<NUM_BANKS;b++) begin
      if (ram_t.ram_mem_complete[b]) begin
        int addr  = ram_t.ram_mem_addr[b];
        int index = get_index(addr);

        data_model[index] = ram_t.ram_mem_data[b];
        valid[index]      = 1;

        // free matching UUID
        for (int u=0;u<(1<<UUID_SIZE);u++) begin
          if (uuid_in_flight[u] && uuid_addr_map[u] == addr) begin
            uuid_in_flight[u] = 0;
            break;
          end
        end

        mshr_occupancy[b]--;
      end
    end
  endfunction

  function int get_index(bit [31:0] addr);
    return addr[9:4]; // example, 256 lines
  endfunction

  function int get_bank(bit [31:0] addr);
    return get_index(addr) % NUM_BANKS;
  endfunction

endclass

`endif
