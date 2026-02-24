// Triangle/trapezoid FIFO buffer design
// Nikhil Vaidyanath (nvaidyan@purdue.edu)
// For triangle buffer, RECT_DELAY should be 0 (no rectangle)

module skew_buffer #(
    parameter int NUM_COLS          = 32,
    parameter int COL_WIDTH         = 16,   // same as bank width (since one bank per column)
    parameter int RECT_DELAY        = 4,    // base level of delay for EVERY column
    parameter int DELAY_SLOPE       = 1,    // how much delay/skew from one column to next (in addition to rectangle delay)
    parameter logic REVERSE_TRIANGLE = 0,   // If 1, reverse triangle direction (right is lowest, left is highest), 
    //if 0 then it's a right triangle with right angle on the right side
    
    // assumption of 1 cycle read/writes
    localparam int READ_LATENCY      = 1,    // sram read latency
    localparam int WRITE_LATENCY     = 1,    // sram write latency (MUST be equal to read latency)
    // since first column gets 0 delay, last column can get NUM_COLS - 1 delay coefficient
    localparam int SRAM_DEPTH = RECT_DELAY + (DELAY_SLOPE * (NUM_COLS - 1)) + 1,
    localparam int PTR_WIDTH = $clog2(SRAM_DEPTH)
) (
    input  logic clk, n_rst,
    input  logic stall,

    // Write side
    input  logic [NUM_COLS-1:0][COL_WIDTH-1:0]      wr_data,

    // Read side
    output logic [NUM_COLS-1:0][COL_WIDTH-1:0]      rd_data
);

    // use global read/write pointers, offset using delay slope and initialize using latencies
    logic [PTR_WIDTH-1:0] wr_ptr, rd_ptr, next_wr_ptr, next_rd_ptr;

    always_ff @(posedge clk, negedge n_rst) begin : pointer_regs
        if (~n_rst) begin
            wr_ptr <= RECT_DELAY + 1; // initialize the skew in write pointer
            rd_ptr <= '0;
        end else begin
            wr_ptr <= next_wr_ptr;
            rd_ptr <= next_rd_ptr;
        end
    end

    always_comb begin : next_pointer
        next_wr_ptr = wr_ptr;
        next_rd_ptr = rd_ptr;

        // we're ALWAYS incrementing read & write pointers (when latency allows us to) UNLESS stall is high
        if (!stall) begin
            if (wr_ptr >= SRAM_DEPTH - 1) begin
                next_wr_ptr = 0;
            end else begin
                next_wr_ptr = wr_ptr + 1;
            end

            if (rd_ptr >= SRAM_DEPTH - 1) begin
                next_rd_ptr = 0;
            end else begin
                next_rd_ptr = rd_ptr + 1;
            end
        end
    end

    logic [NUM_COLS - 1:0][$clog2(SRAM_DEPTH) + 1:0] waddr;
    logic [NUM_COLS - 1:0][$clog2(SRAM_DEPTH) + 1:0] waddr_wrapped;

    genvar i;
    generate
        for (i = 0; i < NUM_COLS; i++) begin
            // Reverse Triangle logic, flip the direction of the slope
                if (REVERSE_TRIANGLE) begin
                    assign waddr[i] = wr_ptr + (DELAY_SLOPE * (NUM_COLS - i - 1));
                end else begin
                    assign waddr[i] = wr_ptr + (DELAY_SLOPE * i);
                end

                assign waddr_wrapped[i] = (waddr[i] >= SRAM_DEPTH) ? waddr[i] - SRAM_DEPTH : waddr[i]; 

            sram_bank #(
                .READ_LATENCY  (READ_LATENCY),
                .WRITE_LATENCY (WRITE_LATENCY),

                // can be theoretically be changed to RECT_DELAY + DELAY_SLOPE * i, makes banks look like triangle/trapezoid
                .HEIGHT        (SRAM_DEPTH), // all banks end up being same size, make the sram rectangular
                .WIDTH         (COL_WIDTH)
            ) u_sram (
                .clk   (clk),
                .n_rst (n_rst),
                .busy  (),
                .ren   (!stall),
                .raddr (rd_ptr), // NO offset for the rd_ptr
                .rdata (rd_data[i]),
                .rdone (),

                .wen   (!stall),
                .waddr (waddr_wrapped[i]),
                .wdata (wr_data[i]),
                .wdone ()
            );
        end
    endgenerate
endmodule
