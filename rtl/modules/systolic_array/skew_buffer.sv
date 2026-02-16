// Triangle/trapezoid FIFO buffer design
// Nikhil Vaidyanath (nvaidyan@purdue.edu)
// For triangle buffer, RECT_DELAY should be 0 (no rectangle)

module skew_buffer #(
    parameter int NUM_COLS          = 32,
    parameter int COL_WIDTH         = 16,   // same as bank width (since one bank per column)
    parameter int RECT_DELAY        = 4,    // base level of delay for EVERY column
    parameter int DELAY_SLOPE       = 1,    // how much delay/skew from one column to next (in addition to rectangle delay)
    parameter int READ_LATENCY      = 1,    // sram read latency
    parameter int WRITE_LATENCY     = 1,    // sram write latency (MUST be equal to read latency)
    
    // since first column gets 0 delay, last column can get NUM_COLS - 1 delay coefficient
    localparam int SRAM_DEPTH = RECT_DELAY + (DELAY_SLOPE * (NUM_COLS - 1)),
    localparam int PTR_WIDTH = $clog2(SRAM_DEPTH)
) (
    input  logic clk, n_rst,
    input  logic stall,

    // Write side
    input  logic                                    wr_en,
    input  logic [NUM_COLS-1:0][COL_WIDTH-1:0]      wr_data,

    // Read side
    output logic [NUM_COLS-1:0][COL_WIDTH-1:0]      rd_data,
);



    // use global read/write pointers, offset using delay slope and initialize using latencies
    logic [PTR_WIDTH-1:0] wr_ptr, rd_ptr, next_wr_ptr, next_rd_ptr;

    // this only matters if latency is over 1, we need to hold address for that many cycles,
    // ends up making rd/wr_ptr not advance every non-stalled cycle
    logic [$clog2(READ_LATENCY):0] ptr_counter, next_ptr_counter;

    always_ff @(posedge clk, negedge n_rst) begin : pointer_regs
        if (~n_rst) begin
            wr_ptr <= RECT_DELAY - READ_LATENCY; // initialize the skew in write pointer
            rd_ptr = '0;
            ptr_counter <= '0;
        end else begin
            wr_ptr = next_wr_ptr;
            rd_ptr = next_rd_ptr;
            ptr_counter <= next_ptr_counter;
        end
    end

    always_comb begin : next_pointer
        next_wr_ptr = wr_ptr;
        next_rd_ptr = rd_ptr;
        next_ptr_counter = ptr_counter;

        // we're ALWAYS incrementing read & write pointers (when latency allows us to) UNLESS stall is high
        if (!stall) begin
            if (wr_ptr >= SRAM_DEPTH - 1) begin
                next_wr_ptr = '0;
            end else if (ptr_counter == READ_LATENCY - 1) begin
                next_wr_ptr = wr_ptr + 1;
                next_ptr_counter = '0;
            end else begin
                next_ptr_counter = ptr_counter + 1;
            end

            if (rd_ptr >= SRAM_DEPTH - 1) begin
                next_rd_ptr = '0;
            end else if (ptr_counter == READ_LATENCY - 1) begin
                next_rd_ptr = rd_ptr + 1;
                next_ptr_counter = '0;
            end else begin
                next_ptr_counter = ptr_counter + 1;
            end
        end
    end

    generate;
        for (genvar i; i < NUM_COLS, i++) begin
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
                .rdata (rd_data),
                .rdone (),

                .wen   (!stall),
                .waddr (wr_ptr + (DELAY_SLOPE * i)),
                .wdata (wr_data),
                .wdone ()
            );
        end
    endgenerate
endmodule