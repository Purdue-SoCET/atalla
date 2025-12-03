// `ifndef LFC_BASIC_SEQUENCE_SV
// `define LFC_BASIC_SEQUENCE_SV

// import uvm_pkg::*;
// `include "uvm_macros.svh"
// `include "lfc_cpu_transaction.sv"


// class lfc_basic_sequence extends uvm_sequence#(lfc_cpu_transaction);
//   `uvm_object_utils(lfc_basic_sequence)

//   function new(string name = "lfc_basic_sequence");
//     super.new(name);
//   endfunction

//   virtual task body();
//     lfc_cpu_transaction req;
//     `uvm_info(get_type_name(), "Starting lfc_basic_sequence...", UVM_MEDIUM)

//     req = lfc_cpu_transaction::type_id::create("req");

//     req.n_rst             = 1'b1; //added
//     req.mem_in_addr       = 32'h1000;
//     req.mem_in_rw_mode    = 1'b1;        // 1 = write, 0 = read
//     req.mem_in_store_value= 32'hDEADBEEF;
//     req.dp_in_halt        = 1'b0;
//     // req.mem_in = 1'b1;    // will stuck all

//     start_item(req);
//     finish_item(req);

//     `uvm_info(get_type_name(),
//       $sformatf("Completed: addr=0x%0h data=0x%0h", req.mem_in_addr, req.mem_in_store_value),
//       UVM_LOW)
//   endtask
// endclass



// `endif // LFC_BASIC_SEQUENCE_SV



`ifndef LFC_BASIC_SEQUENCE_SV
`define LFC_BASIC_SEQUENCE_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"

class lfc_basic_sequence extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_basic_sequence)

  function new(string name = "lfc_basic_sequence");
    super.new(name);
  endfunction

  virtual task body();
    lfc_cpu_transaction req;
    
    logic [31:0] saved_addr;
    logic [31:0] saved_data;

    `uvm_info(get_type_name(), "Starting basic Read-After-Write sequence...", UVM_MEDIUM)

    req = lfc_cpu_transaction::type_id::create("req");

    `uvm_info(get_type_name(), "Sending WRITE transaction...", UVM_MEDIUM)

    saved_addr = 32'h1000;
    saved_data = 32'hDEADBEEF;

    start_item(req);
      req.n_rst              = 1'b1;
      req.mem_in_addr        = saved_addr;
      req.mem_in_rw_mode     = 1'b1; // 1 = write
      req.mem_in_store_value = saved_data;
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("WRITE complete: addr=0x%0h data=0x%0h", saved_addr, saved_data),
      UVM_LOW)
    
    `uvm_info(get_type_name(), "Sending READ transaction...", UVM_MEDIUM)
    

    start_item(req);
      req.n_rst              = 1'b1; 
      req.mem_in_addr        = saved_addr;
      req.mem_in_rw_mode     = 1'b0;
      req.mem_in_store_value = 32'hCAFEBABE; // no matter for read
      req.dp_in_halt         = 1'b0;
      // req.mem_in             = 1'b1;
    finish_item(req);

    `uvm_info(get_type_name(),
      $sformatf("READ request sent: addr=0x%0h", saved_addr),
      UVM_LOW)

  endtask
endclass

`endif // LFC_BASIC_SEQUENCE_SV