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

<<<<<<< HEAD
    // Intermediate
    req_t req_d;
=======
    // Intermediate - use sel_req_t since that's what head_stomach_req expects
    sel_req_t sel_req_d;
>>>>>>> origin/Vector_S26_L1_TB

    always_ff @(posedge hif.clk, negedge hif.n_rst) begin
        if (!hif.n_rst) pipe_busy <= 1'b0;
        else pipe_busy <= (grant_be || grant_fe);
    end

    always_comb begin
<<<<<<< HEAD
        req_d = '0;

        be_v = hif.be_req_valid[IDX];
        fe_v = hif.fe_req_valid[IDX];

        grant_be = (!hif.w_stall) && be_v;
        grant_fe = (!hif.w_stall) && (!be_v) && fe_v;

        if (grant_be) req_d = hif.be_req[IDX];
        else if (grant_fe) req_d = hif.fe_req[IDX];
    end
 
    // head_stomach_req will either go into the scpad_cntrl FIFO or xbar. 
    // No need to latch here -> LATCH_INT
    assign hif.head_stomach_req = fvif.vec_req[IDX];

    assign downstream_stall = hif.w_stall || hif.r_stall;
    assign hif.fe_stall[IDX] = downstream_stall || (fe_v && (pipe_busy || be_v));
    assign hif.be_stall[IDX] = downstream_stall || (be_v && pipe_busy);

endmodule

`ifndef SYNTHESIS



`endif 
=======
        sel_req_d = '0;

        // Access .valid field from req_t struct
        be_v = hif.be_req[IDX].valid;
        fe_v = hif.fe_req[IDX].valid;

        grant_be = (!hif.w_stall[IDX]) && be_v;
        grant_fe = (!hif.w_stall[IDX]) && (!pipe_busy) && (!be_v) && fe_v;

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
    assign downstream_stall = hif.w_stall[IDX] || hif.r_stall[IDX];
    assign hif.fe_stall[IDX] = downstream_stall || pipe_busy || be_v;
    assign hif.be_stall[IDX] = downstream_stall;

endmodule
>>>>>>> origin/Vector_S26_L1_TB
