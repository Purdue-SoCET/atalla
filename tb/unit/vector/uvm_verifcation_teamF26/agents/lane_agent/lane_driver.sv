//get transaction from sequencer to drive dut
class lane_driver extends uvm_driver #(lane_item);
    `uvm_componet_utils(lane_driver)

    function new(string name = "lane_driver", 
                uvm_component parent = null);
        super.new(name, parent);
    endfunction

    task run_phase(uvm_phase phase);
        lane_item req;

        forever begin
            //get the next trasaction from the sequencer
            seq_item_port.get_next_item(req);
            
            //drive here

            //tell sequencer that this transaction is finished
            seq_item_port.item_done();
        end
    endtask
endclass