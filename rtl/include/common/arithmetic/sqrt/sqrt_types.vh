`ifndef SQRT_PKG_VH
`define SQRT_PKG_VH

package sqrt_pkg;

    typedef struct packed {
        logic [15:0] operand;
        logic valid_in;
        logic ready_out;
    } sqrt_if_in_t;

    typedef struct packed {
        logic [15:0] result;
        logic valid_out;
        logic ready_in;
    } sqrt_if_out_t;


endpackage

`endif