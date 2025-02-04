`include "systolic_array_PS_FIFO_if.vh"

module sysarr_PS_FIFO #(
    parameter N = 4, 
    parameter WIDTH = 16
)(
    input logic clk, nRST,
    systolic_array_PS_FIFO_if.PS_FIFO ps_fifo
);
    // Internal storage for Partial sums FIFO
    logic [(2 * N + 1) * WIDTH - 1 : 0] ps_fifo_mem; //need space for two arrays 2 rows of matrix rows added one bc delay
    logic [(2 * N + 1) * WIDTH - 1 : 0] ps_fifo_mem_next;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            ps_fifo_mem <= '0;     // Reset fifo mem to all zeros
        end else begin
            ps_fifo_mem <= ps_fifo_mem_next; 
        end
    end
    integer i;
    always_comb begin
        ps_fifo_mem_next = ps_fifo_mem;
        ps_fifo.out = ps_fifo_mem[WIDTH - 1 : 0]; // Output from the last row
        if (ps_fifo.shift) begin
            ps_fifo_mem_next = ps_fifo_mem >> WIDTH;    // Shift values forward 
        end
        if (ps_fifo.load) begin
            for (i = 0; i < N; i++)begin
                ps_fifo_mem_next[(2 * N + 1) * WIDTH - WIDTH * i - 1 -: WIDTH] = ps_fifo.load_values[i * WIDTH +: WIDTH ];    // Load into first row backwards fuck indexing
            end
        end
    end

endmodule
