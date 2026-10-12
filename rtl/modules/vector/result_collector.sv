// ------------------------------------------------------------
// result_collector.sv
// Collect per-lane FU results into full vectors per FU
// Owner: Jacob Walter
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------
`include "result_collector_if.vh"
`include "vector_pkg.vh"

module result_collector (
    input  logic               CLK,
    input  logic               nRST,
    result_collector_if.rcif   rcif
);
    import vector_pkg::*;
    
    localparam int TIMES = VLMAX / NUM_LANES; //how many times we need to collect until we have a full vector. THIS MUST BE A POWER OF 2
    

    logic [NUM_LANES-1:0][TIMES-1:0][ESZ - 1:0] collection_arrays, collection_arrays_n;
    logic [NUM_LANES-1:0] array_full;
    logic reset_all_counters;
    logic [$clog2(TIMES)-1:0] count_array [NUM_LANES-1:0];
    logic [7:0] vd, vd_n;
    logic mop, mop_n;

    //counter instanciation
    assign reset_all_counters = (&array_full) & rcif.out.wb_valid & rcif.in.wb_ready; //global reset
    genvar i;
    generate
        for (i = 0; i < NUM_LANES; i++) begin : lane_counters
            logic [$clog2(TIMES)-1:0] count;
            logic increment_count;
            
            assign increment_count = rcif.in.input_valid[i] & rcif.out.input_ready[i] & (count < TIMES);
            
            result_collector_counter #(
                .COUNT_TO(TIMES)
            ) counter_inst (
                .CLK(CLK),
                .nRST(nRST),
                .increment(increment_count),
                .reset_counter(reset_all_counters),
                .count(count),
                .at_max(array_full[i])
            );
            
            // Export count to array
            assign count_array[i] = count;
        end
    endgenerate

    //collection
    always_ff @(posedge CLK, negedge nRST) begin : storage_ff
        if (!nRST) begin
            collection_arrays <= 'b0;
        end
        else begin
            collection_arrays <= collection_arrays_n;
        end
    end

    always_comb begin : storage_comb
        collection_arrays_n = collection_arrays;
        for (int j = 0; j < NUM_LANES; j++) begin
            if (rcif.in.input_valid[j] & rcif.out.input_ready[j] & (count_array[j] < TIMES)) begin
                collection_arrays_n[j][count_array[j]] = rcif.in.mask[j] ? rcif.in.lane_input[j] : 'b0;
            end
        end
    end
        
    assign rcif.out.vector_output = collection_arrays; //theoretically this works cause they are both packed and the same bit width

    //vd and mop latching
    logic vd_locked, vd_locked_n;
    logic mop_locked, mop_locked_n;
    always_ff @(posedge CLK, negedge nRST) begin : vd_ff
        if (!nRST) begin
            vd <= 'b0;
            vd_locked <= 1'b0;
            mop <= 'b0;
            mop_locked <= 1'b0;
        end
        else begin
            vd <= vd_n;
            vd_locked <= vd_locked_n;
            mop <= mop_n;
            mop_locked <= mop_locked_n;
        end
    end



    always_comb begin
        vd_locked_n = vd_locked;
        mop_locked_n = mop_locked;
        // Lock VD and MOP when first valid data arrives
        if ((|rcif.in.input_valid) & (|rcif.out.input_ready) & !vd_locked) begin
            vd_locked_n = 1'b1;
        end
        if ((|rcif.in.input_valid) & (|rcif.out.input_ready) & !mop_locked) begin
            mop_locked_n = 1'b1;
        end
        
        // Unlock when handshake completes (vector written back)
        if (rcif.out.wb_valid & rcif.in.wb_ready) begin
            vd_locked_n = 1'b0;
            mop_locked_n = 1'b0;
        end
    end

    always_comb begin : vd_comb
        vd_n = vd;
        mop_n = mop;
        // Capture vd and mop on first valid input, only when unlocked
        if ((|rcif.in.input_valid) & (|rcif.out.input_ready) & !vd_locked) begin
            vd_n = rcif.in.vd_input;
        end
        if ((|rcif.in.input_valid) & (|rcif.out.input_ready) & !mop_locked) begin
            mop_n = rcif.in.mop_in;
        end
    end
    assign rcif.out.vd_output = vd;
    assign rcif.out.mop_out = mop;
    //valid ready determination
    logic [NUM_LANES-1:0] ready, ready_n;
    always_ff @(posedge CLK, negedge nRST) begin : ready_ff
        if (!nRST) begin
            ready <= 'b1;
        end
        else begin
            ready <= ready_n;
        end
    end

always_comb begin : ready_comb
    for (int i = 0; i < NUM_LANES; i++) begin
        ready_n[i] = ready[i];
        if ((rcif.out.wb_valid & !rcif.in.wb_ready & ready[i])) begin
            ready_n[i] = 1'b0;
        end
        else if (rcif.in.wb_ready & !ready[i]) begin
            ready_n[i] = 1'b1;
        end
    end
end

    assign rcif.out.input_ready = ready;

    // wb_valid generation - registered version
    logic wb_valid_r, wb_valid_n;

    always_ff @(posedge CLK, negedge nRST) begin : wb_valid_ff
        if (!nRST) begin
            wb_valid_r <= 1'b0;
        end
        else begin
            wb_valid_r <= wb_valid_n;
        end
    end

    always_comb begin : wb_valid_comb
        wb_valid_n = wb_valid_r;
        
        // Set when all lanes full and not currently valid
        if ((&array_full) & !wb_valid_r) begin
            wb_valid_n = 1'b1;
        end
        
        // Clear immediately when handshake occurs
        if (wb_valid_r & rcif.in.wb_ready) begin
            wb_valid_n = 1'b0;
        end
    end

    assign rcif.out.wb_valid = (wb_valid_r | (&array_full)) & !(wb_valid_r & rcif.in.wb_ready);
    
endmodule