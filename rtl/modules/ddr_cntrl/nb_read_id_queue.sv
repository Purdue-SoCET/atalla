`include "ddr_controller_if.sv"
`include "dram_pkg.svh"

import dram_pkg::*;  // needed at CU scope for the typedef below

typedef struct packed {
    logic [$clog2(ID_NUM) - 1:0] id;
    logic [3:0] len;
} riq_slot_t; // Read ID Queue Slot

module nb_read_id_queue (
    input logic CLK, nRST,
    ddr_controller_if.read_id_queue r_id_queue
);
    import dram_pkg::*;

    // Queue Signals
    logic [$clog2(ID_NUM) - 1:0] head_ptr, head_ptr_n, tail_ptr, tail_ptr_n;
    riq_slot_t [ID_NUM - 1:0] riq_reg, riq_reg_n;

    // Counter Signals
    logic [3:0] count, count_n;
    logic enable, enable_n;

    always_ff @(posedge CLK, negedge nRST) begin
        if (~nRST) begin
            head_ptr <= '0;
            tail_ptr <= '0;
            riq_reg <= '0;
            count <= '0;
            enable <= 0;
        end else begin
            head_ptr <= head_ptr_n;
            tail_ptr <= tail_ptr_n;
            riq_reg <= riq_reg_n;
            count <= count_n;
            enable <= enable_n;
        end
    end

    always_comb begin
        head_ptr_n = head_ptr;
        tail_ptr_n = tail_ptr;
        riq_reg_n = riq_reg;
        count_n = count;
        enable_n = enable;
        r_id_queue.rq_rvalid = '0;
        r_id_queue.rq_rid = '0;
        r_id_queue.rq_rlen = '0;

        // Pushing ID into Slot
        if (r_id_queue.be_push_id) begin
            riq_reg_n[tail_ptr].id = r_id_queue.be_rid;
            riq_reg_n[tail_ptr].len = r_id_queue.be_rlen;
            if (tail_ptr + 1 == ID_NUM) begin
                tail_ptr_n = '0;
            end else begin
                tail_ptr_n = tail_ptr + 1;
            end
        end

        // Popping ID off Queue
        if (r_id_queue.dqs_done) begin // assuming 1 bit signal is added to data transfer unit
            enable_n = 1;
        end 
        
        // Counter going to length + 1 to find the number of beats in transfer
        if (enable) begin
            if (count == riq_reg_n[head_ptr].len + 1) begin // Total beats (fixed tail_head_ptr to head_ptr)
                enable_n = 0;
                count_n = '0;
                if (head_ptr + 1 == ID_NUM) begin
                    head_ptr_n = '0;
                end else begin
                    head_ptr_n = head_ptr + 1;
                end
            end
            if (r_id_queue.rready) begin
                count_n = count + 1;
            end
            r_id_queue.rq_rvalid = 1; // Valid signal is high entire duration of counter
            r_id_queue.rq_rid = riq_reg_n[head_ptr].id;
            r_id_queue.rq_rlen = riq_reg_n[head_ptr].len;
        end     
    end
endmodule

    