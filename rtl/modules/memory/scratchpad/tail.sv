/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"


module tail #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if.spad_tail tif);

    import scpad_pkg::*;

    // Combinational routing - no latch needed
    // Route response to FE or BE based on src field
    always_comb begin
        tif.fe_res[IDX] = '0;
        tif.be_res[IDX] = '0;

        if (tif.stomach_tail_res[IDX].valid && !tif.stomach_tail_res[IDX].write) begin
            // Read response - route to correct destination with data
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
        else if (tif.stomach_tail_res[IDX].valid && tif.stomach_tail_res[IDX].write) begin
            // Write response - just signal completion
            case (tif.stomach_tail_res[IDX].src)
                SRC_FE: tif.fe_res[IDX].valid = 1'b1;
                SRC_BE: tif.be_res[IDX].valid = 1'b1;
            endcase
        end
    end

endmodule

`ifndef SYNTHESIS



`endif