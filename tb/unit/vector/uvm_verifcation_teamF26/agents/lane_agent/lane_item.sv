//transaction
class lane_item extends uvm_sequence_item;
    
    import vecot_pkg::*;

    // I didn't put input_valid signal here cuz we gonna use it in driver
    rand vreg_t v1;
    rand vreg_t v2;
    rand fu_t usel;
    rand logic [7:0] vd;
    rand logic rm;
    rand vmask_t mask;
    rand alu_op_t alu_op;

    `uvm_object_utils(lane_item)//register with uvm factory

    function new(string name = "lane_item");  //constructor
        super.new(name);
    endfunction

endclass