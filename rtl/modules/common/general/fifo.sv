// Credit: https://www.chipverify.com/verilog/synchronous-fifo
// https://www.chipverify.com/images/verilog/sync_fifo.svg

// NOTE on FWFT: this FIFO always presents the head of the queue on `dout`
// combinationally, i.e. it is inherently first-word-fall-through. The FWFT
// parameter exists so that call sites written against the ddr_cntrl_final
// variant (which took `.FWFT(1)`) bind without modification. FWFT=0 (a
// registered output) is NOT implemented -- no caller uses it.
//
// This version is kept over the ddr_cntrl_final one deliberately: the extra
// pointer bit (PTR_W = $clog2(DEPTH)+1) lets the FIFO hold all DEPTH entries,
// whereas the `(wptr+1)==rptr` full-check there sacrifices one slot. It also
// avoids zeroing the whole array on reset, which infers a large reset tree.
module fifo #(
    parameter DEPTH = 8, 
    parameter DWIDTH = 16,
    parameter FWFT = 1   // accepted for call-site compatibility; always FWFT
) (
    input rstn, clk, wr_en, rd_en, 
    input [DWIDTH-1:0] din, 	
    output logic [DWIDTH-1:0] dout, 	
    output  empty,  full 			
);
    localparam PTR_W = $clog2(DEPTH) + 1;
    reg [PTR_W-1:0] wptr;
    reg [PTR_W-1:0] rptr;

    wire [PTR_W-2:0] wptr_idx = wptr[PTR_W-2:0];
    wire [PTR_W-2:0] rptr_idx = rptr[PTR_W-2:0];

    reg [DWIDTH-1 : 0]    fifo[DEPTH];

    always_ff @(posedge clk, negedge rstn) begin
        if (!rstn) begin
            wptr <= 0;
        end else begin
            if (wr_en & !full) begin
                fifo[wptr_idx] <= din;
                wptr <= wptr + 1;
            end
        end
    end

    always_ff @(posedge clk, negedge rstn) begin
        if (!rstn) begin
            rptr <= 0;
        end else begin
            if (rd_en & !empty) begin
                rptr <= rptr + 1;
            end
        end
    end

    // Combinational output: always show head of FIFO
    assign dout  = fifo[rptr_idx];
    // Empty: pointers fully equal (same wrap cycle, same index)
    assign empty = (wptr == rptr);
    // Full: same index but different wrap cycle (top bit differs)
    assign full  = (wptr_idx == rptr_idx) && (wptr[PTR_W-1] != rptr[PTR_W-1]);
endmodule