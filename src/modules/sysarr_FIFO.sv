`include "systolic_array_FIFO_if.vh"

module sysarr_FIFO #(
    parameter N = 4, 
    parameter WIDTH = 16
)(
    input logic clk, nRST,
    systolic_array_FIFO_if.FIFO fifo
);
    // Internal storage for FIFO
    logic [2 * WIDTH * N - 1 : 0] fifo_mem; //need space for two arrays 2 rows of matrix rows
    logic [2 * WIDTH * N - 1 : 0] fifo_mem_next;

    always_ff @(posedge clk or negedge nRST) begin
        if (!nRST) begin
            fifo_mem <= '0;     // Reset fifo mem to all zeros
        end else begin
            fifo_mem <= fifo_mem_next; 
        end
    end
    integer i;
    always_comb begin
        fifo_mem_next = fifo_mem;
        fifo.out = fifo_mem[WIDTH * N - 1 : 0]; // Output from the last row
        if (fifo.load) begin
            for (i = 0; i < N; i = i + 1) begin
                fifo_mem_next[(2 * WIDTH * N - 1) - i * WIDTH -: WIDTH ] = fifo.load_values[i * WIDTH +: WIDTH ];
            end
            // fifo_mem_next[2 * WIDTH * N - 1 : WIDTH * N] = fifo.load_values;    // Load into first row bakcwards
        end
        if (fifo.shift)begin
            fifo_mem_next = fifo_mem_next >> WIDTH;    // Shift values forward 
        end
    end

endmodule
