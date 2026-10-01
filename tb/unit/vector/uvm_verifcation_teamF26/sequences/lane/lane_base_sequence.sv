class lane_base_sequence extends uvm_sequence #(lane_item);
    `uvm_object_utils(lane_base_sequence)//cuz it's an object

    function new(string name = "lane_base_sequence");
        super.new(name);
    endfunction
endclass