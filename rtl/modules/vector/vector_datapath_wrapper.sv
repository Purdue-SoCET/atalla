`include "vector_pkg.vh"
`include "vector_if.vh"
`include "vreduction_if.vh"
`include "reduction_types.vh"
`include "gsau_control_unit_if.vh"
    

module vector_datapath_wrapper (
    input  logic                    CLK,
    input  logic                    nRST,

    //vectpr IF interface
    input logic [1:0] rm, lane_valid_in, lane_ready_in,
    input vreg_t [1:0] v1, v2,
    input vsel_t [1:0] lane_vd_in,
    input  vmask_t [1:0] vmask,
    input valu_op_t [1:0] opcode,
    fu_t [1:0] fu_sel,

    output vreg_t [4:0] result,
    output logic [4:0] valid_o,
    output logic [4:0] ready_o,
    output vsel_t [4:0] lane_vd,

    output vreg_t reduction_result,
    output logic reduction_valid,
    output vsel_t reduction_vd,
    //gsau
    input vreg_t veg_vdata1, veg_vdata2,
    input logic veg_valid,

    input vsel_t sb_vdst,
    input logic sb_valid,
    input logic sb_weight,

    input logic wb_output_ready,
    
    input vreg_t sa_array_output,
    input logic sa_out_valid,
    input logic sa_fifo_has_space,

    output logic veg_ready, sb_ready,
    output vreg_t wb_psum,
    output vsel_t wb_wbdst,
    output logic wb_valid,

    output vreg_t sa_array_in, sa_array_in_partials,
    output logic sa_input_en, sa_weight_en, sa_partial_en, sa_output_ready

    //lanes

);

    import reduction_pkg::*;
    import vector_pkg::*;

    vector_if vif();

    //vector_in_t
    assign vif.vector_in.rm = rm;
    assign vif.vector_in.valid_in = lane_valid_in;
    assign vif.vector_in.ready_in = lane_ready_in;
    assign vif.vector_in.v1 = v1;
    assign vif.vector_in.v2 = v2;
    assign vif.vector_in.vd = lane_vd_in;
    assign vif.vector_in.vmask = vmask;
    assign vif.vector_in.vop = opcode;
    assign vif.vector_in.fu_sel = fu_sel;

    //vector out_t
    assign result = vif.vector_out.result;
    assign valid_o = vif.vector_out.valid_o;
    assign ready_o = vif.vector_out.ready_o;
    assign lane_vd = vif.vector_out.vd;

    //reduction
    assign reduction_result = vif.vector_out.reduction_result;
    assign reduction_valid = vif.vector_out.reduction_valid;
    assign reduction_vd = vif.vector_out.reduction_vd;

    //gsau
    assign vif.vector_in.gsau.veg_vdata1 = veg_vdata1;
    assign vif.vector_in.gsau.veg_vdata2 = veg_vdata2;
    assign vif.vector_in.gsau.veg_valid = veg_valid;
    assign vif.vector_in.gsau.sb_vdst = sb_vdst;
    assign vif.vector_in.gsau.sb_valid = sb_valid;
    assign vif.vector_in.gsau.sb_weight = sb_weight;
    assign vif.vector_in.gsau.wb_output_ready = wb_output_ready;
    assign vif.vector_in.gsau.sa_array_output = sa_array_output;
    assign vif.vector_in.gsau.sa_out_valid = sa_out_valid;
    assign vif.vector_in.gsau.sa_fifo_has_space = sa_fifo_has_space;

    assign veg_ready = vif.vector_out.gsau.veg_ready;
    assign sb_ready = vif.vector_out.gsau.sb_ready;
    assign wb_psum = vif.vector_out.gsau.wb_psum;
    assign wb_wbdst = vif.vector_out.gsau.wb_wbdst;
    assign wb_valid = vif.vector_out.gsau.wb_valid;
    assign sa_array_in = vif.vector_out.gsau.sa_array_in;
    assign sa_array_in_partials = vif.vector_out.gsau.sa_array_in_partials;
    assign sa_input_en = vif.vector_out.gsau.sa_input_en;
    assign sa_weight_en = vif.vector_out.gsau.sa_weight_en;
    assign sa_partial_en = vif.vector_out.gsau.sa_partial_en;
    assign sa_output_ready = vif.vector_out.gsau.sa_output_ready;


    vector_datapath u_vector_datapath (
        .CLK (CLK),
        .nRST(nRST),
        .vif (vif)
    );

endmodule
