/*  Akshath Raghav Ravikiran - araviki@purdue.edu */

`include "scpad_pkg.sv"
`include "scpad_if.sv"


module head #(parameter logic [scpad_pkg::SCPAD_ID_WIDTH-1:0] IDX = '0) (scpad_if.spad_head hif);

    import scpad_pkg::*;

    // Stalls
    logic downstream_stall;
    logic pipe_busy; 

    // Tracking grants
    // Need to hold fe_stall high on the N+1th cycle to ensure we don't overwrite the request. 
    logic be_v, fe_v;
    logic grant_be, grant_fe;

    // Intermediate - use sel_req_t since that's what head_stomach_req expects
    sel_req_t sel_req_d;

    always_ff @(posedge hif.clk, negedge hif.n_rst) begin
        if (!hif.n_rst) pipe_busy <= 1'b0;
        else pipe_busy <= (grant_be || grant_fe);
    end

    always_comb begin
        sel_req_d = '0;

        // Access .valid field from req_t struct
        be_v = hif.be_req[IDX].valid;
        fe_v = hif.fe_req[IDX].valid;

        // w_stall is an array, need [IDX]
        grant_be = (!hif.w_stall[IDX]) && be_v;
        grant_fe = (!hif.w_stall[IDX]) && (!be_v) && fe_v;

        // Convert req_t to sel_req_t
        if (grant_be) begin
            sel_req_d.valid = hif.be_req[IDX].valid;
            sel_req_d.write = hif.be_req[IDX].write;
            sel_req_d.src   = SRC_BE;
            sel_req_d.xbar  = hif.be_req[IDX].xbar;
            sel_req_d.wdata = hif.be_req[IDX].wdata;
        end
        else if (grant_fe) begin
            sel_req_d.valid = hif.fe_req[IDX].valid;
            sel_req_d.write = hif.fe_req[IDX].write;
            sel_req_d.src   = SRC_FE;
            sel_req_d.xbar  = hif.fe_req[IDX].xbar;
            sel_req_d.wdata = hif.fe_req[IDX].wdata;
        end
    end
 
    // head_stomach_req will either go into the scpad_cntrl FIFO or xbar. 
    assign hif.head_stomach_req[IDX] = sel_req_d;

    // w_stall and r_stall are arrays, need [IDX]
    // NOTE: be_stall should only go high on actual backpressure from downstream FIFOs.
    // We removed the (be_v && pipe_busy) term because:
    // 1. It created a combinational loop (be_v depends on be_req.valid, which depends on be_stall)
    // 2. With FIFOs in the pipeline, we can accept requests every cycle until FIFOs are full
    assign downstream_stall = hif.w_stall[IDX] || hif.r_stall[IDX];
    assign hif.fe_stall[IDX] = downstream_stall || pipe_busy || be_v;
    assign hif.be_stall[IDX] = downstream_stall;

endmodule

`ifndef SYNTHESIS



`endif