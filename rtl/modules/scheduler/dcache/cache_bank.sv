`include "cache_types_pkg.svh"

module cache_bank (
    input logic CLK, nRST,
    input logic[BANKS_LEN-1:0] bank_id, 
    input logic instr_valid,  
    input logic[CACHE_RW_SIZE-1:0] ram_mem_data, 
    input mshr_reg mshr_entry_in,
    input in_mem_instr mem_instr_in,
    input logic ram_mem_complete, 
    input logic halt, 
    output logic cache_bank_free, 
    output logic scheduler_hit,
    output logic scheduler_miss,
    output logic hc_stall,
    output logic ram_mem_REN, 
    output logic ram_mem_WEN,
    output logic [CACHE_RW_SIZE-1:0] ram_mem_store, 
    output addr_t ram_mem_addr,
    output logic [31:0] scheduler_data_out,
    output logic [UUID_SIZE-1:0] scheduler_uuid_out,
    output logic scheduler_uuid_ready, 
    output logic flushed,

    // SRAM interface
    output logic sram_ren,
    output logic[NUM_SETS_PER_BANK_LEN-1:0] sram_raddr,
    input cache_set sram_rdata,
    input logic sram_rdone,

    output logic sram_wen,
    output logic[NUM_SETS_PER_BANK_LEN-1:0] sram_waddr,
    output cache_set sram_wdata,
    input logic sram_wdone,
    input logic sram_busy
);
    localparam int BANK_SHIFT = BANKS_LEN-1;

    logic latched_mshr_hit, mshr_hit;
    mshr_reg latched_mshr_entry, mshr_entry; 
    logic latched_cache_bank_busy, cache_bank_busy;

    // FSM
    bank_fsm_states curr_state, next_state; 
    hc_fsm_states hc_state, next_hc_state;
    
    logic[NUM_BLOCKS_LEN-1:0] count_FSM, next_count_FSM;
    logic count_flush;
    cache_frame latched_block_pull_buffer, latched_victim_eject_buffer, victim_eject_buffer, block_pull_buffer;
    logic[NUM_BLOCKS_PER_BANK_LEN:0] flush_count, next_flush_count;
    logic[WAYS_LEN-1:0] latched_victim_way_index, victim_way_index, max_way, next_flush_way, flush_way, mshr_hit_way, latched_mshr_hit_way;
    logic [WAYS_LEN-1:0] new_victim_way_index;
    logic[BLOCK_INDEX_BIT_LEN-1:0] latched_victim_set_index, set_index, victim_set_index, next_flush_set, flush_set; 
    logic[WAYS_LEN-1:0] hc_hit_way, next_hc_hit_way;

    // LRU 
    psuedo_lru_frame[NUM_SETS_PER_BANK-1:0] tree_lru, next_tree_lru;  
    logic[TREE_BITS-1:0] _hit_node, _miss_node, __node;

    assign set_index = mem_instr_in.addr.index >> BANK_SHIFT;   
    assign cache_bank_free = !cache_bank_busy;  

    // Internal Arrays
    cache_set main_latched_set, next_main_latched_set;
    logic [BLOCK_INDEX_BIT_LEN-1:0] main_latched_set_idx, next_main_latched_set_idx;
    cache_set hc_latched_set, next_hc_latched_set;

    // Arbitration
    logic main_sram_ren, main_sram_wen;
    logic[NUM_SETS_PER_BANK_LEN-1:0] main_sram_raddr, main_sram_waddr;
    cache_set main_sram_wdata;

    logic hc_sram_ren, hc_sram_wen;
    logic[NUM_SETS_PER_BANK_LEN-1:0] hc_sram_raddr, hc_sram_waddr;
    cache_set hc_sram_wdata;

    logic main_sram_req;
    assign main_sram_req = main_sram_ren | main_sram_wen;
    logic hc_sram_req;
    assign hc_sram_req = hc_sram_ren | hc_sram_wen;

    logic hc_grant, main_grant;
    assign hc_grant = hc_sram_req; // strict priority
    assign main_grant = main_sram_req & !hc_sram_req;

    assign sram_ren = (hc_grant & hc_sram_ren) | (main_grant & main_sram_ren);
    assign sram_wen = (hc_grant & hc_sram_wen) | (main_grant & main_sram_wen);
    assign sram_raddr = (hc_grant) ? hc_sram_raddr : main_sram_raddr;
    assign sram_waddr = (hc_grant) ? hc_sram_waddr : main_sram_waddr;
    assign sram_wdata = (hc_grant) ? hc_sram_wdata : main_sram_wdata;

    logic main_sram_rdone, main_sram_wdone;
    logic hc_sram_rdone, hc_sram_wdone;
    assign hc_sram_rdone = sram_rdone && (hc_state == HC_WAIT_READ);
    assign hc_sram_wdone = sram_wdone && (hc_state == HC_WAIT_WRITE);
    assign main_sram_rdone = sram_rdone && !hc_sram_rdone;
    assign main_sram_wdone = sram_wdone && !hc_sram_wdone;

    always_ff @ (posedge CLK, negedge nRST) begin : sequential_update
        if (!nRST) begin 
            curr_state <= START;
            hc_state <= HC_IDLE;
            tree_lru <= '0; 
            count_FSM <= '0;
            latched_victim_way_index <= '0; 
            latched_victim_set_index <= '0; 
            latched_victim_eject_buffer <= '0;
            latched_block_pull_buffer <= '0;
            latched_cache_bank_busy <= '0; 
            flush_set <= '0; 
            flush_way <= '0;
            flush_count <= '0;
            latched_mshr_hit <= 0;
            latched_mshr_hit_way <= '0; 
            main_latched_set <= '0;
            main_latched_set_idx <= '0;
            hc_latched_set <= '0;
            hc_hit_way <= '0;
            latched_mshr_entry <= '0;
        end else begin 
            curr_state <= next_state; 
            hc_state <= next_hc_state;
            tree_lru <= next_tree_lru;
            flush_set <= next_flush_set; 
            flush_way <= next_flush_way;
            flush_count <= next_flush_count; 
            count_FSM <= next_count_FSM; 
            latched_mshr_hit <= mshr_hit;
            latched_cache_bank_busy <= cache_bank_busy; 
            latched_mshr_entry <= mshr_entry; 
            latched_victim_set_index <= victim_set_index;
            latched_mshr_hit_way <= mshr_hit_way; 
            latched_victim_eject_buffer <= victim_eject_buffer;
            latched_victim_way_index <= new_victim_way_index; 
            latched_block_pull_buffer <= block_pull_buffer;
            main_latched_set <= next_main_latched_set;
            main_latched_set_idx <= next_main_latched_set_idx;
            hc_latched_set <= next_hc_latched_set;
            hc_hit_way <= next_hc_hit_way;
        end 
    end 

    // ---- Foreground Check Hit State Machine ----
    logic found_hit;
    logic[WAYS_LEN-1:0] h_way;

    always_comb begin
        next_hc_state = hc_state;
        hc_sram_ren = 0;
        hc_sram_wen = 0;
        hc_sram_raddr = set_index;
        hc_sram_waddr = set_index;
        hc_sram_wdata = hc_latched_set; 
        hc_stall = 0;
        scheduler_hit = 0;
        scheduler_miss = 0;
        scheduler_data_out = '0;
        next_hc_latched_set = hc_latched_set;
        next_hc_hit_way = hc_hit_way;
        
        found_hit = 0;
        h_way = 0;

        case (hc_state)
            HC_IDLE: begin
                if (instr_valid) begin
                    hc_stall = 1;
                    hc_sram_ren = 1;
                    hc_sram_raddr = set_index;
                    if (hc_grant && !sram_busy) begin
                        next_hc_state = HC_WAIT_READ;
                    end
                end
            end
            HC_WAIT_READ: begin
                hc_stall = 1;
                if (hc_sram_rdone) begin
                    next_hc_latched_set = sram_rdata;
                    next_hc_state = HC_EVAL;
                end
            end
            HC_EVAL: begin
                hc_stall = 1; 
                for (int i = 0; i < NUM_WAYS; i++) begin
                    if (hc_latched_set[i].valid && hc_latched_set[i].tag == mem_instr_in.addr.tag) begin
                        found_hit = 1;
                        h_way = WAYS_LEN'(i);
                    end
                end
                
                if (found_hit) begin
                    next_hc_hit_way = h_way;
                    if (mem_instr_in.rw_mode) begin
                        next_hc_latched_set[h_way].block[mem_instr_in.addr.block_offset] = mem_instr_in.store_value;
                        next_hc_latched_set[h_way].dirty = 1;
                        
                        hc_sram_wen = 1;
                        hc_sram_waddr = set_index;
                        hc_sram_wdata = next_hc_latched_set;
                        if (hc_grant && !sram_busy) begin
                            next_hc_state = HC_WAIT_WRITE;
                        end else begin
                            next_hc_state = HC_EVAL; 
                        end
                    end else begin
                        scheduler_hit = 1;
                        scheduler_data_out = hc_latched_set[h_way].block[mem_instr_in.addr.block_offset];
                        hc_stall = 0; 
                        next_hc_state = HC_IDLE;
                    end
                end else begin
                    scheduler_miss = 1;
                    hc_stall = 0; 
                    next_hc_state = HC_IDLE;
                end
            end
            HC_WAIT_WRITE: begin
                hc_stall = 1;
                if (hc_sram_wdone) begin
                    scheduler_hit = 1; 
                    hc_stall = 0;
                    next_hc_state = HC_IDLE;
                end
            end
        endcase
    end

    always_comb begin : do_count_FSM
        if (count_flush) next_count_FSM = 0; 
        else if ((
            (ram_mem_complete && !latched_mshr_hit) || 
            latched_mshr_hit || 
            ((latched_mshr_entry.write_status[count_FSM] && (count_FSM != (BLOCK_SIZE - 1))))
        )) next_count_FSM = count_FSM + 1; 
        else next_count_FSM = count_FSM;
    end

    always_comb begin : tree_based_lru_update
        next_tree_lru = tree_lru;
        _hit_node = '0;
        _miss_node = '0;

        if (curr_state == FINISH) begin
          for (int level = 0; level < WAYS_LEN; level++) begin
            next_tree_lru[latched_victim_set_index].tree[_miss_node] = ~latched_victim_way_index[WAYS_LEN - 1 - level];

            if (!latched_victim_way_index[WAYS_LEN - 1 - level]) begin
              _miss_node = (2 * _miss_node) + 1;
            end else begin
              _miss_node = (2 * _miss_node) + 2;
            end
          end
        end

        if (scheduler_hit) begin
          for (int level = 0; level < WAYS_LEN; level++) begin
            next_tree_lru[set_index].tree[_hit_node] = ~next_hc_hit_way[WAYS_LEN - 1 - level];

            if (!next_hc_hit_way[WAYS_LEN - 1 - level]) begin
              _hit_node = (2 * _hit_node) + 1;
            end else begin
              _hit_node = (2 * _hit_node) + 2;
            end
          end
        end
    end 

    always_comb begin : cache_controller_logic
        count_flush = 1'b1; 
        scheduler_uuid_out = '0; 
        ram_mem_REN = 1'b0; 
        ram_mem_WEN = 1'b0; 
        ram_mem_store = '0; 
        ram_mem_addr = '0; 
        scheduler_uuid_ready = 0;
        next_flush_count = flush_count;
        next_flush_set = flush_set; 
        next_flush_way = flush_way; 
        flushed = 0; 
        victim_set_index = latched_victim_set_index; 
        victim_way_index = latched_victim_way_index;
        new_victim_way_index = latched_victim_way_index;
        mshr_hit_way = latched_mshr_hit_way; 
        mshr_hit = latched_mshr_hit;
        mshr_entry = latched_mshr_entry; 
        __node = 0; 
        block_pull_buffer = latched_block_pull_buffer; 
        victim_eject_buffer = latched_victim_eject_buffer; 

        main_sram_ren = 0;
        main_sram_wen = 0;
        main_sram_raddr = victim_set_index;
        main_sram_waddr = victim_set_index;
        
        if (main_sram_rdone) begin
            next_main_latched_set = sram_rdata;
        end else begin
            next_main_latched_set = main_latched_set;
        end

        case (curr_state) 
            START: begin 
                if (mshr_entry_in.valid) begin 
                    mshr_entry = mshr_entry_in;
                    victim_set_index = mshr_entry_in.block_addr.index >> BANK_SHIFT; 
                end
            end 
            ADDRESS_READ: begin
                main_sram_ren = 1;
                main_sram_raddr = latched_victim_set_index;
            end
            ADDRESS_WAIT: begin
            end
            ADDRESS_CALC: begin 
                mshr_hit = 0;
                mshr_hit_way = 0; 
                for (int i = 0; i < NUM_WAYS; i++) begin
                    if (next_main_latched_set[i].valid && latched_mshr_entry.block_addr.tag == next_main_latched_set[i].tag) begin
                        mshr_hit = 1'b1;
                        mshr_hit_way = WAYS_LEN'(i);
                    end 
                end
            end 
            LRU_CALC: begin 
                __node = 0;
                for (int level = 0; level < WAYS_LEN; level++) begin
                    if (tree_lru[latched_victim_set_index].tree[__node] == 0) begin
                        victim_way_index[WAYS_LEN-1 - level] = 0;
                        __node = (2 * __node) + 1;
                    end else begin
                        victim_way_index[WAYS_LEN-1 - level] = 1;
                        __node = (2 * __node) + 2;
                    end
                end 
                new_victim_way_index = (latched_mshr_hit) ? latched_mshr_hit_way : victim_way_index;
            end 
            BUFFER_STATE: begin 
                block_pull_buffer.valid = 1'b1;
                block_pull_buffer.dirty = (|latched_mshr_entry.write_status || (latched_mshr_hit && next_main_latched_set[latched_victim_way_index].dirty));
                block_pull_buffer.tag = latched_mshr_entry.block_addr.tag;
                if (latched_mshr_hit) begin
                    block_pull_buffer.block = next_main_latched_set[latched_victim_way_index].block;
                end
                next_main_latched_set[latched_victim_way_index].valid = 1'b0; 
            end 
            BUFFER_WRITE: begin
                main_sram_wen = 1;
                main_sram_waddr = latched_victim_set_index;
            end
            BUFFER_WAIT: begin
            end
            BLOCK_PULL: begin 
                count_flush = 1'b0; 
                if (latched_mshr_entry.write_status[NUM_BLOCKS_LEN'(count_FSM)]) begin 
                    block_pull_buffer.block[NUM_BLOCKS_LEN'(count_FSM)] = latched_mshr_entry.write_block[NUM_BLOCKS_LEN'(count_FSM)];
                end else if (ram_mem_complete && !latched_mshr_hit) begin 
                    block_pull_buffer.block[NUM_BLOCKS_LEN'(count_FSM)] = ram_mem_data;
                end 

                ram_mem_REN = 1; //!latched_mshr_hit && !latched_mshr_entry.write_status[NUM_BLOCKS_LEN'(count_FSM)];
                ram_mem_addr = addr_t'{latched_mshr_entry.block_addr.tag, ((latched_victim_set_index  << BANK_SHIFT) | bank_id), BLOCK_OFF_BIT_LEN'(count_FSM), BYTE_OFF_BIT_LEN'('0)};

                if ((count_FSM == (BLOCK_SIZE - 1)) && (next_count_FSM == 0)) begin
                     victim_eject_buffer = next_main_latched_set[latched_victim_way_index];
                end
            end 
            VICTIM_EJECT: begin 
                count_flush = 1'b0; 
                ram_mem_WEN = 1'b1; 
                ram_mem_addr = addr_t'{latched_victim_eject_buffer.tag, ((latched_victim_set_index  << BANK_SHIFT) | bank_id), NUM_BLOCKS_LEN'(count_FSM), BYTE_OFF_BIT_LEN'('0)};
                ram_mem_store = latched_victim_eject_buffer.block[NUM_BLOCKS_LEN'(count_FSM)];
            end
            FINISH_WRITE: begin
                next_main_latched_set[latched_victim_way_index] = latched_block_pull_buffer;
                main_sram_wen = 1;
                main_sram_waddr = latched_victim_set_index;
            end
            FINISH_WAIT: begin
            end
            FINISH: begin 
                scheduler_uuid_out = latched_mshr_entry.uuid;
                scheduler_uuid_ready = 1;
                if (mshr_entry_in.valid) begin 
                    mshr_entry = mshr_entry_in;
                    victim_set_index = mshr_entry_in.block_addr.index >> BANK_SHIFT; 
                end
            end
            FLUSH_READ: begin
                main_sram_ren = 1;
                main_sram_raddr = flush_set;
            end
            FLUSH_WAIT: begin
            end
            FLUSH: begin 
                if (next_state != WRITEBACK) begin 
                    if (flush_way == NUM_WAYS - 1) begin
                        next_flush_set = flush_set + 1; 
                        next_flush_way = 0;
                    end else begin
                        next_flush_way = flush_way + 1; 
                    end
                    if (!next_main_latched_set[flush_way].dirty) next_flush_count = flush_count + 1; 
                end 
            end 
            WRITEBACK: begin 
                count_flush = 1'b0; 
                ram_mem_WEN = 1'b1; 
                ram_mem_addr = addr_t'{next_main_latched_set[flush_way].tag, ((flush_set  << BANK_SHIFT) | bank_id), NUM_BLOCKS_LEN'(count_FSM), BYTE_OFF_BIT_LEN'('0)};
                ram_mem_store = next_main_latched_set[flush_way].block[NUM_BLOCKS_LEN'(count_FSM)];
            end
            WRITEBACK_WRITE: begin
                next_main_latched_set[flush_way].dirty = 1'b0;
                next_main_latched_set[flush_way].valid = 1'b0;
                next_main_latched_set[flush_way].block = '0;
                main_sram_wen = 1;
                main_sram_waddr = flush_set;
            end
            WRITEBACK_WAIT: begin
            end
            HALT: begin 
                flushed = 1; 
                next_flush_count = 0; 
                next_flush_set = 0;
                next_flush_way = 0;
            end 
        endcase

        next_main_latched_set_idx = main_latched_set_idx;
        if (main_sram_ren) begin
            next_main_latched_set_idx = main_sram_raddr;
        end

        if (hc_state == HC_EVAL && found_hit && mem_instr_in.rw_mode) begin
            if (set_index == main_latched_set_idx) begin
                next_main_latched_set[h_way].block[mem_instr_in.addr.block_offset] = mem_instr_in.store_value;
                next_main_latched_set[h_way].dirty = 1;
            end
        end

        main_sram_wdata = next_main_latched_set;
    end 

    always_comb begin : fsm_state_logic
        next_state = curr_state; 
        cache_bank_busy = latched_cache_bank_busy; 

        case (curr_state) 
            START: begin 
                if (mshr_entry_in.valid) begin 
                    cache_bank_busy = 1; 
                    next_state = ADDRESS_READ;
                end 
                else if (halt) begin 
                    cache_bank_busy = 1; 
                    next_state = FLUSH_READ; 
                end 
            end 
            ADDRESS_READ: begin
                if (main_grant && !sram_busy) next_state = ADDRESS_WAIT;
            end
            ADDRESS_WAIT: begin
                if (main_sram_rdone) next_state = ADDRESS_CALC;
            end
            ADDRESS_CALC: begin 
                next_state = LRU_CALC; 
            end 
            LRU_CALC: begin 
                next_state = BUFFER_STATE; 
            end 
            BUFFER_STATE: begin 
                next_state = BUFFER_WRITE; 
            end 
            BUFFER_WRITE: begin
                if (main_grant && !sram_busy) next_state = BUFFER_WAIT;
            end
            BUFFER_WAIT: begin
                if (main_sram_wdone) next_state = BLOCK_PULL;
            end
            BLOCK_PULL: begin 
                if ((count_FSM == (BLOCK_SIZE - 1)) && (next_count_FSM == 0)) begin 
                    if (next_main_latched_set[latched_victim_way_index].dirty && !latched_mshr_hit) next_state = VICTIM_EJECT;
                    else begin 
                        next_state = FINISH_WRITE;  
                    end 
                end 
            end
            VICTIM_EJECT: begin 
                if (count_FSM == (BLOCK_SIZE - 1) && (next_count_FSM == 0)) begin 
                    next_state = FINISH_WRITE; 
                end 
            end 
            FINISH_WRITE: begin
                if (main_grant && !sram_busy) next_state = FINISH_WAIT;
            end
            FINISH_WAIT: begin
                if (main_sram_wdone) begin
                    cache_bank_busy = 0;
                    next_state = FINISH;
                end
            end
            FINISH: begin 
                if (mshr_entry_in.valid) begin 
                    cache_bank_busy = 1; 
                    next_state = ADDRESS_READ;
                end else next_state = START; 
            end 
            FLUSH_READ: begin
                if (main_grant && !sram_busy) next_state = FLUSH_WAIT;
            end
            FLUSH_WAIT: begin
                if (main_sram_rdone) next_state = FLUSH;
            end
            FLUSH: begin 
                if (flush_count == NUM_BLOCKS_PER_BANK) next_state = HALT; 
                else if (next_main_latched_set[flush_way].dirty) next_state = WRITEBACK;
                else begin
                    if (flush_way == NUM_WAYS - 1) next_state = FLUSH_READ;
                    else next_state = FLUSH;
                end
            end
            WRITEBACK: begin 
                if (count_FSM == (BLOCK_SIZE - 1) && (next_count_FSM == 0)) begin 
                    next_state = WRITEBACK_WRITE; 
                end 
            end 
            WRITEBACK_WRITE: begin
                if (main_grant && !sram_busy) next_state = WRITEBACK_WAIT;
            end
            WRITEBACK_WAIT: begin
                if (main_sram_wdone) begin
                    next_state = FLUSH;
                end
            end
            HALT: begin 
                if (!halt) next_state = START;
                else next_state = HALT; 
            end 
        endcase
    end 

endmodule