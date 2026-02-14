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

    assign up_handshake = seq_if.in.valid_in && ready_reg; // when thing above has valid data and sequener doesnt alr have a slice processing
    assign down_handshake = valid_reg && seq_if.in.ready_out; // 
    assign last_elem = (elem_idx == IDX_WIDTH'(SLICE_W - 1));


    always_ff @(posedge CLK or negedge nRST) begin // registered_shtuff

        if (~nRST) begin
            elem_idx <= '0;

            v1_reg <= '0;
            v2_reg <= '0;
            mask_reg <= '0;

            valid
        end
        
    end


endmodule