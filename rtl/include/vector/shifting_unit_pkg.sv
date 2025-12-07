`ifndef SHIFTING_UNIT_PKG_VH
`define SHIFTING_UNIT_PKG_VH

`include "vector_pkg.sv"

package shifting_unit_pkg;
    import vector_pkg::*;

    typedef enum logic {
        RIGHT = 1'b0,
        LEFT = 1'b1
    } shift_direction_t;

    typedef struct packed {
        vreg_t                              veg_vdata;      // [vreg bits] vector data
        shift_direction_t                   direction;      // shift direction: 0-left, 1-right
        logic [$clog2(NUM_ELEMENTS)-1:0]    shift_amount;   // amount of elements to shift
        logic                               input_valid;    // vdata & shift is valid
        logic                               output_ready;   // writeback arbiter is ready
    } shifting_unit_inputs_t;

    typedef struct packed {
        vreg_t                              shifted_vdata;  // [vreg bits] shifted vector data
        logic                               input_ready;    // shifting_unit is issuable
        logic                               output_valid;   // shifted vector is valid
    } shifting_unit_outputs_t;

endpackage
`endif