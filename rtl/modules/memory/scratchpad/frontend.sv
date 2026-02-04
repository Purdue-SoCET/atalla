/*  Nicha Muninnimit - nmuninni@purdue.edu */
/*  Rafael Monteiro Martins Pinheiro - rmontei@purdue.edu */
/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"

module frontend #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (
    scpad_if.frontend_vec fvif, 
    scpad_if.frontend_body fsif
); 

    import scpad_pkg::*;

    // Internal request signal to hold vec_req (latched or direct)
    req_t internal_req;

    // Internal interface for swizzle (same pattern as backend)
    scpad_if fe_internal(fvif.clk, fvif.n_rst);

    // Propagate downstream stalls    
    assign fvif.fe_vec_stall[IDX] = fsif.fe_stall[IDX];

    generate 
        if (LATCH_INT) begin 
            latch #(.T(req_t)) u_latch_vec_req (
                .clk(fvif.clk),
                .n_rst(fvif.n_rst),
                .en(!fsif.fe_stall[IDX]),
                .in(fvif.vec_req[IDX]),
                .out(internal_req)
            );
            latch #(.T(res_t)) u_latch_vec_res (
                .clk(fsif.clk),
                .n_rst(fsif.n_rst),
                .en(1'b1),
                .in(fsif.fe_res[IDX]),
                .out(fvif.vec_res[IDX])
            );
        end else begin 
            assign internal_req = fvif.vec_req[IDX];
            assign fvif.vec_res[IDX] = fsif.fe_res[IDX]; 
        end 
    endgenerate

    // Swizzle - instantiated with internal interface (same pattern as backend)
    swizzle u_swizzle (.swizz(fe_internal));
    
    // Drive swizzle request signals
    assign fe_internal.swizz_req.row_or_col = internal_req.row_or_col;
    assign fe_internal.swizz_req.spad_addr  = internal_req.spad_addr;
    assign fe_internal.swizz_req.num_rows   = internal_req.num_rows;
    assign fe_internal.swizz_req.num_cols   = internal_req.num_cols;
    assign fe_internal.swizz_req.row_id     = internal_req.row_id;
    assign fe_internal.swizz_req.col_id     = internal_req.col_id;

    // Combine internal_req with swizzle outputs to form fe_req
    always_comb begin
        fsif.fe_req[IDX] = internal_req;
        fsif.fe_req[IDX].xbar = fe_internal.swizz_res.xbar_desc;
    end

endmodule

`ifndef SYNTHESIS



`endif 