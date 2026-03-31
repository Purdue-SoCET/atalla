
`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

module store_queue (
    input logic CLK, nRST,
    ddr_controller_if.stq stq
);
    import dram_pkg::*;

    logic awready_n;
    logic request_n;
    logic [$clog2(STQ_DEPTH):0] taken, taken_n;
    logic [$clog2(STQ_DEPTH) - 1:0] head_ptr, head_ptr_n, tail_ptr, tail_ptr_n;
    lstq_slot_t [STQ_DEPTH - 1:0] stq_reg, stq_reg_n;

    always_ff @(posedge CLK, negedge nRST) begin
        if (~nRST) begin
            taken <= '0;
            head_ptr <= '0;
            tail_ptr <= '0;
            stq_reg <= '0;

            //Interface signals
            stq.awready <= 0;
            stq.request_s <= 0;
        end else begin
            taken <= taken_n;
            head_ptr <= head_ptr_n;
            tail_ptr <= tail_ptr_n;
            stq_reg <= stq_reg_n;

            stq.awready <= awready_n;
            stq.request_s <= request_n;
        end
    end

    always_comb begin
        // Base signals
        awready_n = 0;
        stq_reg_n = stq_reg;
        head_ptr_n = head_ptr;
        tail_ptr_n = tail_ptr;
        taken_n = taken;
        request_n = stq.request_s;

        // Set ready signal when valid signal goes high (Write Path)
        if (stq.awvalid && taken != STQ_DEPTH) begin
            awready_n = 1;
        end

        // When both high, take data into slot
        if (stq.awready && stq.awvalid) begin
            stq_reg_n[tail_ptr].addr = stq.awaddr;
            stq_reg_n[tail_ptr].len = stq.awlen;
            stq_reg_n[tail_ptr].id = stq.awid;
            taken_n = taken + 1;
            if (tail_ptr + 1 == STQ_DEPTH) begin
                tail_ptr_n = '0; // Wrap Around
            end else begin
                tail_ptr_n = tail_ptr + 1;
            end
        end

        // Read Path
        if(stq.request_s && stq.grant_s) begin
            stq.stq_slot = stq_reg[head_ptr];

            taken_n = taken - 1; // Pop off the queue (reads destroy)
            if (head_ptr + 1 == STQ_DEPTH) begin
                head_ptr_n = '0;
            end else begin
                head_ptr_n = head_ptr + 1;
            end
        end
        
        // Request to Front End Arbiter
        if (taken_n != 0) begin
            request_n = 1;
        end else begin
            request_n = 0;
        end
        
        // Same Cycle Read and Writes
        if (stq.awvalid && stq.awready && stq.request_s && stq.grant_s) begin
            taken_n = taken;
        end
    end
endmodule
    