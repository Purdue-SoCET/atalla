// Credit: https://www.chipverify.com/verilog/synchronous-fifo
// https://www.chipverify.com/images/verilog/sync_fifo.svg

module sync_fifo #(
    parameter DEPTH = 8, 
    parameter DWIDTH = 16,
    parameter FWFT  = 0   // 1 = first-word-fall-through (dout tracks head combinationally)
) (
    input rstn, clk, wr_en, rd_en, 
    input [DWIDTH-1:0] din, 	
    output [DWIDTH-1:0] dout, 	
    output  empty,  full 			
);
    reg [$clog2(DEPTH)-1:0]   wptr;
    reg [$clog2(DEPTH)-1:0]   rptr;

    reg [DWIDTH-1 : 0]    fifo[DEPTH];
    reg [DWIDTH-1 : 0]    dout_reg;

    integer k;
    always_ff @(posedge clk, negedge rstn) begin
        if (!rstn) begin
            wptr <= 0;
            for (k = 0; k < DEPTH; k = k + 1)
                fifo[k] <= '0;
        end else begin
            if (wr_en & !full) begin
                fifo[wptr] <= din;
                wptr <= wptr + 1;
            end
        end
    end

    always_ff @(posedge clk, negedge rstn) begin
        if (!rstn) begin
            rptr     <= 0;
            dout_reg <= '0;
        end else begin
            if (rd_en & !empty) begin
                dout_reg <= fifo[rptr];
                rptr     <= rptr + 1;
            end
        end
    end

    assign dout  = FWFT ? fifo[rptr] : dout_reg;
    assign full  = (wptr + 1) == rptr;
    assign empty = wptr == rptr;
endmodule