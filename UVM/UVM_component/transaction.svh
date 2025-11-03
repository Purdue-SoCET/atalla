`ifndef TRANSACTION_SVH
`define TRANSACTION_SVH
//`include "sys_arr_pkg.vh"
import sys_arr_pkg::*;

class transaction_elem extends uvm_object;
  bit                 en;
  int unsigned        addr;
  rand bit [DW*N:0]     data;
  int unsigned        pre_idle_cycles;
  bit                 en_temp; //For the partial sum in PH_IANDSUM phase //目前先不管partial sum了
  int unsigned        addr_temp;
  rand bit [DW*N:0]     data_temp;
  int unsigned        pre_idle_cycles_temp;

  `uvm_object_utils_begin(transaction_elem)
    `uvm_field_int(en,              UVM_ALL_ON)
    `uvm_field_int(addr,            UVM_ALL_ON)
    `uvm_field_int(pre_idle_cycles, UVM_ALL_ON)
    `uvm_field_int(data,            UVM_ALL_ON)
  `uvm_object_utils_end

  function new(string name="transaction_elem"); super.new(name); endfunction

endclass

class transaction extends uvm_sequence_item;
  //typedef enum {PH_IDLE, PH_INPUT, PH_PSUM, PH_IANDSUM, PH_OUTPUT} phase_e;
  rand sys_arr_pkg::phase_e phase_kind;
  rand bit              out_of_order_flag;
  rand bit              pause_flag;
  rand int unsigned     pause_number;
  rand int unsigned     n_empty;
  transaction_elem      plan[$];

  constraint c_knob {
    pause_number  inside {[1:16]}; //TODO 参数化
    n_empty       inside {[0:16]};
  }

  `uvm_object_utils_begin(transaction)
    `uvm_field_enum(phase_e, phase_kind, UVM_ALL_ON)
    `uvm_field_int(out_of_order_flag,       UVM_ALL_ON)
    `uvm_field_int(pause_flag,              UVM_ALL_ON)
    `uvm_field_int(pause_number,         UVM_ALL_ON)
    `uvm_field_int(n_empty,            UVM_ALL_ON)
  `uvm_object_utils_end

  function new(string name="sa_frame_txn"); super.new(name); endfunction

  function void build_plan();
    plan.delete();
    for (int a=0; a<=sys_arr_pkg::SIZE; a++) begin
      transaction_elem e = transaction_elem::type_id::create($sformatf("elem_addr%0d", a));
      e.en = 1;
      e.addr = a;
      e.pre_idle_cycles = 0;
      assert(e.randomize()with {
        data == 1;});
      plan.push_back(e);
    end

    for (int k=0; k<int'(n_empty); k++) begin
      transaction_elem z = transaction_elem::type_id::create($sformatf("elem_hole%0d", k));
      z.en = 0;
      z.addr = 0;
      z.pre_idle_cycles = 0;
      void'(z.randomize());
      plan.push_back(z);
    end

    if (out_of_order_flag) begin
      foreach (plan[i]) begin
        int j = $urandom_range(0, plan.size()-1);
        transaction_elem t = plan[i]; plan[i] = plan[j]; plan[j] = t;
      end
    end

    if (pause_flag && plan.size()>0) begin
      int pos = $urandom_range(0, plan.size()-1);
      plan[pos].pre_idle_cycles = pause_number;
    end
  endfunction

  function void post_randomize();
    build_plan();
  endfunction
  
endclass
`endif
