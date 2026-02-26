`include "ld_st_unit_if.sv"
`include "atalla_isa_types.vh"

module ld_st_unit #()
(
    input logic CLK, nRST,
    ld_st_unit_if.ld_st ld_st_if
);
    import atalla_isa_pkg::*;

    typedef enum {start, latch} state;
    state n_state, cur_state;

    logic [31:0] cur_addr, cur_store, latched_addr, latched_store, nlatched_addr, nlatched_store;
    logic cur_WEN, cur_REN, latched_REN, latched_WEN, nlatched_REN, nlatched_WEN;
    logic cur_halfword, latched_halfword, nlatched_halfword;
    logic [7:0] nlatchedRD, latchedRD;

    assign ld_st_if.data_addr = cur_addr;
    assign ld_st_if.data_store = cur_store;
    assign ld_st_if.WEN = cur_WEN;
    assign ld_st_if.REN = cur_REN;
    assign ld_st_if.rdOut = latchedRD;


    assign ld_st_if.data_out = cur_halfword ? {16'b0, ld_st_if.data_load[15:0]} : ld_st_if.data_load;


    always_comb begin
        n_state = cur_state;
        ld_st_if.ready_in = 1'b1;
        ld_st_if.valid_out = 1'b0;

        nlatched_addr = latched_addr;
        cur_addr = ld_st_if.addr;
        nlatched_store = latched_store;
        cur_store = ld_st_if.data_in;
        nlatched_REN = latched_REN;
        cur_REN = ld_st_if.valid_in && (4'b1011 == ld_st_if.scalar_type_enable) ? 1 : 0;
        nlatched_WEN = latched_WEN;
        cur_WEN = ld_st_if.valid_in && (4'b1100 == ld_st_if.scalar_type_enable) ? 1 : 0;
        nlatched_halfword = latched_halfword;
        cur_halfword = ld_st_if.halfWord;
        nlatchedRD = latchedRD;

        case (cur_state)
            start: begin
                if(ld_st_if.valid_in) begin
                    n_state = latch;
                end
                ld_st_if.ready_in = 1'b1;
                ld_st_if.valid_out = 1'b0;

                nlatched_addr = ld_st_if.addr;
                nlatched_store = ld_st_if.data_in;
                nlatched_REN = ld_st_if.valid_in && (4'b1011 == ld_st_if.scalar_type_enable) ? 1 : 0;
                nlatched_WEN = ld_st_if.valid_in && (4'b1100 == ld_st_if.scalar_type_enable) ? 1 : 0;
                nlatched_halfword = ld_st_if.halfWord;
                nlatchedRD = ld_st_if.rdIn;

            end
            latch: begin
                if((ld_st_if.hit && latched_WEN) || (ld_st_if.hit && latched_REN && ld_st_if.ready_out)) begin
                    n_state = start;
                end
                if(latched_REN && ld_st_if.hit) begin
                    ld_st_if.valid_out = 1'b1;
                end
                ld_st_if.ready_in = 1'b0;

                cur_addr = latched_addr;
                cur_store = latched_store;
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
            end
        endcase
    end

    always_ff @(posedge CLK, negedge nRST) begin
    if(!nRST) begin
        latched_addr <= 32'b0;
        latched_store <= 32'b0;
        latched_WEN <= 1'b0;
        latched_REN <= 1'b0;
        latched_halfword <= 1'b0;
        latchedRD <= 8'b0;
        cur_state <= start;
    end
    else begin
        latched_addr <= nlatched_addr;
        latched_store <= nlatched_store;
        latched_WEN <= nlatched_WEN;
        latched_REN <= nlatched_REN;
        latched_halfword <= nlatched_halfword;
        latchedRD <= nlatchedRD;
        cur_state <= n_state;
    end
end


endmodule