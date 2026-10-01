class lane_sequencer extends uvm_sequencer #(lane_item);
    `uvm_component_utils(lane_sequencer) //component

    function new(string name = "lane_sequencer", 
                uvm_component parent = null);//cuz sequencer is a component, it has parent
        super.new(name, parent);
    endfunction
endclass