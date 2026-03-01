`ifndef EXP_IF_VH
`define EXP_IF_VH
`include "vector_types.vh"

interface exp_if;
    import vector_pkg::*;

    bf16_t input_val, output_val;
    logic valid_data_in, valid_data_out, ready;

    modport exif (
        input input_val, valid_data_in,
        output output_val, valid_data_out, ready
    );


endinterface

`endif
