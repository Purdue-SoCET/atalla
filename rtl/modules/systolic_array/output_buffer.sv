module output_buffer #(
    parameter int NUM_COLS          = 32,
    parameter int DATA_WIDTH        = 16,
    parameter int SRAM_DEPTH = 128,

    localparam int READ_LATENCY     = 1,
    localparam int WRITE_LATENCY    = 1,

    localparam int PTR_WIDTH = $clog2(SRAM_DEPTH)
)(
    input logic clk, nRST,
    input logic stall,
    input logic rd_en,
    input logic [NUM_COLS-1:0][DATA_WIDTH-1:0] wr_data,
    input logic [NUM_COLS-1:0] wr_en,
    output logic [NUM_COLS-1:0][DATA_WIDTH-1:0] rd_data,
    output logic [NUM_COLS-1:0] rdone
);

    logic [PTR_WIDTH-1:0] rd_ptr, next_rd_ptr;
    logic [NUM_COLS-1:0][PTR_WIDTH-1:0] wr_ptr, next_wr_ptr;
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

    always_comb begin : next_read_pointer
        next_rd_ptr = rd_ptr;
        if (rd_en && !stall) begin
            next_rd_ptr = (rd_ptr >= SRAM_DEPTH - 1) ? '0 : rd_ptr + 1;
        end
    end

    genvar i;
    generate
        for (i = 0; i < NUM_COLS; i++) begin
            always_comb begin : next_read_pointer
                next_wr_ptr[i] = wr_ptr[i];

                if (wr_en[i]) begin
                    next_wr_ptr[i] = (wr_ptr[i] >= SRAM_DEPTH - 1) ? '0 : wr_ptr[i] + 1;
                end
            end
            sram_bank #(
                .READ_LATENCY   (READ_LATENCY),
                .WRITE_LATENCY  (WRITE_LATENCY),
                .HEIGHT         (SRAM_DEPTH),
                .WIDTH          (DATA_WIDTH)
            ) u_sram (
                .clk    (clk),
                .n_rst  (nRST),
                .busy   (),
                .ren    (rd_en),
                .raddr  (rd_ptr),
                .rdata  (rd_data[i]),
                .rdone  (rdone[i]),
                .wen    (wr_en[i]),
                .waddr  (wr_ptr[i]),
                .wdata  (wr_data[i]),
                .wdone  ()
            );
        end
    endgenerate

endmodule