class lane_item extends uvm_sequence_item;
    
    import vecot_pkg::*;

    rand vreg_t v1;
    rand vreg_t v2;
    rand fu_t usel;
    rand logic [7:0] vd;
    rand logic rm;
    rand vmask_t mask;
    rand alu_op_t alu_op;

endclass