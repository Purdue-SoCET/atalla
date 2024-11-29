/* FU Matrix LS Code */

//`include "datapath_types.vh"
`include "fu_matrix_ls_if.vh"

module fu_matrix_ls
(
    fu_matrix_ls_if.mls mlsif // MATRIX LOAD STORE IF
);

// importing types
//import datapath_pkg::*;

assign mlsif.done = mlsif.mhit; // Mhit

always_comb begin : LOAD_STORE
    if (mlsif.enable) begin     // LOAD STORE ENABLE
        if (mlsif.ls_in[0]) begin   // LOAD
            mlsif.ls_out[0] = 1;
            mlsif.rd_out = mlsif.rd_in;
            mlsif.stride_out = mlsif.stride_in;
            mlsif.address = mlsif.rs_in + mlsif.imm_in;
        end

        else if (mlsif.ls_in[1]) begin  // STORE
            mlsif.ls_out[1] = 1;
            mlsif.rd_out = mlsif.rd_in;
            mlsif.stride_out = mlsif.stride_in;
            mlsif.imm_in = mlsif.stride_in;
            mlsif.address = mlsif.rs_in + mlsif.imm_in;
        end
    end
end

endmodule