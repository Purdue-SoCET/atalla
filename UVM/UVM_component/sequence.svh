`ifndef SEQ_SVH
`define SEQ_SVH
import uvm_pkg::*;
`include "uvm_macros.svh"
`include "transaction.svh"

class sa_gemm_seq extends uvm_sequence #(transaction);
  `uvm_object_utils(sa_gemm_seq)

  function
    new(string name="sa_gemm_seq");
    super.new(name);
  endfunction

  task body();
    transaction t = transaction::type_id::create("t");

    start_item(t);
    assert(t.randomize() with{
      phase_kind == PH_INPUT;
      out_of_order_flag == 0;
      pause_flag == 0;
      n_empty == 0;
    });
    finish_item(t);
      `uvm_info ("Driver", $sformatf ("finish_11"), UVM_NONE)

    start_item(t);
    assert(t.randomize() with{
      phase_kind == PH_IANDSUM;
      out_of_order_flag == 0;
      pause_flag == 0;
      n_empty == 0;
    });
    finish_item(t);
      `uvm_info ("Driver", $sformatf ("finish_12"), UVM_NONE)
/*
    start_item(t);
    assert(t.randomize() with{
      phase_kind == PH_INPUT;
      out_of_order_flag == 0;
      pause_flag == 0;
      n_empty == 0;
    });
    finish_item(t);
      `uvm_info ("Driver", $sformatf ("finish_21"), UVM_NONE)

    start_item(t);
    assert(t.randomize() with{
      phase_kind == PH_IANDSUM;
      out_of_order_flag == 0;
      pause_flag == 0;
      n_empty == 0;
    });
    finish_item(t);
      `uvm_info ("Driver", $sformatf ("finish_22"), UVM_NONE)*/


  endtask
endclass

`endif
