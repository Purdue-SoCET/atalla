`include "types_pkg.vh"
`include "fu_matrix_ls_if.vh"

module fu_matrix_ls (input CLK, 
                     input nRST);

    if(mhit) begin 
        address = something;
        stride = something;
    end
    else begin
        address = 0;
        stride = 0;
    end

endmodule