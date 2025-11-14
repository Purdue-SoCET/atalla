`ifndef LFC_WR_SEQUENCE_SV
`define LFC_WR_SEQUENCE_SV

import uvm_pkg::*;
`include "uvm_macros.svh"
`include "lfc_cpu_transaction.sv"


class lfc_wr_sequence extends uvm_sequence#(lfc_cpu_transaction);
  `uvm_object_utils(lfc_wr_sequence)
  parameter NUM_TRANSACTIONS = 10;

  function new(string name = "lfc_wr_sequence");
    super.new(name);
  endfunction

  virtual task body();
    lfc_cpu_transaction req;
    logic [31:0] addrs [NUM_TRANSACTIONS];   
    int addrs_idx;

    `uvm_info(get_type_name(), "Starting lfc_wr_sequence...", UVM_MEDIUM)

    req = lfc_cpu_transaction::type_id::create("req");

    `uvm_info(get_type_name(), "Starting write transactions...", UVM_MEDIUM)
    addrs_idx = 0;
    repeat(NUM_TRANSACTIONS) begin // write transactions
        start_item(req);
        if(!req.randomize() with {mem_in_addr % 4 == 0;}) begin // constrains mem_in_addr to the first byte of a 32 bit chunk of data
            `uvm_fatal("lfc_wr_sequence", "Not able to randomize")
        end
        req.n_rst = 1'b1;
        req.mem_in_rw_mode = 1'b1; // 1 for write, 0 for read
        req.mem_in = 1'b0; // understanding is that this is 1 for a read??
        req.dp_in_halt = 1'b0;
        addrs[addrs_idx] = req.mem_in_addr;
        finish_item(req);

        `uvm_info(get_type_name(),
        $sformatf("Write %0d Completed: addr=0x%0h data=0x%0h", addrs_idx + 1, req.mem_in_addr, req.mem_in_store_value),
        UVM_LOW)

        addrs_idx++;
    end

    `uvm_info(get_type_name(), "Starting read transactions...", UVM_MEDIUM)
    addrs_idx = 0;
    repeat(NUM_TRANSACTIONS) begin // read transactions
        start_item(req);
        if(!req.randomize()) begin 
            `uvm_fatal("lfc_wr_sequence", "Not able to randomize")
        end
        req.n_rst = 1'b1;
        req.mem_in_rw_mode = 1'b0; // 1 for write, 0 for read
        req.mem_in = 1'b1; // understanding is that this is 1 for a read??
        req.dp_in_halt = 1'b0;
        req.mem_in_addr = addrs[addrs_idx];
        finish_item(req);

        `uvm_info(get_type_name(),
        $sformatf("Read %0d Completed: addr=0x%0h data=0x%0h", addrs_idx + 1, req.mem_in_addr, req.mem_in_store_value),
        UVM_LOW)

        addrs_idx++;
    end

  endtask
endclass



`endif // LFC_WR_SEQUENCE_SV