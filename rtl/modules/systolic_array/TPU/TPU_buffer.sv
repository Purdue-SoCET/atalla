module TPU_buffer #(
    parameter int NUM_COLS          = 32,
    parameter int DATA_WIDTH        = 16,

    localparam int READ_LATENCY     = 1,
    localparam int WRITE_LATENCY    = 1,

    localparam int SRAM_DEPTH = NUM_COLS,
    localparam int PTR_WIDTH = $clog2(SRAM_DEPTH)
)(
    input logic clk, nRST,
    input logic wr_en,
    input logic [NUM_COLS-1:0][DATA_WIDTH-1:0] wr_data,
    input logic [NUM_COLS-1:0] rd_en,
    output logic [NUM_COLS-1:0][DATA_WIDTH-1:0] rd_data,
    output logic lane0_empty, full
);

    logic [PTR_WIDTH-1:0] wr_ptr, next_wr_ptr;
    logic [NUM_COLS-1:0][PTR_WIDTH-1:0] rd_ptr, next_rd_ptr;
    logic [SRAM_DEPTH-1:0] empty_vec, full_vec;
    logic [NUM_COLS-1:0][PTR_WIDTH-1:0] used;

    always_ff @(posedge clk or negedge nRST) begin : pointers_regs
        if (!nRST) begin
            wr_ptr <= '0;
            rd_ptr <= '0;
        end else begin
            wr_ptr <= next_wr_ptr;
            rd_ptr <= next_rd_ptr;
        end
    end

    always_comb begin : next_write_pointer
        next_wr_ptr = wr_ptr;
        if (wr_en) begin
            next_wr_ptr = (wr_ptr >= SRAM_DEPTH - 1) ? '0 : wr_ptr + 1;
        end
    end

    genvar i;
    generate
        for (i = 0; i < NUM_COLS; i++) begin
            always_comb begin : next_read_pointer
                next_rd_ptr[i] = rd_ptr[i];

                if (rd_en[i]) begin
                    next_rd_ptr[i] = (rd_ptr[i] >= SRAM_DEPTH -1) ? '0 : rd_ptr[i] + 1;
                end
            end

            always_comb begin
                used[i] = (wr_ptr >= rd_ptr[i]) ? (wr_ptr - rd_ptr[i]) : (wr_ptr + SRAM_DEPTH - rd_ptr[i]);             
                // empty_vec[i] = (used[i] == 0);
                if (i == 0) begin
                    lane0_empty = (used[i] == 0);
                end
                full_vec[i] = (used[i] == SRAM_DEPTH - 1);
            end

            sram_bank #(
                .READ_LATENCY   (READ_LATENCY),
                .WRITE_LATENCY  (WRITE_LATENCY),
                .HEIGHT         (SRAM_DEPTH),
                .WIDTH          (DATA_WIDTH)
            ) u_sram (
                .clk    (clk),
                .nRST   (nRST),
                .busy   (),
                .ren    (rd_en[i]),
                .raddr (rd_ptr[i]),
                .rdata  (rd_data[i]),
                .rdone  (),
                .wen    (wr_en),
                .waddr  (wr_ptr),
                .wdata  (wr_data[i]),
                .wdone  ()
            );
        end
    endgenerate

    assign full = |full_vec;
    // assign empty = &empty_vec;
endmodule