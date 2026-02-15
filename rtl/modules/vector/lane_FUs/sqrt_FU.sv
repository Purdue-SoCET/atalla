// ------------------------------------------------------------
// sqrt_FU.sv
// Lane FU for sqrt
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "functional_unit_if.vh"
`include "vector_pkg.vh"
`include "sqrt_if.vh"

module sqrt_FU.sv (
    input logic                     CLK,
    input logic                     nRST,
    input functional_unit_if.fuif   fuif
);
    import vector_pkg::*;
    localparam int UNIT_LATENCY = 8; //latency of the arithmetic unit

    logic [7:0] vd_r, vd_n;

    //Module and interface instanciation
    lane_sequencer_if lsif();
    lane_sequencer seq (
        .CLK(CLK),
        .nRST(nRST),
        .seq_if(lsif)
    );

    sqrt_if srif();
    sqrt_bf6 sqrt(
        .CLK(CLK),
        .nRST(nRST),
        .srif(srif)
    );
    //take ready from sequencer
    assign fuif.out.input_ready = lsif.out.ready_in;
    assign lsif.in.v2 = 'b0;

    //input port decoding
    //this is a for loop in case for some reason we ever want to be able to issue more than 2
    always_comb begin : input_checking
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == SQRT) & fuif.in.input_ready) begin //are any of the input ports issuing to this FU? and we are ready
                lsif.in.valid_in = 'b1;
                lsif.in.v1 = fuif.in.ports[i].v1;
                lsif.in.mask = fuif.in.ports[i].mask;
            end
            else begin //we are not recieving any data or we are not ready. yes this could be optimized but i dont care
                lsif.in.valid_in = 'b0;
                lsif.in.v1 = 'b0;
                lsif.in.mask = 'b0;
            end
        end
    end

    //connections to the arithmetic unit
    assign srif.in.valid_in = lsif.out.valid_out; //only start the unit when there is data we want to operate on
    assign srif.in.operand = lsif.out.v1;
    assign srif.in.ready_out = fuif.in.wb_ready;
    assign lsif.in.ready_out = srif.out.ready_in;
    //bad solution but the other solution is not the same across each unit, so for the sake of time i am just tracking the mask bit and zeroing out the result when the FU is done
    logic mask_pipe [UNIT_LATENCY-1:0];
    logic valid_pipe [UNIT_LATENCY-1:0];
    logic [7:0] vd_pipe [UNIT_LATENCY-1:0];

    always_ff @(posedge CLK, negedge nRST) begin
        if (!nRST) begin
            for (int i = 0; i < UNIT_LATENCY; i++) begin
                mask_pipe[i] <= 1'b0;
                valid_pipe[i] <= 1'b0;
                 vd_pipe[i] <= 8'b0;
            end
        end 
        else if (fuif.in.wb_ready || !valid_pipe[UNIT_LATENCY-1]) begin
            mask_pipe[0] <= lsif.out.mask;
            valid_pipe[0] <= lsif.out.valid_out;
            vd_pipe[0] <= vd_n;
            
            for (int i = 1; i < UNIT_LATENCY; i++) begin
                mask_pipe[i] <= mask_pipe[i-1];
                valid_pipe[i] <= valid_pipe[i-1];
                vd_pipe[i] <= vd_pipe[i-1];
            end
        end
    end



    //metadata
    
    always_ff @(posedge CLK, negedge nRST) begin : metadata_reg
        if (!nRST) begin
            vd_r <= 'b0;
        end
        else begin
            vd_r <= vd_n;
        end
    end

    always_comb begin : metadata_comb
    vd_n = vd_r;
        //we want to register the metadata only upon accepting an input
        for (int i = 0; i < LANE_ISSUE_W; i++) begin
            if (fuif.in.ports[i].input_valid & (fuif.in.ports[i].usel == SQRT) & fuif.in.input_ready) begin
                vd_n = fuif.in.ports[i].vd;
            end
        end
    end
    assign fuif.out.vd = vd_pipe[UNIT_LATENCY-1];


    //output
    always_comb begin : unit_output
        if (!mask_pipe[UNIT_LATENCY-1] & srif.out.valid_out) begin //do we have a mask and valid data
            fuif.out.result = 'b0;
        end
        else begin
            fuif.out.result = srif.out.result;
        end
    end  
    
    assign fuif.out.wb_valid = srif.out.valid_out;

endmodule