`ifndef lfc_store_hit_seq_SV
`define lfc_store_hit_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_store_hit_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_store_hit_seq)

  function new(string name = "lfc_store_hit_seq");
    super.new(name);
  endfunction

  logic [31:0] rand_addr_temp;

  function logic [31:0] gen_rand_addr();
    // default for debugging
    rand_addr_temp = 32'h1000;

    if (!std::randomize(rand_addr_temp) with {
          rand_addr_temp inside {[32'h1000 : 32'h1FFF]};
          rand_addr_temp % 4 == 0;
        }) begin
      `uvm_error(get_type_name(), "Address randomization failed");
    end

    return rand_addr_temp;
  endfunction

  logic [31:0] rand_addr_temp_2;

  function logic [31:0] gen_rand_addr_2();
    // default for debugging
    rand_addr_temp_2 = 32'h1000;

    if (!std::randomize(rand_addr_temp_2) with {
          rand_addr_temp_2 inside {[32'h2000 : 32'h2FFF]};
          rand_addr_temp_2 % 4 == 0;
        }) begin
      `uvm_error(get_type_name(), "Address randomization failed");
    end

    return rand_addr_temp_2;
  endfunction


  logic [31:0] rand_data_temp;

  function logic [31:0] gen_rand_data();
    // default for debugging
    rand_data_temp = 32'h1000;

    if (!std::randomize(rand_data_temp) with {
          rand_data_temp inside {[32'h1000 : 32'h1FFF]};
          rand_data_temp % 4 == 0;
        }) begin
      `uvm_error(get_type_name(), "Address randomization failed");
    end

    return rand_data_temp;
  endfunction
  

  task read_req(input logic [31:0] addr);
    lfc_cpu_transaction req;
    req = lfc_cpu_transaction #()::type_id::create("req");

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = addr;
      req.mem_in_rw_mode     = 1'b0;
      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("READ request sent: addr=0x%0h", addr),
      UVM_LOW)
  endtask

  task write_req(input logic [31:0] addr, input logic [31:0] data);
    lfc_cpu_transaction req;
    req = lfc_cpu_transaction #()::type_id::create("req");

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = addr;
      req.mem_in_rw_mode     = 1'b1;
      req.mem_in_store_value = data;
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("READ request sent: addr=0x%0h", addr),
      UVM_LOW)
  endtask


  virtual task body();
    lfc_cpu_transaction req;
    
    logic [31:0] saved_addr;
    logic [31:0] write_addr;
    logic [31:0] saved_data;
    logic [31:0] write_data;

    `uvm_info(get_type_name(), "Starting basic lfc_store_hit_seq...", UVM_MEDIUM)

    req = lfc_cpu_transaction #()::type_id::create("req");

    `uvm_info(get_type_name(), "Sending multiple read transaction...", UVM_MEDIUM)

    write_data = gen_rand_data();
    saved_addr = gen_rand_addr();
    write_addr = gen_rand_addr_2();

    write_req(write_addr, write_data);
    
    write_data = gen_rand_data();
    saved_addr = gen_rand_addr();
    write_addr = gen_rand_addr_2();

    write_req(write_addr, write_data);
    // read_req(saved_addr);

    // for (int i = 0; i < 5; i++) begin
    //   // saved_addr = gen_rand_addr();
    //   read_req(saved_addr);
    //   write_req(write_addr);
    // end


  endtask
endclass

`endif // lfc_store_hit_seq_SV
