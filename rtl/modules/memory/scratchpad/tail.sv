/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"


module tail #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if.spad_tail tif);

    import scpad_pkg::*;

    // Combinational routing - no latch needed
    // Route read response to FE or BE based on src field
    // Note: write completions never reach rxbar/tail — body only asserts
    // spad_xbar_req.valid on reads (|bank_rdone). Write completions go
    // through spad_cntrl_res directly to head, bypassing this path.
    always_comb begin
        tif.fe_res[IDX] = '0;
        tif.be_res[IDX] = '0;

        if (tif.stomach_tail_res[IDX].valid) begin
            case (tif.stomach_tail_res[IDX].src)
                SRC_FE: begin
                    tif.fe_res[IDX].valid = 1'b1;
                    tif.fe_res[IDX].rdata = tif.stomach_tail_res[IDX].rdata;
                end
                SRC_BE: begin
                    tif.be_res[IDX].valid = 1'b1;
                    tif.be_res[IDX].rdata = tif.stomach_tail_res[IDX].rdata;
                end
            endcase
        end
    end

endmodule

`ifndef SYNTHESIS



`endif