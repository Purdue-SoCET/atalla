// ------------------------------------------------------------
// alu_FU.sv
// Lane FU for alu
// Owner: Jacob Walter
// This module only works with lanes = 16 cause my reduction module is bad
// This module also assumes that slice width = 2.
// ------------------------------------------------------------
`include "vector_pkg.vh"
`include "functional_unit_if.vh"
`include "lane_sequencer_if.vh"

`include "valu_if.vh"

module alu_FU (
    input logic                     CLK,
    input logic                     nRST,
    functional_unit_if.fuif        fuif
);
    import vector_pkg::*;
    localparam int UNIT_LATENCY = 2;

    logic [7:0] vd;
    logic rm;
    alu_op_t alu_op;
    logic [ESZ-1:0] v1_adjusted, v2_adjusted; //ability to adjust the values in case of reduction

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
        .alu_if(aluif)
    );

    assign fuif.out.input_ready = lsif.out.ready_in;

    always_comb begin : reduction_adjustment
        //adjust the values based on the masks and reduction type
        //seperated for clarity
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == VALU) & fuif.out.input_ready) begin
                if (fuif.in.ports[i].alu_op == ALU_ADD) begin //sum reduction set to 0
                    v1_adjusted = (fuif.in.ports[i].mask[0]) ? fuif.in.ports[i].v1[0] : '0;
                    v2_adjusted = (fuif.in.ports[i].mask[1]) ? fuif.in.ports[i].v1[1] : '0;
                end
                else if (fuif.in.ports[i].alu_op == ALU_MGT) begin //max reduction set to -inf
                    v1_adjusted = (fuif.in.ports[i].mask[0]) ? fuif.in.ports[i].v1[0] : 16'hff80;
                    v2_adjusted = (fuif.in.ports[i].mask[1]) ? fuif.in.ports[i].v1[1] : 16'hff80;
                end
                else if (fuif.in.ports[i].alu_op == ALU_MLT) begin //min reduction, set to pos inf
                    v1_adjusted = (fuif.in.ports[i].mask[0]) ? fuif.in.ports[i].v1[0] : 16'h7f80;
                    v2_adjusted = (fuif.in.ports[i].mask[1]) ? fuif.in.ports[i].v1[1] : 16'h7f80;
                end
            end
        end
    end


    //if this is a reduction and we are ready to take data, we need to put element 1 in v1 and element v2 and pad with zeroes
    always_comb begin : input_checking
        lsif.in.valid_in = 'b0;
        lsif.in.v1 = 'b0;
        lsif.in.v2 = 'b0;
        lsif.in.mask = 'b0;
        lsif.in.rm = '0;
        lsif.in.aluop = '0;
        rm = '0;
        vd = 'b0;
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == VALU) & fuif.out.input_ready) begin //are any of the input ports issuing to this FU? and we are ready
                lsif.in.valid_in = 'b1;
                rm = fuif.in.ports[i].rm;
                vd = fuif.in.ports[i].vd;
                lsif.in.rm = {SLICE_W{fuif.in.ports[i].rm}};
                lsif.in.aluop = {SLICE_W{fuif.in.ports[i].alu_op}};
                if (fuif.in.ports[i].rm) begin
                    //flatten v1 into the 2 ports and padd with 0s so that we can still just go through the seq
                    lsif.in.v1[1] = '0;
                    lsif.in.v1[0] = v1_adjusted;
                    lsif.in.v2[1] = '0;
                    lsif.in.v2[0] = v2_adjusted;
                    lsif.in.mask[1] = 'b0;
                    lsif.in.mask[0] = 'b1;
                end
                else begin
                    lsif.in.v1 = fuif.in.ports[i].v1;
                    lsif.in.v2 = fuif.in.ports[i].v2;
                    lsif.in.mask = fuif.in.ports[i].mask;
                end
            end
        end
    end

    assign aluif.in.valid_in = lsif.out.valid_out;
    assign aluif.in.v1 = lsif.out.v1;
    assign aluif.in.v2 = lsif.out.v2;
    assign aluif.in.mask = lsif.out.mask;
    assign aluif.in.aluop = lsif.out.aluop;
    assign aluif.in.rm = lsif.out.rm;
    assign aluif.in.ready_out = fuif.in.wb_ready;
    assign lsif.in.ready_out = aluif.out.ready_in;
    assign fuif.out.mask = 'b1; //pull high as the ALU itself handles the masking in this case

    


    //vd stuff
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
        .rd_en(aluif.out.valid_out & fuif.in.wb_ready),  // Pop on first output of ALU
        .din(rm),
        .dout(fuif.out.rm)
    ); 

    assign fuif.out.result = aluif.out.result;
    assign fuif.out.wb_valid = aluif.out.valid_out;


endmodule