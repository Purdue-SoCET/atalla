`include "gsau_control_unit_if.vh"

typedef struct packed {
    // Issue Stage (SB -> GSAU)
    logic issue_work;
    logic issue_stall;
    logic issue_starve;

    // Dispatch Stage (GSAU -> SA Input)
    logic dispatch_work;
    logic dispatch_stall;
    logic dispatch_starve; // FIFO empty

    // WB Stage (SA Output -> GSAU -> WB)
    logic wb_work;
    logic wb_stall; // Backpressure from WB preventing drain
    logic wb_starve; // No valid output from SA
} gsau_perf_t;

module gsau_wrapper (
    input logic CLK,
    input logic nRST,

    // SB inputs
    input logic sb_valid_in,
    input logic sb_weight,
    
    // WB inputs
    input logic wb_ready_in,
    
    // SA inputs
    input logic sa_ready_in,
    input logic sa_valid_in,

    // Outputs for monitoring
    output gsau_perf_t perf
);
    gsau_control_unit_if gif();

    gsau_control_unit #(
        .VEGGIEREGS(256),
        .FIFOSIZE(1536) // 1536 bits / 8 bits = 192 entries
    ) u_gsau (
        .CLK(CLK),
        .nRST(nRST),
        .gsau_port(gif.gsau)
    );

    assign gif.sb_valid_in = sb_valid_in;
    assign gif.sb_weight   = sb_weight;
    assign gif.sb_vdst     = 8'h00;
    assign gif.veg_vdata1  = '0;
    assign gif.veg_vdata2  = '0;

    assign gif.wb_ready_in = wb_ready_in;

    assign gif.sa_ready_in = sa_ready_in;
    assign gif.sa_valid_in = sa_valid_in;
    assign gif.sa_array_output = '0;

    assign perf.issue_work   = gif.sb_valid_in && gif.sb_ready_out;
    assign perf.issue_stall  = gif.sb_valid_in && !gif.sb_ready_out;
    assign perf.issue_starve = !gif.sb_valid_in;

    assign perf.dispatch_work   = (gif.sa_input_en || gif.sa_weight_en);
    
    assign perf.dispatch_work = (gif.sa_input_en || gif.sa_weight_en);
    assign perf.dispatch_stall = gif.sb_valid_in && !gif.sa_ready_in;
    assign perf.dispatch_starve = !gif.sb_valid_in;

    assign perf.wb_work     = gif.wb_valid_out;
    assign perf.wb_stall    = gif.sa_valid_in && !gif.wb_ready_in;
    assign perf.wb_starve   = !gif.sa_valid_in;

endmodule
