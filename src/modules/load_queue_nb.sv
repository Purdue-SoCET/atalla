// modport lq (
//     //AXI -> LQ
//     input arvalid, araddr, arid, arsize, arlen, arburst, 
//     //ARB -> LQ
//     grant_l, 
//     //LQ -> AXI
//     output arready, 
//     //STQ -> ARB
//     address_l, request_l, len_l, id_l

//Front End Load Queue
`include "ddr_controller_if.vh"
`include "dram_pkg.vh"

typedef struct packed {
    logic [3:0] len;
    logic [$clog2(ID_NUM) - 1:0] id;
    logic [31:0] addr;
} lq_slot_t;

module load_queue (
    input logic CLK, nRST, 
    ddr_controller_if.lq lq
);

    import dram_pkg::*;
    // arsize & arburst unused here //

    lq_slot_t [LQ_DEPTH - 1:0] lq_reg, lq_reg_n;
    logic [$clog(LQ_DEPTH) - 1:0] head_ptr, head_ptr_n, tail_ptr, tail_ptr_n;
    logic [$clog(LQ_DEPTH):0] occ, occ_n;
    logic arready_n;
    logic request_n;

    always_ff @ (posedge CLK, negedge nRST) begin
        if(~nRST) begin
            lq_reg <= '0;
            head_ptr <= '0;
            tail_ptr <= '0;
            occ <= '0;

            lq.arready <= 0;
            lq.request_l <= 0;
        end else begin
            lq_reg <= lq_reg_n;
            head_ptr <= head_ptr_n;
            tail_ptr <= tail_ptr_n;
            occ <= occ_n;

            lq.arready <= arready_n;
            lq.request_l <= request_n;
        end
    end

    always_comb begin
        arready_n = 0;
        lq_reg_n = lq_reg;
        head_ptr_n = head_ptr;
        tail_ptr_n = tail_ptr;
        occ_n = occ;
        request_n = lq.request_l;

        //write logic
        if(lq.arvalid && (occ != LQ_DEPTH)) begin 
            arready_n = 1;
        end  

        if(lq.arvalid && lq.arready) begin
            lq_reg_n[tail_ptr].addr = lq.araddr;
            lq_reg_n[tail_ptr].len = lq.arlen;
            lq_reg_n[tail_ptr].id = lq.arid;
            occ_n = occ + 1;
            if(tail_ptr + 1 == LQ_DEPTH) begin
                tail_ptr_n = '0;
            end else begin
                tail_ptr_n = tail_ptr + 1;
            end
        end

        //read logic
        if(lq.grant_l && lq.request_l) begin
            lq.address_l = lq_reg[head_ptr].addr;
            lq.id_l = lq_reg[head_ptr].id;
            lq.len_l = lq_reg[head_ptr].len;
            occ_n = occ - 1;
            if(head_ptr + 1 == LQ_DEPTH) begin
                head_ptr_n = '0;
            end else begin
                head_ptr_n = head_ptr + 1;
            end
        end

        //r/w same cycle
        if(lq.arvalid && lq.arready && lq.grant_l && lq.request_l) begin
            occ_n = occ;
        end

        //ready signal to arb
        if(occ_n != 0) begin
            request_n = 1;
        end else begin
            request_n = 0;
        end

    end

endmodule
