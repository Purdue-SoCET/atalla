// ------------------------------------------------------------
// lane_sequencer.sv
// Sequences the slice of vector into the functional unit of a lane
// Owner: Vedant Sharma
// Paramater control for this file is in vector_pkg.vh
// ------------------------------------------------------------

`include "lane_sequencer_if.vh"

module lane_sequencer(
    input logic CLK, 
    input logic nRST,

    lane_sequencer_if.lane_sequencer seq_if
);

    import vector_pkg::*;

    // erm make sure slice_w is pow^2
    initial begin
        assert (2**$clog2(SLICE_W) == SLICE_W) else $fatal("SLICE_W must be a power of 2");
    end

    // bit width for the counter, need it to index 
    localparam IDX_WIDTH = (SLICE_W == 1) ? 1 : $clog2(SLICE_W);

    logic [IDX_WIDTH-1:0] elem_idx, elem_idx_n; // This is to count n track element output

    logic [SLICE_W-1:0][ESZ-1:0] v1_reg, v2_reg, v1_reg_n, v2_reg_n; // Registers for v1 and v2, based of number of elements in a slice, via # of lanes
    logic [SLICE_W-1:0] mask_reg, mask_reg_n; // Registers for the mask bits for the elements

    logic valid_reg, valid_reg_n; // register for valid signal
    logic ready_reg, ready_reg_n; // register for thr ready signal

    logic last_elem;
    assign last_elem = (elem_idx == IDX_WIDTH'(SLICE_W - 1));

    // This is the counter to track which element sequencer is on in the slice, it resets when completed a full slice or when theres new input
    always_ff @(posedge CLK or negedge nRST) begin: elem_idx_ff
        if (!nRST) begin
            elem_idx <= '0;
        end
        else begin
            elem_idx <= elem_idx_n;
        end
    end

    always_comb begin : elem_idx_comb
        elem_idx_n = elem_idx;

        // Advance when FU is ready for output
        if (valid_reg & seq_if.in.ready_out) begin
            if (last_elem) begin
                elem_idx_n = '0;
            end
            else begin
                elem_idx_n = elem_idx + 1;
            end
        end
    end

    // Register the input slice, and mask, and output valid/ready handshakes
    always_ff @(posedge CLK or negedge nRST) begin: registered_shtu_ff
        if (!nRST) begin
            v1_reg <= '0;
            v2_reg <= '0;
            mask_reg <= '0;
        end
        else begin
            v1_reg <= v1_reg_n;
            v2_reg <= v2_reg_n;
            mask_reg <= mask_reg_n;
        end
    end

    always_comb begin: registered_shtu_ff_next
        v1_reg_n = v1_reg;
        v2_reg_n = v2_reg;
        mask_reg_n = mask_reg;

        // Capture new slice when ready and valid
        if (seq_if.in.valid_in & ready_reg) begin
            v1_reg_n = seq_if.in.v1;
            v2_reg_n = seq_if.in.v2;
            mask_reg_n = seq_if.in.mask;
        end
    end

    // Ideally I'd do this in a comb, but im lowkey too lazy
    assign seq_if.out.v1 = v1_reg[elem_idx];
    assign seq_if.out.v2 = v2_reg[elem_idx];
    assign seq_if.out.mask = mask_reg[elem_idx];

    always_ff @(posedge CLK or negedge nRST) begin: valid_ff
        if (!nRST) begin
            valid_reg <= 1'b0;
        end
        else begin
            valid_reg <= valid_reg_n;
        end
    end

    always_comb begin: valid_comb
        valid_reg_n = valid_reg;

        // Assert valid when we accept a new slice
        if (seq_if.in.valid_in & ready_reg) begin
            valid_reg_n = 1'b1;
        end
        // Deassert valid when last element completes
        else if (valid_reg & seq_if.in.ready_out & last_elem) begin
            valid_reg_n = 1'b0;
        end
    end

    assign seq_if.out.valid_out = valid_reg;

    always_ff @(posedge CLK, negedge nRST) begin : ready_ff
        if (!nRST) begin
            ready_reg <= 1'b1;
        end
        else begin
            ready_reg <= ready_reg_n;
        end
    end

    always_comb begin : ready_comb
        ready_reg_n = ready_reg;

        // Not ready when accept a new slice
        if (seq_if.in.valid_in & ready_reg) begin
            ready_reg_n = 1'b0;
        end
        // Ready again when last element completes
        else if (valid_reg & seq_if.in.ready_out & last_elem) begin
            ready_reg_n = 1'b1;
        end
    end

    assign seq_if.out.ready_in = ready_reg;


endmodule