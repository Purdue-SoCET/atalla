// ------------------------------------------------------------
// alu_FU.sv
// Lane FU for alu
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "functional_unit_if.vh"
`include "lane_sequencer_if.vh"

`include "alu_if.vh"

module mul_FU (
    input logic                     CLK,
    input logic                     nRST,
    functional_unit_if.fuif        fuif
);
    import vector_pkg::*;
    localparam int UNIT_LATENCY = 2;

    logic [7:0] vd;
    logic rm;
    logic [1:0] aluop;

    //Module and interface instanciation
    lane_sequencer_if lsif();
    lane_sequencer seq (
        .CLK(CLK),
        .nRST(nRST),
        .seq_if(lsif)
    );

    valu_if aluif();
    valu alu(
        .CLK(CLK),
        .nRST(nRST),
        .aluif(aluif)
    );

    assign fuif.out.input_ready = lsif.out.ready_in;

    //input port decoding
    //this is a for loop in case for some reason we ever want to be able to issue more than 2
    always_comb begin : input_checking
        lsif.in.valid_in = 'b0;
        lsif.in.v1 = 'b0;
        lsif.in.v2 = 'b0;
        lsif.in.mask = 'b0;
        vd = 'b0;
        aluop = 'b0;
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == MUL) & fuif.out.input_ready) begin //are any of the input ports issuing to this FU? and we are ready
                lsif.in.valid_in = 'b1;
                lsif.in.v1 = fuif.in.ports[i].v1;
                lsif.in.v2 = fuif.in.ports[i].v2;
                lsif.in.mask = fuif.in.ports[i].mask;
                vd = fuif.in.ports[i].vd;
                rm = fuif.in.ports[i].rm;
                aluop = fuif.in.ports[i].alu_op;
            end
        end
    end

    //connections to the arithmetic unit. always goes through the unit
    assign aluif.in.valid_in = lsif.out.valid_out; //only start the unit when there is data we want to operate on
    assign aluif.in.operand1 = lsif.out.v1;
    assign aluif.in.operand2 = lsif.out.v2;
    assign aluif.in.ready_out = fuif.in.wb_ready;
    assign lsif.in.ready_out = aluif.out.ready_in;

    //mask
        lane_unit_fifo #(
        .DEPTH(4),   // Twice as big as i think i need
        .DWIDTH(1)    // Single mask bit
    ) mask_fifo (
        .clk(CLK),
        .nRST(nRST),
        .wr_en(lsif.out.valid_out & aluif.out.ready_in),
        .rd_en(aluif.out.valid_out & fuif.in.wb_ready),
        .din(lsif.out.mask),
        .dout(fuif.out.mask)
    );

    //vd
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
        if (aluif.out.valid_out & fuif.in.wb_ready) begin
            if (output_count_r == SLICE_W - 1) begin
                output_count_n = '0;  // Wrap back to 0
            end else begin
                output_count_n = output_count_r + 1;
            end
        end
    end

    logic is_last_element;
    assign is_last_element = (output_count_r == (SLICE_W - 1));

    lane_unit_fifo #(
        .DEPTH(4),
        .DWIDTH(8)
    ) vd_fifo (
        .clk(CLK),
        .nRST(nRST),
        .wr_en(lsif.in.valid_in & lsif.out.ready_in),
        .rd_en(aluif.out.valid_out & fuif.in.wb_ready & is_last_element),  // Pop on last element only
        .din(vd),
        .dout(fuif.out.vd)
    );

    lane_unit_fifo #(
        .DEPTH(4),
        .DWIDTH(1)
    ) rm_fifo (
        .clk(CLK),
        .nRST(nRST),
        .wr_en(lsif.in.valid_in & lsif.out.ready_in),
        .rd_en(aluif.out.valid_out & fuif.in.wb_ready & is_last_element),  // Pop on last element only
        .din(rm),
        .dout(fuif.out.rm)
    );

    lane_unit_fifo #(
        .DEPTH(4),
        .DWIDTH(1)
    ) aluop_fifo (
        .clk(CLK),
        .nRST(nRST),
        .wr_en(lsif.in.valid_in & lsif.out.ready_in),
        .rd_en(aluif.out.valid_out & fuif.in.wb_ready & is_last_element),  // Pop on last element only
        .din(aluop),
        .dout(aluif.in.aluop) //connection to aluif
    );


    assign fuif.out.result = aluif.out.result;
    assign fuif.out.rm = 0;
    assign fuif.out.wb_valid = aluif.out.valid_out;

endmodule