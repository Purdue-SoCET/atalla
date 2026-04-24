// ------------------------------------------------------------
// exp_FU.sv
// Lane FU for exp
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "functional_unit_if.vh"
`include "lane_sequencer_if.vh"

`include "exp_if.vh"

module exp_FU (
    input logic                     CLK,
    input logic                     nRST,
    functional_unit_if.fuif         fuif
);
    import vector_pkg::*;
    localparam int UNIT_LATENCY = 8; //latency of the arithmetic unit

    logic [7:0] vd;

    //Module and interface instanciation
    lane_sequencer_if lsif();
    lane_sequencer seq (
        .CLK(CLK),
        .nRST(nRST),
        .seq_if(lsif)
    );

    //unused, only used in ALU FU
    assign lsif.in.aluop = ALU_ADD;
    assign lsif.in.rm = '0;

    exp_if exif();
    exp exp(
        .CLK(CLK),
        .nRST(nRST),
        .exif(exif)
    );

    assign fuif.out.input_ready = lsif.out.ready_in;
    assign lsif.in.v2 = 'b0;

    //input port decoding
    //this is a for loop in case for some reason we ever want to be able to issue more than 2
    always_comb begin : input_checking
        lsif.in.valid_in = 'b0;
        lsif.in.v1 = 'b0;
        lsif.in.mask = 'b0;
        vd = 'b0;
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == EXP) & fuif.out.input_ready) begin //are any of the input ports issuing to this FU? and we are ready
                lsif.in.valid_in = 'b1;
                lsif.in.v1 = fuif.in.ports[i].v1;
                lsif.in.mask = fuif.in.ports[i].mask;
                vd = fuif.in.ports[i].vd;
            end
        end
    end

    //connections to the arithmetic unit. always goes through the unit
    assign exif.in.valid_in = lsif.out.valid_out; //only start the unit when there is data we want to operate on
    assign exif.in.operand = lsif.out.v1;
    assign exif.in.ready_out = fuif.in.wb_ready;
    assign lsif.in.ready_out = exif.out.ready_in;

    //mask
    sync_fifo #(
        .FIFODEPTH(4),
        .DATAWIDTH(1)
    ) mask_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(lsif.out.valid_out & exif.out.ready_in),
        .shift(exif.out.valid_out & fuif.in.wb_ready),
        .din(lsif.out.mask),
        .dout(fuif.out.mask)
    );

    // VD metadata
    logic [$clog2(SLICE_W)-1:0] output_count_r, output_count_n;

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            output_count_r <= '0;
        end else begin
            output_count_r <= output_count_n;
        end
    end

    always_comb begin
        output_count_n = output_count_r;
        if (exif.out.valid_out & fuif.in.wb_ready) begin
            if (output_count_r == SLICE_W - 1) begin
                output_count_n = '0;  // Wrap back to 0
            end else begin
                output_count_n = output_count_r + 1;
            end
        end
    end

    logic is_last_element;
    assign is_last_element = (output_count_r == (SLICE_W - 1));

    sync_fifo #(
        .FIFODEPTH(4),
        .DATAWIDTH(8)
    ) vd_fifo (
        .CLK(CLK),
        .nRST(nRST),
        .wr_en(lsif.in.valid_in & lsif.out.ready_in),
        .shift(exif.out.valid_out & fuif.in.wb_ready & is_last_element),
        .din(vd),
        .dout(fuif.out.vd)
    );

    //output
    assign fuif.out.result = exif.out.result;
    assign fuif.out.rm = 0;
    assign fuif.out.mop_out = 0;
    assign fuif.out.wb_valid = exif.out.valid_out;

endmodule