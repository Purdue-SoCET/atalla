// ------------------------------------------------------------
// result_collector.sv
// Collect per-lane FU results into full vectors per FU
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "result_collector.vh"
`include "vector_pkg.vh"

module result_collector (
    input  logic               CLK,
    input  logic               nRST,
    result_collector_if.rcif   rcif
);
    import vector_pkg::*;
    
    localparam int TIMES = VLMAX / NUM_LANES; //how many times we need to collect until we have a full vector. THIS MUST BE A POWER OF 2
    

    logic [$clog2(TIMES) - 1: 0] counter, counter_n;
    vreg_t storage_vector, storage_vector_n;
    logic [7:0] vd, vd_n;

    //counter
    always_ff @(posedge CLK, negedge nRST) begin : counter_ff
        if (!nRST) begin
            counter <= 0;
        end
        else begin
            counter <= counter_n;
        end
    end 

    always_comb begin : counter_comb
        counter_n = counter;
        if (rcif.in.input_valid & rcif.out.input_ready & (counter < TIMES)) begin //only incrament on valid inputx
            counter_n = counter + 1;
        end
        if ((counter == TIMES - 1) & rcif.out.wb_valid & rcif.in.wb_ready) begin //only reset the counter when data has been accepted by wb
            counter_n = 'b0;
        end
    end


    //collection
    always_ff @(posedge CLK, negedge nRST ) begin : storage_ff
        if (!nRST) begin
            storage_vector <= 'b0;
        end
        else begin
            storage_vector <= storage_vector_n;
        end
    end

    always_comb begin : storage_comb
        storage_vector_n = storage_vector;
        //if we are given valid data
        if (rcif.in.input_valid & rcif.out.input_ready & (counter < TIMES)) begin
            //put it into the storage vector at the correct indexes
            for (int i = 0; i < NUM_LANES; i++) begin
                storage_vector_n[(i << $clog2(TIMES)) + counter] = rcif.in.lane_input[i]; //the shift avoids any chance of a multiplier being synthed. This is the same as i * TIMES
            end
        end
    end
    assign rcif.out.vector_output = storage_vector;

    //vd latching
    always @(posedge CLK, negedge nRST) begin : vd_ff
        if (!nRST) begin
            vd <= 'b0;
        end
        else begin
            vd <= vd_n;
        end
    end

    always_comb begin : vd_comb
        vd_n = vd;
        //only update vd when we get the first input in the vector
        if ((counter == 'b0) & rcif.in.input_valid & rcif.out.input_ready) begin
            vd_n = rcif.in.vd_input;
        end
    end
    assign rcif.out.vd_output = vd;

    //valid ready determination
    logic ready, ready_n;
    always_ff @(posedge CLK, negedge nRST) begin : ready_ff
        if (!nRST) begin
            ready <= 'b1;
        end
        else begin
            ready <= ready_n;
        end
    end

    always_comb begin : ready_comb
        ready_n = ready;
        if ((rcif.out.wb_valid & !rcif.in.wb_ready & ready)) begin //if wb is not ready, and we have valid data, and are in the ready state, go to not ready
            ready_n = 'b0;
        end
        else if (rcif.in.wb_ready & !ready) begin //only upon output ready going high become ready again. 
            ready_n = 'b1;
        end
    end

    assign rcif.out.input_ready = ready;

    //WB_Valid needs to be delayed one cycle
    logic wb_valid_delayed, wb_valid_delayed_n;
    always_ff @(posedge CLK, negedge nRST) begin : wb_valid_ff
        if (!nRST) begin
            wb_valid_delayed <= 1'b0;
        end
        else begin
            wb_valid_delayed <= wb_valid_delayed_n;
        end
    end

    always_comb begin : wb_valid_comb
        wb_valid_delayed_n = wb_valid_delayed; // Default: hold current value
        
        // Assert valid when we've collected a full vector
        if (counter == TIMES - 1) begin
            wb_valid_delayed_n = 1'b1;
        end
        
        // Only deassert valid when handshake completes
        if (wb_valid_delayed & rcif.in.wb_ready) begin
            wb_valid_delayed_n = 1'b0;
        end
    end
    
    assign rcif.out.wb_valid = wb_valid_delayed; //we have valid data when when counter == times
    


    //After running this module for a LLM to see if it spotted any major errors, it suggested adding an assertion to ensure that TIMES is a power of 2
    //If this causes issues it will be removed, but i agree that its a good idea if it doesnt break anything
    initial begin
        assert (2**$clog2(TIMES) == TIMES) else 
            $fatal("TIMES must be a power of 2");
    end

endmodule