// This exists only cause i couldnt get the one in common to work
module lane_unit_fifo #(
    parameter DEPTH = 8,
    parameter DWIDTH = 1
) (
    input  logic clk,
    input  logic nRST,
    input  logic wr_en,
    input  logic rd_en,
    input  logic [DWIDTH-1:0] din,
    output logic [DWIDTH-1:0] dout,
);

    localparam PWIDTH = $clog2(DEPTH);
    
    logic [DWIDTH-1:0] mem [DEPTH-1:0];
    logic [PWIDTH:0] count;  // Extra bit to count up to DEPTH
    logic [PWIDTH-1:0] wptr, rptr;
    logic full;
    logic empty;

    // Counter tracks number of elements
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            count <= '0;
        end else begin
            case ({wr_en & !full, rd_en & !empty})
                2'b10: count <= count + 1;  // Write only
                2'b01: count <= count - 1;  // Read only
                default: count <= count;     // Both or neither
            endcase
        end
    end

    // Write pointer
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            wptr <= '0;
        end else if (wr_en & !full) begin
            mem[wptr] <= din;
            wptr <= (wptr + 1) % DEPTH;
        end
    end

    // Read pointer
    always_ff @(posedge clk, negedge nRST) begin
        if (!nRST) begin
            rptr <= '0;
        end else if (rd_en & !empty) begin
            rptr <= (rptr + 1) % DEPTH;
        end
    end

    // Outputs
    assign dout  = mem[rptr];
    assign full  = (count == DEPTH);
    assign empty = (count == 0);

endmodule