`ifndef lfc_multiple_miss_seq_SV
`define lfc_multiple_miss_seq_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_multiple_miss_seq extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_multiple_miss_seq)

  function new(string name = "lfc_multiple_miss_seq");
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

  task write_req(input logic [31:0] addr);
    lfc_cpu_transaction req;
    req = lfc_cpu_transaction #()::type_id::create("req");

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = addr;
      req.mem_in_rw_mode     = 1'b1;
      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
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

    `uvm_info(get_type_name(), "Starting basic lfc_multiple_miss_seq...", UVM_MEDIUM)

    req = lfc_cpu_transaction #()::type_id::create("req");

    `uvm_info(get_type_name(), "Sending multiple read transaction...", UVM_MEDIUM)

    
    saved_addr = gen_rand_addr();
    write_addr = gen_rand_addr_2();
    // read_req(saved_addr);

    for (int i = 0; i < 5; i++) begin
      // saved_addr = gen_rand_addr();
      read_req(saved_addr);
      write_req(write_addr);
    end

    // start_item(req);
    //   req.n_rst              = 1'b1; 
    //   req.mem_in_addr        = saved_addr;
    //   req.mem_in_rw_mode     = 1'b0;
    //   req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
    //   req.dp_in_halt         = 1'b0;
    //   // req.mem_in             = 1'b1;
    // finish_item(req);

    // `uvm_info(get_type_name(),
    //   $sformatf("READ request sent: addr=0x%0h", saved_addr),
    //   UVM_LOW)
    
    // saved_addr = gen_rand_addr();
    // start_item(req);
    //   req.n_rst              = 1'b1; 
    //   req.mem_in_addr        = saved_addr;
    //   req.mem_in_rw_mode     = 1'b0;
    //   req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
    //   req.dp_in_halt         = 1'b0;
    //   // req.mem_in             = 1'b1;
    // finish_item(req);

    // `uvm_info(get_type_name(),
    //   $sformatf("READ request sent: addr=0x%0h", saved_addr),
    //   UVM_LOW)

    // saved_addr = gen_rand_addr();
    // start_item(req);
    //   req.n_rst              = 1'b1; 
    //   req.mem_in_addr        = saved_addr;
    //   req.mem_in_rw_mode     = 1'b0;
    //   req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
    //   req.dp_in_halt         = 1'b0;
    //   // req.mem_in             = 1'b1;
    // finish_item(req);

    // `uvm_info(get_type_name(),
    //   $sformatf("READ request sent: addr=0x%0h", saved_addr),
    //   UVM_LOW)

    // saved_addr = gen_rand_addr();
    // start_item(req);
    //   req.n_rst              = 1'b1; 
    //   req.mem_in_addr        = saved_addr;
    //   req.mem_in_rw_mode     = 1'b0;
    //   req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
    //   req.dp_in_halt         = 1'b0;
    //   // req.mem_in             = 1'b1;
    // finish_item(req);

    // `uvm_info(get_type_name(),
    //   $sformatf("READ request sent: addr=0x%0h", saved_addr),
    //   UVM_LOW)


  endtask
endclass

`endif // lfc_multiple_miss_seq_SV
