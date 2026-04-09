`include "ld_st_unit_if.sv"
`include "atalla_isa_types.vh"

module ld_st_unit #()
(
    input logic CLK, nRST,
    ld_st_unit_if.ld_st ld_st_if
);
    import atalla_isa_pkg::*;

    typedef enum {start, latch, miss, data_ready_stall, write_halfword, write_halfword_finish} state;
    state n_state, cur_state;

    logic [31:0] cur_addr, cur_store, latched_addr, latched_store, nlatched_addr, nlatched_store;
    logic cur_WEN, cur_REN, latched_REN, latched_WEN, nlatched_REN, nlatched_WEN;
    logic cur_halfword, latched_halfword, nlatched_halfword;
    logic [7:0] nlatchedRD, latchedRD, curRD;
    logic [31:0] temp_word_reg, temp_word_nreg;
    logic use_stored_value;

    assign ld_st_if.data_addr = cur_addr;
    assign ld_st_if.data_store = cur_store;
    assign ld_st_if.WEN = cur_WEN;
    assign ld_st_if.REN = cur_REN;
    assign ld_st_if.rdOut = curRD;

    always_comb begin
        if(cur_halfword) begin
            if(cur_addr % 4 == 2) begin
                ld_st_if.data_out = {16'b0, ld_st_if.data_load[31:16]};
            end else begin
                ld_st_if.data_out = {16'b0, ld_st_if.data_load[15:0]};
            end
        end  else if(use_stored_value == 1'b1) begin
            ld_st_if.data_out = temp_word_reg;
        end else begin
            ld_st_if.data_out = ld_st_if.data_load;
        end
    end


    always_comb begin
        n_state = cur_state;
        ld_st_if.ready_in = 1'b1;
        ld_st_if.valid_out = 1'b0;
        ld_st_if.mem_in_valid = 1'b0;
        temp_word_nreg = '0;
        use_stored_value = 1'b0;

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
        curRD = ld_st_if.rdIn;

        case (cur_state)
            start: begin

                ld_st_if.ready_in = 1'b1;
                ld_st_if.valid_out = 1'b0;

                if(~ld_st_if.hit && ld_st_if.valid_in) begin
                    n_state = latch;
                    ld_st_if.ready_in = 1'b0;
                    ld_st_if.valid_out = 1'b0;
                    if(4'b1100 == ld_st_if.scalar_type_enable && ld_st_if.halfWord) begin
                        cur_REN = 1'b1;
                        cur_WEN = 1'b0;
                    end
                end

                ld_st_if.mem_in_valid = ld_st_if.valid_in;

                nlatched_addr = ld_st_if.addr;
                nlatched_store = ld_st_if.data_in;
                nlatched_REN = ld_st_if.valid_in && (4'b1011 == ld_st_if.scalar_type_enable) ? 1 : 0;
                nlatched_WEN = ld_st_if.valid_in && (4'b1100 == ld_st_if.scalar_type_enable) ? 1 : 0;
                nlatched_halfword = ld_st_if.halfWord;
                nlatchedRD = ld_st_if.rdIn;

            end
            latch: begin
                cur_addr = latched_addr;
                cur_store = latched_store;
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
                curRD = latchedRD;
                if(latched_WEN && latched_halfword) begin
                    cur_REN = 1'b1;
                    cur_WEN = 1'b0;
                end

                ld_st_if.mem_in_valid = 1'b0;
                ld_st_if.ready_in = 1'b0;
                ld_st_if.valid_out = 1'b0;

                if(ld_st_if.miss == 1'b1) begin
                    n_state = miss;
                end
                if(ld_st_if.hit == 1'b1) begin
                    if(latched_WEN && latched_halfword) begin
                        n_state = write_halfword;
                        temp_word_nreg = ld_st_if.data_load;
                    end
                    else if(cur_WEN == 1'b1) begin
                        n_state = start;
                        ld_st_if.ready_in = 1'b1;
                    end
                    else if(cur_REN == 1'b1) begin
                        if(ld_st_if.ready_out == 1'b1) begin
                            n_state = start;
                            ld_st_if.ready_in = 1'b1;
                            ld_st_if.valid_out = 1'b1;
                        end else begin
                            n_state = data_ready_stall;
                            temp_word_nreg = ld_st_if.data_load;
                            ld_st_if.valid_out = 1'b1;
                        end
                    end
                end

            end
            miss: begin
                ld_st_if.mem_in_valid = 1'b0;
                ld_st_if.ready_in = 1'b0;
                ld_st_if.valid_out = 1'b0;

                if(ld_st_if.block_status == 1'b1) begin
                    n_state = latch;
                    ld_st_if.mem_in_valid = 1'b1;
                end

                cur_addr = latched_addr;
                cur_store = latched_store;
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
                curRD = latchedRD;
                if(latched_WEN && latched_halfword) begin
                    cur_REN = 1'b1;
                    cur_WEN = 1'b0;
                end
            end
            data_ready_stall: begin
                temp_word_nreg = temp_word_reg;
                use_stored_value = 1'b1;
                ld_st_if.valid_out = 1'b1;
                ld_st_if.ready_in = 1'b0;

                if(ld_st_if.ready_out == 1'b1) begin
                    ld_st_if.ready_in = 1'b1;
                    n_state = start;
                end

                cur_addr = latched_addr;
                cur_store = latched_store;
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
                curRD = latchedRD;
            end
            write_halfword: begin
                ld_st_if.mem_in_valid = 1'b1;
                ld_st_if.ready_in = 1'b0;
                ld_st_if.valid_out = 1'b0;

                temp_word_nreg = temp_word_reg;
                cur_addr = latched_addr;
                if(cur_addr % 4 == 2) begin
                    cur_store = {latched_store[15:0], temp_word_reg[15:0]};
                end else begin
                    cur_store = {temp_word_reg[31:16], latched_store[15:0]};
                end
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
                curRD = latchedRD;

                n_state = write_halfword_finish;
            end
            write_halfword_finish: begin
                ld_st_if.mem_in_valid = 1'b0;
                ld_st_if.ready_in = 1'b0;
                ld_st_if.valid_out = 1'b0;

                temp_word_nreg = temp_word_reg;
                cur_addr = latched_addr;
                if(cur_addr % 4 == 2) begin
                    cur_store = {latched_store[15:0], temp_word_reg[15:0]};
                end else begin
                    cur_store = {temp_word_reg[31:16], latched_store[15:0]};
                end
                cur_WEN = latched_WEN;
                cur_REN = latched_REN;
                cur_halfword = latched_halfword;
                curRD = latchedRD;

                if(ld_st_if.hit == 1'b1) begin
                    ld_st_if.ready_in = 1'b1;
                    n_state = start;
                end
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
        temp_word_reg <= '0;
    end
    else begin
        latched_addr <= nlatched_addr;
        latched_store <= nlatched_store;
        latched_WEN <= nlatched_WEN;
        latched_REN <= nlatched_REN;
        latched_halfword <= nlatched_halfword;
        latchedRD <= nlatchedRD;
        cur_state <= n_state;
        temp_word_reg <= temp_word_nreg;
    end
end


endmodule