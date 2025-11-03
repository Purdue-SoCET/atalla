import uvm_pkg::*;
`include "uvm_macros.svh"
`include "systolic_array_if.vh"

class driver extends uvm_driver#(transaction);
  `uvm_component_utils(driver)

  virtual systolic_array_if vif;

  function new(string name, uvm_component parent);
    super.new(name, parent);
  endfunction: new

  function void build_phase(uvm_phase phase);
    super.build_phase(phase);
    // get interface
    if(!uvm_config_db#(virtual systolic_array_if)::get(this, "", "systolic_vif", vif)) begin
      `uvm_fatal("Driver", "No virtual interface specified for this test instance");
    end
  endfunction: build_phase

  task run_phase(uvm_phase phase);
    transaction req_item;

    forever begin
      `uvm_info ("Driver", $sformatf ("In Driver"), UVM_NONE)
      seq_item_port.get_next_item(req_item);

      ////input matrix
      `uvm_info ("Driver", $sformatf ("Got item"), UVM_NONE)

      `uvm_info ("Driver", $sformatf ("Wait for reset over"), UVM_NONE)
      
      vif.weight_en        <= 0;
      vif.input_en         <= 0;
      vif.partial_en       <= 0;
      vif.row_in_en        <= '0;
      vif.row_ps_en        <= '0;
      vif.array_in         <= '0;
      vif.array_in_partials<= '0;
      repeat(4)@(posedge vif.clk); // for reset logic

      foreach (req_item.plan[i]) begin
        transaction_elem e = req_item.plan[i];
        repeat (e.pre_idle_cycles)
        @(posedge vif.clk);
        @(posedge vif.clk);

        if(req_item.phase_kind == PH_INPUT) begin
            vif.weight_en <= e.en;
            vif.row_in_en <= e.addr;
            vif.array_in  <= e.data; 
            vif.input_en  <= 0;
            vif.partial_en<= 0;
        end else if (req_item.phase_kind == PH_IANDSUM) begin
            vif.weight_en <= 0;
            vif.row_in_en <= e.addr;
            vif.row_ps_en <= e.addr;
            vif.array_in  <= e.data; 
            vif.array_in_partials  <= e.data; 
            vif.input_en  <= 1;
            vif.partial_en<= 1;
        end

      @(posedge vif.clk);
      vif.weight_en        <= 0;
      vif.input_en         <= 0;
      vif.partial_en       <= 0;

      end

      repeat(30)@(posedge vif.clk);
      seq_item_port.item_done();
end
  endtask: run_phase

endclass: driver
 