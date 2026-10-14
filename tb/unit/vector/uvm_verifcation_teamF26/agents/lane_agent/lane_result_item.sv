
class lane_result_item extends uvm_sequence_item;

    `uvm_object_utils(lane_result_item)

    // Completed vector result
    vector_pkg::vreg_t result;

    // Destination register identifier
    logic [7:0] vd;

    function new(string name = "lane_result_item");
        super.new(name);
    endfunction

endclass
