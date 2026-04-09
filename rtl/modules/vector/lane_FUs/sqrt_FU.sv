// ------------------------------------------------------------
// sqrt_FU.sv
// Lane FU for sqrt
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "functional_unit_if.vh"
`include "lane_sequencer_if.vh"

`include "sqrt_if.vh"

module sqrt_FU (
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

    sqrt_if srif();
    sqrt_bf16 sqrt(
        .CLK(CLK),
        .nRST(nRST),
        .srif(srif)
    );
    //take ready from sequencer
    assign fuif.out.input_ready = lsif.out.ready_in;
    assign lsif.in.v2 = 'b0;

    //input port decoding
    always_comb begin : input_checking
        lsif.in.valid_in = 'b0;
        lsif.in.v1 = 'b0;
        lsif.in.mask = 'b0;
        vd = 'b0;
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == SQRT) & fuif.out.input_ready) begin //are any of the input ports issuing to this FU? and we are ready
                lsif.in.valid_in = 'b1;
                lsif.in.v1 = fuif.in.ports[i].v1;
                lsif.in.mask = fuif.in.ports[i].mask;
                vd = fuif.in.ports[i].vd;
            end
        end
    end

    //connections to the arithmetic unit. always goes through the unit
    assign srif.in.valid_in = lsif.out.valid_out; //only start the unit when there is data we want to operate on
    assign srif.in.operand = lsif.out.v1;
    assign srif.in.ready_out = fuif.in.wb_ready;
    assign lsif.in.ready_out = srif.out.ready_in;
    
    //idea for tracking masking: when seq streams out valid data, push the mask bit, when there is a valid output handshake, pop it
    lane_unit_fifo #(
        .DEPTH(4),   // Twice as big as i think i need
        .DWIDTH(1)    // Single mask bit
    ) mask_fifo (
        .clk(CLK),
        .nRST(nRST),
        .wr_en(lsif.out.valid_out & srif.out.ready_in),
        .rd_en(srif.out.valid_out & fuif.in.wb_ready),
        .din(lsif.out.mask),
        .dout(fuif.out.mask)
    );

    // VD metadata
    logic [$clog2(SLICE_W)-1:0] output_count_r, output_count_n;
    //this is the best idea i could come up with. Its probably bad. The idea is when the lane is issued a valid input that we can accept we push the VD into a fifo
    //we track what element of the slice is being sent, and only pop the fifo once the last element has been sent through

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            output_count_r <= '0;
        end else begin
            output_count_r <= output_count_n;
        end
    end

    always_comb begin
        output_count_n = output_count_r;
        if (srif.out.valid_out & fuif.in.wb_ready) begin
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
        .rd_en(srif.out.valid_out & fuif.in.wb_ready & is_last_element),  // Pop on last element only
        .din(vd),
        .dout(fuif.out.vd)
    );


    //output
    assign fuif.out.result = srif.out.result;
    assign fuif.out.rm = 0;
    assign fuif.out.wb_valid = srif.out.valid_out;

endmodule