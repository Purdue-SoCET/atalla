`include "lane_sequencer_if.vh"

module lane_sequencer(
    input logic CLK, 
    input logic nRST,

    lane_sequencer_if.lane_sequencer seq_if
);

    import vector_pkg::*;

    // bit width for the counter, need it to index 
    localparam IDX_WIDTH = (SLICE_W == 1) ? 1 : $clog2(SLICE_W);

    logic [IDX_WIDTH-1:0] elem_idx; // This is to count n track element output

    logic [SLICE_W-1:0][ESZ-1:0] v1_reg, v2_reg; // Registers for v1 and v2, based of number of elements in a slice, via # of lanes
    logic [SLICE_W-1:0] mask_reg; // Registers for the mask bits for the elements

    logic valid_reg; // register for valid signal
    logic ready_reg; // register for thr ready signal

    logic up_hanshake;
    logic down_handshake;
    logic last_elem;

    always_comb begin
        up_handshake = seq_if.in.valid_in && ready_reg;
        down_handshake = valid_reg && seq_if.in.ready_out;
        last_elem = (elem_idx == IDX_WIDTH'(SLICE_W - 1));

        seq_if.out.ready_in = ready_reg;
        seq_if.out.valid_out = valid_reg;

        seq_if.out.v1 = v1_reg[elem_idx];
        seq_if.out.v2 = v2_reg[elem_idx];
        seq_if.out.mask = mask_reg[elem_idx];
    end

    always_ff @(posedge CLK or negedge nRST) begin // registered_shtuff

        if (~nRST) begin
            elem_idx <= '0;

            v1_reg <= '0;
            v2_reg <= '0;
            mask_reg <= '0;

            valid_reg <= 1'b0;
            ready_reg <= 1'b1;
        end
        else begin
            if (up_handshake) begin
                elem_idx <= '0;

                v1_reg <= seq_if.in.v1;
                v2_reg <= seq_if.in.v2;
                mask_reg <= seq_if.in.mask;

                valid_reg <= 1'b1;
                ready_reg <= 1'b0;
            end 
            else if (down_handshake) begin
                if (last_elem) begin
                    elem_idx <= '0;

                    valid_reg <= 1'b0;
                    ready_reg <= 1'b1;
                end
                else begin
                    elem_idx <= elem_idx + 1'b1;
                end
            end
        end
    end


endmodule